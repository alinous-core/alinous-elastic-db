#include "include/global.h"


#include "alinous.numeric/InternalDate.h"
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





BigInteger* BigInteger::ZERO = nullptr;
BigInteger* BigInteger::ONE = nullptr;
BigInteger* BigInteger::TEN = nullptr;
BigInteger* BigInteger::MINUS_ONE = nullptr;
constexpr const int BigInteger::EQUALS;
constexpr const int BigInteger::GREATER;
constexpr const int BigInteger::LESS;
IArrayObject<BigInteger>* BigInteger::SMALL_VALUES = nullptr;
IArrayObject<BigInteger>* BigInteger::TWO_POWS = nullptr;
bool BigInteger::__init_done = __init_static_variables();
bool BigInteger::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"BigInteger", L"__init_static_variables");
		__GC_MV(nullptr, &(ZERO), (new(ctx) BigInteger(0, 0, ctx)), BigInteger);
		__GC_MV(nullptr, &(ONE), (new(ctx) BigInteger(1, 1, ctx)), BigInteger);
		__GC_MV(nullptr, &(TEN), (new(ctx) BigInteger(1, 10, ctx)), BigInteger);
		__GC_MV(nullptr, &(MINUS_ONE), (new(ctx) BigInteger(-1, 1, ctx)), BigInteger);
		__GC_MV(nullptr, &(SMALL_VALUES), (new ArrayObject<BigInteger>({(new(ctx) BigInteger(0, 0, ctx)), (new(ctx) BigInteger(1, 1, ctx)), (new(ctx) BigInteger(1, 2, ctx)), (new(ctx) BigInteger(1, 3, ctx)), (new(ctx) BigInteger(1, 4, ctx)), (new(ctx) BigInteger(1, 5, ctx)), (new(ctx) BigInteger(1, 6, ctx)), (new(ctx) BigInteger(1, 7, ctx)), (new(ctx) BigInteger(1, 8, ctx)), (new(ctx) BigInteger(1, 9, ctx)), (new(ctx) BigInteger(1, 10, ctx))}, ctx)), IArrayObject<BigInteger>);
		__GC_MV(nullptr, &(TWO_POWS), nullptr, IArrayObject<BigInteger>);
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 BigInteger::BigInteger(int numBits, Random* rnd, ThreadContext* ctx) throw()  : IObject(ctx), Number(ctx), Comparable<BigInteger>(ctx), digits(nullptr), numberLength(0), sign(0), firstNonzeroDigit(-2), _hashCode(0)
{
	if(numBits < 0)
	{
		throw (new(ctx) IllegalArgumentException(ConstStr::getCNST_STR_50(), ctx));
	}
	if(numBits == 0)
	{
		sign = 0;
		numberLength = 1;
		__GC_MV(this, &(digits), ((IArrayObjectPrimitive<int>*)new(ctx) ArrayObjectPrimitive<int>({0}, ctx)), IArrayObjectPrimitive<int>);
	}
		else 
	{
		sign = 1;
		numberLength = (numBits + 31) >> 5;
		__GC_MV(this, &(digits), ArrayAllocatorPrimitive<int>::allocatep(ctx, numberLength), IArrayObjectPrimitive<int>);
		for(int i = 0; i < numberLength; i ++ )
		{
			digits->set(rnd->nextInt(ctx),i, ctx);
		}
		digits->set((-numBits) & 31,numberLength - 1, ctx);
		cutOffLeadingZeroes(ctx);
	}
}
void BigInteger::__construct_impl(int numBits, Random* rnd, ThreadContext* ctx) throw() 
{
	if(numBits < 0)
	{
		throw (new(ctx) IllegalArgumentException(ConstStr::getCNST_STR_50(), ctx));
	}
	if(numBits == 0)
	{
		sign = 0;
		numberLength = 1;
		__GC_MV(this, &(digits), ((IArrayObjectPrimitive<int>*)new(ctx) ArrayObjectPrimitive<int>({0}, ctx)), IArrayObjectPrimitive<int>);
	}
		else 
	{
		sign = 1;
		numberLength = (numBits + 31) >> 5;
		__GC_MV(this, &(digits), ArrayAllocatorPrimitive<int>::allocatep(ctx, numberLength), IArrayObjectPrimitive<int>);
		for(int i = 0; i < numberLength; i ++ )
		{
			digits->set(rnd->nextInt(ctx),i, ctx);
		}
		digits->set((-numBits) & 31,numberLength - 1, ctx);
		cutOffLeadingZeroes(ctx);
	}
}
 BigInteger::BigInteger(int bitLength, int certainty, Random* rnd, ThreadContext* ctx) throw()  : IObject(ctx), Number(ctx), Comparable<BigInteger>(ctx), digits(nullptr), numberLength(0), sign(0), firstNonzeroDigit(-2), _hashCode(0)
{
	if(bitLength < 2)
	{
		throw (new(ctx) ArithmeticException(ConstStr::getCNST_STR_51(), ctx));
	}
	BigInteger* me = Primality::consBigInteger(bitLength, certainty, rnd, ctx);
	sign = me->sign;
	numberLength = me->numberLength;
	__GC_MV(this, &(digits), me->digits, IArrayObjectPrimitive<int>);
}
void BigInteger::__construct_impl(int bitLength, int certainty, Random* rnd, ThreadContext* ctx) throw() 
{
	if(bitLength < 2)
	{
		throw (new(ctx) ArithmeticException(ConstStr::getCNST_STR_51(), ctx));
	}
	BigInteger* me = Primality::consBigInteger(bitLength, certainty, rnd, ctx);
	sign = me->sign;
	numberLength = me->numberLength;
	__GC_MV(this, &(digits), me->digits, IArrayObjectPrimitive<int>);
}
 BigInteger::BigInteger(String* val, ThreadContext* ctx) throw()  : IObject(ctx), Number(ctx), Comparable<BigInteger>(ctx), digits(nullptr), numberLength(0), sign(0), firstNonzeroDigit(-2), _hashCode(0)
{
	__construct_impl(val, 10, ctx);
}
void BigInteger::__construct_impl(String* val, ThreadContext* ctx) throw() 
{
	__construct_impl(val, 10, ctx);
}
 BigInteger::BigInteger(String* val, int radix, ThreadContext* ctx) throw()  : IObject(ctx), Number(ctx), Comparable<BigInteger>(ctx), digits(nullptr), numberLength(0), sign(0), firstNonzeroDigit(-2), _hashCode(0)
{
	if(val == nullptr)
	{
		throw (new(ctx) NullPointerException(ctx));
	}
	if((radix < Character::MIN_RADIX) || (radix > Character::MAX_RADIX))
	{
		throw (new(ctx) NumberFormatException(ConstStr::getCNST_STR_52(), ctx));
	}
	if(val->length(ctx) == 0)
	{
		throw (new(ctx) NumberFormatException(ConstStr::getCNST_STR_53(), ctx));
	}
	setFromString(this, val, radix, ctx);
}
void BigInteger::__construct_impl(String* val, int radix, ThreadContext* ctx) throw() 
{
	if(val == nullptr)
	{
		throw (new(ctx) NullPointerException(ctx));
	}
	if((radix < Character::MIN_RADIX) || (radix > Character::MAX_RADIX))
	{
		throw (new(ctx) NumberFormatException(ConstStr::getCNST_STR_52(), ctx));
	}
	if(val->length(ctx) == 0)
	{
		throw (new(ctx) NumberFormatException(ConstStr::getCNST_STR_53(), ctx));
	}
	setFromString(this, val, radix, ctx);
}
 BigInteger::BigInteger(int signum, IArrayObjectPrimitive<char>* magnitude, ThreadContext* ctx) throw()  : IObject(ctx), Number(ctx), Comparable<BigInteger>(ctx), digits(nullptr), numberLength(0), sign(0), firstNonzeroDigit(-2), _hashCode(0)
{
	if(magnitude == (IArrayObjectPrimitive<char>*)nullptr)
	{
		throw (new(ctx) NullPointerException(ctx));
	}
	if((signum < -1) || (signum > 1))
	{
		throw (new(ctx) NumberFormatException(ConstStr::getCNST_STR_54(), ctx));
	}
	if(signum == 0)
	{
		{
			const int __max_for = magnitude->length;
			for(int __i_loop = 0; __i_loop != __max_for; ++__i_loop){
				char element = magnitude->get(__i_loop);
				{
					if(element != (char)0)
					{
						throw (new(ctx) NumberFormatException(ConstStr::getCNST_STR_55(), ctx));
					}
				}
			}
		}
	}
	if(magnitude->length == 0)
	{
		sign = 0;
		numberLength = 1;
		__GC_MV(this, &(digits), ((IArrayObjectPrimitive<int>*)new(ctx) ArrayObjectPrimitive<int>({0}, ctx)), IArrayObjectPrimitive<int>);
	}
		else 
	{
		sign = signum;
		putBytesPositiveToIntegers(magnitude, ctx);
		cutOffLeadingZeroes(ctx);
	}
}
void BigInteger::__construct_impl(int signum, IArrayObjectPrimitive<char>* magnitude, ThreadContext* ctx) throw() 
{
	if(magnitude == (IArrayObjectPrimitive<char>*)nullptr)
	{
		throw (new(ctx) NullPointerException(ctx));
	}
	if((signum < -1) || (signum > 1))
	{
		throw (new(ctx) NumberFormatException(ConstStr::getCNST_STR_54(), ctx));
	}
	if(signum == 0)
	{
		{
			const int __max_for = magnitude->length;
			for(int __i_loop = 0; __i_loop != __max_for; ++__i_loop){
				char element = magnitude->get(__i_loop);
				{
					if(element != (char)0)
					{
						throw (new(ctx) NumberFormatException(ConstStr::getCNST_STR_55(), ctx));
					}
				}
			}
		}
	}
	if(magnitude->length == 0)
	{
		sign = 0;
		numberLength = 1;
		__GC_MV(this, &(digits), ((IArrayObjectPrimitive<int>*)new(ctx) ArrayObjectPrimitive<int>({0}, ctx)), IArrayObjectPrimitive<int>);
	}
		else 
	{
		sign = signum;
		putBytesPositiveToIntegers(magnitude, ctx);
		cutOffLeadingZeroes(ctx);
	}
}
 BigInteger::BigInteger(IArrayObjectPrimitive<char>* val, ThreadContext* ctx) throw()  : IObject(ctx), Number(ctx), Comparable<BigInteger>(ctx), digits(nullptr), numberLength(0), sign(0), firstNonzeroDigit(-2), _hashCode(0)
{
	if(val->length == 0)
	{
		throw (new(ctx) NumberFormatException(ConstStr::getCNST_STR_53(), ctx));
	}
	if(val->get(0) < (char)0)
	{
		sign = -1;
		putBytesNegativeToIntegers(val, ctx);
	}
		else 
	{
		sign = 1;
		putBytesPositiveToIntegers(val, ctx);
	}
	cutOffLeadingZeroes(ctx);
}
void BigInteger::__construct_impl(IArrayObjectPrimitive<char>* val, ThreadContext* ctx) throw() 
{
	if(val->length == 0)
	{
		throw (new(ctx) NumberFormatException(ConstStr::getCNST_STR_53(), ctx));
	}
	if(val->get(0) < (char)0)
	{
		sign = -1;
		putBytesNegativeToIntegers(val, ctx);
	}
		else 
	{
		sign = 1;
		putBytesPositiveToIntegers(val, ctx);
	}
	cutOffLeadingZeroes(ctx);
}
 BigInteger::BigInteger(int sign, int value, ThreadContext* ctx) throw()  : IObject(ctx), Number(ctx), Comparable<BigInteger>(ctx), digits(nullptr), numberLength(0), sign(0), firstNonzeroDigit(-2), _hashCode(0)
{
	this->sign = sign;
	numberLength = 1;
	__GC_MV(this, &(digits), ((IArrayObjectPrimitive<int>*)new(ctx) ArrayObjectPrimitive<int>({value}, ctx)), IArrayObjectPrimitive<int>);
}
void BigInteger::__construct_impl(int sign, int value, ThreadContext* ctx) throw() 
{
	this->sign = sign;
	numberLength = 1;
	__GC_MV(this, &(digits), ((IArrayObjectPrimitive<int>*)new(ctx) ArrayObjectPrimitive<int>({value}, ctx)), IArrayObjectPrimitive<int>);
}
 BigInteger::BigInteger(int sign, int numberLength, IArrayObjectPrimitive<int>* digits, ThreadContext* ctx) throw()  : IObject(ctx), Number(ctx), Comparable<BigInteger>(ctx), digits(nullptr), numberLength(0), sign(0), firstNonzeroDigit(-2), _hashCode(0)
{
	this->sign = sign;
	this->numberLength = numberLength;
	__GC_MV(this, &(this->digits), digits, IArrayObjectPrimitive<int>);
}
void BigInteger::__construct_impl(int sign, int numberLength, IArrayObjectPrimitive<int>* digits, ThreadContext* ctx) throw() 
{
	this->sign = sign;
	this->numberLength = numberLength;
	__GC_MV(this, &(this->digits), digits, IArrayObjectPrimitive<int>);
}
 BigInteger::BigInteger(int sign, long long val, ThreadContext* ctx) throw()  : IObject(ctx), Number(ctx), Comparable<BigInteger>(ctx), digits(nullptr), numberLength(0), sign(0), firstNonzeroDigit(-2), _hashCode(0)
{
	this->sign = sign;
	if((val & 0xFFFFFFFF00000000L) == (long long)0)
	{
		numberLength = 1;
		__GC_MV(this, &(digits), ((IArrayObjectPrimitive<int>*)new(ctx) ArrayObjectPrimitive<int>({((int)val)}, ctx)), IArrayObjectPrimitive<int>);
	}
		else 
	{
		numberLength = 2;
		__GC_MV(this, &(digits), ((IArrayObjectPrimitive<int>*)new(ctx) ArrayObjectPrimitive<int>({((int)val), ((int)(val >> 32))}, ctx)), IArrayObjectPrimitive<int>);
	}
}
void BigInteger::__construct_impl(int sign, long long val, ThreadContext* ctx) throw() 
{
	this->sign = sign;
	if((val & 0xFFFFFFFF00000000L) == (long long)0)
	{
		numberLength = 1;
		__GC_MV(this, &(digits), ((IArrayObjectPrimitive<int>*)new(ctx) ArrayObjectPrimitive<int>({((int)val)}, ctx)), IArrayObjectPrimitive<int>);
	}
		else 
	{
		numberLength = 2;
		__GC_MV(this, &(digits), ((IArrayObjectPrimitive<int>*)new(ctx) ArrayObjectPrimitive<int>({((int)val), ((int)(val >> 32))}, ctx)), IArrayObjectPrimitive<int>);
	}
}
 BigInteger::BigInteger(int signum, IArrayObjectPrimitive<int>* digits, ThreadContext* ctx) throw()  : IObject(ctx), Number(ctx), Comparable<BigInteger>(ctx), digits(nullptr), numberLength(0), sign(0), firstNonzeroDigit(-2), _hashCode(0)
{
	if(digits->length == 0)
	{
		sign = 0;
		numberLength = 1;
		__GC_MV(this, &(this->digits), ((IArrayObjectPrimitive<int>*)new(ctx) ArrayObjectPrimitive<int>({0}, ctx)), IArrayObjectPrimitive<int>);
	}
		else 
	{
		sign = signum;
		numberLength = digits->length;
		__GC_MV(this, &(this->digits), digits, IArrayObjectPrimitive<int>);
		cutOffLeadingZeroes(ctx);
	}
}
void BigInteger::__construct_impl(int signum, IArrayObjectPrimitive<int>* digits, ThreadContext* ctx) throw() 
{
	if(digits->length == 0)
	{
		sign = 0;
		numberLength = 1;
		__GC_MV(this, &(this->digits), ((IArrayObjectPrimitive<int>*)new(ctx) ArrayObjectPrimitive<int>({0}, ctx)), IArrayObjectPrimitive<int>);
	}
		else 
	{
		sign = signum;
		numberLength = digits->length;
		__GC_MV(this, &(this->digits), digits, IArrayObjectPrimitive<int>);
		cutOffLeadingZeroes(ctx);
	}
}
 BigInteger::~BigInteger() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void BigInteger::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"BigInteger", L"~BigInteger");
	__e_obj1.add(this->digits, this);
	digits = nullptr;
	if(!prepare){
		return;
	}
	Number::__releaseRegerences(true, ctx);
}
IArrayObjectPrimitive<char>* BigInteger::toByteArray(ThreadContext* ctx) throw() 
{
	if(this->sign == 0)
	{
		return ((IArrayObjectPrimitive<char>*)new(ctx) ArrayObjectPrimitive<char>({0}, ctx));
	}
	BigInteger* temp = this;
	int bitLen = bitLength(ctx);
	int iThis = getFirstNonzeroDigit(ctx);
	int bytesLen = (bitLen >> 3) + 1;
	IArrayObjectPrimitive<char>* bytes = ArrayAllocatorPrimitive<char>::allocatep(ctx, bytesLen);
	int firstByteNumber = 0;
	int highBytes = 0;
	int digitIndex = 0;
	int bytesInInteger = 4;
	int digit = 0;
	int hB = 0;
	if(bytesLen - (numberLength << 2) == 1)
	{
		bytes->set(((char)((sign < 0) ? -1 : 0)),0, ctx);
		highBytes = 4;
		firstByteNumber ++ ;
	}
		else 
	{
		hB = bytesLen & 3;
		highBytes = (hB == 0) ? 4 : hB;
	}
	digitIndex = iThis;
	bytesLen -= iThis << 2;
	if(sign < 0)
	{
		digit = -temp->digits->get(digitIndex);
		digitIndex ++ ;
		if(digitIndex == numberLength)
		{
			bytesInInteger = highBytes;
		}
		for(int i = 0; i < bytesInInteger; i ++ , digit >>= 8)
		{
			bytes->set(((char)digit),--bytesLen, ctx);
		}
		while(bytesLen > firstByteNumber)
		{
			digit = ~temp->digits->get(digitIndex);
			digitIndex ++ ;
			if(digitIndex == numberLength)
			{
				bytesInInteger = highBytes;
			}
			for(int i = 0; i < bytesInInteger; i ++ , digit >>= 8)
			{
				bytes->set(((char)digit),--bytesLen, ctx);
			}
		}
	}
		else 
	{
		while(bytesLen > firstByteNumber)
		{
			digit = temp->digits->get(digitIndex);
			digitIndex ++ ;
			if(digitIndex == numberLength)
			{
				bytesInInteger = highBytes;
			}
			for(int i = 0; i < bytesInInteger; i ++ , digit >>= 8)
			{
				bytes->set(((char)digit),--bytesLen, ctx);
			}
		}
	}
	return bytes;
}
BigInteger* BigInteger::abs(ThreadContext* ctx) throw() 
{
	return ((sign < 0) ? (new(ctx) BigInteger(1, numberLength, digits, ctx)) : this);
}
BigInteger* BigInteger::negate(ThreadContext* ctx) throw() 
{
	return ((sign == 0) ? this : (new(ctx) BigInteger(-sign, numberLength, digits, ctx)));
}
BigInteger* BigInteger::add(BigInteger* val, ThreadContext* ctx) throw() 
{
	return Elementary::add(this, val, ctx);
}
BigInteger* BigInteger::subtract(BigInteger* val, ThreadContext* ctx) throw() 
{
	return Elementary::subtract(this, val, ctx);
}
int BigInteger::signum(ThreadContext* ctx) throw() 
{
	return sign;
}
BigInteger* BigInteger::shiftRight(int n, ThreadContext* ctx) throw() 
{
	if((n == 0) || (sign == 0))
	{
		return this;
	}
	return ((n > 0) ? BitLevel::shiftRight(this, n, ctx) : BitLevel::shiftLeft(this, -n, ctx));
}
BigInteger* BigInteger::shiftLeft(int n, ThreadContext* ctx) throw() 
{
	if((n == 0) || (sign == 0))
	{
		return this;
	}
	return ((n > 0) ? BitLevel::shiftLeft(this, n, ctx) : BitLevel::shiftRight(this, -n, ctx));
}
int BigInteger::bitLength(ThreadContext* ctx) throw() 
{
	return BitLevel::bitLength(this, ctx);
}
bool BigInteger::testBit(int n, ThreadContext* ctx) throw() 
{
	if(n == 0)
	{
		return ((digits->get(0) & 1) != 0);
	}
	if(n < 0)
	{
		throw (new(ctx) ArithmeticException(ConstStr::getCNST_STR_56(), ctx));
	}
	int intCount = n >> 5;
	if(intCount >= numberLength)
	{
		return (sign < 0);
	}
	int digit = digits->get(intCount);
	n = (1 << (n & 31));
	if(sign < 0)
	{
		int firstNonZeroDigit = getFirstNonzeroDigit(ctx);
		if(intCount < firstNonZeroDigit)
		{
			return false;
		}
				else 
		{
			if(firstNonZeroDigit == intCount)
			{
				digit = -digit;
			}
						else 
			{
				digit = ~digit;
			}
		}
	}
	return ((digit & n) != 0);
}
BigInteger* BigInteger::setBit(int n, ThreadContext* ctx) throw() 
{
	if(!testBit(n, ctx))
	{
		return BitLevel::flipBit(this, n, ctx);
	}
	return this;
}
BigInteger* BigInteger::clearBit(int n, ThreadContext* ctx) throw() 
{
	if(testBit(n, ctx))
	{
		return BitLevel::flipBit(this, n, ctx);
	}
	return this;
}
BigInteger* BigInteger::flipBit(int n, ThreadContext* ctx) throw() 
{
	if(n < 0)
	{
		throw (new(ctx) ArithmeticException(ConstStr::getCNST_STR_56(), ctx));
	}
	return BitLevel::flipBit(this, n, ctx);
}
int BigInteger::getLowestSetBit(ThreadContext* ctx) throw() 
{
	if(sign == 0)
	{
		return -1;
	}
	int i = getFirstNonzeroDigit(ctx);
	return ((i << 5) + Integer::numberOfTrailingZeros(digits->get(i), ctx));
}
int BigInteger::bitCount(ThreadContext* ctx) throw() 
{
	return BitLevel::bitCount(this, ctx);
}
BigInteger* BigInteger::_not(ThreadContext* ctx) throw() 
{
	return Logical::_not(this, ctx);
}
BigInteger* BigInteger::_and(BigInteger* val, ThreadContext* ctx) throw() 
{
	return Logical::_and(this, val, ctx);
}
BigInteger* BigInteger::_or(BigInteger* val, ThreadContext* ctx) throw() 
{
	return Logical::_or(this, val, ctx);
}
BigInteger* BigInteger::_xor(BigInteger* val, ThreadContext* ctx) throw() 
{
	return Logical::_xor(this, val, ctx);
}
BigInteger* BigInteger::andNot(BigInteger* val, ThreadContext* ctx) throw() 
{
	return Logical::andNot(this, val, ctx);
}
int BigInteger::intValue(ThreadContext* ctx) throw() 
{
	return (sign * digits->get(0));
}
long long BigInteger::longValue(ThreadContext* ctx) throw() 
{
	long long value = (numberLength > 1) ? ((((long long)digits->get(1))) << 32) | (digits->get(0) & 0xFFFFFFFFL) : (digits->get(0) & 0xFFFFFFFFL);
	return (sign * value);
}
float BigInteger::floatValue(ThreadContext* ctx) throw() 
{
	return ((float)doubleValue(ctx));
}
double BigInteger::doubleValue(ThreadContext* ctx) throw() 
{
	return Conversion::bigInteger2Double(this, ctx);
}
int BigInteger::compareTo(BigInteger* val, ThreadContext* ctx) throw() 
{
	if(sign > val->sign)
	{
		return GREATER;
	}
	if(sign < val->sign)
	{
		return LESS;
	}
	if(numberLength > val->numberLength)
	{
		return sign;
	}
	if(numberLength < val->numberLength)
	{
		return -val->sign;
	}
	return (sign * Elementary::compareArrays(digits, val->digits, numberLength, ctx));
}
BigInteger* BigInteger::min(BigInteger* val, ThreadContext* ctx) throw() 
{
	return ((this->compareTo(val, ctx) == LESS) ? this : val);
}
BigInteger* BigInteger::max(BigInteger* val, ThreadContext* ctx) throw() 
{
	return ((this->compareTo(val, ctx) == GREATER) ? this : val);
}
int BigInteger::hashCode(ThreadContext* ctx) throw() 
{
	if(_hashCode != 0)
	{
		return _hashCode;
	}
	for(int i = 0; i < digits->length; i ++ )
	{
		_hashCode = (_hashCode * 33 + (digits->get(i) & 0xffffffff));
	}
	_hashCode = _hashCode * sign;
	return _hashCode;
}
bool BigInteger::equals(IObject* x, ThreadContext* ctx) throw() 
{
	if(this == x)
	{
		return true;
	}
	if((dynamic_cast<BigInteger*>(x) != 0))
	{
		BigInteger* x1 = dynamic_cast<BigInteger*>(x);
		return sign == x1->sign && numberLength == x1->numberLength && equalsArrays(x1->digits, ctx);
	}
	return false;
}
String* BigInteger::toString(ThreadContext* ctx) throw() 
{
	return Conversion::toDecimalScaledString(this, 0, ctx);
}
String* BigInteger::toString(int radix, ThreadContext* ctx) throw() 
{
	return Conversion::bigInteger2String(this, radix, ctx);
}
BigInteger* BigInteger::gcd(BigInteger* val, ThreadContext* ctx) throw() 
{
	BigInteger* val1 = this->abs(ctx);
	BigInteger* val2 = val->abs(ctx);
	if(val1->signum(ctx) == 0)
	{
		return val2;
	}
		else 
	{
		if(val2->signum(ctx) == 0)
		{
			return val1;
		}
	}
	if(((val1->numberLength == 1) || ((val1->numberLength == 2) && (val1->digits->get(1) > 0))) && (val2->numberLength == 1 || (val2->numberLength == 2 && val2->digits->get(1) > 0)))
	{
		return BigInteger::valueOf(Division::gcdBinary(val1->longValue(ctx), val2->longValue(ctx), ctx), ctx);
	}
	return Division::gcdBinary(val1->copy(ctx), val2->copy(ctx), ctx);
}
BigInteger* BigInteger::multiply(BigInteger* val, ThreadContext* ctx) throw() 
{
	if(val->sign == 0)
	{
		return ZERO;
	}
	if(sign == 0)
	{
		return ZERO;
	}
	return Multiplication::multiply(this, val, ctx);
}
BigInteger* BigInteger::pow(int exp, ThreadContext* ctx) throw() 
{
	if(exp < 0)
	{
		throw (new(ctx) ArithmeticException(ConstStr::getCNST_STR_57(), ctx));
	}
	if(exp == 0)
	{
		return ONE;
	}
		else 
	{
		if(exp == 1 || equals(ONE, ctx) || equals(ZERO, ctx))
		{
			return this;
		}
	}
	if(!testBit(0, ctx))
	{
		int x = 1;
		while(!testBit(x, ctx))
		{
			x ++ ;
		}
		return getPowerOfTwo(x * exp, ctx)->multiply(this->shiftRight(x, ctx)->pow(exp, ctx), ctx);
	}
	return Multiplication::pow(this, exp, ctx);
}
IArrayObject<BigInteger>* BigInteger::divideAndRemainder(BigInteger* divisor, ThreadContext* ctx) throw() 
{
	int divisorSign = divisor->sign;
	if(divisorSign == 0)
	{
		throw (new(ctx) ArithmeticException(ConstStr::getCNST_STR_58(), ctx));
	}
	int divisorLen = divisor->numberLength;
	IArrayObjectPrimitive<int>* divisorDigits = divisor->digits;
	if(divisorLen == 1)
	{
		return Division::divideAndRemainderByInteger(this, divisorDigits->get(0), divisorSign, ctx);
	}
	IArrayObjectPrimitive<int>* thisDigits = digits;
	int thisLen = numberLength;
	int cmp = (thisLen != divisorLen) ? ((thisLen > divisorLen) ? 1 : -1) : Elementary::compareArrays(thisDigits, divisorDigits, thisLen, ctx);
	if(cmp < 0)
	{
		return ((IArrayObject<BigInteger>*)new(ctx) ArrayObject<BigInteger>({ZERO, this}, ctx));
	}
	int thisSign = sign;
	int quotientLength = thisLen - divisorLen + 1;
	int remainderLength = divisorLen;
	int quotientSign = ((thisSign == divisorSign) ? 1 : -1);
	IArrayObjectPrimitive<int>* quotientDigits = ArrayAllocatorPrimitive<int>::allocatep(ctx, quotientLength);
	IArrayObjectPrimitive<int>* remainderDigits = Division::divide(quotientDigits, quotientLength, thisDigits, thisLen, divisorDigits, divisorLen, ctx);
	BigInteger* result0 = (new(ctx) BigInteger(quotientSign, quotientLength, quotientDigits, ctx));
	BigInteger* result1 = (new(ctx) BigInteger(thisSign, remainderLength, remainderDigits, ctx));
	result0->cutOffLeadingZeroes(ctx);
	result1->cutOffLeadingZeroes(ctx);
	return ((IArrayObject<BigInteger>*)new(ctx) ArrayObject<BigInteger>({result0, result1}, ctx));
}
BigInteger* BigInteger::divide(BigInteger* divisor, ThreadContext* ctx) throw() 
{
	if(divisor->sign == 0)
	{
		throw (new(ctx) ArithmeticException(ConstStr::getCNST_STR_58(), ctx));
	}
	int divisorSign = divisor->sign;
	if(divisor->isOne(ctx))
	{
		return ((divisor->sign > 0) ? this : this->negate(ctx));
	}
	int thisSign = sign;
	int thisLen = numberLength;
	int divisorLen = divisor->numberLength;
	if(thisLen + divisorLen == 2)
	{
		long long val = (digits->get(0) & 0xFFFFFFFFL) / (divisor->digits->get(0) & 0xFFFFFFFFL);
		if(thisSign != divisorSign)
		{
			val = -val;
		}
		return valueOf(val, ctx);
	}
	int cmp = ((thisLen != divisorLen) ? ((thisLen > divisorLen) ? 1 : -1) : Elementary::compareArrays(digits, divisor->digits, thisLen, ctx));
	if(cmp == EQUALS)
	{
		return ((thisSign == divisorSign) ? ONE : MINUS_ONE);
	}
	if(cmp == LESS)
	{
		return ZERO;
	}
	int resLength = thisLen - divisorLen + 1;
	IArrayObjectPrimitive<int>* resDigits = ArrayAllocatorPrimitive<int>::allocatep(ctx, resLength);
	int resSign = ((thisSign == divisorSign) ? 1 : -1);
	if(divisorLen == 1)
	{
		Division::divideArrayByInt(resDigits, digits, thisLen, divisor->digits->get(0), ctx);
	}
		else 
	{
		Division::divide(resDigits, resLength, digits, thisLen, divisor->digits, divisorLen, ctx);
	}
	BigInteger* result = (new(ctx) BigInteger(resSign, resLength, resDigits, ctx));
	result->cutOffLeadingZeroes(ctx);
	return result;
}
BigInteger* BigInteger::remainder(BigInteger* divisor, ThreadContext* ctx) throw() 
{
	if(divisor->sign == 0)
	{
		throw (new(ctx) ArithmeticException(ConstStr::getCNST_STR_58(), ctx));
	}
	int thisLen = numberLength;
	int divisorLen = divisor->numberLength;
	if(((thisLen != divisorLen) ? ((thisLen > divisorLen) ? 1 : -1) : Elementary::compareArrays(digits, divisor->digits, thisLen, ctx)) == LESS)
	{
		return this;
	}
	int resLength = divisorLen;
	IArrayObjectPrimitive<int>* resDigits = ArrayAllocatorPrimitive<int>::allocatep(ctx, resLength);
	if(resLength == 1)
	{
		resDigits->set(Division::remainderArrayByInt(digits, thisLen, divisor->digits->get(0), ctx),0, ctx);
	}
		else 
	{
		int qLen = thisLen - divisorLen + 1;
		resDigits = Division::divide((IArrayObjectPrimitive<int>*)nullptr, qLen, digits, thisLen, divisor->digits, divisorLen, ctx);
	}
	BigInteger* result = (new(ctx) BigInteger(sign, resLength, resDigits, ctx));
	result->cutOffLeadingZeroes(ctx);
	return result;
}
BigInteger* BigInteger::modInverse(BigInteger* m, ThreadContext* ctx) throw() 
{
	if(m->sign <= 0)
	{
		throw (new(ctx) ArithmeticException(ConstStr::getCNST_STR_59(), ctx));
	}
	if(!(testBit(0, ctx) || m->testBit(0, ctx)))
	{
		throw (new(ctx) ArithmeticException(ConstStr::getCNST_STR_60(), ctx));
	}
	if(m->isOne(ctx))
	{
		return ZERO;
	}
	BigInteger* res = Division::modInverseMontgomery(abs(ctx)->mod(m, ctx), m, ctx);
	if(res->sign == 0)
	{
		throw (new(ctx) ArithmeticException(ConstStr::getCNST_STR_60(), ctx));
	}
	res = ((sign < 0) ? m->subtract(res, ctx) : res);
	return res;
}
BigInteger* BigInteger::modPow(BigInteger* exponent, BigInteger* m, ThreadContext* ctx) throw() 
{
	if(m->sign <= 0)
	{
		throw (new(ctx) ArithmeticException(ConstStr::getCNST_STR_59(), ctx));
	}
	BigInteger* base = this;
	if(m->isOne(ctx) | ((exponent->sign > 0) & (base->sign == 0)))
	{
		return BigInteger::ZERO;
	}
	if(exponent->sign == 0)
	{
		return BigInteger::ONE->mod(m, ctx);
	}
	if(exponent->sign < 0)
	{
		base = modInverse(m, ctx);
		exponent = exponent->negate(ctx);
	}
	BigInteger* res = (m->testBit(0, ctx)) ? Division::oddModPow(base->abs(ctx), exponent, m, ctx) : Division::evenModPow(base->abs(ctx), exponent, m, ctx);
	if((base->sign < 0) && exponent->testBit(0, ctx))
	{
		res = m->subtract(BigInteger::ONE, ctx)->multiply(res, ctx)->mod(m, ctx);
	}
	return res;
}
BigInteger* BigInteger::mod(BigInteger* m, ThreadContext* ctx) throw() 
{
	if(m->sign <= 0)
	{
		throw (new(ctx) ArithmeticException(ConstStr::getCNST_STR_59(), ctx));
	}
	BigInteger* rem = remainder(m, ctx);
	return ((rem->sign < 0) ? rem->add(m, ctx) : rem);
}
bool BigInteger::isProbablePrime(int certainty, ThreadContext* ctx) throw() 
{
	return Primality::isProbablePrime(abs(ctx), certainty, ctx);
}
BigInteger* BigInteger::nextProbablePrime(ThreadContext* ctx) throw() 
{
	if(sign < 0)
	{
		throw (new(ctx) ArithmeticException(ConstStr::getCNST_STR_61(), ctx));
	}
	return Primality::nextProbablePrime(this, ctx);
}
BigInteger* BigInteger::shiftLeftOneBit(ThreadContext* ctx) throw() 
{
	return (sign == 0) ? this : BitLevel::shiftLeftOneBit(this, ctx);
}
bool BigInteger::equalsArrays(IArrayObjectPrimitive<int>* b, ThreadContext* ctx) throw() 
{
	int i = 0;
	for(i = numberLength - 1; (i >= 0) && (digits->get(i) == b->get(i)); i -- )
	{
	}
	return i < 0;
}
void BigInteger::cutOffLeadingZeroes(ThreadContext* ctx) throw() 
{
	while((numberLength > 0) && (digits->get(--numberLength) == 0))
	{
	}
	if(digits->get(numberLength++) == 0)
	{
		sign = 0;
	}
}
bool BigInteger::isOne(ThreadContext* ctx) throw() 
{
	return ((numberLength == 1) && (digits->get(0) == 1));
}
int BigInteger::getFirstNonzeroDigit(ThreadContext* ctx) throw() 
{
	if(firstNonzeroDigit == -2)
	{
		int i = 0;
		if(this->sign == 0)
		{
			i = -1;
		}
				else 
		{
			for(i = 0; digits->get(i) == 0; i ++ )
			{
			}
		}
		firstNonzeroDigit = i;
	}
	return firstNonzeroDigit;
}
BigInteger* BigInteger::copy(ThreadContext* ctx) throw() 
{
	IArrayObjectPrimitive<int>* copyDigits = ArrayAllocatorPrimitive<int>::allocatep(ctx, numberLength);
	System::arraycopy(digits, 0, copyDigits, 0, numberLength, ctx);
	return (new(ctx) BigInteger(sign, numberLength, copyDigits, ctx));
}
void BigInteger::unCache(ThreadContext* ctx) throw() 
{
	firstNonzeroDigit = -2;
}
void BigInteger::putBytesPositiveToIntegers(IArrayObjectPrimitive<char>* byteValues, ThreadContext* ctx) throw() 
{
	int bytesLen = byteValues->length;
	int highBytes = bytesLen & 3;
	numberLength = (bytesLen >> 2) + ((highBytes == 0) ? 0 : 1);
	__GC_MV(this, &(digits), ArrayAllocatorPrimitive<int>::allocatep(ctx, numberLength), IArrayObjectPrimitive<int>);
	int i = 0;
	while(bytesLen > highBytes)
	{
		int dg = (byteValues->get(--bytesLen) & 0xFF);
		dg = dg | (byteValues->get(--bytesLen) & 0xFF) << 8;
		dg = dg | (byteValues->get(--bytesLen) & 0xFF) << 16;
		dg = dg | (byteValues->get(--bytesLen) & 0xFF) << 24;
		digits->set(dg,i++, ctx);
	}
	for(int j = 0; j < bytesLen; j ++ )
	{
		digits->set((digits->get(i) << 8) | (byteValues->get(j) & 0xFF),i, ctx);
	}
}
void BigInteger::putBytesNegativeToIntegers(IArrayObjectPrimitive<char>* byteValues, ThreadContext* ctx) throw() 
{
	int bytesLen = byteValues->length;
	int highBytes = bytesLen & 3;
	numberLength = (bytesLen >> 2) + ((highBytes == 0) ? 0 : 1);
	__GC_MV(this, &(digits), ArrayAllocatorPrimitive<int>::allocatep(ctx, numberLength), IArrayObjectPrimitive<int>);
	int i = 0;
	digits->set(-1,numberLength - 1, ctx);
	while(bytesLen > highBytes)
	{
		int dg = (byteValues->get(--bytesLen) & 0xFF);
		dg = dg | (byteValues->get(--bytesLen) & 0xFF) << 8;
		dg = dg | (byteValues->get(--bytesLen) & 0xFF) << 16;
		dg = dg | (byteValues->get(--bytesLen) & 0xFF) << 24;
		digits->set(dg,i, ctx);
		if(digits->get(i) != 0)
		{
			digits->set(-digits->get(i),i, ctx);
			firstNonzeroDigit = i;
			i ++ ;
			while(bytesLen > highBytes)
			{
				dg = (byteValues->get(--bytesLen) & 0xFF);
				dg = dg | (byteValues->get(--bytesLen) & 0xFF) << 8;
				dg = dg | (byteValues->get(--bytesLen) & 0xFF) << 16;
				dg = dg | (byteValues->get(--bytesLen) & 0xFF) << 24;
				digits->set(dg,i, ctx);
				digits->set(~digits->get(i),i, ctx);
				i ++ ;
			}
			break ;
		}
		i ++ ;
	}
	if(highBytes != 0)
	{
		if(firstNonzeroDigit != -2)
		{
			for(int j = 0; j < bytesLen; j ++ )
			{
				digits->set((digits->get(i) << 8) | (byteValues->get(j) & 0xFF),i, ctx);
			}
			digits->set(~digits->get(i),i, ctx);
		}
				else 
		{
			for(int j = 0; j < bytesLen; j ++ )
			{
				digits->set((digits->get(i) << 8) | (byteValues->get(j) & 0xFF),i, ctx);
			}
			digits->set(-digits->get(i),i, ctx);
		}
	}
}
void BigInteger::staticInit(ThreadContext* ctx) throw() 
{
	__GC_MV(nullptr, &(TWO_POWS), ArrayAllocator<BigInteger>::allocate(ctx, 32), IArrayObject<BigInteger>);
	for(int i = 0; i < TWO_POWS->length; i ++ )
	{
		TWO_POWS->set(BigInteger::valueOf((long long)1L << i, ctx),i, ctx);
	}
}
BigInteger* BigInteger::valueOf(long long val, ThreadContext* ctx) throw() 
{
	if(val < (long long)0)
	{
		if(val != (long long)-1)
		{
			return (new(ctx) BigInteger(-1, -val, ctx));
		}
		return MINUS_ONE;
	}
		else 
	{
		if(val <= (long long)10)
		{
			return SMALL_VALUES->get(((int)val));
		}
				else 
		{
			return (new(ctx) BigInteger(1, val, ctx));
		}
	}
}
BigInteger* BigInteger::probablePrime(int bitLength, Random* rnd, ThreadContext* ctx) throw() 
{
	return (new(ctx) BigInteger(bitLength, 100, rnd, ctx));
}
BigInteger* BigInteger::getPowerOfTwo(int exp, ThreadContext* ctx) throw() 
{
	if(exp < TWO_POWS->length)
	{
		return TWO_POWS->get(exp);
	}
	int intCount = exp >> 5;
	int bitN = exp & 31;
	IArrayObjectPrimitive<int>* resDigits = ArrayAllocatorPrimitive<int>::allocatep(ctx, intCount + 1);
	resDigits->set(1 << bitN,intCount, ctx);
	return (new(ctx) BigInteger(1, intCount + 1, resDigits, ctx));
}
void BigInteger::setFromString(BigInteger* bi, String* val, int radix, ThreadContext* ctx) throw() 
{
	int sign = 0;
	IArrayObjectPrimitive<int>* digits = 0;
	int numberLength = 0;
	int stringLength = val->length(ctx);
	int startChar = 0;
	int endChar = stringLength;
	if(val->charAt(0, ctx) == L'-')
	{
		sign = -1;
		startChar = 1;
		stringLength -- ;
	}
		else 
	{
		sign = 1;
		startChar = 0;
	}
	int charsPerInt = Conversion::digitFitInInt->get(radix);
	int bigRadixDigitsLength = stringLength / charsPerInt;
	int topChars = stringLength % charsPerInt;
	if(topChars != 0)
	{
		bigRadixDigitsLength ++ ;
	}
	digits = ArrayAllocatorPrimitive<int>::allocatep(ctx, bigRadixDigitsLength);
	int bigRadix = Conversion::bigRadices->get(radix - 2);
	int digitIndex = 0;
	int substrEnd = startChar + ((topChars == 0) ? charsPerInt : topChars);
	int newDigit = 0;
	for(int substrStart = startChar; substrStart < endChar; )
	{
		int bigRadixDigit = Integer::parseInt(val->substring(substrStart, substrEnd, ctx), radix, ctx);
		newDigit = Multiplication::multiplyByInt(digits, digitIndex, bigRadix, ctx);
		newDigit += Elementary::inplaceAdd(digits, digitIndex, bigRadixDigit, ctx);
		digits->set(newDigit,digitIndex++, ctx);
		substrStart = substrEnd;
		substrEnd = substrStart + charsPerInt;
	}
	numberLength = digitIndex;
	bi->sign = sign;
	bi->numberLength = numberLength;
	__GC_MV(bi, &(bi->digits), digits, IArrayObjectPrimitive<int>);
	bi->cutOffLeadingZeroes(ctx);
}
int BigInteger::ValueCompare::operator() (BigInteger* _this, BigInteger* val, ThreadContext* ctx) const throw()
{
	return _this->compareTo(val, ctx);
}
}}

