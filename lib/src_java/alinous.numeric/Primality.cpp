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
#include "java.util/Arrays.h"
#include "alinous.numeric/Primality.h"

namespace alinous {namespace numeric {





const StaticArrayObjectPrimitive<int> Primality::__primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199, 211, 223, 227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281, 283, 293, 307, 311, 313, 317, 331, 337, 347, 349, 353, 359, 367, 373, 379, 383, 389, 397, 401, 409, 419, 421, 431, 433, 439, 443, 449, 457, 461, 463, 467, 479, 487, 491, 499, 503, 509, 521, 523, 541, 547, 557, 563, 569, 571, 577, 587, 593, 599, 601, 607, 613, 617, 619, 631, 641, 643, 647, 653, 659, 661, 673, 677, 683, 691, 701, 709, 719, 727, 733, 739, 743, 751, 757, 761, 769, 773, 787, 797, 809, 811, 821, 823, 827, 829, 839, 853, 857, 859, 863, 877, 881, 883, 887, 907, 911, 919, 929, 937, 941, 947, 953, 967, 971, 977, 983, 991, 997, 1009, 1013, 1019, 1021};
IArrayObjectPrimitive<int>* Primality::primes = (IArrayObjectPrimitive<int>*)const_cast<StaticArrayObjectPrimitive<int>*>(&__primes);
IArrayObject<BigInteger>* Primality::BIprimes = nullptr;
const StaticArrayObjectPrimitive<int> Primality::__BITS = {0, 0, 1854, 1233, 927, 747, 627, 543, 480, 431, 393, 361, 335, 314, 295, 279, 265, 253, 242, 232, 223, 216, 181, 169, 158, 150, 145, 140, 136, 132, 127, 123, 119, 114, 110, 105, 101, 96, 92, 87, 83, 78, 73, 69, 64, 59, 54, 49, 44, 38, 32, 26, 1};
IArrayObjectPrimitive<int>* Primality::BITS = (IArrayObjectPrimitive<int>*)const_cast<StaticArrayObjectPrimitive<int>*>(&__BITS);
IArrayObjectPrimitive<int>* Primality::a0 = nullptr;
IArrayObjectPrimitive<int>* Primality::a1 = nullptr;
const StaticArrayObjectPrimitive<int> Primality::__a2 = {0, 2};
IArrayObjectPrimitive<int>* Primality::a2 = (IArrayObjectPrimitive<int>*)const_cast<StaticArrayObjectPrimitive<int>*>(&__a2);
const StaticArrayObjectPrimitive<int> Primality::__a3 = {2, 2};
IArrayObjectPrimitive<int>* Primality::a3 = (IArrayObjectPrimitive<int>*)const_cast<StaticArrayObjectPrimitive<int>*>(&__a3);
const StaticArrayObjectPrimitive<int> Primality::__a4 = {4, 2};
IArrayObjectPrimitive<int>* Primality::a4 = (IArrayObjectPrimitive<int>*)const_cast<StaticArrayObjectPrimitive<int>*>(&__a4);
const StaticArrayObjectPrimitive<int> Primality::__a5 = {6, 5};
IArrayObjectPrimitive<int>* Primality::a5 = (IArrayObjectPrimitive<int>*)const_cast<StaticArrayObjectPrimitive<int>*>(&__a5);
const StaticArrayObjectPrimitive<int> Primality::__a6 = {11, 7};
IArrayObjectPrimitive<int>* Primality::a6 = (IArrayObjectPrimitive<int>*)const_cast<StaticArrayObjectPrimitive<int>*>(&__a6);
const StaticArrayObjectPrimitive<int> Primality::__a7 = {18, 13};
IArrayObjectPrimitive<int>* Primality::a7 = (IArrayObjectPrimitive<int>*)const_cast<StaticArrayObjectPrimitive<int>*>(&__a7);
const StaticArrayObjectPrimitive<int> Primality::__a8 = {31, 23};
IArrayObjectPrimitive<int>* Primality::a8 = (IArrayObjectPrimitive<int>*)const_cast<StaticArrayObjectPrimitive<int>*>(&__a8);
const StaticArrayObjectPrimitive<int> Primality::__a9 = {54, 43};
IArrayObjectPrimitive<int>* Primality::a9 = (IArrayObjectPrimitive<int>*)const_cast<StaticArrayObjectPrimitive<int>*>(&__a9);
const StaticArrayObjectPrimitive<int> Primality::__a10 = {97, 75};
IArrayObjectPrimitive<int>* Primality::a10 = (IArrayObjectPrimitive<int>*)const_cast<StaticArrayObjectPrimitive<int>*>(&__a10);
IArrayObject<IArrayObjectPrimitive<int>>* Primality::offsetPrimes = nullptr;
bool Primality::__init_done = __init_static_variables();
bool Primality::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"Primality", L"__init_static_variables");
		__GC_MV(nullptr, &(BIprimes), (new ArrayObject<BigInteger>(ArrayAllocator<BigInteger>::allocate(ctx, primes->length), ctx)), IArrayObject<BigInteger>);
		GCUtils<IArrayObject<IArrayObjectPrimitive<int>> >::global(GCUtils<IArrayObject<IArrayObjectPrimitive<int>> >::mv(nullptr, &(offsetPrimes), (new IArrayObject<IArrayObjectPrimitive<int>>({a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10}, ctx)), ctx), ctx, __FILEW__, __LINE__);
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 Primality::Primality(ThreadContext* ctx) throw()  : IObject(ctx)
{
}
void Primality::__construct_impl(ThreadContext* ctx) throw() 
{
}
 Primality::~Primality() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void Primality::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
}
void Primality::initByBigInt(ThreadContext* ctx) throw() 
{
	for(int i = 0; i < primes->length; i ++ )
	{
		BIprimes->set(BigInteger::valueOf((long long)primes->get(i), ctx),i, ctx);
	}
}
BigInteger* Primality::nextProbablePrime(BigInteger* n, ThreadContext* ctx) throw() 
{
	int i = 0;int j = 0;
	int certainty = 0;
	int gapSize = 1024;
	IArrayObjectPrimitive<int>* modules = ArrayAllocatorPrimitive<int>::allocatep(ctx, primes->length);
	IArrayObjectPrimitive<bool>* isDivisible = ArrayAllocatorPrimitive<bool>::allocatep(ctx, gapSize);
	BigInteger* startPoint = 0;
	BigInteger* probPrime = 0;
	if((n->numberLength == 1) && (n->digits->get(0) >= 0) && (n->digits->get(0) < primes->get(primes->length - 1)))
	{
		for(i = 0; n->digits->get(0) >= primes->get(i); i ++ )
		{
			;
		}
		return BIprimes->get(i);
	}
	startPoint = (new(ctx) BigInteger(1, n->numberLength, ArrayAllocatorPrimitive<int>::allocatep(ctx, n->numberLength + 1), ctx));
	System::arraycopy(n->digits, 0, startPoint->digits, 0, n->numberLength, ctx);
	if(n->testBit(0, ctx))
	{
		Elementary::inplaceAdd(startPoint, 2, ctx);
	}
		else 
	{
		startPoint->digits->set(startPoint->digits->get(0) | (1),0, ctx);
	}
	j = startPoint->bitLength(ctx);
	for(certainty = 2; j < BITS->get(certainty); certainty ++ )
	{
		;
	}
	for(i = 0; i < primes->length; i ++ )
	{
		modules->set(Division::remainder(startPoint, primes->get(i), ctx) - gapSize,i, ctx);
	}
	while(true)
	{
		Arrays::fill(isDivisible, false, ctx);
		for(i = 0; i < primes->length; i ++ )
		{
			modules->set((modules->get(i) + gapSize) % primes->get(i),i, ctx);
			j = (modules->get(i) == 0) ? 0 : (primes->get(i) - modules->get(i));
			for(; j < gapSize; j += primes->get(i))
			{
				isDivisible->set(true,j, ctx);
			}
		}
		for(j = 0; j < gapSize; j ++ )
		{
			if(!isDivisible->get(j))
			{
				probPrime = startPoint->copy(ctx);
				Elementary::inplaceAdd(probPrime, j, ctx);
				if(millerRabin(probPrime, certainty, ctx))
				{
					return probPrime;
				}
			}
		}
		Elementary::inplaceAdd(startPoint, gapSize, ctx);
	}
}
BigInteger* Primality::consBigInteger(int bitLength, int certainty, Random* rnd, ThreadContext* ctx) throw() 
{
	if(bitLength <= 10)
	{
		IArrayObjectPrimitive<int>* rp = offsetPrimes->get(bitLength);
		return BIprimes->get(rp->get(0) + rnd->nextInt(rp->get(1), ctx));
	}
	int shiftCount = (-bitLength) & 31;
	int last = (bitLength + 31) >> 5;
	BigInteger* n = (new(ctx) BigInteger(1, last, ArrayAllocatorPrimitive<int>::allocatep(ctx, last), ctx));
	last -- ;
	do
	{
		for(int i = 0; i < n->numberLength; i ++ )
		{
			n->digits->set(rnd->nextInt(ctx),i, ctx);
		}
		n->digits->set(n->digits->get(last) | (0x80000000),last, ctx);
		n->digits->set(shiftCount,last, ctx);
		n->digits->set(n->digits->get(0) | (1),0, ctx);
	}
	while(!isProbablePrime(n, certainty, ctx));
	return n;
}
bool Primality::isProbablePrime(BigInteger* n, int certainty, ThreadContext* ctx) throw() 
{
	if((certainty <= 0) || ((n->numberLength == 1) && (n->digits->get(0) == 2)))
	{
		return true;
	}
	if(!n->testBit(0, ctx))
	{
		return false;
	}
	if((n->numberLength == 1) && ((n->digits->get(0) & 0XFFFFFC00) == 0))
	{
		return (Arrays::binarySearch(primes, n->digits->get(0), ctx) >= 0);
	}
	for(int i = 1; i < primes->length; i ++ )
	{
		if(Division::remainderArrayByInt(n->digits, n->numberLength, primes->get(i), ctx) == 0)
		{
			return false;
		}
	}
	int i = 0;
	int bitLength = n->bitLength(ctx);
	for(i = 2; bitLength < BITS->get(i); i ++ )
	{
		;
	}
	certainty = Math::min(i, 1 + ((certainty - 1) >> 1), ctx);
	return millerRabin(n, certainty, ctx);
}
bool Primality::millerRabin(BigInteger* n, int t, ThreadContext* ctx) throw() 
{
	BigInteger* x = 0;
	BigInteger* y = 0;
	BigInteger* n_minus_1 = n->subtract(BigInteger::ONE, ctx);
	int bitLength = n_minus_1->bitLength(ctx);
	int k = n_minus_1->getLowestSetBit(ctx);
	BigInteger* q = n_minus_1->shiftRight(k, ctx);
	Random* rnd = (new(ctx) Random(ctx));
	for(int i = 0; i < t; i ++ )
	{
		if(i < primes->length)
		{
			x = BIprimes->get(i);
		}
				else 
		{
			do
			{
				x = (new(ctx) BigInteger(bitLength, rnd, ctx));
			}
			while((x->compareTo(n, ctx) >= BigInteger::EQUALS) || (x->sign == 0) || x->isOne(ctx));
		}
		y = x->modPow(q, n, ctx);
		if(y->isOne(ctx) || y->equals(n_minus_1, ctx))
		{
			continue;
		}
		for(int j = 1; j < k; j ++ )
		{
			if(y->equals(n_minus_1, ctx))
			{
				continue;
			}
			y = y->multiply(y, ctx)->mod(n, ctx);
			if(y->isOne(ctx))
			{
				return false;
			}
		}
		if(!y->equals(n_minus_1, ctx))
		{
			return false;
		}
	}
	return true;
}
void Primality::__cleanUp(ThreadContext* ctx){
	GCUtils<IArrayObject<BigInteger>>::dec(nullptr, Primality::BIprimes, ctx, __FILEW__, __LINE__, L"IArrayObject<BigInteger>");
	GCUtils<IArrayObject<IArrayObjectPrimitive<int>>>::dec(nullptr, Primality::offsetPrimes, ctx, __FILEW__, __LINE__, L"IArrayObject<IArrayObjectPrimitive<int>>");
}
}}

