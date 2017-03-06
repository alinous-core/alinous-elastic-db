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





bool AbstractAlinousServerCommand::__init_done = __init_static_variables();
bool AbstractAlinousServerCommand::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"AbstractAlinousServerCommand", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 AbstractAlinousServerCommand::AbstractAlinousServerCommand(long long threadId, ThreadContext* ctx) throw()  : IObject(ctx), IServerCommand(ctx), threadId(0)
{
	this->threadId = threadId;
}
void AbstractAlinousServerCommand::__construct_impl(long long threadId, ThreadContext* ctx) throw() 
{
	this->threadId = threadId;
}
 AbstractAlinousServerCommand::~AbstractAlinousServerCommand() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void AbstractAlinousServerCommand::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"AbstractAlinousServerCommand", L"~AbstractAlinousServerCommand");
	if(!prepare){
		return;
	}
}
long long AbstractAlinousServerCommand::getThreadId(ThreadContext* ctx) throw() 
{
	return this->threadId;
}
void AbstractAlinousServerCommand::sendCommand(ICommandSender* notifier, ScriptMachine* context, ThreadContext* ctx)
{
	notifier->debugOut(ConstStr::getCNST_STR_1212()->clone(ctx)->append(this->toString(ctx), ctx), ctx);
	notifier->sendCommand(this, context, ctx);
}
bool AbstractAlinousServerCommand::containsThread(long long threadId, List<IServerCommand>* needfinish, bool remove, ThreadContext* ctx) throw() 
{
	bool retvalue = false;
	Iterator<IServerCommand>* it = needfinish->iterator(ctx);
	while(it->hasNext(ctx))
	{
		IServerCommand* cmd = it->next(ctx);
		if(cmd->getThreadId(ctx) == threadId)
		{
			if(remove)
			{
				it->remove(ctx);
			}
			retvalue = true;
		}
	}
	return retvalue;
}
void AbstractAlinousServerCommand::__cleanUp(ThreadContext* ctx){
}
}}}}}

