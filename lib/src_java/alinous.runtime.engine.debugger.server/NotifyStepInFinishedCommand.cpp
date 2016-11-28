#include "includes.h"


namespace alinous {namespace runtime {namespace engine {namespace debugger {namespace server {





String* NotifyStepInFinishedCommand::CMD_STRING = ConstStr::getCNST_STR_1146();
bool NotifyStepInFinishedCommand::__init_done = __init_static_variables();
bool NotifyStepInFinishedCommand::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"NotifyStepInFinishedCommand", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 NotifyStepInFinishedCommand::NotifyStepInFinishedCommand(long long threadId, ThreadContext* ctx) throw()  : IObject(ctx), AbstractAlinousServerCommand(threadId, ctx)
{
}
void NotifyStepInFinishedCommand::__construct_impl(long long threadId, ThreadContext* ctx) throw() 
{
}
 NotifyStepInFinishedCommand::~NotifyStepInFinishedCommand() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void NotifyStepInFinishedCommand::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
	AbstractAlinousServerCommand::__releaseRegerences(true, ctx);
}
void NotifyStepInFinishedCommand::sendCommand(ICommandSender* notifier, ScriptMachine* context, ThreadContext* ctx)
{
	AbstractAlinousServerCommand::sendCommand(notifier, context, ctx);
}
void NotifyStepInFinishedCommand::writeCommand(Writer* writer, ThreadContext* ctx)
{
	writer->write(CMD_STRING, ctx);
	writer->flush(ctx);
}
String* NotifyStepInFinishedCommand::getName(ThreadContext* ctx) throw() 
{
	return CMD_STRING;
}
}}}}}

