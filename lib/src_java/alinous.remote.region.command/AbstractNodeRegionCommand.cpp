#include "includes.h"


namespace alinous {namespace remote {namespace region {namespace command {





constexpr const int AbstractNodeRegionCommand::TYPE_VOID;
constexpr const int AbstractNodeRegionCommand::TYPE_FINISH;
constexpr const int AbstractNodeRegionCommand::TYPE_CONNECT;
constexpr const int AbstractNodeRegionCommand::TYPE_TERMINATE;
constexpr const int AbstractNodeRegionCommand::TYPE_GET_SCHEMA_FROM_REGION;
bool AbstractNodeRegionCommand::__init_done = __init_static_variables();
bool AbstractNodeRegionCommand::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"AbstractNodeRegionCommand", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 AbstractNodeRegionCommand::~AbstractNodeRegionCommand() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void AbstractNodeRegionCommand::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"AbstractNodeRegionCommand", L"~AbstractNodeRegionCommand");
	if(!prepare){
		return;
	}
}
int AbstractNodeRegionCommand::getType(ThreadContext* ctx) throw() 
{
	return type;
}
AbstractNodeRegionCommand* AbstractNodeRegionCommand::sendCommand(AlinousSocket* socket, ThreadContext* ctx)
{
	OutputStream* out = socket->getOutputStream(ctx);
	writeByteStream(out, ctx);
	out->flush(ctx);
	InputStream* stream = socket->getInputStream(ctx);
	AbstractNodeRegionCommand* cmd = NodeRegionCommandReader::readFromStream(stream, ctx);
	return cmd;
}
}}}}

