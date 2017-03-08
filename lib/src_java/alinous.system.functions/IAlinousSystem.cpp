#include "include/global.h"


#include "alinous.system/ISystemLog.h"
#include "alinous.system.functions/IAlinousSystem.h"

namespace alinous {namespace system {namespace functions {




bool IAlinousSystem::__init_done = __init_static_variables();
bool IAlinousSystem::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"IAlinousSystem", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 IAlinousSystem::IAlinousSystem(ThreadContext* ctx) throw()  : IObject(ctx)
{
}
void IAlinousSystem::__construct_impl(ThreadContext* ctx) throw() 
{
}
 IAlinousSystem::~IAlinousSystem() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void IAlinousSystem::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
}
void IAlinousSystem::__cleanUp(ThreadContext* ctx){
}
}}}

