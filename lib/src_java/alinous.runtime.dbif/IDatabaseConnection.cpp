#include "includes.h"


namespace alinous {namespace runtime {namespace dbif {




bool IDatabaseConnection::__init_done = __init_static_variables();
bool IDatabaseConnection::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"IDatabaseConnection", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 IDatabaseConnection::~IDatabaseConnection() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void IDatabaseConnection::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
}
}}}

