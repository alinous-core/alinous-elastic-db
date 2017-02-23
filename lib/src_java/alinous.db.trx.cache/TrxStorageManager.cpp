#include "includes.h"


namespace alinous {namespace db {namespace trx {namespace cache {





bool TrxStorageManager::__init_done = __init_static_variables();
bool TrxStorageManager::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"TrxStorageManager", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 TrxStorageManager::TrxStorageManager(String* tmpDir, DbTransaction* trx, ThreadContext* ctx) throw()  : IObject(ctx), tmpDir(nullptr), hasOperation(0), insertStorages(GCUtils<HashMap<String,HashMap<String,TrxRecordsCache>> >::ins(this, (new(ctx) HashMap<String,HashMap<String,TrxRecordsCache>>(ctx)), ctx, __FILEW__, __LINE__, L"")), updateStorages(GCUtils<HashMap<String,HashMap<String,TrxRecordsCache>> >::ins(this, (new(ctx) HashMap<String,HashMap<String,TrxRecordsCache>>(ctx)), ctx, __FILEW__, __LINE__, L"")), trx(nullptr)
{
	__GC_MV(this, &(this->tmpDir), tmpDir, String);
	__GC_MV(this, &(this->trx), trx, DbTransaction);
	initStorage(ctx);
}
void TrxStorageManager::__construct_impl(String* tmpDir, DbTransaction* trx, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->tmpDir), tmpDir, String);
	__GC_MV(this, &(this->trx), trx, DbTransaction);
	initStorage(ctx);
}
 TrxStorageManager::~TrxStorageManager() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void TrxStorageManager::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"TrxStorageManager", L"~TrxStorageManager");
	__e_obj1.add(this->tmpDir, this);
	tmpDir = nullptr;
	__e_obj1.add(this->insertStorages, this);
	insertStorages = nullptr;
	__e_obj1.add(this->updateStorages, this);
	updateStorages = nullptr;
	__e_obj1.add(this->trx, this);
	trx = nullptr;
	if(!prepare){
		return;
	}
}
TrxRecordsCache* TrxStorageManager::getInsertCache(String* schema, String* table, ThreadContext* ctx)
{
	TableMetadata* metadata = this->trx->getMetadata(schema, table, ctx);
	if(metadata == nullptr)
	{
		throw (new(ctx) AlinousDbException(schema->clone(ctx)->append(ConstStr::getCNST_STR_948(), ctx)->append(table, ctx)->append(ConstStr::getCNST_STR_1045(), ctx), ctx));
	}
	HashMap<String,TrxRecordsCache>* tblcache = this->insertStorages->get(schema, ctx);
	if(tblcache == nullptr)
	{
		return nullptr;
	}
	TrxRecordsCache* cache = tblcache->get(table, ctx);
	return cache;
}
TrxRecordsCache* TrxStorageManager::getUpdateCache(String* schema, String* table, ThreadContext* ctx)
{
	TableMetadata* metadata = this->trx->getMetadata(schema, table, ctx);
	if(metadata == nullptr)
	{
		throw (new(ctx) AlinousDbException(schema->clone(ctx)->append(ConstStr::getCNST_STR_948(), ctx)->append(table, ctx)->append(ConstStr::getCNST_STR_1045(), ctx), ctx));
	}
	HashMap<String,TrxRecordsCache>* tblcache = this->updateStorages->get(schema, ctx);
	if(tblcache == nullptr)
	{
		return nullptr;
	}
	TrxRecordsCache* cache = tblcache->get(table, ctx);
	return cache;
}
TrxRecordsCache* TrxStorageManager::getUpdateCacheWithCreate(String* schema, String* table, ThreadContext* ctx)
{
	TableMetadata* metadata = this->trx->getMetadata(schema, table, ctx);
	if(metadata == nullptr)
	{
		throw (new(ctx) AlinousDbException(schema->clone(ctx)->append(ConstStr::getCNST_STR_948(), ctx)->append(table, ctx)->append(ConstStr::getCNST_STR_1045(), ctx), ctx));
	}
	HashMap<String,TrxRecordsCache>* tblcache = this->updateStorages->get(schema, ctx);
	if(tblcache == nullptr)
	{
		tblcache = (new(ctx) HashMap<String,TrxRecordsCache>(ctx));
		this->updateStorages->put(schema, tblcache, ctx);
		TrxRecordsCache* cache = TrxRecordsCacheFactory::createCache(this->tmpDir, schema, table, metadata, this->trx, false, ctx);
		tblcache->put(table, cache, ctx);
		return cache;
	}
	TrxRecordsCache* cache = tblcache->get(table, ctx);
	if(cache == nullptr)
	{
		cache = (new(ctx) TrxRecordsCache(ctx))->init(this->tmpDir, schema, table, metadata, this->trx, false, ctx);
		tblcache->put(table, cache, ctx);
	}
	return cache;
}
TrxRecordsCache* TrxStorageManager::getInsertCacheWithCreate(String* schema, String* table, ThreadContext* ctx)
{
	TableMetadata* metadata = this->trx->getMetadata(schema, table, ctx);
	if(metadata == nullptr)
	{
		throw (new(ctx) AlinousDbException(schema->clone(ctx)->append(ConstStr::getCNST_STR_948(), ctx)->append(table, ctx)->append(ConstStr::getCNST_STR_1045(), ctx), ctx));
	}
	this->hasOperation = true;
	HashMap<String,TrxRecordsCache>* tblcache = this->insertStorages->get(schema, ctx);
	if(tblcache == nullptr)
	{
		tblcache = (new(ctx) HashMap<String,TrxRecordsCache>(ctx));
		this->insertStorages->put(schema, tblcache, ctx);
		TrxRecordsCache* cache = TrxRecordsCacheFactory::createCache(this->tmpDir, schema, table, metadata, this->trx, true, ctx);
		tblcache->put(table, cache, ctx);
		return cache;
	}
	TrxRecordsCache* cache = tblcache->get(table, ctx);
	if(cache == nullptr)
	{
		cache = (new(ctx) TrxRecordsCache(ctx))->init(this->tmpDir, schema, table, metadata, this->trx, true, ctx);
		tblcache->put(table, cache, ctx);
	}
	return cache;
}
void TrxStorageManager::commit(long long newCommitId, ThreadContext* ctx)
{
	AlinousDatabase* db = this->trx->getDatabase(ctx);
	Iterator<String>* scit = this->insertStorages->keySet(ctx)->iterator(ctx);
	while(scit->hasNext(ctx))
	{
		String* sckey = scit->next(ctx);
		TableSchemaCollection* schema = db->getSchema(sckey, ctx);
		HashMap<String,TrxRecordsCache>* cacheMap = this->insertStorages->get(sckey, ctx);
		Iterator<String>* it = cacheMap->keySet(ctx)->iterator(ctx);
		while(it->hasNext(ctx))
		{
			String* key = it->next(ctx);
			TrxRecordsCache* cache = cacheMap->get(key, ctx);
			IDatabaseTable* table = schema->getTableStore(key, ctx);
			cache->commitInsertRecord(db, table, newCommitId, ctx);
		}
	}
	scit = this->updateStorages->keySet(ctx)->iterator(ctx);
	while(scit->hasNext(ctx))
	{
		String* sckey = scit->next(ctx);
		TableSchemaCollection* schema = db->getSchema(sckey, ctx);
		HashMap<String,TrxRecordsCache>* cacheMap = this->updateStorages->get(sckey, ctx);
		Iterator<String>* it = cacheMap->keySet(ctx)->iterator(ctx);
		while(it->hasNext(ctx))
		{
			String* key = it->next(ctx);
			TrxRecordsCache* cache = cacheMap->get(key, ctx);
			IDatabaseTable* table = schema->getTableStore(key, ctx);
			cache->commitUpdateRecord(db, table, newCommitId, ctx);
		}
	}
}
bool TrxStorageManager::isHasOperation(ThreadContext* ctx) throw() 
{
	return hasOperation;
}
void TrxStorageManager::setHasOperation(bool hasOperation, ThreadContext* ctx) throw() 
{
	this->hasOperation = hasOperation;
}
void TrxStorageManager::reset(ThreadContext* ctx) throw() 
{
	Iterator<String>* scit = this->insertStorages->keySet(ctx)->iterator(ctx);
	while(scit->hasNext(ctx))
	{
		String* sckey = scit->next(ctx);
		HashMap<String,TrxRecordsCache>* cacheMap = this->insertStorages->get(sckey, ctx);
		Iterator<String>* it = cacheMap->keySet(ctx)->iterator(ctx);
		while(it->hasNext(ctx))
		{
			String* key = it->next(ctx);
			TrxRecordsCache* cache = cacheMap->get(key, ctx);
			{
				try
				{
					cache->dispose(ctx);
				}
				catch(AlinousException* e)
				{
					this->trx->getLogger(ctx)->logError(e, ctx);
				}
			}
		}
		cacheMap->clear(ctx);
	}
	this->insertStorages->clear(ctx);
	this->hasOperation = false;
}
void TrxStorageManager::dispose(ThreadContext* ctx) throw() 
{
	reset(ctx);
}
void TrxStorageManager::addIndex(CreateIndexMetadata* createMeta, TableMetadata* tblmetadata, AlinousDatabase* database, ThreadContext* ctx)
{
	TableAndSchema* tableAndSchema = createMeta->getTas(ctx);
	TrxRecordsCache* cache = getInsertCacheWithCreate(tableAndSchema->getSchema(ctx), tableAndSchema->getTable(ctx), ctx);
	if(cache != nullptr)
	{
		{
			try
			{
				cache->createIndex(createMeta->getindexName(ctx), createMeta->getColumns(ctx), tblmetadata, database, ctx);
			}
			catch(InterruptedException* e)
			{
				throw (new(ctx) AlinousDbException(ConstStr::getCNST_STR_1719(), e, ctx));
			}
			catch(VariableException* e)
			{
				throw (new(ctx) AlinousDbException(ConstStr::getCNST_STR_1720(), e, ctx));
			}
			catch(AlinousException* e)
			{
				throw (new(ctx) AlinousDbException(ConstStr::getCNST_STR_1721(), e, ctx));
			}
		}
	}
}
void TrxStorageManager::initStorage(ThreadContext* ctx) throw() 
{
	File* file = (new(ctx) File(this->tmpDir, ctx));
	if(file->exists(ctx))
	{
		FileUtils::removeAll(file, ctx);
	}
	file->mkdirs(ctx);
}
}}}}

