/*
 * Copyright (c) Tomohiro Iizuka. All rights reserved.
 * Licensed under the MIT license.
 */


#ifndef BASELIB_THREAD_CONCURRENTTASKEXEXUTOR_H_
#define BASELIB_THREAD_CONCURRENTTASKEXEXUTOR_H_

namespace alinous {


template <typename Task>
class ConcurrentTaskExexutor {
private:
	RawLinkedList<ConcurrentTaskQueue<Task> > queue;
	RawLinkedList<ConcurrentTaskQueue<Task> > readyQueue;
	TaskSynchronizer sync;
	TaskSynchronizer readySync;
	SysThread* finalizer;
	SysThread* launcher;
	TaskSynchronizer finalyzerSync;
	bool finalizerEnds;

	ConcurrentTaskQueue<Task>* lastTask;

public:
	ConcurrentTaskExexutor(){
		this->lastTask = nullptr;
		this->finalizerEnds = false;

	}
	~ConcurrentTaskExexutor(){

	}
	void begin(){
		finalyzerSync.lock();

		this->finalizerEnds = false;

		this->finalizer = SysThread::createThread(finalizerEntryPoint, this);
		finalyzerSync.wait();
		finalyzerSync.unlock();

		readySync.lock();
		this->launcher = SysThread::createThread(launcherLoopEntryPoint, this);
		readySync.wait();
		readySync.unlock();

		wprintf(L"begin exit\n");
	}
	void finalizeLoop(){
		finalyzerSync.lock();
		finalyzerSync.notify();
		finalyzerSync.unlock();


		while(true){
			// wprintf(L"Finalizer Loop\n"); // debug

			sync.lock();

			bool isEmpty = this->queue.isEmpty();
			bool firstFinished = isEmpty ? true : this->queue.get(0)->isFinished();
			bool isNextReady = !isEmpty && firstFinished;

			if(!isNextReady){
				if(this->queue.isEmpty()){
					finalyzerSync.lock();
					finalyzerSync.notifyAll();
					finalyzerSync.unlock();
				}

				if(this->readyQueue.isEmpty() && this->queue.isEmpty() && this->finalizerEnds){
					sync.unlock();
					break;
				}

				sync.wait(); // wait for new task completed
				sync.unlock();

				continue;

			}
			ConcurrentTaskQueue<Task>* task = this->queue.get(0);

			sync.unlock();

			// execute
			task->join();
			task->postExecute();

			sync.lock();
			this->queue.remove(0);
			sync.unlock();

			delete task;
		}
	}
	static void* finalizerEntryPoint(void* param){
		ConcurrentTaskExexutor<Task>* executor = (ConcurrentTaskExexutor<Task>*)param;
		executor->finalizeLoop();

		pthread_exit(NULL);
		return nullptr;
	}
public:
	void startTask(Task* task){
		ConcurrentTaskQueue<Task>* newTask = new ConcurrentTaskQueue<Task>(task, &queue, &sync);

		this->readySync.lock();
		this->readyQueue.add(newTask);
		this->readySync.notify();
		this->readySync.unlock();
	}
	static void* launcherLoopEntryPoint(void* param){
		ConcurrentTaskExexutor* exec  = (ConcurrentTaskExexutor*)param;

		exec->launcherLoop();

		pthread_exit(NULL);
		return nullptr;
	}

	void launcherLoop(){
		readySync.lock();
		readySync.notify();
		readySync.unlock();

		readySync.lock();
		while(true){
			// wprintf(L"Launcher Loop\n"); // debug

			bool isEmpty = this->readyQueue.isEmpty();


			if(isEmpty){
				sync.lock();
				if(this->finalizerEnds){
					sync.unlock();
					break;
				}
				sync.unlock();

				readySync.wait();

				continue;
			}

			// fetch and execute
			readySync.unlock();
			asyncStart();
			readySync.lock();
		}
		readySync.unlock();

	}

	void asyncStart(){
		this->readySync.lock();
		ConcurrentTaskQueue<Task>* newTask = this->readyQueue.get(0);
		this->readySync.unlock();


		if(this->lastTask == nullptr){
			bool start = newTask->beforeStart(nullptr);

			if(start){
				this->sync.lock();
				this->queue.add(newTask);

				this->readySync.lock();
				this->readyQueue.remove(0);
				this->readySync.unlock();

				this->sync.unlock();

				newTask->start();
			}else{
				this->sync.lock();
				this->queue.add(newTask);

				this->readySync.lock();
				this->readyQueue.remove(0);
				this->lastTask = newTask;
				this->readySync.unlock();

				this->sync.unlock();
			}

			this->notifyReadyBecomeEmpty();
			return;
		}

		bool start = this->lastTask->beforeStart(newTask);

		if(start){
			this->sync.lock();
			this->queue.add(newTask);
			this->readySync.lock();
			this->readyQueue.remove(0);
			this->lastTask = nullptr;
			this->readySync.unlock();

			this->sync.unlock();

			newTask->start();
		}else{
			this->sync.lock();
			this->readySync.lock();
			this->readyQueue.remove(0);
			this->readySync.unlock();
			this->sync.unlock();

			delete newTask;
		}

		this->notifyReadyBecomeEmpty();
	}

	void notifyReadyBecomeEmpty(){
		if(this->readyQueue.isEmpty()){
			readySync.lock();
			readySync.notify();
			readySync.unlock();
		}
	}

	void waitForReadyBecomeEmpty(){
		readySync.lock();
		if(!this->readyQueue.isEmpty()){
			readySync.wait();
		}
		readySync.unlock();
	}

	void flush() {
		waitForReadyBecomeEmpty();

		// wprintf(L"flush ()\n"); // debug
		if(this->lastTask != nullptr){
			this->lastTask->start();
			this->lastTask = nullptr;
		}
	}

	void end(){

		flush();

		sync.lock();
		if(!this->queue.isEmpty() || !readyQueue.isEmpty()){
			sync.unlock();
			finalyzerSync.lock();
			finalyzerSync.wait();
			finalyzerSync.unlock();
		}else{
			sync.unlock();
		}

		sync.lock();
		this->finalizerEnds = true;
		sync.notify();
		sync.unlock();

		readySync.lock();
		readySync.notify();
		readySync.unlock();

		finalizer->join();
		launcher->join();
	}
};

}
#endif /* BASELIB_THREAD_CONCURRENTTASKEXEXUTOR_H_ */
