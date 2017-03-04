/*
 * Copyright (c) Tomohiro Iizuka. All rights reserved.
 * Licensed under the MIT license.
 */


#include "include/global.h"

#ifndef RAWARRAYMEMTHREAD_CPP_
#define RAWARRAYMEMTHREAD_CPP_

namespace alinous {

ExtendThread::ExtendThread() throw() : threadId(0), run(false), ready(false) {
	::pthread_mutex_init(&mutex, NULL);
	::pthread_cond_init(&cond, NULL);

	::pthread_create(&threadId, NULL, ExtendThread::extendOperationLoop, this);
	::pthread_setname_np(threadId, "MemExt");

	::pthread_mutex_lock(&mutex);
	this->ready = true;

	if(this->run){
		::pthread_cond_signal(&cond);
	}else{
		::pthread_cond_wait(&cond, &mutex);
	}
	::pthread_mutex_unlock(&mutex);
}
ExtendThread::~ExtendThread() throw() {
	::pthread_mutex_lock(&mutex);
	this->run = false;
	::pthread_cond_signal(&cond);
	::pthread_mutex_unlock(&mutex);

	::pthread_join(this->threadId, nullptr);

	::pthread_cond_destroy(&cond);
	::pthread_mutex_destroy(&mutex);
}

void* ExtendThread::extendOperationLoop(void* param) throw() {
	ExtendThread* _this = (ExtendThread*)param;

	::pthread_mutex_lock(&_this->mutex);
	_this->run = true;

	if(_this->ready){
		::pthread_cond_signal(&_this->cond);
	}
	else{
		::pthread_cond_wait(&_this->cond, &_this->mutex);
	}

	/////////////////////////////////////////////////////////////
	while(_this->run || !_this->tasks.isEmpty()){
		if(_this->tasks.isEmpty()){
			::pthread_cond_wait(&_this->cond, &_this->mutex);
			continue;
		}

		RawMemAllocElement* element = _this->tasks.remove(0);

		::pthread_mutex_unlock(&_this->mutex);

		// do memory allocation
		_this->doJob(element);

		::pthread_mutex_lock(&_this->mutex);
	}

	::pthread_mutex_unlock(&_this->mutex);

	return nullptr;
}

void ExtendThread::request(RawMemAllocElement* element) throw() {
	::pthread_mutex_lock(&mutex);
	element->extReady = false;
	this->tasks.add(element);

	::pthread_cond_signal(&this->cond);

	::pthread_mutex_unlock(&mutex);
}

void ExtendThread::doJob(RawMemAllocElement* element) throw() {
	element->backGroundMalloc();
}

}

#endif /* RAWARRAYMEMTHREAD_CPP_ */
