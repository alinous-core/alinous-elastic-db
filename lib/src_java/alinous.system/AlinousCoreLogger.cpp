#include "include/global.h"


#include "alinous.compile/AbstractSrcElement.h"
#include "alinous.system/AlinousException.h"
#include "alinous.system/ISystemLog.h"
#include "alinous.system/AlinousCoreLogger.h"
#include "alinous.compile.sql.functions/SQLFunctionManager.h"
#include "alinous.remote.db/RemoteTableStorageServer.h"
#include "alinous.remote.monitor/TransactionMonitorServer.h"
#include "alinous.remote.region.server/NodeRegionServer.h"
#include "alinous.system.config/AlinousConfig.h"
#include "alinous.runtime/AlinousModuleRepository.h"
#include "alinous.runtime.dbif/DataSourceManager.h"
#include "alinous.runtime.engine.debugger/AlinousScriptDebugger.h"
#include "alinous.runtime.engine/ScriptRunner.h"
#include "alinous.server.webmodule/WebModuleManager.h"
#include "alinous.system.functions/AlinousFunctionManager.h"
#include "alinous.system/AlinousCore.h"
#include "alinous.system/AlinousNotSupportedException.h"

namespace alinous {namespace system {





bool AlinousCoreLogger::__init_done = __init_static_variables();
bool AlinousCoreLogger::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"AlinousCoreLogger", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 AlinousCoreLogger::AlinousCoreLogger(ThreadContext* ctx) throw()  : IObject(ctx), ISystemLog(ctx)
{
}
void AlinousCoreLogger::__construct_impl(ThreadContext* ctx) throw() 
{
}
 AlinousCoreLogger::~AlinousCoreLogger() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void AlinousCoreLogger::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
}
void AlinousCoreLogger::logError(Throwable* e, ThreadContext* ctx) throw() 
{
	e->printStackTrace(ctx);
}
void AlinousCoreLogger::logWarning(String* message, ThreadContext* ctx) throw() 
{
	System::out->println(message, ctx);
}
void AlinousCoreLogger::logInfo(String* message, ThreadContext* ctx) throw() 
{
	System::out->println(message, ctx);
}
void AlinousCoreLogger::__cleanUp(ThreadContext* ctx){
}
}}

