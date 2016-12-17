#include "includes.h"


namespace alinous {namespace remote {namespace region {namespace command {





bool NodeRegionConnectCommand::__init_done = __init_static_variables();
bool NodeRegionConnectCommand::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"NodeRegionConnectCommand", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 NodeRegionConnectCommand::NodeRegionConnectCommand(ThreadContext* ctx) throw()  : IObject(ctx), AbstractNodeRegionCommand(ctx), connected(0), size(0)
{
	this->type = NodeRegionConnectCommand::TYPE_CONNECT;
	this->size = 4;
}
void NodeRegionConnectCommand::__construct_impl(ThreadContext* ctx) throw() 
{
	this->type = NodeRegionConnectCommand::TYPE_CONNECT;
	this->size = 4;
}
 NodeRegionConnectCommand::~NodeRegionConnectCommand() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void NodeRegionConnectCommand::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"NodeRegionConnectCommand", L"~NodeRegionConnectCommand");
	if(!prepare){
		return;
	}
	AbstractNodeRegionCommand::__releaseRegerences(true, ctx);
}
void NodeRegionConnectCommand::readFromStream(InputStream* stream, ThreadContext* ctx)
{
	int res = NetworkBinalyUtils::readInt(stream, ctx);
	this->connected = (res == 1);
}
void NodeRegionConnectCommand::executeOnServer(TransactionMonitorServer* monitorServer, BufferedOutputStream* outStream, ThreadContext* ctx)
{
	this->connected = true;
	writeByteStream(outStream, ctx);
}
bool NodeRegionConnectCommand::isConnected(ThreadContext* ctx) throw() 
{
	return connected;
}
void NodeRegionConnectCommand::writeByteStream(OutputStream* out, ThreadContext* ctx)
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

