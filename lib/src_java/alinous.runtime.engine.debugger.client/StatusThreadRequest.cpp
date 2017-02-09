#include "includes.h"


namespace alinous {namespace runtime {namespace engine {namespace debugger {namespace client {





String* StatusThreadRequest::THREAD_ID = ConstStr::getCNST_STR_1196();
bool StatusThreadRequest::__init_done = __init_static_variables();
bool StatusThreadRequest::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"StatusThreadRequest", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 StatusThreadRequest::StatusThreadRequest(ThreadContext* ctx) throw()  : IObject(ctx), IClientRequest(ctx), threadId(0)
{
	this->threadId = -1;
}
void StatusThreadRequest::__construct_impl(ThreadContext* ctx) throw() 
{
	this->threadId = -1;
}
 StatusThreadRequest::~StatusThreadRequest() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void StatusThreadRequest::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"StatusThreadRequest", L"~StatusThreadRequest");
	if(!prepare){
		return;
	}
}
String* StatusThreadRequest::getCommand(ThreadContext* ctx) throw() 
{
	return (new(ctx) String(IClientRequest::CMD_STATUS_THREAD, ctx));
}
Map<String,String>* StatusThreadRequest::getParamMap(ThreadContext* ctx) throw() 
{
	Map<String,String>* m = (new(ctx) HashMap<String,String>(ctx));
	m->put(THREAD_ID, Long::toString(this->threadId, ctx), ctx);
	return m;
}
void StatusThreadRequest::importParams(Map<String,String>* params, ThreadContext* ctx) throw() 
{
	String* strThreadId = params->get(THREAD_ID, ctx);
	if(strThreadId != nullptr)
	{
		this->threadId = Long::parseLong(strThreadId, ctx);
	}
		else 
	{
		this->threadId = -1;
	}
}
AlinousServerDebugHttpResponse* StatusThreadRequest::executeRequest(AlinousScriptDebugger* debugManager, ThreadContext* ctx) throw() 
{
	AlinousServerDebugHttpResponse* responce = nullptr;
	responce = exportAllThreads(debugManager, ctx);
	long long hotThreadId = debugManager->getHotThreadId(ctx);
	if(hotThreadId < (long long)0)
	{
		hotThreadId = debugManager->getHotThreadId(ctx);
		responce->setHotThread(hotThreadId, ctx);
	}
	return responce;
}
AlinousServerDebugHttpResponse* StatusThreadRequest::exportAllThreads(AlinousScriptDebugger* debugManager, ThreadContext* ctx) throw() 
{
	AlinousServerDebugHttpResponse* responce = (new(ctx) AlinousServerDebugHttpResponse(0, ctx));
	IArrayObject<DebugThread>* threads = debugManager->getThreads(ctx);
	for(int i = 0; i < threads->length; i ++ )
	{
		responce->addThread(threads->get(i), ctx);
	}
	return responce;
}
}}}}}

