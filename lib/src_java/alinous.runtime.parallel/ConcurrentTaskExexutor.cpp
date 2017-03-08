#include "include/global.h"


#include "alinous.lock/LockObject.h"
#include "alinous.runtime.parallel/LaunchJoin.h"
#include "alinous.runtime.parallel/IThreadAction.h"
#include "alinous.runtime.parallel/AlinousThread.h"
#include "alinous.runtime.parallel/ThreadPool.h"
#include "alinous.runtime.parallel/IParallelTask.h"
#include "alinous.runtime.parallel/ConcurrentTaskQueue.h"
#include "alinous.runtime.parallel/ConcurrentTaskExexutor.h"

namespace alinous {namespace runtime {namespace parallel {





bool ConcurrentTaskExexutor::__init_done = __init_static_variables();
bool ConcurrentTaskExexutor::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"ConcurrentTaskExexutor", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 ConcurrentTaskExexutor::ConcurrentTaskExexutor(ThreadPool* pool, ThreadContext* ctx) throw()  : IObject(ctx), queue(GCUtils<LinkedList<ConcurrentTaskQueue> >::ins(this, (new(ctx) LinkedList<ConcurrentTaskQueue>(ctx)), ctx, __FILEW__, __LINE__, L"")), readyQueue(GCUtils<LinkedList<ConcurrentTaskQueue> >::ins(this, (new(ctx) LinkedList<ConcurrentTaskQueue>(ctx)), ctx, __FILEW__, __LINE__, L"")), sync(__GC_INS(this, (new(ctx) LockObject(ctx)), LockObject)), finalizer(nullptr), finalizerLaunchJoin(nullptr), launcher(nullptr), launcherLaunchJoin(nullptr), finalizerEnds(0), lastTask(nullptr), pool(nullptr)
{
	__GC_MV(this, &(this->lastTask), nullptr, ConcurrentTaskQueue);
	this->finalizerEnds = false;
	__GC_MV(this, &(this->finalizerLaunchJoin), (new(ctx) LaunchJoin(1, ctx)), LaunchJoin);
	__GC_MV(this, &(this->launcherLaunchJoin), (new(ctx) LaunchJoin(1, ctx)), LaunchJoin);
	__GC_MV(this, &(this->pool), pool, ThreadPool);
}
void ConcurrentTaskExexutor::__construct_impl(ThreadPool* pool, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->lastTask), nullptr, ConcurrentTaskQueue);
	this->finalizerEnds = false;
	__GC_MV(this, &(this->finalizerLaunchJoin), (new(ctx) LaunchJoin(1, ctx)), LaunchJoin);
	__GC_MV(this, &(this->launcherLaunchJoin), (new(ctx) LaunchJoin(1, ctx)), LaunchJoin);
	__GC_MV(this, &(this->pool), pool, ThreadPool);
}
 ConcurrentTaskExexutor::~ConcurrentTaskExexutor() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void ConcurrentTaskExexutor::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"ConcurrentTaskExexutor", L"~ConcurrentTaskExexutor");
	__e_obj1.add(this->queue, this);
	queue = nullptr;
	__e_obj1.add(this->readyQueue, this);
	readyQueue = nullptr;
	__e_obj1.add(this->sync, this);
	sync = nullptr;
	__e_obj1.add(this->finalizer, this);
	finalizer = nullptr;
	__e_obj1.add(this->finalizerLaunchJoin, this);
	finalizerLaunchJoin = nullptr;
	__e_obj1.add(this->launcher, this);
	launcher = nullptr;
	__e_obj1.add(this->launcherLaunchJoin, this);
	launcherLaunchJoin = nullptr;
	__e_obj1.add(this->lastTask, this);
	lastTask = nullptr;
	__e_obj1.add(this->pool, this);
	pool = nullptr;
	if(!prepare){
		return;
	}
}
void ConcurrentTaskExexutor::begin(ThreadContext* ctx)
{
	ConcurrentTaskExexutor::LauncherEntryPoint* launcherLoopEntryPoint = (new(ctx) ConcurrentTaskExexutor::LauncherEntryPoint(this, ctx));
	ConcurrentTaskExexutor::FinalyzerEntryPoint* finalizerEntryPoint = (new(ctx) ConcurrentTaskExexutor::FinalyzerEntryPoint(this, ctx));
	this->finalizerEnds = false;
	__GC_MV(this, &(this->finalizer), this->pool->borrow(false, ctx), AlinousThread);
	this->finalizer->execute(finalizerEntryPoint, ctx);
	this->finalizerLaunchJoin->parentJoin(ctx);
	__GC_MV(this, &(this->launcher), this->pool->borrow(false, ctx), AlinousThread);
	this->launcher->execute(launcherLoopEntryPoint, ctx);
	this->launcherLaunchJoin->parentJoin(ctx);
	System::out->println(ConstStr::getCNST_STR_1218(), ctx);
}
void ConcurrentTaskExexutor::startTask(IParallelTask* task, ThreadContext* ctx) throw() 
{
	ConcurrentTaskQueue* newTask = (new(ctx) ConcurrentTaskQueue(task, this->queue, this->sync, this->pool, ctx));
	{
		SynchronizedBlockObj __synchronized_2(this->sync, ctx);
		this->readyQueue->add(newTask, ctx);
		this->sync->notifyAll(ctx);
	}
}
void ConcurrentTaskExexutor::flush(ThreadContext* ctx)
{
	this->launcherLaunchJoin->parentJoin(ctx);
	if(this->lastTask != nullptr)
	{
		this->lastTask->start(ctx);
		__GC_MV(this, &(this->lastTask), nullptr, ConcurrentTaskQueue);
		{
			SynchronizedBlockObj __synchronized_3(sync, ctx);
			sync->notifyAll(ctx);
		}
	}
}
void ConcurrentTaskExexutor::dispose(ThreadContext* ctx) throw() 
{
	{
		SynchronizedBlockObj __synchronized_2(sync, ctx);
		this->finalizerEnds = true;
		sync->notifyAll(ctx);
	}
	{
		try
		{
			flush(ctx);
			this->finalizerLaunchJoin->parentJoin(ctx);
			{
				SynchronizedBlockObj __synchronized_3(sync, ctx);
				sync->notifyAll(ctx);
			}
			finalizer->join(ctx);
			launcher->join(ctx);
			this->pool->putBack(finalizer, ctx);
			this->pool->putBack(launcher, ctx);
		}
		catch(InterruptedException* ignore)
		{
			ignore->printStackTrace(ctx);
		}
	}
}
void ConcurrentTaskExexutor::finalizeLoop(ThreadContext* ctx)
{
	bool loopStart = false;
	while(true)
	{
		{
			SynchronizedBlockObj __synchronized_3(this->sync, ctx);
			if(!loopStart)
			{
				loopStart = true;
				this->finalizerLaunchJoin->childrenJoin(ctx);
			}
			bool isEmpty = this->queue->isEmpty(ctx);
			bool firstFinished = isEmpty ? true : this->queue->get(0, ctx)->isFinished(ctx);
			bool isNextReady = !isEmpty && firstFinished;
			if(!isNextReady)
			{
				if(this->readyQueue->isEmpty(ctx) && this->queue->isEmpty(ctx) && this->finalizerEnds)
				{
					break ;
				}
				sync->wait(ctx);
				continue;
			}
		}
		ConcurrentTaskQueue* task = this->queue->get(0, ctx);
		task->join(ctx);
		task->postExecute(ctx);
		{
			SynchronizedBlockObj __synchronized_3(this->sync, ctx);
			this->queue->remove(0, ctx);
		}
	}
	this->finalizerLaunchJoin->childrenJoin(ctx);
}
void ConcurrentTaskExexutor::launcherLoop(ThreadContext* ctx)
{
	bool loopStart = false;
	while(true)
	{
		{
			SynchronizedBlockObj __synchronized_3(this->sync, ctx);
			if(!loopStart)
			{
				loopStart = true;
				this->launcherLaunchJoin->childrenJoin(ctx);
			}
			bool isEmpty = this->readyQueue->isEmpty(ctx);
			if(isEmpty)
			{
				if(this->finalizerEnds)
				{
					break ;
				}
				sync->wait(ctx);
				continue;
			}
		}
		asyncStart(ctx);
	}
	this->launcherLaunchJoin->childrenJoin(ctx);
}
void ConcurrentTaskExexutor::asyncStart(ThreadContext* ctx)
{
	ConcurrentTaskQueue* newTask = nullptr;
	{
		SynchronizedBlockObj __synchronized_2(this->sync, ctx);
		newTask = this->readyQueue->get(0, ctx);
	}
	if(this->lastTask == nullptr)
	{
		bool start = newTask->beforeStart(nullptr, ctx);
		if(start)
		{
			{
				SynchronizedBlockObj __synchronized_4(this->sync, ctx);
				this->queue->add(newTask, ctx);
				this->readyQueue->remove(0, ctx);
			}
			newTask->start(ctx);
		}
				else 
		{
			{
				SynchronizedBlockObj __synchronized_4(this->sync, ctx);
				this->queue->add(newTask, ctx);
				this->readyQueue->remove(0, ctx);
				__GC_MV(this, &(this->lastTask), newTask, ConcurrentTaskQueue);
			}
		}
		return;
	}
	bool start = this->lastTask->beforeStart(newTask, ctx);
	if(start)
	{
		{
			SynchronizedBlockObj __synchronized_3(this->sync, ctx);
			this->queue->add(newTask, ctx);
			this->readyQueue->remove(0, ctx);
			__GC_MV(this, &(this->lastTask), nullptr, ConcurrentTaskQueue);
		}
		this->lastTask->start(ctx);
	}
		else 
	{
		{
			SynchronizedBlockObj __synchronized_3(this->sync, ctx);
			this->readyQueue->remove(0, ctx);
		}
	}
}
void ConcurrentTaskExexutor::__cleanUp(ThreadContext* ctx){
}
}}}

