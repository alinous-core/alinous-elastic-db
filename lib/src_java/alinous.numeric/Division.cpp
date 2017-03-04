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





bool Division::__init_done = __init_static_variables();
bool Division::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"Division", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 Division::~Division() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void Division::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
}
IArrayObjectPrimitive<int>* Division::divide(IArrayObjectPrimitive<int>* quot, int quotLength, IArrayObjectPrimitive<int>* a, int aLength, IArrayObjectPrimitive<int>* b, int bLength, ThreadContext* ctx) throw() 
{
	IArrayObjectPrimitive<int>* normA = ArrayAllocatorPrimitive<int>::allocatep(ctx, aLength + 1);
	IArrayObjectPrimitive<int>* normB = ArrayAllocatorPrimitive<int>::allocatep(ctx, bLength + 1);
	int normBLength = bLength;
	int divisorShift = Integer::numberOfLeadingZeros(b->get(bLength - 1), ctx);
	if(divisorShift != 0)
	{
		BitLevel::shiftLeft(normB, b, 0, divisorShift, ctx);
		BitLevel::shiftLeft(normA, a, 0, divisorShift, ctx);
	}
		else 
	{
		System::arraycopy(a, 0, normA, 0, aLength, ctx);
		System::arraycopy(b, 0, normB, 0, bLength, ctx);
	}
	int firstDivisorDigit = normB->get(normBLength - 1);
	int i = quotLength - 1;
	int j = aLength;
	while(i >= 0)
	{
		int guessDigit = 0;
		if(normA->get(j) == firstDivisorDigit)
		{
			guessDigit = -1;
		}
				else 
		{
			long long product = (((normA->get(j) & 0xffffffffL) << 32) + (normA->get(j - 1) & 0xffffffffL));
			long long res = Division::divideLongByInt(product, firstDivisorDigit, ctx);
			guessDigit = ((int)res);
			int rem = ((int)(res >> 32));
			if(guessDigit != 0)
			{
				long long leftHand = 0;
				long long rightHand = 0;
				bool rOverflowed = false;
				guessDigit ++ ;
				do
				{
					guessDigit -- ;
					if(rOverflowed)
					{
						break ;
					}
					leftHand = (guessDigit & 0xffffffffL) * (normB->get(normBLength - 2) & 0xffffffffL);
					rightHand = (((long long)rem) << 32) + (normA->get(j - 2) & 0xffffffffL);
					long long longR = (rem & 0xffffffffL) + (firstDivisorDigit & 0xffffffffL);
					if(Integer::numberOfLeadingZeros(((int)(((unsigned long long)longR)>> 32)), ctx) < 32)
					{
						rOverflowed = true;
					}
										else 
					{
						rem = ((int)longR);
					}
				}
				while(((leftHand ^ 0x8000000000000000L) > (rightHand ^ 0x8000000000000000L)));
			}
		}
		if(guessDigit != 0)
		{
			int borrow = Division::multiplyAndSubtract(normA, j - normBLength, normB, normBLength, guessDigit, ctx);
			if(borrow != 0)
			{
				guessDigit -- ;
				long long carry = 0;
				for(int k = 0; k < normBLength; k ++ )
				{
					carry += (normA->get(j - normBLength + k) & 0xffffffffL) + (normB->get(k) & 0xffffffffL);
					normA->set(((int)carry),j - normBLength + k, ctx);
					carry = ((unsigned long long)carry) >> 32;
				}
			}
		}
		if(quot != (IArrayObjectPrimitive<int>*)nullptr)
		{
			quot->set(guessDigit,i, ctx);
		}
		j -- ;
		i -- ;
	}
	if(divisorShift != 0)
	{
		BitLevel::shiftRight(normB, normBLength, normA, 0, divisorShift, ctx);
		return normB;
	}
	System::arraycopy(normA, 0, normB, 0, bLength, ctx);
	return normA;
}
int Division::divideArrayByInt(IArrayObjectPrimitive<int>* dest, IArrayObjectPrimitive<int>* src, int srcLength, int divisor, ThreadContext* ctx) throw() 
{
	long long rem = 0;
	long long bLong = divisor & 0xffffffffL;
	for(int i = srcLength - 1; i >= 0; i -- )
	{
		long long temp = (rem << 32) | (src->get(i) & 0xffffffffL);
		long long quot = 0;
		if(temp >= (long long)0)
		{
			quot = (temp / bLong);
			rem = (temp % bLong);
		}
				else 
		{
			long long aPos = ((unsigned long long)temp)>> 1;
			long long bPos = ((unsigned int)divisor)>> 1;
			quot = aPos / bPos;
			rem = aPos % bPos;
			rem = (rem << 1) + (temp & 1);
			if((divisor & 1) != 0)
			{
				if(quot <= rem)
				{
					rem -= quot;
				}
								else 
				{
					if(quot - rem <= bLong)
					{
						rem += bLong - quot;
						quot -= 1;
					}
										else 
					{
						rem += (bLong << 1) - quot;
						quot -= 2;
					}
				}
			}
		}
		dest->set(((int)(quot & 0xffffffffL)),i, ctx);
	}
	return ((int)rem);
}
int Division::remainderArrayByInt(IArrayObjectPrimitive<int>* src, int srcLength, int divisor, ThreadContext* ctx) throw() 
{
	long long result = 0;
	for(int i = srcLength - 1; i >= 0; i -- )
	{
		long long temp = (result << 32) + (src->get(i) & 0xffffffffL);
		long long res = divideLongByInt(temp, divisor, ctx);
		result = ((int)(res >> 32));
	}
	return ((int)result);
}
int Division::remainder(BigInteger* dividend, int divisor, ThreadContext* ctx) throw() 
{
	return remainderArrayByInt(dividend->digits, dividend->numberLength, divisor, ctx);
}
long long Division::divideLongByInt(long long a, int b, ThreadContext* ctx) throw() 
{
	long long quot = 0;
	long long rem = 0;
	long long bLong = b & 0xffffffffL;
	if(a >= (long long)0)
	{
		quot = (a / bLong);
		rem = (a % bLong);
	}
		else 
	{
		long long aPos = ((unsigned long long)a)>> 1;
		long long bPos = ((unsigned int)b)>> 1;
		quot = aPos / bPos;
		rem = aPos % bPos;
		rem = (rem << 1) + (a & 1);
		if((b & 1) != 0)
		{
			if(quot <= rem)
			{
				rem -= quot;
			}
						else 
			{
				if(quot - rem <= bLong)
				{
					rem += bLong - quot;
					quot -= 1;
				}
								else 
				{
					rem += (bLong << 1) - quot;
					quot -= 2;
				}
			}
		}
	}
	return (rem << 32) | (quot & 0xffffffffL);
}
IArrayObject<BigInteger>* Division::divideAndRemainderByInteger(BigInteger* val, int divisor, int divisorSign, ThreadContext* ctx) throw() 
{
	IArrayObjectPrimitive<int>* valDigits = val->digits;
	int valLen = val->numberLength;
	int valSign = val->sign;
	if(valLen == 1)
	{
		long long a = (valDigits->get(0) & 0xffffffffL);
		long long b = (divisor & 0xffffffffL);
		long long quo = a / b;
		long long rem = a % b;
		if(valSign != divisorSign)
		{
			quo = -quo;
		}
		if(valSign < 0)
		{
			rem = -rem;
		}
		return ((IArrayObject<BigInteger>*)new(ctx) ArrayObject<BigInteger>({BigInteger::valueOf(quo, ctx), BigInteger::valueOf(rem, ctx)}, ctx));
	}
	int quotientLength = valLen;
	int quotientSign = ((valSign == divisorSign) ? 1 : -1);
	IArrayObjectPrimitive<int>* quotientDigits = ArrayAllocatorPrimitive<int>::allocatep(ctx, quotientLength);
	IArrayObjectPrimitive<int>* remainderDigits = 0;
	remainderDigits = ((IArrayObjectPrimitive<int>*)new(ctx) ArrayObjectPrimitive<int>({Division::divideArrayByInt(quotientDigits, valDigits, valLen, divisor, ctx)}, ctx));
	BigInteger* result0 = (new(ctx) BigInteger(quotientSign, quotientLength, quotientDigits, ctx));
	BigInteger* result1 = (new(ctx) BigInteger(valSign, 1, remainderDigits, ctx));
	result0->cutOffLeadingZeroes(ctx);
	result1->cutOffLeadingZeroes(ctx);
	return ((IArrayObject<BigInteger>*)new(ctx) ArrayObject<BigInteger>({result0, result1}, ctx));
}
int Division::multiplyAndSubtract(IArrayObjectPrimitive<int>* a, int start, IArrayObjectPrimitive<int>* b, int bLen, int c, ThreadContext* ctx) throw() 
{
	long long carry0 = 0;
	long long carry1 = 0;
	for(int i = 0; i < bLen; i ++ )
	{
		carry0 = Multiplication::unsignedMultAddAdd(b->get(i), c, ((int)carry0), 0, ctx);
		carry1 = (a->get(start + i) & 0xffffffffL) - (carry0 & 0xffffffffL) + carry1;
		a->set(((int)carry1),start + i, ctx);
		carry1 >>= 32;
		carry0 = ((unsigned long long)carry0) >> 32;
	}
	carry1 = (a->get(start + bLen) & 0xffffffffL) - carry0 + carry1;
	a->set(((int)carry1),start + bLen, ctx);
	return ((int)(carry1 >> 32));
}
BigInteger* Division::gcdBinary(BigInteger* op1, BigInteger* op2, ThreadContext* ctx) throw() 
{
	int lsb1 = op1->getLowestSetBit(ctx);
	int lsb2 = op2->getLowestSetBit(ctx);
	int pow2Count = Math::min(lsb1, lsb2, ctx);
	BitLevel::inplaceShiftRight(op1, lsb1, ctx);
	BitLevel::inplaceShiftRight(op2, lsb2, ctx);
	BigInteger* swap = 0;
	if(op1->compareTo(op2, ctx) == BigInteger::GREATER)
	{
		swap = op1;
		op1 = op2;
		op2 = swap;
	}
	do
	{
		if((op2->numberLength == 1) || ((op2->numberLength == 2) && (op2->digits->get(1) > 0)))
		{
			op2 = BigInteger::valueOf(Division::gcdBinary(op1->longValue(ctx), op2->longValue(ctx), ctx), ctx);
			break ;
		}
		if(op2->numberLength > op1->numberLength * 1.2)
		{
			op2 = op2->remainder(op1, ctx);
			if(op2->signum(ctx) != 0)
			{
				BitLevel::inplaceShiftRight(op2, op2->getLowestSetBit(ctx), ctx);
			}
		}
				else 
		{
			do
			{
				Elementary::inplaceSubtract(op2, op1, ctx);
				BitLevel::inplaceShiftRight(op2, op2->getLowestSetBit(ctx), ctx);
			}
			while(op2->compareTo(op1, ctx) >= BigInteger::EQUALS);
		}
		swap = op2;
		op2 = op1;
		op1 = swap;
	}
	while(op1->sign != 0);
	return op2->shiftLeft(pow2Count, ctx);
}
long long Division::gcdBinary(long long op1, long long op2, ThreadContext* ctx) throw() 
{
	int lsb1 = Long::numberOfTrailingZeros(op1, ctx);
	int lsb2 = Long::numberOfTrailingZeros(op2, ctx);
	int pow2Count = Math::min(lsb1, lsb2, ctx);
	if(lsb1 != 0)
	{
		op1 = ((unsigned long long)op1) >> lsb1;
	}
	if(lsb2 != 0)
	{
		op2 = ((unsigned long long)op2) >> lsb2;
	}
	do
	{
		if(op1 >= op2)
		{
			op1 -= op2;
			op1 = ((unsigned long long)op1) >> Long::numberOfTrailingZeros(op1, ctx);
		}
				else 
		{
			op2 -= op1;
			op2 = ((unsigned long long)op2) >> Long::numberOfTrailingZeros(op2, ctx);
		}
	}
	while(op1 != (long long)0);
	return (op2 << pow2Count);
}
BigInteger* Division::modInverseMontgomery(BigInteger* a, BigInteger* p, ThreadContext* ctx) throw() 
{
	if(a->sign == 0)
	{
		throw (new(ctx) ArithmeticException(ConstStr::getCNST_STR_49(), ctx));
	}
	if(!p->testBit(0, ctx))
	{
		return modInverseHars(a, p, ctx);
	}
	int m = p->numberLength * 32;
	BigInteger* u = 0;BigInteger* v = 0;BigInteger* r = 0;BigInteger* s = 0;
	u = p->copy(ctx);
	v = a->copy(ctx);
	int max = Math::max(v->numberLength, u->numberLength, ctx);
	r = (new(ctx) BigInteger(1, 1, ArrayAllocatorPrimitive<int>::allocatep(ctx, max + 1), ctx));
	s = (new(ctx) BigInteger(1, 1, ArrayAllocatorPrimitive<int>::allocatep(ctx, max + 1), ctx));
	s->digits->set(1,0, ctx);
	int k = 0;
	int lsbu = u->getLowestSetBit(ctx);
	int lsbv = v->getLowestSetBit(ctx);
	int toShift = 0;
	if(lsbu > lsbv)
	{
		BitLevel::inplaceShiftRight(u, lsbu, ctx);
		BitLevel::inplaceShiftRight(v, lsbv, ctx);
		BitLevel::inplaceShiftLeft(r, lsbv, ctx);
		k += lsbu - lsbv;
	}
		else 
	{
		BitLevel::inplaceShiftRight(u, lsbu, ctx);
		BitLevel::inplaceShiftRight(v, lsbv, ctx);
		BitLevel::inplaceShiftLeft(s, lsbu, ctx);
		k += lsbv - lsbu;
	}
	r->sign = 1;
	while(v->signum(ctx) > 0)
	{
		while(u->compareTo(v, ctx) > BigInteger::EQUALS)
		{
			Elementary::inplaceSubtract(u, v, ctx);
			toShift = u->getLowestSetBit(ctx);
			BitLevel::inplaceShiftRight(u, toShift, ctx);
			Elementary::inplaceAdd(r, s, ctx);
			BitLevel::inplaceShiftLeft(s, toShift, ctx);
			k += toShift;
		}
		while(u->compareTo(v, ctx) <= BigInteger::EQUALS)
		{
			Elementary::inplaceSubtract(v, u, ctx);
			if(v->signum(ctx) == 0)
			{
				break ;
			}
			toShift = v->getLowestSetBit(ctx);
			BitLevel::inplaceShiftRight(v, toShift, ctx);
			Elementary::inplaceAdd(s, r, ctx);
			BitLevel::inplaceShiftLeft(r, toShift, ctx);
			k += toShift;
		}
	}
	if(!u->isOne(ctx))
	{
		throw (new(ctx) ArithmeticException(ConstStr::getCNST_STR_49(), ctx));
	}
	if(r->compareTo(p, ctx) >= BigInteger::EQUALS)
	{
		Elementary::inplaceSubtract(r, p, ctx);
	}
	r = p->subtract(r, ctx);
	int n1 = calcN(p, ctx);
	if(k > m)
	{
		r = monPro(r, BigInteger::ONE, p, n1, ctx);
		k = k - m;
	}
	r = monPro(r, BigInteger::getPowerOfTwo(m - k, ctx), p, n1, ctx);
	return r;
}
BigInteger* Division::squareAndMultiply(BigInteger* x2, BigInteger* a2, BigInteger* exponent, BigInteger* modulus, int n2, ThreadContext* ctx) throw() 
{
	BigInteger* res = x2;
	for(int i = exponent->bitLength(ctx) - 1; i >= 0; i -- )
	{
		res = monPro(res, res, modulus, n2, ctx);
		if(BitLevel::testBit(exponent, i, ctx))
		{
			res = monPro(res, a2, modulus, n2, ctx);
		}
	}
	return res;
}
BigInteger* Division::modInverseHars(BigInteger* a, BigInteger* m, ThreadContext* ctx) throw() 
{
	BigInteger* u = 0;BigInteger* v = 0;BigInteger* r = 0;BigInteger* s = 0;BigInteger* temp = 0;
	if(a->compareTo(m, ctx) == BigInteger::LESS)
	{
		u = m;
		v = a;
		r = BigInteger::ZERO;
		s = BigInteger::ONE;
	}
		else 
	{
		v = m;
		u = a;
		s = BigInteger::ZERO;
		r = BigInteger::ONE;
	}
	int uLen = u->bitLength(ctx);
	int vLen = v->bitLength(ctx);
	int f = uLen - vLen;
	while(vLen > 1)
	{
		if(u->sign == v->sign)
		{
			u = u->subtract(v->shiftLeft(f, ctx), ctx);
			r = r->subtract(s->shiftLeft(f, ctx), ctx);
		}
				else 
		{
			u = u->add(v->shiftLeft(f, ctx), ctx);
			r = r->add(s->shiftLeft(f, ctx), ctx);
		}
		uLen = u->abs(ctx)->bitLength(ctx);
		vLen = v->abs(ctx)->bitLength(ctx);
		f = uLen - vLen;
		if(f < 0)
		{
			temp = u;
			u = v;
			v = temp;
			temp = r;
			r = s;
			s = temp;
			f = -f;
			vLen = uLen;
		}
	}
	if(v->sign == 0)
	{
		return BigInteger::ZERO;
	}
	if(v->sign < 0)
	{
		s = s->negate(ctx);
	}
	if(s->compareTo(m, ctx) == BigInteger::GREATER)
	{
		return s->subtract(m, ctx);
	}
	if(s->sign < 0)
	{
		return s->add(m, ctx);
	}
	return s;
}
BigInteger* Division::slidingWindow(BigInteger* x2, BigInteger* a2, BigInteger* exponent, BigInteger* modulus, int n2, ThreadContext* ctx) throw() 
{
	IArrayObject<BigInteger>* pows = ArrayAllocator<BigInteger>::allocate(ctx, 8);
	BigInteger* res = x2;
	int lowexp = 0;
	BigInteger* x3 = 0;
	int acc3 = 0;
	pows->set(a2,0, ctx);
	x3 = monPro(a2, a2, modulus, n2, ctx);
	for(int i = 1; i <= 7; i ++ )
	{
		pows->set(monPro(pows->get(i - 1), x3, modulus, n2, ctx),i, ctx);
	}
	for(int i = exponent->bitLength(ctx) - 1; i >= 0; i -- )
	{
		if(BitLevel::testBit(exponent, i, ctx))
		{
			lowexp = 1;
			acc3 = i;
			for(int j = Math::max(i - 3, 0, ctx); j <= i - 1; j ++ )
			{
				if(BitLevel::testBit(exponent, j, ctx))
				{
					if(j < acc3)
					{
						acc3 = j;
						lowexp = (lowexp << (i - j)) ^ 1;
					}
										else 
					{
						lowexp = lowexp ^ (1 << (j - acc3));
					}
				}
			}
			for(int j = acc3; j <= i; j ++ )
			{
				res = monPro(res, res, modulus, n2, ctx);
			}
			res = monPro(pows->get((lowexp - 1) >> 1), res, modulus, n2, ctx);
			i = acc3;
		}
				else 
		{
			res = monPro(res, res, modulus, n2, ctx);
		}
	}
	return res;
}
BigInteger* Division::oddModPow(BigInteger* base, BigInteger* exponent, BigInteger* modulus, ThreadContext* ctx) throw() 
{
	int k = (modulus->numberLength << 5);
	BigInteger* a2 = base->shiftLeft(k, ctx)->mod(modulus, ctx);
	BigInteger* x2 = BigInteger::getPowerOfTwo(k, ctx)->mod(modulus, ctx);
	BigInteger* res = 0;
	int n2 = calcN(modulus, ctx);
	if(modulus->numberLength == 1)
	{
		res = squareAndMultiply(x2, a2, exponent, modulus, n2, ctx);
	}
		else 
	{
		res = slidingWindow(x2, a2, exponent, modulus, n2, ctx);
	}
	return monPro(res, BigInteger::ONE, modulus, n2, ctx);
}
BigInteger* Division::evenModPow(BigInteger* base, BigInteger* exponent, BigInteger* modulus, ThreadContext* ctx) throw() 
{
	int j = modulus->getLowestSetBit(ctx);
	BigInteger* q = modulus->shiftRight(j, ctx);
	BigInteger* x1 = oddModPow(base, exponent, q, ctx);
	BigInteger* x2 = pow2ModPow(base, exponent, j, ctx);
	BigInteger* qInv = modPow2Inverse(q, j, ctx);
	BigInteger* y = (x2->subtract(x1, ctx))->multiply(qInv, ctx);
	inplaceModPow2(y, j, ctx);
	if(y->sign < 0)
	{
		y = y->add(BigInteger::getPowerOfTwo(j, ctx), ctx);
	}
	return x1->add(q->multiply(y, ctx), ctx);
}
BigInteger* Division::pow2ModPow(BigInteger* base, BigInteger* exponent, int j, ThreadContext* ctx) throw() 
{
	BigInteger* res = BigInteger::ONE;
	BigInteger* e = exponent->copy(ctx);
	BigInteger* baseMod2toN = base->copy(ctx);
	BigInteger* res2 = 0;
	if(base->testBit(0, ctx))
	{
		inplaceModPow2(e, j - 1, ctx);
	}
	inplaceModPow2(baseMod2toN, j, ctx);
	for(int i = e->bitLength(ctx) - 1; i >= 0; i -- )
	{
		res2 = res->copy(ctx);
		inplaceModPow2(res2, j, ctx);
		res = res->multiply(res2, ctx);
		if(BitLevel::testBit(e, i, ctx))
		{
			res = res->multiply(baseMod2toN, ctx);
			inplaceModPow2(res, j, ctx);
		}
	}
	inplaceModPow2(res, j, ctx);
	return res;
}
BigInteger* Division::monPro(BigInteger* a, BigInteger* b, BigInteger* modulus, int n2, ThreadContext* ctx) throw() 
{
	int modulusLen = modulus->numberLength;
	IArrayObjectPrimitive<int>* res = ArrayAllocatorPrimitive<int>::allocatep(ctx, (modulusLen << 1) + 1);
	Multiplication::multArraysPAP(a->digits, Math::min(modulusLen, a->numberLength, ctx), b->digits, Math::min(modulusLen, b->numberLength, ctx), res, ctx);
	monReduction(res, modulus, n2, ctx);
	return finalSubtraction(res, modulus, ctx);
}
BigInteger* Division::finalSubtraction(IArrayObjectPrimitive<int>* res, BigInteger* modulus, ThreadContext* ctx) throw() 
{
	int modulusLen = modulus->numberLength;
	bool doSub = res->get(modulusLen) != 0;
	if(!doSub)
	{
		IArrayObjectPrimitive<int>* modulusDigits = modulus->digits;
		doSub = true;
		for(int i = modulusLen - 1; i >= 0; i -- )
		{
			if(res->get(i) != modulusDigits->get(i))
			{
				doSub = (res->get(i) != 0) && ((res->get(i) & 0xFFFFFFFFL) > (modulusDigits->get(i) & 0xFFFFFFFFL));
				break ;
			}
		}
	}
	BigInteger* result = (new(ctx) BigInteger(1, modulusLen + 1, res, ctx));
	if(doSub)
	{
		Elementary::inplaceSubtract(result, modulus, ctx);
	}
	result->cutOffLeadingZeroes(ctx);
	return result;
}
BigInteger* Division::modPow2Inverse(BigInteger* x, int n, ThreadContext* ctx) throw() 
{
	BigInteger* y = (new(ctx) BigInteger(1, ArrayAllocatorPrimitive<int>::allocatep(ctx, 1 << n), ctx));
	y->numberLength = 1;
	y->digits->set(1,0, ctx);
	y->sign = 1;
	for(int i = 1; i < n; i ++ )
	{
		if(BitLevel::testBit(x->multiply(y, ctx), i, ctx))
		{
			y->digits->set(y->digits->get(i >> 5) | ((1 << (i & 31))),i >> 5, ctx);
		}
	}
	return y;
}
void Division::inplaceModPow2(BigInteger* x, int n, ThreadContext* ctx) throw() 
{
	int fd = n >> 5;
	int leadingZeros = 0;
	if((x->numberLength < fd) || (x->bitLength(ctx) <= n))
	{
		return;
	}
	leadingZeros = 32 - (n & 31);
	x->numberLength = fd + 1;
	x->digits->set(x->digits->get(fd) & ((leadingZeros < 32) ? (((unsigned int)-1)>> leadingZeros) : 0),fd, ctx);
	x->cutOffLeadingZeroes(ctx);
}
int Division::calcN(BigInteger* a, ThreadContext* ctx) throw() 
{
	long long m0 = a->digits->get(0) & 0xFFFFFFFFL;
	long long n2 = 1L;
	long long powerOfTwo = 2L;
	do
	{
		if(((m0 * n2) & powerOfTwo) != (long long)0)
		{
			n2 = n2 | (powerOfTwo);
		}
		powerOfTwo <<= 1;
	}
	while(powerOfTwo < (long long)0x100000000L);
	n2 = -n2;
	return ((int)(n2 & 0xFFFFFFFFL));
}
void Division::monReduction(IArrayObjectPrimitive<int>* res, BigInteger* modulus, int n2, ThreadContext* ctx) throw() 
{
	IArrayObjectPrimitive<int>* modulus_digits = modulus->digits;
	int modulusLen = modulus->numberLength;
	long long outerCarry = 0;
	for(int i = 0; i < modulusLen; i ++ )
	{
		long long innnerCarry = 0;
		int m = ((int)Multiplication::unsignedMultAddAdd(res->get(i), n2, 0, 0, ctx));
		for(int j = 0; j < modulusLen; j ++ )
		{
			innnerCarry = Multiplication::unsignedMultAddAdd(m, modulus_digits->get(j), res->get(i + j), ((int)innnerCarry), ctx);
			res->set(((int)innnerCarry),i + j, ctx);
			innnerCarry = ((unsigned long long)innnerCarry) >> 32;
		}
		outerCarry += (res->get(i + modulusLen) & 0xFFFFFFFFL) + innnerCarry;
		res->set(((int)outerCarry),i + modulusLen, ctx);
		outerCarry = ((unsigned long long)outerCarry) >> 32;
	}
	res->set(((int)outerCarry),modulusLen << 1, ctx);
	for(int j = 0; j < modulusLen + 1; j ++ )
	{
		res->set(res->get(j + modulusLen),j, ctx);
	}
}
}}

