#include "includes.h"


namespace alinous {namespace runtime {namespace engine {namespace debugger {namespace server {





bool StepInOperation::__init_done = __init_static_variables();
bool StepInOperation::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"StepInOperation", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 StepInOperation::StepInOperation(DebugThread* thread, AlinousScriptDebugger* manager, ThreadContext* ctx) throw()  : IObject(ctx), AbstractDebuggerOperation(thread, manager, ctx)
{
}
void StepInOperation::__construct_impl(DebugThread* thread, AlinousScriptDebugger* manager, ThreadContext* ctx) throw() 
{
}
 StepInOperation::~StepInOperation() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void StepInOperation::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
	AbstractDebuggerOperation::__releaseRegerences(true, ctx);
}
void StepInOperation::handleEvent(AlinousDebugEvent* event, ScriptMachine* machine, ThreadContext* ctx) throw() 
{
	MainStackFrame* frame = machine->getFrame(ctx);
	frame->setCurrentLine(event->getLine(ctx), ctx);
}
void StepInOperation::init(DebugThread* debugThread, AlinousScriptDebugger* manager, ThreadContext* ctx) throw() 
{
}
}}}}}

