#include "includes.h"


namespace alinous {namespace runtime {namespace engine {namespace debugger {namespace server {





bool StepOverOperation::__init_done = __init_static_variables();
bool StepOverOperation::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"StepOverOperation", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 StepOverOperation::StepOverOperation(DebugThread* thread, AlinousScriptDebugger* manager, long long currentStackId, ThreadContext* ctx) throw()  : IObject(ctx), AbstractDebuggerOperation(thread, manager, ctx), currentStackId(0)
{
	this->currentStackId = currentStackId;
}
void StepOverOperation::__construct_impl(DebugThread* thread, AlinousScriptDebugger* manager, long long currentStackId, ThreadContext* ctx) throw() 
{
	this->currentStackId = currentStackId;
}
 StepOverOperation::~StepOverOperation() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void StepOverOperation::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"StepOverOperation", L"~StepOverOperation");
	if(!prepare){
		return;
	}
	AbstractDebuggerOperation::__releaseRegerences(true, ctx);
}
void StepOverOperation::handleEvent(AlinousDebugEvent* event, ScriptMachine* machine, ThreadContext* ctx) throw() 
{
	MainStackFrame* frame = machine->getFrame(ctx);
	frame->setCurrentLine(event->getLine(ctx), ctx);
}
void StepOverOperation::init(DebugThread* debugThread, AlinousScriptDebugger* manager, ThreadContext* ctx) throw() 
{
}
long long StepOverOperation::getCurrentStackId(ThreadContext* ctx) throw() 
{
	return currentStackId;
}
void StepOverOperation::setCurrentStackId(long long currentStackId, ThreadContext* ctx) throw() 
{
	this->currentStackId = currentStackId;
}
}}}}}

