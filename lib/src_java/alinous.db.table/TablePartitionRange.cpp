#include "include/global.h"


#include "alinous.lock/LockObject.h"
#include "alinous.lock/ConcurrentGate.h"
#include "alinous.buffer.storage/FileStorageEntry.h"
#include "alinous.buffer.storage/IFileStorage.h"
#include "alinous.buffer.storage/FileStorageEntryWriter.h"
#include "alinous.buffer.storage/FileStorageEntryReader.h"
#include "alinous.buffer.storage/FileStorage.h"
#include "alinous.buffer.storage/FileStorageEntryBuilder.h"
#include "alinous.buffer.storage/FileStorageEntryFetcher.h"
#include "alinous.compile/AbstractSrcElement.h"
#include "alinous.system/AlinousException.h"
#include "alinous.runtime/ExecutionException.h"
#include "alinous.runtime.dom/VariableException.h"
#include "java.lang/Comparable.h"
#include "alinous.btree/IBTreeKey.h"
#include "alinous.btree/IValueFetcher.h"
#include "alinous.btree/IBTreeValue.h"
#include "alinous.btree/IBTreeNode.h"
#include "alinous.btree/BTreeGlobalCache.h"
#include "alinous.btree/IBTree.h"
#include "alinous.btree/BTree.h"
#include "alinous.compile.sql.analyze/ScanTableIdentifier.h"
#include "alinous.btree.scan/BTreeScanner.h"
#include "alinous.compile.sql.analyze/ScanTableColumnIdentifier.h"
#include "alinous.db/AlinousDbException.h"
#include "alinous.db.table/DatabaseException.h"
#include "java.util/Locale.h"
#include "java.util/Calendar.h"
#include "java.util/GregorianCalendar.h"
#include "java.util/Date.h"
#include "alinous.numeric/InternalDate.h"
#include "java.util/TimeZone.h"
#include "java.sql/Timestamp.h"
#include "alinous.remote.socket/NetworkBinaryBuffer.h"
#include "alinous.remote.socket/ICommandData.h"
#include "alinous.runtime.dom/IAlinousVariable.h"
#include "alinous.runtime.dom/NetworkAlinousVariableFactory.h"
#include "alinous.runtime.variant/VariantValue.h"
#include "alinous.db.table/IDatabaseRecord.h"
#include "alinous.db.table.lockmonitor/IThreadLocker.h"
#include "alinous.runtime.parallel/ThreadPool.h"
#include "alinous.runtime.parallel/IThreadAction.h"
#include "alinous.runtime.parallel/SequentialBackgroundJob.h"
#include "alinous.system/ISystemLog.h"
#include "alinous.system/AlinousCore.h"
#include "java.lang/Number.h"
#include "java.lang/Integer.h"
#include "alinous.db.table/TableColumnMetadata.h"
#include "alinous.db.table/DatabaseRecord.h"
#include "alinous.db.table/IScannableIndex.h"
#include "alinous.db.table/TableMetadataUnique.h"
#include "alinous.db.table/TablePartitionKey.h"
#include "alinous.compile.sql.analyze/ScanUnique.h"
#include "alinous.db.table/TableIndexMetadata.h"
#include "alinous.db.table/TablePartitionKeyCollection.h"
#include "alinous.db.table/TablePartitionRange.h"
#include "alinous.db.table/TablePartitionRangeCollection.h"
#include "alinous.db.table/TableMetadata.h"
#include "alinous.db.table/IDatabaseTable.h"
#include "alinous.db.trx.scan/ITableTargetScanner.h"
#include "alinous.db.trx/DbTransaction.h"
#include "alinous.db.table/IBtreeTableIndex.h"
#include "alinous.db.table/BTreeIndexKey.h"
#include "alinous.db.table/TableIndexValue.h"
#include "alinous.db.table/TableIndex.h"
#include "alinous.btree/LongValue.h"
#include "alinous.db.table/AbstractDatabaseTable.h"
#include "alinous.db.table/DataTableStorageSupport.h"
#include "alinous.db.table/DatatableLockSupport.h"
#include "alinous.db.table/DatatableDDLSupport.h"
#include "alinous.db.table/DatatableUpdateSupport.h"
#include "alinous.db.table/IndexInsertJob.h"
#include "alinous.db.table/OidIndexJob.h"
#include "alinous.db.table.cache/RecordCacheEngine.h"
#include "alinous.db.table.lockmonitor/DBThreadMonitor.h"
#include "alinous.db.table/DatabaseTable.h"
#include "alinous.db.table/DatatableUpdateCache.h"
#include "alinous.db.table/DatabaseTableIdPublisher.h"
#include "alinous.db.table/IOidPublisher.h"
#include "alinous.db.table/OidPublisherFactory.h"
#include "alinous.db.table/LocalOidCounter.h"
#include "alinous.db.table/LocalOidPublisher.h"
#include "alinous.db.table/DatatableConstants.h"

