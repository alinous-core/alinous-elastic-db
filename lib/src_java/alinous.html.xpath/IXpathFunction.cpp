#include "includes.h"


namespace alinous {namespace html {namespace xpath {




bool IXpathFunction::__init_done = __init_static_variables();
bool IXpathFunction::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"IXpathFunction", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 IXpathFunction::~IXpathFunction() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void IXpathFunction::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
	IXpathElement::__releaseRegerences(true, ctx);
}
}}}

