#include "includes.h"


namespace alinous {namespace runtime {namespace engine {namespace debugger {namespace client {





String* StepReturnRequest::THREAD_ID = ConstStr::getCNST_STR_1193();
String* StepReturnRequest::STACK_ID = ConstStr::getCNST_STR_1194();
bool StepReturnRequest::__init_done = __init_static_variables();
bool StepReturnRequest::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"StepReturnRequest", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 StepReturnRequest::~StepReturnRequest() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void StepReturnRequest::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"StepReturnRequest", L"~StepReturnRequest");
	if(!prepare){
		return;
	}
}
AlinousServerDebugHttpResponse* StepReturnRequest::executeRequest(AlinousScriptDebugger* debugManager, ThreadContext* ctx) throw() 
{
	DebugThread* debugThread = debugManager->getDebugThread(this->threadId, ctx);
	debugManager->setOperation(this->threadId, (new(ctx) StepReturnOperation(debugThread, debugManager, this->stackId, ctx)), ctx);
	debugManager->resume(this->threadId, ctx);
	AlinousServerDebugHttpResponse* responce = (new(ctx) AlinousServerDebugHttpResponse(0, ctx));
	return responce;
}
String* StepReturnRequest::getCommand(ThreadContext* ctx) throw() 
{
	return IClientRequest::CMD_STEP_RETURN;
}
Map<String,String>* StepReturnRequest::getParamMap(ThreadContext* ctx) throw() 
{
	Map<String,String>* m = (new(ctx) HashMap<String,String>(ctx));
	m->put(THREAD_ID, Long::toString(this->threadId, ctx), ctx);
	m->put(STACK_ID, Long::toString(this->stackId, ctx), ctx);
	return m;
}
void StepReturnRequest::importParams(Map<String,String>* params, ThreadContext* ctx) throw() 
{
	String* strThreadId = params->get(THREAD_ID, ctx);
	if(strThreadId != nullptr)
	{
		this->threadId = Long::parseLong(strThreadId, ctx);
	}
	String* strStackId = params->get(STACK_ID, ctx);
	if(strStackId != nullptr)
	{
		this->stackId = Long::parseLong(strStackId, ctx);
	}
}
long long StepReturnRequest::getThreadId(ThreadContext* ctx) throw() 
{
	return threadId;
}
void StepReturnRequest::setThreadId(long long threadId, ThreadContext* ctx) throw() 
{
	this->threadId = threadId;
}
long long StepReturnRequest::getStackId(ThreadContext* ctx) throw() 
{
	return stackId;
}
void StepReturnRequest::setStackId(long long stackId, ThreadContext* ctx) throw() 
{
	this->stackId = stackId;
}
}}}}}

