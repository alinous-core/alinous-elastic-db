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
#include "alinous.system/AlinousCore.h"
#include "alinous.remote.db.server/RemoteTableStorageServer.h"
#include "alinous.remote.db.client.command/RemoteStorageCommandReader.h"
#include "alinous.remote.db.client.command/AbstractRemoteStorageCommand.h"
#include "alinous.remote.db.client.command.dml/ClearRowLocksCommand.h"

namespace alinous {namespace remote {namespace db {namespace client {namespace command {namespace dml {





bool ClearRowLocksCommand::__init_done = __init_static_variables();
bool ClearRowLocksCommand::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"ClearRowLocksCommand", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 ClearRowLocksCommand::ClearRowLocksCommand(ThreadContext* ctx) throw()  : IObject(ctx), AbstractRemoteStorageCommand(ctx), vctx(nullptr)
{
	this->type = AbstractRemoteStorageCommand::TYPE_CLEAR_ROW_LOCKS;
}
void ClearRowLocksCommand::__construct_impl(ThreadContext* ctx) throw() 
{
	this->type = AbstractRemoteStorageCommand::TYPE_CLEAR_ROW_LOCKS;
}
 ClearRowLocksCommand::~ClearRowLocksCommand() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void ClearRowLocksCommand::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"ClearRowLocksCommand", L"~ClearRowLocksCommand");
	__e_obj1.add(this->vctx, this);
	vctx = nullptr;
	if(!prepare){
		return;
	}
	AbstractRemoteStorageCommand::__releaseRegerences(true, ctx);
}
void ClearRowLocksCommand::executeOnServer(RemoteTableStorageServer* tableStorageServer, BufferedOutputStream* outStream, ThreadContext* ctx)
{
	{
		try
		{
			tableStorageServer->clearRowLocks(this->vctx, ctx);
		}
		catch(Throwable* e)
		{
			AlinousCore* core = tableStorageServer->getCore(ctx);
			core->logError(e, ctx);
			handleError(e, ctx);
		}
	}
	writeByteStream(outStream, ctx);
}
void ClearRowLocksCommand::readFromStream(InputStream* stream, int remain, ThreadContext* ctx)
{
	IArrayObjectPrimitive<char>* src = ArrayAllocatorPrimitive<char>::allocatep(ctx, remain);
	stream->read(src, ctx);
	NetworkBinaryBuffer* buff = (new(ctx) NetworkBinaryBuffer(src, ctx));
	bool isnull = buff->getBoolean(ctx);
	if(!isnull)
	{
		__GC_MV(this, &(this->vctx), DbVersionContext::fromNetwork(buff, ctx), DbVersionContext);
	}
}
DbVersionContext* ClearRowLocksCommand::getVctx(ThreadContext* ctx) throw() 
{
	return vctx;
}
void ClearRowLocksCommand::setVctx(DbVersionContext* vctx, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->vctx), vctx, DbVersionContext);
}
void ClearRowLocksCommand::writeByteStream(OutputStream* outStream, ThreadContext* ctx)
{
	NetworkBinaryBuffer* buff = (new(ctx) NetworkBinaryBuffer(1024 * 2, ctx));
	buff->putInt(this->type, ctx);
	bool isnull = (this->vctx == nullptr);
	buff->putBoolean(isnull, ctx);
	if(!isnull)
	{
		this->vctx->writeData(buff, ctx);
	}
	writeErrorByteStream(buff, ctx);
	IArrayObjectPrimitive<char>* b = buff->toBinary(ctx);
	int pos = buff->getPutSize(ctx);
	outStream->write(b, 0, pos, ctx);
	outStream->flush(ctx);
}
void ClearRowLocksCommand::__cleanUp(ThreadContext* ctx){
}
}}}}}}

