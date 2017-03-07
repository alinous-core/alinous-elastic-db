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




bool ISystemLog::__init_done = __init_static_variables();
bool ISystemLog::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"ISystemLog", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 ISystemLog::ISystemLog(ThreadContext* ctx) throw()  : IObject(ctx)
{
}
void ISystemLog::__construct_impl(ThreadContext* ctx) throw() 
{
}
 ISystemLog::~ISystemLog() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void ISystemLog::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
}
void ISystemLog::__cleanUp(ThreadContext* ctx){
}
}}

