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
#include "alinous.db.trx.cache/CachedRecord.h"
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





bool DatabaseRecord::__init_done = __init_static_variables();
bool DatabaseRecord::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"DatabaseRecord", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 DatabaseRecord::DatabaseRecord(long long oid, int numColumn, long long CommitId, ThreadContext* ctx) throw()  : IObject(ctx), IDatabaseRecord(ctx), position(0), oid(0), lastUpdateCommitId(0), insertedCommitId(0), deletedCommitId(0), values(GCUtils<ArrayList<VariantValue> >::ins(this, (new(ctx) ArrayList<VariantValue>(ctx)), ctx, __FILEW__, __LINE__, L"")), storageForCache(nullptr), hashcode(0)
{
	this->oid = oid;
	this->lastUpdateCommitId = 0;
	this->insertedCommitId = CommitId;
	this->deletedCommitId = 0;
	for(int i = 0; i != numColumn; ++i)
	{
		this->values->add((new(ctx) VariantValue(ctx)), ctx);
	}
}
void DatabaseRecord::__construct_impl(long long oid, int numColumn, long long CommitId, ThreadContext* ctx) throw() 
{
	this->oid = oid;
	this->lastUpdateCommitId = 0;
	this->insertedCommitId = CommitId;
	this->deletedCommitId = 0;
	for(int i = 0; i != numColumn; ++i)
	{
		this->values->add((new(ctx) VariantValue(ctx)), ctx);
	}
}
 DatabaseRecord::DatabaseRecord(long long oid, int numColumn, long long CommitId, IDatabaseRecord* data, ThreadContext* ctx) throw()  : IObject(ctx), IDatabaseRecord(ctx), position(0), oid(0), lastUpdateCommitId(0), insertedCommitId(0), deletedCommitId(0), values(GCUtils<ArrayList<VariantValue> >::ins(this, (new(ctx) ArrayList<VariantValue>(ctx)), ctx, __FILEW__, __LINE__, L"")), storageForCache(nullptr), hashcode(0)
{
	this->oid = oid;
	this->lastUpdateCommitId = 0;
	this->insertedCommitId = CommitId;
	this->deletedCommitId = 0;
	for(int i = 0; i != numColumn; ++i)
	{
		this->values->add(data->getColumnValue(i, ctx), ctx);
	}
}
void DatabaseRecord::__construct_impl(long long oid, int numColumn, long long CommitId, IDatabaseRecord* data, ThreadContext* ctx) throw() 
{
	this->oid = oid;
	this->lastUpdateCommitId = 0;
	this->insertedCommitId = CommitId;
	this->deletedCommitId = 0;
	for(int i = 0; i != numColumn; ++i)
	{
		this->values->add(data->getColumnValue(i, ctx), ctx);
	}
}
 DatabaseRecord::~DatabaseRecord() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void DatabaseRecord::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"DatabaseRecord", L"~DatabaseRecord");
	__e_obj1.add(this->values, this);
	values = nullptr;
	__e_obj1.add(this->storageForCache, this);
	storageForCache = nullptr;
	if(!prepare){
		return;
	}
}
int DatabaseRecord::getNumValues(ThreadContext* ctx) throw() 
{
	return this->values->size(ctx);
}
VariantValue* DatabaseRecord::getColumnValue(int index, ThreadContext* ctx) throw() 
{
	return this->values->get(index, ctx);
}
void DatabaseRecord::setValue(int index, VariantValue* value, ThreadContext* ctx) throw() 
{
	this->values->set(index, value, ctx);
}
void DatabaseRecord::addValue(VariantValue* vv, ThreadContext* ctx) throw() 
{
	this->values->add(vv, ctx);
}
void DatabaseRecord::appendToEntry(FileStorageEntryBuilder* builder, ThreadContext* ctx)
{
	builder->putInt(IBTreeValue::TYPE_DATABASE_RECORD, ctx);
	builder->putLong(this->oid, ctx);
	builder->putLong(this->lastUpdateCommitId, ctx);
	builder->putLong(this->insertedCommitId, ctx);
	builder->putLong(this->deletedCommitId, ctx);
	int maxLoop = this->values->size(ctx);
	builder->putInt(maxLoop, ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		VariantValue* variant = this->values->get(i, ctx);
		variant->appendToEntry(builder, ctx);
	}
}
int DatabaseRecord::diskSize(ThreadContext* ctx)
{
	int total = 4 + 8;
	total += 8 * 3;
	int maxLoop = this->values->size(ctx);
	total += 4;
	for(int i = 0; i != maxLoop; ++i)
	{
		VariantValue* val = this->values->get(i, ctx);
		total += val->bufferSize(ctx);
	}
	return total;
}
IValueFetcher* DatabaseRecord::getFetcher(ThreadContext* ctx) throw() 
{
	return (new(ctx) DatabaseRecord::ValueFetcher(ctx));
}
long long DatabaseRecord::getOid(ThreadContext* ctx) throw() 
{
	return oid;
}
void DatabaseRecord::setOid(long long oid, ThreadContext* ctx) throw() 
{
	this->oid = oid;
}
long long DatabaseRecord::getLastUpdateCommitId(ThreadContext* ctx) throw() 
{
	return lastUpdateCommitId;
}
void DatabaseRecord::setLastUpdateCommitId(long long lastUpdateCommitId, ThreadContext* ctx) throw() 
{
	this->lastUpdateCommitId = lastUpdateCommitId;
}
long long DatabaseRecord::getInsertedCommitId(ThreadContext* ctx) throw() 
{
	return insertedCommitId;
}
void DatabaseRecord::setInsertedCommitId(long long insertedCommitId, ThreadContext* ctx) throw() 
{
	this->insertedCommitId = insertedCommitId;
}
long long DatabaseRecord::getDeletedCommitId(ThreadContext* ctx) throw() 
{
	return deletedCommitId;
}
void DatabaseRecord::setDeletedCommitId(long long deletedCommitId, ThreadContext* ctx) throw() 
{
	this->deletedCommitId = deletedCommitId;
}
long long DatabaseRecord::getMaxCommitId(ThreadContext* ctx) throw() 
{
	return this->insertedCommitId < this->lastUpdateCommitId ? this->lastUpdateCommitId : this->insertedCommitId;
}
String* DatabaseRecord::toString(ThreadContext* ctx) throw() 
{
	StringBuilder* buff = (new(ctx) StringBuilder(ctx));
	int maxLoop = this->values->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		VariantValue* variant = this->values->get(i, ctx);
		if(i != 0)
		{
			buff->append(ConstStr::getCNST_STR_73(), ctx);
		}
		buff->append(variant->toString(ctx), ctx);
	}
	return buff->toString(ctx);
}
long long DatabaseRecord::getPosition(ThreadContext* ctx) throw() 
{
	return position;
}
void DatabaseRecord::setPosition(long long position, ThreadContext* ctx) throw() 
{
	this->position = position;
}
bool DatabaseRecord::equals(IObject* obj, ThreadContext* ctx) throw() 
{
	return this == obj;
}
int DatabaseRecord::getHashKey(ThreadContext* ctx) throw() 
{
	return this->hashcode;
}
IDatabaseTable* DatabaseRecord::getStorageForCache(ThreadContext* ctx) throw() 
{
	return storageForCache;
}
void DatabaseRecord::setStorageForCache(IDatabaseTable* storageForCache, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->storageForCache), storageForCache, IDatabaseTable);
	this->hashcode = ((int)(((unsigned long long)((this->position + this->storageForCache->getTableId(ctx)->intValue(ctx)) * 2654404609L))>> 32));
}
ArrayList<VariantValue>* DatabaseRecord::getValues(ThreadContext* ctx) throw() 
{
	return values;
}
int DatabaseRecord::getKind(ThreadContext* ctx) throw() 
{
	return IDatabaseRecord::NORMAL_RECORD;
}
int DatabaseRecord::getNumColumn(ThreadContext* ctx) throw() 
{
	return this->values->size(ctx);
}
DatabaseRecord* DatabaseRecord::valueFromFetcher(FileStorageEntryFetcher* fetcher, ThreadContext* ctx)
{
	long long oid = fetcher->fetchLong(ctx);
	long long uid = fetcher->fetchLong(ctx);
	long long iid = fetcher->fetchLong(ctx);
	long long did = fetcher->fetchLong(ctx);
	int maxLoop = fetcher->fetchInt(ctx);
	DatabaseRecord* rec = (new(ctx) DatabaseRecord(oid, maxLoop, 0, ctx));
	rec->setPosition(fetcher->getPosition(ctx), ctx);
	rec->lastUpdateCommitId = uid;
	rec->setInsertedCommitId(iid, ctx);
	rec->setDeletedCommitId(did, ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		VariantValue* variant = VariantValue::valueFromFetcher(fetcher, ctx);
		rec->setValue(i, variant, ctx);
	}
	return rec;
}
void DatabaseRecord::__cleanUp(ThreadContext* ctx){
}
}}}

namespace alinous {namespace db {namespace table {





bool DatabaseRecord::ValueFetcher::__init_done = __init_static_variables();
bool DatabaseRecord::ValueFetcher::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"DatabaseRecord::ValueFetcher", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 DatabaseRecord::ValueFetcher::ValueFetcher(ThreadContext* ctx) throw()  : IObject(ctx), IValueFetcher(ctx)
{
}
void DatabaseRecord::ValueFetcher::__construct_impl(ThreadContext* ctx) throw() 
{
}
 DatabaseRecord::ValueFetcher::~ValueFetcher() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void DatabaseRecord::ValueFetcher::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
}
IBTreeValue* DatabaseRecord::ValueFetcher::valueFromFetcher(FileStorageEntryFetcher* fetcher, ThreadContext* ctx)
{
	return CachedRecord::valueFromFetcher(fetcher, ctx);
}
void DatabaseRecord::ValueFetcher::__cleanUp(ThreadContext* ctx){
}
}}}

