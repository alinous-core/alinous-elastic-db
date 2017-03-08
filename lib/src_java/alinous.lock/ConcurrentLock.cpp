#include "include/global.h"


#include "alinous.lock/ILock.h"
#include "alinous.lock/IConcurrentLockManager.h"
#include "alinous.lock/UpdateLock.h"
#include "alinous.lock/ShareLock.h"
#include "alinous.lock/ConcurrentLock.h"

namespace alinous {namespace lock {





bool ConcurrentLock::__init_done = __init_static_variables();
bool ConcurrentLock::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"ConcurrentLock", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 ConcurrentLock::ConcurrentLock(ThreadContext* ctx) throw()  : IObject(ctx), IConcurrentLockManager(ctx), ThreadMonitor(ctx), currentLock(nullptr), sem(nullptr), shareCount(0), maxShare(0), updWaitCnt(0)
{
	__GC_MV(this, &(sem), (new(ctx) Mutex(ctx)), Mutex);
	this->shareCount = 0;
	this->maxShare = 5;
	this->updWaitCnt = 0;
}
void ConcurrentLock::__construct_impl(ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(sem), (new(ctx) Mutex(ctx)), Mutex);
	this->shareCount = 0;
	this->maxShare = 5;
	this->updWaitCnt = 0;
}
 ConcurrentLock::~ConcurrentLock() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void ConcurrentLock::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"ConcurrentLock", L"~ConcurrentLock");
	__e_obj1.add(this->currentLock, this);
	currentLock = nullptr;
	__e_obj1.add(this->sem, this);
	sem = nullptr;
	if(!prepare){
		return;
	}
}
UpdateLock* ConcurrentLock::updateLock(ThreadContext* ctx)
{
	ILock* lock = tryLock(true, ctx);
	return static_cast<UpdateLock*>(lock);
}
void ConcurrentLock::endUpdateLock(ThreadContext* ctx)
{
	sem->lock(ctx);
	{
		__GC_MV(this, &(this->currentLock), nullptr, ILock);
	}
	sem->unlock(ctx);
	{
		SynchronizedBlockObj __synchronized_2(this, ctx);
		notifyAll(ctx);
	}
}
ShareLock* ConcurrentLock::shareLock(ThreadContext* ctx)
{
	ILock* lock = tryLock(false, ctx);
	{
		SynchronizedBlockObj __synchronized_2(this, ctx);
		notifyAll(ctx);
	}
	return static_cast<ShareLock*>(lock);
}
void ConcurrentLock::endShareLock(ThreadContext* ctx)
{
	sem->lock(ctx);
	{
		int cnt = (static_cast<ShareLock*>(this->currentLock))->dec(ctx);
		if(cnt == 0)
		{
			__GC_MV(this, &(this->currentLock), nullptr, ILock);
		}
	}
	sem->unlock(ctx);
	{
		SynchronizedBlockObj __synchronized_2(this, ctx);
		notifyAll(ctx);
	}
}
ILock* ConcurrentLock::tryLock(bool upd, ThreadContext* ctx)
{
	while(true)
	{
		sem->lock(ctx);
		{
			if(upd)
			{
				if(this->currentLock == nullptr)
				{
					__GC_MV(this, &(this->currentLock), (new(ctx) UpdateLock(this, ctx)), ILock);
					this->updWaitCnt = 0;
					this->shareCount = 0;
					sem->unlock(ctx);
					return this->currentLock;
				}
								else 
				{
					this->updWaitCnt ++ ;
				}
			}
						else 
			{
				if(this->updWaitCnt <= 0 || this->shareCount < this->maxShare)
				{
					if(this->currentLock == nullptr)
					{
						__GC_MV(this, &(this->currentLock), (new(ctx) ShareLock(this, ctx)), ILock);
						this->shareCount ++ ;
						sem->unlock(ctx);
						return this->currentLock;
					}
										else 
					{
						if((dynamic_cast<ShareLock*>(this->currentLock) != 0))
						{
							(static_cast<ShareLock*>(this->currentLock))->inc(ctx);
							this->shareCount ++ ;
							sem->unlock(ctx);
							return this->currentLock;
						}
					}
				}
			}
		}
		sem->unlock(ctx);
		{
			SynchronizedBlockObj __synchronized_3(this, ctx);
			wait(ctx);
		}
	}
}
void ConcurrentLock::__cleanUp(ThreadContext* ctx){
}
}}

