#include "include/global.h"


#include "alinous.lock/IConcurrentLockManager.h"

namespace alinous {namespace lock {




bool IConcurrentLockManager::__init_done = __init_static_variables();
bool IConcurrentLockManager::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"IConcurrentLockManager", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 IConcurrentLockManager::IConcurrentLockManager(ThreadContext* ctx) throw()  : IObject(ctx)
{
}
void IConcurrentLockManager::__construct_impl(ThreadContext* ctx) throw() 
{
}
 IConcurrentLockManager::~IConcurrentLockManager() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void IConcurrentLockManager::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
}
void IConcurrentLockManager::__cleanUp(ThreadContext* ctx){
}
}}

