#include "include/global.h"


#include "alinous.compile/AbstractSrcElement.h"
#include "alinous.system/AlinousException.h"
#include "alinous.db/AlinousDbException.h"
#include "alinous.db.table.scan/IndexScannerLockRequirement.h"
#include "alinous.lock/LockObject.h"
#include "alinous.remote.region.server/NodeRegionServer.h"
#include "java.lang/Number.h"
#include "java.lang/Comparable.h"
#include "java.lang/Long.h"
#include "alinous.remote.region.server.lock/IRemoteTableLock.h"
#include "alinous.remote.region.server.lock/RemoteTrxLockContext.h"
#include "alinous.remote.region.server.lock/RemoteTableLock.h"
#include "alinous.remote.region.server.lock/RegionTableLockManager.h"

namespace alinous {namespace remote {namespace region {namespace server {namespace lock {





bool RegionTableLockManager::__init_done = __init_static_variables();
bool RegionTableLockManager::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"RegionTableLockManager", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 RegionTableLockManager::RegionTableLockManager(ThreadContext* ctx) throw()  : IObject(ctx), lockContext(GCUtils<Map<Long,RemoteTrxLockContext> >::ins(this, (new(ctx) HashMap<Long,RemoteTrxLockContext>(ctx)), ctx, __FILEW__, __LINE__, L"")), ctxlock(__GC_INS(this, (new(ctx) LockObject(ctx)), LockObject)), locks(GCUtils<Map<String,IRemoteTableLock> >::ins(this, (new(ctx) HashMap<String,IRemoteTableLock>(ctx)), ctx, __FILEW__, __LINE__, L""))
{
}
void RegionTableLockManager::__construct_impl(ThreadContext* ctx) throw() 
{
}
 RegionTableLockManager::~RegionTableLockManager() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void RegionTableLockManager::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"RegionTableLockManager", L"~RegionTableLockManager");
	__e_obj1.add(this->lockContext, this);
	lockContext = nullptr;
	__e_obj1.add(this->ctxlock, this);
	ctxlock = nullptr;
	__e_obj1.add(this->locks, this);
	locks = nullptr;
	if(!prepare){
		return;
	}
}
void RegionTableLockManager::lockTable(String* schema, String* table, int lockMode, long long trxId, NodeRegionServer* server, ThreadContext* ctx)
{
	StringBuilder* buff = (new(ctx) StringBuilder(ctx));
	buff->append(schema, ctx)->append(ConstStr::getCNST_STR_953(), ctx)->append(table, ctx);
	Long* trxIdObj = (new(ctx) Long(trxId, ctx));
	String* fullName = buff->toString(ctx);
	{
		SynchronizedBlockObj __synchronized_2(this->ctxlock, ctx);
		RemoteTrxLockContext* context = this->lockContext->get(trxIdObj, ctx);
		if(context == nullptr)
		{
			context = (new(ctx) RemoteTrxLockContext(ctx));
			this->lockContext->put(trxIdObj, context, ctx);
		}
		IRemoteTableLock* tableLock = getLock(fullName, server, true, ctx);
		context->addLock(fullName, tableLock, lockMode, ctx);
	}
}
void RegionTableLockManager::unlockShared(String* schema, String* table, long long trxId, NodeRegionServer* server, ThreadContext* ctx)
{
	StringBuilder* buff = (new(ctx) StringBuilder(ctx));
	buff->append(schema, ctx)->append(ConstStr::getCNST_STR_953(), ctx)->append(table, ctx);
	String* fullName = buff->toString(ctx);
	Long* trxIdObj = (new(ctx) Long(trxId, ctx));
	{
		SynchronizedBlockObj __synchronized_2(this->ctxlock, ctx);
		RemoteTrxLockContext* context = this->lockContext->get(trxIdObj, ctx);
		if(context == nullptr)
		{
			return;
		}
		context->releaseLock(fullName, IndexScannerLockRequirement::INSTANT_SHARE, ctx);
	}
}
IRemoteTableLock* RegionTableLockManager::getLock(String* fullName, NodeRegionServer* server, bool create, ThreadContext* ctx) throw() 
{
	IRemoteTableLock* lock = this->locks->get(fullName, ctx);
	if(lock == nullptr && create)
	{
		return createTableLock(server, ctx);
	}
	return lock;
}
IRemoteTableLock* RegionTableLockManager::createTableLock(NodeRegionServer* server, ThreadContext* ctx) throw() 
{
	if(server->isScale(ctx))
	{
		return nullptr;
	}
	return (new(ctx) RemoteTableLock(ctx));
}
void RegionTableLockManager::__cleanUp(ThreadContext* ctx){
}
}}}}}

