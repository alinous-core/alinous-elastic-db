#include "includes.h"


namespace alinous {namespace system {





bool AlinousCore::__init_done = __init_static_variables();
bool AlinousCore::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"AlinousCore", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 AlinousCore::AlinousCore(String* home, bool debug, ThreadContext* ctx) throw()  : IObject(ctx), diskCache(nullptr), sqlFunctionManager(nullptr), webModuleManager(nullptr), debug(0), alinousHome(nullptr), config(nullptr), logger(nullptr), functionManager(nullptr), modulerepository(nullptr), databaseManager(nullptr), debugger(nullptr), runner(nullptr)
{
	if(home->endsWith(ConstStr::getCNST_STR_984(), ctx))
	{
		__GC_MV(this, &(this->alinousHome), home, String);
	}
		else 
	{
		__GC_MV(this, &(this->alinousHome), home->clone(ctx)->append(ConstStr::getCNST_STR_984(), ctx), String);
	}
	this->debug = debug;
}
void AlinousCore::__construct_impl(String* home, bool debug, ThreadContext* ctx) throw() 
{
	if(home->endsWith(ConstStr::getCNST_STR_984(), ctx))
	{
		__GC_MV(this, &(this->alinousHome), home, String);
	}
		else 
	{
		__GC_MV(this, &(this->alinousHome), home->clone(ctx)->append(ConstStr::getCNST_STR_984(), ctx), String);
	}
	this->debug = debug;
}
 AlinousCore::~AlinousCore() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void AlinousCore::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"AlinousCore", L"~AlinousCore");
	__e_obj1.add(this->diskCache, this);
	diskCache = nullptr;
	__e_obj1.add(this->sqlFunctionManager, this);
	sqlFunctionManager = nullptr;
	__e_obj1.add(this->webModuleManager, this);
	webModuleManager = nullptr;
	__e_obj1.add(this->alinousHome, this);
	alinousHome = nullptr;
	__e_obj1.add(this->config, this);
	config = nullptr;
	__e_obj1.add(this->logger, this);
	logger = nullptr;
	__e_obj1.add(this->functionManager, this);
	functionManager = nullptr;
	__e_obj1.add(this->modulerepository, this);
	modulerepository = nullptr;
	__e_obj1.add(this->databaseManager, this);
	databaseManager = nullptr;
	__e_obj1.add(this->debugger, this);
	debugger = nullptr;
	__e_obj1.add(this->runner, this);
	runner = nullptr;
	if(!prepare){
		return;
	}
}
void AlinousCore::init(int debugPort, ThreadContext* ctx)
{
	__GC_MV(this, &(this->logger), (new(ctx) AlinousCoreLogger(ctx)), AlinousCoreLogger);
	__GC_MV(this, &(this->diskCache), (new(ctx) DiskCacheManager(ctx)), DiskCacheManager);
	__GC_MV(this, &(this->config), (new(ctx) AlinousConfig(this->alinousHome, ctx)), AlinousConfig);
	this->config->parseInitFile(ctx);
	__GC_MV(this, &(this->functionManager), (new(ctx) AlinousFunctionManager(this, ctx)), AlinousFunctionManager);
	this->functionManager->init(ctx);
	__GC_MV(this, &(this->modulerepository), (new(ctx) AlinousModuleRepository(this, ctx)), AlinousModuleRepository);
	__GC_MV(this, &(this->debugger), (new(ctx) AlinousScriptDebugger(this, debugPort, ctx)), AlinousScriptDebugger);
	__GC_MV(this, &(this->runner), (new(ctx) ScriptRunner(ctx)), ScriptRunner);
	__GC_MV(this, &(this->sqlFunctionManager), (new(ctx) SQLFunctionManager(ctx)), SQLFunctionManager);
	__GC_MV(this, &(this->webModuleManager), (new(ctx) WebModuleManager(this, ctx)), WebModuleManager);
}
void AlinousCore::initDatabase(ThreadContext* ctx)
{
	__GC_MV(this, &(this->databaseManager), (new(ctx) DataSourceManager(this, ctx)), DataSourceManager);
	this->databaseManager->init(ctx);
}
void AlinousCore::dispose(ThreadContext* ctx) throw() 
{
	if(this->functionManager != nullptr)
	{
		this->functionManager->dispose(ctx);
		__GC_MV(this, &(this->functionManager), nullptr, AlinousFunctionManager);
	}
	if(this->config != nullptr)
	{
		__GC_MV(this, &(this->config), nullptr, AlinousConfig);
	}
	if(this->databaseManager != nullptr)
	{
		this->databaseManager->dispose(ctx);
	}
	if(this->debugger != nullptr)
	{
		{
			try
			{
				this->debugger->dispose(ctx);
			}
			catch(InterruptedException* e)
			{
				getLogger(ctx)->logError(e, ctx);
			}
		}
	}
}
String* AlinousCore::getAlinousHome(ThreadContext* ctx) throw() 
{
	return alinousHome;
}
AlinousConfig* AlinousCore::getConfig(ThreadContext* ctx) throw() 
{
	return config;
}
AlinousModuleRepository* AlinousCore::getModulerepository(ThreadContext* ctx) throw() 
{
	return modulerepository;
}
DataSourceManager* AlinousCore::getDatabaseManager(ThreadContext* ctx) throw() 
{
	return databaseManager;
}
ISystemLog* AlinousCore::getLogger(ThreadContext* ctx) throw() 
{
	return logger;
}
ScriptRunner* AlinousCore::getRunner(ThreadContext* ctx) throw() 
{
	return runner;
}
AlinousScriptDebugger* AlinousCore::getDebugger(ThreadContext* ctx) throw() 
{
	return debugger;
}
AlinousFunctionManager* AlinousCore::getFunctionManager(ThreadContext* ctx) throw() 
{
	return functionManager;
}
}}

