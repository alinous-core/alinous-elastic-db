#include "include/global.h"


#include "java.io/FilterOutputStream.h"
#include "java.io/BufferedOutputStream.h"
#include "alinous.compile/AbstractSrcElement.h"
#include "alinous.system/AlinousException.h"
#include "alinous.runtime/ExecutionException.h"
#include "alinous.runtime.dom/VariableException.h"
#include "alinous.remote.socket/NetworkBinaryBuffer.h"
#include "alinous.remote.socket/ICommandData.h"
#include "alinous.db.trx/DbVersionContext.h"
#include "alinous.remote.region.server/NodeRegionServer.h"
#include "alinous.remote.region.client.command/AbstractNodeRegionCommand.h"
#include "alinous.remote.region.client.command.dml/ClientClearSelectSessionCommand.h"

namespace alinous {namespace remote {namespace region {namespace client {namespace command {namespace dml {





bool ClientClearSelectSessionCommand::__init_done = __init_static_variables();
bool ClientClearSelectSessionCommand::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"ClientClearSelectSessionCommand", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 ClientClearSelectSessionCommand::ClientClearSelectSessionCommand(ThreadContext* ctx) throw()  : IObject(ctx), AbstractNodeRegionCommand(ctx), commitId(0), vctx(nullptr)
{
	this->type = AbstractNodeRegionCommand::TYPE_CLEAR_SELECT_SESSION;
}
void ClientClearSelectSessionCommand::__construct_impl(ThreadContext* ctx) throw() 
{
	this->type = AbstractNodeRegionCommand::TYPE_CLEAR_SELECT_SESSION;
}
 ClientClearSelectSessionCommand::~ClientClearSelectSessionCommand() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void ClientClearSelectSessionCommand::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"ClientClearSelectSessionCommand", L"~ClientClearSelectSessionCommand");
	__e_obj1.add(this->vctx, this);
	vctx = nullptr;
	if(!prepare){
		return;
	}
	AbstractNodeRegionCommand::__releaseRegerences(true, ctx);
}
void ClientClearSelectSessionCommand::executeOnServer(NodeRegionServer* nodeRegionServer, BufferedOutputStream* outStream, ThreadContext* ctx)
{
	nodeRegionServer->clearSelectLocks(this->commitId, this->vctx, ctx);
	writeByteStream(outStream, ctx);
}
void ClientClearSelectSessionCommand::readFromStream(InputStream* stream, int remain, ThreadContext* ctx)
{
	IArrayObjectPrimitive<char>* src = ArrayAllocatorPrimitive<char>::allocatep(ctx, remain);
	stream->read(src, ctx);
	NetworkBinaryBuffer* buff = (new(ctx) NetworkBinaryBuffer(src, ctx));
	this->commitId = buff->getLong(ctx);
	bool isnull = buff->getBoolean(ctx);
	if(!isnull)
	{
		__GC_MV(this, &(this->vctx), DbVersionContext::fromNetwork(buff, ctx), DbVersionContext);
	}
}
long long ClientClearSelectSessionCommand::getCommitId(ThreadContext* ctx) throw() 
{
	return commitId;
}
void ClientClearSelectSessionCommand::setCommitId(long long commitId, ThreadContext* ctx) throw() 
{
	this->commitId = commitId;
}
DbVersionContext* ClientClearSelectSessionCommand::getVctx(ThreadContext* ctx) throw() 
{
	return vctx;
}
void ClientClearSelectSessionCommand::setVctx(DbVersionContext* vctx, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->vctx), vctx, DbVersionContext);
}
void ClientClearSelectSessionCommand::writeByteStream(OutputStream* outStream, ThreadContext* ctx)
{
	NetworkBinaryBuffer* buff = (new(ctx) NetworkBinaryBuffer(32, ctx));
	buff->putInt(this->type, ctx);
	buff->putLong(this->commitId, ctx);
	bool isnull = (this->vctx == nullptr);
	buff->putBoolean(isnull, ctx);
	if(!isnull)
	{
		this->vctx->writeData(buff, ctx);
	}
	IArrayObjectPrimitive<char>* b = buff->toBinary(ctx);
	int pos = buff->getPutSize(ctx);
	outStream->write(b, 0, pos, ctx);
	outStream->flush(ctx);
}
void ClientClearSelectSessionCommand::__cleanUp(ThreadContext* ctx){
}
}}}}}}

