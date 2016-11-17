/*
 * Copyright (c) Tomohiro Iizuka. All rights reserved.
 * Licensed under the MIT license.
 */


#include "includes.h"

namespace java { namespace lang {

Thread::Thread(ThreadContext* ctx) : IObject(ctx), Runnable(ctx)  {
	this->target = 0;
	this->name = nullptr;
}
Thread::Thread(SysThread* thread, ThreadContext* ctx) : IObject(ctx), Runnable(ctx) {
	sysThread = thread;
	this->target = 0;
	this->name = nullptr;
}
Thread::Thread(Runnable *target, ThreadContext* ctx) : IObject(ctx), Runnable(ctx){
	this->target = __GC_INS(this, target, Runnable);
	this->name = nullptr;
}
Thread::Thread(Runnable *target, UnicodeString* name, ThreadContext* ctx) : IObject(ctx), Runnable(ctx) {
	this->target = __GC_INS(this, target, Runnable);
	this->name = __GC_INS(this, name, UnicodeString);
}

Thread::~Thread(){
	ThreadContext* ctx = ThreadContext::getCurentContext();
	__releaseRegerences(false, ctx);
}

void Thread::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() {
	if(this->sysThread != nullptr){
		//delete this->sysThread;
		this->sysThread = nullptr;

		__GC_DEC(this, this->target, Runnable);
		this->target = nullptr;

		if(this->name != nullptr){
			__GC_DEC(this, this->name, UnicodeString);
			this->name = nullptr;
		}
	}
}

void Thread::start(ThreadContext* ctx) {
	//ctx->localGC();


	this->sysThread = SysThread::createThread(Thread::__alinous_thread_runner_starts, this->target);
	if(this->name != nullptr){
		this->sysThread->setName(name, ctx);
	}
}

void Thread::handler(int sig){
	return;
}

void Thread::__destructKey(void* info){

}

void* Thread::__alinous_thread_runner_starts(void *params)
{
	ThreadParams* tp = (ThreadParams*)params;
	SysThread::init(tp->thread);

	signal(SysThread::SIGSUSPEND, Thread::handler);

	alinous::ThreadContext *ctx = alinous::ThreadContext::newThreadContext();

	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"Thread", L"__alinous_thread_runner_starts");

		java::lang::Runnable* run = (java::lang::Runnable*)(tp->param);
		ctx->protectRootObject(run);

		run->run(ctx);

		ctx->localGC();
	}

	delete ctx;
	delete tp;

	ThreadInfo* pinfo = (ThreadInfo*)::pthread_getspecific(SysThread::key);
	pinfo->thread = nullptr;
	delete pinfo->alloc;
	delete pinfo;

	::pthread_setspecific(SysThread::key, nullptr);

	::pthread_exit(nullptr);

    return 0;
}


Thread* Thread::getCurrentThread(ThreadContext* ctx) {
	Thread* th = new Thread(SysThread::getCurrentThread(), ctx);
	return th;
}

void Thread::join(ThreadContext* ctx) {
	this->sysThread->join();
}

void Thread::sleep(int milli, ThreadContext* ctx){
	::usleep(milli * 1000);
}

bool Thread::equals(IObject* obj, ThreadContext* ctx)
{
	Thread* th = dynamic_cast<Thread*>(obj);
	return getId(ctx) == th->getId(ctx);
}


long Thread::getId(ThreadContext* ctx) const {
	return (long)this->sysThread->getId();
}

Thread* Thread::currentThread(ThreadContext* ctx){
	SysThread* pt = SysThread::getCurrentThread();

	return new Thread(pt, ctx);
}

void Thread::setName(UnicodeString* name, ThreadContext* ctx){
	__GC_MV(this, &this->name, name, UnicodeString);
}


}}

