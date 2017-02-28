#include "includes.h"


namespace alinous {namespace lock {namespace unique {





bool UniqueLockClientFactory::__init_done = __init_static_variables();
bool UniqueLockClientFactory::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"UniqueLockClientFactory", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 UniqueLockClientFactory::~UniqueLockClientFactory() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void UniqueLockClientFactory::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
}
UniqueExclusiveLockClient* UniqueLockClientFactory::createClient(UniqueExclusiveLockManager* mgr, ThreadContext* ctx) throw() 
{
	return (new(ctx) UniqueExclusiveLockClient(mgr, ctx));
}
}}}

