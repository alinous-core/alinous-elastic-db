#include "includes.h"


namespace alinous {namespace remote {namespace db {





String* RemoteTableStorageServer::THREAD_NAME = ConstStr::getCNST_STR_3483();
const IntKey RemoteTableStorageServer:: __SCHEMA = (IntKey(10, nullptr));
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
 RemoteTableStorageServer::RemoteTableStorageServer(int port, int maxthread, String* datadir, ThreadContext* ctx) throw()  : IObject(ctx), schemas(nullptr), port(0), maxthread(0), dataDir(nullptr), socketServer(nullptr), btreeCache(nullptr), workerThreadsPool(nullptr), core(nullptr), dbconfig(nullptr), configFile(nullptr)
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
			throw (new(ctx) AlinousInitException(ConstStr::getCNST_STR_3481(), e, ctx));
		}
	}
	__GC_MV(this, &(this->workerThreadsPool), (new(ctx) ThreadPool(16, ConstStr::getCNST_STR_3482(), ctx)), ThreadPool);
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
	__GC_MV(this, &(this->workerThreadsPool), (new(ctx) ThreadPool(16, ConstStr::getCNST_STR_1594(), ctx)), ThreadPool);
	RemoteStorageResponceActionFactory* factory = (new(ctx) RemoteStorageResponceActionFactory(this, ctx));
	__GC_MV(this, &(this->socketServer), (new(ctx) SocketServer(this->port, core->getLogger(ctx), factory, ctx)), SocketServer);
	this->socketServer->start(this->maxthread, RemoteTableStorageServer::THREAD_NAME, ctx);
	__GC_MV(this, &(this->schemas), (new(ctx) SchemaManager(this->dataDir, core->getLogger(ctx), this->workerThreadsPool, core, this->btreeCache, ctx)), SchemaManager);
}
void RemoteTableStorageServer::dispose(ThreadContext* ctx) throw() 
{
	this->socketServer->dispose(ctx);
	this->workerThreadsPool->dispose(ctx);
}
AlinousCore* RemoteTableStorageServer::getCore(ThreadContext* ctx) throw() 
{
	return core;
}
void RemoteTableStorageServer::initInstance(AlinousCore* core, ThreadContext* ctx)
{
	int BLOCK_SIZE = 256;
	int nodeCapacity = 8;
	long long capacity = 1024;
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
			schemas->createSchema(ConstStr::getCNST_STR_951(), ctx);
			__GC_MV(this, &(this->dbconfig), (new(ctx) BTree(ctx))->init(file, this->btreeCache, core->diskCache, ctx), BTree);
			this->dbconfig->initTreeStorage(nodeCapacity, IBTreeKey::TYPE_INT, IBTreeKey::TYPE_INT, capacity, (long long)BLOCK_SIZE, ctx);
			this->dbconfig->open(ctx);
			this->dbconfig->putKeyValue(SCHEMA, schemas, ctx);
		}
		catch(IOException* e)
		{
			throw (new(ctx) AlinousDbException(ConstStr::getCNST_STR_1596(), e, ctx));
		}
		catch(InterruptedException* e)
		{
			throw (new(ctx) AlinousDbException(ConstStr::getCNST_STR_1596(), e, ctx));
		}
		catch(BTreeException* e)
		{
			throw (new(ctx) AlinousDbException(ConstStr::getCNST_STR_1596(), e, ctx));
		}
		catch(VariableException* e)
		{
			throw (new(ctx) AlinousDbException(ConstStr::getCNST_STR_1596(), e, ctx));
		}
	}
}
File* RemoteTableStorageServer::getConfigFile(ThreadContext* ctx) throw() 
{
	if(this->configFile == nullptr)
	{
		String* pathname = this->dataDir->clone(ctx)->append(ConstStr::getCNST_STR_1598(), ctx);
		__GC_MV(this, &(this->configFile), (new(ctx) File(pathname, ctx)), File);
	}
	return this->configFile;
}
}}}

