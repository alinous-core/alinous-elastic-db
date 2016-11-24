#include "includes.h"


namespace alinous {namespace db {




bool ITableRegion::__init_done = __init_static_variables();
bool ITableRegion::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"ITableRegion", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 ITableRegion::~ITableRegion() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void ITableRegion::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
}
}}

