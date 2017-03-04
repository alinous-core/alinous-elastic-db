#include "include/global.h"


#include "java.lang/Boolean.h"
#include "java.lang/Comparable.h"
#include "java.lang/Number.h"
#include "java.lang/Double.h"
#include "java.lang/Integer.h"
#include "java.lang/Byte.h"
#include "java.lang/Long.h"
#include "java.lang/Float.h"
#include "java.lang/Short.h"
#include "java.lang/BinarySearch.h"

namespace java {namespace lang {





bool BinarySearch::__init_done = __init_static_variables();
bool BinarySearch::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"BinarySearch", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 BinarySearch::~BinarySearch() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void BinarySearch::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
}
int BinarySearch::binarySearchRange(String* data, wchar_t c, ThreadContext* ctx) throw() 
{
	wchar_t value = 0;
	int low = 0;int mid = -1;int high = data->length(ctx) - 1;
	while(low <= high)
	{
		mid = (low + high) >> 1;
		value = data->charAt(mid, ctx);
		if(c > value)
		{
			low = mid + 1;
		}
				else 
		{
			if(c == value)
			{
				return mid;
			}
						else 
			{
				high = mid - 1;
			}
		}
	}
	return mid - (c < value ? 1 : 0);
}
int BinarySearch::binarySearch(String* data, wchar_t value, ThreadContext* ctx) throw() 
{
	int low = 0;int high = data->length(ctx) - 1;
	while(low <= high)
	{
		int mid = (low + high) >> 1;
		wchar_t target = data->charAt(mid, ctx);
		if(value == target)
		{
			return mid;
		}
				else 
		{
			if(value < target)
			{
				high = mid - 1;
			}
						else 
			{
				low = mid + 1;
			}
		}
	}
	return -1;
}
}}

