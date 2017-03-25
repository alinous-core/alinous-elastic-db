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
#include "alinous.remote.db.server/RemoteTableStorageServer.h"
#include "alinous.remote.db.client.command/RemoteStorageCommandReader.h"
#include "alinous.remote.db.client.command/AbstractRemoteStorageCommand.h"
#include "alinous.remote.db.client.command.dml/CommitDMLCommand.h"

namespace alinous {namespace remote {namespace db {namespace client {namespace command {namespace dml {





bool CommitDMLCommand::__init_done = __init_static_variables();
bool CommitDMLCommand::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"CommitDMLCommand", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 CommitDMLCommand::CommitDMLCommand(ThreadContext* ctx) throw()  : IObject(ctx), AbstractRemoteStorageCommand(ctx), newCommitId(0), vctx(nullptr)
{
	this->type = AbstractRemoteStorageCommand::TYPE_COMMIT_DML;
}
void CommitDMLCommand::__construct_impl(ThreadContext* ctx) throw() 
{
	this->type = AbstractRemoteStorageCommand::TYPE_COMMIT_DML;
}
 CommitDMLCommand::~CommitDMLCommand() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void CommitDMLCommand::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"CommitDMLCommand", L"~CommitDMLCommand");
	__e_obj1.add(this->vctx, this);
	vctx = nullptr;
	if(!prepare){
		return;
	}
	AbstractRemoteStorageCommand::__releaseRegerences(true, ctx);
}
void CommitDMLCommand::executeOnServer(RemoteTableStorageServer* tableStorageServer, BufferedOutputStream* outStream, ThreadContext* ctx)
{
	writeByteStream(outStream, ctx);
}
void CommitDMLCommand::readFromStream(InputStream* stream, int remain, ThreadContext* ctx)
{
}
long long CommitDMLCommand::getNewCommitId(ThreadContext* ctx) throw() 
{
	return newCommitId;
}
void CommitDMLCommand::setNewCommitId(long long newCommitId, ThreadContext* ctx) throw() 
{
	this->newCommitId = newCommitId;
}
DbVersionContext* CommitDMLCommand::getVctx(ThreadContext* ctx) throw() 
{
	return vctx;
}
void CommitDMLCommand::setVctx(DbVersionContext* vctx, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->vctx), vctx, DbVersionContext);
}
void CommitDMLCommand::writeByteStream(OutputStream* outStream, ThreadContext* ctx)
{
}
void CommitDMLCommand::__cleanUp(ThreadContext* ctx){
}
}}}}}}

