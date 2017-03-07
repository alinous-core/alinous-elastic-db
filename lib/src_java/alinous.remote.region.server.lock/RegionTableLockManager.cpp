#include "include/global.h"


#include "alinous.remote.region.server.lock/RegionTableLockManager.h"

namespace alinous {namespace remote {namespace region {namespace server {namespace lock {





bool RegionTableLockManager::__init_done = __init_static_variables();
bool RegionTableLockManager::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"RegionTableLockManager", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 RegionTableLockManager::RegionTableLockManager(ThreadContext* ctx) throw()  : IObject(ctx)
{
}
void RegionTableLockManager::__construct_impl(ThreadContext* ctx) throw() 
{
}
 RegionTableLockManager::~RegionTableLockManager() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void RegionTableLockManager::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
}
void RegionTableLockManager::__cleanUp(ThreadContext* ctx){
}
}}}}}

