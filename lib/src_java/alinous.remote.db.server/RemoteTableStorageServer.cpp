#include "include/global.h"


#include "alinous.buffer.storage/FileStorageEntryBuilder.h"
#include "alinous.compile/AbstractSrcElement.h"
#include "alinous.system/AlinousException.h"
#include "alinous.runtime/ExecutionException.h"
#include "alinous.runtime.dom/VariableException.h"
#include "alinous.lock/LockObject.h"
#include "alinous.btree/BTreeGlobalCache.h"
#include "alinous.btree/IValueFetcher.h"
#include "alinous.btree/IBTreeValue.h"
#include "java.lang/Comparable.h"
#include "alinous.btree/IBTreeKey.h"
#include "alinous.btree/BTreeException.h"
#include "alinous.btree/IBTree.h"
#include "alinous.btree/BTree.h"
#include "alinous.btree/IntKey.h"
#include "alinous.btree/LongValue.h"
#include "alinous.db/AlinousDbException.h"
#include "alinous.db.table/DatabaseException.h"
#include "alinous.runtime.parallel/ThreadPool.h"
#include "alinous.system.config/AlinousInitException.h"
#include "alinous.system/ISystemLog.h"
#include "alinous.system/AlinousCore.h"
#include "alinous.remote.socket/ICommandData.h"
#include "alinous.db.table/TableMetadata.h"
#include "alinous.db.table/IDatabaseRecord.h"
#include "alinous.db.table/IDatabaseTable.h"
#include "alinous.remote.db.client.command.data/SchemasStructureInfoData.h"
#include "alinous.db/ITableSchema.h"
#include "alinous.db/TableSchema.h"
#include "alinous.db/SchemaManager.h"
#include "alinous.db.trx/DbVersionContext.h"
#include "alinous.lock.unique/UniqueExclusiveLockManager.h"
#include "alinous.system.config/IAlinousConfigElement.h"
#include "alinous.system.config.remote/MonitorRef.h"
#include "alinous.remote.db/MonitorAccess.h"
#include "alinous.remote.socket/SocketServer.h"
#include "alinous.remote.socket/ISocketActionFactory.h"
#include "alinous.remote.db/RemoteStorageResponceActionFactory.h"
#include "alinous.remote.region.client.command.data/ClientNetworkRecord.h"
#include "alinous.remote.region.server.schema.strategy/UniqueCheckOperation.h"
#include "alinous.remote.db.server.trx/StorageTransaction.h"
#include "alinous.remote.db.server.trx/StorageTransactionManager.h"
#include "alinous.remote.db.server/RemoteTableStorageServer.h"

