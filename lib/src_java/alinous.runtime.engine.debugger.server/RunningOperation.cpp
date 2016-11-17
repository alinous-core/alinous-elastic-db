#include "includes.h"


namespace alinous {namespace runtime {namespace engine {namespace debugger {namespace server {





bool RunningOperation::__init_done = __init_static_variables();
bool RunningOperation::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"RunningOperation", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 RunningOperation::RunningOperation(DebugThread* thread, AlinousScriptDebugger* manager, ThreadContext* ctx) throw()  : IObject(ctx), AbstractDebuggerOperation(thread, manager, ctx)
{
}
void RunningOperation::__construct_impl(DebugThread* thread, AlinousScriptDebugger* manager, ThreadContext* ctx) throw() 
{
}
 RunningOperation::~RunningOperation() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void RunningOperation::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
	AbstractDebuggerOperation::__releaseRegerences(true, ctx);
}
void RunningOperation::init(DebugThread* debugThread, AlinousScriptDebugger* manager, ThreadContext* ctx) throw() 
{
}
void RunningOperation::handleEvent(AlinousDebugEvent* event, ScriptMachine* machine, ThreadContext* ctx) throw() 
{
	MainStackFrame* frame = machine->getFrame(ctx);
	frame->setCurrentLine(event->getLine(ctx), ctx);
	long long id = hitBreakpoint(event, ctx);
	if(id < (long long)0)
	{
		return;
	}
	AlinousDebugEventNotifier* notifier = this->debugManager->getDebugEventNotifier(ctx);
	NotifyHitBreakpoint* command = (new(ctx) NotifyHitBreakpoint(this->thread->getThreadId(ctx), ctx));
	this->debugManager->setHotThreadId(this->thread->getThreadId(ctx), ctx);
	{
		try
		{
			notifier->sendCommand(command, machine, ctx);
		}
		catch(IOException* e)
		{
			e->printStackTrace(ctx);
			machine->getCore(ctx)->getLogger(ctx)->logError(e, ctx);
		}
	}
	{
		try
		{
			this->debugManager->setHotThreadId(id, ctx);
			this->thread->suspend(ctx);
		}
		catch(InterruptedException* e)
		{
			machine->getCore(ctx)->getLogger(ctx)->logError(e, ctx);
		}
	}
}
}}}}}

