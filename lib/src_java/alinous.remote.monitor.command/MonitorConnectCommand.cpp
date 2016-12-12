#include "includes.h"


namespace alinous {namespace remote {namespace monitor {namespace command {





bool MonitorConnectCommand::__init_done = __init_static_variables();
bool MonitorConnectCommand::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"MonitorConnectCommand", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 MonitorConnectCommand::MonitorConnectCommand(ThreadContext* ctx) throw()  : IObject(ctx), AbstractMonitorCommand(ctx)
{
	this->type = AbstractMonitorCommand::TYPE_CONNECT;
}
void MonitorConnectCommand::__construct_impl(ThreadContext* ctx) throw() 
{
	this->type = AbstractMonitorCommand::TYPE_CONNECT;
}
 MonitorConnectCommand::~MonitorConnectCommand() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void MonitorConnectCommand::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
	AbstractMonitorCommand::__releaseRegerences(true, ctx);
}
void MonitorConnectCommand::readFromStream(InputStream* stream, ThreadContext* ctx)
{
}
void MonitorConnectCommand::writeByteStream(OutputStream* out, ThreadContext* ctx)
{
}
void MonitorConnectCommand::executeOnServer(AbstractMonitorCommand* cmd, BufferedOutputStream* outStream, ThreadContext* ctx) throw() 
{
}
}}}}

