#include "include/global.h"


#include "alinous.db.table/DatabaseException.h"
#include "alinous.db.table.lockmonitor/DatabaseLockException.h"
#include "alinous.lock/ConcurrentGate.h"
#include "alinous.db.table.lockmonitor/ConcurrentGatePool.h"
#include "alinous.db.table.lockmonitor/IDatabaseLock.h"
#include "alinous.db.table.lockmonitor/TableLock.h"
#include "alinous.db.table.lockmonitor/RowLock.h"
#include "alinous.db.table.lockmonitor/IThreadLocker.h"
#include "alinous.runtime.parallel/ThreadPool.h"
#include "alinous.db.table/IDatabaseTable.h"
#include "alinous.db.table.lockmonitor/ThreadLocker.h"
#include "alinous.db.table.lockmonitor.db/RowLockDb.h"
#include "alinous.db.table.lockmonitor.db/TableLockHashDb.h"
#include "alinous.db.table.lockmonitor/DBThreadMonitor.h"
#include "alinous.runtime.parallel/IThreadAction.h"
#include "alinous.db.table.lockmonitor/RowLockReleaser.h"

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
 ThreadLocker::ThreadLocker(String* fullName, ThreadContext* ctx) throw()  : IObject(ctx), IThreadLocker(ctx), tableLocks(GCUtils<ArrayList<TableLock> >::ins(this, (new(ctx) ArrayList<TableLock>(ctx)), ctx, __FILEW__, __LINE__, L"")), rowLocks(GCUtils<ArrayList<RowLock> >::ins(this, (new(ctx) ArrayList<RowLock>(ctx)), ctx, __FILEW__, __LINE__, L"")), fullName(nullptr)
{
	__GC_MV(this, &(this->fullName), fullName, String);
}
void ThreadLocker::__construct_impl(String* fullName, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->fullName), fullName, String);
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
	__e_obj1.add(this->fullName, this);
	fullName = nullptr;
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
String* ThreadLocker::getFullName(ThreadContext* ctx) throw() 
{
	return fullName;
}
void ThreadLocker::__cleanUp(ThreadContext* ctx){
}
}}}}

