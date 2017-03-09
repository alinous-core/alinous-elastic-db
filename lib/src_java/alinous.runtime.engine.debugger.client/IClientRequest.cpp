#include "include/global.h"


#include "alinous.runtime.engine.debugger/AlinousScriptDebugger.h"
#include "alinous.runtime.engine.debugger/AlinousServerDebugHttpResponse.h"
#include "alinous.runtime.engine.debugger.client/IClientRequest.h"

namespace alinous {namespace runtime {namespace engine {namespace debugger {namespace client {




String* IClientRequest::CMD_TERMINATE = ConstStr::getCNST_STR_1288();
String* IClientRequest::CMD_STATUS_THREAD = ConstStr::getCNST_STR_1289();
String* IClientRequest::CMD_CLEAR_BREAKPOINTS = ConstStr::getCNST_STR_1290();
String* IClientRequest::CMD_SETUP_ALL_BREAKPOINTS = ConstStr::getCNST_STR_1291();
String* IClientRequest::CMD_ADD_BREAKPOINTS = ConstStr::getCNST_STR_1292();
String* IClientRequest::CMD_RESUME = ConstStr::getCNST_STR_1293();
String* IClientRequest::CMD_STEP_OVER = ConstStr::getCNST_STR_1294();
String* IClientRequest::CMD_STEP_IN = ConstStr::getCNST_STR_1295();
String* IClientRequest::CMD_STEP_RETURN = ConstStr::getCNST_STR_1296();
bool IClientRequest::__init_done = __init_static_variables();
bool IClientRequest::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"IClientRequest", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 IClientRequest::IClientRequest(ThreadContext* ctx) throw()  : IObject(ctx)
{
}
void IClientRequest::__construct_impl(ThreadContext* ctx) throw() 
{
}
 IClientRequest::~IClientRequest() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void IClientRequest::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
}
void IClientRequest::__cleanUp(ThreadContext* ctx){
}
}}}}}