namespace alinous {namespace db {namespace table {





bool TablePartitionRange::__init_done = __init_static_variables();
bool TablePartitionRange::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"TablePartitionRange", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 TablePartitionRange::TablePartitionRange(ThreadContext* ctx) throw()  : IObject(ctx), ICommandData(ctx), key(nullptr), max(GCUtils<List<VariantValue> >::ins(this, (new(ctx) ArrayList<VariantValue>(ctx)), ctx, __FILEW__, __LINE__, L"")), min(GCUtils<List<VariantValue> >::ins(this, (new(ctx) ArrayList<VariantValue>(ctx)), ctx, __FILEW__, __LINE__, L""))
{
}
void TablePartitionRange::__construct_impl(ThreadContext* ctx) throw() 
{
}
 TablePartitionRange::TablePartitionRange(TablePartitionKey* key, ThreadContext* ctx) throw()  : IObject(ctx), ICommandData(ctx), key(nullptr), max(GCUtils<List<VariantValue> >::ins(this, (new(ctx) ArrayList<VariantValue>(ctx)), ctx, __FILEW__, __LINE__, L"")), min(GCUtils<List<VariantValue> >::ins(this, (new(ctx) ArrayList<VariantValue>(ctx)), ctx, __FILEW__, __LINE__, L""))
{
	__GC_MV(this, &(this->key), key, TablePartitionKey);
}
void TablePartitionRange::__construct_impl(TablePartitionKey* key, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->key), key, TablePartitionKey);
}
 TablePartitionRange::~TablePartitionRange() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void TablePartitionRange::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"TablePartitionRange", L"~TablePartitionRange");
	__e_obj1.add(this->key, this);
	key = nullptr;
	__e_obj1.add(this->max, this);
	max = nullptr;
	__e_obj1.add(this->min, this);
	min = nullptr;
	if(!prepare){
		return;
	}
}
void TablePartitionRange::addMaxKeyValue(VariantValue* value, ThreadContext* ctx) throw() 
{
	this->max->add(value, ctx);
}
void TablePartitionRange::addMinKeyValue(VariantValue* value, ThreadContext* ctx) throw() 
{
	this->min->add(value, ctx);
}
TablePartitionKey* TablePartitionRange::getKey(ThreadContext* ctx) throw() 
{
	return key;
}
List<VariantValue>* TablePartitionRange::getMax(ThreadContext* ctx) throw() 
{
	return max;
}
List<VariantValue>* TablePartitionRange::getMin(ThreadContext* ctx) throw() 
{
	return min;
}
int TablePartitionRange::fileSize(ThreadContext* ctx)
{
	int total = this->key->fileSize(ctx);
	int maxLoop = this->max->size(ctx);
	total += 4;
	for(int i = 0; i != maxLoop; ++i)
	{
		VariantValue* value = this->max->get(i, ctx);
		total += value->bufferSize(ctx);
	}
	maxLoop = this->min->size(ctx);
	total += 4;
	for(int i = 0; i != maxLoop; ++i)
	{
		VariantValue* value = this->min->get(i, ctx);
		total += value->bufferSize(ctx);
	}
	return total;
}
void TablePartitionRange::toFileEntry(FileStorageEntryBuilder* builder, ThreadContext* ctx)
{
	this->key->toFileEntry(builder, ctx);
	int maxLoop = this->max->size(ctx);
	builder->putInt(maxLoop, ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		VariantValue* value = this->max->get(i, ctx);
		value->appendToEntry(builder, ctx);
	}
	maxLoop = this->min->size(ctx);
	builder->putInt(maxLoop, ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		VariantValue* value = this->min->get(i, ctx);
		value->appendToEntry(builder, ctx);
	}
}
void TablePartitionRange::readData(NetworkBinaryBuffer* buff, ThreadContext* ctx)
{
	__GC_MV(this, &(this->key), TablePartitionKey::fromNetwork(buff, ctx), TablePartitionKey);
	int maxLoop = buff->getInt(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		IAlinousVariable* val = NetworkAlinousVariableFactory::fromNetworkData(buff, ctx);
		if(val == nullptr || !((dynamic_cast<VariantValue*>(val) != 0)))
		{
			throw (new(ctx) VariableException(ConstStr::getCNST_STR_1119(), ctx));
		}
		VariantValue* vv = static_cast<VariantValue*>(val);
		this->max->add(vv, ctx);
	}
	maxLoop = buff->getInt(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		IAlinousVariable* val = NetworkAlinousVariableFactory::fromNetworkData(buff, ctx);
		if(val == nullptr || !((dynamic_cast<VariantValue*>(val) != 0)))
		{
			throw (new(ctx) VariableException(ConstStr::getCNST_STR_1119(), ctx));
		}
		VariantValue* vv = static_cast<VariantValue*>(val);
		this->min->add(vv, ctx);
	}
}
void TablePartitionRange::writeData(NetworkBinaryBuffer* buff, ThreadContext* ctx)
{
	this->key->writeData(buff, ctx);
	int maxLoop = this->max->size(ctx);
	buff->putInt(maxLoop, ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		VariantValue* vv = this->max->get(i, ctx);
		vv->writeData(buff, ctx);
	}
	maxLoop = this->min->size(ctx);
	buff->putInt(maxLoop, ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		VariantValue* vv = this->min->get(i, ctx);
		vv->writeData(buff, ctx);
	}
}
TablePartitionRange* TablePartitionRange::loadFromFetcher(FileStorageEntryFetcher* fetcher, ThreadContext* ctx)
{
	TablePartitionRange* range = (new(ctx) TablePartitionRange(ctx));
	__GC_MV(range, &(range->key), TablePartitionKey::loadFromFetcher(fetcher, ctx), TablePartitionKey);
	int maxLoop = fetcher->fetchInt(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		VariantValue* vv = VariantValue::valueFromFetcher(fetcher, ctx);
		range->max->add(vv, ctx);
	}
	maxLoop = fetcher->fetchInt(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		VariantValue* vv = VariantValue::valueFromFetcher(fetcher, ctx);
		range->min->add(vv, ctx);
	}
	return range;
}
TablePartitionRange* TablePartitionRange::fromNetwork(NetworkBinaryBuffer* buff, ThreadContext* ctx)
{
	TablePartitionRange* range = (new(ctx) TablePartitionRange(ctx));
	range->readData(buff, ctx);
	return range;
}
void TablePartitionRange::__cleanUp(ThreadContext* ctx){
}
}}}

