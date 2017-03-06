#include "include/global.h"


#include "alinous.compile/AbstractSrcElement.h"
#include "alinous.system/AlinousException.h"
#include "alinous.runtime/ExecutionException.h"
#include "alinous.runtime.dom/VariableException.h"
#include "alinous.remote.socket/NetworkBinaryBuffer.h"
#include "alinous.remote.socket/ICommandData.h"
#include "alinous.buffer.storage/FileStorageEntryBuilder.h"
#include "alinous.buffer.storage/FileStorageEntryFetcher.h"
#include "alinous.db.table/TableMetadata.h"
#include "alinous.remote.region.client.command.data/ClientTableData.h"
#include "alinous.remote.region.client.command.data/ClientSchemaData.h"
#include "alinous.remote.region.client.command.data/ClientStructureMetadata.h"
#include "alinous.btree/IValueFetcher.h"
#include "alinous.btree/IBTreeValue.h"
#include "alinous.runtime.dom/IAlinousVariable.h"
#include "alinous.runtime.variant/VariantValue.h"
#include "alinous.db.table/IDatabaseRecord.h"
#include "alinous.remote.region.client.command.data/ClientNetworkRecord.h"

namespace alinous {namespace remote {namespace region {namespace client {namespace command {namespace data {





bool ClientSchemaData::__init_done = __init_static_variables();
bool ClientSchemaData::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"ClientSchemaData", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 ClientSchemaData::ClientSchemaData(ThreadContext* ctx) throw()  : IObject(ctx), ICommandData(ctx), map(GCUtils<Map<String,ClientTableData> >::ins(this, (new(ctx) HashMap<String,ClientTableData>(ctx)), ctx, __FILEW__, __LINE__, L"")), name(nullptr)
{
}
void ClientSchemaData::__construct_impl(ThreadContext* ctx) throw() 
{
}
 ClientSchemaData::~ClientSchemaData() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void ClientSchemaData::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"ClientSchemaData", L"~ClientSchemaData");
	__e_obj1.add(this->map, this);
	map = nullptr;
	__e_obj1.add(this->name, this);
	name = nullptr;
	if(!prepare){
		return;
	}
}
void ClientSchemaData::addTable(String* tableName, ClientTableData* tableData, ThreadContext* ctx) throw() 
{
	this->map->put(tableName, tableData, ctx);
}
Map<String,ClientTableData>* ClientSchemaData::getMap(ThreadContext* ctx) throw() 
{
	return map;
}
void ClientSchemaData::readData(NetworkBinaryBuffer* buff, ThreadContext* ctx)
{
	int maxLoop = buff->getInt(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		String* tableName = buff->getString(ctx);
		ClientTableData* data = (new(ctx) ClientTableData(ctx));
		data->readData(buff, ctx);
		this->map->put(tableName, data, ctx);
	}
}
void ClientSchemaData::writeData(NetworkBinaryBuffer* buff, ThreadContext* ctx)
{
	int size = this->map->size(ctx);
	buff->putInt(size, ctx);
	Iterator<String>* it = this->map->keySet(ctx)->iterator(ctx);
	while(it->hasNext(ctx))
	{
		String* tableName = it->next(ctx);
		ClientTableData* data = this->map->get(tableName, ctx);
		buff->putString(tableName, ctx);
		data->writeData(buff, ctx);
	}
}
String* ClientSchemaData::getName(ThreadContext* ctx) throw() 
{
	return name;
}
void ClientSchemaData::setName(String* name, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->name), name, String);
}
void ClientSchemaData::__cleanUp(ThreadContext* ctx){
}
}}}}}}

