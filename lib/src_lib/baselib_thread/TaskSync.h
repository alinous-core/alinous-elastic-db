/*
 * Copyright (c) Tomohiro Iizuka. All rights reserved.
 * Licensed under the MIT license.
 */


#ifndef BASELIB_THREAD_TASKSYNC_H_
#define BASELIB_THREAD_TASKSYNC_H_

namespace alinous { namespace concurrent {
class TaskSync :public IObject, public TaskSynchronizer {
public:
	inline TaskSync(ThreadContext* ctx) throw() : IObject(ctx), TaskSynchronizer() {

	}
	virtual ~TaskSync() throw() {

	}
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw() {
	}
	inline void lock(ThreadContext* ctx) throw() {
		TaskSynchronizer::lock();
	}
	inline void unlock(ThreadContext* ctx) throw() {
		TaskSynchronizer::unlock();
	}
	inline void _wait(ThreadContext* ctx) throw() {
		TaskSynchronizer::wait();
	}
	inline void _notifyAll(ThreadContext* ctx) throw() {
		TaskSynchronizer::notifyAll();
	}
	inline void _notify(ThreadContext* ctx) throw() {
		TaskSynchronizer::notify();
	}

};
}}

#endif /* BASELIB_THREAD_TASKSYNC_H_ */
