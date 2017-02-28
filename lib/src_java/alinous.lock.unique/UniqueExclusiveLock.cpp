#include "includes.h"


namespace alinous {namespace lock {namespace unique {





bool UniqueExclusiveLock::__init_done = __init_static_variables();
bool UniqueExclusiveLock::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"UniqueExclusiveLock", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 UniqueExclusiveLock::UniqueExclusiveLock(ThreadContext* ctx) throw()  : IObject(ctx), gate(nullptr)
{
	__GC_MV(this, &(this->gate), (new(ctx) ConcurrentGate(ctx)), ConcurrentGate);
}
void UniqueExclusiveLock::__construct_impl(ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->gate), (new(ctx) ConcurrentGate(ctx)), ConcurrentGate);
}
 UniqueExclusiveLock::~UniqueExclusiveLock() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void UniqueExclusiveLock::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"UniqueExclusiveLock", L"~UniqueExclusiveLock");
	__e_obj1.add(this->gate, this);
	gate = nullptr;
	if(!prepare){
		return;
	}
}
void UniqueExclusiveLock::lock(ThreadContext* ctx)
{
	gate->close(ctx);
}
void UniqueExclusiveLock::unlock(ThreadContext* ctx)
{
	gate->open(ctx);
}
}}}

