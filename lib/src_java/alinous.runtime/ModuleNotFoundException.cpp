#include "includes.h"


namespace alinous {namespace runtime {





constexpr const long long ModuleNotFoundException::serialVersionUID;
bool ModuleNotFoundException::__init_done = __init_static_variables();
bool ModuleNotFoundException::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"ModuleNotFoundException", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 ModuleNotFoundException::~ModuleNotFoundException() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void ModuleNotFoundException::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
	AlinousException::__releaseRegerences(true, ctx);
}
}}

