#include "include/global.h"


#include "alinous.runtime.engine.debugger/AlinousScriptDebugger.h"
#include "alinous.runtime.engine.debugger/AlinousServerDebugHttpResponse.h"
#include "alinous.runtime.engine.debugger.client/IClientRequest.h"
#include "alinous.runtime.engine.debugger.client/TerminateServerRequest.h"

namespace alinous {namespace runtime {namespace engine {namespace debugger {namespace client {





bool TerminateServerRequest::__init_done = __init_static_variables();
bool TerminateServerRequest::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"TerminateServerRequest", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 TerminateServerRequest::TerminateServerRequest(ThreadContext* ctx) throw()  : IObject(ctx), IClientRequest(ctx)
{
}
void TerminateServerRequest::__construct_impl(ThreadContext* ctx) throw() 
{
}
 TerminateServerRequest::~TerminateServerRequest() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void TerminateServerRequest::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
}
String* TerminateServerRequest::getCommand(ThreadContext* ctx) throw() 
{
	return IClientRequest::CMD_TERMINATE;
}
Map<String,String>* TerminateServerRequest::getParamMap(ThreadContext* ctx) throw() 
{
	Map<String,String>* m = (new(ctx) HashMap<String,String>(ctx));
	return m;
}
void TerminateServerRequest::importParams(Map<String,String>* params, ThreadContext* ctx) throw() 
{
}
AlinousServerDebugHttpResponse* TerminateServerRequest::executeRequest(AlinousScriptDebugger* debugManager, ThreadContext* ctx) throw() 
{
	AlinousServerDebugHttpResponse* responce = (new(ctx) AlinousServerDebugHttpResponse(0, ctx));
	responce->setShutdown(true, ctx);
	return responce;
}
void TerminateServerRequest::__cleanUp(ThreadContext* ctx){
}
}}}}}

