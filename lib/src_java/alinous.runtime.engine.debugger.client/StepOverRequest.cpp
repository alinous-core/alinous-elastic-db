#include "includes.h"


namespace alinous {namespace runtime {namespace engine {namespace debugger {namespace client {





String* StepOverRequest::THREAD_ID = ConstStr::getCNST_STR_1186();
String* StepOverRequest::STACK_ID = ConstStr::getCNST_STR_1187();
bool StepOverRequest::__init_done = __init_static_variables();
bool StepOverRequest::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"StepOverRequest", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 StepOverRequest::~StepOverRequest() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void StepOverRequest::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"StepOverRequest", L"~StepOverRequest");
	if(!prepare){
		return;
	}
}
AlinousServerDebugHttpResponse* StepOverRequest::executeRequest(AlinousScriptDebugger* debugManager, ThreadContext* ctx) throw() 
{
	System::out->println(ConstStr::getCNST_STR_1190(), ctx);
	DebugThread* debugThread = debugManager->getDebugThread(this->threadId, ctx);
	debugManager->setOperation(this->threadId, (new(ctx) StepOverOperation(debugThread, debugManager, this->stackId, ctx)), ctx);
	debugManager->resume(this->threadId, ctx);
	AlinousServerDebugHttpResponse* responce = (new(ctx) AlinousServerDebugHttpResponse(0, ctx));
	return responce;
}
String* StepOverRequest::getCommand(ThreadContext* ctx) throw() 
{
	return IClientRequest::CMD_STEP_OVER;
}
Map<String,String>* StepOverRequest::getParamMap(ThreadContext* ctx) throw() 
{
	Map<String,String>* m = (new(ctx) HashMap<String,String>(ctx));
	m->put(THREAD_ID, Long::toString(this->threadId, ctx), ctx);
	m->put(STACK_ID, Long::toString(this->stackId, ctx), ctx);
	return m;
}
void StepOverRequest::importParams(Map<String,String>* params, ThreadContext* ctx) throw() 
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
long long StepOverRequest::getThreadId(ThreadContext* ctx) throw() 
{
	return threadId;
}
void StepOverRequest::setThreadId(long long threadId, ThreadContext* ctx) throw() 
{
	this->threadId = threadId;
}
long long StepOverRequest::getStackId(ThreadContext* ctx) throw() 
{
	return stackId;
}
void StepOverRequest::setStackId(long long stackId, ThreadContext* ctx) throw() 
{
	this->stackId = stackId;
}
}}}}}

