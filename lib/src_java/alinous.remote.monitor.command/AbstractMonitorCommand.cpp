#include "includes.h"


namespace alinous {namespace remote {namespace monitor {namespace command {





constexpr const int AbstractMonitorCommand::TYPE_VOID;
constexpr const int AbstractMonitorCommand::TYPE_FINISH;
constexpr const int AbstractMonitorCommand::TYPE_CONNECT;
constexpr const int AbstractMonitorCommand::TYPE_TERMINATE;
bool AbstractMonitorCommand::__init_done = __init_static_variables();
bool AbstractMonitorCommand::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"AbstractMonitorCommand", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 AbstractMonitorCommand::~AbstractMonitorCommand() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void AbstractMonitorCommand::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"AbstractMonitorCommand", L"~AbstractMonitorCommand");
	if(!prepare){
		return;
	}
}
int AbstractMonitorCommand::getType(ThreadContext* ctx) throw() 
{
	return type;
}
void AbstractMonitorCommand::sendCommand(AlinousSocket* socket, ThreadContext* ctx)
{
	OutputStream* out = socket->getOutputStream(ctx);
	writeByteStream(out, ctx);
	out->flush(ctx);
	InputStream* stream = socket->getInputStream(ctx);
	readFromStream(stream, ctx);
}
}}}}

