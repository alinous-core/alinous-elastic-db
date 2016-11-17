#include "includes.h"


namespace alinous {namespace runtime {namespace engine {namespace debugger {namespace server {




bool ICommandSender::__init_done = __init_static_variables();
bool ICommandSender::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"ICommandSender", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 ICommandSender::~ICommandSender() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void ICommandSender::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
}
}}}}}

