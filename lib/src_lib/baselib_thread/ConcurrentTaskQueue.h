/*
 * Copyright (c) Tomohiro Iizuka. All rights reserved.
 * Licensed under the MIT license.
 */


#ifndef BASELIB_THREAD_CONCURRENTTASKQUEUE_H_
#define BASELIB_THREAD_CONCURRENTTASKQUEUE_H_

namespace alinous {

template <typename Task>
class ConcurrentTaskQueue {
public:
	ConcurrentTaskQueue(Task* task, RawLinkedList<ConcurrentTaskQueue<Task> > *queue,
			TaskSynchronizer* sync);
	~ConcurrentTaskQueue();
	void start();
	void startWithCurrentThread(THREAD_ID threadId);
	bool isFinished();
	void postExecute();
	bool beforeStart(ConcurrentTaskQueue* task);
	RawLinkedList<ConcurrentTaskQueue<Task> >* getQueue();
	TaskSynchronizer* getSync();
	void join();
protected:
	void execute();
	static void* threadEntryPoint(void *param);
private:
	SysThread* thread;
	Task* task;
	RawLinkedList<ConcurrentTaskQueue<Task> >* queue;
	TaskSynchronizer* sync;
	bool finished;
	bool directExec;
};

}

#endif /* BASELIB_THREAD_CONCURRENTTASKQUEUE_H_ */
