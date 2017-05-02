#include "include/global.h"


#include "alinous.compile/AbstractSrcElement.h"
#include "alinous.system/AlinousException.h"
#include "alinous.db/AlinousDbException.h"
#include "alinous.db.table/IDatabaseTable.h"
#include "alinous.remote.socket/ICommandData.h"
#include "alinous.db.trx/DbVersionContext.h"
#include "alinous.lock/LockObject.h"
#include "alinous.remote.region.client.command.dml/ClientScanCommandData.h"
#include "alinous.remote.region.server.scan/ScanWorkerResult.h"
#include "alinous.remote.db.server.scan/AbstractStorageScanSession.h"
#include "java.lang/Number.h"
#include "java.lang/Comparable.h"
#include "java.lang/Long.h"
#include "alinous.remote.db.server.scan/FullScanSession.h"
#include "alinous.remote.db.server.scan/EqKeyScanSession.h"
#include "alinous.remote.db.server.scan/ListScanSession.h"
#include "alinous.remote.db.server.scan/RangeScanSession.h"
#include "alinous.remote.db.server.scan/StorageScanSessionManager.h"

namespace alinous {namespace remote {namespace db {namespace server {namespace scan {





bool StorageScanSessionManager::__init_done = __init_static_variables();
bool StorageScanSessionManager::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"StorageScanSessionManager", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 StorageScanSessionManager::StorageScanSessionManager(ThreadContext* ctx) throw()  : IObject(ctx), lock(__GC_INS(this, (new(ctx) LockObject(ctx)), LockObject)), sessions(GCUtils<Map<Long,AbstractStorageScanSession> >::ins(this, (new(ctx) HashMap<Long,AbstractStorageScanSession>(ctx)), ctx, __FILEW__, __LINE__, L""))
{
}
void StorageScanSessionManager::__construct_impl(ThreadContext* ctx) throw() 
{
}
 StorageScanSessionManager::~StorageScanSessionManager() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void StorageScanSessionManager::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"StorageScanSessionManager", L"~StorageScanSessionManager");
	__e_obj1.add(this->lock, this);
	lock = nullptr;
	__e_obj1.add(this->sessions, this);
	sessions = nullptr;
	if(!prepare){
		return;
	}
}
AbstractStorageScanSession* StorageScanSessionManager::getScanSession(IDatabaseTable* table, DbVersionContext* vctx, ClientScanCommandData* data, ThreadContext* ctx)
{
	Long* trxId = (new(ctx) Long(vctx->getTrxId(ctx), ctx));
	{
		SynchronizedBlockObj __synchronized_2(this->lock, ctx);
		AbstractStorageScanSession* session = this->sessions->get(trxId, ctx);
		if(session == nullptr)
		{
			session = newSession(table, data, ctx);
			this->sessions->put(trxId, session, ctx);
		}
		return session;
	}
}
AbstractStorageScanSession* StorageScanSessionManager::newSession(IDatabaseTable* table, ClientScanCommandData* data, ThreadContext* ctx)
{
	AbstractStorageScanSession* session = nullptr;
	if(data->isFullscan(ctx))
	{
		session = (new(ctx) FullScanSession(table, data, ctx));
	}
		else 
	{
		if(data->getEqKey(ctx) != nullptr)
		{
			session = (new(ctx) EqKeyScanSession(table, data, ctx));
		}
				else 
		{
			if(data->getListParam(ctx) != nullptr)
			{
				session = (new(ctx) ListScanSession(table, data, ctx));
			}
						else 
			{
				if(data->getRangeParam(ctx) != nullptr)
				{
					session = (new(ctx) RangeScanSession(table, data, ctx));
				}
								else 
				{
					throw (new(ctx) AlinousDbException(ConstStr::getCNST_STR_3597(), ctx));
				}
			}
		}
	}
	session->init(ctx);
	return session;
}
void StorageScanSessionManager::__cleanUp(ThreadContext* ctx){
}
}}}}}

