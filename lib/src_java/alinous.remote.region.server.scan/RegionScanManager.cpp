#include "include/global.h"


#include "alinous.compile/AbstractSrcElement.h"
#include "alinous.system/AlinousException.h"
#include "alinous.db/AlinousDbException.h"
#include "alinous.lock/LockObject.h"
#include "alinous.remote.socket/ICommandData.h"
#include "alinous.remote.region.client.command.dml/ClientScanCommandData.h"
#include "alinous.remote.region.server.scan/ScanSession.h"
#include "java.lang/Number.h"
#include "java.lang/Comparable.h"
#include "java.lang/Long.h"
#include "alinous.remote.region.server.scan/RegionScanManager.h"

namespace alinous {namespace remote {namespace region {namespace server {namespace scan {





bool RegionScanManager::__init_done = __init_static_variables();
bool RegionScanManager::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"RegionScanManager", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 RegionScanManager::RegionScanManager(ThreadContext* ctx) throw()  : IObject(ctx), sessions(GCUtils<Map<Long,ScanSession> >::ins(this, (new(ctx) HashMap<Long,ScanSession>(ctx)), ctx, __FILEW__, __LINE__, L"")), lock(__GC_INS(this, (new(ctx) LockObject(ctx)), LockObject))
{
}
void RegionScanManager::__construct_impl(ThreadContext* ctx) throw() 
{
}
 RegionScanManager::~RegionScanManager() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void RegionScanManager::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"RegionScanManager", L"~RegionScanManager");
	__e_obj1.add(this->sessions, this);
	sessions = nullptr;
	__e_obj1.add(this->lock, this);
	lock = nullptr;
	if(!prepare){
		return;
	}
}
ScanSession* RegionScanManager::getScanSession(long long trxId, ClientScanCommandData* data, ThreadContext* ctx)
{
	Long* id = (new(ctx) Long(trxId, ctx));
	{
		SynchronizedBlockObj __synchronized_2(this->lock, ctx);
		ScanSession* session = this->sessions->get(id, ctx);
		if(session == nullptr)
		{
			session = (new(ctx) ScanSession(data, ctx))->init(ctx);
			this->sessions->put(id, session, ctx);
		}
		return session;
	}
}
void RegionScanManager::endSession(long long trxId, ThreadContext* ctx) throw() 
{
	Long* id = (new(ctx) Long(trxId, ctx));
	{
		SynchronizedBlockObj __synchronized_2(this->lock, ctx);
		this->sessions->remove(id, ctx);
	}
}
void RegionScanManager::__cleanUp(ThreadContext* ctx){
}
}}}}}

