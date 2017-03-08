#include "include/global.h"


#include "alinous.runtime.engine/ScriptMachine.h"
#include "alinous.runtime.engine.debugger.server/IServerCommand.h"
#include "alinous.runtime.engine.debugger.server/ICommandSender.h"
#include "alinous.runtime.engine.debugger.server/AbstractAlinousServerCommand.h"
#include "alinous.runtime.engine.debugger.server/NotifyTerminatedCommand.h"

namespace alinous {namespace runtime {namespace engine {namespace debugger {namespace server {





String* NotifyTerminatedCommand::CMD_STRING = ConstStr::getCNST_STR_1205();
bool NotifyTerminatedCommand::__init_done = __init_static_variables();
bool NotifyTerminatedCommand::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"NotifyTerminatedCommand", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 NotifyTerminatedCommand::NotifyTerminatedCommand(long long threadId, ThreadContext* ctx) throw()  : IObject(ctx), AbstractAlinousServerCommand(threadId, ctx)
{
}
void NotifyTerminatedCommand::__construct_impl(long long threadId, ThreadContext* ctx) throw() 
{
}
 NotifyTerminatedCommand::~NotifyTerminatedCommand() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void NotifyTerminatedCommand::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
	AbstractAlinousServerCommand::__releaseRegerences(true, ctx);
}
void NotifyTerminatedCommand::writeCommand(Writer* writer, ThreadContext* ctx)
{
	writer->write(CMD_STRING, ctx);
	writer->flush(ctx);
}
String* NotifyTerminatedCommand::getName(ThreadContext* ctx) throw() 
{
	return CMD_STRING;
}
void NotifyTerminatedCommand::__cleanUp(ThreadContext* ctx){
}
}}}}}

