#include "includes.h"


namespace alinous {namespace runtime {namespace engine {namespace debugger {namespace server {





String* NotifyResumeComand::CMD_STRING = ConstStr::getCNST_STR_1194();
bool NotifyResumeComand::__init_done = __init_static_variables();
bool NotifyResumeComand::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"NotifyResumeComand", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 NotifyResumeComand::NotifyResumeComand(long long threadId, ThreadContext* ctx) throw()  : IObject(ctx), AbstractAlinousServerCommand(threadId, ctx)
{
}
void NotifyResumeComand::__construct_impl(long long threadId, ThreadContext* ctx) throw() 
{
}
 NotifyResumeComand::~NotifyResumeComand() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void NotifyResumeComand::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
	AbstractAlinousServerCommand::__releaseRegerences(true, ctx);
}
void NotifyResumeComand::writeCommand(Writer* writer, ThreadContext* ctx)
{
	writer->write(CMD_STRING, ctx);
	writer->flush(ctx);
}
String* NotifyResumeComand::getName(ThreadContext* ctx) throw() 
{
	return CMD_STRING;
}
}}}}}

