#include "include/global.h"


#include "alinous.db.table.lockmonitor/ConcurrentGatePool.h"
#include "alinous.db.table.lockmonitor/IDatabaseLock.h"
#include "alinous.db.table.lockmonitor/TableLock.h"
#include "alinous.db.table.lockmonitor/RowLock.h"
#include "alinous.db.table.lockmonitor/IThreadLocker.h"
#include "alinous.runtime.parallel/ThreadPool.h"
#include "alinous.db.table/IDatabaseTable.h"
#include "alinous.db.table.lockmonitor.db/RowLockManager.h"
#include "alinous.db.table.lockmonitor.db/RowLockDb.h"
#include "alinous.db.table.lockmonitor.db/TableLockMamager.h"
#include "alinous.db.table.lockmonitor.db/TableLockHashDb.h"
#include "alinous.db.table.lockmonitor/ThreadLocker.h"
#include "alinous.db.table.lockmonitor/DBThreadMonitor.h"

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
 DBThreadMonitor::DBThreadMonitor(ThreadPool* threadPool, ThreadContext* ctx) throw()  : IObject(ctx), tableLockDb(nullptr), rowLockDb(nullptr), gatePool(nullptr), threadPool(nullptr), globalLock(__GC_INS(this, (new(ctx) SpinMutex(ctx)), SpinMutex))
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
IThreadLocker* DBThreadMonitor::newThread(String* fullName, ThreadContext* ctx) throw() 
{
	return (new(ctx) ThreadLocker(fullName, ctx));
}
void DBThreadMonitor::lockTable(IDatabaseTable* table, IThreadLocker* locker, bool update, ThreadContext* ctx)
{
	TableLockMamager* mgr = 0;
	TableLock* lock = 0;
	this->globalLock->lock(ctx);
	mgr = this->tableLockDb->getTableLockManager(table, this->gatePool, ctx);
	lock = mgr->newLock(locker, update, ctx);
	locker->getTableLocks(ctx)->add(lock, ctx);
	this->globalLock->unlock(ctx);
	{
		try
		{
			lock->lock(ctx);
		}
		catch(Throwable* e)
		{
			this->globalLock->lock(ctx);
			this->globalLock->unlock(ctx);
			throw e;
		}
	}
	this->globalLock->lock(ctx);
	this->globalLock->unlock(ctx);
}
void DBThreadMonitor::unlockTable(IDatabaseTable* table, IThreadLocker* locker, ThreadContext* ctx)
{
	this->globalLock->lock(ctx);
	TableLock* lock = this->tableLockDb->releaseLock(table, locker, ctx);
	if(lock->count == 1)
	{
		locker->getTableLocks(ctx)->remove(lock, ctx);
	}
	this->globalLock->unlock(ctx);
	lock->unlock(this->gatePool, ctx);
}
void DBThreadMonitor::unlockRow(IDatabaseTable* table, long long oid, IThreadLocker* locker, ThreadContext* ctx)
{
	RowLock* lock = nullptr;
	this->globalLock->lock(ctx);
	lock = this->rowLockDb->releaseLock(table, oid, locker, ctx);
	if(lock->count == 1)
	{
		locker->getRowLocks(ctx)->remove(lock, ctx);
	}
	this->globalLock->unlock(ctx);
	lock->unlock(this->gatePool, ctx);
}
void DBThreadMonitor::lockRow(IDatabaseTable* table, long long oid, IThreadLocker* locker, bool update, ThreadContext* ctx)
{
	RowLockManager* mgr = 0;
	RowLock* lock = 0;
	this->globalLock->lock(ctx);
	mgr = this->rowLockDb->getRowLockManager(table, oid, this->gatePool, ctx);
	lock = mgr->newLock(locker, update, ctx);
	locker->getRowLocks(ctx)->add(lock, ctx);
	this->globalLock->unlock(ctx);
	{
		try
		{
			lock->lock(ctx);
		}
		catch(Throwable* e)
		{
			this->globalLock->lock(ctx);
			this->globalLock->unlock(ctx);
			throw e;
		}
	}
}
ThreadPool* DBThreadMonitor::getThreadPool(ThreadContext* ctx) throw() 
{
	return threadPool;
}
void DBThreadMonitor::__cleanUp(ThreadContext* ctx){
}
}}}}

