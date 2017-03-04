/*
 * Copyright (c) Tomohiro Iizuka. All rights reserved.
 * Licensed under the MIT license.
 */


#include "include/global.h"

namespace alinous {


HashedSpiLock::HashedSpiLock() throw() {
	this->MAX_HASH = 256;
	this->MAX_HASH_MASK = this->MAX_HASH - 1;

	this->mutexes = new SysSpinMutex* [this->MAX_HASH]{};
	for(int i = 0; i != this->MAX_HASH; ++i){
		this->mutexes[i] = new SysSpinMutex();
	}
}

HashedSpiLock::~HashedSpiLock() throw() {
	for(int i = 0; i != this->MAX_HASH; ++i){
		delete this->mutexes[i];
	}
	delete [] this->mutexes;
}

SysSpinMutex* HashedSpiLock::lock(void* ptr) throw() {
	long long num = (long long)ptr;
	long long hash = num & this->MAX_HASH_MASK;


	SysSpinMutex* mutex = this->mutexes[hash];
	mutex->lock();
	return mutex;
}

HashedSpiLock* HashedSpiLock::getInstance() throw() {
	static HashedSpiLock locker;
	return &locker;
}

}

