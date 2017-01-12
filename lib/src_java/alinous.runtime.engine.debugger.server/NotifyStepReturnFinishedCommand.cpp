#include "includes.h"


namespace alinous {namespace runtime {namespace engine {namespace debugger {namespace server {





String* NotifyStepReturnFinishedCommand::CMD_STRING = ConstStr::getCNST_STR_1201();
bool NotifyStepReturnFinishedCommand::__init_done = __init_static_variables();
bool NotifyStepReturnFinishedCommand::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"NotifyStepReturnFinishedCommand", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 NotifyStepReturnFinishedCommand::NotifyStepReturnFinishedCommand(long long threadId, ThreadContext* ctx) throw()  : IObject(ctx), AbstractAlinousServerCommand(threadId, ctx)
{
}
void NotifyStepReturnFinishedCommand::__construct_impl(long long threadId, ThreadContext* ctx) throw() 
{
}
 NotifyStepReturnFinishedCommand::~NotifyStepReturnFinishedCommand() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void NotifyStepReturnFinishedCommand::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
	AbstractAlinousServerCommand::__releaseRegerences(true, ctx);
}
void NotifyStepReturnFinishedCommand::sendCommand(ICommandSender* notifier, ScriptMachine* context, ThreadContext* ctx)
{
	AbstractAlinousServerCommand::sendCommand(notifier, context, ctx);
}
void NotifyStepReturnFinishedCommand::writeCommand(Writer* writer, ThreadContext* ctx)
{
	writer->write(CMD_STRING, ctx);
	writer->flush(ctx);
}
String* NotifyStepReturnFinishedCommand::getName(ThreadContext* ctx) throw() 
{
	return CMD_STRING;
}
}}}}}

