#include "includes.h"


namespace alinous {namespace db {namespace table {namespace cache {





bool DbRecordHashMainList::__init_done = __init_static_variables();
bool DbRecordHashMainList::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"DbRecordHashMainList", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 DbRecordHashMainList::~DbRecordHashMainList() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void DbRecordHashMainList::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"DbRecordHashMainList", L"~DbRecordHashMainList");
	__e_obj1.add(this->arrays, this);
	arrays = nullptr;
	__e_obj1.add(this->bitset, this);
	bitset = nullptr;
	if(!prepare){
		return;
	}
}
DbRecordHashMainList* DbRecordHashMainList::init(int MAX_HASH, ThreadContext* ctx)
{
	if((MAX_HASH & 1) != 0)
	{
		throw (new(ctx) AlinousException(ConstStr::getCNST_STR_1554(), ctx));
	}
	this->MAX_HASH = MAX_HASH;
	this->MAX_HASH_MASK = this->MAX_HASH - 1;
	__GC_MV(this, &(this->arrays), ArrayAllocator<DbRecordHashArray>::allocate(ctx, MAX_HASH), IArrayObject<DbRecordHashArray>);
	for(int i = 0; i != MAX_HASH; i ++ )
	{
		arrays->set((new(ctx) DbRecordHashArray(4, ctx)),i, ctx);
	}
	return this;
}
int DbRecordHashMainList::size(ThreadContext* ctx) throw() 
{
	return this->numElements;
}
DatabaseRecord* DbRecordHashMainList::addElement(DatabaseRecord* ptr, ThreadContext* ctx) throw() 
{
	int hashcode = ((int)(ptr->getHashKey(ctx) & MAX_HASH_MASK));
	arrays->get(hashcode)->add(ptr, ctx);
	bitset->set(hashcode, ctx);
	++numElements;
	return ptr;
}
bool DbRecordHashMainList::removeByObj(DatabaseRecord* obj, ThreadContext* ctx) throw() 
{
	int hashcode = ((int)(obj->getHashKey(ctx) & MAX_HASH_MASK));
	bool result = arrays->get(hashcode)->removeByObj(obj, ctx);
	if(result)
	{
		--numElements;
	}
	if(arrays->get(hashcode)->size(ctx) == 0)
	{
		bitset->clear(hashcode, ctx);
	}
	return result;
}
DatabaseRecord* DbRecordHashMainList::search(DataTableStorageSupport* table, long long position, ThreadContext* ctx) throw() 
{
	int hashcode = ((int)(((unsigned long long)((position + table->getTableId(ctx)->intValue(ctx)) * 2654404609L))>> 32));
	hashcode = hashcode & MAX_HASH_MASK;
	return arrays->get(hashcode)->search(table, position, ctx);
}
void DbRecordHashMainList::reset(ThreadContext* ctx) throw() 
{
	for(int i = 0; i != MAX_HASH; i ++ )
	{
		arrays->get(i)->reset(ctx);
	}
	bitset->clear(ctx);
	numElements = 0;
}
DbREcordHashListIterator* DbRecordHashMainList::iterator(ThreadContext* ctx) throw() 
{
	return (new(ctx) DbREcordHashListIterator(arrays, bitset, MAX_HASH, ctx));
}
}}}}

