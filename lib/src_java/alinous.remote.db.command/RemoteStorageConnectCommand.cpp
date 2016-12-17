#include "includes.h"


namespace alinous {namespace remote {namespace db {namespace command {





bool RemoteStorageConnectCommand::__init_done = __init_static_variables();
bool RemoteStorageConnectCommand::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"RemoteStorageConnectCommand", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 RemoteStorageConnectCommand::RemoteStorageConnectCommand(ThreadContext* ctx) throw()  : IObject(ctx), AbstractRemoteStorageCommand(ctx), connected(0), size(0)
{
	this->type = RemoteStorageConnectCommand::TYPE_CONNECT;
	this->size = 4;
}
void RemoteStorageConnectCommand::__construct_impl(ThreadContext* ctx) throw() 
{
	this->type = RemoteStorageConnectCommand::TYPE_CONNECT;
	this->size = 4;
}
 RemoteStorageConnectCommand::~RemoteStorageConnectCommand() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void RemoteStorageConnectCommand::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"RemoteStorageConnectCommand", L"~RemoteStorageConnectCommand");
	if(!prepare){
		return;
	}
	AbstractRemoteStorageCommand::__releaseRegerences(true, ctx);
}
void RemoteStorageConnectCommand::readFromStream(InputStream* stream, ThreadContext* ctx)
{
	int res = NetworkBinalyUtils::readInt(stream, ctx);
	this->connected = (res == 1);
}
bool RemoteStorageConnectCommand::isConnected(ThreadContext* ctx) throw() 
{
	return connected;
}
void RemoteStorageConnectCommand::executeOnServer(RemoteTableStorageServer* tableStorageServer, BufferedOutputStream* outStream, ThreadContext* ctx)
{
}
void RemoteStorageConnectCommand::writeByteStream(OutputStream* out, ThreadContext* ctx)
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

