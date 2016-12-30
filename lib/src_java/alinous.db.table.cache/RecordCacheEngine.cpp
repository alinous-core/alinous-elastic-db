#include "includes.h"


namespace alinous {namespace db {namespace table {namespace cache {





bool RecordCacheEngine::__init_done = __init_static_variables();
bool RecordCacheEngine::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"RecordCacheEngine", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 RecordCacheEngine::~RecordCacheEngine() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void RecordCacheEngine::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"RecordCacheEngine", L"~RecordCacheEngine");
	__e_obj1.add(this->cache, this);
	cache = nullptr;
	if(!prepare){
		return;
	}
}
RecordCacheEngine* RecordCacheEngine::init(int maxCache, ThreadContext* ctx)
{
	this->maxCache = maxCache;
	__GC_MV(this, &(this->cache), (new(ctx) DbRecordCache(ctx))->init(maxCache, ctx), DbRecordCache);
	return this;
}
void RecordCacheEngine::updateData(DatatableUpdateSupport* table, DatabaseRecord* dbrecord, long long commitId, IArrayObject<SequentialBackgroundJob>* jobs, ISystemLog* log, ThreadContext* ctx)
{
	FileStorageEntryWriter* writer = table->getDataStorage(ctx)->getWriter(ctx);
	{
		try
		{
			int cap = dbrecord->diskSize(ctx);
			FileStorageEntryBuilder* builder = (new(ctx) FileStorageEntryBuilder(cap, ctx));
			dbrecord->appendToEntry(builder, ctx);
			FileStorageEntry* entry = builder->toEntry(ctx);
			writer->write(entry, ctx);
			dbrecord->setPosition(entry->position, ctx);
			int slot = 0;
			jobs->get(slot++)->addJob((new(ctx) IndexInsertJob(table->getPrimaryIndex(ctx), dbrecord, ctx)), ctx);
			ArrayList<IScannableIndex>* indexes = table->getIndexes(ctx);
			int maxLoop = indexes->size(ctx);
			for(int i = 0; i != maxLoop; ++i)
			{
				IScannableIndex* tableIndex = indexes->get(i, ctx);
				jobs->get(slot++)->addJob((new(ctx) IndexInsertJob(tableIndex, dbrecord, ctx)), ctx);
			}
			this->cache->addCachedRecord(table, dbrecord, ctx);
		}
		catch(VariableException* e)
		{
			throw (new(ctx) AlinousDbException(ConstStr::getCNST_STR_1620(), ctx));
		}
		catch(Throwable* e)
		{
			writer->end(ctx);
			throw (new(ctx) AlinousDbException(ConstStr::getCNST_STR_1620(), e, ctx));
		}
	}
	writer->end(ctx);
}
void RecordCacheEngine::insertData(DatatableUpdateSupport* table, DatabaseRecord* dbrecord, long long commitId, IArrayObject<SequentialBackgroundJob>* jobs, ISystemLog* log, ThreadContext* ctx)
{
	FileStorageEntryWriter* writer = table->getDataStorage(ctx)->getWriter(ctx);
	{
		try
		{
			int cap = dbrecord->diskSize(ctx);
			FileStorageEntryBuilder* builder = (new(ctx) FileStorageEntryBuilder(cap, ctx));
			dbrecord->appendToEntry(builder, ctx);
			FileStorageEntry* entry = builder->toEntry(ctx);
			writer->write(entry, ctx);
			dbrecord->setPosition(entry->position, ctx);
			int slot = 0;
			jobs->get(slot++)->addJob((new(ctx) OidIndexJob(dbrecord->getOid(ctx), table->getOidIndex(ctx), entry->position, ctx)), ctx);
			jobs->get(slot++)->addJob((new(ctx) IndexInsertJob(table->getPrimaryIndex(ctx), dbrecord, ctx)), ctx);
			ArrayList<IScannableIndex>* indexes = table->getIndexes(ctx);
			int maxLoop = indexes->size(ctx);
			for(int i = 0; i != maxLoop; ++i)
			{
				IScannableIndex* tableIndex = indexes->get(i, ctx);
				jobs->get(slot++)->addJob((new(ctx) IndexInsertJob(tableIndex, dbrecord, ctx)), ctx);
			}
			this->cache->addCachedRecord(table, dbrecord, ctx);
		}
		catch(VariableException* e)
		{
			throw (new(ctx) AlinousDbException(ConstStr::getCNST_STR_1620(), ctx));
		}
		catch(Throwable* e)
		{
			writer->end(ctx);
			throw e;
		}
	}
	writer->end(ctx);
}
DatabaseRecord* RecordCacheEngine::loadRecord(DataTableStorageSupport* table, long long filePointer, ThreadContext* ctx)
{
	DatabaseRecord* record = this->cache->loadRecord(table, filePointer, ctx);
	if(record != nullptr)
	{
		return record;
	}
	FileStorage* storage = table->getDataStorage(ctx);
	FileStorageEntryReader* reader = (new(ctx) FileStorageEntryReader(storage, ctx));
	{
		try
		{
			FileStorageEntry* entry = reader->read(filePointer, ctx);
			FileStorageEntryFetcher* fetcher = (new(ctx) FileStorageEntryFetcher(entry, ctx));
			fetcher->fetchInt(ctx);
			record = DatabaseRecord::valueFromFetcher(fetcher, ctx);
		}
		catch(Throwable* e)
		{
			reader->end(ctx);
			throw e;
		}
	}
	reader->end(ctx);
	return record;
}
int RecordCacheEngine::getMaxCache(ThreadContext* ctx) throw() 
{
	return maxCache;
}
}}}}

