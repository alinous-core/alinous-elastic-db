#include "includes.h"


namespace alinous {namespace compile {namespace sql {namespace select {namespace join {





bool IJoin::__init_done = __init_static_variables();
bool IJoin::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"IJoin", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 IJoin::~IJoin() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void IJoin::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
	ISqlStatement::__releaseRegerences(true, ctx);
}
}}}}}

