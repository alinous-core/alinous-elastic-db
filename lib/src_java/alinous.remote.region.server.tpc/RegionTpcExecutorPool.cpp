#include "include/global.h"


#include "alinous.compile/AbstractSrcElement.h"
#include "alinous.system/AlinousException.h"
#include "alinous.db/AlinousDbException.h"
#include "alinous.remote.socket/ICommandData.h"
#include "alinous.db.trx/DbVersionContext.h"
#include "alinous.lock/LockObject.h"
#include "alinous.remote.region.server.schema/NodeReferenceManager.h"
#include "alinous.remote.region.server.tpc/CommitClusterNodeListner.h"
#include "java.lang/Number.h"
#include "java.lang/Comparable.h"
#include "java.lang/Long.h"
#include "alinous.remote.region.server.tpc/RegionInsertExecutor.h"
#include "alinous.remote.region.server.tpc/RegionTpcExecutorPool.h"

namespace alinous {namespace remote {namespace region {namespace server {namespace tpc {





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
 RegionTpcExecutorPool::RegionTpcExecutorPool(ThreadContext* ctx) throw()  : IObject(ctx), insertSessions(GCUtils<Map<Long,RegionInsertExecutor> >::ins(this, (new(ctx) HashMap<Long,RegionInsertExecutor>(ctx)), ctx, __FILEW__, __LINE__, L"")), listners(GCUtils<Map<Long,CommitClusterNodeListner> >::ins(this, (new(ctx) HashMap<Long,CommitClusterNodeListner>(ctx)), ctx, __FILEW__, __LINE__, L"")), lock(__GC_INS(this, (new(ctx) LockObject(ctx)), LockObject))
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
	__e_obj1.add(this->listners, this);
	listners = nullptr;
	__e_obj1.add(this->lock, this);
	lock = nullptr;
	if(!prepare){
		return;
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
			CommitClusterNodeListner* listner = (new(ctx) CommitClusterNodeListner(ctx));
			exec = (new(ctx) RegionInsertExecutor(vctx->getTrxId(ctx), commitId, refs, listner, ctx));
			this->insertSessions->put(exec->getTrxId(ctx), exec, ctx);
			this->listners->put(exec->getTrxId(ctx), listner, ctx);
		}
		return exec;
	}
}
void RegionTpcExecutorPool::tcpCommit(long long newCommitId, DbVersionContext* vctx, ThreadContext* ctx)
{
	CommitClusterNodeListner* commitListner = nullptr;
	{
		SynchronizedBlockObj __synchronized_2(this->lock, ctx);
		Long* key = (new(ctx) Long(vctx->getTrxId(ctx), ctx));
		commitListner = this->listners->get(key, ctx);
		if(commitListner == nullptr)
		{
			throw (new(ctx) AlinousDbException(ConstStr::getCNST_STR_3629(), ctx));
		}
	}
	commitListner->sendCommit(newCommitId, vctx, ctx);
}
void RegionTpcExecutorPool::removeSession(long long trxId, ThreadContext* ctx) throw() 
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
		this->listners->remove(key, ctx);
	}
}
void RegionTpcExecutorPool::__cleanUp(ThreadContext* ctx){
}
}}}}}

