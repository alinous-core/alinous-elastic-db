#include "includes.h"


namespace alinous {namespace compile {namespace declare {





bool IDeclare::__init_done = __init_static_variables();
bool IDeclare::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"IDeclare", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 IDeclare::~IDeclare() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void IDeclare::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
	IAlinousElement::__releaseRegerences(true, ctx);
}
}}}

