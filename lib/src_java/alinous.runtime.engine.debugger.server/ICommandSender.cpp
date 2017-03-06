#include "include/global.h"


#include "alinous.runtime.engine/ScriptMachine.h"
#include "alinous.runtime.engine.debugger.server/ServerBreakPoint.h"
#include "alinous.runtime.engine.debugger.server/FileBreakpointContainer.h"
#include "alinous.runtime.engine.debugger.server/IServerCommand.h"
#include "alinous.runtime.engine.debugger.server/AbstractAlinousServerCommand.h"
#include "alinous.runtime.engine.debugger.server/NotifyHitBreakpoint.h"
#include "alinous.runtime.engine.debugger.server/IDebuggerOperation.h"
#include "alinous.runtime.engine.debugger.server/AbstractDebuggerOperation.h"
#include "alinous.runtime.engine.debugger.server/RunningOperation.h"
#include "alinous.runtime.engine.debugger/DebugThread.h"
#include "alinous.runtime.engine.debugger/AlinousDebugEvent.h"
#include "alinous.runtime.engine.debugger.server/NotifyThreadEndedCommand.h"
#include "alinous.runtime.engine.debugger.server/NotifyThreadStartCommand.h"
#include "alinous.runtime.engine.debugger/AlinousScriptDebugger.h"
#include "alinous.runtime.engine.debugger.server/ICommandSender.h"
#include "alinous.runtime.engine.debugger.server/NotifyStepOverFinishedCommand.h"
#include "alinous.runtime.engine.debugger.server/NotifyTerminatedCommand.h"
#include "alinous.runtime.engine.debugger.server/NotifyResumeComand.h"
#include "alinous.runtime.engine.debugger.server/NotifyExceptionThrownCommand.h"
#include "alinous.runtime.engine.debugger.server/NotifyStepInFinishedCommand.h"
#include "alinous.runtime.engine.debugger.server/StepOverOperation.h"
#include "alinous.runtime.engine.debugger.server/NotifyStepReturnFinishedCommand.h"
#include "alinous.runtime.engine.debugger.server/StepInOperation.h"
#include "alinous.runtime.engine.debugger.server/StepReturnOperation.h"
#include "alinous.runtime.engine.debugger.server/NotifyStartCommand.h"

namespace alinous {namespace runtime {namespace engine {namespace debugger {namespace server {




bool ICommandSender::__init_done = __init_static_variables();
bool ICommandSender::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"ICommandSender", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 ICommandSender::ICommandSender(ThreadContext* ctx) throw()  : IObject(ctx)
{
}
void ICommandSender::__construct_impl(ThreadContext* ctx) throw() 
{
}
 ICommandSender::~ICommandSender() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void ICommandSender::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
}
void ICommandSender::__cleanUp(ThreadContext* ctx){
}
}}}}}