namespace alinous {namespace runtime {namespace parallel {





bool ConcurrentTaskExexutor::FinalyzerEntryPoint::__init_done = __init_static_variables();
bool ConcurrentTaskExexutor::FinalyzerEntryPoint::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"ConcurrentTaskExexutor::FinalyzerEntryPoint", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 ConcurrentTaskExexutor::FinalyzerEntryPoint::FinalyzerEntryPoint(ConcurrentTaskExexutor* exec, ThreadContext* ctx) throw()  : IObject(ctx), IThreadAction(ctx), executor(nullptr)
{
	__GC_MV(this, &(this->executor), exec, ConcurrentTaskExexutor);
}
void ConcurrentTaskExexutor::FinalyzerEntryPoint::__construct_impl(ConcurrentTaskExexutor* exec, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->executor), exec, ConcurrentTaskExexutor);
}
 ConcurrentTaskExexutor::FinalyzerEntryPoint::~FinalyzerEntryPoint() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void ConcurrentTaskExexutor::FinalyzerEntryPoint::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"FinalyzerEntryPoint", L"~FinalyzerEntryPoint");
	__e_obj1.add(this->executor, this);
	executor = nullptr;
	if(!prepare){
		return;
	}
}
void ConcurrentTaskExexutor::FinalyzerEntryPoint::execute(ThreadContext* ctx) throw() 
{
	{
		try
		{
			executor->finalizeLoop(ctx);
		}
		catch(InterruptedException* e)
		{
			e->printStackTrace(ctx);
		}
	}
}
void ConcurrentTaskExexutor::FinalyzerEntryPoint::__cleanUp(ThreadContext* ctx){
}
}}}

