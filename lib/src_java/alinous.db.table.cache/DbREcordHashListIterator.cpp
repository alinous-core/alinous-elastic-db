#include "includes.h"


namespace alinous {namespace db {namespace table {namespace cache {





bool DbREcordHashListIterator::__init_done = __init_static_variables();
bool DbREcordHashListIterator::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"DbREcordHashListIterator", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 DbREcordHashListIterator::DbREcordHashListIterator(IArrayObject<DbRecordHashArray>* arrays, BitSet* bitset, long long MAX_HASH, ThreadContext* ctx) throw()  : IObject(ctx), MAX_HASH(0), hashCode(0), index(0), arrays(nullptr), bitset(nullptr)
{
	this->MAX_HASH = MAX_HASH;
	this->hashCode = 0;
	this->index = 0;
	__GC_MV(this, &(this->arrays), arrays, IArrayObject<DbRecordHashArray>);
	__GC_MV(this, &(this->bitset), bitset, BitSet);
}
void DbREcordHashListIterator::__construct_impl(IArrayObject<DbRecordHashArray>* arrays, BitSet* bitset, long long MAX_HASH, ThreadContext* ctx) throw() 
{
	this->MAX_HASH = MAX_HASH;
	this->hashCode = 0;
	this->index = 0;
	__GC_MV(this, &(this->arrays), arrays, IArrayObject<DbRecordHashArray>);
	__GC_MV(this, &(this->bitset), bitset, BitSet);
}
 DbREcordHashListIterator::~DbREcordHashListIterator() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void DbREcordHashListIterator::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"DbREcordHashListIterator", L"~DbREcordHashListIterator");
	__e_obj1.add(this->arrays, this);
	arrays = nullptr;
	__e_obj1.add(this->bitset, this);
	bitset = nullptr;
	if(!prepare){
		return;
	}
}
bool DbREcordHashListIterator::hasNext(ThreadContext* ctx) throw() 
{
	DbRecordHashArray* current = arrays->get(hashCode);
	if(current->size(ctx) == index)
	{
		int nextHash = hashCode + 1;
		if(nextHash == (int)MAX_HASH)
		{
			return false;
		}
		int next = bitset->nextSetBit(nextHash, ctx);
		if(next < 0)
		{
			return false;
		}
		return true;
	}
	return true;
}
DatabaseRecord* DbREcordHashListIterator::next(ThreadContext* ctx) throw() 
{
	DbRecordHashArray* current = arrays->get(hashCode);
	if(current->size(ctx) == index)
	{
		int nextHash = hashCode + 1;
		int next = bitset->nextSetBit(nextHash, ctx);
		if(nextHash == (int)MAX_HASH || next < 0)
		{
			return nullptr;
		}
		index = 0;
		hashCode = next;
	}
	current = arrays->get(hashCode);
	return current->get(index++, ctx);
}
}}}}

