#include "includes.h"


namespace alinous {namespace db {namespace trx {





bool TrxLockManager::__init_done = __init_static_variables();
bool TrxLockManager::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"TrxLockManager", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 TrxLockManager::~TrxLockManager() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void TrxLockManager::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
}
TrxLockContext* TrxLockManager::newLockContext(ThreadContext* ctx) throw() 
{
	return (new(ctx) TrxLockContext(ctx));
}
}}}

