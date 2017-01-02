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
 RemoteStorageConnectCommand::RemoteStorageConnectCommand(ThreadContext* ctx) throw()  : IObject(ctx), AbstractRemoteStorageCommand(ctx), connected(0)
{
	this->type = RemoteStorageConnectCommand::TYPE_CONNECT;
}
void RemoteStorageConnectCommand::__construct_impl(ThreadContext* ctx) throw() 
{
	this->type = RemoteStorageConnectCommand::TYPE_CONNECT;
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
void RemoteStorageConnectCommand::readFromStream(InputStream* stream, int remain, ThreadContext* ctx)
{
	IArrayObjectPrimitive<char>* src = ArrayAllocatorPrimitive<char>::allocatep(ctx, remain);
	stream->read(src, ctx);
	NetworkBinaryBuffer* buff = (new(ctx) NetworkBinaryBuffer(src, ctx));
	int res = buff->getInt(ctx);
	this->connected = (res == 1);
}
bool RemoteStorageConnectCommand::isConnected(ThreadContext* ctx) throw() 
{
	return connected;
}
void RemoteStorageConnectCommand::executeOnServer(RemoteTableStorageServer* tableStorageServer, BufferedOutputStream* outStream, ThreadContext* ctx)
{
	writeByteStream(outStream, ctx);
}
void RemoteStorageConnectCommand::writeByteStream(OutputStream* out, ThreadContext* ctx)
{
	NetworkBinaryBuffer* buff = (new(ctx) NetworkBinaryBuffer(32, ctx));
	buff->putInt(RemoteStorageConnectCommand::TYPE_CONNECT, ctx);
	if(this->connected)
	{
		buff->putInt(1, ctx);
	}
		else 
	{
		buff->putInt(0, ctx);
	}
	IArrayObjectPrimitive<char>* b = buff->toBinary(ctx);
	int pos = buff->getPutSize(ctx);
	out->write(b, 0, pos, ctx);
	out->flush(ctx);
}
}}}}

