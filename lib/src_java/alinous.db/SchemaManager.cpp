#include "include/global.h"


#include "alinous.btree/BTreeException.h"
#include "alinous.lock/LockObject.h"
#include "alinous.lock/ConcurrentGate.h"
#include "alinous.buffer.storage/IFileStorage.h"
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
#include "alinous.db/AlinousDbException.h"
#include "alinous.btree/IBTree.h"
#include "alinous.btree/BTree.h"
#include "alinous.btree/IntKey.h"
#include "alinous.btree/LongValue.h"
#include "alinous.db.table/IOidPublisher.h"
#include "alinous.db.table/LocalOidPublisher.h"
#include "alinous.runtime.parallel/LaunchJoin.h"
#include "alinous.runtime.parallel/IThreadAction.h"
#include "alinous.runtime.parallel/AlinousThread.h"
#include "alinous.runtime.parallel/ThreadPool.h"
#include "alinous.remote.monitor.client.command.data/OidSchemaContainer.h"
#include "alinous.system/ISystemLog.h"
#include "alinous.remote.monitor/TransactionMonitorServer.h"
#include "alinous.system/AlinousCore.h"
#include "alinous.db.trx/DbVersionContext.h"
#include "alinous.db.trx/DbTransactionManager.h"
#include "alinous.db.trx/TrxLockContext.h"
#include "alinous.db.trx/TrxLockManager.h"
#include "alinous.db.table/IDatabaseRecord.h"
#include "alinous.lock.unique/UniqueExclusiveLockManager.h"
#include "alinous.lock.unique/UniqueExclusiveLockClient.h"
#include "alinous.db/ICommidIdPublisher.h"
#include "java.io/FilterOutputStream.h"
#include "java.io/BufferedOutputStream.h"
#include "alinous.remote.monitor.client.command/AbstractMonitorCommand.h"
#include "alinous.remote.monitor.client.command.commitId/ReportSchemaVersionCommand.h"
#include "alinous.remote.monitor.client.command/AllocOidCommand.h"
#include "alinous.remote.monitor.client.command/ReportMaxOidCommand.h"
#include "alinous.remote.monitor.client.command/MinitorCommandReader.h"
#include "alinous.remote.socket/ISocketConnection.h"
#include "alinous.remote.socket/ISocketConnectionFactory.h"
#include "alinous.remote.socket/SocketConnectionPool.h"
#include "alinous.system.config/IAlinousConfigElement.h"
#include "alinous.system.config.remote/MonitorRef.h"
#include "alinous.remote.monitor.client/MonitorConnectionInfo.h"
#include "alinous.remote.monitor.client/MonitorClientConnectionFactory.h"
#include "alinous.remote.monitor.client/RemoteCommitIdPublisher.h"
#include "alinous.remote.db.client.command.data/TableClusterData.h"
#include "alinous.db.table/TableMetadata.h"
#include "alinous.db/ITableRegion.h"
#include "alinous.system.config.remote/RegionRef.h"
#include "alinous.remote.region.client/RemoteRegionRef.h"
#include "alinous.system.config.remote/RegionsRef.h"
#include "alinous.system.config/AlinousDbInstanceInfo.h"
#include "alinous.db/LocalCommitIdPublisher.h"
#include "alinous.db.table/DatabaseRecord.h"
#include "alinous.numeric/InternalDate.h"
#include "java.sql/Timestamp.h"
#include "java.lang/Number.h"
#include "java.lang/Integer.h"
#include "alinous.db.table/DatabaseTableIdPublisher.h"
#include "alinous.db.table/IBtreeTableIndex.h"
#include "alinous.db.table/IScannableIndex.h"
#include "alinous.db.table/TableIndex.h"
#include "alinous.db.table/DatatableConstants.h"
#include "alinous.db.table/DatatableUpdateCache.h"
#include "alinous.db.table/IDatabaseTable.h"
#include "alinous.db.table/AbstractDatabaseTable.h"
#include "alinous.db.table/DataTableStorageSupport.h"
#include "alinous.runtime.parallel/SequentialBackgroundJob.h"
#include "alinous.db.table/DatatableLockSupport.h"
#include "alinous.db.table/DatatableDDLSupport.h"
#include "alinous.db.table/DatatableUpdateSupport.h"
#include "alinous.db.table.cache/RecordCacheEngine.h"
#include "alinous.db.table/DatabaseTable.h"
#include "alinous.remote.db/MonitorAccess.h"
#include "alinous.remote.db.client.command.data/SchemaData.h"
#include "alinous.remote.db.client.command.data/SchemasStructureInfoData.h"
#include "alinous.db/ITableSchema.h"
#include "alinous.db/TableSchema.h"
#include "alinous.db/SchemaManager.h"
#include "alinous.db/LocalTableRegion.h"
#include "alinous.db/TableSchemaCollection.h"
#include "alinous.db/TableRegionManager.h"
#include "alinous.runtime.dbif/IDatabaseConnection.h"
#include "alinous.db/ConnectInfo.h"
#include "alinous.db/AlinousDbConnection.h"
#include "alinous.db/AlinousDatabase.h"
#include "alinous.db.trx/DbTransaction.h"

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
 SchemaManager::SchemaManager(String* dataDir, ISystemLog* logger, ThreadPool* threadPool, AlinousCore* core, BTreeGlobalCache* cache, ThreadContext* ctx) throw()  : IObject(ctx), IBTreeValue(ctx), dataDir(nullptr), schemas(GCUtils<HashMap<String,TableSchema> >::ins(this, (new(ctx) HashMap<String,TableSchema>(ctx)), ctx, __FILEW__, __LINE__, L"")), schemeLock(__GC_INS(this, (new(ctx) LockObject(ctx)), LockObject)), logger(nullptr), threadPool(nullptr)
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
	__e_obj1.add(this->schemeLock, this);
	schemeLock = nullptr;
	__e_obj1.add(this->logger, this);
	logger = nullptr;
	__e_obj1.add(this->threadPool, this);
	threadPool = nullptr;
	if(!prepare){
		return;
	}
}
void SchemaManager::createTable(String* schemaName, TableMetadata* tableMetadata, ThreadPool* threadPool, AlinousCore* core, BTreeGlobalCache* cache, ThreadContext* ctx)
{
	{
		SynchronizedBlockObj __synchronized_2(schemeLock, ctx);
		doCreateTable(schemaName, tableMetadata, threadPool, core, cache, ctx);
	}
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
void SchemaManager::reportMaxOids(MonitorAccess* monitorAccess, ThreadContext* ctx)
{
	OidSchemaContainer* container = (new(ctx) OidSchemaContainer(ctx));
	Iterator<String>* it = this->schemas->keySet(ctx)->iterator(ctx);
	while(it->hasNext(ctx))
	{
		String* scName = it->next(ctx);
		TableSchema* sc = this->schemas->get(scName, ctx);
		reportMaxOidsSchema(monitorAccess, sc, container, ctx);
	}
	monitorAccess->reportMaxOid(container, ctx);
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
		sc->initAfterFetched(dataDir, sc->name, threadPool, core, cache, ctx);
	}
}
void SchemaManager::appendToEntry(FileStorageEntryBuilder* builder, ThreadContext* ctx)
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
	return this == obj;
}
IValueFetcher* SchemaManager::getFetcher(ThreadContext* ctx) throw() 
{
	return nullptr;
}
void SchemaManager::getSchemaData(SchemasStructureInfoData* data, String* region, String* host, int port, bool ipv6, ThreadContext* ctx) throw() 
{
	{
		SynchronizedBlockObj __synchronized_2(this->schemeLock, ctx);
		Iterator<String>* it = this->schemas->keySet(ctx)->iterator(ctx);
		while(it->hasNext(ctx))
		{
			String* key = it->next(ctx);
			TableSchema* sc = this->schemas->get(key, ctx);
			SchemaData* scdata = sc->toCommandData(region, host, port, ipv6, ctx);
			data->addScheme(scdata, ctx);
		}
	}
}
void SchemaManager::doCreateTable(String* schemaName, TableMetadata* tableMetadata, ThreadPool* threadPool, AlinousCore* core, BTreeGlobalCache* cache, ThreadContext* ctx)
{
	TableSchema* schema = this->schemas->get(schemaName, ctx);
	if(schema == nullptr)
	{
		schema = createSchema(schemaName, ctx);
	}
	IDatabaseTable* table = schema->getTableStore(tableMetadata->getTableName(ctx), ctx);
	if(table != nullptr)
	{
		logger->logWarning(ConstStr::getCNST_STR_1686()->clone(ctx)->append(tableMetadata->getTableName(ctx), ctx)->append(ConstStr::getCNST_STR_1687(), ctx), ctx);
		return;
	}
	IDatabaseTable* tableStore = (new(ctx) DatabaseTable(schemaName, tableMetadata->getTableName(ctx), schema->getSchemaDir(ctx), this->threadPool, ctx));
	tableStore->createTable(tableMetadata, threadPool, core, cache, ctx);
	schema->addTableStore(tableStore, ctx);
}
void SchemaManager::reportMaxOidsSchema(MonitorAccess* monitorAccess, TableSchema* sc, OidSchemaContainer* container, ThreadContext* ctx) throw() 
{
	HashMap<String,IDatabaseTable>* tableStores = sc->getTableStores(ctx);
	String* schemaName = sc->name;
	Iterator<String>* it = tableStores->keySet(ctx)->iterator(ctx);
	while(it->hasNext(ctx))
	{
		String* tableName = it->next(ctx);
		IDatabaseTable* table = tableStores->get(tableName, ctx);
		long long nextOid = table->getNextOid(ctx);
		container->addOid(schemaName, tableName, nextOid, ctx);
	}
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
void SchemaManager::__cleanUp(ThreadContext* ctx){
}
}}

