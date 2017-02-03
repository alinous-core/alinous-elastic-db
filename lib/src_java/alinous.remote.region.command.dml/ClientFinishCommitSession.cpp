#include "includes.h"


namespace alinous {namespace remote {namespace region {namespace command {namespace dml {





bool ClientFinishCommitSession::__init_done = __init_static_variables();
bool ClientFinishCommitSession::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"ClientFinishCommitSession", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 ClientFinishCommitSession::ClientFinishCommitSession(ThreadContext* ctx) throw()  : IObject(ctx), AbstractNodeRegionCommand(ctx), commitId(0)
{
	this->type = AbstractNodeRegionCommand::TYPE_FINISH_COMMIT_SESSION;
}
void ClientFinishCommitSession::__construct_impl(ThreadContext* ctx) throw() 
{
	this->type = AbstractNodeRegionCommand::TYPE_FINISH_COMMIT_SESSION;
}
 ClientFinishCommitSession::~ClientFinishCommitSession() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void ClientFinishCommitSession::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"ClientFinishCommitSession", L"~ClientFinishCommitSession");
	if(!prepare){
		return;
	}
	AbstractNodeRegionCommand::__releaseRegerences(true, ctx);
}
void ClientFinishCommitSession::executeOnServer(NodeRegionServer* nodeRegionServer, BufferedOutputStream* outStream, ThreadContext* ctx)
{
	writeByteStream(outStream, ctx);
}
void ClientFinishCommitSession::readFromStream(InputStream* stream, int remain, ThreadContext* ctx)
{
	IArrayObjectPrimitive<char>* src = ArrayAllocatorPrimitive<char>::allocatep(ctx, remain);
	stream->read(src, ctx);
	NetworkBinaryBuffer* buff = (new(ctx) NetworkBinaryBuffer(src, ctx));
	this->commitId = buff->getLong(ctx);
}
long long ClientFinishCommitSession::getCommitId(ThreadContext* ctx) throw() 
{
	return commitId;
}
void ClientFinishCommitSession::setCommitId(long long commitId, ThreadContext* ctx) throw() 
{
	this->commitId = commitId;
}
void ClientFinishCommitSession::writeByteStream(OutputStream* outStream, ThreadContext* ctx)
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

