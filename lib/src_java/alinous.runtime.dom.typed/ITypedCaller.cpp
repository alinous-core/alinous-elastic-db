#include "includes.h"


namespace alinous {namespace runtime {namespace dom {namespace typed {




bool ITypedCaller::__init_done = __init_static_variables();
bool ITypedCaller::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"ITypedCaller", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 ITypedCaller::~ITypedCaller() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void ITypedCaller::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
}
}}}}

