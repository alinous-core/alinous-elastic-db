#include "include/global.h"


#include "java.io/FilterOutputStream.h"
#include "java.io/BufferedOutputStream.h"
#include "alinous.remote.monitor/TransactionMonitorServer.h"
#include "alinous.remote.socket/NetworkBinaryBuffer.h"
#include "alinous.remote.monitor.client.command/MinitorCommandReader.h"
#include "alinous.remote.monitor.client.command/AbstractMonitorCommand.h"
#include "alinous.remote.monitor.client.command.commitId/GetMaxCommitIdCommand.h"

namespace alinous {namespace remote {namespace monitor {namespace client {namespace command {namespace commitId {





bool GetMaxCommitIdCommand::__init_done = __init_static_variables();
bool GetMaxCommitIdCommand::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"GetMaxCommitIdCommand", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 GetMaxCommitIdCommand::GetMaxCommitIdCommand(ThreadContext* ctx) throw()  : IObject(ctx), AbstractMonitorCommand(ctx), commitId(0)
{
	this->type = AbstractMonitorCommand::TYPE_GET_MAX_COMMIT_ID;
}
void GetMaxCommitIdCommand::__construct_impl(ThreadContext* ctx) throw() 
{
	this->type = AbstractMonitorCommand::TYPE_GET_MAX_COMMIT_ID;
}
 GetMaxCommitIdCommand::~GetMaxCommitIdCommand() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void GetMaxCommitIdCommand::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"GetMaxCommitIdCommand", L"~GetMaxCommitIdCommand");
	if(!prepare){
		return;
	}
	AbstractMonitorCommand::__releaseRegerences(true, ctx);
}
void GetMaxCommitIdCommand::executeOnServer(TransactionMonitorServer* monitorServer, BufferedOutputStream* outStream, ThreadContext* ctx)
{
	this->commitId = monitorServer->getCommitId(ctx);
	writeByteStream(outStream, ctx);
}
void GetMaxCommitIdCommand::writeByteStream(OutputStream* out, ThreadContext* ctx)
{
	NetworkBinaryBuffer* buff = (new(ctx) NetworkBinaryBuffer(32, ctx));
	buff->putInt(AbstractMonitorCommand::TYPE_GET_MAX_COMMIT_ID, ctx);
	buff->putLong(this->commitId, ctx);
	IArrayObjectPrimitive<char>* b = buff->toBinary(ctx);
	int pos = buff->getPutSize(ctx);
	out->write(b, 0, pos, ctx);
	out->flush(ctx);
}
void GetMaxCommitIdCommand::readFromStream(InputStream* stream, int remain, ThreadContext* ctx)
{
	IArrayObjectPrimitive<char>* src = ArrayAllocatorPrimitive<char>::allocatep(ctx, remain);
	stream->read(src, ctx);
	NetworkBinaryBuffer* buff = (new(ctx) NetworkBinaryBuffer(src, ctx));
	this->commitId = buff->getLong(ctx);
}
long long GetMaxCommitIdCommand::getCommitId(ThreadContext* ctx) throw() 
{
	return commitId;
}
void GetMaxCommitIdCommand::__cleanUp(ThreadContext* ctx){
}
}}}}}}

