/*
 * Copyright (c) Tomohiro Iizuka. All rights reserved.
 * Licensed under the MIT license.
 */


#ifndef BASELIB_THREAD_SYNCHRONIZEDBLOCKOBJ_H_
#define BASELIB_THREAD_SYNCHRONIZEDBLOCKOBJ_H_


// #define THREAD_MONITOR_DEBUG

namespace alinous {

class ThreadMonitor;

class SynchronizedBlockObj {
public:
	inline SynchronizedBlockObj(ThreadMonitor* mon, ThreadContext* ctx) throw() : mon(mon) {
		mon->lock();
	}

	inline ~SynchronizedBlockObj() throw() {
		this->mon->unlock();
	}

private:
	ThreadMonitor* mon;
};

} /* namespace alinous */

#endif /* BASELIB_THREAD_SYNCHRONIZEDBLOCKOBJ_H_ */
