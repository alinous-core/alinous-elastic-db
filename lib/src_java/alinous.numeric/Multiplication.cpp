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





constexpr const int Multiplication::whenUseKaratsuba;
const StaticArrayObjectPrimitive<int> Multiplication::__tenPows = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000};
IArrayObjectPrimitive<int>* Multiplication::tenPows = (IArrayObjectPrimitive<int>*)const_cast<StaticArrayObjectPrimitive<int>*>(&__tenPows);
const StaticArrayObjectPrimitive<int> Multiplication::__fivePows = {1, 5, 25, 125, 625, 3125, 15625, 78125, 390625, 1953125, 9765625, 48828125, 244140625, 1220703125};
IArrayObjectPrimitive<int>* Multiplication::fivePows = (IArrayObjectPrimitive<int>*)const_cast<StaticArrayObjectPrimitive<int>*>(&__fivePows);
IArrayObject<BigInteger>* Multiplication::bigTenPows = nullptr;
IArrayObject<BigInteger>* Multiplication::bigFivePows = nullptr;
bool Multiplication::__init_done = __init_static_variables();
bool Multiplication::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"Multiplication", L"__init_static_variables");
		__GC_MV(nullptr, &(bigTenPows), (new ArrayObject<BigInteger>(ArrayAllocator<BigInteger>::allocate(ctx, 32), ctx)), IArrayObject<BigInteger>);
		__GC_MV(nullptr, &(bigFivePows), (new ArrayObject<BigInteger>(ArrayAllocator<BigInteger>::allocate(ctx, 32), ctx)), IArrayObject<BigInteger>);
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 Multiplication::~Multiplication() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void Multiplication::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
}
void Multiplication::initByBigInt(ThreadContext* ctx) throw() 
{
	int i = 0;
	long long fivePow = 1L;
	for(i = 0; i <= 18; i ++ )
	{
		bigFivePows->set(BigInteger::valueOf(fivePow, ctx),i, ctx);
		bigTenPows->set(BigInteger::valueOf(fivePow << i, ctx),i, ctx);
		fivePow *= 5;
	}
	for(; i < bigTenPows->length; i ++ )
	{
		bigFivePows->set(bigFivePows->get(i - 1)->multiply(bigFivePows->get(1), ctx),i, ctx);
		bigTenPows->set(bigTenPows->get(i - 1)->multiply(BigInteger::TEN, ctx),i, ctx);
	}
}
BigInteger* Multiplication::multiply(BigInteger* x, BigInteger* y, ThreadContext* ctx) throw() 
{
	return karatsuba(x, y, ctx);
}
BigInteger* Multiplication::karatsuba(BigInteger* op1, BigInteger* op2, ThreadContext* ctx) throw() 
{
	BigInteger* temp = 0;
	if(op2->numberLength > op1->numberLength)
	{
		temp = op1;
		op1 = op2;
		op2 = temp;
	}
	if(op2->numberLength < whenUseKaratsuba)
	{
		return multiplyPAP(op1, op2, ctx);
	}
	int ndiv2 = (op1->numberLength & 0xFFFFFFFE) << 4;
	BigInteger* upperOp1 = op1->shiftRight(ndiv2, ctx);
	BigInteger* upperOp2 = op2->shiftRight(ndiv2, ctx);
	BigInteger* lowerOp1 = op1->subtract(upperOp1->shiftLeft(ndiv2, ctx), ctx);
	BigInteger* lowerOp2 = op2->subtract(upperOp2->shiftLeft(ndiv2, ctx), ctx);
	BigInteger* upper = karatsuba(upperOp1, upperOp2, ctx);
	BigInteger* lower = karatsuba(lowerOp1, lowerOp2, ctx);
	BigInteger* middle = karatsuba(upperOp1->subtract(lowerOp1, ctx), lowerOp2->subtract(upperOp2, ctx), ctx);
	middle = middle->add(upper, ctx)->add(lower, ctx);
	middle = middle->shiftLeft(ndiv2, ctx);
	upper = upper->shiftLeft(ndiv2 << 1, ctx);
	return upper->add(middle, ctx)->add(lower, ctx);
}
BigInteger* Multiplication::multiplyPAP(BigInteger* a, BigInteger* b, ThreadContext* ctx) throw() 
{
	int aLen = a->numberLength;
	int bLen = b->numberLength;
	int resLength = aLen + bLen;
	int resSign = (a->sign != b->sign) ? -1 : 1;
	if(resLength == 2)
	{
		long long val = unsignedMultAddAdd(a->digits->get(0), b->digits->get(0), 0, 0, ctx);
		int valueLo = ((int)val);
		int valueHi = ((int)(((unsigned long long)val)>> 32));
		return ((valueHi == 0) ? (new(ctx) BigInteger(resSign, valueLo, ctx)) : (new(ctx) BigInteger(resSign, 2, ((IArrayObjectPrimitive<int>*)new(ctx) ArrayObjectPrimitive<int>({valueLo, valueHi}, ctx)), ctx)));
	}
	IArrayObjectPrimitive<int>* aDigits = a->digits;
	IArrayObjectPrimitive<int>* bDigits = b->digits;
	IArrayObjectPrimitive<int>* resDigits = ArrayAllocatorPrimitive<int>::allocatep(ctx, resLength);
	multArraysPAP(aDigits, aLen, bDigits, bLen, resDigits, ctx);
	BigInteger* result = (new(ctx) BigInteger(resSign, resLength, resDigits, ctx));
	result->cutOffLeadingZeroes(ctx);
	return result;
}
void Multiplication::multArraysPAP(IArrayObjectPrimitive<int>* aDigits, int aLen, IArrayObjectPrimitive<int>* bDigits, int bLen, IArrayObjectPrimitive<int>* resDigits, ThreadContext* ctx) throw() 
{
	if(aLen == 0 || bLen == 0)
	{
		return;
	}
	if(aLen == 1)
	{
		resDigits->set(multiplyByInt(resDigits, bDigits, bLen, aDigits->get(0), ctx),bLen, ctx);
	}
		else 
	{
		if(bLen == 1)
		{
			resDigits->set(multiplyByInt(resDigits, aDigits, aLen, bDigits->get(0), ctx),aLen, ctx);
		}
				else 
		{
			multPAP(aDigits, bDigits, resDigits, aLen, bLen, ctx);
		}
	}
}
void Multiplication::multPAP(IArrayObjectPrimitive<int>* a, IArrayObjectPrimitive<int>* b, IArrayObjectPrimitive<int>* t, int aLen, int bLen, ThreadContext* ctx) throw() 
{
	if(a == b && aLen == bLen)
	{
		square(a, aLen, t, ctx);
		return;
	}
	for(int i = 0; i < aLen; i ++ )
	{
		long long carry = 0;
		int aI = a->get(i);
		for(int j = 0; j < bLen; j ++ )
		{
			carry = unsignedMultAddAdd(aI, b->get(j), t->get(i + j), ((int)carry), ctx);
			t->set(((int)carry),i + j, ctx);
			carry = ((unsigned long long)carry) >> 32;
		}
		t->set(((int)carry),i + bLen, ctx);
	}
}
int Multiplication::multiplyByInt(IArrayObjectPrimitive<int>* a, int aSize, int factor, ThreadContext* ctx) throw() 
{
	return multiplyByInt(a, a, aSize, factor, ctx);
}
BigInteger* Multiplication::multiplyByPositiveInt(BigInteger* val, int factor, ThreadContext* ctx) throw() 
{
	int resSign = val->sign;
	if(resSign == 0)
	{
		return BigInteger::ZERO;
	}
	int aNumberLength = val->numberLength;
	IArrayObjectPrimitive<int>* aDigits = val->digits;
	if(aNumberLength == 1)
	{
		long long res = unsignedMultAddAdd(aDigits->get(0), factor, 0, 0, ctx);
		int resLo = ((int)res);
		int resHi = ((int)(((unsigned long long)res)>> 32));
		return ((resHi == 0) ? (new(ctx) BigInteger(resSign, resLo, ctx)) : (new(ctx) BigInteger(resSign, 2, ((IArrayObjectPrimitive<int>*)new(ctx) ArrayObjectPrimitive<int>({resLo, resHi}, ctx)), ctx)));
	}
	int resLength = aNumberLength + 1;
	IArrayObjectPrimitive<int>* resDigits = ArrayAllocatorPrimitive<int>::allocatep(ctx, resLength);
	resDigits->set(multiplyByInt(resDigits, aDigits, aNumberLength, factor, ctx),aNumberLength, ctx);
	BigInteger* result = (new(ctx) BigInteger(resSign, resLength, resDigits, ctx));
	result->cutOffLeadingZeroes(ctx);
	return result;
}
BigInteger* Multiplication::pow(BigInteger* base, int exponent, ThreadContext* ctx) throw() 
{
	BigInteger* res = BigInteger::ONE;
	BigInteger* acc = base;
	for(; exponent > 1; exponent >>= 1)
	{
		if((exponent & 1) != 0)
		{
			res = res->multiply(acc, ctx);
		}
		if(acc->numberLength == 1)
		{
			acc = acc->multiply(acc, ctx);
		}
				else 
		{
			acc = (new(ctx) BigInteger(1, square(acc->digits, acc->numberLength, ArrayAllocatorPrimitive<int>::allocatep(ctx, acc->numberLength << 1), ctx), ctx));
		}
	}
	res = res->multiply(acc, ctx);
	return res;
}
IArrayObjectPrimitive<int>* Multiplication::square(IArrayObjectPrimitive<int>* a, int aLen, IArrayObjectPrimitive<int>* res, ThreadContext* ctx) throw() 
{
	long long carry = 0;
	for(int i = 0; i < aLen; i ++ )
	{
		carry = 0;
		for(int j = i + 1; j < aLen; j ++ )
		{
			carry = unsignedMultAddAdd(a->get(i), a->get(j), res->get(i + j), ((int)carry), ctx);
			res->set(((int)carry),i + j, ctx);
			carry = ((unsigned long long)carry) >> 32;
		}
		res->set(((int)carry),i + aLen, ctx);
	}
	BitLevel::shiftLeftOneBit(res, res, aLen << 1, ctx);
	carry = 0;
	for(int i = 0, index = 0; i < aLen; i ++ , index ++ )
	{
		carry = unsignedMultAddAdd(a->get(i), a->get(i), res->get(index), ((int)carry), ctx);
		res->set(((int)carry),index, ctx);
		carry = ((unsigned long long)carry) >> 32;
		index ++ ;
		carry += res->get(index) & 0xFFFFFFFFL;
		res->set(((int)carry),index, ctx);
		carry = ((unsigned long long)carry) >> 32;
	}
	return res;
}
BigInteger* Multiplication::multiplyByTenPow(BigInteger* val, long long exp, ThreadContext* ctx) throw() 
{
	return ((exp < (long long)tenPows->length) ? multiplyByPositiveInt(val, tenPows->get(((int)exp)), ctx) : val->multiply(powerOf10(exp, ctx), ctx));
}
BigInteger* Multiplication::powerOf10(long long exp, ThreadContext* ctx) throw() 
{
	int intExp = ((int)exp);
	if(exp < (long long)bigTenPows->length)
	{
		return bigTenPows->get(intExp);
	}
		else 
	{
		if(exp <= (long long)50)
		{
			return BigInteger::TEN->pow(intExp, ctx);
		}
				else 
		{
			if(exp <= (long long)1000)
			{
				return bigFivePows->get(1)->pow(intExp, ctx)->shiftLeft(intExp, ctx);
			}
		}
	}
	long long byteArraySize = 1 + ((long long)(exp / 2.4082399653118496));
	if(byteArraySize > (long long)1024 * 1024 * 1024)
	{
		throw (new(ctx) ArithmeticException(ConstStr::getCNST_STR_8(), ctx));
	}
	if(exp <= (long long)Integer::MAX_VALUE)
	{
		return bigFivePows->get(1)->pow(intExp, ctx)->shiftLeft(intExp, ctx);
	}
	BigInteger* powerOfFive = bigFivePows->get(1)->pow(Integer::MAX_VALUE, ctx);
	BigInteger* res = powerOfFive;
	long long longExp = exp - Integer::MAX_VALUE;
	intExp = ((int)(exp % Integer::MAX_VALUE));
	while(longExp > (long long)Integer::MAX_VALUE)
	{
		res = res->multiply(powerOfFive, ctx);
		longExp -= Integer::MAX_VALUE;
	}
	res = res->multiply(bigFivePows->get(1)->pow(intExp, ctx), ctx);
	res = res->shiftLeft(Integer::MAX_VALUE, ctx);
	longExp = exp - Integer::MAX_VALUE;
	while(longExp > (long long)Integer::MAX_VALUE)
	{
		res = res->shiftLeft(Integer::MAX_VALUE, ctx);
		longExp -= Integer::MAX_VALUE;
	}
	res = res->shiftLeft(intExp, ctx);
	return res;
}
BigInteger* Multiplication::multiplyByFivePow(BigInteger* val, int exp, ThreadContext* ctx) throw() 
{
	if(exp < fivePows->length)
	{
		return multiplyByPositiveInt(val, fivePows->get(exp), ctx);
	}
		else 
	{
		if(exp < bigFivePows->length)
		{
			return val->multiply(bigFivePows->get(exp), ctx);
		}
				else 
		{
			return val->multiply(bigFivePows->get(1)->pow(exp, ctx), ctx);
		}
	}
}
long long Multiplication::unsignedMultAddAdd(int a, int b, int c, int d, ThreadContext* ctx) throw() 
{
	return (a & 0xFFFFFFFFL) * (b & 0xFFFFFFFFL) + (c & 0xFFFFFFFFL) + (d & 0xFFFFFFFFL);
}
int Multiplication::multiplyByInt(IArrayObjectPrimitive<int>* res, IArrayObjectPrimitive<int>* a, int aSize, int factor, ThreadContext* ctx) throw() 
{
	long long carry = 0;
	for(int i = 0; i < aSize; i ++ )
	{
		carry = unsignedMultAddAdd(a->get(i), factor, ((int)carry), 0, ctx);
		res->set(((int)carry),i, ctx);
		carry = ((unsigned long long)carry) >> 32;
	}
	return ((int)carry);
}
}}

