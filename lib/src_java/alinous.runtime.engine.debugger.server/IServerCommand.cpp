#include "include/global.h"


#include "alinous.runtime.engine/ScriptMachine.h"
#include "alinous.runtime.engine.debugger.server/ICommandSender.h"
#include "alinous.runtime.engine.debugger.server/IServerCommand.h"

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
 IServerCommand::IServerCommand(ThreadContext* ctx) throw()  : IObject(ctx)
{
}
void IServerCommand::__construct_impl(ThreadContext* ctx) throw() 
{
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
void IServerCommand::__cleanUp(ThreadContext* ctx){
}
}}}}}

