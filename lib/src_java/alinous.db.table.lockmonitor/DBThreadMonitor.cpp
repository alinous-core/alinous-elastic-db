#include "includes.h"


namespace alinous {namespace db {namespace table {namespace lockmonitor {





bool DBThreadMonitor::__init_done = __init_static_variables();
bool DBThreadMonitor::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"DBThreadMonitor", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 DBThreadMonitor::DBThreadMonitor(ThreadPool* threadPool, ThreadContext* ctx) throw()  : IObject(ctx), threads(GCUtils<ArrayList<ThreadLocker> >::ins(this, (new(ctx) ArrayList<ThreadLocker>(ctx)), ctx, __FILEW__, __LINE__, L"")), threadLock(__GC_INS(this, (new(ctx) LockObject(ctx)), LockObject)), tableLockDb(nullptr), rowLockDb(nullptr), gatePool(nullptr), threadPool(nullptr), globalLock(__GC_INS(this, (new(ctx) SpinMutex(ctx)), SpinMutex))
{
	__GC_MV(this, &(this->tableLockDb), (new(ctx) TableLockHashDb(64, ctx)), TableLockHashDb);
	__GC_MV(this, &(this->rowLockDb), (new(ctx) RowLockDb(1024 * 64, ctx)), RowLockDb);
	__GC_MV(this, &(this->gatePool), (new(ctx) ConcurrentGatePool(1000, ctx)), ConcurrentGatePool);
	__GC_MV(this, &(this->threadPool), threadPool, ThreadPool);
}
void DBThreadMonitor::__construct_impl(ThreadPool* threadPool, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->tableLockDb), (new(ctx) TableLockHashDb(64, ctx)), TableLockHashDb);
	__GC_MV(this, &(this->rowLockDb), (new(ctx) RowLockDb(1024 * 64, ctx)), RowLockDb);
	__GC_MV(this, &(this->gatePool), (new(ctx) ConcurrentGatePool(1000, ctx)), ConcurrentGatePool);
	__GC_MV(this, &(this->threadPool), threadPool, ThreadPool);
}
 DBThreadMonitor::~DBThreadMonitor() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void DBThreadMonitor::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"DBThreadMonitor", L"~DBThreadMonitor");
	__e_obj1.add(this->threads, this);
	threads = nullptr;
	__e_obj1.add(this->threadLock, this);
	threadLock = nullptr;
	__e_obj1.add(this->tableLockDb, this);
	tableLockDb = nullptr;
	__e_obj1.add(this->rowLockDb, this);
	rowLockDb = nullptr;
	__e_obj1.add(this->gatePool, this);
	gatePool = nullptr;
	__e_obj1.add(this->threadPool, this);
	threadPool = nullptr;
	__e_obj1.add(this->globalLock, this);
	globalLock = nullptr;
	if(!prepare){
		return;
	}
}
ThreadLocker* DBThreadMonitor::newThread(ThreadContext* ctx) throw() 
{
	ThreadLocker* thread = 0;
	{
		SynchronizedBlockObj __synchronized_2(this->threadLock, ctx);
		thread = (new(ctx) ThreadLocker(this, ctx));
		this->threads->add(thread, ctx);
	}
	return thread;
}
void DBThreadMonitor::lockTable(DatabaseTable* table, ThreadLocker* locker, bool update, ThreadContext* ctx)
{
	TableLockMamager* mgr = 0;
	TableLock* lock = 0;
	this->globalLock->lock(ctx);
	mgr = this->tableLockDb->getTableLockManager(table, this->gatePool, ctx);
	if(mgr->checkDedLock(locker, ctx))
	{
		globalLock->unlock(ctx);
		throw (new(ctx) DatabaseLockException(ConstStr::getCNST_STR_1582(), ctx));
	}
	lock = mgr->newLock(locker, update, ctx);
	if(lock->count > 0)
	{
		__GC_MV(locker, &(locker->blockingLock), lock, IDatabaseLock);
	}
		else 
	{
		locker->tableLocks->add(lock, ctx);
	}
	this->globalLock->unlock(ctx);
	{
		try
		{
			lock->lock(ctx);
		}
		catch(Throwable* e)
		{
			this->globalLock->lock(ctx);
			__GC_MV(locker, &(locker->blockingLock), nullptr, IDatabaseLock);
			this->globalLock->unlock(ctx);
			throw e;
		}
	}
	this->globalLock->lock(ctx);
	__GC_MV(locker, &(locker->blockingLock), nullptr, IDatabaseLock);
	this->globalLock->unlock(ctx);
}
void DBThreadMonitor::unlockTable(DatabaseTable* table, ThreadLocker* locker, ThreadContext* ctx)
{
	this->globalLock->lock(ctx);
	TableLock* lock = this->tableLockDb->releaseLock(table, locker, ctx);
	if(lock->count == 1)
	{
		locker->tableLocks->remove(lock, ctx);
	}
	this->globalLock->unlock(ctx);
	lock->unlock(this->gatePool, ctx);
}
void DBThreadMonitor::unlockRow(DatabaseTable* table, long long oid, ThreadLocker* locker, ThreadContext* ctx)
{
	RowLock* lock = nullptr;
	this->globalLock->lock(ctx);
	lock = this->rowLockDb->releaseLock(table, oid, locker, ctx);
	if(lock->count == 1)
	{
		locker->rowLocks->remove(lock, ctx);
	}
	this->globalLock->unlock(ctx);
	lock->unlock(this->gatePool, ctx);
}
void DBThreadMonitor::lockRow(DatabaseTable* table, long long oid, ThreadLocker* locker, bool update, ThreadContext* ctx)
{
	RowLockManager* mgr = 0;
	RowLock* lock = 0;
	this->globalLock->lock(ctx);
	mgr = this->rowLockDb->getRowLockManager(table, oid, this->gatePool, ctx);
	if(mgr->checkDedLock(locker, ctx))
	{
		this->globalLock->unlock(ctx);
		throw (new(ctx) DatabaseLockException(ConstStr::getCNST_STR_1582(), ctx));
	}
	lock = mgr->newLock(locker, update, ctx);
	if(lock->count > 0)
	{
		__GC_MV(locker, &(locker->blockingLock), lock, IDatabaseLock);
	}
		else 
	{
		__GC_MV(locker, &(locker->blockingLock), lock, IDatabaseLock);
		locker->rowLocks->add(lock, ctx);
	}
	this->globalLock->unlock(ctx);
	{
		try
		{
			lock->lock(ctx);
		}
		catch(Throwable* e)
		{
			this->globalLock->lock(ctx);
			__GC_MV(locker, &(locker->blockingLock), nullptr, IDatabaseLock);
			this->globalLock->unlock(ctx);
			throw e;
		}
	}
	this->globalLock->lock(ctx);
	__GC_MV(locker, &(locker->blockingLock), nullptr, IDatabaseLock);
	this->globalLock->unlock(ctx);
}
ThreadPool* DBThreadMonitor::getThreadPool(ThreadContext* ctx) throw() 
{
	return threadPool;
}
}}}}

