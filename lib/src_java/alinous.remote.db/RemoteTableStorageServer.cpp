#include "includes.h"


namespace alinous {namespace remote {namespace db {





String* RemoteTableStorageServer::THREAD_NAME = ConstStr::getCNST_STR_3538();
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
 RemoteTableStorageServer::RemoteTableStorageServer(int port, int maxthread, String* datadir, ThreadContext* ctx) throw()  : IObject(ctx), schemas(nullptr), BLOCK_SIZE(256), nodeCapacity(8), capacity(1024), port(0), maxthread(0), dataDir(nullptr), socketServer(nullptr), btreeCache(nullptr), workerThreadsPool(nullptr), core(nullptr), dbconfig(nullptr), configFile(nullptr), schemaVersion(0)
{
	this->port = port;
	this->maxthread = maxthread;
	__GC_MV(this, &(this->dataDir), datadir, String);
}
void RemoteTableStorageServer::__construct_impl(int port, int maxthread, String* datadir, ThreadContext* ctx) throw() 
{
	this->port = port;
	this->maxthread = maxthread;
	__GC_MV(this, &(this->dataDir), datadir, String);
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
	if(!prepare){
		return;
	}
}
void RemoteTableStorageServer::init(AlinousCore* core, ThreadContext* ctx)
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
			throw (new(ctx) AlinousInitException(ConstStr::getCNST_STR_3535(), e, ctx));
		}
	}
	__GC_MV(this, &(this->workerThreadsPool), (new(ctx) ThreadPool(16, ConstStr::getCNST_STR_3536(), ctx)), ThreadPool);
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
			throw (new(ctx) AlinousInitException(ConstStr::getCNST_STR_3537(), ctx));
		}
		catch(InterruptedException* e)
		{
			throw (new(ctx) AlinousInitException(ConstStr::getCNST_STR_3537(), ctx));
		}
		catch(BTreeException* e)
		{
			throw (new(ctx) AlinousInitException(ConstStr::getCNST_STR_3537(), ctx));
		}
		catch(VariableException* e)
		{
			throw (new(ctx) AlinousInitException(ConstStr::getCNST_STR_3537(), ctx));
		}
		catch(DatabaseException* e)
		{
			throw (new(ctx) AlinousInitException(ConstStr::getCNST_STR_3537(), ctx));
		}
		catch(AlinousException* e)
		{
			throw (new(ctx) AlinousInitException(ConstStr::getCNST_STR_3537(), ctx));
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
				this->core->getLogger(ctx)->logError(e, ctx);
			}
			catch(InterruptedException* e)
			{
				this->core->getLogger(ctx)->logError(e, ctx);
			}
		}
	}
}
AlinousCore* RemoteTableStorageServer::getCore(ThreadContext* ctx) throw() 
{
	return core;
}
void RemoteTableStorageServer::getSchemeInfo(SchemasStructureInfoData* data, ThreadContext* ctx) throw() 
{
	this->schemas->getSchemaData(data, ctx);
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
			schemas->createSchema(ConstStr::getCNST_STR_955(), ctx);
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
			throw (new(ctx) AlinousDbException(ConstStr::getCNST_STR_1648(), e, ctx));
		}
		catch(InterruptedException* e)
		{
			throw (new(ctx) AlinousDbException(ConstStr::getCNST_STR_1648(), e, ctx));
		}
		catch(BTreeException* e)
		{
			throw (new(ctx) AlinousDbException(ConstStr::getCNST_STR_1648(), e, ctx));
		}
		catch(VariableException* e)
		{
			throw (new(ctx) AlinousDbException(ConstStr::getCNST_STR_1648(), e, ctx));
		}
	}
}
File* RemoteTableStorageServer::getConfigFile(ThreadContext* ctx) throw() 
{
	if(this->configFile == nullptr)
	{
		String* pathname = this->dataDir->clone(ctx)->append(ConstStr::getCNST_STR_1652(), ctx);
		__GC_MV(this, &(this->configFile), (new(ctx) File(pathname, ctx)), File);
	}
	return this->configFile;
}
}}}

