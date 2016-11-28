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
	__e_obj1.add(this->tableLocks, this);
	tableLocks = nullptr;
	__e_obj1.add(this->rowLocks, this);
	rowLocks = nullptr;
	if(!prepare){
		return;
	}
}
void ThreadLocker::dispose(ThreadContext* ctx)
{
	while(this->tableLocks->size(ctx) > 0)
	{
		TableLock* l = this->tableLocks->get(0, ctx);
		if(l->update)
		{
			l->table->updateUnlockTable(this, ctx);
		}
				else 
		{
			l->table->shareUnlockTable(this, ctx);
		}
	}
	while(this->rowLocks->size(ctx) > 0)
	{
		RowLock* rl = this->rowLocks->get(0, ctx);
		if(rl->update)
		{
			rl->table->updateUnlockRow(rl->oid, this, ctx);
		}
				else 
		{
			rl->table->shareUnlockRow(rl->oid, this, ctx);
		}
	}
}
void ThreadLocker::updateLockTable(IDatabaseTable* table, ThreadContext* ctx)
{
	table->updateLockTable(this, ctx);
}
void ThreadLocker::updateUnlockTable(IDatabaseTable* table, ThreadContext* ctx)
{
	table->updateUnlockTable(this, ctx);
}
void ThreadLocker::shareLockTable(IDatabaseTable* table, ThreadContext* ctx)
{
	table->shareLockTable(this, ctx);
}
void ThreadLocker::shareUnlockTable(IDatabaseTable* table, ThreadContext* ctx)
{
	table->shareUnlockTable(this, ctx);
}
void ThreadLocker::shareLockRow(IDatabaseTable* table, long long oid, ThreadContext* ctx)
{
	table->shareLockRow(oid, this, ctx);
}
void ThreadLocker::shareUnlockRow(IDatabaseTable* table, long long oid, ThreadContext* ctx)
{
	table->shareUnlockRow(oid, this, ctx);
}
void ThreadLocker::updateLockRow(IDatabaseTable* table, long long oid, ThreadContext* ctx)
{
	table->updateLockRow(oid, this, ctx);
}
void ThreadLocker::updateUnlockRow(IDatabaseTable* table, long long oid, ThreadContext* ctx)
{
	table->updateUnlockRow(oid, this, ctx);
}
ArrayList<TableLock>* ThreadLocker::getTableLocks(ThreadContext* ctx) throw() 
{
	return tableLocks;
}
ArrayList<RowLock>* ThreadLocker::getRowLocks(ThreadContext* ctx) throw() 
{
	return rowLocks;
}
}}}}

