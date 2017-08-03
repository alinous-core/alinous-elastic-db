#include "include/global.h"


#include "alinous.remote.socket/NetworkBinaryBuffer.h"
#include "alinous.remote.socket/ICommandData.h"
#include "alinous.db.trx/DbVersionContext.h"
#include "java.io/FilterOutputStream.h"
#include "java.io/BufferedOutputStream.h"
#include "alinous.compile/AbstractSrcElement.h"
#include "alinous.system/AlinousException.h"
#include "alinous.remote.db.server/RemoteTableStorageServer.h"
#include "alinous.remote.db.client.command/AbstractRemoteStorageCommand.h"
#include "alinous.remote.db.client.command.dml/CommitDMLCommand.h"
#include "alinous.remote.db.client.command/RemoteStorageCommandReader.h"
#include "alinous.remote.db.client.command.dml/ClearRowLocksCommand.h"
#include "alinous.remote.region.server.schema/NodeReference.h"
#include "alinous.remote.region.server.tpc/CommitClusterNodeListner.h"

namespace alinous {namespace remote {namespace region {namespace server {namespace tpc {





bool CommitClusterNodeListner::__init_done = __init_static_variables();
bool CommitClusterNodeListner::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"CommitClusterNodeListner", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 CommitClusterNodeListner::CommitClusterNodeListner(ThreadContext* ctx) throw()  : IObject(ctx), nodeRefs(GCUtils<Map<String,NodeReference> >::ins(this, (new(ctx) HashMap<String,NodeReference>(ctx)), ctx, __FILEW__, __LINE__, L""))
{
}
void CommitClusterNodeListner::__construct_impl(ThreadContext* ctx) throw() 
{
}
 CommitClusterNodeListner::~CommitClusterNodeListner() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void CommitClusterNodeListner::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"CommitClusterNodeListner", L"~CommitClusterNodeListner");
	__e_obj1.add(this->nodeRefs, this);
	nodeRefs = nullptr;
	if(!prepare){
		return;
	}
}
void CommitClusterNodeListner::addNode(NodeReference* ref, ThreadContext* ctx) throw() 
{
	String* key = ref->toString(ctx);
	NodeReference* lastRef = this->nodeRefs->get(key, ctx);
	if(lastRef == nullptr)
	{
		this->nodeRefs->put(key, ref, ctx);
	}
}
void CommitClusterNodeListner::sendRemoveRowLocks(DbVersionContext* vctx, ThreadContext* ctx)
{
	Iterator<String>* it = this->nodeRefs->keySet(ctx)->iterator(ctx);
	while(it->hasNext(ctx))
	{
		String* key = it->next(ctx);
		NodeReference* ref = this->nodeRefs->get(key, ctx);
		doSendRemoveRowLocks(ref, vctx, ctx);
	}
}
void CommitClusterNodeListner::sendCommit(long long newCommitId, DbVersionContext* vctx, ThreadContext* ctx)
{
	Iterator<String>* it = this->nodeRefs->keySet(ctx)->iterator(ctx);
	while(it->hasNext(ctx))
	{
		String* key = it->next(ctx);
		NodeReference* ref = this->nodeRefs->get(key, ctx);
		sendCommitCommand(newCommitId, vctx, ref, ctx);
	}
}
void CommitClusterNodeListner::doSendRemoveRowLocks(NodeReference* ref, DbVersionContext* vctx, ThreadContext* ctx)
{
	ClearRowLocksCommand* cmd = (new(ctx) ClearRowLocksCommand(ctx));
	cmd->setVctx(vctx, ctx);
	ref->sendCommand(cmd, ctx);
}
void CommitClusterNodeListner::sendCommitCommand(long long newCommitId, DbVersionContext* vctx, NodeReference* ref, ThreadContext* ctx)
{
	CommitDMLCommand* cmd = (new(ctx) CommitDMLCommand(ctx));
	cmd->setNewCommitId(newCommitId, ctx);
	cmd->setVctx(vctx, ctx);
	ref->sendCommand(cmd, ctx);
}
void CommitClusterNodeListner::__cleanUp(ThreadContext* ctx){
}
}}}}}

