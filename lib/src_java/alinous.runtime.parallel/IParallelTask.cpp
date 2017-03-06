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




bool IParallelTask::__init_done = __init_static_variables();
bool IParallelTask::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"IParallelTask", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 IParallelTask::IParallelTask(ThreadContext* ctx) throw()  : IObject(ctx)
{
}
void IParallelTask::__construct_impl(ThreadContext* ctx) throw() 
{
}
 IParallelTask::~IParallelTask() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void IParallelTask::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
}
void IParallelTask::__cleanUp(ThreadContext* ctx){
}
}}}

