#include "includes.h"


namespace alinous {namespace db {





bool SchemaManager::__init_done = __init_static_variables();
bool SchemaManager::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"SchemaManager", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 SchemaManager::SchemaManager(String* dataDir, ISystemLog* logger, ThreadPool* threadPool, AlinousCore* core, BTreeGlobalCache* cache, ThreadContext* ctx) throw()  : IObject(ctx), IBTreeValue(ctx), dataDir(nullptr), schemas(GCUtils<HashMap<String,TableSchema> >::ins(this, (new(ctx) HashMap<String,TableSchema>(ctx)), ctx, __FILEW__, __LINE__, L"")), logger(nullptr), threadPool(nullptr), oidPublisher(nullptr)
{
	__GC_MV(this, &(this->dataDir), dataDir, String);
	__GC_MV(this, &(this->logger), logger, ISystemLog);
	__GC_MV(this, &(this->threadPool), threadPool, ThreadPool);
}
void SchemaManager::__construct_impl(String* dataDir, ISystemLog* logger, ThreadPool* threadPool, AlinousCore* core, BTreeGlobalCache* cache, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->dataDir), dataDir, String);
	__GC_MV(this, &(this->logger), logger, ISystemLog);
	__GC_MV(this, &(this->threadPool), threadPool, ThreadPool);
}
 SchemaManager::~SchemaManager() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void SchemaManager::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"SchemaManager", L"~SchemaManager");
	__e_obj1.add(this->dataDir, this);
	dataDir = nullptr;
	__e_obj1.add(this->schemas, this);
	schemas = nullptr;
	__e_obj1.add(this->logger, this);
	logger = nullptr;
	__e_obj1.add(this->threadPool, this);
	threadPool = nullptr;
	__e_obj1.add(this->oidPublisher, this);
	oidPublisher = nullptr;
	if(!prepare){
		return;
	}
}
void SchemaManager::createTable(String* schemaName, TableMetadata* tableMetadata, ThreadPool* threadPool, AlinousCore* core, BTreeGlobalCache* cache, ThreadContext* ctx)
{
	TableSchema* schema = this->schemas->get(schemaName, ctx);
	if(schema == nullptr)
	{
		schema = createSchema(schemaName, ctx);
	}
	IDatabaseTable* table = schema->getTableStore(tableMetadata->getTableName(ctx), ctx);
	if(table != nullptr)
	{
		logger->logWarning(ConstStr::getCNST_STR_1601()->clone(ctx)->append(tableMetadata->getTableName(ctx), ctx)->append(ConstStr::getCNST_STR_1602(), ctx), ctx);
		return;
	}
	IDatabaseTable* tableStore = (new(ctx) DatabaseTable(schemaName, tableMetadata->getTableName(ctx), schema->getSchemaDir(ctx), this->threadPool, this->oidPublisher, ctx));
	tableStore->createTable(tableMetadata, threadPool, core, cache, ctx);
	schema->addTableStore(tableStore, ctx);
}
TableSchema* SchemaManager::createSchema(String* name, ThreadContext* ctx) throw() 
{
	TableSchema* schema = this->schemas->get(name, ctx);
	if(schema != nullptr)
	{
		return schema;
	}
	schema = (new(ctx) TableSchema(name, this->dataDir, ctx));
	schema->create(ctx);
	this->schemas->put(name, schema, ctx);
	return schema;
}
TableSchema* SchemaManager::getSchema(String* name, ThreadContext* ctx) throw() 
{
	return this->schemas->get(name, ctx);
}
void SchemaManager::loadAfterFetch(String* dataDir, ISystemLog* logger, ThreadPool* threadPool, AlinousCore* core, BTreeGlobalCache* cache, ThreadContext* ctx)
{
	__GC_MV(this, &(this->dataDir), dataDir, String);
	__GC_MV(this, &(this->logger), logger, ISystemLog);
	__GC_MV(this, &(this->threadPool), threadPool, ThreadPool);
	Iterator<String>* it = this->schemas->keySet(ctx)->iterator(ctx);
	while(it->hasNext(ctx))
	{
		String* key = it->next(ctx);
		TableSchema* sc = this->schemas->get(key, ctx);
		sc->initAfterFetched(dataDir, sc->name, threadPool, this->oidPublisher, core, cache, ctx);
	}
}
void SchemaManager::appendToEntry(FileStorageEntryBuilder* builder, ThreadContext* ctx) throw() 
{
	builder->putInt(IBTreeValue::TYPE_SCHEME, ctx);
	builder->putInt(this->schemas->keySet(ctx)->size(ctx), ctx);
	Iterator<String>* it = this->schemas->keySet(ctx)->iterator(ctx);
	while(it->hasNext(ctx))
	{
		String* key = it->next(ctx);
		TableSchema* sc = this->schemas->get(key, ctx);
		sc->appendToEntry(builder, ctx);
	}
}
int SchemaManager::diskSize(ThreadContext* ctx) throw() 
{
	int total = 4;
	Iterator<String>* it = this->schemas->keySet(ctx)->iterator(ctx);
	while(it->hasNext(ctx))
	{
		String* key = it->next(ctx);
		TableSchema* sc = this->schemas->get(key, ctx);
		total += sc->diskSize(ctx);
	}
	return total;
}
bool SchemaManager::equals(IObject* obj, ThreadContext* ctx) throw() 
{
	return true;
}
IValueFetcher* SchemaManager::getFetcher(ThreadContext* ctx) throw() 
{
	return nullptr;
}
SchemaManager* SchemaManager::valueFromFetcher(FileStorageEntryFetcher* fetcher, ThreadContext* ctx)
{
	SchemaManager* mgr = (new(ctx) SchemaManager(nullptr, nullptr, nullptr, nullptr, nullptr, ctx));
	int maxLoop = fetcher->fetchInt(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		TableSchema* sc = TableSchema::valueFromFetcher(fetcher, ctx);
		mgr->schemas->put(sc->name, sc, ctx);
	}
	return mgr;
}
}}

