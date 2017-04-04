#include "include/global.h"


#include "alinous.lock/LockObject.h"
#include "alinous.remote.monitor/OidHolder.h"
#include "alinous.remote.monitor/TableOidHolder.h"

namespace alinous {namespace remote {namespace monitor {





bool TableOidHolder::__init_done = __init_static_variables();
bool TableOidHolder::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"TableOidHolder", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 TableOidHolder::TableOidHolder(ThreadContext* ctx) throw()  : IObject(ctx), tableOids(GCUtils<Map<String,OidHolder> >::ins(this, (new(ctx) HashMap<String,OidHolder>(ctx)), ctx, __FILEW__, __LINE__, L"")), lock(__GC_INS(this, (new(ctx) LockObject(ctx)), LockObject))
{
}
void TableOidHolder::__construct_impl(ThreadContext* ctx) throw() 
{
}
 TableOidHolder::~TableOidHolder() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void TableOidHolder::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"TableOidHolder", L"~TableOidHolder");
	__e_obj1.add(this->tableOids, this);
	tableOids = nullptr;
	__e_obj1.add(this->lock, this);
	lock = nullptr;
	if(!prepare){
		return;
	}
}
void TableOidHolder::setNextOid(String* tableFullName, long long nextOid, ThreadContext* ctx) throw() 
{
	OidHolder* holder = nullptr;
	{
		SynchronizedBlockObj __synchronized_2(this->lock, ctx);
		holder = getOidHolder(tableFullName, ctx);
	}
	holder->setNextOid(nextOid, ctx);
}
long long TableOidHolder::getNextOid(String* tableFullName, int length, ThreadContext* ctx) throw() 
{
	OidHolder* holder = nullptr;
	{
		SynchronizedBlockObj __synchronized_2(this->lock, ctx);
		holder = getOidHolder(tableFullName, ctx);
	}
	return holder->getNextOid(length, ctx);
}
void TableOidHolder::syncNextOid(String* tableFullName, long long nextOid, ThreadContext* ctx) throw() 
{
	OidHolder* holder = nullptr;
	{
		SynchronizedBlockObj __synchronized_2(this->lock, ctx);
		holder = getOidHolder(tableFullName, ctx);
	}
	holder->syncNextOid(nextOid, ctx);
}
OidHolder* TableOidHolder::getOidHolder(String* tableFullName, ThreadContext* ctx) throw() 
{
	OidHolder* holder = tableOids->get(tableFullName, ctx);
	if(holder == nullptr)
	{
		holder = (new(ctx) OidHolder(ctx));
		this->tableOids->put(tableFullName, holder, ctx);
	}
	return holder;
}
void TableOidHolder::__cleanUp(ThreadContext* ctx){
}
}}}

