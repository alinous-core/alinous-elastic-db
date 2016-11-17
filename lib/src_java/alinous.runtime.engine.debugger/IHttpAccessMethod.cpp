#include "includes.h"


namespace alinous {namespace runtime {namespace engine {namespace debugger {




bool IHttpAccessMethod::__init_done = __init_static_variables();
bool IHttpAccessMethod::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"IHttpAccessMethod", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 IHttpAccessMethod::~IHttpAccessMethod() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void IHttpAccessMethod::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
}
}}}}

