#include "includes.h"


namespace alinous {namespace runtime {namespace engine {namespace debugger {namespace client {





String* StepInRequest::THREAD_ID = ConstStr::getCNST_STR_1186();
String* StepInRequest::STACK_ID = ConstStr::getCNST_STR_1187();
bool StepInRequest::__init_done = __init_static_variables();
bool StepInRequest::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"StepInRequest", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 StepInRequest::~StepInRequest() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void StepInRequest::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"StepInRequest", L"~StepInRequest");
	if(!prepare){
		return;
	}
}
AlinousServerDebugHttpResponse* StepInRequest::executeRequest(AlinousScriptDebugger* debugManager, ThreadContext* ctx) throw() 
{
	DebugThread* debugThread = debugManager->getDebugThread(this->threadId, ctx);
	StepInOperation* ope = (new(ctx) StepInOperation(debugThread, debugManager, ctx));
	debugManager->setOperation(this->threadId, ope, ctx);
	debugManager->resume(this->threadId, ctx);
	AlinousServerDebugHttpResponse* responce = (new(ctx) AlinousServerDebugHttpResponse(0, ctx));
	return responce;
}
String* StepInRequest::getCommand(ThreadContext* ctx) throw() 
{
	return IClientRequest::CMD_STEP_IN;
}
Map<String,String>* StepInRequest::getParamMap(ThreadContext* ctx) throw() 
{
	Map<String,String>* m = (new(ctx) HashMap<String,String>(ctx));
	m->put(THREAD_ID, Long::toString(this->threadId, ctx), ctx);
	m->put(STACK_ID, Long::toString(this->stackId, ctx), ctx);
	return m;
}
void StepInRequest::importParams(Map<String,String>* params, ThreadContext* ctx) throw() 
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
long long StepInRequest::getStackId(ThreadContext* ctx) throw() 
{
	return stackId;
}
void StepInRequest::setStackId(long long stackId, ThreadContext* ctx) throw() 
{
	this->stackId = stackId;
}
long long StepInRequest::getThreadId(ThreadContext* ctx) throw() 
{
	return threadId;
}
void StepInRequest::setThreadId(long long threadId, ThreadContext* ctx) throw() 
{
	this->threadId = threadId;
}
}}}}}

