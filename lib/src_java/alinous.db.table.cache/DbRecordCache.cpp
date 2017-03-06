#include "include/global.h"


#include "java.util/BitSet.h"
#include "alinous.lock/ConcurrentGate.h"
#include "alinous.buffer.storage/FileStorageEntry.h"
#include "alinous.buffer.storage/IFileStorage.h"
#include "alinous.buffer.storage/FileStorageEntryWriter.h"
#include "alinous.buffer.storage/FileStorageEntryReader.h"
#include "alinous.buffer.storage/FileStorage.h"
#include "alinous.buffer.storage/FileStorageEntryBuilder.h"
#include "alinous.compile/AbstractSrcElement.h"
#include "alinous.system/AlinousException.h"
#include "java.lang/Comparable.h"
#include "alinous.btree/IBTreeKey.h"
#include "alinous.buffer.storage/FileStorageEntryFetcher.h"
#include "alinous.btree/IValueFetcher.h"
#include "alinous.btree/IBTreeValue.h"
#include "alinous.btree/IBTreeNode.h"
#include "alinous.btree/LongValue.h"
#include "alinous.db/AlinousDbException.h"
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
#include "alinous.buffer/FifoElement.h"
#include "alinous.buffer/FifoList.h"
#include "alinous.buffer/FifoIterator.h"
#include "alinous.btree/BTreeGlobalCache.h"
#include "alinous.runtime.parallel/ThreadPool.h"
#include "alinous.runtime.parallel/IThreadAction.h"
#include "alinous.runtime.parallel/SequentialBackgroundJob.h"
#include "alinous.system/ISystemLog.h"
#include "alinous.system/AlinousCore.h"
#include "java.lang/Number.h"
#include "java.lang/Integer.h"
#include "alinous.btree/IBTree.h"
#include "alinous.btree/BTree.h"
#include "alinous.db.table/IScannableIndex.h"
#include "alinous.db.table/TableIndexMetadata.h"
#include "alinous.db.table/TableMetadata.h"
#include "alinous.db.table/IDatabaseTable.h"
#include "alinous.db.table/DatabaseRecord.h"
#include "alinous.btree.scan/BTreeScanner.h"
#include "alinous.db.table/IBtreeTableIndex.h"
#include "alinous.db.table/BTreeIndexKey.h"
#include "alinous.db.table/TableIndex.h"
#include "alinous.db.table/DatabaseException.h"
#include "alinous.db.table/AbstractDatabaseTable.h"
#include "alinous.db.table/DatatableUpdateCache.h"
#include "alinous.db.table/DataTableStorageSupport.h"
#include "alinous.db.table/DatatableLockSupport.h"
#include "alinous.db.table/DatatableDDLSupport.h"
#include "alinous.db.table/DatatableUpdateSupport.h"
#include "alinous.db.table.cache/DbRecordCache.h"
#include "alinous.db.table.cache/RecordCacheEngine.h"
#include "alinous.db.table.cache/DbRecordHashArray.h"
#include "alinous.db.table.cache/DbREcordHashListIterator.h"
#include "alinous.db.table.cache/DbRecordHashMainList.h"

namespace alinous {namespace db {namespace table {namespace cache {





bool DbRecordCache::__init_done = __init_static_variables();
bool DbRecordCache::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"DbRecordCache", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 DbRecordCache::DbRecordCache(ThreadContext* ctx) throw()  : IObject(ctx), fifo(GCUtils<FifoList<DatabaseRecord> >::ins(this, (new(ctx) FifoList<DatabaseRecord>(ctx)), ctx, __FILEW__, __LINE__, L"")), mainList(nullptr), spin(__GC_INS(this, (new(ctx) SpinMutex(ctx)), SpinMutex)), num(0), MAX_HASH(0)
{
}
void DbRecordCache::__construct_impl(ThreadContext* ctx) throw() 
{
}
 DbRecordCache::~DbRecordCache() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void DbRecordCache::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"DbRecordCache", L"~DbRecordCache");
	__e_obj1.add(this->fifo, this);
	fifo = nullptr;
	__e_obj1.add(this->mainList, this);
	mainList = nullptr;
	__e_obj1.add(this->spin, this);
	spin = nullptr;
	if(!prepare){
		return;
	}
}
DbRecordCache* DbRecordCache::init(int MAX_HASH, ThreadContext* ctx)
{
	__GC_MV(this, &(this->mainList), (new(ctx) DbRecordHashMainList(ctx))->init(MAX_HASH, ctx), DbRecordHashMainList);
	this->MAX_HASH = MAX_HASH;
	return this;
}
void DbRecordCache::addCachedRecord(IDatabaseTable* table, DatabaseRecord* record, ThreadContext* ctx)
{
	record->setStorageForCache(table, ctx);
	spin->lock(ctx);
	this->fifo->add(record, ctx);
	this->mainList->addElement(record, ctx);
	this->num ++ ;
	if(this->num > this->MAX_HASH)
	{
		DatabaseRecord* delrecord = this->fifo->remove(0, ctx);
		this->mainList->removeByObj(delrecord, ctx);
		this->num -- ;
	}
	spin->unlock(ctx);
}
DatabaseRecord* DbRecordCache::loadRecord(DataTableStorageSupport* table, long long position, ThreadContext* ctx)
{
	spin->lock(ctx);
	DatabaseRecord* record = this->mainList->search(table, position, ctx);
	spin->unlock(ctx);
	return record;
}
void DbRecordCache::__cleanUp(ThreadContext* ctx){
}
}}}}

