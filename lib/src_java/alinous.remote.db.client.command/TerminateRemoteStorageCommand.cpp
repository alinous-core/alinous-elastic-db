#include "include/global.h"


#include "java.io/FilterOutputStream.h"
#include "java.io/BufferedOutputStream.h"
#include "alinous.remote.socket/NetworkBinaryBuffer.h"
#include "alinous.remote.socket/ICommandData.h"
#include "alinous.remote.db.client.command.data/SchemasStructureInfoData.h"
#include "alinous.remote.db/RemoteTableStorageServer.h"
#include "alinous.remote.db.client.command/AbstractRemoteStorageCommand.h"
#include "alinous.remote.db.client.command/GetTableSchemeCommand.h"
#include "alinous.remote.monitor/TransactionMonitorServer.h"
#include "alinous.remote.monitor.client.command/AbstractMonitorCommand.h"
#include "alinous.remote.db.client.command/TerminateRemoteStorageCommand.h"
#include "alinous.remote.db.client.command/FinishRemoteStorageConnectionCommand.h"
#include "alinous.remote.db.client.command/VoidRemoteStorageCommand.h"
#include "alinous.remote.db.client.command/RemoteStorageConnectCommand.h"
#include "alinous.remote.db.client.command/RemoteStorageCommandReader.h"

namespace alinous {namespace remote {namespace db {namespace client {namespace command {





bool TerminateRemoteStorageCommand::__init_done = __init_static_variables();
bool TerminateRemoteStorageCommand::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"TerminateRemoteStorageCommand", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 TerminateRemoteStorageCommand::TerminateRemoteStorageCommand(ThreadContext* ctx) throw()  : IObject(ctx), AbstractRemoteStorageCommand(ctx)
{
	this->type = AbstractMonitorCommand::TYPE_TERMINATE;
}
void TerminateRemoteStorageCommand::__construct_impl(ThreadContext* ctx) throw() 
{
	this->type = AbstractMonitorCommand::TYPE_TERMINATE;
}
 TerminateRemoteStorageCommand::~TerminateRemoteStorageCommand() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void TerminateRemoteStorageCommand::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
	AbstractRemoteStorageCommand::__releaseRegerences(true, ctx);
}
void TerminateRemoteStorageCommand::readFromStream(InputStream* stream, int remain, ThreadContext* ctx)
{
}
void TerminateRemoteStorageCommand::executeOnServer(RemoteTableStorageServer* tableStorageServer, BufferedOutputStream* outStream, ThreadContext* ctx)
{
	writeByteStream(outStream, ctx);
}
void TerminateRemoteStorageCommand::writeByteStream(OutputStream* out, ThreadContext* ctx)
{
	NetworkBinaryBuffer* buff = (new(ctx) NetworkBinaryBuffer(32, ctx));
	buff->putInt(RemoteStorageConnectCommand::TYPE_TERMINATE, ctx);
	IArrayObjectPrimitive<char>* b = buff->toBinary(ctx);
	int pos = buff->getPutSize(ctx);
	out->write(b, 0, pos, ctx);
	out->flush(ctx);
}
void TerminateRemoteStorageCommand::__cleanUp(ThreadContext* ctx){
}
}}}}}

