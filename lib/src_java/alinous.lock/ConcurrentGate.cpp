#include "include/global.h"


#include "alinous.lock/ILock.h"
#include "alinous.lock/IConcurrentLockManager.h"
#include "alinous.lock/UpdateLock.h"
#include "alinous.lock/ShareLock.h"
#include "alinous.lock/ConcurrentLock.h"
#include "alinous.lock/LockObject.h"
#include "alinous.lock/UpgreadableGate.h"
#include "alinous.lock/CriticalSectionMarkerException.h"
#include "alinous.lock/CriticalSectionMarker.h"
#include "alinous.lock/ConcurrentGate.h"

namespace alinous {namespace lock {





bool ConcurrentGate::__init_done = __init_static_variables();
bool ConcurrentGate::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"ConcurrentGate", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 ConcurrentGate::ConcurrentGate(ThreadContext* ctx) throw()  : IObject(ctx), isOpened(0), counter(0), roomWaiter(0), doorKeeperLock(__GC_INS(this, (new(ctx) Mutex(ctx)), Mutex)), stateLock(__GC_INS(this, (new(ctx) LockObject(ctx)), LockObject)), roomLock(__GC_INS(this, (new(ctx) LockObject(ctx)), LockObject))
{
	this->isOpened = true;
	this->counter = 0;
	this->roomWaiter = 0;
}
void ConcurrentGate::__construct_impl(ThreadContext* ctx) throw() 
{
	this->isOpened = true;
	this->counter = 0;
	this->roomWaiter = 0;
}
 ConcurrentGate::~ConcurrentGate() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void ConcurrentGate::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"ConcurrentGate", L"~ConcurrentGate");
	__e_obj1.add(this->doorKeeperLock, this);
	doorKeeperLock = nullptr;
	__e_obj1.add(this->stateLock, this);
	stateLock = nullptr;
	__e_obj1.add(this->roomLock, this);
	roomLock = nullptr;
	if(!prepare){
		return;
	}
}
void ConcurrentGate::enter(ThreadContext* ctx)
{
	{
		SynchronizedBlockObj __synchronized_2(this->stateLock, ctx);
		if(this->isOpened)
		{
			this->counter ++ ;
		}
				else 
		{
			{
				SynchronizedBlockObj __synchronized_4(this->roomLock, ctx);
				this->roomWaiter ++ ;
			}
			this->stateLock->wait(ctx);
			{
				SynchronizedBlockObj __synchronized_4(this->roomLock, ctx);
				this->roomWaiter -- ;
				if(this->roomWaiter == 0)
				{
					this->roomLock->notify(ctx);
				}
			}
			this->counter ++ ;
		}
	}
}
void ConcurrentGate::open(ThreadContext* ctx)
{
	{
		SynchronizedBlockObj __synchronized_2(this->stateLock, ctx);
		this->isOpened = true;
		this->stateLock->notifyAll(ctx);
	}
	{
		SynchronizedBlockObj __synchronized_2(this->roomLock, ctx);
		if(this->roomWaiter > 0)
		{
			this->roomLock->wait(ctx);
		}
	}
	doorKeeperLock->unlock(ctx);
}
void ConcurrentGate::exit(ThreadContext* ctx) throw() 
{
	{
		SynchronizedBlockObj __synchronized_2(this->stateLock, ctx);
		this->counter -- ;
		if(this->counter == 0)
		{
			this->stateLock->notify(ctx);
		}
	}
}
void ConcurrentGate::close(ThreadContext* ctx)
{
	doorKeeperLock->lock(ctx);
	{
		SynchronizedBlockObj __synchronized_2(this->stateLock, ctx);
		this->isOpened = false;
		if(this->counter > 0)
		{
			this->stateLock->wait(ctx);
		}
	}
}
void ConcurrentGate::dispose(ThreadContext* ctx) throw() 
{
}
void ConcurrentGate::__cleanUp(ThreadContext* ctx){
}
}}

