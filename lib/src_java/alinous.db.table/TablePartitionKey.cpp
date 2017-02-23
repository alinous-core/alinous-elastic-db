#include "includes.h"


namespace alinous {namespace db {namespace table {





bool TablePartitionKey::__init_done = __init_static_variables();
bool TablePartitionKey::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"TablePartitionKey", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 TablePartitionKey::~TablePartitionKey() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void TablePartitionKey::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"TablePartitionKey", L"~TablePartitionKey");
	__e_obj1.add(this->keys, this);
	keys = nullptr;
	if(!prepare){
		return;
	}
}
void TablePartitionKey::addKeyColumn(TableColumnMetadata* col, ThreadContext* ctx) throw() 
{
	this->keys->add(col, ctx);
}
int TablePartitionKey::fileSize(ThreadContext* ctx)
{
	int total = 4;
	int maxLoop = this->keys->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		TableColumnMetadata* col = this->keys->get(i, ctx);
		total += col->fileSize(ctx);
	}
	return total;
}
void TablePartitionKey::toFileEntry(FileStorageEntryBuilder* builder, ThreadContext* ctx)
{
	int maxLoop = this->keys->size(ctx);
	builder->putInt(maxLoop, ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		TableColumnMetadata* col = this->keys->get(i, ctx);
		col->toFileEntry(builder, ctx);
	}
}
void TablePartitionKey::readData(NetworkBinaryBuffer* buff, ThreadContext* ctx)
{
	int maxLoop = buff->getInt(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		TableColumnMetadata* col = TableColumnMetadata::fromNetwork(buff, ctx);
		this->keys->add(col, ctx);
	}
}
void TablePartitionKey::writeData(NetworkBinaryBuffer* buff, ThreadContext* ctx)
{
	int maxLoop = this->keys->size(ctx);
	buff->putInt(maxLoop, ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		TableColumnMetadata* col = this->keys->get(i, ctx);
		col->writeData(buff, ctx);
	}
}
ArrayList<TableColumnMetadata>* TablePartitionKey::getKeys(ThreadContext* ctx) throw() 
{
	return keys;
}
TablePartitionKey* TablePartitionKey::loadFromFetcher(FileStorageEntryFetcher* fetcher, ThreadContext* ctx)
{
	TablePartitionKey* partitionKey = (new(ctx) TablePartitionKey(ctx));
	int maxLoop = fetcher->fetchInt(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		TableColumnMetadata* col = TableColumnMetadata::loadFromFetcher(fetcher, ctx);
		partitionKey->keys->add(col, ctx);
	}
	return partitionKey;
}
TablePartitionKey* TablePartitionKey::fromNetwork(NetworkBinaryBuffer* buff, ThreadContext* ctx)
{
	TablePartitionKey* partitionKey = (new(ctx) TablePartitionKey(ctx));
	partitionKey->readData(buff, ctx);
	return partitionKey;
}
}}}

