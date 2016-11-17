#include "includes.h"


namespace alinous {namespace db {namespace table {namespace lockmonitor {





bool ThreadLocker::__init_done = __init_static_variables();
bool ThreadLocker::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"ThreadLocker", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 ThreadLocker::ThreadLocker(DBThreadMonitor* monitor, ThreadContext* ctx) throw()  : IObject(ctx), blockingLock(nullptr), tableLocks(GCUtils<ArrayList<TableLock> >::ins(this, (new(ctx) ArrayList<TableLock>(ctx)), ctx, __FILEW__, __LINE__, L"")), rowLocks(GCUtils<ArrayList<RowLock> >::ins(this, (new(ctx) ArrayList<RowLock>(ctx)), ctx, __FILEW__, __LINE__, L"")), monitor(nullptr)
{
	__GC_MV(this, &(this->monitor), monitor, DBThreadMonitor);
}
void ThreadLocker::__construct_impl(DBThreadMonitor* monitor, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->monitor), monitor, DBThreadMonitor);
}
 ThreadLocker::~ThreadLocker() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void ThreadLocker::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"ThreadLocker", L"~ThreadLocker");
	__e_obj1.add(this->blockingLock, this);
	blockingLock = nullptr;
	__e_obj1.add(this->tableLocks, this);
	tableLocks = nullptr;
	__e_obj1.add(this->rowLocks, this);
	rowLocks = nullptr;
	__e_obj1.add(this->monitor, this);
	monitor = nullptr;
	if(!prepare){
		return;
	}
}
void ThreadLocker::updateLockTable(DatabaseTable* table, ThreadContext* ctx)
{
	this->monitor->lockTable(table, this, true, ctx);
}
void ThreadLocker::updateUnlockTable(DatabaseTable* table, ThreadContext* ctx)
{
	this->monitor->unlockTable(table, this, ctx);
}
void ThreadLocker::shareLockTable(DatabaseTable* table, ThreadContext* ctx)
{
	this->monitor->lockTable(table, this, false, ctx);
}
void ThreadLocker::shareUnlockTable(DatabaseTable* table, ThreadContext* ctx)
{
	this->monitor->unlockTable(table, this, ctx);
}
void ThreadLocker::shareLockRow(DatabaseTable* table, long long oid, ThreadContext* ctx)
{
	this->monitor->lockRow(table, oid, this, false, ctx);
}
void ThreadLocker::shareUnlockRow(DatabaseTable* table, long long oid, ThreadContext* ctx)
{
	this->monitor->unlockRow(table, oid, this, ctx);
}
void ThreadLocker::updateLockRow(DatabaseTable* table, long long oid, ThreadContext* ctx)
{
	this->monitor->lockRow(table, oid, this, true, ctx);
}
void ThreadLocker::updateUnlockRow(DatabaseTable* table, long long oid, ThreadContext* ctx)
{
	this->monitor->unlockRow(table, oid, this, ctx);
}
bool ThreadLocker::checkContention(IDatabaseLock* lock, ThreadContext* ctx) throw() 
{
	int tableSize = this->tableLocks->size(ctx);
	int rowSize = this->rowLocks->size(ctx);
	if(lock->getLockType(ctx) == IDatabaseLock::TABLE_LOCK)
	{
		TableLock* blkTable = static_cast<TableLock*>(lock);
		for(int i = 0; i != tableSize; ++i)
		{
			TableLock* l = this->tableLocks->get(i, ctx);
			if((blkTable->update == false && l->update == false) || (blkTable->table != l->table))
			{
				continue;
			}
			return true;
		}
		for(int i = 0; i != rowSize; ++i)
		{
			RowLock* rl = this->rowLocks->get(i, ctx);
			if((blkTable->update == false && rl->update == false) || (blkTable->table != rl->table))
			{
				continue;
			}
			return true;
		}
	}
		else 
	{
		RowLock* blkRow = static_cast<RowLock*>(lock);
		for(int i = 0; i != tableSize; ++i)
		{
			TableLock* l = this->tableLocks->get(i, ctx);
			if((blkRow->update == false && l->update == false) || (blkRow->table != l->table))
			{
				continue;
			}
			return true;
		}
		for(int i = 0; i != rowSize; ++i)
		{
			RowLock* rl = this->rowLocks->get(i, ctx);
			if((blkRow->update == false && rl->update == false) || (blkRow->table != rl->table) || (blkRow->oid != rl->oid))
			{
				continue;
			}
			return true;
		}
	}
	return false;
}
}}}}

