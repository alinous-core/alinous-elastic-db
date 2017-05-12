#include "include/global.h"


#include "alinous.remote.region.client/TableAccessStatus.h"

namespace alinous {namespace remote {namespace region {namespace client {





constexpr const int TableAccessStatus::STAT_COMMITTED_DONE;
constexpr const int TableAccessStatus::STAT_COMMITTED_NEEDED;
bool TableAccessStatus::__init_done = __init_static_variables();
bool TableAccessStatus::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"TableAccessStatus", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 TableAccessStatus::TableAccessStatus(ThreadContext* ctx) throw()  : IObject(ctx), status(0)
{
}
void TableAccessStatus::__construct_impl(ThreadContext* ctx) throw() 
{
}
 TableAccessStatus::~TableAccessStatus() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void TableAccessStatus::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"TableAccessStatus", L"~TableAccessStatus");
	if(!prepare){
		return;
	}
}
int TableAccessStatus::getStatus(ThreadContext* ctx) throw() 
{
	return status;
}
void TableAccessStatus::setStatus(int status, ThreadContext* ctx) throw() 
{
	this->status = status;
}
void TableAccessStatus::__cleanUp(ThreadContext* ctx){
}
}}}}

