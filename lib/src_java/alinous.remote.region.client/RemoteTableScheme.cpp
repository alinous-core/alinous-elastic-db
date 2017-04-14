#include "include/global.h"


#include "alinous.db.table/IDatabaseTable.h"
#include "alinous.db/ITableSchema.h"
#include "alinous.lock/LockObject.h"
#include "alinous.remote.socket/ICommandData.h"
#include "alinous.remote.region.client.command.data/ClientTableData.h"
#include "alinous.remote.region.client.command.data/ClientSchemaData.h"
#include "alinous.remote.socket/SocketConnectionPool.h"
#include "alinous.remote.region.client/DatabaseTableClient.h"
#include "alinous.remote.region.client/RemoteTableScheme.h"

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
void RemoteTableScheme::updateInfo(ClientSchemaData* scdata, SocketConnectionPool* regionAccessPool, ThreadContext* ctx) throw() 
{
	{
		SynchronizedBlockObj __synchronized_2(this->lock, ctx);
		Map<String,ClientTableData>* map = scdata->getMap(ctx);
		doUpdateInfo(map, regionAccessPool, ctx);
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
void RemoteTableScheme::doUpdateInfo(Map<String,ClientTableData>* map, SocketConnectionPool* regionAccessPool, ThreadContext* ctx) throw() 
{
	Iterator<String>* it = map->keySet(ctx)->iterator(ctx);
	while(it->hasNext(ctx))
	{
		String* tableName = it->next(ctx);
		ClientTableData* tableData = map->get(tableName, ctx);
		DatabaseTableClient* table = getOrInitDatabaseTableClient(tableName, tableData, regionAccessPool, ctx);
		table->updateMetadata(tableData->getMetadata(ctx), ctx);
	}
	ArrayList<String>* delList = (new(ctx) ArrayList<String>(ctx));
	it = this->tables->keySet(ctx)->iterator(ctx);
	while(it->hasNext(ctx))
	{
		String* tableName = it->next(ctx);
		DatabaseTableClient* table = this->tables->get(tableName, ctx);
		if(table == nullptr)
		{
			delList->add(tableName, ctx);
		}
	}
	int maxLoop = delList->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		String* tableName = delList->get(i, ctx);
		this->tables->remove(tableName, ctx);
	}
}
DatabaseTableClient* RemoteTableScheme::getOrInitDatabaseTableClient(String* tableName, ClientTableData* tableData, SocketConnectionPool* regionAccessPool, ThreadContext* ctx) throw() 
{
	DatabaseTableClient* client = this->tables->get(tableName, ctx);
	if(client == nullptr)
	{
		client = (new(ctx) DatabaseTableClient(this->name, tableName, tableData->getMetadata(ctx), regionAccessPool, ctx));
		client->init(ctx);
		this->tables->put(tableName, client, ctx);
	}
	return client;
}
void RemoteTableScheme::__cleanUp(ThreadContext* ctx){
}
}}}}