namespace alinous {namespace remote {namespace db {namespace server {





String* RemoteTableStorageServer::THREAD_NAME = ConstStr::getCNST_STR_3590();
const IntKey RemoteTableStorageServer:: __SCHEMA = (IntKey(10, nullptr));
const IntKey RemoteTableStorageServer:: __SCHEMA_VERSION = (IntKey(11, nullptr));
bool RemoteTableStorageServer::__init_done = __init_static_variables();
bool RemoteTableStorageServer::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"RemoteTableStorageServer", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 RemoteTableStorageServer::RemoteTableStorageServer(int port, int maxthread, String* datadir, ThreadContext* ctx) throw()  : IObject(ctx), schemas(nullptr), BLOCK_SIZE(256), nodeCapacity(8), capacity(1024), port(0), maxthread(0), dataDir(nullptr), socketServer(nullptr), btreeCache(nullptr), workerThreadsPool(nullptr), core(nullptr), dbconfig(nullptr), configFile(nullptr), schemaVersionLock(__GC_INS(this, (new(ctx) LockObject(ctx)), LockObject)), schemaVersion(0), monitorAccess(nullptr), storageTrxManager(nullptr), uniqueExclusiveLock(nullptr)
{
	this->port = port;
	this->maxthread = maxthread;
	__GC_MV(this, &(this->dataDir), datadir, String);
	__GC_MV(this, &(this->storageTrxManager), (new(ctx) StorageTransactionManager(datadir, this, ctx)), StorageTransactionManager);
	__GC_MV(this, &(this->uniqueExclusiveLock), (new(ctx) UniqueExclusiveLockManager(ctx)), UniqueExclusiveLockManager);
}
void RemoteTableStorageServer::__construct_impl(int port, int maxthread, String* datadir, ThreadContext* ctx) throw() 
{
	this->port = port;
	this->maxthread = maxthread;
	__GC_MV(this, &(this->dataDir), datadir, String);
	__GC_MV(this, &(this->storageTrxManager), (new(ctx) StorageTransactionManager(datadir, this, ctx)), StorageTransactionManager);
	__GC_MV(this, &(this->uniqueExclusiveLock), (new(ctx) UniqueExclusiveLockManager(ctx)), UniqueExclusiveLockManager);
}
 RemoteTableStorageServer::~RemoteTableStorageServer() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void RemoteTableStorageServer::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"RemoteTableStorageServer", L"~RemoteTableStorageServer");
	__e_obj1.add(this->schemas, this);
	schemas = nullptr;
	__e_obj1.add(this->dataDir, this);
	dataDir = nullptr;
	__e_obj1.add(this->socketServer, this);
	socketServer = nullptr;
	__e_obj1.add(this->btreeCache, this);
	btreeCache = nullptr;
	__e_obj1.add(this->workerThreadsPool, this);
	workerThreadsPool = nullptr;
	__e_obj1.add(this->core, this);
	core = nullptr;
	__e_obj1.add(this->dbconfig, this);
	dbconfig = nullptr;
	__e_obj1.add(this->configFile, this);
	configFile = nullptr;
	__e_obj1.add(this->schemaVersionLock, this);
	schemaVersionLock = nullptr;
	__e_obj1.add(this->monitorAccess, this);
	monitorAccess = nullptr;
	__e_obj1.add(this->storageTrxManager, this);
	storageTrxManager = nullptr;
	__e_obj1.add(this->uniqueExclusiveLock, this);
	uniqueExclusiveLock = nullptr;
	if(!prepare){
		return;
	}
}
void RemoteTableStorageServer::init(AlinousCore* core, MonitorRef* monitorRef, ThreadContext* ctx)
{
	File* file = (new(ctx) File(this->dataDir, ctx));
	if(!file->exists(ctx))
	{
		file->mkdirs(ctx);
	}
	{
		try
		{
			__GC_MV(this, &(this->btreeCache), (new(ctx) BTreeGlobalCache(ctx))->init(1024, ctx), BTreeGlobalCache);
		}
		catch(BTreeException* e)
		{
			e->printStackTrace(ctx);
			throw (new(ctx) AlinousInitException(ConstStr::getCNST_STR_3586(), e, ctx));
		}
	}
	__GC_MV(this, &(this->workerThreadsPool), (new(ctx) ThreadPool(16, ConstStr::getCNST_STR_3587(), ctx)), ThreadPool);
	__GC_MV(this, &(this->monitorAccess), (new(ctx) MonitorAccess(monitorRef, ctx)), MonitorAccess);
	this->monitorAccess->init(ctx);
	if(exists(ctx))
	{
		return;
	}
	initInstance(core, ctx);
}
bool RemoteTableStorageServer::exists(ThreadContext* ctx) throw() 
{
	File* file = getConfigFile(ctx);
	return file->exists(ctx);
}
void RemoteTableStorageServer::start(AlinousCore* core, ThreadContext* ctx)
{
	__GC_MV(this, &(this->core), core, AlinousCore);
	File* file = getConfigFile(ctx);
	{
		try
		{
			__GC_MV(this, &(this->dbconfig), (new(ctx) BTree(ctx))->init(file, this->btreeCache, core->diskCache, ctx), BTree);
			this->dbconfig->open(ctx);
			ArrayList<IBTreeValue>* schemeValue = this->dbconfig->getValues(SCHEMA, ctx);
			__GC_MV(this, &(this->schemas), static_cast<SchemaManager*>(schemeValue->get(0, ctx)), SchemaManager);
			this->schemas->loadAfterFetch(this->dataDir, this->core->getLogger(ctx), this->workerThreadsPool, this->core, this->btreeCache, ctx);
			ArrayList<IBTreeValue>* schemeVersionValue = this->dbconfig->getValues(SCHEMA_VERSION, ctx);
			LongValue* lv = static_cast<LongValue*>(schemeVersionValue->get(0, ctx));
			this->schemaVersion = lv->value;
		}
		catch(IOException* e)
		{
			throw (new(ctx) AlinousInitException(ConstStr::getCNST_STR_3588(), ctx));
		}
		catch(InterruptedException* e)
		{
			throw (new(ctx) AlinousInitException(ConstStr::getCNST_STR_3588(), ctx));
		}
		catch(BTreeException* e)
		{
			throw (new(ctx) AlinousInitException(ConstStr::getCNST_STR_3588(), ctx));
		}
		catch(VariableException* e)
		{
			throw (new(ctx) AlinousInitException(ConstStr::getCNST_STR_3588(), ctx));
		}
		catch(DatabaseException* e)
		{
			throw (new(ctx) AlinousInitException(ConstStr::getCNST_STR_3588(), ctx));
		}
		catch(AlinousException* e)
		{
			throw (new(ctx) AlinousInitException(ConstStr::getCNST_STR_3588(), ctx));
		}
	}
	RemoteStorageResponceActionFactory* factory = (new(ctx) RemoteStorageResponceActionFactory(this, ctx));
	__GC_MV(this, &(this->socketServer), (new(ctx) SocketServer(this->port, core->getLogger(ctx), factory, ctx)), SocketServer);
	this->socketServer->start(this->maxthread, RemoteTableStorageServer::THREAD_NAME, ctx);
}
void RemoteTableStorageServer::dispose(ThreadContext* ctx) throw() 
{
	this->socketServer->dispose(ctx);
	this->workerThreadsPool->dispose(ctx);
	if(this->dbconfig != nullptr)
	{
		{
			try
			{
				this->dbconfig->close(ctx);
			}
			catch(IOException* e)
			{
				this->core->logError(e, ctx);
			}
			catch(InterruptedException* e)
			{
				this->core->logError(e, ctx);
			}
		}
	}
	if(this->monitorAccess != nullptr)
	{
		this->monitorAccess->dispose(ctx);
	}
	if(this->storageTrxManager != nullptr)
	{
		this->storageTrxManager->dispose(ctx);
	}
	if(this->uniqueExclusiveLock != nullptr)
	{
		this->uniqueExclusiveLock->dispose(ctx);
	}
}
UniqueExclusiveLockManager* RemoteTableStorageServer::getUniqueExclusiveLock(ThreadContext* ctx) throw() 
{
	return uniqueExclusiveLock;
}
AlinousCore* RemoteTableStorageServer::getCore(ThreadContext* ctx) throw() 
{
	return core;
}
void RemoteTableStorageServer::logError(Throwable* e, ThreadContext* ctx) throw() 
{
	ISystemLog* log = this->core->getLogger(ctx);
	log->logError(e, ctx);
}
long long RemoteTableStorageServer::getSchemeInfo(SchemasStructureInfoData* data, String* region, String* host, int port, bool ipv6, ThreadContext* ctx) throw() 
{
	this->schemas->getSchemaData(data, region, host, port, ipv6, ctx);
	{
		SynchronizedBlockObj __synchronized_2(this->schemaVersionLock, ctx);
		data->setSchemaVersion(this->schemaVersion, ctx);
		return this->schemaVersion;
	}
}
void RemoteTableStorageServer::createSchema(String* schemaName, ThreadContext* ctx)
{
	{
		SynchronizedBlockObj __synchronized_2(this->schemaVersionLock, ctx);
		this->schemas->createSchema(schemaName, ctx);
		this->schemaVersion ++ ;
		this->monitorAccess->reportSchemaUpdated(ctx);
	}
}
void RemoteTableStorageServer::createTable(TableMetadata* metadata, ThreadContext* ctx)
{
	{
		SynchronizedBlockObj __synchronized_2(this->schemaVersionLock, ctx);
		String* schemaName = metadata->getSchema(ctx);
		this->schemas->createTable(schemaName, metadata, this->workerThreadsPool, this->core, this->btreeCache, ctx);
		this->schemaVersion ++ ;
		this->monitorAccess->reportSchemaUpdated(ctx);
	}
}
void RemoteTableStorageServer::prepareInsert(String* schemaName, String* tableName, long long newCommitId, List<UniqueCheckOperation>* uniqueCheckOps, List<ClientNetworkRecord>* records, DbVersionContext* vctx, int isolationLevel, ThreadContext* ctx)
{
	TableSchema* schema = this->schemas->getSchema(schemaName, ctx);
	if(schema == nullptr)
	{
		throw (new(ctx) AlinousDbException(ConstStr::getCNST_STR_3589()->clone(ctx)->append(schemaName, ctx)->append(ConstStr::getCNST_STR_1125(), ctx), ctx));
	}
	IDatabaseTable* table = schema->getTableStore(tableName, ctx);
	if(table == nullptr)
	{
		throw (new(ctx) AlinousDbException(ConstStr::getCNST_STR_3589()->clone(ctx)->append(schemaName, ctx)->append(ConstStr::getCNST_STR_953(), ctx)->append(tableName, ctx)->append(ConstStr::getCNST_STR_1125(), ctx), ctx));
	}
	StorageTransaction* storageTrx = this->storageTrxManager->getStorageTransaction(isolationLevel, vctx, ctx);
	storageTrx->prepareInsert(table, uniqueCheckOps, records, ctx);
}
void RemoteTableStorageServer::initInstance(AlinousCore* core, ThreadContext* ctx)
{
	{
		std::function<void(void)> finallyLm2= [&, this]()
		{
			if(this->dbconfig != nullptr)
			{
				{
					try
					{
						this->dbconfig->close(ctx);
					}
					catch(IOException* e)
					{
						e->printStackTrace(ctx);
					}
					catch(InterruptedException* e)
					{
						e->printStackTrace(ctx);
					}
				}
			}
			if(this->schemas != nullptr)
			{
				__GC_MV(this, &(this->schemas), nullptr, SchemaManager);
			}
		};
		Releaser finalyCaller2(finallyLm2);
		try
		{
			File* file = getConfigFile(ctx);
			__GC_MV(this, &(this->schemas), (new(ctx) SchemaManager(this->dataDir, core->getLogger(ctx), this->workerThreadsPool, core, this->btreeCache, ctx)), SchemaManager);
			schemas->createSchema(ConstStr::getCNST_STR_1086(), ctx);
			__GC_MV(this, &(this->dbconfig), (new(ctx) BTree(ctx))->init(file, this->btreeCache, core->diskCache, ctx), BTree);
			this->dbconfig->initTreeStorage(nodeCapacity, IBTreeKey::TYPE_INT, IBTreeKey::TYPE_INT, capacity, (long long)BLOCK_SIZE, ctx);
			this->dbconfig->open(ctx);
			this->dbconfig->putKeyValue(SCHEMA, schemas, ctx);
			this->schemaVersion = 1;
			IBTreeValue* schemeValue = (new(ctx) LongValue(this->schemaVersion, ctx));
			this->dbconfig->putKeyValue(SCHEMA_VERSION, schemeValue, ctx);
		}
		catch(IOException* e)
		{
			throw (new(ctx) AlinousDbException(ConstStr::getCNST_STR_1675(), e, ctx));
		}
		catch(InterruptedException* e)
		{
			throw (new(ctx) AlinousDbException(ConstStr::getCNST_STR_1675(), e, ctx));
		}
		catch(BTreeException* e)
		{
			throw (new(ctx) AlinousDbException(ConstStr::getCNST_STR_1675(), e, ctx));
		}
		catch(VariableException* e)
		{
			throw (new(ctx) AlinousDbException(ConstStr::getCNST_STR_1675(), e, ctx));
		}
		catch(AlinousException* e)
		{
			throw (new(ctx) AlinousDbException(ConstStr::getCNST_STR_1675(), e, ctx));
		}
	}
}
File* RemoteTableStorageServer::getConfigFile(ThreadContext* ctx) throw() 
{
	if(this->configFile == nullptr)
	{
		String* pathname = this->dataDir->clone(ctx)->append(ConstStr::getCNST_STR_1679(), ctx);
		__GC_MV(this, &(this->configFile), (new(ctx) File(pathname, ctx)), File);
	}
	return this->configFile;
}
void RemoteTableStorageServer::__cleanUp(ThreadContext* ctx){
}
}}}}

