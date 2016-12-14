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
 MonitorConnectCommand::MonitorConnectCommand(ThreadContext* ctx) throw()  : IObject(ctx), AbstractMonitorCommand(ctx), connected(0), size(0)
{
	this->type = AbstractMonitorCommand::TYPE_CONNECT;
	this->size = 4;
}
void MonitorConnectCommand::__construct_impl(ThreadContext* ctx) throw() 
{
	this->type = AbstractMonitorCommand::TYPE_CONNECT;
	this->size = 4;
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
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"MonitorConnectCommand", L"~MonitorConnectCommand");
	if(!prepare){
		return;
	}
	AbstractMonitorCommand::__releaseRegerences(true, ctx);
}
void MonitorConnectCommand::readFromStream(InputStream* stream, ThreadContext* ctx)
{
	int res = NetworkBinalyUtils::readInt(stream, ctx);
	this->connected = (res == 1);
}
void MonitorConnectCommand::executeOnServer(TransactionMonitorServer* monitorServer, BufferedOutputStream* outStream, ThreadContext* ctx)
{
	this->connected = true;
	writeByteStream(outStream, ctx);
}
bool MonitorConnectCommand::isConnected(ThreadContext* ctx) throw() 
{
	return connected;
}
void MonitorConnectCommand::writeByteStream(OutputStream* out, ThreadContext* ctx)
{
	ByteBuffer* buffer = ByteBuffer::allocate(this->size, ctx);
	if(this->connected)
	{
		buffer->putInt(1, ctx);
	}
		else 
	{
		buffer->putInt(0, ctx);
	}
	IArrayObjectPrimitive<char>* b = buffer->array(ctx);
	out->write(b, ctx);
	out->flush(ctx);
}
}}}}

