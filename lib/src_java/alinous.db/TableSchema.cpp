#include "includes.h"


namespace alinous {namespace db {





bool TableSchema::__init_done = __init_static_variables();
bool TableSchema::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"TableSchema", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 TableSchema::TableSchema(String* name, String* dataDir, ThreadContext* ctx) throw()  : IObject(ctx), IBTreeValue(ctx), ITableSchema(ctx), name(nullptr), dataDir(nullptr), schemaDir(nullptr), tables(GCUtils<HashMap<String,TableMetadata> >::ins(this, (new(ctx) HashMap<String,TableMetadata>(ctx)), ctx, __FILEW__, __LINE__, L"")), tableStores(GCUtils<HashMap<String,IDatabaseTable> >::ins(this, (new(ctx) HashMap<String,IDatabaseTable>(ctx)), ctx, __FILEW__, __LINE__, L"")), regionName(nullptr)
{
	__GC_MV(this, &(this->dataDir), dataDir, String);
	__GC_MV(this, &(this->name), name, String);
	__GC_MV(this, &(this->regionName), ConstStr::getCNST_STR_1656(), String);
}
void TableSchema::__construct_impl(String* name, String* dataDir, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->dataDir), dataDir, String);
	__GC_MV(this, &(this->name), name, String);
	__GC_MV(this, &(this->regionName), ConstStr::getCNST_STR_1656(), String);
}
 TableSchema::~TableSchema() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void TableSchema::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"TableSchema", L"~TableSchema");
	__e_obj1.add(this->name, this);
	name = nullptr;
	__e_obj1.add(this->dataDir, this);
	dataDir = nullptr;
	__e_obj1.add(this->schemaDir, this);
	schemaDir = nullptr;
	__e_obj1.add(this->tables, this);
	tables = nullptr;
	__e_obj1.add(this->tableStores, this);
	tableStores = nullptr;
	__e_obj1.add(this->regionName, this);
	regionName = nullptr;
	if(!prepare){
		return;
	}
}
void TableSchema::create(ThreadContext* ctx) throw() 
{
	String* path = getSchemaDir(ctx);
	File* file = (new(ctx) File(path, ctx));
	if(!file->exists(ctx))
	{
		file->mkdirs(ctx);
	}
}
void TableSchema::initAfterFetched(String* dataDir, String* schemaName, ThreadPool* threadPool, IOidPublisher* oidPublisher, AlinousCore* core, BTreeGlobalCache* cache, ThreadContext* ctx)
{
	__GC_MV(this, &(this->dataDir), dataDir, String);
	StringBuilder* buff = (new(ctx) StringBuilder(ctx));
	buff->append(this->dataDir, ctx)->append(schemaName, ctx)->append(ConstStr::getCNST_STR_1007(), ctx);
	String* baseDir = buff->toString(ctx);
	Iterator<String>* it = this->tables->keySet(ctx)->iterator(ctx);
	while(it->hasNext(ctx))
	{
		String* tableNname = it->next(ctx);
		IDatabaseTable* dataStore = (new(ctx) DatabaseTable(schemaName, tableNname, baseDir, threadPool, oidPublisher, ctx));
		this->tableStores->put(tableNname, dataStore, ctx);
		dataStore->open(core, cache, ctx);
	}
}
String* TableSchema::getSchemaDir(ThreadContext* ctx) throw() 
{
	if(this->schemaDir == nullptr)
	{
		__GC_MV(this, &(this->schemaDir), this->dataDir->clone(ctx)->append(this->name, ctx)->append(ConstStr::getCNST_STR_1007(), ctx), String);
	}
	return this->schemaDir;
}
void TableSchema::addTableStore(IDatabaseTable* tableStore, ThreadContext* ctx) throw() 
{
	this->tableStores->put(tableStore->getName(ctx), tableStore, ctx);
	this->tables->put(tableStore->getName(ctx), tableStore->getMetadata(ctx), ctx);
}
IDatabaseTable* TableSchema::getTableStore(String* tableName, ThreadContext* ctx) throw() 
{
	return this->tableStores->get(tableName, ctx);
}
TableMetadata* TableSchema::getDableMetadata(String* tableName, ThreadContext* ctx) throw() 
{
	return this->tables->get(tableName, ctx);
}
Set<String>* TableSchema::getTableNames(ThreadContext* ctx) throw() 
{
	Set<String>* tableNames = this->tables->keySet(ctx);
	return tableNames;
}
void TableSchema::addTableMetadata(TableMetadata* tblMetadata, ThreadContext* ctx) throw() 
{
	this->tables->put(tblMetadata->getTableName(ctx), tblMetadata, ctx);
}
void TableSchema::appendToEntry(FileStorageEntryBuilder* builder, ThreadContext* ctx) throw() 
{
	builder->putString(this->name, ctx);
	builder->putInt(this->tables->keySet(ctx)->size(ctx), ctx);
	Iterator<String>* it = this->tables->keySet(ctx)->iterator(ctx);
	while(it->hasNext(ctx))
	{
		String* key = it->next(ctx);
		TableMetadata* tblMetadata = this->tables->get(key, ctx);
		tblMetadata->toFileEntry(builder, ctx);
	}
}
int TableSchema::diskSize(ThreadContext* ctx) throw() 
{
	int total = this->name->length(ctx) * 2 + 4;
	total += 4;
	Iterator<String>* it = this->tables->keySet(ctx)->iterator(ctx);
	while(it->hasNext(ctx))
	{
		String* key = it->next(ctx);
		total += key->length(ctx) * 2 + 4;
	}
	return total;
}
bool TableSchema::equals(IObject* obj, ThreadContext* ctx) throw() 
{
	if((dynamic_cast<TableSchema*>(obj) != 0))
	{
		TableSchema* other = dynamic_cast<TableSchema*>(obj);
		return this->name->equals(other->name, ctx);
	}
	return false;
}
bool TableSchema::equals(TableSchema* other, ThreadContext* ctx) throw() 
{
	return this->name->equals(other->name, ctx);
}
IValueFetcher* TableSchema::getFetcher(ThreadContext* ctx) throw() 
{
	return nullptr;
}
String* TableSchema::getregionName(ThreadContext* ctx) throw() 
{
	return regionName;
}
void TableSchema::setRegionName(String* name, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->name), name, String);
}
TableSchema* TableSchema::valueFromFetcher(FileStorageEntryFetcher* fetcher, ThreadContext* ctx)
{
	String* name = fetcher->fetchString(ctx);
	TableSchema* schema = (new(ctx) TableSchema(name, nullptr, ctx));
	int maxLoop = fetcher->fetchInt(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		TableMetadata* tblMeta = TableMetadata::loadFromFetcher(fetcher, ctx);
		schema->tables->put(tblMeta->getTableName(ctx), tblMeta, ctx);
	}
	return schema;
}
}}

