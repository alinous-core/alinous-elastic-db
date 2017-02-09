#include "includes.h"


namespace alinous {namespace runtime {namespace engine {namespace debugger {namespace client {





String* ResumeRequest::THREAD_ID = ConstStr::getCNST_STR_1196();
bool ResumeRequest::__init_done = __init_static_variables();
bool ResumeRequest::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"ResumeRequest", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 ResumeRequest::ResumeRequest(long long threadId, ThreadContext* ctx) throw()  : IObject(ctx), IClientRequest(ctx), threadId(0)
{
	this->threadId = threadId;
}
void ResumeRequest::__construct_impl(long long threadId, ThreadContext* ctx) throw() 
{
	this->threadId = threadId;
}
 ResumeRequest::~ResumeRequest() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void ResumeRequest::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"ResumeRequest", L"~ResumeRequest");
	if(!prepare){
		return;
	}
}
AlinousServerDebugHttpResponse* ResumeRequest::executeRequest(AlinousScriptDebugger* debugManager, ThreadContext* ctx) throw() 
{
	DebugThread* debugThread = debugManager->getDebugThread(this->threadId, ctx);
	IDebuggerOperation* ope = (new(ctx) RunningOperation(debugThread, debugManager, ctx));
	debugManager->setOperation(debugThread->threadId, ope, ctx);
	debugManager->resume(debugThread->threadId, ctx);
	debugManager->setHotThreadId(debugThread->threadId, ctx);
	AlinousServerDebugHttpResponse* responce = (new(ctx) AlinousServerDebugHttpResponse(0, ctx));
	return responce;
}
String* ResumeRequest::getCommand(ThreadContext* ctx) throw() 
{
	return IClientRequest::CMD_RESUME;
}
Map<String,String>* ResumeRequest::getParamMap(ThreadContext* ctx) throw() 
{
	Map<String,String>* m = (new(ctx) HashMap<String,String>(ctx));
	m->put(THREAD_ID, Long::toString(this->threadId, ctx), ctx);
	return m;
}
void ResumeRequest::importParams(Map<String,String>* params, ThreadContext* ctx) throw() 
{
	String* strThreadId = params->get(THREAD_ID, ctx);
	if(strThreadId != nullptr)
	{
		this->threadId = Long::parseLong(strThreadId, ctx);
	}
}
}}}}}

