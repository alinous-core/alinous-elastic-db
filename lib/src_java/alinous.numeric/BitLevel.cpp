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





bool BitLevel::__init_done = __init_static_variables();
bool BitLevel::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"BitLevel", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 BitLevel::BitLevel(ThreadContext* ctx) throw()  : IObject(ctx)
{
}
void BitLevel::__construct_impl(ThreadContext* ctx) throw() 
{
}
 BitLevel::~BitLevel() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void BitLevel::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
}
int BitLevel::bitLength(BigInteger* val, ThreadContext* ctx) throw() 
{
	if(val->sign == 0)
	{
		return 0;
	}
	int bLength = (val->numberLength << 5);
	int highDigit = val->digits->get(val->numberLength - 1);
	if(val->sign < 0)
	{
		int i = val->getFirstNonzeroDigit(ctx);
		if(i == val->numberLength - 1)
		{
			highDigit -- ;
		}
	}
	bLength -= Integer::numberOfLeadingZeros(highDigit, ctx);
	return bLength;
}
int BitLevel::bitCount(BigInteger* val, ThreadContext* ctx) throw() 
{
	int bCount = 0;
	if(val->sign == 0)
	{
		return 0;
	}
	int i = val->getFirstNonzeroDigit(ctx);
	;
	if(val->sign > 0)
	{
		for(; i < val->numberLength; i ++ )
		{
			bCount += Integer::bitCount(val->digits->get(i), ctx);
		}
	}
		else 
	{
		bCount += Integer::bitCount(-val->digits->get(i), ctx);
		for(i ++ ; i < val->numberLength; i ++ )
		{
			bCount += Integer::bitCount(~val->digits->get(i), ctx);
		}
		bCount = (val->numberLength << 5) - bCount;
	}
	return bCount;
}
bool BitLevel::testBit(BigInteger* val, int n, ThreadContext* ctx) throw() 
{
	return ((val->digits->get(n >> 5) & (1 << (n & 31))) != 0);
}
bool BitLevel::nonZeroDroppedBits(int numberOfBits, IArrayObjectPrimitive<int>* digits, ThreadContext* ctx) throw() 
{
	int intCount = numberOfBits >> 5;
	int bitCount = numberOfBits & 31;
	int i = 0;
	for(i = 0; (i < intCount) && (digits->get(i) == 0); i ++ )
	{
		;
	}
	return ((i != intCount) || (digits->get(i) << (32 - bitCount) != 0));
}
BigInteger* BitLevel::shiftLeft(BigInteger* source, int count, ThreadContext* ctx) throw() 
{
	int intCount = count >> 5;
	count = count & (31);
	int resLength = source->numberLength + intCount + ((count == 0) ? 0 : 1);
	IArrayObjectPrimitive<int>* resDigits = ArrayAllocatorPrimitive<int>::allocatep(ctx, resLength);
	shiftLeft(resDigits, source->digits, intCount, count, ctx);
	BigInteger* result = (new(ctx) BigInteger(source->sign, resLength, resDigits, ctx));
	result->cutOffLeadingZeroes(ctx);
	return result;
}
void BitLevel::inplaceShiftLeft(BigInteger* val, int count, ThreadContext* ctx) throw() 
{
	int intCount = count >> 5;
	val->numberLength += intCount + (Integer::numberOfLeadingZeros(val->digits->get(val->numberLength - 1), ctx) - (count & 31) >= 0 ? 0 : 1);
	shiftLeft(val->digits, val->digits, intCount, count & 31, ctx);
	val->cutOffLeadingZeroes(ctx);
	val->unCache(ctx);
}
void BitLevel::shiftLeft(IArrayObjectPrimitive<int>* result, IArrayObjectPrimitive<int>* source, int intCount, int count, ThreadContext* ctx) throw() 
{
	if(count == 0)
	{
		System::arraycopy(source, 0, result, intCount, result->length - intCount, ctx);
	}
		else 
	{
		int rightShiftCount = 32 - count;
		result->set(0,result->length - 1, ctx);
		for(int i = result->length - 1; i > intCount; i -- )
		{
			result->set(result->get(i) | (((unsigned int)source->get(i - intCount - 1))>> rightShiftCount),i, ctx);
			result->set(source->get(i - intCount - 1) << count,i - 1, ctx);
		}
	}
	for(int i = 0; i < intCount; i ++ )
	{
		result->set(0,i, ctx);
	}
}
void BitLevel::shiftLeftOneBit(IArrayObjectPrimitive<int>* result, IArrayObjectPrimitive<int>* source, int srcLen, ThreadContext* ctx) throw() 
{
	int carry = 0;
	for(int i = 0; i < srcLen; i ++ )
	{
		int val = source->get(i);
		result->set((val << 1) | carry,i, ctx);
		carry = ((unsigned int)val)>> 31;
	}
	if(carry != 0)
	{
		result->set(carry,srcLen, ctx);
	}
}
BigInteger* BitLevel::shiftLeftOneBit(BigInteger* source, ThreadContext* ctx) throw() 
{
	int srcLen = source->numberLength;
	int resLen = srcLen + 1;
	IArrayObjectPrimitive<int>* resDigits = ArrayAllocatorPrimitive<int>::allocatep(ctx, resLen);
	shiftLeftOneBit(resDigits, source->digits, srcLen, ctx);
	BigInteger* result = (new(ctx) BigInteger(source->sign, resLen, resDigits, ctx));
	result->cutOffLeadingZeroes(ctx);
	return result;
}
BigInteger* BitLevel::shiftRight(BigInteger* source, int count, ThreadContext* ctx) throw() 
{
	int intCount = count >> 5;
	count = count & (31);
	if(intCount >= source->numberLength)
	{
		return ((source->sign < 0) ? BigInteger::MINUS_ONE : BigInteger::ZERO);
	}
	int i = 0;
	int resLength = source->numberLength - intCount;
	IArrayObjectPrimitive<int>* resDigits = ArrayAllocatorPrimitive<int>::allocatep(ctx, resLength + 1);
	shiftRight(resDigits, resLength, source->digits, intCount, count, ctx);
	if(source->sign < 0)
	{
		for(i = 0; (i < intCount) && (source->digits->get(i) == 0); i ++ )
		{
			;
		}
		if((i < intCount) || ((count > 0) && ((source->digits->get(i) << (32 - count)) != 0)))
		{
			for(i = 0; (i < resLength) && (resDigits->get(i) == -1); i ++ )
			{
				resDigits->set(0,i, ctx);
			}
			if(i == resLength)
			{
				resLength ++ ;
			}
			resDigits->set(resDigits->get(i) + 1,i, ctx);
		}
	}
	BigInteger* result = (new(ctx) BigInteger(source->sign, resLength, resDigits, ctx));
	result->cutOffLeadingZeroes(ctx);
	return result;
}
void BitLevel::inplaceShiftRight(BigInteger* val, int count, ThreadContext* ctx) throw() 
{
	int sign = val->signum(ctx);
	if(count == 0 || val->signum(ctx) == 0)
	{
		return;
	}
	int intCount = count >> 5;
	val->numberLength -= intCount;
	if(!shiftRight(val->digits, val->numberLength, val->digits, intCount, count & 31, ctx) && sign < 0)
	{
		int i = 0;
		for(i = 0; (i < val->numberLength) && (val->digits->get(i) == -1); i ++ )
		{
			val->digits->set(0,i, ctx);
		}
		if(i == val->numberLength)
		{
			val->numberLength ++ ;
		}
		val->digits->set(val->digits->get(i) + 1,i, ctx);
	}
	val->cutOffLeadingZeroes(ctx);
	val->unCache(ctx);
}
bool BitLevel::shiftRight(IArrayObjectPrimitive<int>* result, int resultLen, IArrayObjectPrimitive<int>* source, int intCount, int count, ThreadContext* ctx) throw() 
{
	int i = 0;
	bool allZero = true;
	for(i = 0; i < intCount; i ++ )
	allZero = allZero & (source->get(i) == 0);
	if(count == 0)
	{
		System::arraycopy(source, intCount, result, 0, resultLen, ctx);
		i = resultLen;
	}
		else 
	{
		int leftShiftCount = 32 - count;
		allZero = allZero & ((source->get(i) << leftShiftCount) == 0);
		for(i = 0; i < resultLen - 1; i ++ )
		{
			result->set((((unsigned int)source->get(i + intCount))>> count) | (source->get(i + intCount + 1) << leftShiftCount),i, ctx);
		}
		result->set((((unsigned int)source->get(i + intCount))>> count),i, ctx);
		i ++ ;
	}
	return allZero;
}
BigInteger* BitLevel::flipBit(BigInteger* val, int n, ThreadContext* ctx) throw() 
{
	int resSign = (val->sign == 0) ? 1 : val->sign;
	int intCount = n >> 5;
	int bitN = n & 31;
	int resLength = Math::max(intCount + 1, val->numberLength, ctx) + 1;
	IArrayObjectPrimitive<int>* resDigits = ArrayAllocatorPrimitive<int>::allocatep(ctx, resLength);
	int i = 0;
	int bitNumber = 1 << bitN;
	System::arraycopy(val->digits, 0, resDigits, 0, val->numberLength, ctx);
	if(val->sign < 0)
	{
		if(intCount >= val->numberLength)
		{
			resDigits->set(bitNumber,intCount, ctx);
		}
				else 
		{
			int firstNonZeroDigit = val->getFirstNonzeroDigit(ctx);
			if(intCount > firstNonZeroDigit)
			{
				resDigits->set(resDigits->get(intCount) ^ (bitNumber),intCount, ctx);
			}
						else 
			{
				if(intCount < firstNonZeroDigit)
				{
					resDigits->set(-bitNumber,intCount, ctx);
					for(i = intCount + 1; i < firstNonZeroDigit; i ++ )
					{
						resDigits->set(-1,i, ctx);
					}
					resDigits->set(resDigits->get(i),i, ctx);
					resDigits->set(resDigits->get(i) - 1,i, ctx);
				}
								else 
				{
					i = intCount;
					resDigits->set(-((-resDigits->get(intCount)) ^ bitNumber),i, ctx);
					if(resDigits->get(i) == 0)
					{
						for(i ++ ; resDigits->get(i) == -1; i ++ )
						{
							resDigits->set(0,i, ctx);
						}
						resDigits->set(resDigits->get(i) + 1,i, ctx);
					}
				}
			}
		}
	}
		else 
	{
		resDigits->set(resDigits->get(intCount) ^ (bitNumber),intCount, ctx);
	}
	BigInteger* result = (new(ctx) BigInteger(resSign, resLength, resDigits, ctx));
	result->cutOffLeadingZeroes(ctx);
	return result;
}
void BitLevel::__cleanUp(ThreadContext* ctx){
}
}}

