#include "includes.h"


namespace alinous {namespace lock {





bool UpgreadableGate::__init_done = __init_static_variables();
bool UpgreadableGate::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"UpgreadableGate", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 UpgreadableGate::UpgreadableGate(ThreadContext* ctx) throw()  : IObject(ctx), upgradeLock(__GC_INS(this, (new(ctx) LockObject(ctx)), LockObject)), stateLock(__GC_INS(this, (new(ctx) LockObject(ctx)), LockObject)), counter(0), isOpened(0), disposed(0), list(GCUtils<LinkedList<Thread> >::ins(this, (new(ctx) LinkedList<Thread>(ctx)), ctx, __FILEW__, __LINE__, L"")), cancelList(GCUtils<ArrayList<Thread> >::ins(this, (new(ctx) ArrayList<Thread>(ctx)), ctx, __FILEW__, __LINE__, L"")), listLock(__GC_INS(this, (new(ctx) LockObject(ctx)), LockObject)), executingUpdate(nullptr)
{
	this->counter = 0;
	this->isOpened = true;
	this->disposed = false;
}
void UpgreadableGate::__construct_impl(ThreadContext* ctx) throw() 
{
	this->counter = 0;
	this->isOpened = true;
	this->disposed = false;
}
 UpgreadableGate::~UpgreadableGate() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void UpgreadableGate::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"UpgreadableGate", L"~UpgreadableGate");
	__e_obj1.add(this->upgradeLock, this);
	upgradeLock = nullptr;
	__e_obj1.add(this->stateLock, this);
	stateLock = nullptr;
	__e_obj1.add(this->list, this);
	list = nullptr;
	__e_obj1.add(this->cancelList, this);
	cancelList = nullptr;
	__e_obj1.add(this->listLock, this);
	listLock = nullptr;
	__e_obj1.add(this->executingUpdate, this);
	executingUpdate = nullptr;
	if(!prepare){
		return;
	}
}
void UpgreadableGate::dispose(ThreadContext* ctx) throw() 
{
	{
		SynchronizedBlockObj __synchronized_2(listLock, ctx);
		this->disposed = true;
		this->listLock->notifyAll(ctx);
	}
}
void UpgreadableGate::enter(ThreadContext* ctx)
{
	{
		SynchronizedBlockObj __synchronized_2(stateLock, ctx);
		while(!isOpened)
		{
			stateLock->wait(ctx);
		}
		this->counter ++ ;
	}
}
void UpgreadableGate::exit(ThreadContext* ctx) throw() 
{
	{
		SynchronizedBlockObj __synchronized_2(stateLock, ctx);
		this->counter -- ;
		if(this->counter == 0)
		{
			stateLock->notifyAll(ctx);
		}
	}
}
void UpgreadableGate::upgrade(ThreadContext* ctx)
{
	reserve(ctx);
	execClose(true, ctx);
}
void UpgreadableGate::reserve(ThreadContext* ctx) throw() 
{
	Thread* thread = Thread::currentThread(ctx);
	{
		SynchronizedBlockObj __synchronized_2(listLock, ctx);
		{
			SynchronizedBlockObj __synchronized_3(stateLock, ctx);
			if(this->executingUpdate != nullptr)
			{
				this->cancelList->add(this->executingUpdate, ctx);
				this->list->add(1, thread, ctx);
			}
						else 
			{
				this->list->add(0, thread, ctx);
			}
			this->counter -- ;
			this->stateLock->notifyAll(ctx);
		}
	}
}
void UpgreadableGate::downgrade(ThreadContext* ctx)
{
	reserveShare(ctx);
	open(ctx);
}
void UpgreadableGate::close(ThreadContext* ctx)
{
	Thread* thread = Thread::currentThread(ctx);
	bool added = false;
	bool retry = false;
	do
	{
		{
			SynchronizedBlockObj __synchronized_3(listLock, ctx);
			if(!added)
			{
				this->list->add(thread, ctx);
				added = true;
			}
			while(true)
			{
				Thread* firstThread = list->get(0, ctx);
				if(firstThread->getId(ctx) == thread->getId(ctx))
				{
					{
						SynchronizedBlockObj __synchronized_6(stateLock, ctx);
						__GC_MV(this, &(this->executingUpdate), firstThread, Thread);
					}
					break ;
				}
				listLock->wait(ctx);
				if(this->disposed)
				{
					throw (new(ctx) InterruptedException(ctx));
				}
			}
		}
		retry = doclose(thread, ctx);
	}
	while(retry);
}
void UpgreadableGate::open(ThreadContext* ctx)
{
	{
		SynchronizedBlockObj __synchronized_2(this->stateLock, ctx);
		this->isOpened = true;
		this->stateLock->notifyAll(ctx);
	}
	{
		SynchronizedBlockObj __synchronized_2(listLock, ctx);
		list->remove(0, ctx);
		listLock->notifyAll(ctx);
	}
}
void UpgreadableGate::reserveShare(ThreadContext* ctx) throw() 
{
	{
		SynchronizedBlockObj __synchronized_2(stateLock, ctx);
		this->counter ++ ;
	}
}
void UpgreadableGate::execClose(bool added, ThreadContext* ctx)
{
	Thread* thread = Thread::currentThread(ctx);
	if(!added)
	{
		{
			SynchronizedBlockObj __synchronized_3(listLock, ctx);
			this->list->add(thread, ctx);
		}
	}
	bool retry = false;
	do
	{
		{
			SynchronizedBlockObj __synchronized_3(listLock, ctx);
			while(true)
			{
				Thread* firstThread = list->get(0, ctx);
				if(firstThread->getId(ctx) == thread->getId(ctx))
				{
					{
						SynchronizedBlockObj __synchronized_6(stateLock, ctx);
						__GC_MV(this, &(this->executingUpdate), firstThread, Thread);
					}
					break ;
				}
				listLock->wait(ctx);
				if(this->disposed)
				{
					throw (new(ctx) InterruptedException(ctx));
				}
			}
		}
		retry = doclose(thread, ctx);
	}
	while(retry);
}
bool UpgreadableGate::doclose(Thread* currentthread, ThreadContext* ctx)
{
	{
		SynchronizedBlockObj __synchronized_2(stateLock, ctx);
		this->isOpened = false;
		if(this->counter != 0)
		{
			this->stateLock->wait(ctx);
		}
		__GC_MV(this, &(this->executingUpdate), nullptr, Thread);
	}
	{
		SynchronizedBlockObj __synchronized_2(listLock, ctx);
		long long thisId = currentthread->getId(ctx);
		int maxLoop = this->cancelList->size(ctx);
		for(int i = 0; i != maxLoop; ++i)
		{
			Thread* thread = this->cancelList->get(i, ctx);
			if(thread->getId(ctx) == thisId)
			{
				this->cancelList->remove(i, ctx);
				this->list->remove(0, ctx);
				this->list->add(currentthread, ctx);
				listLock->notifyAll(ctx);
				return true;
			}
		}
	}
	return false;
}
}}

