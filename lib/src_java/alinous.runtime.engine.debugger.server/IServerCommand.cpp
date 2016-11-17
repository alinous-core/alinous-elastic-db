#include "includes.h"


namespace alinous {namespace runtime {namespace engine {namespace debugger {namespace server {




bool IServerCommand::__init_done = __init_static_variables();
bool IServerCommand::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"IServerCommand", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 IServerCommand::~IServerCommand() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void IServerCommand::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
}
}}}}}

