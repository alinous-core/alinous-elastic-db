#include "includes.h"


namespace alinous {namespace runtime {namespace dom {




constexpr const int IDomVariable::TYPE_DOM;
constexpr const int IDomVariable::TYPE_ARRAY;
bool IDomVariable::__init_done = __init_static_variables();
bool IDomVariable::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"IDomVariable", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 IDomVariable::~IDomVariable() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void IDomVariable::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
	IDomVariableContainer::__releaseRegerences(true, ctx);
	IAlinousVariable::__releaseRegerences(true, ctx);
}
}}}

