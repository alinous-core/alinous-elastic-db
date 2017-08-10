#include "include/global.h"


#include "alinous.compile/AbstractSrcElement.h"
#include "alinous.system/AlinousException.h"
#include "alinous.db/AlinousDbException.h"
#include "alinous.remote.region.server.lock/IRemoteTableLock.h"
#include "alinous.remote.region.server.lock/TrxLockContextLockHolder.h"

namespace alinous {namespace remote {namespace region {namespace server {namespace lock {





bool TrxLockContextLockHolder::__init_done = __init_static_variables();
bool TrxLockContextLockHolder::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"TrxLockContextLockHolder", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 TrxLockContextLockHolder::TrxLockContextLockHolder(IRemoteTableLock* remoteLock, ThreadContext* ctx) throw()  : IObject(ctx), remoteLock(nullptr), shareCount(0), updateCount(0)
{
	__GC_MV(this, &(this->remoteLock), remoteLock, IRemoteTableLock);
}
void TrxLockContextLockHolder::__construct_impl(IRemoteTableLock* remoteLock, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->remoteLock), remoteLock, IRemoteTableLock);
}
 TrxLockContextLockHolder::~TrxLockContextLockHolder() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void TrxLockContextLockHolder::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"TrxLockContextLockHolder", L"~TrxLockContextLockHolder");
	__e_obj1.add(this->remoteLock, this);
	remoteLock = nullptr;
	if(!prepare){
		return;
	}
}
void TrxLockContextLockHolder::shareLock(ThreadContext* ctx)
{
	if(this->shareCount > 0 || this->updateCount > 0)
	{
		return;
	}
	this->remoteLock->shareLock(ctx);
	incShareCount(ctx);
}
void TrxLockContextLockHolder::shareUnlock(ThreadContext* ctx) throw() 
{
	if(this->shareCount == 0)
	{
		return;
	}
	this->remoteLock->shareUnlock(ctx);
	decShareCount(ctx);
}
void TrxLockContextLockHolder::updateLock(ThreadContext* ctx)
{
	if(this->updateCount > 0)
	{
		return;
	}
	if(this->shareCount > 0)
	{
		throw (new(ctx) AlinousDbException(ConstStr::getCNST_STR_3629(), ctx));
	}
	this->remoteLock->updateLock(ctx);
	incUpdateCount(ctx);
}
void TrxLockContextLockHolder::updateUnlock(ThreadContext* ctx)
{
	if(this->updateCount == 0)
	{
		return;
	}
	this->remoteLock->updateUnlock(ctx);
	decUpdateCount(ctx);
}
void TrxLockContextLockHolder::clearLocks(ThreadContext* ctx) throw() 
{
	if(this->updateCount > 0)
	{
		this->updateCount = 0;
		{
			try
			{
				this->remoteLock->updateUnlock(ctx);
			}
			catch(InterruptedException* ignore)
			{
				ignore->printStackTrace(ctx);
			}
		}
	}
	if(this->shareCount > 0)
	{
		this->shareCount = 0;
		this->remoteLock->shareUnlock(ctx);
	}
}
void TrxLockContextLockHolder::incShareCount(ThreadContext* ctx) throw() 
{
	this->shareCount ++ ;
}
void TrxLockContextLockHolder::decShareCount(ThreadContext* ctx) throw() 
{
	this->shareCount -- ;
}
void TrxLockContextLockHolder::incUpdateCount(ThreadContext* ctx) throw() 
{
	this->updateCount ++ ;
}
void TrxLockContextLockHolder::decUpdateCount(ThreadContext* ctx) throw() 
{
	this->updateCount -- ;
}
int TrxLockContextLockHolder::getShareCount(ThreadContext* ctx) throw() 
{
	return shareCount;
}
int TrxLockContextLockHolder::getUpdateCount(ThreadContext* ctx) throw() 
{
	return updateCount;
}
void TrxLockContextLockHolder::__cleanUp(ThreadContext* ctx){
}
}}}}}

