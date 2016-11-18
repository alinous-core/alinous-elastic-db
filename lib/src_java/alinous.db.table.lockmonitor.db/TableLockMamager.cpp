#include "includes.h"


namespace alinous {namespace db {namespace table {namespace lockmonitor {namespace db {





bool TableLockMamager::__init_done = __init_static_variables();
bool TableLockMamager::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"TableLockMamager", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 TableLockMamager::TableLockMamager(IDatabaseTable* table, ConcurrentGate* gate, ThreadContext* ctx) throw()  : IObject(ctx), list(GCUtils<ArrayList<TableLock> >::ins(this, (new(ctx) ArrayList<TableLock>(ctx)), ctx, __FILEW__, __LINE__, L"")), table(nullptr), gate(nullptr)
{
	__GC_MV(this, &(this->table), table, IDatabaseTable);
	__GC_MV(this, &(this->gate), gate, ConcurrentGate);
}
void TableLockMamager::__construct_impl(IDatabaseTable* table, ConcurrentGate* gate, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->table), table, IDatabaseTable);
	__GC_MV(this, &(this->gate), gate, ConcurrentGate);
}
 TableLockMamager::~TableLockMamager() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void TableLockMamager::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"TableLockMamager", L"~TableLockMamager");
	__e_obj1.add(this->list, this);
	list = nullptr;
	__e_obj1.add(this->table, this);
	table = nullptr;
	__e_obj1.add(this->gate, this);
	gate = nullptr;
	if(!prepare){
		return;
	}
}
IDatabaseTable* TableLockMamager::getTable(ThreadContext* ctx) throw() 
{
	return this->table;
}
TableLock* TableLockMamager::newLock(ThreadLocker* locker, bool update, ThreadContext* ctx) throw() 
{
	ArrayList<TableLock>* list = this->list;
	int maxLoop = list->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		TableLock* lock = list->get(i, ctx);
		if(lock->locker == locker)
		{
			return lock;
		}
	}
	return (new(ctx) TableLock(update, this->table, locker, this->gate, ctx));
}
TableLock* TableLockMamager::releaseLock(ThreadLocker* locker, ThreadContext* ctx) throw() 
{
	ArrayList<TableLock>* list = this->list;
	int maxLoop = list->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		TableLock* lock = list->get(i, ctx);
		if(lock->locker == locker)
		{
			if(lock->count == 1)
			{
				this->list->remove(i, ctx);
			}
			return lock;
		}
	}
	return nullptr;
}
bool TableLockMamager::checkDedLock(ThreadLocker* locker, ThreadContext* ctx) throw() 
{
	ArrayList<TableLock>* list = this->list;
	int maxLoop = list->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		TableLock* lock = list->get(i, ctx);
		IDatabaseLock* blockingLock = lock->locker->blockingLock;
		if(blockingLock != nullptr && locker->checkContention(blockingLock, ctx))
		{
			return true;
		}
	}
	return false;
}
}}}}}

