/*
 * Copyright (c) Tomohiro Iizuka. All rights reserved.
 * Licensed under the MIT license.
 */


#ifndef BASELIB_THREAD_TASKSYNCHRONIZER_H_
#define BASELIB_THREAD_TASKSYNCHRONIZER_H_

namespace alinous {
class TaskSynchronizer {
public:
	inline TaskSynchronizer()  {
		pthread_cond_init(&cond, 0);
		pthread_mutex_init(&mutex, NULL);
	}
	inline ~TaskSynchronizer() {
		pthread_cond_destroy(&cond);
		pthread_mutex_destroy(&mutex);
	}

	inline void wait() {
		pthread_cond_wait(&cond, &mutex);
	}

	inline void lock() {
		int res = pthread_mutex_lock(&mutex);
		if(res != 0){

		}
	}

	inline void unlock() {
		pthread_mutex_unlock(&mutex) ;
	}
	inline void notifyAll(){
		pthread_cond_broadcast(&cond);
	}
	inline void notify()  {
		pthread_cond_signal(&cond);
	}


private:
	pthread_cond_t cond;
	pthread_mutex_t mutex;
};
}

#endif /* BASELIB_THREAD_TASKSYNCHRONIZER_H_ */
