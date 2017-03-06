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





bool Elementary::__init_done = __init_static_variables();
bool Elementary::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"Elementary", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 Elementary::Elementary(ThreadContext* ctx) throw()  : IObject(ctx)
{
}
void Elementary::__construct_impl(ThreadContext* ctx) throw() 
{
}
 Elementary::~Elementary() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void Elementary::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
}
int Elementary::compareArrays(IArrayObjectPrimitive<int>* a, IArrayObjectPrimitive<int>* b, int size, ThreadContext* ctx) throw() 
{
	int i = 0;
	for(i = size - 1; (i >= 0) && (a->get(i) == b->get(i)); i -- )
	{
		;
	}
	return ((i < 0) ? BigInteger::EQUALS : (a->get(i) & 0xFFFFFFFFL) < (b->get(i) & 0xFFFFFFFFL) ? BigInteger::LESS : BigInteger::GREATER);
}
BigInteger* Elementary::add(BigInteger* op1, BigInteger* op2, ThreadContext* ctx) throw() 
{
	IArrayObjectPrimitive<int>* resDigits = 0;
	int resSign = 0;
	int op1Sign = op1->sign;
	int op2Sign = op2->sign;
	if(op1Sign == 0)
	{
		return op2;
	}
	if(op2Sign == 0)
	{
		return op1;
	}
	int op1Len = op1->numberLength;
	int op2Len = op2->numberLength;
	if(op1Len + op2Len == 2)
	{
		long long a = (op1->digits->get(0) & 0xFFFFFFFFL);
		long long b = (op2->digits->get(0) & 0xFFFFFFFFL);
		long long res = 0;
		int valueLo = 0;
		int valueHi = 0;
		if(op1Sign == op2Sign)
		{
			res = a + b;
			valueLo = ((int)res);
			valueHi = ((int)(((unsigned long long)res)>> 32));
			return ((valueHi == 0) ? (new(ctx) BigInteger(op1Sign, valueLo, ctx)) : (new(ctx) BigInteger(op1Sign, 2, ((IArrayObjectPrimitive<int>*)new(ctx) ArrayObjectPrimitive<int>({valueLo, valueHi}, ctx)), ctx)));
		}
		return BigInteger::valueOf((op1Sign < 0) ? (b - a) : (a - b), ctx);
	}
		else 
	{
		if(op1Sign == op2Sign)
		{
			resSign = op1Sign;
			resDigits = (op1Len >= op2Len) ? add(op1->digits, op1Len, op2->digits, op2Len, ctx) : add(op2->digits, op2Len, op1->digits, op1Len, ctx);
		}
				else 
		{
			int cmp = ((op1Len != op2Len) ? ((op1Len > op2Len) ? 1 : -1) : compareArrays(op1->digits, op2->digits, op1Len, ctx));
			if(cmp == BigInteger::EQUALS)
			{
				return BigInteger::ZERO;
			}
			if(cmp == BigInteger::GREATER)
			{
				resSign = op1Sign;
				resDigits = subtract(op1->digits, op1Len, op2->digits, op2Len, ctx);
			}
						else 
			{
				resSign = op2Sign;
				resDigits = subtract(op2->digits, op2Len, op1->digits, op1Len, ctx);
			}
		}
	}
	BigInteger* res = (new(ctx) BigInteger(resSign, resDigits->length, resDigits, ctx));
	res->cutOffLeadingZeroes(ctx);
	return res;
}
BigInteger* Elementary::subtract(BigInteger* op1, BigInteger* op2, ThreadContext* ctx) throw() 
{
	int resSign = 0;
	IArrayObjectPrimitive<int>* resDigits = 0;
	int op1Sign = op1->sign;
	int op2Sign = op2->sign;
	if(op2Sign == 0)
	{
		return op1;
	}
	if(op1Sign == 0)
	{
		return op2->negate(ctx);
	}
	int op1Len = op1->numberLength;
	int op2Len = op2->numberLength;
	if(op1Len + op2Len == 2)
	{
		long long a = (op1->digits->get(0) & 0xFFFFFFFFL);
		long long b = (op2->digits->get(0) & 0xFFFFFFFFL);
		if(op1Sign < 0)
		{
			a = -a;
		}
		if(op2Sign < 0)
		{
			b = -b;
		}
		return BigInteger::valueOf(a - b, ctx);
	}
	int cmp = ((op1Len != op2Len) ? ((op1Len > op2Len) ? 1 : -1) : Elementary::compareArrays(op1->digits, op2->digits, op1Len, ctx));
	if(cmp == BigInteger::LESS)
	{
		resSign = -op2Sign;
		resDigits = (op1Sign == op2Sign) ? subtract(op2->digits, op2Len, op1->digits, op1Len, ctx) : add(op2->digits, op2Len, op1->digits, op1Len, ctx);
	}
		else 
	{
		resSign = op1Sign;
		if(op1Sign == op2Sign)
		{
			if(cmp == BigInteger::EQUALS)
			{
				return BigInteger::ZERO;
			}
			resDigits = subtract(op1->digits, op1Len, op2->digits, op2Len, ctx);
		}
				else 
		{
			resDigits = add(op1->digits, op1Len, op2->digits, op2Len, ctx);
		}
	}
	BigInteger* res = (new(ctx) BigInteger(resSign, resDigits->length, resDigits, ctx));
	res->cutOffLeadingZeroes(ctx);
	return res;
}
void Elementary::inplaceAdd(BigInteger* op1, BigInteger* op2, ThreadContext* ctx) throw() 
{
	add(op1->digits, op1->digits, op1->numberLength, op2->digits, op2->numberLength, ctx);
	op1->numberLength = Math::min(Math::max(op1->numberLength, op2->numberLength, ctx) + 1, op1->digits->length, ctx);
	op1->cutOffLeadingZeroes(ctx);
	op1->unCache(ctx);
}
int Elementary::inplaceAdd(IArrayObjectPrimitive<int>* a, int aSize, int addend, ThreadContext* ctx) throw() 
{
	long long carry = addend & 0xFFFFFFFFL;
	for(int i = 0; (carry != (long long)0) && (i < aSize); i ++ )
	{
		carry += a->get(i) & 0xFFFFFFFFL;
		a->set(((int)carry),i, ctx);
		carry >>= 32;
	}
	return ((int)carry);
}
void Elementary::inplaceAdd(BigInteger* op1, int addend, ThreadContext* ctx) throw() 
{
	int carry = inplaceAdd(op1->digits, op1->numberLength, addend, ctx);
	if(carry == 1)
	{
		op1->digits->set(1,op1->numberLength, ctx);
		op1->numberLength ++ ;
	}
	op1->unCache(ctx);
}
void Elementary::inplaceSubtract(BigInteger* op1, BigInteger* op2, ThreadContext* ctx) throw() 
{
	subtract(op1->digits, op1->digits, op1->numberLength, op2->digits, op2->numberLength, ctx);
	op1->cutOffLeadingZeroes(ctx);
	op1->unCache(ctx);
}
void Elementary::completeInPlaceSubtract(BigInteger* op1, BigInteger* op2, ThreadContext* ctx) throw() 
{
	int resultSign = op1->compareTo(op2, ctx);
	if(op1->sign == 0)
	{
		System::arraycopy(op2->digits, 0, op1->digits, 0, op2->numberLength, ctx);
		op1->sign = -op2->sign;
	}
		else 
	{
		if(op1->sign != op2->sign)
		{
			add(op1->digits, op1->digits, op1->numberLength, op2->digits, op2->numberLength, ctx);
			op1->sign = resultSign;
		}
				else 
		{
			int sign = unsignedArraysCompare(op1->digits, op2->digits, op1->numberLength, op2->numberLength, ctx);
			if(sign > 0)
			{
				subtract(op1->digits, op1->digits, op1->numberLength, op2->digits, op2->numberLength, ctx);
			}
						else 
			{
				inverseSubtract(op1->digits, op1->digits, op1->numberLength, op2->digits, op2->numberLength, ctx);
				op1->sign = -op1->sign;
			}
		}
	}
	op1->numberLength = Math::max(op1->numberLength, op2->numberLength, ctx) + 1;
	op1->cutOffLeadingZeroes(ctx);
	op1->unCache(ctx);
}
void Elementary::completeInPlaceAdd(BigInteger* op1, BigInteger* op2, ThreadContext* ctx) throw() 
{
	if(op1->sign == 0)
	{
		System::arraycopy(op2->digits, 0, op1->digits, 0, op2->numberLength, ctx);
	}
		else 
	{
		if(op2->sign == 0)
		{
			return;
		}
				else 
		{
			if(op1->sign == op2->sign)
			{
				add(op1->digits, op1->digits, op1->numberLength, op2->digits, op2->numberLength, ctx);
			}
						else 
			{
				int sign = unsignedArraysCompare(op1->digits, op2->digits, op1->numberLength, op2->numberLength, ctx);
				if(sign > 0)
				{
					subtract(op1->digits, op1->digits, op1->numberLength, op2->digits, op2->numberLength, ctx);
				}
								else 
				{
					inverseSubtract(op1->digits, op1->digits, op1->numberLength, op2->digits, op2->numberLength, ctx);
					op1->sign = -op1->sign;
				}
			}
		}
	}
	op1->numberLength = Math::max(op1->numberLength, op2->numberLength, ctx) + 1;
	op1->cutOffLeadingZeroes(ctx);
	op1->unCache(ctx);
}
void Elementary::add(IArrayObjectPrimitive<int>* res, IArrayObjectPrimitive<int>* a, int aSize, IArrayObjectPrimitive<int>* b, int bSize, ThreadContext* ctx) throw() 
{
	int i = 0;
	long long carry = (a->get(0) & 0xFFFFFFFFL) + (b->get(0) & 0xFFFFFFFFL);
	res->set(((int)carry),0, ctx);
	carry >>= 32;
	if(aSize >= bSize)
	{
		for(i = 1; i < bSize; i ++ )
		{
			carry += (a->get(i) & 0xFFFFFFFFL) + (b->get(i) & 0xFFFFFFFFL);
			res->set(((int)carry),i, ctx);
			carry >>= 32;
		}
		for(; i < aSize; i ++ )
		{
			carry += a->get(i) & 0xFFFFFFFFL;
			res->set(((int)carry),i, ctx);
			carry >>= 32;
		}
	}
		else 
	{
		for(i = 1; i < aSize; i ++ )
		{
			carry += (a->get(i) & 0xFFFFFFFFL) + (b->get(i) & 0xFFFFFFFFL);
			res->set(((int)carry),i, ctx);
			carry >>= 32;
		}
		for(; i < bSize; i ++ )
		{
			carry += b->get(i) & 0xFFFFFFFFL;
			res->set(((int)carry),i, ctx);
			carry >>= 32;
		}
	}
	if(carry != (long long)0)
	{
		res->set(((int)carry),i, ctx);
	}
}
void Elementary::subtract(IArrayObjectPrimitive<int>* res, IArrayObjectPrimitive<int>* a, int aSize, IArrayObjectPrimitive<int>* b, int bSize, ThreadContext* ctx) throw() 
{
	int i = 0;
	long long borrow = 0;
	for(i = 0; i < bSize; i ++ )
	{
		borrow += (a->get(i) & 0xFFFFFFFFL) - (b->get(i) & 0xFFFFFFFFL);
		res->set(((int)borrow),i, ctx);
		borrow >>= 32;
	}
	for(; i < aSize; i ++ )
	{
		borrow += a->get(i) & 0xFFFFFFFFL;
		res->set(((int)borrow),i, ctx);
		borrow >>= 32;
	}
}
IArrayObjectPrimitive<int>* Elementary::add(IArrayObjectPrimitive<int>* a, int aSize, IArrayObjectPrimitive<int>* b, int bSize, ThreadContext* ctx) throw() 
{
	IArrayObjectPrimitive<int>* res = ArrayAllocatorPrimitive<int>::allocatep(ctx, aSize + 1);
	add(res, a, aSize, b, bSize, ctx);
	return res;
}
void Elementary::inverseSubtract(IArrayObjectPrimitive<int>* res, IArrayObjectPrimitive<int>* a, int aSize, IArrayObjectPrimitive<int>* b, int bSize, ThreadContext* ctx) throw() 
{
	int i = 0;
	long long borrow = 0;
	if(aSize < bSize)
	{
		for(i = 0; i < aSize; i ++ )
		{
			borrow += (b->get(i) & 0xFFFFFFFFL) - (a->get(i) & 0xFFFFFFFFL);
			res->set(((int)borrow),i, ctx);
			borrow >>= 32;
		}
		for(; i < bSize; i ++ )
		{
			borrow += b->get(i) & 0xFFFFFFFFL;
			res->set(((int)borrow),i, ctx);
			borrow >>= 32;
		}
	}
		else 
	{
		for(i = 0; i < bSize; i ++ )
		{
			borrow += (b->get(i) & 0xFFFFFFFFL) - (a->get(i) & 0xFFFFFFFFL);
			res->set(((int)borrow),i, ctx);
			borrow >>= 32;
		}
		for(; i < aSize; i ++ )
		{
			borrow -= a->get(i) & 0xFFFFFFFFL;
			res->set(((int)borrow),i, ctx);
			borrow >>= 32;
		}
	}
}
IArrayObjectPrimitive<int>* Elementary::subtract(IArrayObjectPrimitive<int>* a, int aSize, IArrayObjectPrimitive<int>* b, int bSize, ThreadContext* ctx) throw() 
{
	IArrayObjectPrimitive<int>* res = ArrayAllocatorPrimitive<int>::allocatep(ctx, aSize);
	subtract(res, a, aSize, b, bSize, ctx);
	return res;
}
int Elementary::unsignedArraysCompare(IArrayObjectPrimitive<int>* a, IArrayObjectPrimitive<int>* b, int aSize, int bSize, ThreadContext* ctx) throw() 
{
	if(aSize > bSize)
	{
		return 1;
	}
		else 
	{
		if(aSize < bSize)
		{
			return -1;
		}
				else 
		{
			int i = 0;
			for(i = aSize - 1; i >= 0 && a->get(i) == b->get(i); i -- )
			;
			return i < 0 ? BigInteger::EQUALS : ((a->get(i) & 0xFFFFFFFFL) < (b->get(i) & 0xFFFFFFFFL) ? BigInteger::LESS : BigInteger::GREATER);
		}
	}
}
void Elementary::__cleanUp(ThreadContext* ctx){
}
}}

