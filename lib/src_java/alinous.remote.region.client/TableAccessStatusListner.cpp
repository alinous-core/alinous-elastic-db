#include "include/global.h"


#include "alinous.remote.region.client/TableAccessStatus.h"
#include "alinous.remote.region.client/TableAccessStatusListner.h"

namespace alinous {namespace remote {namespace region {namespace client {





bool TableAccessStatusListner::__init_done = __init_static_variables();
bool TableAccessStatusListner::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"TableAccessStatusListner", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 TableAccessStatusListner::TableAccessStatusListner(ThreadContext* ctx) throw()  : IObject(ctx), stats(GCUtils<Map<String,TableAccessStatus> >::ins(this, (new(ctx) HashMap<String,TableAccessStatus>(ctx)), ctx, __FILEW__, __LINE__, L""))
{
}
void TableAccessStatusListner::__construct_impl(ThreadContext* ctx) throw() 
{
}
 TableAccessStatusListner::~TableAccessStatusListner() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void TableAccessStatusListner::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"TableAccessStatusListner", L"~TableAccessStatusListner");
	__e_obj1.add(this->stats, this);
	stats = nullptr;
	if(!prepare){
		return;
	}
}
void TableAccessStatusListner::setStatus(String* schemaName, String* TableName, int status, ThreadContext* ctx) throw() 
{
	StringBuilder* buff = (new(ctx) StringBuilder(ctx));
	buff->append(schemaName, ctx)->append(ConstStr::getCNST_STR_953(), ctx)->append(TableName, ctx);
	setStatus(buff->toString(ctx), status, ctx);
}
void TableAccessStatusListner::setStatus(String* fullName, int status, ThreadContext* ctx) throw() 
{
	TableAccessStatus* access = this->stats->get(fullName, ctx);
	if(access == nullptr)
	{
		access = (new(ctx) TableAccessStatus(ctx));
		this->stats->put(fullName, access, ctx);
	}
	access->setStatus(status, ctx);
}
void TableAccessStatusListner::__cleanUp(ThreadContext* ctx){
}
}}}}

