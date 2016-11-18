#include "includes.h"


namespace alinous {namespace db {namespace table {namespace lockmonitor {namespace db {





bool RowLockManagerList::__init_done = __init_static_variables();
bool RowLockManagerList::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"RowLockManagerList", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 RowLockManagerList::~RowLockManagerList() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void RowLockManagerList::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"RowLockManagerList", L"~RowLockManagerList");
	__e_obj1.add(this->list, this);
	list = nullptr;
	if(!prepare){
		return;
	}
}
RowLockManager* RowLockManagerList::getRowLockManager(IDatabaseTable* table, long long oid, BitSet* bitset, int hashcode, RowLockDb* hashDb, ConcurrentGatePool* getePool, ThreadContext* ctx) throw() 
{
	RowLockManager* mgr = 0;
	ArrayList<RowLockManager>* list = this->list;
	int maxLoop = list->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		mgr = list->get(i, ctx);
		if(mgr->table == table)
		{
			return mgr;
		}
	}
	mgr = (new(ctx) RowLockManager(table, oid, getePool->borrow(ctx), ctx));
	bitset->set(hashcode, ctx);
	this->list->add(mgr, ctx);
	return mgr;
}
RowLock* RowLockManagerList::releaseLock(IDatabaseTable* table, long long oid, BitSet* bitset, int hashcode, ThreadLocker* locker, ThreadContext* ctx) throw() 
{
	RowLockManager* mgr = nullptr;
	ArrayList<RowLockManager>* list = this->list;
	int maxLoop = list->size(ctx);
	int i = 0;
	for(; i != maxLoop; ++i)
	{
		mgr = list->get(i, ctx);
		if(mgr->table == table && mgr->oid == oid)
		{
			break ;
		}
	}
	RowLock* rowLock = mgr->releaseLock(locker, ctx);
	if(mgr->list->isEmpty(ctx))
	{
		list->remove(i, ctx);
		if(list->isEmpty(ctx))
		{
			bitset->clear(hashcode, ctx);
		}
	}
	return rowLock;
}
}}}}}

