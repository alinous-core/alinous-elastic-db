#include "includes.h"


namespace alinous {namespace remote {namespace region {namespace client {





bool RemoteTableScheme::__init_done = __init_static_variables();
bool RemoteTableScheme::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"RemoteTableScheme", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 RemoteTableScheme::RemoteTableScheme(String* name, ThreadContext* ctx) throw()  : IObject(ctx), ITableSchema(ctx), name(nullptr), lock(__GC_INS(this, (new(ctx) LockObject(ctx)), LockObject)), tables(GCUtils<Map<String,DatabaseTableClient> >::ins(this, (new(ctx) HashMap<String,DatabaseTableClient>(ctx)), ctx, __FILEW__, __LINE__, L""))
{
	__GC_MV(this, &(this->name), name, String);
}
void RemoteTableScheme::__construct_impl(String* name, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->name), name, String);
}
 RemoteTableScheme::~RemoteTableScheme() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void RemoteTableScheme::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"RemoteTableScheme", L"~RemoteTableScheme");
	__e_obj1.add(this->name, this);
	name = nullptr;
	__e_obj1.add(this->lock, this);
	lock = nullptr;
	__e_obj1.add(this->tables, this);
	tables = nullptr;
	if(!prepare){
		return;
	}
}
void RemoteTableScheme::updateInfo(ClientSchemaData* scdata, ThreadContext* ctx) throw() 
{
	{
		SynchronizedBlockObj __synchronized_2(this->lock, ctx);
	}
}
IDatabaseTable* RemoteTableScheme::getTableStore(String* tableName, ThreadContext* ctx) throw() 
{
	{
		SynchronizedBlockObj __synchronized_2(this->lock, ctx);
		return this->tables->get(tableName, ctx);
	}
}
String* RemoteTableScheme::getName(ThreadContext* ctx) throw() 
{
	return name;
}
}}}}