namespace alinous {namespace runtime {namespace parallel {





bool ConcurrentTaskExexutor::LauncherEntryPoint::__init_done = __init_static_variables();
bool ConcurrentTaskExexutor::LauncherEntryPoint::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"ConcurrentTaskExexutor::LauncherEntryPoint", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 ConcurrentTaskExexutor::LauncherEntryPoint::LauncherEntryPoint(ConcurrentTaskExexutor* exec, ThreadContext* ctx) throw()  : IObject(ctx), IThreadAction(ctx), exec(nullptr)
{
	__GC_MV(this, &(this->exec), exec, ConcurrentTaskExexutor);
}
void ConcurrentTaskExexutor::LauncherEntryPoint::__construct_impl(ConcurrentTaskExexutor* exec, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->exec), exec, ConcurrentTaskExexutor);
}
 ConcurrentTaskExexutor::LauncherEntryPoint::~LauncherEntryPoint() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void ConcurrentTaskExexutor::LauncherEntryPoint::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"LauncherEntryPoint", L"~LauncherEntryPoint");
	__e_obj1.add(this->exec, this);
	exec = nullptr;
	if(!prepare){
		return;
	}
}
void ConcurrentTaskExexutor::LauncherEntryPoint::execute(ThreadContext* ctx) throw() 
{
	{
		try
		{
			exec->launcherLoop(ctx);
		}
		catch(InterruptedException* e)
		{
			e->printStackTrace(ctx);
		}
	}
}
void ConcurrentTaskExexutor::LauncherEntryPoint::__cleanUp(ThreadContext* ctx){
}
}}}

