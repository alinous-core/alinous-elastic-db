#include "include/global.h"


#include "alinous.remote.socket/NetworkBinaryBuffer.h"
#include "alinous.remote.socket/ICommandData.h"
#include "alinous.db.trx/DbVersionContext.h"
#include "java.io/FilterOutputStream.h"
#include "java.io/BufferedOutputStream.h"
#include "alinous.buffer.storage/FileStorageEntryBuilder.h"
#include "alinous.compile/AbstractSrcElement.h"
#include "alinous.system/AlinousException.h"
#include "alinous.btree/IValueFetcher.h"
#include "alinous.btree/IBTreeValue.h"
#include "alinous.db.table/IDatabaseRecord.h"
#include "alinous.remote.region.client.command.data/ClientNetworkRecord.h"
#include "alinous.remote.db.server/RemoteTableStorageServer.h"
#include "alinous.remote.db.client.command/RemoteStorageCommandReader.h"
#include "alinous.remote.db.client.command/AbstractRemoteStorageCommand.h"
#include "alinous.remote.region.server.schema/NodeReference.h"
#include "alinous.remote.db.client.command.dml/InsertPrepareCommand.h"
#include "alinous.remote.region.server.schema.strategy/RegionPartitionTableAccess.h"
#include "alinous.remote.region.server.schema/NodeReferenceManager.h"
#include "alinous.remote.region.server.schema.strategy/InsertTableStrategy.h"
#include "java.lang/Number.h"
#include "java.lang/Comparable.h"
#include "java.lang/Long.h"
#include "alinous.remote.region.server.tpc/RegionInsertExecutor.h"

namespace alinous {namespace remote {namespace region {namespace server {namespace tpc {





bool RegionInsertExecutor::__init_done = __init_static_variables();
bool RegionInsertExecutor::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"RegionInsertExecutor", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 RegionInsertExecutor::RegionInsertExecutor(long long trxId, long long commitId, NodeReferenceManager* ref, ThreadContext* ctx) throw()  : IObject(ctx), ref(nullptr), trxId(nullptr), commitId(0), strategy(nullptr)
{
	__GC_MV(this, &(this->ref), ref, NodeReferenceManager);
	__GC_MV(this, &(this->trxId), (new(ctx) Long(trxId, ctx)), Long);
	this->commitId = commitId;
}
void RegionInsertExecutor::__construct_impl(long long trxId, long long commitId, NodeReferenceManager* ref, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->ref), ref, NodeReferenceManager);
	__GC_MV(this, &(this->trxId), (new(ctx) Long(trxId, ctx)), Long);
	this->commitId = commitId;
}
 RegionInsertExecutor::~RegionInsertExecutor() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void RegionInsertExecutor::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"RegionInsertExecutor", L"~RegionInsertExecutor");
	__e_obj1.add(this->ref, this);
	ref = nullptr;
	__e_obj1.add(this->trxId, this);
	trxId = nullptr;
	__e_obj1.add(this->strategy, this);
	strategy = nullptr;
	if(!prepare){
		return;
	}
}
void RegionInsertExecutor::prepareInsert(ArrayList<ClientNetworkRecord>* list, String* schema, String* table, DbVersionContext* vctx, long long newCommitId, int isolationLevel, ThreadContext* ctx)
{
	RegionPartitionTableAccess* tableAccess = this->ref->getCluster(schema, table, ctx);
	__GC_MV(this, &(this->strategy), (new(ctx) InsertTableStrategy(this->commitId, tableAccess, ctx)), InsertTableStrategy);
	this->strategy->build(list, ctx);
	List<InsertPrepareCommand>* prepares = this->strategy->toPrepareCommand(vctx, newCommitId, isolationLevel, ctx);
	int maxLoop = prepares->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		InsertPrepareCommand* cmd = prepares->get(i, ctx);
		sendPrepareCommand(cmd, ctx);
	}
}
void RegionInsertExecutor::tpcCommitInsert(ThreadContext* ctx) throw() 
{
}
void RegionInsertExecutor::dispose(ThreadContext* ctx) throw() 
{
}
Long* RegionInsertExecutor::getTrxId(ThreadContext* ctx) throw() 
{
	return trxId;
}
void RegionInsertExecutor::sendPrepareCommand(InsertPrepareCommand* cmd, ThreadContext* ctx)
{
	NodeReference* ref = cmd->getNodeAccessRef(ctx);
	ref->sendCommand(cmd, ctx);
}
void RegionInsertExecutor::__cleanUp(ThreadContext* ctx){
}
}}}}}

