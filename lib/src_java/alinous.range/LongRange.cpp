#include "include/global.h"


#include "alinous.range/LongRange.h"
#include "alinous.range/LongRangeIterator.h"
#include "alinous.range/LongRangeList.h"

namespace alinous {namespace range {





bool LongRange::__init_done = __init_static_variables();
bool LongRange::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"LongRange", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 LongRange::LongRange(long long min, long long max, ThreadContext* ctx) throw()  : IObject(ctx), min(0), max(0)
{
	this->min = min;
	this->max = max;
}
void LongRange::__construct_impl(long long min, long long max, ThreadContext* ctx) throw() 
{
	this->min = min;
	this->max = max;
}
 LongRange::~LongRange() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void LongRange::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"LongRange", L"~LongRange");
	if(!prepare){
		return;
	}
}
long long LongRange::width(ThreadContext* ctx) throw() 
{
	return this->min - this->max + 1;
}
bool LongRange::hasNext(long long value, ThreadContext* ctx) throw() 
{
	return this->max > value;
}
long long LongRange::getMin(ThreadContext* ctx) throw() 
{
	return min;
}
void LongRange::setMin(long long min, ThreadContext* ctx) throw() 
{
	this->min = min;
}
long long LongRange::getMax(ThreadContext* ctx) throw() 
{
	return max;
}
void LongRange::setMax(long long max, ThreadContext* ctx) throw() 
{
	this->max = max;
}
void LongRange::__cleanUp(ThreadContext* ctx){
}
}}

