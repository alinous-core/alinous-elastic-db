#include "includes.h"


namespace alinous {namespace runtime {namespace engine {namespace debugger {namespace server {





String* NotifyHitBreakpoint::CMD_STRING = ConstStr::getCNST_STR_1199();
bool NotifyHitBreakpoint::__init_done = __init_static_variables();
bool NotifyHitBreakpoint::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"NotifyHitBreakpoint", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 NotifyHitBreakpoint::NotifyHitBreakpoint(long long threadId, ThreadContext* ctx) throw()  : IObject(ctx), AbstractAlinousServerCommand(threadId, ctx)
{
}
void NotifyHitBreakpoint::__construct_impl(long long threadId, ThreadContext* ctx) throw() 
{
}
 NotifyHitBreakpoint::~NotifyHitBreakpoint() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void NotifyHitBreakpoint::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
	AbstractAlinousServerCommand::__releaseRegerences(true, ctx);
}
void NotifyHitBreakpoint::sendCommand(ICommandSender* notifier, ScriptMachine* contxt, ThreadContext* ctx)
{
	AbstractAlinousServerCommand::sendCommand(notifier, contxt, ctx);
}
void NotifyHitBreakpoint::writeCommand(Writer* writer, ThreadContext* ctx)
{
	writer->write(CMD_STRING, ctx);
	writer->flush(ctx);
}
String* NotifyHitBreakpoint::getName(ThreadContext* ctx) throw() 
{
	return CMD_STRING;
}
}}}}}

