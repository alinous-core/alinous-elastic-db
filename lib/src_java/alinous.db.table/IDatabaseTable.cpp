#include "includes.h"


namespace alinous {namespace db {namespace table {




bool IDatabaseTable::__init_done = __init_static_variables();
bool IDatabaseTable::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"IDatabaseTable", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 IDatabaseTable::~IDatabaseTable() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void IDatabaseTable::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
}
}}}

