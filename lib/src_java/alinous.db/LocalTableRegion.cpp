#include "includes.h"


namespace alinous {namespace db {





bool LocalTableRegion::__init_done = __init_static_variables();
bool LocalTableRegion::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"LocalTableRegion", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 LocalTableRegion::~LocalTableRegion() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void LocalTableRegion::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
}
}}

