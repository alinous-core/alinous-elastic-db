#include "includes.h"


namespace alinous {namespace runtime {namespace engine {namespace debugger {namespace server {





bool StepReturnOperation::__init_done = __init_static_variables();
bool StepReturnOperation::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"StepReturnOperation", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 StepReturnOperation::StepReturnOperation(DebugThread* thread, AlinousScriptDebugger* manager, long long currentStackId, ThreadContext* ctx) throw()  : IObject(ctx), AbstractDebuggerOperation(thread, manager, ctx), currentStackId(0)
{
	this->currentStackId = currentStackId;
}
void StepReturnOperation::__construct_impl(DebugThread* thread, AlinousScriptDebugger* manager, long long currentStackId, ThreadContext* ctx) throw() 
{
	this->currentStackId = currentStackId;
}
 StepReturnOperation::~StepReturnOperation() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void StepReturnOperation::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"StepReturnOperation", L"~StepReturnOperation");
	if(!prepare){
		return;
	}
	AbstractDebuggerOperation::__releaseRegerences(true, ctx);
}
void StepReturnOperation::handleEvent(AlinousDebugEvent* event, ScriptMachine* machine, ThreadContext* ctx) throw() 
{
	MainStackFrame* frame = machine->getFrame(ctx);
	frame->setCurrentLine(event->getLine(ctx), ctx);
}
void StepReturnOperation::init(DebugThread* debugThread, AlinousScriptDebugger* manager, ThreadContext* ctx) throw() 
{
}
long long StepReturnOperation::getCurrentStackId(ThreadContext* ctx) throw() 
{
	return currentStackId;
}
}}}}}

