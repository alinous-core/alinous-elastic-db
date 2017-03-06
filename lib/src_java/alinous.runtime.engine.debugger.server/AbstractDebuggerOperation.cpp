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





bool AbstractDebuggerOperation::__init_done = __init_static_variables();
bool AbstractDebuggerOperation::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"AbstractDebuggerOperation", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 AbstractDebuggerOperation::AbstractDebuggerOperation(DebugThread* thread, AlinousScriptDebugger* manager, ThreadContext* ctx) throw()  : IObject(ctx), IDebuggerOperation(ctx), debugManager(nullptr), thread(nullptr)
{
	__GC_MV(this, &(this->debugManager), manager, AlinousScriptDebugger);
	__GC_MV(this, &(this->thread), thread, DebugThread);
}
void AbstractDebuggerOperation::__construct_impl(DebugThread* thread, AlinousScriptDebugger* manager, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->debugManager), manager, AlinousScriptDebugger);
	__GC_MV(this, &(this->thread), thread, DebugThread);
}
 AbstractDebuggerOperation::~AbstractDebuggerOperation() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void AbstractDebuggerOperation::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"AbstractDebuggerOperation", L"~AbstractDebuggerOperation");
	__e_obj1.add(this->debugManager, this);
	debugManager = nullptr;
	__e_obj1.add(this->thread, this);
	thread = nullptr;
	if(!prepare){
		return;
	}
}
long long AbstractDebuggerOperation::hitBreakpoint(AlinousDebugEvent* event, ThreadContext* ctx) throw() 
{
	FileBreakpointContainer* container = this->debugManager->getFileBreakpointContainer(event->getDebugFilePath(ctx), ctx);
	Iterator<ServerBreakPoint>* it = container->iterator(ctx);
	while(it->hasNext(ctx))
	{
		ServerBreakPoint* breakpoint = it->next(ctx);
		if(breakpoint->getLine(ctx) == event->getLine(ctx))
		{
			return event->getThread(ctx)->getThreadId(ctx);
		}
	}
	return -1;
}
void AbstractDebuggerOperation::__cleanUp(ThreadContext* ctx){
}
}}}}}

