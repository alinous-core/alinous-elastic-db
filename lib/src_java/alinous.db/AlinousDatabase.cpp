#include "includes.h"


namespace alinous {namespace db {





const IntKey AlinousDatabase:: __SCHEMA = (IntKey(10, nullptr));
const IntKey AlinousDatabase:: __USERS = (IntKey(20, nullptr));
const IntKey AlinousDatabase:: __MAX_COMMIT_ID = (IntKey(30, nullptr));
bool AlinousDatabase::__init_done = __init_static_variables();
bool AlinousDatabase::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"AlinousDatabase", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 AlinousDatabase::AlinousDatabase(ThreadContext* ctx) throw()  : IObject(ctx), instanceConfigLock(__GC_INS(this, (new(ctx) LockObject(ctx)), LockObject)), trxManager(nullptr), trxLockManager(nullptr), localCommitId(nullptr), workerThreadsPool(nullptr), core(nullptr), dataDir(nullptr), dbconfig(nullptr), configFile(nullptr), trxWriterThread(nullptr), cahceEngine(nullptr), btreeCache(nullptr), regionManager(nullptr)
{
	__GC_MV(this, &(this->trxWriterThread), nullptr, AlinousThread);
	__GC_MV(this, &(this->workerThreadsPool), nullptr, ThreadPool);
	__GC_MV(this, &(this->localCommitId), (new(ctx) LocalCommitIdPublisher(this, ctx)), ICommidIdPublisher);
}
void AlinousDatabase::__construct_impl(ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->trxWriterThread), nullptr, AlinousThread);
	__GC_MV(this, &(this->workerThreadsPool), nullptr, ThreadPool);
	__GC_MV(this, &(this->localCommitId), (new(ctx) LocalCommitIdPublisher(this, ctx)), ICommidIdPublisher);
}
 AlinousDatabase::~AlinousDatabase() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void AlinousDatabase::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"AlinousDatabase", L"~AlinousDatabase");
	__e_obj1.add(this->instanceConfigLock, this);
	instanceConfigLock = nullptr;
	__e_obj1.add(this->trxManager, this);
	trxManager = nullptr;
	__e_obj1.add(this->trxLockManager, this);
	trxLockManager = nullptr;
	__e_obj1.add(this->localCommitId, this);
	localCommitId = nullptr;
	__e_obj1.add(this->workerThreadsPool, this);
	workerThreadsPool = nullptr;
	__e_obj1.add(this->core, this);
	core = nullptr;
	__e_obj1.add(this->dataDir, this);
	dataDir = nullptr;
	__e_obj1.add(this->dbconfig, this);
	dbconfig = nullptr;
	__e_obj1.add(this->configFile, this);
	configFile = nullptr;
	__e_obj1.add(this->trxWriterThread, this);
	trxWriterThread = nullptr;
	__e_obj1.add(this->cahceEngine, this);
	cahceEngine = nullptr;
	__e_obj1.add(this->btreeCache, this);
	btreeCache = nullptr;
	__e_obj1.add(this->regionManager, this);
	regionManager = nullptr;
	if(!prepare){
		return;
	}
}
void AlinousDatabase::construct(AlinousCore* core, String* dataDir, String* trxTmpDir, int maxConnection, ThreadContext* ctx)
{
	__GC_MV(this, &(this->cahceEngine), (new(ctx) RecordCacheEngine(ctx))->init(1024, ctx), RecordCacheEngine);
	__GC_MV(this, &(this->core), core, AlinousCore);
	__GC_MV(this, &(this->dataDir), dataDir, String);
	LocalTableRegion* localRegion = (new(ctx) LocalTableRegion(this->cahceEngine, dataDir, this->core->getLogger(ctx), this, ctx));
	__GC_MV(this, &(this->regionManager), (new(ctx) TableRegionManager(ctx)), TableRegionManager);
	this->regionManager->addRegion(localRegion, ctx);
	__GC_MV(this, &(this->trxManager), (new(ctx) DbTransactionManager(this, trxTmpDir, maxConnection, core->getLogger(ctx), this->workerThreadsPool, ctx)), DbTransactionManager);
	File* file = getConfigFile(ctx);
	{
		try
		{
			__GC_MV(this, &(this->btreeCache), (new(ctx) BTreeGlobalCache(ctx))->init(1024, ctx), BTreeGlobalCache);
			__GC_MV(this, &(this->dbconfig), (new(ctx) BTree(ctx))->init(file, this->btreeCache, core->diskCache, ctx), BTree);
		}
		catch(IOException* e)
		{
			throw (new(ctx) AlinousDbException(ConstStr::getCNST_STR_1588(), e, ctx));
		}
		catch(InterruptedException* e)
		{
			throw (new(ctx) AlinousDbException(ConstStr::getCNST_STR_1588(), e, ctx));
		}
		catch(BTreeException* e)
		{
			throw (new(ctx) AlinousDbException(ConstStr::getCNST_STR_1588(), e, ctx));
		}
	}
}
TrxLockContext* AlinousDatabase::newLockContext(ThreadContext* ctx) throw() 
{
	return this->trxLockManager->newLockContext(ctx);
}
void AlinousDatabase::initInstance(ThreadContext* ctx)
{
	File* file = (new(ctx) File(this->dataDir, ctx));
	if(!file->exists(ctx))
	{
		file->mkdirs(ctx);
	}
	LocalTableRegion* localRegion = this->regionManager->getLocalRegion(ctx);
	SchemaManager* schemas = localRegion->getSchemaManager(ctx);
	schemas->createSchema(ConstStr::getCNST_STR_951(), ctx);
	{
		try
		{
			int BLOCK_SIZE = 256;
			int nodeCapacity = 8;
			long long capacity = 1024;
			this->dbconfig->initTreeStorage(nodeCapacity, IBTreeKey::TYPE_INT, IBTreeKey::TYPE_INT, capacity, (long long)BLOCK_SIZE, ctx);
			this->dbconfig->open(ctx);
			this->dbconfig->putKeyValue(SCHEMA, schemas, ctx);
			LongValue* lvTrx = (new(ctx) LongValue(this->localCommitId->getMaxCommitId(ctx), ctx));
			this->dbconfig->putKeyValue(MAX_COMMIT_ID, lvTrx, ctx);
			this->dbconfig->close(ctx);
		}
		catch(IOException* e)
		{
			e->printStackTrace(ctx);
			throw (new(ctx) AlinousDbException(ConstStr::getCNST_STR_1589(), e, ctx));
		}
		catch(InterruptedException* e)
		{
			throw (new(ctx) AlinousDbException(ConstStr::getCNST_STR_1589(), e, ctx));
		}
		catch(BTreeException* e)
		{
			throw (new(ctx) AlinousDbException(ConstStr::getCNST_STR_1589(), e, ctx));
		}
		catch(VariableException* e)
		{
			throw (new(ctx) AlinousDbException(ConstStr::getCNST_STR_1589(), e, ctx));
		}
	}
}
long long AlinousDatabase::getCommitId(ThreadContext* ctx) throw() 
{
	return this->localCommitId->getMaxCommitId(ctx);
}
long long AlinousDatabase::newCommitId(ThreadContext* ctx)
{
	return this->localCommitId->newCommitId(ctx);
}
void AlinousDatabase::syncScheme(ThreadContext* ctx)
{
	LocalTableRegion* localRegion = this->regionManager->getLocalRegion(ctx);
	SchemaManager* schemas = localRegion->getSchemaManager(ctx);
	BTreeLeafNode* lvTrxIdNode = nullptr;
	{
		try
		{
			this->dbconfig->open(ctx);
			this->dbconfig->putKeyValue(SCHEMA, schemas, ctx);
			lvTrxIdNode = this->dbconfig->findByKey(MAX_COMMIT_ID, ctx);
			ArrayList<IBTreeValue>* trxvals = lvTrxIdNode->getValues(ctx);
			if(trxvals->size(ctx) > 0)
			{
				trxvals->clear(ctx);
				;
				trxvals->add((new(ctx) LongValue(this->localCommitId->getMaxCommitId(ctx), ctx)), ctx);
				lvTrxIdNode->save(ctx);
			}
						else 
			{
				LongValue* lvTrx = (new(ctx) LongValue(this->localCommitId->getMaxCommitId(ctx), ctx));
				this->dbconfig->putKeyValue(MAX_COMMIT_ID, lvTrx, ctx);
			}
			this->dbconfig->close(ctx);
		}
		catch(Throwable* e)
		{
			{
				try
				{
					if(lvTrxIdNode != nullptr)
					{
						lvTrxIdNode->endUse(ctx);
					}
				}
				catch(InterruptedException* e2)
				{
					e->printStackTrace(ctx);
					this->core->getLogger(ctx)->logError(e2, ctx);
				}
			}
			e->printStackTrace(ctx);
			throw (new(ctx) AlinousDbException(ConstStr::getCNST_STR_1590(), e, ctx));
		}
	}
	{
		try
		{
			lvTrxIdNode->endUse(ctx);
		}
		catch(InterruptedException* e)
		{
			e->printStackTrace(ctx);
			this->core->getLogger(ctx)->logError(e, ctx);
		}
	}
}
void AlinousDatabase::open(ThreadContext* ctx)
{
	__GC_MV(this, &(this->workerThreadsPool), (new(ctx) ThreadPool(16, ConstStr::getCNST_STR_1592(), ctx)), ThreadPool);
	LaunchJoin* trxLaunchJoin = (new(ctx) LaunchJoin(1, ctx));
	__GC_MV(this, &(this->trxWriterThread), (new(ctx) AlinousThread(trxLaunchJoin, ctx)), AlinousThread);
	{
		try
		{
			trxLaunchJoin->parentJoin(ctx);
		}
		catch(InterruptedException* e)
		{
			this->workerThreadsPool->dispose(ctx);
			__GC_MV(this, &(this->workerThreadsPool), nullptr, ThreadPool);
			throw (new(ctx) AlinousDbException(ConstStr::getCNST_STR_1593(), e, ctx));
		}
	}
	__GC_MV(this, &(this->trxLockManager), (new(ctx) TrxLockManager(ctx)), TrxLockManager);
	{
		try
		{
			this->dbconfig->open(ctx);
			ArrayList<IBTreeValue>* schemeValue = this->dbconfig->getValues(SCHEMA, ctx);
			if(schemeValue->size(ctx) > 0)
			{
				LocalTableRegion* localRegion = this->regionManager->getLocalRegion(ctx);
				SchemaManager* schemas = localRegion->getSchemaManager(ctx);
				schemas = static_cast<SchemaManager*>(schemeValue->get(0, ctx));
				schemas->loadAfterFetch(this->cahceEngine, this->dataDir, this->core->getLogger(ctx), this, ctx);
			}
			ArrayList<IBTreeValue>* lvTrxIds = this->dbconfig->getValues(MAX_COMMIT_ID, ctx);
			this->localCommitId->setMaxCommitId((static_cast<LongValue*>(lvTrxIds->get(0, ctx)))->value, ctx);
		}
		catch(Throwable* e)
		{
			{
				try
				{
					this->dbconfig->close(ctx);
				}
				catch(IOException* e2)
				{
					throw (new(ctx) AlinousDbException(ConstStr::getCNST_STR_1594(), e2, ctx));
				}
				catch(InterruptedException* e2)
				{
					throw (new(ctx) AlinousDbException(ConstStr::getCNST_STR_1594(), e2, ctx));
				}
			}
			throw (new(ctx) AlinousDbException(ConstStr::getCNST_STR_1594(), e, ctx));
		}
	}
	{
		try
		{
			this->dbconfig->close(ctx);
		}
		catch(IOException* e)
		{
			throw (new(ctx) AlinousDbException(ConstStr::getCNST_STR_1594(), e, ctx));
		}
		catch(InterruptedException* e)
		{
			throw (new(ctx) AlinousDbException(ConstStr::getCNST_STR_1594(), e, ctx));
		}
	}
}
TableSchemaCollection* AlinousDatabase::getSchema(String* name, ThreadContext* ctx) throw() 
{
	return this->regionManager->getSchema(name, ctx);
}
IDatabaseTable* AlinousDatabase::getTable(AlinousName* tableName, String* currentSchema, ThreadContext* ctx) throw() 
{
	ArrayList<String>* segs = tableName->getSegments(ctx);
	int size = segs->size(ctx);
	if(size == 1)
	{
		return getTable(currentSchema, segs->get(0, ctx), ctx);
	}
	return getTable(segs->get(0, ctx), segs->get(1, ctx), ctx);
}
IDatabaseTable* AlinousDatabase::getTable(String* schemaName, String* tableName, ThreadContext* ctx) throw() 
{
	TableSchemaCollection* sc = this->regionManager->getSchema(schemaName, ctx);
	return sc->getTableStore(tableName, ctx);
}
void AlinousDatabase::closeDatabase(ThreadContext* ctx) throw() 
{
	{
		try
		{
			{
				SynchronizedBlockObj __synchronized_3(instanceConfigLock, ctx);
				syncScheme(ctx);
			}
		}
		catch(AlinousDbException* e)
		{
			this->core->getLogger(ctx)->logError(e, ctx);
		}
	}
	if(this->trxManager != nullptr)
	{
		this->trxManager->dispose(ctx);
		__GC_MV(this, &(this->trxManager), nullptr, DbTransactionManager);
	}
	if(this->workerThreadsPool != nullptr)
	{
		this->workerThreadsPool->dispose(ctx);
		__GC_MV(this, &(this->workerThreadsPool), nullptr, ThreadPool);
	}
	if(this->trxWriterThread != nullptr)
	{
		this->trxWriterThread->shutdown(ctx);
		__GC_MV(this, &(this->trxWriterThread), nullptr, AlinousThread);
	}
}
AlinousDbConnection* AlinousDatabase::connect(ConnectInfo* info, ThreadContext* ctx) throw() 
{
	AlinousDbConnection* con = (new(ctx) AlinousDbConnection(this, info, ctx));
	return con;
}
void AlinousDatabase::disConnect(AlinousDbConnection* con, ThreadContext* ctx) throw() 
{
}
void AlinousDatabase::dropInstance(ThreadContext* ctx) throw() 
{
	File* file = (new(ctx) File(this->dataDir, ctx));
	if(file->exists(ctx))
	{
		FileUtils::removeAll(file, ctx);
	}
}
bool AlinousDatabase::exists(ThreadContext* ctx) throw() 
{
	File* file = getConfigFile(ctx);
	return file->exists(ctx);
}
AlinousCore* AlinousDatabase::getCore(ThreadContext* ctx) throw() 
{
	return core;
}
BTreeGlobalCache* AlinousDatabase::getBtreeCache(ThreadContext* ctx) throw() 
{
	return btreeCache;
}
TableRegionManager* AlinousDatabase::getRegionManager(ThreadContext* ctx) throw() 
{
	return regionManager;
}
File* AlinousDatabase::getConfigFile(ThreadContext* ctx) throw() 
{
	if(this->configFile == nullptr)
	{
		String* pathname = this->dataDir->clone(ctx)->append(ConstStr::getCNST_STR_1591(), ctx);
		__GC_MV(this, &(this->configFile), (new(ctx) File(pathname, ctx)), File);
	}
	return this->configFile;
}
}}

