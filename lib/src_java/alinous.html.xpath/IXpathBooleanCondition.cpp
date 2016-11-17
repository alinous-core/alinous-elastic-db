#include "includes.h"


namespace alinous {namespace html {namespace xpath {




bool IXpathBooleanCondition::__init_done = __init_static_variables();
bool IXpathBooleanCondition::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"IXpathBooleanCondition", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 IXpathBooleanCondition::~IXpathBooleanCondition() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void IXpathBooleanCondition::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
	IXpathElement::__releaseRegerences(true, ctx);
}
}}}

