#include "includes.h"


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
			__GC_MV(this, &(this->dataStorage), (new(ctx) FileStorage(core->diskCache, (new(ctx) File(dataStoragePath, ctx)), ConstStr::getCNST_STR_1652(), ctx)), FileStorage);
			this->dataStorage->createStorage((long long)DatatableConstants::capacity, (long long)DatatableConstants::BLOCK_SIZE, ctx);
			__GC_MV(this, &(this->oidIndex), (new(ctx) BTree(ctx))->init((new(ctx) File(this->oidIndexPath, ctx)), cache, core->diskCache, ctx), BTree);
			this->oidIndex->initTreeStorage(32, IBTreeValue::TYPE_LONG, IBTreeValue::TYPE_LONG, (long long)DatatableConstants::capacity, (long long)64, ctx);
			StringBuilder* primname = (new(ctx) StringBuilder(ctx));
			primname->append(this->name, ctx)->append(ConstStr::getCNST_STR_1676(), ctx);
			__GC_MV(this, &(this->primaryIndex), (new(ctx) TableIndex(primname->toString(ctx), this->baseDir, true, metadata->getPrimaryKeys(ctx), ctx)), TableIndex);
			this->primaryIndex->createIndex(core, cache, ctx);
			__GC_MV(this, &(this->metadata), metadata, TableMetadata);
			__GC_MV(this, &(this->updateHistoryCache), (new(ctx) DatatableUpdateCache(this, ctx)), DatatableUpdateCache);
			this->updateHistoryCache->execCreateTable(core, cache, ctx);
			open(false, core, cache, ctx);
			__GC_MV(this, &(this->schmeUpdated), (new(ctx) Timestamp(System::currentTimeMillis(ctx), ctx)), Timestamp);
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
			throw (new(ctx) AlinousDbException(ConstStr::getCNST_STR_1677(), e, ctx));
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
		fetcher->fetchInt(ctx);
		DatabaseRecord* dbrecord = DatabaseRecord::valueFromFetcher(fetcher, ctx);
		newindex->addIndexValue(dbrecord, ctx);
	}
	scanner->endScan(ctx);
}
}}}

