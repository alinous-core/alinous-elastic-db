#include "includes.h"


namespace alinous {namespace runtime {namespace engine {namespace debugger {namespace server {





String* NotifyExceptionThrownCommand::CMD_STRING = ConstStr::getCNST_STR_1196();
bool NotifyExceptionThrownCommand::__init_done = __init_static_variables();
bool NotifyExceptionThrownCommand::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"NotifyExceptionThrownCommand", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 NotifyExceptionThrownCommand::NotifyExceptionThrownCommand(Throwable* e, long long threadId, ThreadContext* ctx) throw()  : IObject(ctx), AbstractAlinousServerCommand(threadId, ctx)
{
	e->printStackTrace(ctx);
}
void NotifyExceptionThrownCommand::__construct_impl(Throwable* e, long long threadId, ThreadContext* ctx) throw() 
{
	e->printStackTrace(ctx);
}
 NotifyExceptionThrownCommand::~NotifyExceptionThrownCommand() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void NotifyExceptionThrownCommand::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
	AbstractAlinousServerCommand::__releaseRegerences(true, ctx);
}
void NotifyExceptionThrownCommand::writeCommand(Writer* writer, ThreadContext* ctx)
{
	writer->write(CMD_STRING, ctx);
	writer->flush(ctx);
}
String* NotifyExceptionThrownCommand::getName(ThreadContext* ctx) throw() 
{
	return CMD_STRING;
}
}}}}}

