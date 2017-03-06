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





bool ConcurrentTaskQueue::__init_done = __init_static_variables();
bool ConcurrentTaskQueue::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"ConcurrentTaskQueue", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 ConcurrentTaskQueue::ConcurrentTaskQueue(IParallelTask* task, LinkedList<ConcurrentTaskQueue>* queue, LockObject* sync, ThreadPool* pool, ThreadContext* ctx) throw()  : IObject(ctx), thread(nullptr), task(nullptr), queue(nullptr), sync(nullptr), finished(0), pool(nullptr)
{
	__GC_MV(this, &(this->task), task, IParallelTask);
	GCUtils<LinkedList<ConcurrentTaskQueue> >::mv(this, &(this->queue), queue, ctx);
	__GC_MV(this, &(this->sync), sync, LockObject);
	this->finished = false;
	__GC_MV(this, &(this->pool), pool, ThreadPool);
}
void ConcurrentTaskQueue::__construct_impl(IParallelTask* task, LinkedList<ConcurrentTaskQueue>* queue, LockObject* sync, ThreadPool* pool, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->task), task, IParallelTask);
	GCUtils<LinkedList<ConcurrentTaskQueue> >::mv(this, &(this->queue), queue, ctx);
	__GC_MV(this, &(this->sync), sync, LockObject);
	this->finished = false;
	__GC_MV(this, &(this->pool), pool, ThreadPool);
}
 ConcurrentTaskQueue::~ConcurrentTaskQueue() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void ConcurrentTaskQueue::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"ConcurrentTaskQueue", L"~ConcurrentTaskQueue");
	__e_obj1.add(this->thread, this);
	thread = nullptr;
	__e_obj1.add(this->task, this);
	task = nullptr;
	__e_obj1.add(this->queue, this);
	queue = nullptr;
	__e_obj1.add(this->sync, this);
	sync = nullptr;
	__e_obj1.add(this->pool, this);
	pool = nullptr;
	if(!prepare){
		return;
	}
}
void ConcurrentTaskQueue::start(ThreadContext* ctx) throw() 
{
	ConcurrentTaskQueue::ThreadEntryPoint* action = (new(ctx) ConcurrentTaskQueue::ThreadEntryPoint(this, ctx));
	__GC_MV(this, &(this->thread), this->pool->borrow(true, ctx), AlinousThread);
	this->thread->execute(action, ctx);
}
void ConcurrentTaskQueue::execute(ThreadContext* ctx) throw() 
{
	task->execute(ctx);
}
bool ConcurrentTaskQueue::beforeStart(ConcurrentTaskQueue* task, ThreadContext* ctx) throw() 
{
	bool res = task == nullptr ? this->task->beforeStart(nullptr, ctx) : this->task->beforeStart(task->task, ctx);
	return res;
}
void ConcurrentTaskQueue::join(ThreadContext* ctx)
{
	this->thread->join(ctx);
}
void ConcurrentTaskQueue::postExecute(ThreadContext* ctx) throw() 
{
	this->task->postExecute(ctx);
}
bool ConcurrentTaskQueue::isFinished(ThreadContext* ctx) throw() 
{
	return this->finished;
}
LinkedList<ConcurrentTaskQueue>* ConcurrentTaskQueue::getQueue(ThreadContext* ctx) throw() 
{
	return queue;
}
void ConcurrentTaskQueue::__cleanUp(ThreadContext* ctx){
}
}}}

namespace alinous {namespace runtime {namespace parallel {





bool ConcurrentTaskQueue::ThreadEntryPoint::__init_done = __init_static_variables();
bool ConcurrentTaskQueue::ThreadEntryPoint::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"ConcurrentTaskQueue::ThreadEntryPoint", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 ConcurrentTaskQueue::ThreadEntryPoint::ThreadEntryPoint(ConcurrentTaskQueue* queue, ThreadContext* ctx) throw()  : IObject(ctx), IThreadAction(ctx), _this(nullptr)
{
	__GC_MV(this, &(this->_this), queue, ConcurrentTaskQueue);
}
void ConcurrentTaskQueue::ThreadEntryPoint::__construct_impl(ConcurrentTaskQueue* queue, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->_this), queue, ConcurrentTaskQueue);
}
 ConcurrentTaskQueue::ThreadEntryPoint::~ThreadEntryPoint() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void ConcurrentTaskQueue::ThreadEntryPoint::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"ThreadEntryPoint", L"~ThreadEntryPoint");
	__e_obj1.add(this->_this, this);
	_this = nullptr;
	if(!prepare){
		return;
	}
}
void ConcurrentTaskQueue::ThreadEntryPoint::execute(ThreadContext* ctx) throw() 
{
	_this->execute(ctx);
	{
		SynchronizedBlockObj __synchronized_2(_this->sync, ctx);
		_this->finished = true;
		_this->sync->notifyAll(ctx);
	}
}
void ConcurrentTaskQueue::ThreadEntryPoint::__cleanUp(ThreadContext* ctx){
}
}}}

