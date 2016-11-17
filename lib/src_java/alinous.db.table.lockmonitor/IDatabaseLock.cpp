#include "includes.h"


namespace alinous {namespace db {namespace table {namespace lockmonitor {




int IDatabaseLock::TABLE_LOCK = 0;
int IDatabaseLock::ROW_LOCK = 0;
bool IDatabaseLock::__init_done = __init_static_variables();
bool IDatabaseLock::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"IDatabaseLock", L"__init_static_variables");
		IDatabaseLock::TABLE_LOCK = 1;
		IDatabaseLock::ROW_LOCK = 2;
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 IDatabaseLock::~IDatabaseLock() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void IDatabaseLock::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
}
}}}}

