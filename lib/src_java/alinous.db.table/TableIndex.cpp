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
#include "alinous.btree/BTreeException.h"
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





constexpr const int TableIndex::capacity;
constexpr const int TableIndex::BLOCK_SIZE;
constexpr const int TableIndex::maxCache;
bool TableIndex::__init_done = __init_static_variables();
bool TableIndex::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"TableIndex", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 TableIndex::TableIndex(String* name, String* baseDir, bool primary, ArrayList<TableColumnMetadata>* metadata, ThreadContext* ctx) throw()  : IObject(ctx), IBtreeTableIndex(ctx), IScannableIndex(ctx), name(nullptr), baseDir(nullptr), primary(0), columns(GCUtils<ArrayList<TableColumnMetadata> >::ins(this, (new(ctx) ArrayList<TableColumnMetadata>(ctx)), ctx, __FILEW__, __LINE__, L"")), filePath(nullptr), storage(nullptr)
{
	__GC_MV(this, &(this->name), name, String);
	__GC_MV(this, &(this->baseDir), baseDir, String);
	this->primary = primary;
	GCUtils<ArrayList<TableColumnMetadata> >::mv(this, &(this->columns), metadata, ctx);
	setPath(ctx);
}
void TableIndex::__construct_impl(String* name, String* baseDir, bool primary, ArrayList<TableColumnMetadata>* metadata, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->name), name, String);
	__GC_MV(this, &(this->baseDir), baseDir, String);
	this->primary = primary;
	GCUtils<ArrayList<TableColumnMetadata> >::mv(this, &(this->columns), metadata, ctx);
	setPath(ctx);
}
 TableIndex::~TableIndex() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void TableIndex::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"TableIndex", L"~TableIndex");
	__e_obj1.add(this->name, this);
	name = nullptr;
	__e_obj1.add(this->baseDir, this);
	baseDir = nullptr;
	__e_obj1.add(this->columns, this);
	columns = nullptr;
	__e_obj1.add(this->filePath, this);
	filePath = nullptr;
	__e_obj1.add(this->storage, this);
	storage = nullptr;
	if(!prepare){
		return;
	}
}
bool TableIndex::isOpened(ThreadContext* ctx) throw() 
{
	return this->storage->isOpened(ctx);
}
void TableIndex::open(AlinousCore* core, BTreeGlobalCache* cache, ThreadContext* ctx)
{
	if(this->storage == nullptr)
	{
		File* file = (new(ctx) File(this->filePath, ctx));
		__GC_MV(this, &(this->storage), (new(ctx) BTree(ctx))->init(file, cache, core->diskCache, ctx), BTree);
	}
	if(!this->storage->isOpened(ctx))
	{
		this->storage->open(ctx);
	}
}
void TableIndex::close(ThreadContext* ctx)
{
	if(this->storage->isOpened(ctx))
	{
		this->storage->close(ctx);
	}
}
bool TableIndex::isAvailable(ArrayList<String>* columnsStr, ThreadContext* ctx) throw() 
{
	int maxLoop = columnsStr->size(ctx);
	if(maxLoop > this->columns->size(ctx))
	{
		return false;
	}
	for(int i = 0; i != maxLoop; ++i)
	{
		String* key = columnsStr->get(i, ctx);
		TableColumnMetadata* colMeta = this->columns->get(i, ctx);
		if(!key->equals(colMeta->name, ctx))
		{
			return false;
		}
	}
	return true;
}
bool TableIndex::isAvailableByScanId(ArrayList<ScanTableColumnIdentifier>* columnIds, ThreadContext* ctx) throw() 
{
	int maxLoop = columnIds->size(ctx);
	if(maxLoop > this->columns->size(ctx))
	{
		return false;
	}
	for(int i = 0; i != maxLoop; ++i)
	{
		String* key = columnIds->get(i, ctx)->getColumn(ctx);
		TableColumnMetadata* colMeta = this->columns->get(i, ctx);
		if(!key->equals(colMeta->name, ctx))
		{
			return false;
		}
	}
	return true;
}
void TableIndex::addIndexValue(DatabaseRecord* record, ThreadContext* ctx)
{
	BTreeIndexKey* indexKey = (new(ctx) BTreeIndexKey(this, record, ctx));
	TableIndexValue* positionValue = (new(ctx) TableIndexValue(record->getOid(ctx), record->getPosition(ctx), ctx));
	this->storage->gate->close(ctx);
	this->storage->putKeyValue(indexKey, positionValue, ctx);
	this->storage->gate->open(ctx);
}
void TableIndex::createIndex(AlinousCore* core, BTreeGlobalCache* cache, ThreadContext* ctx)
{
	File* file = (new(ctx) File(this->filePath, ctx));
	if(file->exists(ctx))
	{
		file->_delete(ctx);
	}
	{
		try
		{
			__GC_MV(this, &(this->storage), (new(ctx) BTree(ctx))->init(file, cache, core->diskCache, ctx), BTree);
			this->storage->initTreeStorage(32, IBTreeValue::TYPE_LONG, IBTreeValue::TYPE_LONG, (long long)capacity, (long long)64, ctx);
		}
		catch(IOException* e)
		{
			throw (new(ctx) AlinousDbException(ConstStr::getCNST_STR_1701(), e, ctx));
		}
		catch(InterruptedException* e)
		{
			throw (new(ctx) AlinousDbException(ConstStr::getCNST_STR_1701(), e, ctx));
		}
		catch(BTreeException* e)
		{
			throw (new(ctx) AlinousDbException(ConstStr::getCNST_STR_1701(), e, ctx));
		}
	}
}
int TableIndex::archiveSize(ThreadContext* ctx)
{
	int total = 4 + (this->name->length(ctx) * 2);
	total += 1 + 4;
	int maxLoop = this->columns->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		TableColumnMetadata* col = this->columns->get(i, ctx);
		total += col->fileSize(ctx);
	}
	return total;
}
void TableIndex::appendToEntry(FileStorageEntryBuilder* builder, ThreadContext* ctx)
{
	builder->putString(this->name, ctx);
	char bl = ((char)(this->primary ? 1 : 0));
	builder->putByte(bl, ctx);
	int maxLoop = this->columns->size(ctx);
	builder->putInt(maxLoop, ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		TableColumnMetadata* col = this->columns->get(i, ctx);
		col->toFileEntry(builder, ctx);
	}
}
BTree* TableIndex::getStorage(ThreadContext* ctx) throw() 
{
	return storage;
}
String* TableIndex::getName(ThreadContext* ctx) throw() 
{
	return name;
}
bool TableIndex::isPrimary(ThreadContext* ctx) throw() 
{
	return primary;
}
ArrayList<TableColumnMetadata>* TableIndex::getColumns(ThreadContext* ctx) throw() 
{
	return columns;
}
void TableIndex::setPath(ThreadContext* ctx) throw() 
{
	StringBuilder* buff = (new(ctx) StringBuilder(ctx));
	buff->append(this->baseDir, ctx)->append(name, ctx)->append(ConstStr::getCNST_STR_1702(), ctx);
	__GC_MV(this, &(this->filePath), buff->toString(ctx), String);
}
TableIndex* TableIndex::valueFromFetcher(FileStorageEntryFetcher* fetcher, String* baseDir, ThreadContext* ctx) throw() 
{
	String* name = fetcher->fetchString(ctx);
	char bl = fetcher->fetchByte(ctx);
	bool primary = bl == (char)1;
	int maxLoop = fetcher->fetchInt(ctx);
	ArrayList<TableColumnMetadata>* metadata = (new(ctx) ArrayList<TableColumnMetadata>(ctx));
	for(int i = 0; i != maxLoop; ++i)
	{
		TableColumnMetadata* col = TableColumnMetadata::loadFromFetcher(fetcher, ctx);
		metadata->add(col, ctx);
	}
	TableIndex* tableindex = (new(ctx) TableIndex(name, baseDir, primary, metadata, ctx));
	return tableindex;
}
void TableIndex::__cleanUp(ThreadContext* ctx){
}
}}}

