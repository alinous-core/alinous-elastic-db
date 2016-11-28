#include "includes.h"


namespace alinous {namespace runtime {namespace engine {namespace debugger {namespace server {





String* NotifyStepOverFinishedCommand::CMD_STRING = ConstStr::getCNST_STR_1140();
bool NotifyStepOverFinishedCommand::__init_done = __init_static_variables();
bool NotifyStepOverFinishedCommand::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"NotifyStepOverFinishedCommand", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 NotifyStepOverFinishedCommand::NotifyStepOverFinishedCommand(long long threadId, ThreadContext* ctx) throw()  : IObject(ctx), AbstractAlinousServerCommand(threadId, ctx)
{
}
void NotifyStepOverFinishedCommand::__construct_impl(long long threadId, ThreadContext* ctx) throw() 
{
}
 NotifyStepOverFinishedCommand::~NotifyStepOverFinishedCommand() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void NotifyStepOverFinishedCommand::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
	AbstractAlinousServerCommand::__releaseRegerences(true, ctx);
}
void NotifyStepOverFinishedCommand::sendCommand(ICommandSender* notifier, ScriptMachine* context, ThreadContext* ctx)
{
	AbstractAlinousServerCommand::sendCommand(notifier, context, ctx);
}
void NotifyStepOverFinishedCommand::writeCommand(Writer* writer, ThreadContext* ctx)
{
	writer->write(CMD_STRING, ctx);
	writer->flush(ctx);
}
String* NotifyStepOverFinishedCommand::getName(ThreadContext* ctx) throw() 
{
	return CMD_STRING;
}
}}}}}

