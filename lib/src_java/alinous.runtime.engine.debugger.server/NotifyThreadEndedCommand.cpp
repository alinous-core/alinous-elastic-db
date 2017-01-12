#include "includes.h"


namespace alinous {namespace runtime {namespace engine {namespace debugger {namespace server {





String* NotifyThreadEndedCommand::CMD_STRING = ConstStr::getCNST_STR_1192();
bool NotifyThreadEndedCommand::__init_done = __init_static_variables();
bool NotifyThreadEndedCommand::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"NotifyThreadEndedCommand", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 NotifyThreadEndedCommand::NotifyThreadEndedCommand(long long threadId, ThreadContext* ctx) throw()  : IObject(ctx), AbstractAlinousServerCommand(threadId, ctx)
{
}
void NotifyThreadEndedCommand::__construct_impl(long long threadId, ThreadContext* ctx) throw() 
{
}
 NotifyThreadEndedCommand::~NotifyThreadEndedCommand() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void NotifyThreadEndedCommand::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
	AbstractAlinousServerCommand::__releaseRegerences(true, ctx);
}
void NotifyThreadEndedCommand::writeCommand(Writer* writer, ThreadContext* ctx)
{
	writer->write(CMD_STRING, ctx);
	writer->flush(ctx);
}
String* NotifyThreadEndedCommand::getName(ThreadContext* ctx) throw() 
{
	return CMD_STRING;
}
}}}}}

