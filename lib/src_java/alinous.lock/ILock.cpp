#include "include/global.h"


#include "alinous.lock/ILock.h"

namespace alinous {namespace lock {




bool ILock::__init_done = __init_static_variables();
bool ILock::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"ILock", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 ILock::ILock(ThreadContext* ctx) throw()  : IObject(ctx)
{
}
void ILock::__construct_impl(ThreadContext* ctx) throw() 
{
}
 ILock::~ILock() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void ILock::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
}
void ILock::__cleanUp(ThreadContext* ctx){
}
}}

