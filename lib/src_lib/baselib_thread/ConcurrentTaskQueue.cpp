/*
 * Copyright (c) Tomohiro Iizuka. All rights reserved.
 * Licensed under the MIT license.
 */


#include "includes.h"

namespace alinous {

template <typename Task>
ConcurrentTaskQueue<Task>::ConcurrentTaskQueue(Task* task, RawLinkedList<ConcurrentTaskQueue<Task> > *queue,
		TaskSynchronizer* sync)
	: task(task), queue(queue), sync(sync)
{
	this->finished = false;
	this->directExec = false;
}

template <typename Task>
ConcurrentTaskQueue<Task>::~ConcurrentTaskQueue() {
	delete task;
	task = nullptr;
	queue = nullptr;
	sync = nullptr;
}

template <typename Task>
void ConcurrentTaskQueue<Task>::start() {
	thread = SysThread::createThread(threadEntryPoint, this);
}

template <typename Task>
void ConcurrentTaskQueue<Task>::startWithCurrentThread(THREAD_ID threadId){
	this->thread.setId(threadId);
	this->directExec = true;

	threadEntryPoint(this);
}

template <typename Task>
bool ConcurrentTaskQueue<Task>::isFinished() {
	return this->finished;
}

template <typename Task>
void ConcurrentTaskQueue<Task>::postExecute() {
	task->postExecute();
}

template <typename Task>
bool ConcurrentTaskQueue<Task>::beforeStart(ConcurrentTaskQueue* task) {
	return task == nullptr ? this->task->beforeStart(nullptr) : this->task->beforeStart(task->task);
}

template <typename Task>
RawLinkedList<ConcurrentTaskQueue<Task> >* ConcurrentTaskQueue<Task>::getQueue() {
	return this->queue;
}

template <typename Task>
TaskSynchronizer* ConcurrentTaskQueue<Task>::getSync() {
	return this->sync;
}

template <typename Task>
void ConcurrentTaskQueue<Task>::join() {
	this->thread->join();
}

template <typename Task>
void ConcurrentTaskQueue<Task>::execute() {
	task->execute();
}

template <typename Task>
void* ConcurrentTaskQueue<Task>::threadEntryPoint(void *param) {
	ConcurrentTaskQueue* _this = (ConcurrentTaskQueue*)param;

	_this->execute();

	_this->sync->lock();
	_this->finished = true;
	_this->sync->notifyAll();
	_this->sync->unlock();

	if(!_this->directExec){
		pthread_exit(NULL);
	}
	return nullptr;
}


}


