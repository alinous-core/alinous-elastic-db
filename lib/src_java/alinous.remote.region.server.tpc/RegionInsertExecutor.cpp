#include "include/global.h"


#include "alinous.buffer.storage/FileStorageEntryBuilder.h"
#include "alinous.btree/IValueFetcher.h"
#include "alinous.btree/IBTreeValue.h"
#include "alinous.db.table/IDatabaseRecord.h"
#include "alinous.remote.socket/ICommandData.h"
#include "alinous.remote.region.client.command.data/ClientNetworkRecord.h"
#include "alinous.db.table/TableMetadata.h"
#include "alinous.lock/LockObject.h"
#include "alinous.remote.region.server.schema/NodeTableClaster.h"
#include "alinous.remote.region.server.schema/RegionShardPart.h"
#include "alinous.remote.region.server.schema/RegionShardTable.h"
#include "alinous.remote.region.server.schema/NodeReferenceManager.h"
#include "java.lang/Number.h"
#include "java.lang/Comparable.h"
#include "java.lang/Long.h"
#include "alinous.remote.region.server.tpc/RegionInsertExecutor.h"
#include "alinous.db.trx/DbVersionContext.h"
#include "alinous.remote.region.server.tpc/RegionTpcExecutorPool.h"

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
 RegionInsertExecutor::RegionInsertExecutor(long long trxId, long long commitId, NodeReferenceManager* ref, ThreadContext* ctx) throw()  : IObject(ctx), ref(nullptr), trxId(nullptr), commitId(0)
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
	if(!prepare){
		return;
	}
}
void RegionInsertExecutor::prepareInsert(ArrayList<ClientNetworkRecord>* list, String* schema, String* table, ThreadContext* ctx) throw() 
{
	RegionShardTable* shard = this->ref->getCluster(schema, table, ctx);
	shard->setCommitId(this->commitId, ctx);
	shard->putRecords(list, ctx);
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
void RegionInsertExecutor::__cleanUp(ThreadContext* ctx){
}
}}}}}

