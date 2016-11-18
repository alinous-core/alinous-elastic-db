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
	if(!prepare){
		return;
	}
}
void ThreadLocker::updateLockTable(IDatabaseTable* table, ThreadContext* ctx)
{
	table->updateLockTable(table, this, ctx);
}
void ThreadLocker::updateUnlockTable(IDatabaseTable* table, ThreadContext* ctx)
{
	table->updateUnlockTable(table, this, ctx);
}
void ThreadLocker::shareLockTable(IDatabaseTable* table, ThreadContext* ctx)
{
	table->shareLockTable(table, this, ctx);
}
void ThreadLocker::shareUnlockTable(IDatabaseTable* table, ThreadContext* ctx)
{
	table->shareUnlockTable(table, this, ctx);
}
void ThreadLocker::shareLockRow(IDatabaseTable* table, long long oid, ThreadContext* ctx)
{
	table->shareLockRow(table, oid, this, ctx);
}
void ThreadLocker::shareUnlockRow(IDatabaseTable* table, long long oid, ThreadContext* ctx)
{
	table->shareUnlockRow(table, oid, this, ctx);
}
void ThreadLocker::updateLockRow(IDatabaseTable* table, long long oid, ThreadContext* ctx)
{
	table->updateLockRow(table, oid, this, ctx);
}
void ThreadLocker::updateUnlockRow(IDatabaseTable* table, long long oid, ThreadContext* ctx)
{
	table->updateUnlockRow(table, oid, this, ctx);
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

