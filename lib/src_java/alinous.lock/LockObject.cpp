#include "include/global.h"


#include "alinous.lock/LockObject.h"

namespace alinous {namespace lock {





bool LockObject::__init_done = __init_static_variables();
bool LockObject::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"LockObject", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 LockObject::LockObject(ThreadContext* ctx) throw()  : IObject(ctx), ThreadMonitor(ctx)
{
}
void LockObject::__construct_impl(ThreadContext* ctx) throw() 
{
}
 LockObject::~LockObject() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void LockObject::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
}
void LockObject::__cleanUp(ThreadContext* ctx){
}
}}

