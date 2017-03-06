#include "include/global.h"


#include "java.util/Locale.h"
#include "java.util/Calendar.h"
#include "java.util/GregorianCalendar.h"
#include "java.util/Date.h"
#include "alinous.numeric/InternalDate.h"
#include "java.util/TimeZone.h"
#include "alinous.numeric/TimeOnlyTimestamp.h"
#include "java.util/Random.h"
#include "java.lang/Number.h"
#include "java.lang/Comparable.h"
#include "alinous.numeric/BigInteger.h"
#include "alinous.numeric/BitLevel.h"
#include "alinous.numeric/Multiplication.h"
#include "alinous.numeric/Conversion.h"
#include "alinous.numeric/RoundingMode.h"
#include "alinous.numeric/Logical.h"
#include "alinous.numeric/MathContext.h"
#include "alinous.numeric/Division.h"
#include "alinous.lock/LockObject.h"
#include "alinous.numeric/BigDecimal.h"
#include "alinous.numeric/Elementary.h"
#include "alinous.numeric/Primality.h"

namespace alinous {namespace numeric {





const StaticArrayObjectPrimitive<int> Conversion::__digitFitInInt = {-1, -1, 31, 19, 15, 13, 11, 11, 10, 9, 9, 8, 8, 8, 8, 7, 7, 7, 7, 7, 7, 7, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 5};
IArrayObjectPrimitive<int>* Conversion::digitFitInInt = (IArrayObjectPrimitive<int>*)const_cast<StaticArrayObjectPrimitive<int>*>(&__digitFitInInt);
const StaticArrayObjectPrimitive<int> Conversion::__bigRadices = {-2147483648, 1162261467, 1073741824, 1220703125, 362797056, 1977326743, 1073741824, 387420489, 1000000000, 214358881, 429981696, 815730721, 1475789056, 170859375, 268435456, 410338673, 612220032, 893871739, 1280000000, 1801088541, 113379904, 148035889, 191102976, 244140625, 308915776, 387420489, 481890304, 594823321, 729000000, 887503681, 1073741824, 1291467969, 1544804416, 1838265625, 60466176};
IArrayObjectPrimitive<int>* Conversion::bigRadices = (IArrayObjectPrimitive<int>*)const_cast<StaticArrayObjectPrimitive<int>*>(&__bigRadices);
bool Conversion::__init_done = __init_static_variables();
bool Conversion::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"Conversion", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 Conversion::Conversion(ThreadContext* ctx) throw()  : IObject(ctx)
{
}
void Conversion::__construct_impl(ThreadContext* ctx) throw() 
{
}
 Conversion::~Conversion() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void Conversion::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
}
String* Conversion::bigInteger2String(BigInteger* val, int radix, ThreadContext* ctx) throw() 
{
	int sign = val->sign;
	int numberLength = val->numberLength;
	IArrayObjectPrimitive<int>* digits = val->digits;
	if(sign == 0)
	{
		return ConstStr::getCNST_STR_9();
	}
	if(numberLength == 1)
	{
		int highDigit = digits->get(numberLength - 1);
		long long v = highDigit & 0xFFFFFFFFL;
		if(sign < 0)
		{
			v = -v;
		}
		return Long::toString(v, radix, ctx);
	}
	if((radix == 10) || (radix < Character::MIN_RADIX) || (radix > Character::MAX_RADIX))
	{
		return val->toString(ctx);
	}
	double bitsForRadixDigit = 0;
	bitsForRadixDigit = Math::log((double)radix, ctx) / Math::log((double)2, ctx);
	int resLengthInChars = ((int)(val->abs(ctx)->bitLength(ctx) / bitsForRadixDigit + ((sign < 0) ? 1 : 0))) + 1;
	IArrayObjectPrimitive<wchar_t>* result = ArrayAllocatorPrimitive<wchar_t>::allocatep(ctx, resLengthInChars);
	int currentChar = resLengthInChars;
	int resDigit = 0;
	if(radix != 16)
	{
		IArrayObjectPrimitive<int>* temp = ArrayAllocatorPrimitive<int>::allocatep(ctx, numberLength);
		System::arraycopy(digits, 0, temp, 0, numberLength, ctx);
		int tempLen = numberLength;
		int charsPerInt = digitFitInInt->get(radix);
		int i = 0;
		int bigRadix = bigRadices->get(radix - 2);
		while(true)
		{
			resDigit = Division::divideArrayByInt(temp, temp, tempLen, bigRadix, ctx);
			int previous = currentChar;
			do
			{
				result->set(Character::forDigit(resDigit % radix, radix, ctx),--currentChar, ctx);
			}
			while(((resDigit /= radix) != 0) && (currentChar != 0));
			int delta = charsPerInt - previous + currentChar;
			for(i = 0; i < delta && currentChar > 0; i ++ )
			{
				result->set(L'0',--currentChar, ctx);
			}
			for(i = tempLen - 1; (i > 0) && (temp->get(i) == 0); i -- )
			{
				;
			}
			tempLen = i + 1;
			if((tempLen == 1) && (temp->get(0) == 0))
			{
				break ;
			}
		}
	}
		else 
	{
		for(int i = 0; i < numberLength; i ++ )
		{
			for(int j = 0; (j < 8) && (currentChar > 0); j ++ )
			{
				resDigit = digits->get(i) >> (j << 2) & 0xf;
				result->set(Character::forDigit(resDigit, 16, ctx),--currentChar, ctx);
			}
		}
	}
	while(result->get(currentChar) == L'0')
	{
		currentChar ++ ;
	}
	if(sign == -1)
	{
		result->set(L'-',--currentChar, ctx);
	}
	return (new(ctx) String(result, currentChar, resLengthInChars - currentChar, ctx));
}
String* Conversion::toDecimalScaledString(BigInteger* val, int scale, ThreadContext* ctx) throw() 
{
	int sign = val->sign;
	int numberLength = val->numberLength;
	IArrayObjectPrimitive<int>* digits = val->digits;
	int resLengthInChars = 0;
	int currentChar = 0;
	IArrayObjectPrimitive<wchar_t>* result = 0;
	if(sign == 0)
	{
		switch(scale) {
		case 0:
			return ConstStr::getCNST_STR_9();
		case 1:
			return ConstStr::getCNST_STR_10();
		case 2:
			return ConstStr::getCNST_STR_11();
		case 3:
			return ConstStr::getCNST_STR_12();
		case 4:
			return ConstStr::getCNST_STR_13();
		case 5:
			return ConstStr::getCNST_STR_14();
		case 6:
			return ConstStr::getCNST_STR_15();
		default:
			{
			StringBuilder* result1 = (new(ctx) StringBuilder(ctx));
			if(scale < 0)
			{
				result1->append(ConstStr::getCNST_STR_16(), ctx);
			}
						else 
			{
				result1->append(ConstStr::getCNST_STR_17(), ctx);
			}
			result1->append(-scale, ctx);
			return result1->toString(ctx);
			break;
			}
		}
	}
	resLengthInChars = numberLength * 10 + 1 + 7;
	result = ArrayAllocatorPrimitive<wchar_t>::allocatep(ctx, resLengthInChars + 1);
	currentChar = resLengthInChars;
	if(numberLength == 1)
	{
		int highDigit = digits->get(0);
		if(highDigit < 0)
		{
			long long v = highDigit & 0xFFFFFFFFL;
			do
			{
				long long prev = v;
				v /= 10;
				result->set(((wchar_t)(0x0030 + (((int)(prev - v * 10))))),--currentChar, ctx);
			}
			while(v != (long long)0);
		}
				else 
		{
			int v = highDigit;
			do
			{
				int prev = v;
				v /= 10;
				result->set(((wchar_t)(0x0030 + (prev - v * 10))),--currentChar, ctx);
			}
			while(v != 0);
		}
	}
		else 
	{
		IArrayObjectPrimitive<int>* temp = ArrayAllocatorPrimitive<int>::allocatep(ctx, numberLength);
		int tempLen = numberLength;
		System::arraycopy(digits, 0, temp, 0, tempLen, ctx);
		while(true)
		{
			long long result11 = 0;
			for(int i1 = tempLen - 1; i1 >= 0; i1 -- )
			{
				long long temp1 = (result11 << 32) + (temp->get(i1) & 0xFFFFFFFFL);
				long long res = divideLongByBillion(temp1, ctx);
				temp->set(((int)res),i1, ctx);
				result11 = ((int)(res >> 32));
			}
			int resDigit = ((int)result11);
			int previous = currentChar;
			do
			{
				result->set(((wchar_t)(0x0030 + (resDigit % 10))),--currentChar, ctx);
			}
			while(((resDigit /= 10) != 0) && (currentChar != 0));
			int delta = 9 - previous + currentChar;
			for(int i = 0; (i < delta) && (currentChar > 0); i ++ )
			{
				result->set(L'0',--currentChar, ctx);
			}
			int j = tempLen - 1;
			for(; temp->get(j) == 0; j -- )
			{
				if(j == 0)
				{
					goto BIG_LOOP_out_break;
				}
			}
			tempLen = j + 1;
		}
		BIG_LOOP_out_break: ;
		while(result->get(currentChar) == L'0')
		{
			currentChar ++ ;
		}
	}
	bool negNumber = (sign < 0);
	int exponent = resLengthInChars - currentChar - scale - 1;
	if(scale == 0)
	{
		if(negNumber)
		{
			result->set(L'-',--currentChar, ctx);
		}
		return (new(ctx) String(result, currentChar, resLengthInChars - currentChar, ctx));
	}
	if((scale > 0) && (exponent >= -6))
	{
		if(exponent >= 0)
		{
			int insertPoint = currentChar + exponent;
			for(int j = resLengthInChars - 1; j >= insertPoint; j -- )
			{
				result->set(result->get(j),j + 1, ctx);
			}
			result->set(L'.',++insertPoint, ctx);
			if(negNumber)
			{
				result->set(L'-',--currentChar, ctx);
			}
			return (new(ctx) String(result, currentChar, resLengthInChars - currentChar + 1, ctx));
		}
		for(int j = 2; j < -exponent + 1; j ++ )
		{
			result->set(L'0',--currentChar, ctx);
		}
		result->set(L'.',--currentChar, ctx);
		result->set(L'0',--currentChar, ctx);
		if(negNumber)
		{
			result->set(L'-',--currentChar, ctx);
		}
		return (new(ctx) String(result, currentChar, resLengthInChars - currentChar, ctx));
	}
	int startPoint = currentChar + 1;
	int endPoint = resLengthInChars;
	StringBuilder* result1 = (new(ctx) StringBuilder(16 + endPoint - startPoint, ctx));
	if(negNumber)
	{
		result1->append(L'-', ctx);
	}
	if(endPoint - startPoint >= 1)
	{
		result1->append(result->get(currentChar), ctx);
		result1->append(L'.', ctx);
		result1->append(result, currentChar + 1, resLengthInChars - currentChar - 1, ctx);
	}
		else 
	{
		result1->append(result, currentChar, resLengthInChars - currentChar, ctx);
	}
	result1->append(L'E', ctx);
	if(exponent > 0)
	{
		result1->append(L'+', ctx);
	}
	result1->append(Integer::toString(exponent, ctx), ctx);
	return result1->toString(ctx);
}
String* Conversion::toDecimalScaledString(long long value, int scale, ThreadContext* ctx) throw() 
{
	int resLengthInChars = 0;
	int currentChar = 0;
	IArrayObjectPrimitive<wchar_t>* result = 0;
	bool negNumber = value < (long long)0;
	if(negNumber)
	{
		value = -value;
	}
	if(value == (long long)0)
	{
		switch(scale) {
		case 0:
			return ConstStr::getCNST_STR_9();
		case 1:
			return ConstStr::getCNST_STR_10();
		case 2:
			return ConstStr::getCNST_STR_11();
		case 3:
			return ConstStr::getCNST_STR_12();
		case 4:
			return ConstStr::getCNST_STR_13();
		case 5:
			return ConstStr::getCNST_STR_14();
		case 6:
			return ConstStr::getCNST_STR_15();
		default:
			{
			StringBuilder* result1 = (new(ctx) StringBuilder(ctx));
			if(scale < 0)
			{
				result1->append(ConstStr::getCNST_STR_16(), ctx);
			}
						else 
			{
				result1->append(ConstStr::getCNST_STR_17(), ctx);
			}
			result1->append((scale == Integer::MIN_VALUE) ? ConstStr::getCNST_STR_18() : Integer::toString(-scale, ctx), ctx);
			return result1->toString(ctx);
			break;
			}
		}
	}
	resLengthInChars = 18;
	result = ArrayAllocatorPrimitive<wchar_t>::allocatep(ctx, resLengthInChars + 1);
	currentChar = resLengthInChars;
	long long v = value;
	do
	{
		long long prev = v;
		v /= 10;
		result->set(((wchar_t)(0x0030 + (prev - v * 10))),--currentChar, ctx);
	}
	while(v != (long long)0);
	long long exponent = ((long long)resLengthInChars) - ((long long)currentChar) - scale - 1L;
	if(scale == 0)
	{
		if(negNumber)
		{
			result->set(L'-',--currentChar, ctx);
		}
		return (new(ctx) String(result, currentChar, resLengthInChars - currentChar, ctx));
	}
	if(scale > 0 && exponent >= (long long)-6)
	{
		if(exponent >= (long long)0)
		{
			int insertPoint = currentChar + ((int)exponent);
			for(int j = resLengthInChars - 1; j >= insertPoint; j -- )
			{
				result->set(result->get(j),j + 1, ctx);
			}
			result->set(L'.',++insertPoint, ctx);
			if(negNumber)
			{
				result->set(L'-',--currentChar, ctx);
			}
			return (new(ctx) String(result, currentChar, resLengthInChars - currentChar + 1, ctx));
		}
		for(int j = 2; j < (int)-exponent + 1; j ++ )
		{
			result->set(L'0',--currentChar, ctx);
		}
		result->set(L'.',--currentChar, ctx);
		result->set(L'0',--currentChar, ctx);
		if(negNumber)
		{
			result->set(L'-',--currentChar, ctx);
		}
		return (new(ctx) String(result, currentChar, resLengthInChars - currentChar, ctx));
	}
	int startPoint = currentChar + 1;
	int endPoint = resLengthInChars;
	StringBuilder* result1 = (new(ctx) StringBuilder(16 + endPoint - startPoint, ctx));
	if(negNumber)
	{
		result1->append(L'-', ctx);
	}
	if(endPoint - startPoint >= 1)
	{
		result1->append(result->get(currentChar), ctx);
		result1->append(L'.', ctx);
		result1->append(result, currentChar + 1, resLengthInChars - currentChar - 1, ctx);
	}
		else 
	{
		result1->append(result, currentChar, resLengthInChars - currentChar, ctx);
	}
	result1->append(L'E', ctx);
	if(exponent > (long long)0)
	{
		result1->append(L'+', ctx);
	}
	result1->append(Long::toString(exponent, ctx), ctx);
	return result1->toString(ctx);
}
long long Conversion::divideLongByBillion(long long a, ThreadContext* ctx) throw() 
{
	long long quot = 0;
	long long rem = 0;
	if(a >= (long long)0)
	{
		long long bLong = 1000000000L;
		quot = (a / bLong);
		rem = (a % bLong);
	}
		else 
	{
		long long aPos = ((unsigned long long)a)>> 1;
		long long bPos = ((unsigned int)1000000000L)>> 1;
		quot = aPos / bPos;
		rem = aPos % bPos;
		rem = (rem << 1) + (a & 1);
	}
	return ((rem << 32) | (quot & 0xFFFFFFFFL));
}
double Conversion::bigInteger2Double(BigInteger* val, ThreadContext* ctx) throw() 
{
	if((val->numberLength < 2) || ((val->numberLength == 2) && (val->digits->get(1) > 0)))
	{
		return val->longValue(ctx);
	}
	if(val->numberLength > 32)
	{
		return ((val->sign > 0) ? Double::POSITIVE_INFINITY : Double::NEGATIVE_INFINITY);
	}
	int bitLen = val->abs(ctx)->bitLength(ctx);
	long long exponent = bitLen - 1;
	int delta = bitLen - 54;
	long long lVal = val->abs(ctx)->shiftRight(delta, ctx)->longValue(ctx);
	long long mantissa = lVal & 0x1FFFFFFFFFFFFFL;
	if(exponent == (long long)1023)
	{
		if(mantissa == (long long)0X1FFFFFFFFFFFFFL)
		{
			return ((val->sign > 0) ? Double::POSITIVE_INFINITY : Double::NEGATIVE_INFINITY);
		}
		if(mantissa == (long long)0x1FFFFFFFFFFFFEL)
		{
			return ((val->sign > 0) ? Double::MAX_VALUE : -Double::MAX_VALUE);
		}
	}
	if(((mantissa & 1) == (long long)1) && (((mantissa & 2) == (long long)2) || BitLevel::nonZeroDroppedBits(delta, val->digits, ctx)))
	{
		mantissa += 2;
	}
	mantissa >>= 1;
	long long resSign = (val->sign < 0) ? 0x8000000000000000L : 0;
	exponent = ((1023 + exponent) << 52) & 0x7FF0000000000000L;
	long long result = resSign | exponent | mantissa;
	return Double::longBitsToDouble(result, ctx);
}
void Conversion::__cleanUp(ThreadContext* ctx){
}
}}

