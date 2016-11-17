#include "includes.h"


namespace alinous {namespace runtime {namespace dom {




bool IDomVariableContainer::__init_done = __init_static_variables();
bool IDomVariableContainer::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"IDomVariableContainer", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 IDomVariableContainer::~IDomVariableContainer() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void IDomVariableContainer::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
}
}}}

