#include "include/global.h"


#include "alinous.runtime.engine.debugger.server/ServerBreakPoint.h"
#include "alinous.runtime.engine.debugger/AlinousScriptDebugger.h"
#include "alinous.runtime.engine.debugger/AlinousServerDebugHttpResponse.h"
#include "alinous.runtime.engine.debugger.client/IClientRequest.h"
#include "alinous.runtime.engine.debugger.client/SetupAllBreakPointsRequest.h"
#include "alinous.runtime.engine.debugger.client/TerminateServerRequest.h"
#include "alinous.runtime.engine.debugger.client/StatusThreadRequest.h"
#include "alinous.runtime.engine.debugger.client/ClearBreakpointsRequest.h"
#include "alinous.runtime.engine.debugger.client/AddBreakpointsRequest.h"
#include "alinous.runtime.engine.debugger.client/ResumeRequest.h"
#include "alinous.runtime.engine.debugger.client/StepOverRequest.h"
#include "alinous.runtime.engine.debugger.client/StepInRequest.h"
#include "alinous.runtime.engine.debugger.client/StepReturnRequest.h"
#include "alinous.runtime.engine.debugger.client/ClientRequestFactory.h"

namespace alinous {namespace runtime {namespace engine {namespace debugger {namespace client {




String* IClientRequest::CMD_TERMINATE = ConstStr::getCNST_STR_1189();
String* IClientRequest::CMD_STATUS_THREAD = ConstStr::getCNST_STR_1190();
String* IClientRequest::CMD_CLEAR_BREAKPOINTS = ConstStr::getCNST_STR_1191();
String* IClientRequest::CMD_SETUP_ALL_BREAKPOINTS = ConstStr::getCNST_STR_1192();
String* IClientRequest::CMD_ADD_BREAKPOINTS = ConstStr::getCNST_STR_1193();
String* IClientRequest::CMD_RESUME = ConstStr::getCNST_STR_1194();
String* IClientRequest::CMD_STEP_OVER = ConstStr::getCNST_STR_1195();
String* IClientRequest::CMD_STEP_IN = ConstStr::getCNST_STR_1196();
String* IClientRequest::CMD_STEP_RETURN = ConstStr::getCNST_STR_1197();
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

