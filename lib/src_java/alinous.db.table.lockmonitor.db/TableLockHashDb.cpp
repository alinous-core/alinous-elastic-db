#include "includes.h"


namespace alinous {namespace db {namespace table {namespace lockmonitor {namespace db {





bool TableLockHashDb::__init_done = __init_static_variables();
bool TableLockHashDb::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"TableLockHashDb", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 TableLockHashDb::TableLockHashDb(int MAX_HASH, ThreadContext* ctx) throw()  : IObject(ctx), MAX_HASH(0), MAX_HASH_MASK(0), arrays(nullptr), bitset(__GC_INS(this, (new(ctx) BitSet(ctx)), BitSet)), numElements(0)
{
	this->MAX_HASH = MAX_HASH;
	this->MAX_HASH_MASK = this->MAX_HASH - 1;
	__GC_MV(this, &(this->arrays), ArrayAllocator<TableLockManagerList>::allocate(ctx, MAX_HASH), IArrayObject<TableLockManagerList>);
	for(int i = 0; i != MAX_HASH; i ++ )
	{
		arrays->set((new(ctx) TableLockManagerList(ctx)),i, ctx);
	}
}
void TableLockHashDb::__construct_impl(int MAX_HASH, ThreadContext* ctx) throw() 
{
	this->MAX_HASH = MAX_HASH;
	this->MAX_HASH_MASK = this->MAX_HASH - 1;
	__GC_MV(this, &(this->arrays), ArrayAllocator<TableLockManagerList>::allocate(ctx, MAX_HASH), IArrayObject<TableLockManagerList>);
	for(int i = 0; i != MAX_HASH; i ++ )
	{
		arrays->set((new(ctx) TableLockManagerList(ctx)),i, ctx);
	}
}
 TableLockHashDb::~TableLockHashDb() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void TableLockHashDb::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"TableLockHashDb", L"~TableLockHashDb");
	__e_obj1.add(this->arrays, this);
	arrays = nullptr;
	__e_obj1.add(this->bitset, this);
	bitset = nullptr;
	if(!prepare){
		return;
	}
}
int TableLockHashDb::size(ThreadContext* ctx) throw() 
{
	return this->numElements;
}
void TableLockHashDb::inc(ThreadContext* ctx) throw() 
{
	this->numElements ++ ;
}
TableLockMamager* TableLockHashDb::getTableLockManager(DatabaseTable* table, ConcurrentGatePool* gatePool, ThreadContext* ctx) throw() 
{
	int hashcode = ((int)(table->tableId->intValue(ctx) & MAX_HASH_MASK));
	return arrays->get(hashcode)->getTableLockmanager(table, this->bitset, hashcode, this, gatePool, ctx);
}
TableLock* TableLockHashDb::releaseLock(DatabaseTable* table, ThreadLocker* locker, ThreadContext* ctx) throw() 
{
	int hashcode = ((int)(table->tableId->intValue(ctx) & MAX_HASH_MASK));
	TableLockManagerList* list = arrays->get(hashcode);
	return list->releaseLock(table, this->bitset, hashcode, locker, ctx);
}
}}}}}

