#include "include/global.h"


#include "alinous.buffer.storage/FileStorageEntryBuilder.h"
#include "alinous.buffer.storage/FileStorageEntryFetcher.h"
#include "alinous.compile/AbstractSrcElement.h"
#include "alinous.system/AlinousException.h"
#include "alinous.db/AlinousDbException.h"
#include "alinous.runtime/ExecutionException.h"
#include "alinous.runtime.dom/VariableException.h"
#include "alinous.remote.socket/NetworkBinaryBuffer.h"
#include "alinous.remote.socket/ICommandData.h"
#include "alinous.db.table/TablePartitionKey.h"
#include "alinous.db.table/TablePartitionKeyCollection.h"

namespace alinous {namespace db {namespace table {





bool TablePartitionKeyCollection::__init_done = __init_static_variables();
bool TablePartitionKeyCollection::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"TablePartitionKeyCollection", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 TablePartitionKeyCollection::TablePartitionKeyCollection(ThreadContext* ctx) throw()  : IObject(ctx), ICommandData(ctx), keys(GCUtils<List<TablePartitionKey> >::ins(this, (new(ctx) ArrayList<TablePartitionKey>(ctx)), ctx, __FILEW__, __LINE__, L""))
{
}
void TablePartitionKeyCollection::__construct_impl(ThreadContext* ctx) throw() 
{
}
 TablePartitionKeyCollection::~TablePartitionKeyCollection() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void TablePartitionKeyCollection::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"TablePartitionKeyCollection", L"~TablePartitionKeyCollection");
	__e_obj1.add(this->keys, this);
	keys = nullptr;
	if(!prepare){
		return;
	}
}
void TablePartitionKeyCollection::addPartitionKey(TablePartitionKey* key, ThreadContext* ctx) throw() 
{
	this->keys->add(key, ctx);
}
int TablePartitionKeyCollection::fileSize(ThreadContext* ctx)
{
	int total = 4;
	int maxLoop = this->keys->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		TablePartitionKey* key = this->keys->get(i, ctx);
		total += key->fileSize(ctx);
	}
	return total;
}
void TablePartitionKeyCollection::toFileEntry(FileStorageEntryBuilder* builder, ThreadContext* ctx)
{
	int maxLoop = this->keys->size(ctx);
	builder->putInt(maxLoop, ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		TablePartitionKey* key = this->keys->get(i, ctx);
		key->toFileEntry(builder, ctx);
	}
}
void TablePartitionKeyCollection::readData(NetworkBinaryBuffer* buff, ThreadContext* ctx)
{
	int maxLoop = buff->getInt(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		TablePartitionKey* key = TablePartitionKey::fromNetwork(buff, ctx);
		this->keys->add(key, ctx);
	}
}
void TablePartitionKeyCollection::writeData(NetworkBinaryBuffer* buff, ThreadContext* ctx)
{
	int maxLoop = this->keys->size(ctx);
	buff->putInt(maxLoop, ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		TablePartitionKey* key = this->keys->get(i, ctx);
		key->writeData(buff, ctx);
	}
}
List<TablePartitionKey>* TablePartitionKeyCollection::getKeys(ThreadContext* ctx) throw() 
{
	return keys;
}
TablePartitionKeyCollection* TablePartitionKeyCollection::loadFromFetcher(FileStorageEntryFetcher* fetcher, ThreadContext* ctx)
{
	TablePartitionKeyCollection* collection = (new(ctx) TablePartitionKeyCollection(ctx));
	int maxLoop = fetcher->fetchInt(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		TablePartitionKey* key = TablePartitionKey::loadFromFetcher(fetcher, ctx);
		collection->keys->add(key, ctx);
	}
	return collection;
}
TablePartitionKeyCollection* TablePartitionKeyCollection::fromNetwork(NetworkBinaryBuffer* buff, ThreadContext* ctx)
{
	TablePartitionKeyCollection* collection = (new(ctx) TablePartitionKeyCollection(ctx));
	collection->readData(buff, ctx);
	return collection;
}
void TablePartitionKeyCollection::__cleanUp(ThreadContext* ctx){
}
}}}

