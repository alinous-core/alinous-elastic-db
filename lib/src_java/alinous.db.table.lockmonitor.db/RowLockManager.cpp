#include "includes.h"


namespace alinous {namespace db {namespace table {namespace lockmonitor {namespace db {





bool RowLockManager::__init_done = __init_static_variables();
bool RowLockManager::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"RowLockManager", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 RowLockManager::RowLockManager(DatabaseTable* table, long long oid, ConcurrentGate* concurrentGate, ThreadContext* ctx) throw()  : IObject(ctx), table(nullptr), oid(0), list(GCUtils<ArrayList<RowLock> >::ins(this, (new(ctx) ArrayList<RowLock>(ctx)), ctx, __FILEW__, __LINE__, L"")), concurrentGate(nullptr)
{
	__GC_MV(this, &(this->table), table, DatabaseTable);
	this->oid = oid;
	__GC_MV(this, &(this->concurrentGate), concurrentGate, ConcurrentGate);
}
void RowLockManager::__construct_impl(DatabaseTable* table, long long oid, ConcurrentGate* concurrentGate, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->table), table, DatabaseTable);
	this->oid = oid;
	__GC_MV(this, &(this->concurrentGate), concurrentGate, ConcurrentGate);
}
 RowLockManager::~RowLockManager() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void RowLockManager::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"RowLockManager", L"~RowLockManager");
	__e_obj1.add(this->table, this);
	table = nullptr;
	__e_obj1.add(this->list, this);
	list = nullptr;
	__e_obj1.add(this->concurrentGate, this);
	concurrentGate = nullptr;
	if(!prepare){
		return;
	}
}
ConcurrentGate* RowLockManager::getConcurrentGate(ThreadContext* ctx) throw() 
{
	return concurrentGate;
}
RowLock* RowLockManager::newLock(ThreadLocker* locker, bool update, ThreadContext* ctx) throw() 
{
	ArrayList<RowLock>* list = this->list;
	int maxLoop = list->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		RowLock* lock = list->get(i, ctx);
		if(lock->locker == locker)
		{
			return lock;
		}
	}
	RowLock* lock = (new(ctx) RowLock(this->table, this->oid, update, locker, this->concurrentGate, ctx));
	this->list->add(lock, ctx);
	return lock;
}
bool RowLockManager::checkDedLock(ThreadLocker* locker, ThreadContext* ctx) throw() 
{
	ArrayList<RowLock>* list = this->list;
	int maxLoop = list->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		RowLock* lock = list->get(i, ctx);
		IDatabaseLock* blockingLock = lock->locker->blockingLock;
		if(blockingLock != nullptr && locker->checkContention(blockingLock, ctx))
		{
			return true;
		}
	}
	return false;
}
RowLock* RowLockManager::releaseLock(ThreadLocker* locker, ThreadContext* ctx) throw() 
{
	ArrayList<RowLock>* list = this->list;
	int maxLoop = list->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		RowLock* lock = list->get(i, ctx);
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
}}}}}

