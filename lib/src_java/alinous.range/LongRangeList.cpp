#include "include/global.h"


#include "alinous.range/LongRange.h"
#include "alinous.range/LongRangeIterator.h"
#include "alinous.range/LongRangeList.h"

namespace alinous {namespace range {





bool LongRangeList::__init_done = __init_static_variables();
bool LongRangeList::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"LongRangeList", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 LongRangeList::LongRangeList(ThreadContext* ctx) throw()  : IObject(ctx), list(GCUtils<ArrayList<LongRange> >::ins(this, (new(ctx) ArrayList<LongRange>(ctx)), ctx, __FILEW__, __LINE__, L""))
{
}
void LongRangeList::__construct_impl(ThreadContext* ctx) throw() 
{
}
 LongRangeList::~LongRangeList() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void LongRangeList::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"LongRangeList", L"~LongRangeList");
	__e_obj1.add(this->list, this);
	list = nullptr;
	if(!prepare){
		return;
	}
}
void LongRangeList::addRange(long long value, ThreadContext* ctx) throw() 
{
	if(this->list->isEmpty(ctx))
	{
		LongRange* newRange = (new(ctx) LongRange(value, value, ctx));
		list->add(newRange, ctx);
		return;
	}
	int pos = indexOfInsert(value, ctx);
	if(pos == list->size(ctx))
	{
		int lastPos = pos - 1;
		LongRange* lastRange = this->list->get(lastPos, ctx);
		if(lastRange->getMax(ctx) + 1 == value)
		{
			lastRange->setMax(value, ctx);
			return;
		}
		LongRange* newRange = (new(ctx) LongRange(value, value, ctx));
		list->add(newRange, ctx);
	}
		else 
	{
		insertOrExtend(pos, value, ctx);
	}
}
void LongRangeList::removeRange(long long value, ThreadContext* ctx) throw() 
{
	int pos = indexOfInsert(value, ctx);
	LongRange* range = this->list->get(pos, ctx);
	if(range->width(ctx) == (long long)1)
	{
		list->remove(pos, ctx);
	}
		else 
	{
		if(range->getMax(ctx) == value)
		{
			range->setMax(value - 1, ctx);
		}
				else 
		{
			if(range->getMin(ctx) == value)
			{
				range->setMin(value + 1, ctx);
			}
						else 
			{
				spiltByRemove(range, value, pos, ctx);
			}
		}
	}
}
LongRange* LongRangeList::get(int listIndex, ThreadContext* ctx) throw() 
{
	return this->list->get(listIndex, ctx);
}
bool LongRangeList::isEmpty(ThreadContext* ctx) throw() 
{
	return this->list->isEmpty(ctx);
}
int LongRangeList::size(ThreadContext* ctx) throw() 
{
	return this->list->size(ctx);
}
LongRangeIterator* LongRangeList::iterator(ThreadContext* ctx) throw() 
{
	return (new(ctx) LongRangeIterator(this, ctx));
}
void LongRangeList::spiltByRemove(LongRange* range, long long value, int pos, ThreadContext* ctx) throw() 
{
	LongRange* newRange = (new(ctx) LongRange(range->getMin(ctx), value - 1, ctx));
	range->setMin(value + 1, ctx);
	insertRange(pos, newRange, ctx);
}
void LongRangeList::insertRange(int pos, LongRange* newRange, ThreadContext* ctx) throw() 
{
	list->add(newRange, ctx);
	int maxLoop = this->list->size(ctx) - 1;
	for(int i = maxLoop; i != pos; i -- )
	{
		this->list->set(i, this->list->get(i - 1, ctx), ctx);
	}
	this->list->set(pos, newRange, ctx);
}
void LongRangeList::insertOrExtend(int pos, long long value, ThreadContext* ctx) throw() 
{
	LongRange* range = nullptr;
	long long prev = -1;
	if(pos != 0)
	{
		range = this->list->get(pos - 1, ctx);
		prev = range->getMax(ctx) + 1;
	}
	long long next = -1;
	LongRange* nextRange = nullptr;
	if(pos < this->list->size(ctx))
	{
		nextRange = this->list->get(pos, ctx);
		next = nextRange->getMin(ctx) - 1;
	}
	if(prev == value && next == value)
	{
		range->setMax(nextRange->getMax(ctx), ctx);
		list->remove(pos, ctx);
	}
		else 
	{
		if(prev == value)
		{
			range->setMax(value, ctx);
		}
				else 
		{
			if(next == value)
			{
				nextRange->setMin(value, ctx);
			}
						else 
			{
				insertRange(pos, value, ctx);
			}
		}
	}
}
void LongRangeList::insertRange(int pos, long long value, ThreadContext* ctx) throw() 
{
	LongRange* newRange = (new(ctx) LongRange(value, value, ctx));
	list->add(newRange, ctx);
	int maxLoop = this->list->size(ctx) - 1;
	for(int i = maxLoop; i != pos; i -- )
	{
		this->list->set(i, this->list->get(i - 1, ctx), ctx);
	}
	this->list->set(pos, newRange, ctx);
}
int LongRangeList::indexOfInsert(long long value, ThreadContext* ctx) throw() 
{
	int begin = 0;
	int end = this->list->size(ctx) - 1;
	int mid = (begin + end) / 2;
	while(begin <= end)
	{
		mid = (begin + end) / 2;
		if(list->get(mid, ctx)->getMax(ctx) - value == (long long)0)
		{
			return mid;
		}
				else 
		{
			if(list->get(mid, ctx)->getMax(ctx) - value < (long long)0)
			{
				begin = mid + 1;
			}
						else 
			{
				end = mid - 1;
			}
		}
	}
	if(end < 0)
	{
		return 0;
	}
	if(list->get(end, ctx)->getMax(ctx) - value > (long long)0)
	{
		return end;
	}
	if(begin >= this->list->size(ctx))
	{
		return this->list->size(ctx);
	}
	if(list->get(begin, ctx)->getMax(ctx) - value > (long long)0)
	{
		return begin;
	}
	return this->list->size(ctx);
}
void LongRangeList::__cleanUp(ThreadContext* ctx){
}
}}

