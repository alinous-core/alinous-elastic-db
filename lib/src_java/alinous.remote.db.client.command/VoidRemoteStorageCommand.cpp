#include "include/global.h"


#include "java.io/FilterOutputStream.h"
#include "java.io/BufferedOutputStream.h"
#include "alinous.remote.db/RemoteTableStorageServer.h"
#include "alinous.remote.socket/NetworkBinaryBuffer.h"
#include "alinous.remote.db.client.command/RemoteStorageCommandReader.h"
#include "alinous.remote.db.client.command/AbstractRemoteStorageCommand.h"
#include "alinous.remote.db.client.command/VoidRemoteStorageCommand.h"

namespace alinous {namespace remote {namespace db {namespace client {namespace command {





bool VoidRemoteStorageCommand::__init_done = __init_static_variables();
bool VoidRemoteStorageCommand::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"VoidRemoteStorageCommand", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 VoidRemoteStorageCommand::VoidRemoteStorageCommand(ThreadContext* ctx) throw()  : IObject(ctx), AbstractRemoteStorageCommand(ctx)
{
	this->type = AbstractRemoteStorageCommand::TYPE_VOID;
}
void VoidRemoteStorageCommand::__construct_impl(ThreadContext* ctx) throw() 
{
	this->type = AbstractRemoteStorageCommand::TYPE_VOID;
}
 VoidRemoteStorageCommand::~VoidRemoteStorageCommand() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void VoidRemoteStorageCommand::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
	AbstractRemoteStorageCommand::__releaseRegerences(true, ctx);
}
void VoidRemoteStorageCommand::readFromStream(InputStream* stream, int remain, ThreadContext* ctx)
{
}
void VoidRemoteStorageCommand::executeOnServer(RemoteTableStorageServer* tableStorageServer, BufferedOutputStream* outStream, ThreadContext* ctx)
{
	writeByteStream(outStream, ctx);
}
void VoidRemoteStorageCommand::writeByteStream(OutputStream* out, ThreadContext* ctx)
{
	NetworkBinaryBuffer* buff = (new(ctx) NetworkBinaryBuffer(32, ctx));
	buff->putInt(AbstractRemoteStorageCommand::TYPE_VOID, ctx);
	IArrayObjectPrimitive<char>* b = buff->toBinary(ctx);
	int pos = buff->getPutSize(ctx);
	out->write(b, 0, pos, ctx);
	out->flush(ctx);
}
void VoidRemoteStorageCommand::__cleanUp(ThreadContext* ctx){
}
}}}}}

