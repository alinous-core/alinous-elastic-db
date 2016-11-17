/*
 * Copyright (c) Tomohiro Iizuka. All rights reserved.
 * Licensed under the MIT license.
 */


#ifndef BASELIB_THREADMONITOR_H_
#define BASELIB_THREADMONITOR_H_

namespace alinous {


class WaitReleaseNotifier;

class ThreadMonitor {
public:
	inline ThreadMonitor(ThreadContext *ctx) throw() {
		// pthread_cond_init(&cond, )
		pthread_cond_init(&cond, 0);
		pthread_mutex_init(&mutex, NULL);

	}

	virtual ~ThreadMonitor() throw() {
		pthread_cond_destroy(&cond);
		pthread_mutex_destroy(&mutex);
	}

	inline void notifyAll(ThreadContext *ctx) throw() {
		pthread_cond_broadcast(&cond);
	}

	inline void notify(ThreadContext *ctx) throw() {
		pthread_cond_signal(&cond);
	}

	inline void wait(ThreadContext *ctx) throw() {
		pthread_cond_wait(&cond, &mutex);
	}

	inline int lock() throw() {
		return pthread_mutex_lock(&mutex);
	}

	inline void unlock() throw() {
		pthread_mutex_unlock(&mutex) ;
	}



private:
	pthread_cond_t cond;
	pthread_mutex_t mutex;


};

} /* namespace alinous */

#endif /* BASELIB_THREADMONITOR_H_ */
