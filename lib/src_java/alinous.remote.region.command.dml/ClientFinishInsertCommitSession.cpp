#include "includes.h"


namespace alinous {namespace remote {namespace region {namespace command {namespace dml {





bool ClientFinishInsertCommitSession::__init_done = __init_static_variables();
bool ClientFinishInsertCommitSession::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"ClientFinishInsertCommitSession", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 ClientFinishInsertCommitSession::ClientFinishInsertCommitSession(ThreadContext* ctx) throw()  : IObject(ctx), AbstractNodeRegionCommand(ctx), commitId(0), trxId(0)
{
	this->type = AbstractNodeRegionCommand::TYPE_FINISH_COMMIT_SESSION;
}
void ClientFinishInsertCommitSession::__construct_impl(ThreadContext* ctx) throw() 
{
	this->type = AbstractNodeRegionCommand::TYPE_FINISH_COMMIT_SESSION;
}
 ClientFinishInsertCommitSession::~ClientFinishInsertCommitSession() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void ClientFinishInsertCommitSession::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"ClientFinishInsertCommitSession", L"~ClientFinishInsertCommitSession");
	if(!prepare){
		return;
	}
	AbstractNodeRegionCommand::__releaseRegerences(true, ctx);
}
void ClientFinishInsertCommitSession::executeOnServer(NodeRegionServer* nodeRegionServer, BufferedOutputStream* outStream, ThreadContext* ctx)
{
	nodeRegionServer->finishInsertData(this->trxId, ctx);
	writeByteStream(outStream, ctx);
}
void ClientFinishInsertCommitSession::readFromStream(InputStream* stream, int remain, ThreadContext* ctx)
{
	IArrayObjectPrimitive<char>* src = ArrayAllocatorPrimitive<char>::allocatep(ctx, remain);
	stream->read(src, ctx);
	NetworkBinaryBuffer* buff = (new(ctx) NetworkBinaryBuffer(src, ctx));
	this->commitId = buff->getLong(ctx);
}
long long ClientFinishInsertCommitSession::getTrxId(ThreadContext* ctx) throw() 
{
	return trxId;
}
void ClientFinishInsertCommitSession::setTrxId(long long trxId, ThreadContext* ctx) throw() 
{
	this->trxId = trxId;
}
long long ClientFinishInsertCommitSession::getCommitId(ThreadContext* ctx) throw() 
{
	return commitId;
}
void ClientFinishInsertCommitSession::setCommitId(long long commitId, ThreadContext* ctx) throw() 
{
	this->commitId = commitId;
}
void ClientFinishInsertCommitSession::writeByteStream(OutputStream* outStream, ThreadContext* ctx)
{
	NetworkBinaryBuffer* buff = (new(ctx) NetworkBinaryBuffer(32, ctx));
	buff->putInt(this->type, ctx);
	buff->putLong(this->commitId, ctx);
	IArrayObjectPrimitive<char>* b = buff->toBinary(ctx);
	int pos = buff->getPutSize(ctx);
	outStream->write(b, 0, pos, ctx);
	outStream->flush(ctx);
}
}}}}}

