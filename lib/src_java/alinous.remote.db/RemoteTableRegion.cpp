#include "includes.h"


namespace alinous {namespace remote {namespace db {





bool RemoteTableRegion::__init_done = __init_static_variables();
bool RemoteTableRegion::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"RemoteTableRegion", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 RemoteTableRegion::~RemoteTableRegion() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void RemoteTableRegion::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
}
}}}

