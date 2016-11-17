#include "includes.h"


namespace alinous {namespace runtime {namespace dbif {




constexpr const int IDatabaseDriver::UNREAD_COMMITTED;
constexpr const int IDatabaseDriver::READ_COMMITTED;
constexpr const int IDatabaseDriver::REPEATABLE_READ;
constexpr const int IDatabaseDriver::SERIALIZABLE;
bool IDatabaseDriver::__init_done = __init_static_variables();
bool IDatabaseDriver::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"IDatabaseDriver", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 IDatabaseDriver::~IDatabaseDriver() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void IDatabaseDriver::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
}
}}}

