#include "includes.h"


namespace alinous {namespace runtime {namespace parallel {





bool SequentialBackgroundJob::__init_done = __init_static_variables();
bool SequentialBackgroundJob::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"SequentialBackgroundJob", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 SequentialBackgroundJob::~SequentialBackgroundJob() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void SequentialBackgroundJob::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"SequentialBackgroundJob", L"~SequentialBackgroundJob");
	__e_obj1.add(this->actions, this);
	actions = nullptr;
	__e_obj1.add(this->actionLock, this);
	actionLock = nullptr;
	__e_obj1.add(this->pool, this);
	pool = nullptr;
	__e_obj1.add(this->executor, this);
	executor = nullptr;
	__e_obj1.add(this->lastException, this);
	lastException = nullptr;
	if(!prepare){
		return;
	}
}
SequentialBackgroundJob* SequentialBackgroundJob::init(ThreadPool* pool, ThreadContext* ctx)
{
	__GC_MV(this, &(this->pool), pool, ThreadPool);
	__GC_MV(this, &(this->executor), this->pool->borrow(false, ctx), AlinousThread);
	this->executing = true;
	LaunchJoin* launchJoin = (new(ctx) LaunchJoin(1, ctx));
	SequentialBackgroundJob::QueueExecutor* exec = (new(ctx) SequentialBackgroundJob::QueueExecutor(launchJoin, this, ctx));
	this->executor->execute(exec, ctx);
	launchJoin->parentJoin(ctx);
	return this;
}
void SequentialBackgroundJob::addJob(IThreadAction* action, ThreadContext* ctx) throw() 
{
	{
		SynchronizedBlockObj __synchronized_2(actionLock, ctx);
		this->actions->add(action, ctx);
		actionLock->notify(ctx);
	}
}
void SequentialBackgroundJob::execLoop(LaunchJoin* launchJoin, ThreadContext* ctx)
{
	LaunchJoin* startSync = launchJoin;
	while(true)
	{
		IThreadAction* action = nullptr;
		if(startSync != nullptr)
		{
			startSync->childrenJoin(ctx);
			startSync = nullptr;
		}
		{
			SynchronizedBlockObj __synchronized_3(actionLock, ctx);
			if(!this->executing && this->actions->isEmpty(ctx))
			{
				break ;
			}
						else 
			{
				if(this->actions->isEmpty(ctx))
				{
					actionLock->wait(ctx);
				}
			}
			if(!this->actions->isEmpty(ctx))
			{
				action = this->actions->remove(0, ctx);
			}
		}
		if(action != nullptr)
		{
			{
				try
				{
					action->execute(ctx);
				}
				catch(Throwable* e)
				{
					e->printStackTrace(ctx);
					__GC_MV(this, &(this->lastException), e, Throwable);
				}
			}
		}
	}
}
void SequentialBackgroundJob::joinAndEnd(ThreadContext* ctx) throw() 
{
	{
		SynchronizedBlockObj __synchronized_2(actionLock, ctx);
		this->executing = false;
		actionLock->notify(ctx);
	}
	this->executor->join(ctx);
	this->pool->putBack(this->executor, ctx);
}
Throwable* SequentialBackgroundJob::getLastException(ThreadContext* ctx) throw() 
{
	return lastException;
}
}}}

namespace alinous {namespace runtime {namespace parallel {





bool SequentialBackgroundJob::QueueExecutor::__init_done = __init_static_variables();
bool SequentialBackgroundJob::QueueExecutor::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"SequentialBackgroundJob::QueueExecutor", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 SequentialBackgroundJob::QueueExecutor::QueueExecutor(LaunchJoin* launchJoin, SequentialBackgroundJob* _this, ThreadContext* ctx) throw()  : IObject(ctx), IThreadAction(ctx), launchJoin(nullptr), _this(nullptr)
{
	__GC_MV(this, &(this->launchJoin), launchJoin, LaunchJoin);
	__GC_MV(this, &(this->_this), _this, SequentialBackgroundJob);
}
void SequentialBackgroundJob::QueueExecutor::__construct_impl(LaunchJoin* launchJoin, SequentialBackgroundJob* _this, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->launchJoin), launchJoin, LaunchJoin);
	__GC_MV(this, &(this->_this), _this, SequentialBackgroundJob);
}
 SequentialBackgroundJob::QueueExecutor::~QueueExecutor() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void SequentialBackgroundJob::QueueExecutor::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"QueueExecutor", L"~QueueExecutor");
	__e_obj1.add(this->launchJoin, this);
	launchJoin = nullptr;
	__e_obj1.add(this->_this, this);
	_this = nullptr;
	if(!prepare){
		return;
	}
}
void SequentialBackgroundJob::QueueExecutor::execute(ThreadContext* ctx) throw() 
{
	{
		try
		{
			_this->execLoop(launchJoin, ctx);
		}
		catch(InterruptedException* e)
		{
			e->printStackTrace(ctx);
		}
	}
}
}}}

