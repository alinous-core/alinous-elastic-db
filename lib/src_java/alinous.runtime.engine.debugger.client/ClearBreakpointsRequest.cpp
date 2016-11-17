#include "includes.h"


namespace alinous {namespace runtime {namespace engine {namespace debugger {namespace client {





bool ClearBreakpointsRequest::__init_done = __init_static_variables();
bool ClearBreakpointsRequest::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"ClearBreakpointsRequest", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 ClearBreakpointsRequest::~ClearBreakpointsRequest() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void ClearBreakpointsRequest::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
}
AlinousServerDebugHttpResponse* ClearBreakpointsRequest::executeRequest(AlinousScriptDebugger* debugManager, ThreadContext* ctx) throw() 
{
	AlinousServerDebugHttpResponse* res = (new(ctx) AlinousServerDebugHttpResponse(0, ctx));
	debugManager->clearBreakpoints(ctx);
	return res;
}
String* ClearBreakpointsRequest::getCommand(ThreadContext* ctx) throw() 
{
	return (new(ctx) String(IClientRequest::CMD_CLEAR_BREAKPOINTS, ctx));
}
Map<String,String>* ClearBreakpointsRequest::getParamMap(ThreadContext* ctx) throw() 
{
	Map<String,String>* m = (new(ctx) HashMap<String,String>(ctx));
	return m;
}
void ClearBreakpointsRequest::importParams(Map<String,String>* params, ThreadContext* ctx) throw() 
{
}
}}}}}

