#include "include/global.h"


#include "alinous.lock/LockObject.h"
#include "alinous.runtime.parallel/LaunchJoin.h"
#include "alinous.runtime.parallel/IThreadAction.h"
#include "alinous.runtime.parallel/AlinousThread.h"
#include "alinous.runtime.parallel/ThreadPool.h"
#include "alinous.runtime.parallel/IParallelTask.h"
#include "alinous.runtime.parallel/ConcurrentTaskQueue.h"
#include "alinous.runtime.parallel/ConcurrentTaskExexutor.h"
#include "alinous.runtime.parallel/SequentialBackgroundJob.h"

namespace alinous {namespace runtime {namespace parallel {





constexpr const int AlinousThread::EXECUTING;
constexpr const int AlinousThread::WAIT;
bool AlinousThread::__init_done = __init_static_variables();
bool AlinousThread::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"AlinousThread", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 AlinousThread::AlinousThread(LaunchJoin* launchJoin, ThreadContext* ctx) throw()  : IObject(ctx), Runnable(ctx), lock(__GC_INS(this, (new(ctx) LockObject(ctx)), LockObject)), thread(nullptr), running(0), action(nullptr), lastError(nullptr), pool(nullptr), autoReturn(0), parentstate(WAIT), taskDone(true), launchJoin(nullptr)
{
	__GC_MV(this, &(this->launchJoin), launchJoin, LaunchJoin);
	__GC_MV(this, &(this->pool), nullptr, ThreadPool);
	this->parentstate = WAIT;
	this->running = true;
	__GC_MV(this, &(this->thread), (new(ctx) Thread(this, ctx)), Thread);
	this->thread->start(ctx);
}
void AlinousThread::__construct_impl(LaunchJoin* launchJoin, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->launchJoin), launchJoin, LaunchJoin);
	__GC_MV(this, &(this->pool), nullptr, ThreadPool);
	this->parentstate = WAIT;
	this->running = true;
	__GC_MV(this, &(this->thread), (new(ctx) Thread(this, ctx)), Thread);
	this->thread->start(ctx);
}
 AlinousThread::AlinousThread(LaunchJoin* launchJoin, ThreadPool* pool, String* name, ThreadContext* ctx) throw()  : IObject(ctx), Runnable(ctx), lock(__GC_INS(this, (new(ctx) LockObject(ctx)), LockObject)), thread(nullptr), running(0), action(nullptr), lastError(nullptr), pool(nullptr), autoReturn(0), parentstate(WAIT), taskDone(true), launchJoin(nullptr)
{
	__GC_MV(this, &(this->launchJoin), launchJoin, LaunchJoin);
	__GC_MV(this, &(this->pool), pool, ThreadPool);
	this->running = true;
	__GC_MV(this, &(this->thread), (new(ctx) Thread(this, ctx)), Thread);
	this->thread->setName(name, ctx);
	this->thread->start(ctx);
}
void AlinousThread::__construct_impl(LaunchJoin* launchJoin, ThreadPool* pool, String* name, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->launchJoin), launchJoin, LaunchJoin);
	__GC_MV(this, &(this->pool), pool, ThreadPool);
	this->running = true;
	__GC_MV(this, &(this->thread), (new(ctx) Thread(this, ctx)), Thread);
	this->thread->setName(name, ctx);
	this->thread->start(ctx);
}
 AlinousThread::~AlinousThread() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void AlinousThread::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"AlinousThread", L"~AlinousThread");
	__e_obj1.add(this->lock, this);
	lock = nullptr;
	__e_obj1.add(this->thread, this);
	thread = nullptr;
	__e_obj1.add(this->action, this);
	action = nullptr;
	__e_obj1.add(this->lastError, this);
	lastError = nullptr;
	__e_obj1.add(this->pool, this);
	pool = nullptr;
	__e_obj1.add(this->launchJoin, this);
	launchJoin = nullptr;
	if(!prepare){
		return;
	}
}
void AlinousThread::execute(IThreadAction* action, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->action), action, IThreadAction);
	{
		SynchronizedBlockObj __synchronized_2(this->lock, ctx);
		this->taskDone = false;
		this->lock->notify(ctx);
	}
}
void AlinousThread::join(ThreadContext* ctx) throw() 
{
	{
		SynchronizedBlockObj __synchronized_2(this->lock, ctx);
		if(this->taskDone)
		{
			return;
		}
		this->parentstate = WAIT;
		{
			try
			{
				this->lock->wait(ctx);
			}
			catch(InterruptedException* e)
			{
				e->printStackTrace(ctx);
			}
		}
		this->parentstate = EXECUTING;
	}
}
void AlinousThread::endExecute(ThreadContext* ctx) throw() 
{
	join(ctx);
	this->pool->putBack(this, ctx);
}
void AlinousThread::shutdown(ThreadContext* ctx) throw() 
{
	join(ctx);
	{
		SynchronizedBlockObj __synchronized_2(this->lock, ctx);
		this->running = false;
		this->lock->notify(ctx);
	}
	{
		try
		{
			this->thread->join(ctx);
		}
		catch(InterruptedException* e)
		{
			__GC_MV(this, &(this->lastError), e, Throwable);
		}
	}
}
void AlinousThread::run(ThreadContext* ctx) throw() 
{
	this->parentstate = WAIT;
	{
		SynchronizedBlockObj __synchronized_2(this->lock, ctx);
		this->launchJoin->childrenJoin(ctx);
		__GC_MV(this, &(this->launchJoin), nullptr, LaunchJoin);
		while(this->running)
		{
			threadLoop(ctx);
		}
	}
}
bool AlinousThread::isRunning(ThreadContext* ctx) throw() 
{
	return running;
}
Throwable* AlinousThread::getLastError(ThreadContext* ctx) throw() 
{
	return lastError;
}
void AlinousThread::setAutoReturn(bool autoReturn, ThreadContext* ctx) throw() 
{
	this->autoReturn = autoReturn;
}
void AlinousThread::threadLoop(ThreadContext* ctx) throw() 
{
	GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"AlinousThread", L"threadLoop");
	{
		try
		{
			__GC_MV(this, &(this->lastError), nullptr, Throwable);
			this->lock->wait(ctx);
		}
		catch(InterruptedException* e)
		{
			__GC_MV(this, &(this->lastError), e, Throwable);
		}
	}
	if(this->action != nullptr)
	{
		{
			try
			{
				this->action->execute(ctx);
			}
			catch(Throwable* e)
			{
				__GC_MV(this, &(this->lastError), e, Throwable);
			}
		}
	}
	this->taskDone = true;
	__GC_MV(this, &(this->action), nullptr, IThreadAction);
	if(this->parentstate == WAIT)
	{
		this->lock->notify(ctx);
	}
	if(this->autoReturn)
	{
		this->pool->putBack(this, ctx);
	}
}
void AlinousThread::__cleanUp(ThreadContext* ctx){
}
}}}

