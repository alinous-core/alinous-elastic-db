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
#include "alinous.compile/IAlinousVisitorContainer.h"
#include "alinous.remote.socket/NetworkBinaryBuffer.h"
#include "alinous.remote.socket/ICommandData.h"
#include "alinous.compile/AbstractSrcElement.h"
#include "alinous.compile/IAlinousElement.h"
#include "alinous.compile.declare/AlinousName.h"
#include "alinous.compile.declare/IDeclare.h"
#include "alinous.compile.declare.function/AlinousFunction.h"
#include "alinous.compile.analyse/SrcAnalyseContext.h"
#include "alinous.db.table/DatabaseException.h"
#include "java.util/Locale.h"
#include "java.util/Calendar.h"
#include "java.util/GregorianCalendar.h"
#include "java.util/Date.h"
#include "alinous.numeric/InternalDate.h"
#include "java.util/TimeZone.h"
#include "java.sql/Timestamp.h"
#include "alinous.runtime.dom/IAlinousVariable.h"
#include "alinous.runtime.variant/VariantValue.h"
#include "alinous.compile.declare/ClassMemberModifiers.h"
#include "alinous.compile.declare/IClassMember.h"
#include "alinous.compile.declare/AbstractClassMember.h"
#include "alinous.compile.declare/ClassMethodFunction.h"
#include "alinous.compile.declare/AlinousClass.h"
#include "alinous.compile/Token.h"
#include "alinous.system/AlinousException.h"
#include "java.lang/Comparable.h"
#include "alinous.btree/IBTreeKey.h"
#include "alinous.btree/IValueFetcher.h"
#include "alinous.btree/IBTreeValue.h"
#include "alinous.btree/IBTreeNode.h"
#include "alinous.btree/BTreeGlobalCache.h"
#include "alinous.compile.sql.analyze/ScanTableColumnIdentifier.h"
#include "alinous.db/AlinousDbException.h"
#include "alinous.db.table.lockmonitor/IThreadLocker.h"
#include "alinous.btree/IBTree.h"
#include "alinous.btree.scan/BTreeScanner.h"
#include "alinous.btree/BTree.h"
#include "alinous.btree/IntKey.h"
#include "alinous.btree/LongValue.h"
#include "alinous.db.table/IOidPublisher.h"
#include "alinous.runtime.parallel/IThreadAction.h"
#include "alinous.runtime.parallel/AlinousThread.h"
#include "alinous.runtime.parallel/ThreadPool.h"
#include "alinous.system/ISystemLog.h"
#include "alinous.system/AlinousCore.h"
#include "alinous.db.trx/DbVersionContext.h"
#include "alinous.db.trx/DbTransactionManager.h"
#include "alinous.db.trx/TrxLockContext.h"
#include "alinous.db.trx/TrxLockManager.h"
#include "alinous.db.table/IDatabaseRecord.h"
#include "alinous.lock.unique/UniqueExclusiveLockManager.h"
#include "alinous.lock.unique/UniqueExclusiveLockClient.h"
#include "alinous.system.config/IAlinousConfigElement.h"
#include "alinous.system.config/AlinousDbInstanceInfo.h"
#include "alinous.db/ICommidIdPublisher.h"
#include "alinous.db/LocalCommitIdPublisher.h"
#include "alinous.remote.db.client.command.data/StorageNodeData.h"
#include "alinous.remote.db.client.command.data/TableClusterData.h"
#include "alinous.db.table/TableColumnMetadata.h"
#include "alinous.db.table/TableIndexMetadata.h"
#include "alinous.db.table/TableMetadata.h"
#include "alinous.db.table/DatabaseRecord.h"
#include "alinous.db.table/IBtreeTableIndex.h"
#include "alinous.db.table/BTreeIndexKey.h"
#include "java.lang/Number.h"
#include "java.lang/Integer.h"
#include "alinous.db.table/DatatableUpdateCache.h"
#include "alinous.db.table/IScannableIndex.h"
#include "alinous.db.table/TableIndex.h"
#include "alinous.db.table/IDatabaseTable.h"
#include "alinous.db.table/AbstractDatabaseTable.h"
#include "alinous.db.table/DataTableStorageSupport.h"
#include "alinous.runtime.parallel/SequentialBackgroundJob.h"
#include "alinous.db.table/DatatableLockSupport.h"
#include "alinous.db.table/DatatableDDLSupport.h"
#include "alinous.db.table/DatatableUpdateSupport.h"
#include "alinous.db.table.cache/RecordCacheEngine.h"
#include "alinous.db.table.lockmonitor/DBThreadMonitor.h"
#include "alinous.db.table/DatabaseTable.h"
#include "alinous.remote.db.client.command.data/SchemaData.h"
#include "alinous.db/ITableSchema.h"
#include "alinous.db/TableSchema.h"
#include "alinous.db/SchemaManager.h"
#include "alinous.db/ITableRegion.h"
#include "alinous.db/LocalTableRegion.h"
#include "alinous.db/TableSchemaCollection.h"
#include "alinous.db/TableRegionManager.h"
#include "alinous.runtime.dbif/IDatabaseConnection.h"
#include "alinous.db/ConnectInfo.h"
#include "alinous.db/AlinousDbConnection.h"
#include "alinous.db/AlinousDatabase.h"
#include "alinous.db.trx/DbTransaction.h"

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
	__GC_MV(this, &(this->regionName), ConstStr::getCNST_STR_1683(), String);
}
void TableSchema::__construct_impl(String* name, String* dataDir, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->dataDir), dataDir, String);
	__GC_MV(this, &(this->name), name, String);
	__GC_MV(this, &(this->regionName), ConstStr::getCNST_STR_1683(), String);
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
SchemaData* TableSchema::toCommandData(String* region, String* host, int port, bool ipv6, ThreadContext* ctx) throw() 
{
	SchemaData* data = (new(ctx) SchemaData(ctx));
	data->setName(name, ctx);
	Iterator<String>* it = this->tables->keySet(ctx)->iterator(ctx);
	while(it->hasNext(ctx))
	{
		String* tableName = it->next(ctx);
		TableMetadata* table = this->tables->get(tableName, ctx);
		TableClusterData* tabledata = table->toCommandData(region, host, port, ipv6, ctx);
		data->addTable(tabledata, ctx);
	}
	return data;
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
void TableSchema::initAfterFetched(String* dataDir, String* schemaName, ThreadPool* threadPool, AlinousCore* core, BTreeGlobalCache* cache, ThreadContext* ctx)
{
	__GC_MV(this, &(this->dataDir), dataDir, String);
	StringBuilder* buff = (new(ctx) StringBuilder(ctx));
	buff->append(this->dataDir, ctx)->append(schemaName, ctx)->append(ConstStr::getCNST_STR_1007(), ctx);
	String* baseDir = buff->toString(ctx);
	Iterator<String>* it = this->tables->keySet(ctx)->iterator(ctx);
	while(it->hasNext(ctx))
	{
		String* tableNname = it->next(ctx);
		IDatabaseTable* dataStore = (new(ctx) DatabaseTable(schemaName, tableNname, baseDir, threadPool, ctx));
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
void TableSchema::appendToEntry(FileStorageEntryBuilder* builder, ThreadContext* ctx)
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
void TableSchema::setRegionName(String* regionName, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->regionName), regionName, String);
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
void TableSchema::__cleanUp(ThreadContext* ctx){
}
}}

