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





bool ThreadPool::__init_done = __init_static_variables();
bool ThreadPool::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"ThreadPool", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 ThreadPool::ThreadPool(int maxThread, String* name, ThreadContext* ctx) throw()  : IObject(ctx), threads(GCUtils<Stack<AlinousThread> >::ins(this, (new(ctx) Stack<AlinousThread>(ctx)), ctx, __FILEW__, __LINE__, L"")), maxThread(0), lock(__GC_INS(this, (new(ctx) LockObject(ctx)), LockObject)), waiting(0)
{
	this->maxThread = maxThread;
	this->waiting = 0;
	LaunchJoin* join = (new(ctx) LaunchJoin(1, ctx));
	for(int i = 0; i != maxThread; ++i)
	{
		AlinousThread* thread = (new(ctx) AlinousThread(join, this, name, ctx));
		{
			SynchronizedBlockObj __synchronized_3(this->lock, ctx);
			this->threads->push(thread, ctx);
		}
		{
			try
			{
				join->parentJoin(ctx);
			}
			catch(InterruptedException* e)
			{
				e->printStackTrace(ctx);
			}
		}
	}
}
void ThreadPool::__construct_impl(int maxThread, String* name, ThreadContext* ctx) throw() 
{
	this->maxThread = maxThread;
	this->waiting = 0;
	LaunchJoin* join = (new(ctx) LaunchJoin(1, ctx));
	for(int i = 0; i != maxThread; ++i)
	{
		AlinousThread* thread = (new(ctx) AlinousThread(join, this, name, ctx));
		{
			SynchronizedBlockObj __synchronized_3(this->lock, ctx);
			this->threads->push(thread, ctx);
		}
		{
			try
			{
				join->parentJoin(ctx);
			}
			catch(InterruptedException* e)
			{
				e->printStackTrace(ctx);
			}
		}
	}
}
 ThreadPool::~ThreadPool() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void ThreadPool::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"ThreadPool", L"~ThreadPool");
	__e_obj1.add(this->threads, this);
	threads = nullptr;
	__e_obj1.add(this->lock, this);
	lock = nullptr;
	if(!prepare){
		return;
	}
}
void ThreadPool::dispose(ThreadContext* ctx) throw() 
{
	int maxLoop = 0;
	{
		SynchronizedBlockObj __synchronized_2(lock, ctx);
		maxLoop = this->threads->size(ctx);
	}
	while(maxLoop > 0)
	{
		AlinousThread* thread = nullptr;
		{
			SynchronizedBlockObj __synchronized_3(lock, ctx);
			thread = this->threads->pop(ctx);
		}
		thread->shutdown(ctx);
		{
			SynchronizedBlockObj __synchronized_3(lock, ctx);
			maxLoop = this->threads->size(ctx);
		}
	}
	this->threads->clear(ctx);
}
AlinousThread* ThreadPool::borrow(bool autoReturn, ThreadContext* ctx) throw() 
{
	AlinousThread* thread = nullptr;
	{
		SynchronizedBlockObj __synchronized_2(this->lock, ctx);
		while(this->threads->isEmpty(ctx))
		{
			{
				try
				{
					this->waiting ++ ;
					this->lock->wait(ctx);
					this->waiting -- ;
				}
				catch(InterruptedException* e)
				{
					e->printStackTrace(ctx);
				}
			}
		}
		thread = this->threads->pop(ctx);
	}
	thread->setAutoReturn(autoReturn, ctx);
	return thread;
}
void ThreadPool::putBack(AlinousThread* thread, ThreadContext* ctx) throw() 
{
	{
		SynchronizedBlockObj __synchronized_2(this->lock, ctx);
		this->threads->push(thread, ctx);
		if(this->waiting > 0)
		{
			this->lock->notify(ctx);
		}
	}
}
int ThreadPool::getMaxThread(ThreadContext* ctx) throw() 
{
	return maxThread;
}
void ThreadPool::__cleanUp(ThreadContext* ctx){
}
}}}

