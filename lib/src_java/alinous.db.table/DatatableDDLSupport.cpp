#include "include/global.h"


#include "alinous.numeric/InternalDate.h"
#include "java.sql/Timestamp.h"
#include "alinous.lock/LockObject.h"
#include "alinous.lock/ConcurrentGate.h"
#include "alinous.buffer.storage/FileStorageEntry.h"
#include "alinous.buffer.storage/IFileStorage.h"
#include "alinous.buffer.storage/FileStorageEntryReader.h"
#include "alinous.buffer.storage/FileStorage.h"
#include "alinous.buffer.storage/FileStorageEntryBuilder.h"
#include "alinous.buffer.storage/FileStorageEntryFetcher.h"
#include "alinous.compile/AbstractSrcElement.h"
#include "alinous.system/AlinousException.h"
#include "alinous.btree/IValueFetcher.h"
#include "alinous.btree/IBTreeValue.h"
#include "java.lang/Comparable.h"
#include "alinous.btree/IBTreeNode.h"
#include "alinous.btree/BTreeGlobalCache.h"
#include "alinous.btree/BTreeException.h"
#include "alinous.btree/IBTree.h"
#include "alinous.btree/BTree.h"
#include "alinous.btree/LongValue.h"
#include "alinous.btree.scan/BTreeScanner.h"
#include "alinous.db/AlinousDbException.h"
#include "alinous.runtime.parallel/ThreadPool.h"
#include "alinous.system/AlinousCore.h"
#include "alinous.db.table/DatatableConstants.h"
#include "alinous.db.table/DatabaseException.h"
#include "alinous.remote.socket/ICommandData.h"
#include "alinous.db.table/TableIndexMetadata.h"
#include "alinous.db.table/TableMetadata.h"
#include "alinous.db.table/IDatabaseRecord.h"
#include "alinous.db.table/IBtreeTableIndex.h"
#include "alinous.db.table/IScannableIndex.h"
#include "alinous.db.table/TableIndex.h"
#include "java.lang/Number.h"
#include "java.lang/Integer.h"
#include "alinous.db.table/DatabaseTableIdPublisher.h"
#include "alinous.db.table/IDatabaseTable.h"
#include "alinous.db.table/AbstractDatabaseTable.h"
#include "alinous.db.table/DatabaseRecord.h"
#include "alinous.db.table/DatatableUpdateCache.h"
#include "alinous.db.table.cache/RecordCacheEngine.h"
#include "alinous.db.table/DataTableStorageSupport.h"
#include "alinous.db.table/DatatableLockSupport.h"
#include "alinous.db.table/DatatableDDLSupport.h"

