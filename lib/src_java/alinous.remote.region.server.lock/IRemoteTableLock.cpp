#include "include/global.h"


#include "alinous.remote.region.server.lock/IRemoteTableLock.h"

namespace alinous {namespace remote {namespace region {namespace server {namespace lock {




bool IRemoteTableLock::__init_done = __init_static_variables();
bool IRemoteTableLock::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"IRemoteTableLock", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 IRemoteTableLock::IRemoteTableLock(ThreadContext* ctx) throw()  : IObject(ctx)
{
}
void IRemoteTableLock::__construct_impl(ThreadContext* ctx) throw() 
{
}
 IRemoteTableLock::~IRemoteTableLock() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void IRemoteTableLock::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
}
void IRemoteTableLock::__cleanUp(ThreadContext* ctx){
}
}}}}}

