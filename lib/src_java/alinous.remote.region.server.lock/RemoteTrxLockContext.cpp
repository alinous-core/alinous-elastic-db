#include "include/global.h"


#include "alinous.compile/AbstractSrcElement.h"
#include "alinous.system/AlinousException.h"
#include "alinous.db/AlinousDbException.h"
#include "alinous.db.table.scan/IndexScannerLockRequirement.h"
#include "alinous.remote.region.server.lock/IRemoteTableLock.h"
#include "alinous.remote.region.server.lock/TrxLockContextLockHolder.h"
#include "alinous.remote.region.server.lock/RemoteTrxLockContext.h"

namespace alinous {namespace remote {namespace region {namespace server {namespace lock {





bool RemoteTrxLockContext::__init_done = __init_static_variables();
bool RemoteTrxLockContext::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"RemoteTrxLockContext", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 RemoteTrxLockContext::RemoteTrxLockContext(ThreadContext* ctx) throw()  : IObject(ctx), tables(GCUtils<Map<String,TrxLockContextLockHolder> >::ins(this, (new(ctx) HashMap<String,TrxLockContextLockHolder>(ctx)), ctx, __FILEW__, __LINE__, L""))
{
}
void RemoteTrxLockContext::__construct_impl(ThreadContext* ctx) throw() 
{
}
 RemoteTrxLockContext::~RemoteTrxLockContext() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void RemoteTrxLockContext::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"RemoteTrxLockContext", L"~RemoteTrxLockContext");
	__e_obj1.add(this->tables, this);
	tables = nullptr;
	if(!prepare){
		return;
	}
}
void RemoteTrxLockContext::addLock(String* fullName, IRemoteTableLock* lock, int lockMode, ThreadContext* ctx)
{
	TrxLockContextLockHolder* lastLock = this->tables->get(fullName, ctx);
	if(lastLock == nullptr)
	{
		lastLock = (new(ctx) TrxLockContextLockHolder(lock, ctx));
		this->tables->put(fullName, lastLock, ctx);
	}
	switch(lockMode) {
	case IndexScannerLockRequirement::INSTANT_SHARE:
	case IndexScannerLockRequirement::EXPLICIT_SHARE:
		lastLock->shareLock(ctx);
		break ;
	case IndexScannerLockRequirement::INSTANT_UPDATE:
	case IndexScannerLockRequirement::EXPLICIT_UPDATE:
		lastLock->updateLock(ctx);
		break ;
	default:
		break ;
	}
}
void RemoteTrxLockContext::releaseLock(String* fullName, int lockMode, ThreadContext* ctx)
{
	TrxLockContextLockHolder* lastLock = this->tables->get(fullName, ctx);
	if(lastLock == nullptr)
	{
		return;
	}
	switch(lockMode) {
	case IndexScannerLockRequirement::INSTANT_SHARE:
	case IndexScannerLockRequirement::EXPLICIT_SHARE:
		lastLock->shareUnlock(ctx);
		break ;
	case IndexScannerLockRequirement::INSTANT_UPDATE:
	case IndexScannerLockRequirement::EXPLICIT_UPDATE:
		lastLock->updateUnlock(ctx);
		break ;
	default:
		break ;
	}
}
Map<String,TrxLockContextLockHolder>* RemoteTrxLockContext::getTables(ThreadContext* ctx) throw() 
{
	return tables;
}
void RemoteTrxLockContext::__cleanUp(ThreadContext* ctx){
}
}}}}}

