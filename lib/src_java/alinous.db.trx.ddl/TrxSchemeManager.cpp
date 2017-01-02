#include "includes.h"


namespace alinous {namespace db {namespace trx {namespace ddl {





bool TrxSchemeManager::__init_done = __init_static_variables();
bool TrxSchemeManager::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"TrxSchemeManager", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 TrxSchemeManager::TrxSchemeManager(AlinousDatabase* database, ISystemLog* logger, ThreadContext* ctx) throw()  : IObject(ctx), newMetadata(GCUtils<ArrayList<TableSchema> >::ins(this, (new(ctx) ArrayList<TableSchema>(ctx)), ctx, __FILEW__, __LINE__, L"")), droppedMetadata(GCUtils<ArrayList<TableSchema> >::ins(this, (new(ctx) ArrayList<TableSchema>(ctx)), ctx, __FILEW__, __LINE__, L"")), createIndexMetadata(GCUtils<ArrayList<CreateIndexMetadata> >::ins(this, (new(ctx) ArrayList<CreateIndexMetadata>(ctx)), ctx, __FILEW__, __LINE__, L"")), logger(nullptr), hasOperation(0), database(nullptr)
{
	__GC_MV(this, &(this->database), database, AlinousDatabase);
	__GC_MV(this, &(this->logger), logger, ISystemLog);
}
void TrxSchemeManager::__construct_impl(AlinousDatabase* database, ISystemLog* logger, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->database), database, AlinousDatabase);
	__GC_MV(this, &(this->logger), logger, ISystemLog);
}
 TrxSchemeManager::~TrxSchemeManager() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void TrxSchemeManager::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"TrxSchemeManager", L"~TrxSchemeManager");
	__e_obj1.add(this->newMetadata, this);
	newMetadata = nullptr;
	__e_obj1.add(this->droppedMetadata, this);
	droppedMetadata = nullptr;
	__e_obj1.add(this->createIndexMetadata, this);
	createIndexMetadata = nullptr;
	__e_obj1.add(this->logger, this);
	logger = nullptr;
	__e_obj1.add(this->database, this);
	database = nullptr;
	if(!prepare){
		return;
	}
}
void TrxSchemeManager::executeCommit(AlinousCore* core, BTreeGlobalCache* cache, ThreadContext* ctx)
{
	int maxLoop = this->newMetadata->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		TableSchema* sc = this->newMetadata->get(i, ctx);
		{
			try
			{
				executeCreateSchemaAndTable(sc, core, ctx);
			}
			catch(IOException* e)
			{
				throw (new(ctx) AlinousDbException(ConstStr::getCNST_STR_1657(), e, ctx));
			}
			catch(InterruptedException* e)
			{
				throw (new(ctx) AlinousDbException(ConstStr::getCNST_STR_1617(), e, ctx));
			}
			catch(BTreeException* e)
			{
				throw (new(ctx) AlinousDbException(ConstStr::getCNST_STR_1658(), e, ctx));
			}
			catch(DatabaseException* e)
			{
				throw (new(ctx) AlinousDbException(ConstStr::getCNST_STR_1659(), e, ctx));
			}
		}
	}
	maxLoop = this->createIndexMetadata->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		CreateIndexMetadata* meta = this->createIndexMetadata->get(i, ctx);
		executeCreateIndex(meta, core, cache, ctx);
	}
}
void TrxSchemeManager::addIndex(CreateIndexMetadata* meta, ThreadContext* ctx) throw() 
{
	this->createIndexMetadata->add(meta, ctx);
	this->hasOperation = true;
}
void TrxSchemeManager::addNewMetadata(TableSchema* metadata, ThreadContext* ctx) throw() 
{
	TableSchema* target = metadata;
	bool alreadyHas = false;
	int maxLoop = this->newMetadata->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		TableSchema* schema = newMetadata->get(i, ctx);
		if(schema->equals(metadata, ctx))
		{
			target = schema;
			alreadyHas = true;
		}
	}
	if(!alreadyHas)
	{
		this->newMetadata->add(metadata, ctx);
		this->hasOperation = true;
		return;
	}
	Iterator<String>* it = metadata->getTableNames(ctx)->iterator(ctx);
	while(it->hasNext(ctx))
	{
		String* tableName = it->next(ctx);
		target->addTableMetadata(metadata->getDableMetadata(tableName, ctx), ctx);
	}
	this->hasOperation = true;
}
TableMetadata* TrxSchemeManager::getTableMetadata(String* schemaName, String* tableName, ThreadContext* ctx) throw() 
{
	TableSchema* schema = getNewSchema(schemaName, ctx);
	if(schema == nullptr)
	{
		return nullptr;
	}
	TableMetadata* meta = schema->getDableMetadata(tableName, ctx);
	return meta;
}
bool TrxSchemeManager::tableExists(String* schemaName, String* tableName, ThreadContext* ctx) throw() 
{
	IDatabaseTable* tbl = this->database->getTable(schemaName, tableName, ctx);
	if(tbl != nullptr)
	{
		return true;
	}
	return false;
}
bool TrxSchemeManager::isDropped(TableSchema* metadata, ThreadContext* ctx) throw() 
{
	int maxLoop = this->droppedMetadata->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		TableSchema* meta = this->droppedMetadata->get(i, ctx);
		if(meta == metadata)
		{
			return true;
		}
	}
	return false;
}
void TrxSchemeManager::reset(ThreadContext* ctx) throw() 
{
	this->droppedMetadata->clear(ctx);
	this->newMetadata->clear(ctx);
	this->hasOperation = false;
}
void TrxSchemeManager::dispose(ThreadContext* ctx) throw() 
{
	reset(ctx);
}
bool TrxSchemeManager::isHasOperation(ThreadContext* ctx) throw() 
{
	return hasOperation;
}
void TrxSchemeManager::executeCreateIndex(CreateIndexMetadata* meta, AlinousCore* core, BTreeGlobalCache* cache, ThreadContext* ctx) throw() 
{
	String* schemaName = meta->getTas(ctx)->getSchema(ctx);
	String* tableName = meta->getTas(ctx)->getTable(ctx);
	TableSchemaCollection* schema = this->database->getSchema(schemaName, ctx);
	IDatabaseTable* tableStore = schema->getTableStore(tableName, ctx);
	if(tableStore == nullptr)
	{
		this->logger->logWarning(ConstStr::getCNST_STR_1660()->clone(ctx)->append(meta->getindexName(ctx), ctx)->append(ConstStr::getCNST_STR_1661(), ctx), ctx);
		return;
	}
	{
		try
		{
			tableStore->createIndex(meta->getindexName(ctx), meta->getColumns(ctx), core, cache, ctx);
		}
		catch(Throwable* e)
		{
			this->logger->logWarning(ConstStr::getCNST_STR_1660()->clone(ctx)->append(meta->getindexName(ctx), ctx)->append(ConstStr::getCNST_STR_1661(), ctx), ctx);
			this->logger->logError(e, ctx);
		}
	}
}
void TrxSchemeManager::executeCreateSchemaAndTable(TableSchema* sc, AlinousCore* core, ThreadContext* ctx)
{
	String* schemaName = sc->name;
	String* regionName = sc->getregionName(ctx);
	TableRegionManager* regions = this->database->getRegionManager(ctx);
	Set<String>* keys = sc->getTableNames(ctx);
	Iterator<String>* it = keys->iterator(ctx);
	while(it->hasNext(ctx))
	{
		String* tableName = it->next(ctx);
		TableMetadata* tblMeta = sc->getDableMetadata(tableName, ctx);
		regions->commitCreateTable(regionName, schemaName, tblMeta, this->database, core, ctx);
	}
	{
		SynchronizedBlockObj __synchronized_2(this->database->instanceConfigLock, ctx);
		this->database->syncScheme(ctx);
	}
}
TableSchema* TrxSchemeManager::getNewSchema(String* schemaName, ThreadContext* ctx) throw() 
{
	int maxLoop = this->newMetadata->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		TableSchema* sc = this->newMetadata->get(i, ctx);
		if(sc->name->equals(schemaName, ctx))
		{
			return sc;
		}
	}
	return nullptr;
}
}}}}

