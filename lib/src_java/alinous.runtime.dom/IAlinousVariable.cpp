#include "includes.h"


namespace alinous {namespace runtime {namespace dom {




constexpr const int IAlinousVariable::CLASS_VARIANT;
constexpr const int IAlinousVariable::CLASS_DOM;
constexpr const int IAlinousVariable::CLASS_OBJECT;
constexpr const int IAlinousVariable::CLASS_TYPED;
constexpr const int IAlinousVariable::CLASS_IDENTIFIER;
String* IAlinousVariable::ATTR_NAME = ConstStr::getCNST_STR_1116();
bool IAlinousVariable::__init_done = __init_static_variables();
bool IAlinousVariable::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"IAlinousVariable", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 IAlinousVariable::~IAlinousVariable() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void IAlinousVariable::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
	ICommandData::__releaseRegerences(true, ctx);
}
}}}

