#include "include/global.h"


#include "java.lang/Number.h"
#include "java.lang/Comparable.h"
#include "java.lang/Long.h"

namespace java {namespace lang {





constexpr const long long Long::MAX_VALUE;
constexpr const long long Long::MIN_VALUE;
constexpr const int Long::SIZE;
bool Long::__init_done = __init_static_variables();
bool Long::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"Long", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 Long::Long(long long value, ThreadContext* ctx) throw()  : IObject(ctx), Number(ctx), Comparable<Long>(ctx), value(0)
{
	this->value = value;
}
void Long::__construct_impl(long long value, ThreadContext* ctx) throw() 
{
	this->value = value;
}
 Long::Long(String* string, ThreadContext* ctx) : IObject(ctx), Number(ctx), Comparable<Long>(ctx), value(0)
{
	__construct_impl(parseLong(string, ctx), ctx);
}
void Long::__construct_impl(String* string, ThreadContext* ctx)
{
	__construct_impl(parseLong(string, ctx), ctx);
}
 Long::~Long() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void Long::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"Long", L"~Long");
	if(!prepare){
		return;
	}
	Number::__releaseRegerences(true, ctx);
}
char Long::byteValue(ThreadContext* ctx) throw() 
{
	return ((char)value);
}
int Long::compareTo(Long* object, ThreadContext* ctx) throw() 
{
	return value > object->value ? 1 : (value < object->value ? -1 : 0);
}
double Long::doubleValue(ThreadContext* ctx) throw() 
{
	return value;
}
bool Long::equals(IObject* o, ThreadContext* ctx) throw() 
{
	return ((dynamic_cast<Long*>(o) != 0)) && (value == (dynamic_cast<Long*>(o))->value);
}
float Long::floatValue(ThreadContext* ctx) throw() 
{
	return value;
}
int Long::hashCode(ThreadContext* ctx) throw() 
{
	return ((int)(value ^ (((unsigned long long)value)>> 32)));
}
int Long::intValue(ThreadContext* ctx) throw() 
{
	return ((int)value);
}
long long Long::longValue(ThreadContext* ctx) throw() 
{
	return value;
}
short Long::shortValue(ThreadContext* ctx) throw() 
{
	return ((short)value);
}
String* Long::toString(ThreadContext* ctx) throw() 
{
	return Long::toString(value, ctx);
}
Long* Long::decode(String* string, ThreadContext* ctx)
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
			return valueOf(ConstStr::getCNST_STR_9(), ctx);
		}
		firstDigit = string->charAt(i, ctx);
		if((firstDigit) == L'x' || firstDigit == L'X')
		{
			if(i == length)
			{
				throw (new(ctx) NumberFormatException(string, ctx));
			}
			i ++ ;
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
			if(i == length)
			{
				throw (new(ctx) NumberFormatException(string, ctx));
			}
			i ++ ;
			base = 16;
		}
	}
	long long result = parse(string, i, base, negative, ctx);
	return valueOf(result, ctx);
}
Long* Long::getLong(String* string, ThreadContext* ctx) throw() 
{
	if(string == nullptr || string->length(ctx) == 0)
	{
		return nullptr;
	}
	return (new(ctx) Long(parseLong(string, ctx), ctx));
}
Long* Long::getLong(String* string, long long defaultValue, ThreadContext* ctx) throw() 
{
	if(string == nullptr || string->length(ctx) == 0)
	{
		return valueOf(defaultValue, ctx);
	}
	return (new(ctx) Long(parseLong(string, ctx), ctx));
}
Long* Long::getLong(String* string, Long* defaultValue, ThreadContext* ctx) throw() 
{
	if(string == nullptr || string->length(ctx) == 0)
	{
		return defaultValue;
	}
	return (new(ctx) Long(parseLong(string, ctx), ctx));
}
long long Long::parseLong(String* string, ThreadContext* ctx)
{
	return parseLong(string, 10, ctx);
}
long long Long::parseLong(String* string, int radix, ThreadContext* ctx)
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
String* Long::toBinaryString(long long l, ThreadContext* ctx) throw() 
{
	int count = 1;
	long long j = l;
	if(l < (long long)0)
	{
		count = 64;
	}
		else 
	{
		j >>= 1;
		while((j) != (long long)0)
		{
			count ++ ;
		}
	}
	IArrayObjectPrimitive<wchar_t>* buffer = ArrayAllocatorPrimitive<wchar_t>::allocatep(ctx, count);
	do
	{
		buffer->set(((wchar_t)((l & 1) + L'0')),--count, ctx);
		l >>= 1;
	}
	while(count > 0);
	return (new(ctx) String(buffer, ctx));
}
String* Long::toHexString(long long l, ThreadContext* ctx) throw() 
{
	int count = 1;
	long long j = l;
	if(l < (long long)0)
	{
		count = 16;
	}
		else 
	{
		j >>= 4;
		while((j) != (long long)0)
		{
			count ++ ;
		}
	}
	IArrayObjectPrimitive<wchar_t>* buffer = ArrayAllocatorPrimitive<wchar_t>::allocatep(ctx, count);
	do
	{
		int t = ((int)(l & 15));
		if(t > 9)
		{
			t = t - 10 + L'a';
		}
				else 
		{
			t += L'0';
		}
		buffer->set(((wchar_t)t),--count, ctx);
		l >>= 4;
	}
	while(count > 0);
	return (new(ctx) String(buffer, ctx));
}
String* Long::toOctalString(long long l, ThreadContext* ctx) throw() 
{
	int count = 1;
	long long j = l;
	if(l < (long long)0)
	{
		count = 22;
	}
		else 
	{
		j = ((unsigned long long)j) >> 3;
		while((j) != (long long)0)
		{
			count ++ ;
		}
	}
	IArrayObjectPrimitive<wchar_t>* buffer = ArrayAllocatorPrimitive<wchar_t>::allocatep(ctx, count);
	do
	{
		buffer->set(((wchar_t)((l & 7) + L'0')),--count, ctx);
		l = ((unsigned long long)l) >> 3;
	}
	while(count > 0);
	return (new(ctx) String(buffer, ctx));
}
String* Long::toString(long long l, ThreadContext* ctx) throw() 
{
	return toString(l, 10, ctx);
}
String* Long::toString(long long l, int radix, ThreadContext* ctx) throw() 
{
	if(radix < Character::MIN_RADIX || radix > Character::MAX_RADIX)
	{
		radix = 10;
	}
	if(l == (long long)0)
	{
		return ConstStr::getCNST_STR_9();
	}
	int count = 2;
	long long j = l;
	bool negative = l < (long long)0;
	if(!negative)
	{
		count = 1;
		j = -l;
	}
	l /= radix;
	while((l) != (long long)0)
	{
		count ++ ;
	}
	IArrayObjectPrimitive<wchar_t>* buffer = ArrayAllocatorPrimitive<wchar_t>::allocatep(ctx, count);
	do
	{
		int ch = 0 - ((int)(j % radix));
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
	while((j /= radix) != (long long)0);
	if(negative)
	{
		buffer->set(L'-',0, ctx);
	}
	return (new(ctx) String(buffer, ctx));
}
Long* Long::valueOf(String* string, ThreadContext* ctx)
{
	return valueOf(parseLong(string, ctx), ctx);
}
Long* Long::valueOf(String* string, int radix, ThreadContext* ctx)
{
	return valueOf(parseLong(string, radix, ctx), ctx);
}
long long Long::highestOneBit(long long lng, ThreadContext* ctx) throw() 
{
	lng = lng | ((lng >> 1));
	lng = lng | ((lng >> 2));
	lng = lng | ((lng >> 4));
	lng = lng | ((lng >> 8));
	lng = lng | ((lng >> 16));
	lng = lng | ((lng >> 32));
	return (lng & ~(((unsigned long long)lng)>> 1));
}
long long Long::lowestOneBit(long long lng, ThreadContext* ctx) throw() 
{
	return (lng & (-lng));
}
int Long::numberOfLeadingZeros(long long lng, ThreadContext* ctx) throw() 
{
	lng = lng | (lng >> 1);
	lng = lng | (lng >> 2);
	lng = lng | (lng >> 4);
	lng = lng | (lng >> 8);
	lng = lng | (lng >> 16);
	lng = lng | (lng >> 32);
	return bitCount(~lng, ctx);
}
int Long::numberOfTrailingZeros(long long lng, ThreadContext* ctx) throw() 
{
	return bitCount((lng & -lng) - 1, ctx);
}
int Long::bitCount(long long lng, ThreadContext* ctx) throw() 
{
	lng = (lng & 0x5555555555555555L) + ((lng >> 1) & 0x5555555555555555L);
	lng = (lng & 0x3333333333333333L) + ((lng >> 2) & 0x3333333333333333L);
	int i = ((int)((((unsigned long long)lng)>> 32) + lng));
	i = (i & 0x0F0F0F0F) + ((i >> 4) & 0x0F0F0F0F);
	i = (i & 0x00FF00FF) + ((i >> 8) & 0x00FF00FF);
	i = (i & 0x0000FFFF) + ((i >> 16) & 0x0000FFFF);
	return i;
}
long long Long::rotateLeft(long long lng, int distance, ThreadContext* ctx) throw() 
{
	if(distance == 0)
	{
		return lng;
	}
	return ((lng << distance) | (((unsigned long long)lng)>> (-distance)));
}
long long Long::rotateRight(long long lng, int distance, ThreadContext* ctx) throw() 
{
	if(distance == 0)
	{
		return lng;
	}
	return ((((unsigned long long)lng)>> distance) | (lng << (-distance)));
}
long long Long::reverseBytes(long long lng, ThreadContext* ctx) throw() 
{
	long long b7 = ((unsigned long long)lng)>> 56;
	long long b6 = (((unsigned long long)lng)>> 40) & 0xFF00L;
	long long b5 = (((unsigned long long)lng)>> 24) & 0xFF0000L;
	long long b4 = (((unsigned long long)lng)>> 8) & 0xFF000000L;
	long long b3 = (lng & 0xFF000000L) << 8;
	long long b2 = (lng & 0xFF0000L) << 24;
	long long b1 = (lng & 0xFF00L) << 40;
	long long b0 = lng << 56;
	return (b0 | b1 | b2 | b3 | b4 | b5 | b6 | b7);
}
long long Long::reverse(long long lng, ThreadContext* ctx) throw() 
{
	lng = (lng & 0x5555555555555555L) << 1 | ((lng >> 1) & 0x5555555555555555L);
	lng = (lng & 0x3333333333333333L) << 2 | ((lng >> 2) & 0x3333333333333333L);
	lng = (lng & 0x0F0F0F0F0F0F0F0FL) << 4 | ((lng >> 4) & 0x0F0F0F0F0F0F0F0FL);
	return reverseBytes(lng, ctx);
}
int Long::signum(long long lng, ThreadContext* ctx) throw() 
{
	return (lng == (long long)0 ? 0 : (lng < (long long)0 ? -1 : 1));
}
Long* Long::valueOf(long long lng, ThreadContext* ctx) throw() 
{
	return (new(ctx) Long(lng, ctx));
}
long long Long::parse(String* string, int offset, int radix, bool negative, ThreadContext* ctx) throw() 
{
	long long max = Long::MIN_VALUE / radix;
	long long result = 0;long long length = string->length(ctx);
	while(offset < (int)length)
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
		long long next = result * radix - digit;
		if(next > result)
		{
			throw (new(ctx) NumberFormatException(string, ctx));
		}
		result = next;
	}
	if(!negative)
	{
		result = -result;
		if(result < (long long)0)
		{
			throw (new(ctx) NumberFormatException(string, ctx));
		}
	}
	return result;
}
void Long::__cleanUp(ThreadContext* ctx){
}
int Long::ValueCompare::operator() (Long* _this, Long* object, ThreadContext* ctx) const throw()
{
	return _this->compareTo(object, ctx);
}
}}

