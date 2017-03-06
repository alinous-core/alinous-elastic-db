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
#include "alinous.db.table/IBtreeTableIndex.h"
#include "alinous.db.table/BTreeIndexKey.h"
#include "alinous.db.trx.scan/ScanResultIndexKey.h"
#include "alinous.db.trx.scan/ITableTargetScanner.h"
#include "alinous.db.trx/DbTransaction.h"
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





bool BTreeIndexKey::__init_done = __init_static_variables();
bool BTreeIndexKey::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"BTreeIndexKey", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 BTreeIndexKey::BTreeIndexKey(ThreadContext* ctx) throw()  : IObject(ctx), IBTreeKey(ctx), values(GCUtils<ArrayList<VariantValue> >::ins(this, (new(ctx) ArrayList<VariantValue>(ctx)), ctx, __FILEW__, __LINE__, L""))
{
}
void BTreeIndexKey::__construct_impl(ThreadContext* ctx) throw() 
{
}
 BTreeIndexKey::BTreeIndexKey(ScanResultIndexKey* indexKeyValue, ThreadContext* ctx) throw()  : IObject(ctx), IBTreeKey(ctx), values(GCUtils<ArrayList<VariantValue> >::ins(this, (new(ctx) ArrayList<VariantValue>(ctx)), ctx, __FILEW__, __LINE__, L""))
{
	int maxLoop = indexKeyValue->getNumCols(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		VariantValue* vv = indexKeyValue->get(i, ctx);
		this->values->add(vv, ctx);
	}
}
void BTreeIndexKey::__construct_impl(ScanResultIndexKey* indexKeyValue, ThreadContext* ctx) throw() 
{
	int maxLoop = indexKeyValue->getNumCols(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		VariantValue* vv = indexKeyValue->get(i, ctx);
		this->values->add(vv, ctx);
	}
}
 BTreeIndexKey::BTreeIndexKey(IBtreeTableIndex* index, IDatabaseRecord* dbrecord, ThreadContext* ctx) throw()  : IObject(ctx), IBTreeKey(ctx), values(GCUtils<ArrayList<VariantValue> >::ins(this, (new(ctx) ArrayList<VariantValue>(ctx)), ctx, __FILEW__, __LINE__, L""))
{
	ArrayList<TableColumnMetadata>* list = index->getColumns(ctx);
	int maxLoop = list->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		TableColumnMetadata* col = list->get(i, ctx);
		int colOrder = col->columnOrder;
		VariantValue* value = dbrecord->getColumnValue(colOrder, ctx);
		this->values->add(value, ctx);
	}
}
void BTreeIndexKey::__construct_impl(IBtreeTableIndex* index, IDatabaseRecord* dbrecord, ThreadContext* ctx) throw() 
{
	ArrayList<TableColumnMetadata>* list = index->getColumns(ctx);
	int maxLoop = list->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		TableColumnMetadata* col = list->get(i, ctx);
		int colOrder = col->columnOrder;
		VariantValue* value = dbrecord->getColumnValue(colOrder, ctx);
		this->values->add(value, ctx);
	}
}
 BTreeIndexKey::~BTreeIndexKey() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void BTreeIndexKey::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"BTreeIndexKey", L"~BTreeIndexKey");
	__e_obj1.add(this->values, this);
	values = nullptr;
	if(!prepare){
		return;
	}
}
int BTreeIndexKey::compareTo(IBTreeKey* another, ThreadContext* ctx) throw() 
{
	BTreeIndexKey* otherIndex = static_cast<BTreeIndexKey*>(another);
	int maxLoop = this->values->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		VariantValue* value = this->values->get(i, ctx);
		VariantValue* other = otherIndex->values->get(i, ctx);
		int result = value->compareTo(other, ctx);
		if(result != 0)
		{
			return result;
		}
	}
	return 0;
}
int BTreeIndexKey::getNumCols(ThreadContext* ctx) throw() 
{
	return this->values->size(ctx);
}
bool BTreeIndexKey::equals(IObject* obj, ThreadContext* ctx) throw() 
{
	BTreeIndexKey* otherIndex = dynamic_cast<BTreeIndexKey*>(obj);
	int maxLoop = this->values->size(ctx);
	if(otherIndex->getNumCols(ctx) != maxLoop)
	{
		return false;
	}
	for(int i = 0; i != maxLoop; ++i)
	{
		VariantValue* value = this->values->get(i, ctx);
		VariantValue* other = otherIndex->values->get(i, ctx);
		int result = value->compareTo(other, ctx);
		if(result != 0)
		{
			return false;
		}
	}
	return true;
}
void BTreeIndexKey::appendToEntry(FileStorageEntryBuilder* builder, ThreadContext* ctx)
{
	builder->putInt(IBTreeKey::TYPE_BTREE_INDEX_KEY, ctx);
	int maxLoop = this->values->size(ctx);
	builder->putInt(maxLoop, ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		VariantValue* value = this->values->get(i, ctx);
		value->appendToEntry(builder, ctx);
	}
}
int BTreeIndexKey::size(ThreadContext* ctx)
{
	int total = 4 + 4;
	int maxLoop = this->values->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		VariantValue* value = this->values->get(i, ctx);
		total += value->bufferSize(ctx);
	}
	return total;
}
BTreeIndexKey* BTreeIndexKey::fetchFromEntry(FileStorageEntryFetcher* fetcher, ThreadContext* ctx)
{
	BTreeIndexKey* indexKey = (new(ctx) BTreeIndexKey(ctx));
	int maxLoop = fetcher->fetchInt(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		VariantValue::valueFromFetcher(fetcher, ctx);
	}
	return indexKey;
}
void BTreeIndexKey::__cleanUp(ThreadContext* ctx){
}
int BTreeIndexKey::ValueCompare::operator() (IBTreeKey* _this, IBTreeKey* another, ThreadContext* ctx) const throw()
{
	return _this->compareTo(another, ctx);
}
}}}

