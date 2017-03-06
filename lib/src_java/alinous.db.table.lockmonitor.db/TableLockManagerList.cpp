#include "include/global.h"


#include "java.util/BitSet.h"
#include "alinous.db.table.lockmonitor/ConcurrentGatePool.h"
#include "alinous.db.table.lockmonitor/IDatabaseLock.h"
#include "alinous.db.table.lockmonitor/TableLock.h"
#include "alinous.db.table.lockmonitor/RowLock.h"
#include "alinous.db.table.lockmonitor/IThreadLocker.h"
#include "alinous.db.table/IDatabaseTable.h"
#include "alinous.db.table.lockmonitor.db/RowLockManager.h"
#include "alinous.db.table.lockmonitor.db/RowLockManagerList.h"
#include "alinous.db.table.lockmonitor.db/RowLockDb.h"
#include "alinous.db.table.lockmonitor.db/TableLockMamager.h"
#include "alinous.db.table.lockmonitor.db/TableLockManagerList.h"
#include "alinous.db.table.lockmonitor.db/TableLockHashDb.h"

namespace alinous {namespace db {namespace table {namespace lockmonitor {namespace db {





bool TableLockManagerList::__init_done = __init_static_variables();
bool TableLockManagerList::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"TableLockManagerList", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 TableLockManagerList::TableLockManagerList(ThreadContext* ctx) throw()  : IObject(ctx), list(GCUtils<ArrayList<TableLockMamager> >::ins(this, (new(ctx) ArrayList<TableLockMamager>(ctx)), ctx, __FILEW__, __LINE__, L""))
{
}
void TableLockManagerList::__construct_impl(ThreadContext* ctx) throw() 
{
}
 TableLockManagerList::~TableLockManagerList() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void TableLockManagerList::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"TableLockManagerList", L"~TableLockManagerList");
	__e_obj1.add(this->list, this);
	list = nullptr;
	if(!prepare){
		return;
	}
}
TableLockMamager* TableLockManagerList::getTableLockmanager(IDatabaseTable* table, BitSet* bitset, int hashcode, TableLockHashDb* hashDb, ConcurrentGatePool* gatePool, ThreadContext* ctx) throw() 
{
	TableLockMamager* mgr = 0;
	int maxLoop = this->list->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		mgr = this->list->get(i, ctx);
		if(mgr->getTable(ctx) == table)
		{
			return mgr;
		}
	}
	mgr = (new(ctx) TableLockMamager(table, gatePool->borrow(ctx), ctx));
	bitset->set(hashcode, ctx);
	this->list->add(mgr, ctx);
	hashDb->inc(ctx);
	return mgr;
}
TableLock* TableLockManagerList::releaseLock(IDatabaseTable* table, BitSet* bitset, int hashcode, IThreadLocker* locker, ThreadContext* ctx) throw() 
{
	TableLockMamager* mgr = nullptr;
	int maxLoop = this->list->size(ctx);
	int i = 0;
	for(; i != maxLoop; ++i)
	{
		mgr = this->list->get(i, ctx);
		if(mgr->getTable(ctx) == table)
		{
			break ;
		}
	}
	TableLock* tblLock = mgr->releaseLock(locker, ctx);
	if(mgr->list->isEmpty(ctx))
	{
		this->list->remove(i, ctx);
		if(this->list->isEmpty(ctx))
		{
			bitset->clear(hashcode, ctx);
		}
		tblLock->pushBack = true;
	}
	return tblLock;
}
void TableLockManagerList::__cleanUp(ThreadContext* ctx){
}
}}}}}

