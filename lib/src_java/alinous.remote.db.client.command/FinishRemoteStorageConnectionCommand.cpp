#include "include/global.h"


#include "java.io/FilterOutputStream.h"
#include "java.io/BufferedOutputStream.h"
#include "alinous.remote.db/RemoteTableStorageServer.h"
#include "alinous.remote.socket/NetworkBinaryBuffer.h"
#include "alinous.remote.db.client.command/RemoteStorageCommandReader.h"
#include "alinous.remote.db.client.command/AbstractRemoteStorageCommand.h"
#include "alinous.remote.db.client.command/FinishRemoteStorageConnectionCommand.h"

namespace alinous {namespace remote {namespace db {namespace client {namespace command {





bool FinishRemoteStorageConnectionCommand::__init_done = __init_static_variables();
bool FinishRemoteStorageConnectionCommand::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"FinishRemoteStorageConnectionCommand", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 FinishRemoteStorageConnectionCommand::FinishRemoteStorageConnectionCommand(ThreadContext* ctx) throw()  : IObject(ctx), AbstractRemoteStorageCommand(ctx)
{
	this->type = AbstractRemoteStorageCommand::TYPE_FINISH;
}
void FinishRemoteStorageConnectionCommand::__construct_impl(ThreadContext* ctx) throw() 
{
	this->type = AbstractRemoteStorageCommand::TYPE_FINISH;
}
 FinishRemoteStorageConnectionCommand::~FinishRemoteStorageConnectionCommand() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void FinishRemoteStorageConnectionCommand::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
	AbstractRemoteStorageCommand::__releaseRegerences(true, ctx);
}
void FinishRemoteStorageConnectionCommand::readFromStream(InputStream* stream, int remain, ThreadContext* ctx)
{
}
void FinishRemoteStorageConnectionCommand::executeOnServer(RemoteTableStorageServer* tableStorageServer, BufferedOutputStream* outStream, ThreadContext* ctx)
{
	writeByteStream(outStream, ctx);
}
void FinishRemoteStorageConnectionCommand::writeByteStream(OutputStream* out, ThreadContext* ctx)
{
	NetworkBinaryBuffer* buff = (new(ctx) NetworkBinaryBuffer(32, ctx));
	buff->putInt(AbstractRemoteStorageCommand::TYPE_FINISH, ctx);
	IArrayObjectPrimitive<char>* b = buff->toBinary(ctx);
	int pos = buff->getPutSize(ctx);
	out->write(b, 0, pos, ctx);
	out->flush(ctx);
}
void FinishRemoteStorageConnectionCommand::__cleanUp(ThreadContext* ctx){
}
}}}}}

