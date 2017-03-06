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





bool ClientStructureMetadata::__init_done = __init_static_variables();
bool ClientStructureMetadata::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"ClientStructureMetadata", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 ClientStructureMetadata::ClientStructureMetadata(ThreadContext* ctx) throw()  : IObject(ctx), ICommandData(ctx), map(GCUtils<Map<String,ClientSchemaData> >::ins(this, (new(ctx) HashMap<String,ClientSchemaData>(ctx)), ctx, __FILEW__, __LINE__, L""))
{
}
void ClientStructureMetadata::__construct_impl(ThreadContext* ctx) throw() 
{
}
 ClientStructureMetadata::~ClientStructureMetadata() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void ClientStructureMetadata::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"ClientStructureMetadata", L"~ClientStructureMetadata");
	__e_obj1.add(this->map, this);
	map = nullptr;
	if(!prepare){
		return;
	}
}
void ClientStructureMetadata::addSchema(String* name, ClientSchemaData* data, ThreadContext* ctx) throw() 
{
	this->map->put(name, data, ctx);
}
Map<String,ClientSchemaData>* ClientStructureMetadata::getMap(ThreadContext* ctx) throw() 
{
	return map;
}
void ClientStructureMetadata::readData(NetworkBinaryBuffer* buff, ThreadContext* ctx)
{
	int maxLoop = buff->getInt(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		String* schemeName = buff->getString(ctx);
		ClientSchemaData* data = (new(ctx) ClientSchemaData(ctx));
		data->readData(buff, ctx);
		this->map->put(schemeName, data, ctx);
	}
}
void ClientStructureMetadata::writeData(NetworkBinaryBuffer* buff, ThreadContext* ctx)
{
	int size = this->map->size(ctx);
	buff->putInt(size, ctx);
	Iterator<String>* it = this->map->keySet(ctx)->iterator(ctx);
	while(it->hasNext(ctx))
	{
		String* schemeName = it->next(ctx);
		ClientSchemaData* data = this->map->get(schemeName, ctx);
		buff->putString(schemeName, ctx);
		data->writeData(buff, ctx);
	}
}
void ClientStructureMetadata::__cleanUp(ThreadContext* ctx){
}
}}}}}}

