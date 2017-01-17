#include "includes.h"


namespace alinous {namespace runtime {namespace engine {namespace debugger {namespace client {




String* IClientRequest::CMD_TERMINATE = ConstStr::getCNST_STR_1180();
String* IClientRequest::CMD_STATUS_THREAD = ConstStr::getCNST_STR_1181();
String* IClientRequest::CMD_CLEAR_BREAKPOINTS = ConstStr::getCNST_STR_1182();
String* IClientRequest::CMD_SETUP_ALL_BREAKPOINTS = ConstStr::getCNST_STR_1183();
String* IClientRequest::CMD_ADD_BREAKPOINTS = ConstStr::getCNST_STR_1184();
String* IClientRequest::CMD_RESUME = ConstStr::getCNST_STR_1185();
String* IClientRequest::CMD_STEP_OVER = ConstStr::getCNST_STR_1186();
String* IClientRequest::CMD_STEP_IN = ConstStr::getCNST_STR_1187();
String* IClientRequest::CMD_STEP_RETURN = ConstStr::getCNST_STR_1188();
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
}}}}}

