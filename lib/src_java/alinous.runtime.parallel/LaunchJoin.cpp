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





bool LaunchJoin::__init_done = __init_static_variables();
bool LaunchJoin::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"LaunchJoin", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 LaunchJoin::LaunchJoin(int count, ThreadContext* ctx) throw()  : IObject(ctx), count(0), max(0), sync(__GC_INS(this, (new(ctx) LockObject(ctx)), LockObject))
{
	this->count = count;
	this->max = count;
}
void LaunchJoin::__construct_impl(int count, ThreadContext* ctx) throw() 
{
	this->count = count;
	this->max = count;
}
 LaunchJoin::~LaunchJoin() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void LaunchJoin::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"LaunchJoin", L"~LaunchJoin");
	__e_obj1.add(this->sync, this);
	sync = nullptr;
	if(!prepare){
		return;
	}
}
void LaunchJoin::parentJoin(ThreadContext* ctx)
{
	{
		SynchronizedBlockObj __synchronized_2(sync, ctx);
		if(this->count != 0)
		{
			this->sync->wait(ctx);
		}
		this->count = this->max;
	}
}
void LaunchJoin::childrenJoin(ThreadContext* ctx) throw() 
{
	{
		SynchronizedBlockObj __synchronized_2(sync, ctx);
		this->count -- ;
		if(this->count == 0)
		{
			this->sync->notify(ctx);
		}
	}
}
void LaunchJoin::__cleanUp(ThreadContext* ctx){
}
}}}

