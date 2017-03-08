#include "include/global.h"


#include "alinous.range/LongRange.h"
#include "alinous.range/LongRangeList.h"
#include "alinous.range/LongRangeIterator.h"

namespace alinous {namespace range {





bool LongRangeIterator::__init_done = __init_static_variables();
bool LongRangeIterator::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"LongRangeIterator", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 LongRangeIterator::LongRangeIterator(LongRangeList* list, ThreadContext* ctx) throw()  : IObject(ctx), list(nullptr), listIndex(0), current(0)
{
	__GC_MV(this, &(this->list), list, LongRangeList);
	this->listIndex = 0;
	if(this->list->isEmpty(ctx))
	{
		this->current = -1;
	}
		else 
	{
		LongRange* range = list->get(this->listIndex, ctx);
		this->current = range->getMin(ctx);
	}
}
void LongRangeIterator::__construct_impl(LongRangeList* list, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->list), list, LongRangeList);
	this->listIndex = 0;
	if(this->list->isEmpty(ctx))
	{
		this->current = -1;
	}
		else 
	{
		LongRange* range = list->get(this->listIndex, ctx);
		this->current = range->getMin(ctx);
	}
}
 LongRangeIterator::~LongRangeIterator() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void LongRangeIterator::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"LongRangeIterator", L"~LongRangeIterator");
	__e_obj1.add(this->list, this);
	list = nullptr;
	if(!prepare){
		return;
	}
}
bool LongRangeIterator::hasNext(ThreadContext* ctx) throw() 
{
	if(this->list->isEmpty(ctx) || listIndex == this->list->size(ctx))
	{
		return false;
	}
	return this->current > (long long)0;
}
long long LongRangeIterator::next(ThreadContext* ctx) throw() 
{
	long long ret = this->current;
	LongRange* range = list->get(this->listIndex, ctx);
	if(range->hasNext(this->current, ctx))
	{
		this->current ++ ;
	}
		else 
	{
		if(list->size(ctx) - 1 > this->listIndex)
		{
			this->listIndex ++ ;
			range = list->get(this->listIndex, ctx);
			this->current = range->getMin(ctx);
		}
				else 
		{
			this->current = -1;
		}
	}
	return ret;
}
void LongRangeIterator::__cleanUp(ThreadContext* ctx){
}
}}

