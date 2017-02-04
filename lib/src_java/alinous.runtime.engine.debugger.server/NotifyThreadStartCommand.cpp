#include "includes.h"


namespace alinous {namespace runtime {namespace engine {namespace debugger {namespace server {





String* NotifyThreadStartCommand::CMD_STRING = ConstStr::getCNST_STR_1206();
bool NotifyThreadStartCommand::__init_done = __init_static_variables();
bool NotifyThreadStartCommand::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"NotifyThreadStartCommand", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 NotifyThreadStartCommand::NotifyThreadStartCommand(long long threadId, ThreadContext* ctx) throw()  : IObject(ctx), AbstractAlinousServerCommand(threadId, ctx)
{
}
void NotifyThreadStartCommand::__construct_impl(long long threadId, ThreadContext* ctx) throw() 
{
}
 NotifyThreadStartCommand::~NotifyThreadStartCommand() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void NotifyThreadStartCommand::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
	AbstractAlinousServerCommand::__releaseRegerences(true, ctx);
}
void NotifyThreadStartCommand::sendCommand(ICommandSender* notifier, ScriptMachine* context, ThreadContext* ctx)
{
	notifier->debugOut(ConstStr::getCNST_STR_1205()->clone(ctx)->append(this, ctx), ctx);
}
void NotifyThreadStartCommand::writeCommand(Writer* writer, ThreadContext* ctx)
{
	writer->write(CMD_STRING, ctx);
	writer->flush(ctx);
}
String* NotifyThreadStartCommand::getName(ThreadContext* ctx) throw() 
{
	return CMD_STRING;
}
}}}}}

