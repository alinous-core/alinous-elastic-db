#include "include/global.h"


#include "java.util/Locale.h"
#include "java.util/TimeZone.h"
#include "java.util/SimpleTimeZone.h"
#include "java.util/Calendar.h"
#include "java.util/GregorianCalendar.h"
#include "java.util/Date.h"
#include "alinous.numeric/InternalDate.h"
#include "java.util/TimeZones.h"
#include "java.sql/Date.h"
#include "java.util/BitSet.h"
#include "java.util/Random.h"
#include "java.util/Arrays.h"

namespace java {namespace util {





bool Arrays::__init_done = __init_static_variables();
bool Arrays::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"Arrays", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 Arrays::Arrays(ThreadContext* ctx) throw()  : IObject(ctx)
{
}
void Arrays::__construct_impl(ThreadContext* ctx) throw() 
{
}
 Arrays::~Arrays() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void Arrays::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
}
bool Arrays::equals(IArrayObjectPrimitive<char>* array1, IArrayObjectPrimitive<char>* array2, ThreadContext* ctx) throw() 
{
	if(array1 == array2)
	{
		return true;
	}
	if(array1 == (IArrayObjectPrimitive<char>*)nullptr || array2 == (IArrayObjectPrimitive<char>*)nullptr || array1->length != array2->length)
	{
		return false;
	}
	for(int i = 0; i < array1->length; i ++ )
	{
		if(array1->get(i) != array2->get(i))
		{
			return false;
		}
	}
	return true;
}
bool Arrays::equals(IArrayObjectPrimitive<short>* array1, IArrayObjectPrimitive<short>* array2, ThreadContext* ctx) throw() 
{
	if(array1 == array2)
	{
		return true;
	}
	if(array1 == (IArrayObjectPrimitive<short>*)nullptr || array2 == (IArrayObjectPrimitive<short>*)nullptr || array1->length != array2->length)
	{
		return false;
	}
	for(int i = 0; i < array1->length; i ++ )
	{
		if(array1->get(i) != array2->get(i))
		{
			return false;
		}
	}
	return true;
}
bool Arrays::equals(IArrayObjectPrimitive<wchar_t>* array1, IArrayObjectPrimitive<wchar_t>* array2, ThreadContext* ctx) throw() 
{
	if(array1 == array2)
	{
		return true;
	}
	if(array1 == (IArrayObjectPrimitive<wchar_t>*)nullptr || array2 == (IArrayObjectPrimitive<wchar_t>*)nullptr || array1->length != array2->length)
	{
		return false;
	}
	for(int i = 0; i < array1->length; i ++ )
	{
		if(array1->get(i) != array2->get(i))
		{
			return false;
		}
	}
	return true;
}
bool Arrays::equals(IArrayObjectPrimitive<int>* array1, IArrayObjectPrimitive<int>* array2, ThreadContext* ctx) throw() 
{
	if(array1 == array2)
	{
		return true;
	}
	if(array1 == (IArrayObjectPrimitive<int>*)nullptr || array2 == (IArrayObjectPrimitive<int>*)nullptr || array1->length != array2->length)
	{
		return false;
	}
	for(int i = 0; i < array1->length; i ++ )
	{
		if(array1->get(i) != array2->get(i))
		{
			return false;
		}
	}
	return true;
}
bool Arrays::equals(IArrayObjectPrimitive<long long>* array1, IArrayObjectPrimitive<long long>* array2, ThreadContext* ctx) throw() 
{
	if(array1 == array2)
	{
		return true;
	}
	if(array1 == (IArrayObjectPrimitive<long long>*)nullptr || array2 == (IArrayObjectPrimitive<long long>*)nullptr || array1->length != array2->length)
	{
		return false;
	}
	for(int i = 0; i < array1->length; i ++ )
	{
		if(array1->get(i) != array2->get(i))
		{
			return false;
		}
	}
	return true;
}
bool Arrays::equals(IArrayObjectPrimitive<double>* array1, IArrayObjectPrimitive<double>* array2, ThreadContext* ctx) throw() 
{
	if(array1 == array2)
	{
		return true;
	}
	if(array1 == (IArrayObjectPrimitive<double>*)nullptr || array2 == (IArrayObjectPrimitive<double>*)nullptr || array1->length != array2->length)
	{
		return false;
	}
	for(int i = 0; i < array1->length; i ++ )
	{
		if(Double::doubleToLongBits(array1->get(i), ctx) != Double::doubleToLongBits(array2->get(i), ctx))
		{
			return false;
		}
	}
	return true;
}
bool Arrays::equals(IArrayObjectPrimitive<bool>* array1, IArrayObjectPrimitive<bool>* array2, ThreadContext* ctx) throw() 
{
	if(array1 == array2)
	{
		return true;
	}
	if(array1 == (IArrayObjectPrimitive<bool>*)nullptr || array2 == (IArrayObjectPrimitive<bool>*)nullptr || array1->length != array2->length)
	{
		return false;
	}
	for(int i = 0; i < array1->length; i ++ )
	{
		if(array1->get(i) != array2->get(i))
		{
			return false;
		}
	}
	return true;
}
bool Arrays::equals(IArrayObjectPrimitive<float>* array1, IArrayObjectPrimitive<float>* array2, ThreadContext* ctx) throw() 
{
	if(array1 == array2)
	{
		return true;
	}
	if(array1 == (IArrayObjectPrimitive<float>*)nullptr || array2 == (IArrayObjectPrimitive<float>*)nullptr || array1->length != array2->length)
	{
		return false;
	}
	for(int i = 0; i < array1->length; i ++ )
	{
		if(Float::floatToIntBits(array1->get(i), ctx) != Float::floatToIntBits(array2->get(i), ctx))
		{
			return false;
		}
	}
	return true;
}
void Arrays::fill(IArrayObjectPrimitive<int>* groupBounds, int i, ThreadContext* ctx) throw() 
{
	for(int j = 0; j < groupBounds->length; j ++ )
	{
		groupBounds->set(i,j, ctx);
	}
}
void Arrays::fill(IArrayObjectPrimitive<char>* array, char value, ThreadContext* ctx) throw() 
{
	for(int i = 0; i < array->length; i ++ )
	{
		array->set(value,i, ctx);
	}
}
void Arrays::fill(IArrayObjectPrimitive<char>* array, int start, int end, char value, ThreadContext* ctx) throw() 
{
	for(int i = start; i < end; i ++ )
	{
		array->set(value,i, ctx);
	}
}
void Arrays::fill(IArrayObjectPrimitive<short>* array, short value, ThreadContext* ctx) throw() 
{
	for(int i = 0; i < array->length; i ++ )
	{
		array->set(value,i, ctx);
	}
}
void Arrays::fill(IArrayObjectPrimitive<short>* array, int start, int end, short value, ThreadContext* ctx) throw() 
{
	for(int i = start; i < end; i ++ )
	{
		array->set(value,i, ctx);
	}
}
void Arrays::fill(IArrayObjectPrimitive<wchar_t>* array, wchar_t value, ThreadContext* ctx) throw() 
{
	for(int i = 0; i < array->length; i ++ )
	{
		array->set(value,i, ctx);
	}
}
void Arrays::fill(IArrayObjectPrimitive<wchar_t>* array, int start, int end, wchar_t value, ThreadContext* ctx) throw() 
{
	for(int i = start; i < end; i ++ )
	{
		array->set(value,i, ctx);
	}
}
void Arrays::fill(IArrayObjectPrimitive<int>* array, int start, int end, int value, ThreadContext* ctx) throw() 
{
	for(int i = start; i < end; i ++ )
	{
		array->set(value,i, ctx);
	}
}
void Arrays::fill(IArrayObjectPrimitive<long long>* array, long long value, ThreadContext* ctx) throw() 
{
	for(int i = 0; i < array->length; i ++ )
	{
		array->set(value,i, ctx);
	}
}
void Arrays::fill(IArrayObjectPrimitive<long long>* array, int start, int end, long long value, ThreadContext* ctx) throw() 
{
	for(int i = start; i < end; i ++ )
	{
		array->set(value,i, ctx);
	}
}
void Arrays::fill(IArrayObjectPrimitive<float>* array, float value, ThreadContext* ctx) throw() 
{
	for(int i = 0; i < array->length; i ++ )
	{
		array->set(value,i, ctx);
	}
}
void Arrays::fill(IArrayObjectPrimitive<float>* array, int start, int end, float value, ThreadContext* ctx) throw() 
{
	for(int i = start; i < end; i ++ )
	{
		array->set(value,i, ctx);
	}
}
void Arrays::fill(IArrayObjectPrimitive<double>* array, double value, ThreadContext* ctx) throw() 
{
	for(int i = 0; i < array->length; i ++ )
	{
		array->set(value,i, ctx);
	}
}
void Arrays::fill(IArrayObjectPrimitive<double>* array, int start, int end, double value, ThreadContext* ctx) throw() 
{
	for(int i = start; i < end; i ++ )
	{
		array->set(value,i, ctx);
	}
}
void Arrays::fill(IArrayObjectPrimitive<bool>* array, bool value, ThreadContext* ctx) throw() 
{
	for(int i = 0; i < array->length; i ++ )
	{
		array->set(value,i, ctx);
	}
}
void Arrays::fill(IArrayObjectPrimitive<bool>* array, int start, int end, bool value, ThreadContext* ctx) throw() 
{
	for(int i = start; i < end; i ++ )
	{
		array->set(value,i, ctx);
	}
}
int Arrays::binarySearch(IArrayObjectPrimitive<wchar_t>* array, wchar_t value, ThreadContext* ctx) throw() 
{
	int low = 0;int mid = -1;int high = array->length - 1;
	while(low <= high)
	{
		mid = ((unsigned int)(low + high))>> 1;
		if(value > array->get(mid))
		{
			low = mid + 1;
		}
				else 
		{
			if(value == array->get(mid))
			{
				return mid;
			}
						else 
			{
				high = mid - 1;
			}
		}
	}
	if(mid < 0)
	{
		return -1;
	}
	return -mid - (value < array->get(mid) ? 1 : 2);
}
int Arrays::binarySearch(IArrayObjectPrimitive<int>* array, int value, ThreadContext* ctx) throw() 
{
	int low = 0;int mid = -1;int high = array->length - 1;
	while(low <= high)
	{
		mid = ((unsigned int)(low + high))>> 1;
		if(value > array->get(mid))
		{
			low = mid + 1;
		}
				else 
		{
			if(value == array->get(mid))
			{
				return mid;
			}
						else 
			{
				high = mid - 1;
			}
		}
	}
	if(mid < 0)
	{
		return -1;
	}
	return -mid - (value < array->get(mid) ? 1 : 2);
}
int Arrays::binarySearch(IArrayObjectPrimitive<long long>* array, long long value, ThreadContext* ctx) throw() 
{
	int low = 0;int mid = -1;int high = array->length - 1;
	while(low <= high)
	{
		mid = ((unsigned int)(low + high))>> 1;
		if(value > array->get(mid))
		{
			low = mid + 1;
		}
				else 
		{
			if(value == array->get(mid))
			{
				return mid;
			}
						else 
			{
				high = mid - 1;
			}
		}
	}
	if(mid < 0)
	{
		return -1;
	}
	return -mid - (value < array->get(mid) ? 1 : 2);
}
int Arrays::binarySearch(IArrayObjectPrimitive<short>* array, short value, ThreadContext* ctx) throw() 
{
	int low = 0;int mid = -1;int high = array->length - 1;
	while(low <= high)
	{
		mid = ((unsigned int)(low + high))>> 1;
		if(value > array->get(mid))
		{
			low = mid + 1;
		}
				else 
		{
			if(value == array->get(mid))
			{
				return mid;
			}
						else 
			{
				high = mid - 1;
			}
		}
	}
	if(mid < 0)
	{
		return -1;
	}
	return -mid - (value < array->get(mid) ? 1 : 2);
}
void Arrays::__cleanUp(ThreadContext* ctx){
}
}}