namespace alinous {namespace db {namespace table {





bool DatatableDDLSupport::__init_done = __init_static_variables();
bool DatatableDDLSupport::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"DatatableDDLSupport", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 DatatableDDLSupport::DatatableDDLSupport(String* schema, String* name, String* baseDir, ThreadContext* ctx) throw()  : IObject(ctx), DatatableLockSupport(schema, name, baseDir, ctx)
{
}
void DatatableDDLSupport::__construct_impl(String* schema, String* name, String* baseDir, ThreadContext* ctx) throw() 
{
}
 DatatableDDLSupport::~DatatableDDLSupport() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void DatatableDDLSupport::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
	DatatableLockSupport::__releaseRegerences(true, ctx);
}
void DatatableDDLSupport::createTable(TableMetadata* metadata, ThreadPool* threadPool, AlinousCore* core, BTreeGlobalCache* cache, ThreadContext* ctx)
{
	getDataStorageName(ctx);
	getOidIndexName(ctx);
	{
		try
		{
			File* dir = (new(ctx) File(this->baseDir, ctx));
			if(!dir->exists(ctx))
			{
				dir->mkdirs(ctx);
			}
			__GC_MV(this, &(this->dataStorage), (new(ctx) FileStorage(core->diskCache, (new(ctx) File(dataStoragePath, ctx)), ConstStr::getCNST_STR_1670(), ctx)), FileStorage);
			this->dataStorage->createStorage((long long)DatatableConstants::capacity, (long long)DatatableConstants::BLOCK_SIZE, ctx);
			__GC_MV(this, &(this->oidIndex), (new(ctx) BTree(ctx))->init((new(ctx) File(this->oidIndexPath, ctx)), cache, core->diskCache, ctx), BTree);
			this->oidIndex->initTreeStorage(32, IBTreeValue::TYPE_LONG, IBTreeValue::TYPE_LONG, (long long)DatatableConstants::capacity, (long long)64, ctx);
			StringBuilder* primname = (new(ctx) StringBuilder(ctx));
			primname->append(this->name, ctx)->append(ConstStr::getCNST_STR_1742(), ctx);
			__GC_MV(this, &(this->primaryIndex), (new(ctx) TableIndex(primname->toString(ctx), this->baseDir, true, metadata->getPrimaryKeys(ctx), ctx)), IScannableIndex);
			this->primaryIndex->createIndex(core, cache, ctx);
			__GC_MV(this, &(this->metadata), metadata, TableMetadata);
			__GC_MV(this, &(this->updateHistoryCache), (new(ctx) DatatableUpdateCache(this, ctx)), DatatableUpdateCache);
			this->updateHistoryCache->execCreateTable(core, cache, ctx);
			open(false, core, cache, ctx);
			__GC_MV(this, &(this->schmeUpdated), (new(ctx) Timestamp(System::currentTimeMillis(ctx), ctx)), Timestamp);
			setNextOid((long long)1, ctx);
			syncScheme(ctx);
		}
		catch(IOException* e)
		{
			close(ctx);
			throw e;
		}
		catch(InterruptedException* e)
		{
			close(ctx);
			throw e;
		}
		catch(BTreeException* e)
		{
			close(ctx);
			throw e;
		}
		catch(DatabaseException* e)
		{
			close(ctx);
			throw e;
		}
		catch(AlinousException* e)
		{
			close(ctx);
			throw e;
		}
	}
}
void DatatableDDLSupport::createIndex(String* indexName, ArrayList<String>* columns, AlinousCore* core, BTreeGlobalCache* cache, ThreadContext* ctx)
{
	lockStorage(ctx);
	if(this->metadata->checkHasIndex(columns, indexName, ctx))
	{
		unlockStorage(ctx);
		throw (new(ctx) AlinousDbException(ConstStr::getCNST_STR_1743(), ctx));
	}
	{
		try
		{
			TableIndexMetadata* metadata = (new(ctx) TableIndexMetadata(indexName, columns, ctx));
			metadata->setupColumnMetadata(this->metadata, ctx);
			this->metadata->addindex(metadata, ctx);
			TableIndex* newindex = (new(ctx) TableIndex(indexName, this->baseDir, false, metadata->getMetadata(ctx), ctx));
			newindex->createIndex(core, cache, ctx);
			this->indexes->add(newindex, ctx);
			newindex->open(core, cache, ctx);
			buildFirstindexValue(newindex, ctx);
			__GC_MV(this, &(this->schmeUpdated), (new(ctx) Timestamp(System::currentTimeMillis(ctx), ctx)), Timestamp);
			syncScheme(ctx);
		}
		catch(Throwable* e)
		{
			unlockStorage(ctx);
			throw (new(ctx) AlinousDbException(ConstStr::getCNST_STR_1744(), e, ctx));
		}
	}
	unlockStorage(ctx);
}
void DatatableDDLSupport::buildFirstindexValue(TableIndex* newindex, ThreadContext* ctx)
{
	BTreeScanner* scanner = (new(ctx) BTreeScanner(this->oidIndex, ctx));
	FileStorageEntryReader* reader = nullptr;
	FileStorageEntry* entry = nullptr;
	FileStorageEntryFetcher* fetcher = (new(ctx) FileStorageEntryFetcher(ctx));
	scanner->startScan(false, ctx);
	reader = this->dataStorage->getReader(ctx);
	while(scanner->hasNext(ctx))
	{
		IBTreeNode* lnode = scanner->next(ctx);
		ArrayList<IBTreeValue>* values = lnode->getValues(ctx);
		LongValue* longValue = static_cast<LongValue*>(values->get(0, ctx));
		entry = reader->read(longValue->value, ctx);
		fetcher->load(entry, ctx);
		int type = fetcher->fetchInt(ctx);
		if(type != IBTreeValue::TYPE_DATABASE_RECORD)
		{
			throw (new(ctx) AlinousException(ConstStr::getCNST_STR_1745(), ctx));
		}
		DatabaseRecord* dbrecord = DatabaseRecord::valueFromFetcher(fetcher, ctx);
		newindex->addIndexValue(dbrecord, ctx);
	}
	scanner->endScan(ctx);
}
void DatatableDDLSupport::includes(DatatableConstants* arg0, DatabaseException* arg2, ThreadContext* ctx) throw() 
{
}
void DatatableDDLSupport::__cleanUp(ThreadContext* ctx){
}
}}}

