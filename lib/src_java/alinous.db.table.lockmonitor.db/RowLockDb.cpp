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





bool RowLockDb::__init_done = __init_static_variables();
bool RowLockDb::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"RowLockDb", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 RowLockDb::RowLockDb(int MAX_HASH, ThreadContext* ctx) throw()  : IObject(ctx), MAX_HASH(0), MAX_HASH_MASK(0), numElements(0), arrays(nullptr), bitset(__GC_INS(this, (new(ctx) BitSet(ctx)), BitSet))
{
	this->MAX_HASH = MAX_HASH;
	this->MAX_HASH_MASK = this->MAX_HASH - 1;
	__GC_MV(this, &(this->arrays), ArrayAllocator<RowLockManagerList>::allocate(ctx, MAX_HASH), IArrayObject<RowLockManagerList>);
	for(int i = 0; i != MAX_HASH; i ++ )
	{
		arrays->set((new(ctx) RowLockManagerList(ctx)),i, ctx);
	}
}
void RowLockDb::__construct_impl(int MAX_HASH, ThreadContext* ctx) throw() 
{
	this->MAX_HASH = MAX_HASH;
	this->MAX_HASH_MASK = this->MAX_HASH - 1;
	__GC_MV(this, &(this->arrays), ArrayAllocator<RowLockManagerList>::allocate(ctx, MAX_HASH), IArrayObject<RowLockManagerList>);
	for(int i = 0; i != MAX_HASH; i ++ )
	{
		arrays->set((new(ctx) RowLockManagerList(ctx)),i, ctx);
	}
}
 RowLockDb::~RowLockDb() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void RowLockDb::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"RowLockDb", L"~RowLockDb");
	__e_obj1.add(this->arrays, this);
	arrays = nullptr;
	__e_obj1.add(this->bitset, this);
	bitset = nullptr;
	if(!prepare){
		return;
	}
}
RowLockManager* RowLockDb::getRowLockManager(IDatabaseTable* table, long long oid, ConcurrentGatePool* gatePool, ThreadContext* ctx) throw() 
{
	int hashcode = ((int)((table->getTableId(ctx)->intValue(ctx) << 8 | oid) & MAX_HASH_MASK));
	return arrays->get(hashcode)->getRowLockManager(table, oid, this->bitset, hashcode, this, gatePool, ctx);
}
RowLock* RowLockDb::releaseLock(IDatabaseTable* table, long long oid, IThreadLocker* locker, ThreadContext* ctx) throw() 
{
	int hashcode = ((int)((table->getTableId(ctx)->intValue(ctx) << 8 | oid) & MAX_HASH_MASK));
	RowLockManagerList* list = arrays->get(hashcode);
	return list->releaseLock(table, oid, this->bitset, hashcode, locker, ctx);
}
void RowLockDb::__cleanUp(ThreadContext* ctx){
}
}}}}}

