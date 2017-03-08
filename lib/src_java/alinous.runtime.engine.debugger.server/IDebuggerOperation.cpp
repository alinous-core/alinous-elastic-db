#include "include/global.h"


#include "alinous.runtime.engine/ScriptMachine.h"
#include "alinous.runtime.engine.debugger/AlinousScriptDebugger.h"
#include "alinous.runtime.engine.debugger/DebugThread.h"
#include "alinous.runtime.engine.debugger/AlinousDebugEvent.h"
#include "alinous.runtime.engine.debugger.server/IDebuggerOperation.h"

namespace alinous {namespace runtime {namespace engine {namespace debugger {namespace server {




bool IDebuggerOperation::__init_done = __init_static_variables();
bool IDebuggerOperation::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"IDebuggerOperation", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 IDebuggerOperation::IDebuggerOperation(ThreadContext* ctx) throw()  : IObject(ctx)
{
}
void IDebuggerOperation::__construct_impl(ThreadContext* ctx) throw() 
{
}
 IDebuggerOperation::~IDebuggerOperation() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void IDebuggerOperation::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
}
void IDebuggerOperation::__cleanUp(ThreadContext* ctx){
}
}}}}}

