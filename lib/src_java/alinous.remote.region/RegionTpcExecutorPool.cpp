#include "include/global.h"


#include "alinous.buffer.storage/FileStorageEntryBuilder.h"
#include "alinous.remote.socket/ICommandData.h"
#include "alinous.db.table/TablePartitionRangeCollection.h"
#include "alinous.db.table/TableMetadata.h"
#include "alinous.lock/LockObject.h"
#include "alinous.remote.socket/SocketConnectionPool.h"
#include "alinous.remote.region/NodeReference.h"
#include "alinous.remote.region/NodeTableReference.h"
#include "alinous.db.trx/DbVersionContext.h"
#include "alinous.btree/IValueFetcher.h"
#include "alinous.btree/IBTreeValue.h"
#include "alinous.db.table/IDatabaseRecord.h"
#include "alinous.remote.region.client.command.data/ClientNetworkRecord.h"
#include "alinous.remote.region.client.command.data/ClientSchemaData.h"
#include "alinous.remote.region.client.command.data/ClientStructureMetadata.h"
#include "alinous.runtime.parallel/IThreadAction.h"
#include "alinous.system/ISystemLog.h"
#include "alinous.remote.socket/ISocketActionFactory.h"
#include "alinous.remote.socket/SocketServer.h"
#include "alinous.system.config/IAlinousConfigElement.h"
#include "alinous.system.config.remote/MonitorRef.h"
#include "alinous.system.config.remote/RegionsServer.h"
#include "alinous.system/AlinousCore.h"
#include "alinous.remote.db.client.command.data/SchemaData.h"
#include "alinous.remote.region/NodeCluster.h"
#include "alinous.remote.region/NodeTableClaster.h"
#include "alinous.remote.region/NodeRegionSchema.h"
#include "alinous.remote.region/RegionShardPart.h"
#include "alinous.remote.region/RegionShardTable.h"
#include "alinous.remote.region/NodeReferenceManager.h"
#include "java.io/FilterInputStream.h"
#include "java.io/BufferedInputStream.h"
#include "java.io/FilterOutputStream.h"
#include "java.io/BufferedOutputStream.h"
#include "alinous.remote.region/NodeRegionResponceAction.h"
#include "alinous.remote.region/NodeRegionResponceActionFactory.h"
#include "java.lang/Number.h"
#include "java.lang/Comparable.h"
#include "java.lang/Long.h"
#include "alinous.remote.region/RegionInsertExecutor.h"
#include "alinous.remote.region/RegionTpcExecutorPool.h"
#include "alinous.remote.region/NodeRegionServer.h"
#include "alinous.remote.region/RegionTableLockManager.h"

namespace alinous {namespace remote {namespace region {





bool RegionTpcExecutorPool::__init_done = __init_static_variables();
bool RegionTpcExecutorPool::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"RegionTpcExecutorPool", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 RegionTpcExecutorPool::RegionTpcExecutorPool(ThreadContext* ctx) throw()  : IObject(ctx), insertSessions(GCUtils<Map<Long,RegionInsertExecutor> >::ins(this, (new(ctx) HashMap<Long,RegionInsertExecutor>(ctx)), ctx, __FILEW__, __LINE__, L"")), lock(__GC_INS(this, (new(ctx) LockObject(ctx)), LockObject))
{
}
void RegionTpcExecutorPool::__construct_impl(ThreadContext* ctx) throw() 
{
}
 RegionTpcExecutorPool::~RegionTpcExecutorPool() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void RegionTpcExecutorPool::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"RegionTpcExecutorPool", L"~RegionTpcExecutorPool");
	__e_obj1.add(this->insertSessions, this);
	insertSessions = nullptr;
	__e_obj1.add(this->lock, this);
	lock = nullptr;
	if(!prepare){
		return;
	}
}
void RegionTpcExecutorPool::putInsertSession(RegionInsertExecutor* exec, ThreadContext* ctx) throw() 
{
	{
		SynchronizedBlockObj __synchronized_2(this->lock, ctx);
		this->insertSessions->put(exec->getTrxId(ctx), exec, ctx);
	}
}
RegionInsertExecutor* RegionTpcExecutorPool::getInsertSession(long long trxId, long long commitId, DbVersionContext* vctx, NodeReferenceManager* refs, ThreadContext* ctx) throw() 
{
	{
		SynchronizedBlockObj __synchronized_2(this->lock, ctx);
		Long* key = (new(ctx) Long(trxId, ctx));
		RegionInsertExecutor* exec = this->insertSessions->get(key, ctx);
		if(exec == nullptr)
		{
			exec = (new(ctx) RegionInsertExecutor(vctx->getTrxId(ctx), commitId, refs, ctx));
			putInsertSession(exec, ctx);
		}
		return exec;
	}
}
void RegionTpcExecutorPool::removeInsertSession(long long trxId, ThreadContext* ctx) throw() 
{
	{
		SynchronizedBlockObj __synchronized_2(this->lock, ctx);
		Long* key = (new(ctx) Long(trxId, ctx));
		RegionInsertExecutor* exec = this->insertSessions->get(key, ctx);
		if(exec == nullptr)
		{
			return;
		}
		exec->dispose(ctx);
		this->insertSessions->remove(key, ctx);
	}
}
void RegionTpcExecutorPool::__cleanUp(ThreadContext* ctx){
}
}}}

