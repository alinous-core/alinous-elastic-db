/*
 * Mutex.h
 *
 *  Created on: 2015/09/03
 *      Author: iizuka
 */

#ifndef SYSTEM_MUTEX_H_
#define SYSTEM_MUTEX_H_

namespace alinous {

class SysSpinMutex {
public:
	SysSpinMutex() throw() {
		pthread_spin_init(&spinlock, PTHREAD_PROCESS_PRIVATE);
	}
	~SysSpinMutex() throw(){
		pthread_spin_destroy(&spinlock);
	}

	__attribute__((always_inline))
	void lock() throw() {
		pthread_spin_lock(&spinlock);
	}
	__attribute__((always_inline))
	void unlock() throw() {
		pthread_spin_unlock(&spinlock);
	}
private:
	pthread_spinlock_t spinlock;
};

class SysMutex {
public:
	SysMutex() throw() {
		pthread_mutex_init(&mutex, NULL);
	}
	~SysMutex() throw() {
		pthread_mutex_destroy(&mutex);
	}

	void lock() throw() {
		pthread_mutex_lock(&mutex);
	}


	void unlock() throw() {
		pthread_mutex_unlock(&mutex);
	}
private:
	pthread_mutex_t mutex;

public:
};

class HashedSpiLock {
public:
	HashedSpiLock() throw() ;

	~HashedSpiLock() throw() ;

	SysSpinMutex* lock(void* ptr) throw() ;
	static HashedSpiLock* getInstance() throw() ;
private:
	SysSpinMutex** mutexes;
	long long MAX_HASH;
	long long MAX_HASH_MASK;
};


} /* namespace alinous */

#endif /* SYSTEM_MUTEX_H_ */
