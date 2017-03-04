/*
 * Copyright (c) Tomohiro Iizuka. All rights reserved.
 * Licensed under the MIT license.
 */


#include "include/global.h"


namespace alinous {

sigset_t SysThread::mask;
bool SysThread::key_registerd = false;
pthread_once_t SysThread::once = PTHREAD_ONCE_INIT;
pthread_key_t SysThread::key;
bool SysThread::initStaticDone = SysThread::initStatic();

SysThread* SysThread::getCurrentThread() throw() {
	void* value = ::pthread_getspecific(SysThread::key);
	if(__builtin_expect(value == nullptr, 0)){
		SysThread* thread = new SysThread();
		thread->id = pthread_self();

		SysThread::init(thread);

		value = ::pthread_getspecific(SysThread::key);
	}

	ThreadInfo* info = (ThreadInfo*)value;

	return info->thread;
}


THREAD_ID SysThread::getCurrentThreadId() throw() {
	return pthread_self();
}

SysThread* SysThread::createThread(SysThread__start_routine threadFunc, void* params) throw() {
	SysThread* thread = new SysThread();

	ThreadParams *tp = new ThreadParams;
	tp->param = params;
	tp->thread = thread;

	::pthread_create( &(thread->id), NULL, threadFunc, tp);


	return thread;
}

void SysThread::destructKey(void* info) throw(){
	if(info == nullptr){
		return;
	}
	ThreadInfo* pinfo = (ThreadInfo*)info;
	if(pinfo->thread != nullptr){
		delete pinfo->thread;
	}
	if(pinfo->alloc != nullptr){
		delete pinfo->alloc;
	}
	delete pinfo;
}

void SysThread::exits() throw() {
	void* value = ::pthread_getspecific(SysThread::key);
	if(value != nullptr){
		destructKey(value);

		::pthread_setspecific(SysThread::key, nullptr);
	}
}

void SysThread::onceInit() throw() {
	::pthread_key_create(&key, SysThread::destructKey);

	Java2CppSystem::getSelf()->startMemoryAllocator();
	SysThread::key_registerd = true;
}

void SysThread::init(SysThread* thread) throw() {
	if(!SysThread::key_registerd ){
		::pthread_once(&SysThread::once, SysThread::onceInit);
		Java2CppSystem::getSelf()->startGCExecutor();

		void* value = ::pthread_getspecific(SysThread::key);
		if(value != nullptr){
			ThreadInfo* info = (ThreadInfo*)value;
			delete info->thread;
			info->thread = thread;

			return;
		}
	}

	ThreadInfo* info = new ThreadInfo();
	info->thread = thread;
	info->alloc = new RawArrayMemAlloc(Java2CppSystem::memManager);

	int ret = ::pthread_setspecific(key, info);
	if(ret == EINVAL){
		printf("key is EINVAL");
	}
}

bool SysThread::suspend() throw() {
	int sig;
	sigwait(&mask, &sig);

	if(sig == SIGINTERRUPT){
		return true;
	}

	return false;
}
void SysThread::resume() throw() {
	pthread_kill(this->id, SIGSUSPEND);
}

void SysThread::interrupt() throw(){
	pthread_kill(this->id, SIGINTERRUPT);
}

void SysThread::join() const throw(){
	if(this->id != 0){
		pthread_join( this->id, NULL );
	}
}

void SysThread::setName(UnicodeString* name, ThreadContext* ctx){
	if(this->name_cstr != nullptr){
		delete [] this->name_cstr;
	}

	this->name_cstr = name->toCString(ctx);

	::pthread_setname_np(this->id, this->name_cstr);
}

}

