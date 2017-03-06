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





constexpr const int Integer::MAX_VALUE;
constexpr const int Integer::MIN_VALUE;
constexpr const int Integer::SIZE;
const StaticArrayObjectPrimitive<int> Integer::__decimalScale = {1000000000, 100000000, 10000000, 1000000, 100000, 10000, 1000, 100, 10, 1};
IArrayObjectPrimitive<int>* Integer::decimalScale = (IArrayObjectPrimitive<int>*)const_cast<StaticArrayObjectPrimitive<int>*>(&__decimalScale);
bool Integer::__init_done = __init_static_variables();
bool Integer::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"Integer", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 Integer::Integer(int value, ThreadContext* ctx) throw()  : IObject(ctx), Number(ctx), Comparable<Integer>(ctx), value(0)
{
	this->value = value;
}
void Integer::__construct_impl(int value, ThreadContext* ctx) throw() 
{
	this->value = value;
}
 Integer::Integer(String* string, ThreadContext* ctx) : IObject(ctx), Number(ctx), Comparable<Integer>(ctx), value(0)
{
	__construct_impl(parseInt(string, ctx), ctx);
}
void Integer::__construct_impl(String* string, ThreadContext* ctx)
{
	__construct_impl(parseInt(string, ctx), ctx);
}
 Integer::~Integer() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void Integer::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"Integer", L"~Integer");
	if(!prepare){
		return;
	}
	Number::__releaseRegerences(true, ctx);
}
char Integer::byteValue(ThreadContext* ctx) throw() 
{
	return ((char)value);
}
int Integer::compareTo(Integer* object, ThreadContext* ctx) throw() 
{
	return value > object->value ? 1 : (value < object->value ? -1 : 0);
}
double Integer::doubleValue(ThreadContext* ctx) throw() 
{
	return value;
}
bool Integer::equals(IObject* o, ThreadContext* ctx) throw() 
{
	return ((dynamic_cast<Integer*>(o) != 0)) && (value == (dynamic_cast<Integer*>(o))->value);
}
float Integer::floatValue(ThreadContext* ctx) throw() 
{
	return value;
}
int Integer::hashCode(ThreadContext* ctx) throw() 
{
	return value;
}
int Integer::intValue(ThreadContext* ctx) throw() 
{
	return value;
}
long long Integer::longValue(ThreadContext* ctx) throw() 
{
	return value;
}
short Integer::shortValue(ThreadContext* ctx) throw() 
{
	return ((short)value);
}
String* Integer::toString(ThreadContext* ctx) throw() 
{
	return Integer::toString(value, ctx);
}
Integer* Integer::decode(String* string, ThreadContext* ctx)
{
	int length = string->length(ctx);int i = 0;
	if(length == 0)
	{
		throw (new(ctx) NumberFormatException(ctx));
	}
	wchar_t firstDigit = string->charAt(i, ctx);
	bool negative = firstDigit == L'-';
	if(negative)
	{
		if(length == 1)
		{
			throw (new(ctx) NumberFormatException(string, ctx));
		}
		firstDigit = string->charAt(++i, ctx);
	}
	int base = 10;
	if(firstDigit == L'0')
	{
		if(++i == length)
		{
			return valueOf(0, ctx);
		}
		firstDigit = string->charAt(i, ctx);
		if((firstDigit) == L'x' || firstDigit == L'X')
		{
			if(++i == length)
			{
				throw (new(ctx) NumberFormatException(string, ctx));
			}
			base = 16;
		}
				else 
		{
			base = 8;
		}
	}
		else 
	{
		if(firstDigit == L'#')
		{
			if(++i == length)
			{
				throw (new(ctx) NumberFormatException(string, ctx));
			}
			base = 16;
		}
	}
	int result = parse(string, i, base, negative, ctx);
	return valueOf(result, ctx);
}
Integer* Integer::getInteger(String* string, ThreadContext* ctx) throw() 
{
	if(string == nullptr || string->length(ctx) == 0)
	{
		return nullptr;
	}
	{
		try
		{
			return decode(string, ctx);
		}
		catch(NumberFormatException* ex)
		{
			return nullptr;
		}
	}
}
Integer* Integer::getInteger(String* string, int defaultValue, ThreadContext* ctx) throw() 
{
	if(string == nullptr || string->length(ctx) == 0)
	{
		return valueOf(defaultValue, ctx);
	}
	return (new(ctx) Integer(parseInt(string, ctx), ctx));
}
Integer* Integer::getInteger(String* string, Integer* defaultValue, ThreadContext* ctx) throw() 
{
	if(string == nullptr || string->length(ctx) == 0)
	{
		return defaultValue;
	}
	return (new(ctx) Integer(parseInt(string, ctx), ctx));
}
int Integer::parseInt(String* string, ThreadContext* ctx)
{
	return parseInt(string, 10, ctx);
}
int Integer::parseInt(String* string, int radix, ThreadContext* ctx)
{
	if(string == nullptr || radix < Character::MIN_RADIX || radix > Character::MAX_RADIX)
	{
		throw (new(ctx) NumberFormatException(ctx));
	}
	int length = string->length(ctx);int i = 0;
	if(length == 0)
	{
		throw (new(ctx) NumberFormatException(string, ctx));
	}
	bool negative = string->charAt(i, ctx) == L'-';
	if(negative && ++i == length)
	{
		throw (new(ctx) NumberFormatException(string, ctx));
	}
	return parse(string, i, radix, negative, ctx);
}
String* Integer::toBinaryString(int i, ThreadContext* ctx) throw() 
{
	int count = 1;int j = i;
	if(i < 0)
	{
		count = 32;
	}
		else 
	{
		j = ((unsigned int)j) >> 1;
		while((j) != 0)
		{
			count ++ ;
		}
	}
	IArrayObjectPrimitive<wchar_t>* buffer = ArrayAllocatorPrimitive<wchar_t>::allocatep(ctx, count);
	do
	{
		buffer->set(((wchar_t)((i & 1) + L'0')),--count, ctx);
		i = ((unsigned int)i) >> 1;
	}
	while(count > 0);
	return (new(ctx) String(buffer, ctx));
}
String* Integer::toHexString(int i, ThreadContext* ctx) throw() 
{
	int count = 1;int j = i;
	if(i < 0)
	{
		count = 8;
	}
		else 
	{
		j = ((unsigned int)j) >> 4;
		while((j) != 0)
		{
			count ++ ;
		}
	}
	IArrayObjectPrimitive<wchar_t>* buffer = ArrayAllocatorPrimitive<wchar_t>::allocatep(ctx, count);
	do
	{
		int t = i & 15;
		if(t > 9)
		{
			t = t - 10 + L'a';
		}
				else 
		{
			t += L'0';
		}
		buffer->set(((wchar_t)t),--count, ctx);
		i = ((unsigned int)i) >> 4;
	}
	while(count > 0);
	return (new(ctx) String(buffer, ctx));
}
String* Integer::toOctalString(int i, ThreadContext* ctx) throw() 
{
	int count = 1;int j = i;
	if(i < 0)
	{
		count = 11;
	}
		else 
	{
		j = ((unsigned int)j) >> 3;
		while((j) != 0)
		{
			count ++ ;
		}
	}
	IArrayObjectPrimitive<wchar_t>* buffer = ArrayAllocatorPrimitive<wchar_t>::allocatep(ctx, count);
	do
	{
		buffer->set(((wchar_t)((i & 7) + L'0')),--count, ctx);
		i = ((unsigned int)i) >> 3;
	}
	while(count > 0);
	return (new(ctx) String(buffer, ctx));
}
String* Integer::toString(int value, ThreadContext* ctx) throw() 
{
	if(value == 0)
	{
		return ConstStr::getCNST_STR_9();
	}
	if(value < 1000 && value > -1000)
	{
		IArrayObjectPrimitive<wchar_t>* buffer = ArrayAllocatorPrimitive<wchar_t>::allocatep(ctx, 4);
		int positive_value = value < 0 ? -1 * value : value;
		int first_digit = 0;
		if(value < 0)
		{
			buffer->set(L'-',0, ctx);
			first_digit ++ ;
		}
		int last_digit = first_digit;
		int quot = positive_value;
		do
		{
			int res = quot / 10;
			int digit_value = quot - ((res << 3) + (res << 1));
			digit_value += L'0';
			buffer->set(((wchar_t)digit_value),last_digit++, ctx);
			quot = res;
		}
		while(quot != 0);
		int count = last_digit--;
		do
		{
			wchar_t tmp = buffer->get(last_digit);
			buffer->set(buffer->get(first_digit),last_digit--, ctx);
			buffer->set(tmp,first_digit++, ctx);
		}
		while(first_digit < last_digit);
		IArrayObjectPrimitive<wchar_t>* ret = CharBuffer::wrap(buffer, 0, count, ctx)->array(ctx);
		return (new(ctx) String(ret, ctx));
	}
	if(value == MIN_VALUE)
	{
		return ConstStr::getCNST_STR_378();
	}
	IArrayObjectPrimitive<wchar_t>* buffer = ArrayAllocatorPrimitive<wchar_t>::allocatep(ctx, 11);
	int positive_value = value < 0 ? -value : value;
	char first_digit = 0;
	if(value < 0)
	{
		buffer->set(L'-',0, ctx);
		first_digit ++ ;
	}
	char last_digit = first_digit;
	char count = 0;
	int number = 0;
	bool start = false;
	for(int i = 0; i < 9; i ++ )
	{
		count = 0;
		number = decimalScale->get(i);
		if(positive_value < (number))
		{
			if(start)
			{
				buffer->set(L'0',last_digit++, ctx);
			}
			continue;
		}
		if(i > 0)
		{
			number = (decimalScale->get(i) << 3);
			if(positive_value >= number)
			{
				positive_value -= number;
				count += 8;
			}
			number = (decimalScale->get(i) << 2);
			if(positive_value >= number)
			{
				positive_value -= number;
				count += 4;
			}
		}
		number = (decimalScale->get(i) << 1);
		if(positive_value >= number)
		{
			positive_value -= number;
			count += 2;
		}
		if(positive_value >= decimalScale->get(i))
		{
			positive_value -= decimalScale->get(i);
			count ++ ;
		}
		if(count > (char)0 && !start)
		{
			start = true;
		}
		if(start)
		{
			buffer->set(((wchar_t)(count + L'0')),last_digit++, ctx);
		}
	}
	buffer->set(((wchar_t)(positive_value + L'0')),last_digit++, ctx);
	count = last_digit--;
	IArrayObjectPrimitive<wchar_t>* ret = CharBuffer::wrap(buffer, 0, (int)count, ctx)->array(ctx);
	return (new(ctx) String(ret, ctx));
}
String* Integer::toString(int i, int radix, ThreadContext* ctx) throw() 
{
	if(radix < Character::MIN_RADIX || radix > Character::MAX_RADIX)
	{
		radix = 10;
	}
	if(i == 0)
	{
		return ConstStr::getCNST_STR_9();
	}
	int count = 2;int j = i;
	bool negative = i < 0;
	if(!negative)
	{
		count = 1;
		j = -i;
	}
	i /= radix;
	while((i) != 0)
	{
		count ++ ;
	}
	IArrayObjectPrimitive<wchar_t>* buffer = ArrayAllocatorPrimitive<wchar_t>::allocatep(ctx, count);
	do
	{
		int ch = 0 - (j % radix);
		if(ch > 9)
		{
			ch = ch - 10 + L'a';
		}
				else 
		{
			ch += L'0';
		}
		buffer->set(((wchar_t)ch),--count, ctx);
	}
	while((j /= radix) != 0);
	if(negative)
	{
		buffer->set(L'-',0, ctx);
	}
	return (new(ctx) String(buffer, ctx));
}
Integer* Integer::valueOf(String* string, ThreadContext* ctx)
{
	return valueOf(parseInt(string, ctx), ctx);
}
Integer* Integer::valueOf(String* string, int radix, ThreadContext* ctx)
{
	return valueOf(parseInt(string, radix, ctx), ctx);
}
int Integer::highestOneBit(int i, ThreadContext* ctx) throw() 
{
	i = i | ((i >> 1));
	i = i | ((i >> 2));
	i = i | ((i >> 4));
	i = i | ((i >> 8));
	i = i | ((i >> 16));
	return (i & ~(((unsigned int)i)>> 1));
}
int Integer::lowestOneBit(int i, ThreadContext* ctx) throw() 
{
	return (i & (-i));
}
int Integer::numberOfLeadingZeros(int i, ThreadContext* ctx) throw() 
{
	i = i | (i >> 1);
	i = i | (i >> 2);
	i = i | (i >> 4);
	i = i | (i >> 8);
	i = i | (i >> 16);
	return bitCount(~i, ctx);
}
int Integer::numberOfTrailingZeros(int i, ThreadContext* ctx) throw() 
{
	return bitCount((i & -i) - 1, ctx);
}
int Integer::bitCount(int i, ThreadContext* ctx) throw() 
{
	i -= ((i >> 1) & 0x55555555);
	i = (i & 0x33333333) + ((i >> 2) & 0x33333333);
	i = (((i >> 4) + i) & 0x0F0F0F0F);
	i += (i >> 8);
	i += (i >> 16);
	return (i & 0x0000003F);
}
int Integer::rotateLeft(int i, int distance, ThreadContext* ctx) throw() 
{
	if(distance == 0)
	{
		return i;
	}
	return ((i << distance) | (((unsigned int)i)>> (-distance)));
}
int Integer::rotateRight(int i, int distance, ThreadContext* ctx) throw() 
{
	if(distance == 0)
	{
		return i;
	}
	return ((((unsigned int)i)>> distance) | (i << (-distance)));
}
int Integer::reverseBytes(int i, ThreadContext* ctx) throw() 
{
	int b3 = ((unsigned int)i)>> 24;
	int b2 = (((unsigned int)i)>> 8) & 0xFF00;
	int b1 = (i & 0xFF00) << 8;
	int b0 = i << 24;
	return (b0 | b1 | b2 | b3);
}
int Integer::reverse(int i, ThreadContext* ctx) throw() 
{
	i = (i & 0x55555555) << 1 | ((i >> 1) & 0x55555555);
	i = (i & 0x33333333) << 2 | ((i >> 2) & 0x33333333);
	i = (i & 0x0F0F0F0F) << 4 | ((i >> 4) & 0x0F0F0F0F);
	return reverseBytes(i, ctx);
}
int Integer::signum(int i, ThreadContext* ctx) throw() 
{
	return (i == 0 ? 0 : (i < 0 ? -1 : 1));
}
Integer* Integer::valueOf(int i, ThreadContext* ctx) throw() 
{
	return (new(ctx) Integer(i, ctx));
}
int Integer::parse(String* string, int offset, int radix, bool negative, ThreadContext* ctx)
{
	int max = Integer::MIN_VALUE / radix;
	int result = 0;int length = string->length(ctx);
	while(offset < length)
	{
		int digit = Character::digit(string->charAt(offset++, ctx), radix, ctx);
		if(digit == -1)
		{
			throw (new(ctx) NumberFormatException(string, ctx));
		}
		if(max > result)
		{
			throw (new(ctx) NumberFormatException(string, ctx));
		}
		int next = result * radix - digit;
		if(next > result)
		{
			throw (new(ctx) NumberFormatException(string, ctx));
		}
		result = next;
	}
	if(!negative)
	{
		result = -result;
		if(result < 0)
		{
			throw (new(ctx) NumberFormatException(string, ctx));
		}
	}
	return result;
}
void Integer::__cleanUp(ThreadContext* ctx){
}
int Integer::ValueCompare::operator() (Integer* _this, Integer* object, ThreadContext* ctx) const throw()
{
	return _this->compareTo(object, ctx);
}
}}

