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
#include "alinous.runtime.dom/IAlinousVariable.h"
#include "alinous.runtime.variant/VariantValue.h"
#include "alinous.db.table/TableColumnMetadata.h"
#include "alinous.btree/IValueFetcher.h"
#include "alinous.btree/IBTreeValue.h"
#include "alinous.db.table/IDatabaseRecord.h"
#include "alinous.db.table/TablePartitionKey.h"

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
 TablePartitionKey::TablePartitionKey(ThreadContext* ctx) throw()  : IObject(ctx), ICommandData(ctx), keys(GCUtils<ArrayList<TableColumnMetadata> >::ins(this, (new(ctx) ArrayList<TableColumnMetadata>(ctx)), ctx, __FILEW__, __LINE__, L"")), colString(nullptr)
{
}
void TablePartitionKey::__construct_impl(ThreadContext* ctx) throw() 
{
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
	__e_obj1.add(this->colString, this);
	colString = nullptr;
	if(!prepare){
		return;
	}
}
void TablePartitionKey::addKeyColumn(TableColumnMetadata* col, ThreadContext* ctx) throw() 
{
	this->keys->add(col, ctx);
}
List<VariantValue>* TablePartitionKey::makeValues(IDatabaseRecord* record, ThreadContext* ctx) throw() 
{
	List<VariantValue>* values = (new(ctx) ArrayList<VariantValue>(ctx));
	int maxLoop = this->keys->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		TableColumnMetadata* col = this->keys->get(i, ctx);
		int colOrder = col->columnOrder;
		VariantValue* vv = record->getColumnValue(colOrder, ctx);
		values->add(vv, ctx);
	}
	return values;
}
String* TablePartitionKey::getColumnString(ThreadContext* ctx) throw() 
{
	if(this->colString == nullptr)
	{
		__GC_MV(this, &(this->colString), TableColumnMetadata::arrayToString(this->keys, ctx), String);
	}
	return this->colString;
}
String* TablePartitionKey::toString(ThreadContext* ctx) throw() 
{
	StringBuffer* buff = (new(ctx) StringBuffer(ctx));
	int maxLoop = this->keys->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		TableColumnMetadata* col = this->keys->get(i, ctx);
		if(i != 0)
		{
			buff->append(ConstStr::getCNST_STR_888(), ctx);
		}
		buff->append(col->name, ctx);
	}
	return buff->toString(ctx);
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
void TablePartitionKey::__cleanUp(ThreadContext* ctx){
}
}}}

