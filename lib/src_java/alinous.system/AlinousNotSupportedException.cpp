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





constexpr const long long AlinousNotSupportedException::serialVersionUID;
bool AlinousNotSupportedException::__init_done = __init_static_variables();
bool AlinousNotSupportedException::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"AlinousNotSupportedException", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 AlinousNotSupportedException::AlinousNotSupportedException(ThreadContext* ctx) throw()  : IObject(ctx), AlinousException(ctx)
{
}
void AlinousNotSupportedException::__construct_impl(ThreadContext* ctx) throw() 
{
}
 AlinousNotSupportedException::AlinousNotSupportedException(String* msg, ThreadContext* ctx) throw()  : IObject(ctx), AlinousException(msg, ctx)
{
}
void AlinousNotSupportedException::__construct_impl(String* msg, ThreadContext* ctx) throw() 
{
}
 AlinousNotSupportedException::AlinousNotSupportedException(String* msg, Throwable* e, ThreadContext* ctx) throw()  : IObject(ctx), AlinousException(msg, e, ctx)
{
}
void AlinousNotSupportedException::__construct_impl(String* msg, Throwable* e, ThreadContext* ctx) throw() 
{
}
 AlinousNotSupportedException::~AlinousNotSupportedException() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void AlinousNotSupportedException::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
	AlinousException::__releaseRegerences(true, ctx);
}
void AlinousNotSupportedException::__cleanUp(ThreadContext* ctx){
}
}}

