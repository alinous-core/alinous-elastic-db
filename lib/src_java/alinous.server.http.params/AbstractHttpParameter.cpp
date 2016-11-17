#include "includes.h"


namespace alinous {namespace server {namespace http {namespace params {





constexpr const int AbstractHttpParameter::TYPE_NORMAL_PARAM;
constexpr const int AbstractHttpParameter::TYPE_ARRAY_PARAM;
constexpr const int AbstractHttpParameter::TYPE_FILE_PARAM;
bool AbstractHttpParameter::__init_done = __init_static_variables();
bool AbstractHttpParameter::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"AbstractHttpParameter", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 AbstractHttpParameter::~AbstractHttpParameter() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void AbstractHttpParameter::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"AbstractHttpParameter", L"~AbstractHttpParameter");
	if(!prepare){
		return;
	}
}
}}}}

