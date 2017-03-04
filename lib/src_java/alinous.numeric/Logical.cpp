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





bool Logical::__init_done = __init_static_variables();
bool Logical::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"Logical", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 Logical::~Logical() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void Logical::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
}
BigInteger* Logical::_not(BigInteger* val, ThreadContext* ctx) throw() 
{
	if(val->sign == 0)
	{
		return BigInteger::MINUS_ONE;
	}
	if(val->equals(BigInteger::MINUS_ONE, ctx))
	{
		return BigInteger::ZERO;
	}
	IArrayObjectPrimitive<int>* resDigits = ArrayAllocatorPrimitive<int>::allocatep(ctx, val->numberLength + 1);
	int i = 0;
	if(val->sign > 0)
	{
		if(val->digits->get(val->numberLength - 1) != -1)
		{
			for(i = 0; val->digits->get(i) == -1; i ++ )
			{
				;
			}
		}
				else 
		{
			for(i = 0; (i < val->numberLength) && (val->digits->get(i) == -1); i ++ )
			{
				;
			}
			if(i == val->numberLength)
			{
				resDigits->set(1,i, ctx);
				return (new(ctx) BigInteger(-val->sign, i + 1, resDigits, ctx));
			}
		}
	}
		else 
	{
		for(i = 0; val->digits->get(i) == 0; i ++ )
		{
			resDigits->set(-1,i, ctx);
		}
	}
	resDigits->set(val->digits->get(i) + val->sign,i, ctx);
	for(i ++ ; i < val->numberLength; i ++ )
	{
		resDigits->set(val->digits->get(i),i, ctx);
	}
	return (new(ctx) BigInteger(-val->sign, i, resDigits, ctx));
}
BigInteger* Logical::_and(BigInteger* val, BigInteger* that, ThreadContext* ctx) throw() 
{
	if(that->sign == 0 || val->sign == 0)
	{
		return BigInteger::ZERO;
	}
	if(that->equals(BigInteger::MINUS_ONE, ctx))
	{
		return val;
	}
	if(val->equals(BigInteger::MINUS_ONE, ctx))
	{
		return that;
	}
	if(val->sign > 0)
	{
		if(that->sign > 0)
		{
			return andPositive(val, that, ctx);
		}
				else 
		{
			return andDiffSigns(val, that, ctx);
		}
	}
		else 
	{
		if(that->sign > 0)
		{
			return andDiffSigns(that, val, ctx);
		}
				else 
		{
			if(val->numberLength > that->numberLength)
			{
				return andNegative(val, that, ctx);
			}
						else 
			{
				return andNegative(that, val, ctx);
			}
		}
	}
}
BigInteger* Logical::andPositive(BigInteger* val, BigInteger* that, ThreadContext* ctx) throw() 
{
	int resLength = Math::min(val->numberLength, that->numberLength, ctx);
	int i = Math::max(val->getFirstNonzeroDigit(ctx), that->getFirstNonzeroDigit(ctx), ctx);
	if(i >= resLength)
	{
		return BigInteger::ZERO;
	}
	IArrayObjectPrimitive<int>* resDigits = ArrayAllocatorPrimitive<int>::allocatep(ctx, resLength);
	for(; i < resLength; i ++ )
	{
		resDigits->set(val->digits->get(i) & that->digits->get(i),i, ctx);
	}
	BigInteger* result = (new(ctx) BigInteger(1, resLength, resDigits, ctx));
	result->cutOffLeadingZeroes(ctx);
	return result;
}
BigInteger* Logical::andDiffSigns(BigInteger* positive, BigInteger* negative, ThreadContext* ctx) throw() 
{
	int iPos = positive->getFirstNonzeroDigit(ctx);
	int iNeg = negative->getFirstNonzeroDigit(ctx);
	if(iNeg >= positive->numberLength)
	{
		return BigInteger::ZERO;
	}
	int resLength = positive->numberLength;
	IArrayObjectPrimitive<int>* resDigits = ArrayAllocatorPrimitive<int>::allocatep(ctx, resLength);
	int i = Math::max(iPos, iNeg, ctx);
	if(i == iNeg)
	{
		resDigits->set(-negative->digits->get(i) & positive->digits->get(i),i, ctx);
		i ++ ;
	}
	int limit = Math::min(negative->numberLength, positive->numberLength, ctx);
	for(; i < limit; i ++ )
	{
		resDigits->set(~negative->digits->get(i) & positive->digits->get(i),i, ctx);
	}
	if(i >= negative->numberLength)
	{
		for(; i < positive->numberLength; i ++ )
		{
			resDigits->set(positive->digits->get(i),i, ctx);
		}
	}
	BigInteger* result = (new(ctx) BigInteger(1, resLength, resDigits, ctx));
	result->cutOffLeadingZeroes(ctx);
	return result;
}
BigInteger* Logical::andNegative(BigInteger* longer, BigInteger* shorter, ThreadContext* ctx) throw() 
{
	int iLonger = longer->getFirstNonzeroDigit(ctx);
	int iShorter = shorter->getFirstNonzeroDigit(ctx);
	if(iLonger >= shorter->numberLength)
	{
		return longer;
	}
	int resLength = 0;
	IArrayObjectPrimitive<int>* resDigits = 0;
	int i = Math::max(iShorter, iLonger, ctx);
	int digit = 0;
	if(iShorter > iLonger)
	{
		digit = -shorter->digits->get(i) & ~longer->digits->get(i);
	}
		else 
	{
		if(iShorter < iLonger)
		{
			digit = ~shorter->digits->get(i) & -longer->digits->get(i);
		}
				else 
		{
			digit = -shorter->digits->get(i) & -longer->digits->get(i);
		}
	}
	if(digit == 0)
	{
		for(i ++ ; i < shorter->numberLength && (digit = ~(longer->digits->get(i) | shorter->digits->get(i))) == 0; i ++ )
		;
		if(digit == 0)
		{
			for(; i < longer->numberLength && (digit = ~longer->digits->get(i)) == 0; i ++ )
			;
			if(digit == 0)
			{
				resLength = longer->numberLength + 1;
				resDigits = ArrayAllocatorPrimitive<int>::allocatep(ctx, resLength);
				resDigits->set(1,resLength - 1, ctx);
				BigInteger* result = (new(ctx) BigInteger(-1, resLength, resDigits, ctx));
				return result;
			}
		}
	}
	resLength = longer->numberLength;
	resDigits = ArrayAllocatorPrimitive<int>::allocatep(ctx, resLength);
	resDigits->set(-digit,i, ctx);
	for(i ++ ; i < shorter->numberLength; i ++ )
	{
		resDigits->set(longer->digits->get(i) | shorter->digits->get(i),i, ctx);
	}
	for(; i < longer->numberLength; i ++ )
	{
		resDigits->set(longer->digits->get(i),i, ctx);
	}
	BigInteger* result = (new(ctx) BigInteger(-1, resLength, resDigits, ctx));
	return result;
}
BigInteger* Logical::andNot(BigInteger* val, BigInteger* that, ThreadContext* ctx) throw() 
{
	if(that->sign == 0)
	{
		return val;
	}
	if(val->sign == 0)
	{
		return BigInteger::ZERO;
	}
	if(val->equals(BigInteger::MINUS_ONE, ctx))
	{
		return that->_not(ctx);
	}
	if(that->equals(BigInteger::MINUS_ONE, ctx))
	{
		return BigInteger::ZERO;
	}
	if(val->sign > 0)
	{
		if(that->sign > 0)
		{
			return andNotPositive(val, that, ctx);
		}
				else 
		{
			return andNotPositiveNegative(val, that, ctx);
		}
	}
		else 
	{
		if(that->sign > 0)
		{
			return andNotNegativePositive(val, that, ctx);
		}
				else 
		{
			return andNotNegative(val, that, ctx);
		}
	}
}
BigInteger* Logical::andNotPositive(BigInteger* val, BigInteger* that, ThreadContext* ctx) throw() 
{
	IArrayObjectPrimitive<int>* resDigits = ArrayAllocatorPrimitive<int>::allocatep(ctx, val->numberLength);
	int limit = Math::min(val->numberLength, that->numberLength, ctx);
	int i = 0;
	for(i = val->getFirstNonzeroDigit(ctx); i < limit; i ++ )
	{
		resDigits->set(val->digits->get(i) & ~that->digits->get(i),i, ctx);
	}
	for(; i < val->numberLength; i ++ )
	{
		resDigits->set(val->digits->get(i),i, ctx);
	}
	BigInteger* result = (new(ctx) BigInteger(1, val->numberLength, resDigits, ctx));
	result->cutOffLeadingZeroes(ctx);
	return result;
}
BigInteger* Logical::andNotPositiveNegative(BigInteger* positive, BigInteger* negative, ThreadContext* ctx) throw() 
{
	int iNeg = negative->getFirstNonzeroDigit(ctx);
	int iPos = positive->getFirstNonzeroDigit(ctx);
	if(iNeg >= positive->numberLength)
	{
		return positive;
	}
	int resLength = Math::min(positive->numberLength, negative->numberLength, ctx);
	IArrayObjectPrimitive<int>* resDigits = ArrayAllocatorPrimitive<int>::allocatep(ctx, resLength);
	int i = iPos;
	for(; i < iNeg; i ++ )
	{
		resDigits->set(positive->digits->get(i),i, ctx);
	}
	if(i == iNeg)
	{
		resDigits->set(positive->digits->get(i) & (negative->digits->get(i) - 1),i, ctx);
		i ++ ;
	}
	for(; i < resLength; i ++ )
	{
		resDigits->set(positive->digits->get(i) & negative->digits->get(i),i, ctx);
	}
	BigInteger* result = (new(ctx) BigInteger(1, resLength, resDigits, ctx));
	result->cutOffLeadingZeroes(ctx);
	return result;
}
BigInteger* Logical::andNotNegativePositive(BigInteger* negative, BigInteger* positive, ThreadContext* ctx) throw() 
{
	int resLength = 0;
	IArrayObjectPrimitive<int>* resDigits = 0;
	int limit = 0;
	int digit = 0;
	int iNeg = negative->getFirstNonzeroDigit(ctx);
	int iPos = positive->getFirstNonzeroDigit(ctx);
	if(iNeg >= positive->numberLength)
	{
		return negative;
	}
	resLength = Math::max(negative->numberLength, positive->numberLength, ctx);
	int i = iNeg;
	if(iPos > iNeg)
	{
		resDigits = ArrayAllocatorPrimitive<int>::allocatep(ctx, resLength);
		limit = Math::min(negative->numberLength, iPos, ctx);
		for(; i < limit; i ++ )
		{
			resDigits->set(negative->digits->get(i),i, ctx);
		}
		if(i == negative->numberLength)
		{
			for(i = iPos; i < positive->numberLength; i ++ )
			{
				resDigits->set(positive->digits->get(i),i, ctx);
			}
		}
	}
		else 
	{
		digit = -negative->digits->get(i) & ~positive->digits->get(i);
		if(digit == 0)
		{
			limit = Math::min(positive->numberLength, negative->numberLength, ctx);
			for(i ++ ; i < limit && (digit = ~(negative->digits->get(i) | positive->digits->get(i))) == 0; i ++ )
			;
			if(digit == 0)
			{
				for(; i < positive->numberLength && (digit = ~positive->digits->get(i)) == 0; i ++ )
				;
				for(; i < negative->numberLength && (digit = ~negative->digits->get(i)) == 0; i ++ )
				;
				if(digit == 0)
				{
					resLength ++ ;
					resDigits = ArrayAllocatorPrimitive<int>::allocatep(ctx, resLength);
					resDigits->set(1,resLength - 1, ctx);
					BigInteger* result = (new(ctx) BigInteger(-1, resLength, resDigits, ctx));
					return result;
				}
			}
		}
		resDigits = ArrayAllocatorPrimitive<int>::allocatep(ctx, resLength);
		resDigits->set(-digit,i, ctx);
		i ++ ;
	}
	limit = Math::min(positive->numberLength, negative->numberLength, ctx);
	for(; i < limit; i ++ )
	{
		resDigits->set(negative->digits->get(i) | positive->digits->get(i),i, ctx);
	}
	for(; i < negative->numberLength; i ++ )
	{
		resDigits->set(negative->digits->get(i),i, ctx);
	}
	for(; i < positive->numberLength; i ++ )
	{
		resDigits->set(positive->digits->get(i),i, ctx);
	}
	BigInteger* result = (new(ctx) BigInteger(-1, resLength, resDigits, ctx));
	return result;
}
BigInteger* Logical::andNotNegative(BigInteger* val, BigInteger* that, ThreadContext* ctx) throw() 
{
	int iVal = val->getFirstNonzeroDigit(ctx);
	int iThat = that->getFirstNonzeroDigit(ctx);
	if(iVal >= that->numberLength)
	{
		return BigInteger::ZERO;
	}
	int resLength = that->numberLength;
	IArrayObjectPrimitive<int>* resDigits = ArrayAllocatorPrimitive<int>::allocatep(ctx, resLength);
	int limit = 0;
	int i = iVal;
	if(iVal < iThat)
	{
		resDigits->set(-val->digits->get(i),i, ctx);
		limit = Math::min(val->numberLength, iThat, ctx);
		for(i ++ ; i < limit; i ++ )
		{
			resDigits->set(~val->digits->get(i),i, ctx);
		}
		if(i == val->numberLength)
		{
			for(; i < iThat; i ++ )
			{
				resDigits->set(-1,i, ctx);
			}
			resDigits->set(that->digits->get(i) - 1,i, ctx);
		}
				else 
		{
			resDigits->set(~val->digits->get(i) & (that->digits->get(i) - 1),i, ctx);
		}
	}
		else 
	{
		if(iThat < iVal)
		{
			resDigits->set(-val->digits->get(i) & that->digits->get(i),i, ctx);
		}
				else 
		{
			resDigits->set(-val->digits->get(i) & (that->digits->get(i) - 1),i, ctx);
		}
	}
	limit = Math::min(val->numberLength, that->numberLength, ctx);
	for(i ++ ; i < limit; i ++ )
	{
		resDigits->set(~val->digits->get(i) & that->digits->get(i),i, ctx);
	}
	for(; i < that->numberLength; i ++ )
	{
		resDigits->set(that->digits->get(i),i, ctx);
	}
	BigInteger* result = (new(ctx) BigInteger(1, resLength, resDigits, ctx));
	result->cutOffLeadingZeroes(ctx);
	return result;
}
BigInteger* Logical::_or(BigInteger* val, BigInteger* that, ThreadContext* ctx) throw() 
{
	if(that->equals(BigInteger::MINUS_ONE, ctx) || val->equals(BigInteger::MINUS_ONE, ctx))
	{
		return BigInteger::MINUS_ONE;
	}
	if(that->sign == 0)
	{
		return val;
	}
	if(val->sign == 0)
	{
		return that;
	}
	if(val->sign > 0)
	{
		if(that->sign > 0)
		{
			if(val->numberLength > that->numberLength)
			{
				return orPositive(val, that, ctx);
			}
						else 
			{
				return orPositive(that, val, ctx);
			}
		}
				else 
		{
			return orDiffSigns(val, that, ctx);
		}
	}
		else 
	{
		if(that->sign > 0)
		{
			return orDiffSigns(that, val, ctx);
		}
				else 
		{
			if(that->getFirstNonzeroDigit(ctx) > val->getFirstNonzeroDigit(ctx))
			{
				return orNegative(that, val, ctx);
			}
						else 
			{
				return orNegative(val, that, ctx);
			}
		}
	}
}
BigInteger* Logical::orPositive(BigInteger* longer, BigInteger* shorter, ThreadContext* ctx) throw() 
{
	int resLength = longer->numberLength;
	IArrayObjectPrimitive<int>* resDigits = ArrayAllocatorPrimitive<int>::allocatep(ctx, resLength);
	int i = Math::min(longer->getFirstNonzeroDigit(ctx), shorter->getFirstNonzeroDigit(ctx), ctx);
	for(i = 0; i < shorter->numberLength; i ++ )
	{
		resDigits->set(longer->digits->get(i) | shorter->digits->get(i),i, ctx);
	}
	for(; i < resLength; i ++ )
	{
		resDigits->set(longer->digits->get(i),i, ctx);
	}
	BigInteger* result = (new(ctx) BigInteger(1, resLength, resDigits, ctx));
	return result;
}
BigInteger* Logical::orNegative(BigInteger* val, BigInteger* that, ThreadContext* ctx) throw() 
{
	int iThat = that->getFirstNonzeroDigit(ctx);
	int iVal = val->getFirstNonzeroDigit(ctx);
	int i = 0;
	if(iVal >= that->numberLength)
	{
		return that;
	}
		else 
	{
		if(iThat >= val->numberLength)
		{
			return val;
		}
	}
	int resLength = Math::min(val->numberLength, that->numberLength, ctx);
	IArrayObjectPrimitive<int>* resDigits = ArrayAllocatorPrimitive<int>::allocatep(ctx, resLength);
	if(iThat == iVal)
	{
		resDigits->set(-(-val->digits->get(iVal) | -that->digits->get(iVal)),iVal, ctx);
		i = iVal;
	}
		else 
	{
		for(i = iThat; i < iVal; i ++ )
		{
			resDigits->set(that->digits->get(i),i, ctx);
		}
		resDigits->set(that->digits->get(i) & (val->digits->get(i) - 1),i, ctx);
	}
	for(i ++ ; i < resLength; i ++ )
	{
		resDigits->set(val->digits->get(i) & that->digits->get(i),i, ctx);
	}
	BigInteger* result = (new(ctx) BigInteger(-1, resLength, resDigits, ctx));
	result->cutOffLeadingZeroes(ctx);
	return result;
}
BigInteger* Logical::orDiffSigns(BigInteger* positive, BigInteger* negative, ThreadContext* ctx) throw() 
{
	int iNeg = negative->getFirstNonzeroDigit(ctx);
	int iPos = positive->getFirstNonzeroDigit(ctx);
	int i = 0;
	int limit = 0;
	if(iPos >= negative->numberLength)
	{
		return negative;
	}
	int resLength = negative->numberLength;
	IArrayObjectPrimitive<int>* resDigits = ArrayAllocatorPrimitive<int>::allocatep(ctx, resLength);
	if(iNeg < iPos)
	{
		for(i = iNeg; i < iPos; i ++ )
		{
			resDigits->set(negative->digits->get(i),i, ctx);
		}
	}
		else 
	{
		if(iPos < iNeg)
		{
			i = iPos;
			resDigits->set(-positive->digits->get(i),i, ctx);
			limit = Math::min(positive->numberLength, iNeg, ctx);
			for(i ++ ; i < limit; i ++ )
			{
				resDigits->set(~positive->digits->get(i),i, ctx);
			}
			if(i != positive->numberLength)
			{
				resDigits->set(~(-negative->digits->get(i) | positive->digits->get(i)),i, ctx);
			}
						else 
			{
				for(; i < iNeg; i ++ )
				{
					resDigits->set(-1,i, ctx);
				}
				resDigits->set(negative->digits->get(i) - 1,i, ctx);
			}
			i ++ ;
		}
				else 
		{
			i = iPos;
			resDigits->set(-(-negative->digits->get(i) | positive->digits->get(i)),i, ctx);
			i ++ ;
		}
	}
	limit = Math::min(negative->numberLength, positive->numberLength, ctx);
	for(; i < limit; i ++ )
	{
		resDigits->set(negative->digits->get(i) & ~positive->digits->get(i),i, ctx);
	}
	for(; i < negative->numberLength; i ++ )
	{
		resDigits->set(negative->digits->get(i),i, ctx);
	}
	BigInteger* result = (new(ctx) BigInteger(-1, resLength, resDigits, ctx));
	result->cutOffLeadingZeroes(ctx);
	return result;
}
BigInteger* Logical::_xor(BigInteger* val, BigInteger* that, ThreadContext* ctx) throw() 
{
	if(that->sign == 0)
	{
		return val;
	}
	if(val->sign == 0)
	{
		return that;
	}
	if(that->equals(BigInteger::MINUS_ONE, ctx))
	{
		return val->_not(ctx);
	}
	if(val->equals(BigInteger::MINUS_ONE, ctx))
	{
		return that->_not(ctx);
	}
	if(val->sign > 0)
	{
		if(that->sign > 0)
		{
			if(val->numberLength > that->numberLength)
			{
				return xorPositive(val, that, ctx);
			}
						else 
			{
				return xorPositive(that, val, ctx);
			}
		}
				else 
		{
			return xorDiffSigns(val, that, ctx);
		}
	}
		else 
	{
		if(that->sign > 0)
		{
			return xorDiffSigns(that, val, ctx);
		}
				else 
		{
			if(that->getFirstNonzeroDigit(ctx) > val->getFirstNonzeroDigit(ctx))
			{
				return xorNegative(that, val, ctx);
			}
						else 
			{
				return xorNegative(val, that, ctx);
			}
		}
	}
}
BigInteger* Logical::xorPositive(BigInteger* longer, BigInteger* shorter, ThreadContext* ctx) throw() 
{
	int resLength = longer->numberLength;
	IArrayObjectPrimitive<int>* resDigits = ArrayAllocatorPrimitive<int>::allocatep(ctx, resLength);
	int i = Math::min(longer->getFirstNonzeroDigit(ctx), shorter->getFirstNonzeroDigit(ctx), ctx);
	for(; i < shorter->numberLength; i ++ )
	{
		resDigits->set(longer->digits->get(i) ^ shorter->digits->get(i),i, ctx);
	}
	for(; i < longer->numberLength; i ++ )
	{
		resDigits->set(longer->digits->get(i),i, ctx);
	}
	BigInteger* result = (new(ctx) BigInteger(1, resLength, resDigits, ctx));
	result->cutOffLeadingZeroes(ctx);
	return result;
}
BigInteger* Logical::xorNegative(BigInteger* val, BigInteger* that, ThreadContext* ctx) throw() 
{
	int resLength = Math::max(val->numberLength, that->numberLength, ctx);
	IArrayObjectPrimitive<int>* resDigits = ArrayAllocatorPrimitive<int>::allocatep(ctx, resLength);
	int iVal = val->getFirstNonzeroDigit(ctx);
	int iThat = that->getFirstNonzeroDigit(ctx);
	int i = iThat;
	int limit = 0;
	if(iVal == iThat)
	{
		resDigits->set(-val->digits->get(i) ^ -that->digits->get(i),i, ctx);
	}
		else 
	{
		resDigits->set(-that->digits->get(i),i, ctx);
		limit = Math::min(that->numberLength, iVal, ctx);
		for(i ++ ; i < limit; i ++ )
		{
			resDigits->set(~that->digits->get(i),i, ctx);
		}
		if(i == that->numberLength)
		{
			for(; i < iVal; i ++ )
			{
				resDigits->set(-1,i, ctx);
			}
			resDigits->set(val->digits->get(i) - 1,i, ctx);
		}
				else 
		{
			resDigits->set(-val->digits->get(i) ^ ~that->digits->get(i),i, ctx);
		}
	}
	limit = Math::min(val->numberLength, that->numberLength, ctx);
	for(i ++ ; i < limit; i ++ )
	{
		resDigits->set(val->digits->get(i) ^ that->digits->get(i),i, ctx);
	}
	for(; i < val->numberLength; i ++ )
	{
		resDigits->set(val->digits->get(i),i, ctx);
	}
	for(; i < that->numberLength; i ++ )
	{
		resDigits->set(that->digits->get(i),i, ctx);
	}
	BigInteger* result = (new(ctx) BigInteger(1, resLength, resDigits, ctx));
	result->cutOffLeadingZeroes(ctx);
	return result;
}
BigInteger* Logical::xorDiffSigns(BigInteger* positive, BigInteger* negative, ThreadContext* ctx) throw() 
{
	int resLength = Math::max(negative->numberLength, positive->numberLength, ctx);
	IArrayObjectPrimitive<int>* resDigits = 0;
	int iNeg = negative->getFirstNonzeroDigit(ctx);
	int iPos = positive->getFirstNonzeroDigit(ctx);
	int i = 0;
	int limit = 0;
	if(iNeg < iPos)
	{
		resDigits = ArrayAllocatorPrimitive<int>::allocatep(ctx, resLength);
		i = iNeg;
		resDigits->set(negative->digits->get(i),i, ctx);
		limit = Math::min(negative->numberLength, iPos, ctx);
		for(i ++ ; i < limit; i ++ )
		{
			resDigits->set(negative->digits->get(i),i, ctx);
		}
		if(i == negative->numberLength)
		{
			for(; i < positive->numberLength; i ++ )
			{
				resDigits->set(positive->digits->get(i),i, ctx);
			}
		}
	}
		else 
	{
		if(iPos < iNeg)
		{
			resDigits = ArrayAllocatorPrimitive<int>::allocatep(ctx, resLength);
			i = iPos;
			resDigits->set(-positive->digits->get(i),i, ctx);
			limit = Math::min(positive->numberLength, iNeg, ctx);
			for(i ++ ; i < limit; i ++ )
			{
				resDigits->set(~positive->digits->get(i),i, ctx);
			}
			if(i == iNeg)
			{
				resDigits->set(~(positive->digits->get(i) ^ -negative->digits->get(i)),i, ctx);
				i ++ ;
			}
						else 
			{
				for(; i < iNeg; i ++ )
				{
					resDigits->set(-1,i, ctx);
				}
				for(; i < negative->numberLength; i ++ )
				{
					resDigits->set(negative->digits->get(i),i, ctx);
				}
			}
		}
				else 
		{
			int digit = 0;
			i = iNeg;
			digit = positive->digits->get(i) ^ -negative->digits->get(i);
			if(digit == 0)
			{
				limit = Math::min(positive->numberLength, negative->numberLength, ctx);
				for(i ++ ; i < limit && (digit = positive->digits->get(i) ^ ~negative->digits->get(i)) == 0; i ++ )
				;
				if(digit == 0)
				{
					for(; i < positive->numberLength && (digit = ~positive->digits->get(i)) == 0; i ++ )
					;
					for(; i < negative->numberLength && (digit = ~negative->digits->get(i)) == 0; i ++ )
					;
					if(digit == 0)
					{
						resLength = resLength + 1;
						resDigits = ArrayAllocatorPrimitive<int>::allocatep(ctx, resLength);
						resDigits->set(1,resLength - 1, ctx);
						BigInteger* result = (new(ctx) BigInteger(-1, resLength, resDigits, ctx));
						return result;
					}
				}
			}
			resDigits = ArrayAllocatorPrimitive<int>::allocatep(ctx, resLength);
			resDigits->set(-digit,i, ctx);
			i ++ ;
		}
	}
	limit = Math::min(negative->numberLength, positive->numberLength, ctx);
	for(; i < limit; i ++ )
	{
		resDigits->set(~(~negative->digits->get(i) ^ positive->digits->get(i)),i, ctx);
	}
	for(; i < positive->numberLength; i ++ )
	{
		resDigits->set(positive->digits->get(i),i, ctx);
	}
	for(; i < negative->numberLength; i ++ )
	{
		resDigits->set(negative->digits->get(i),i, ctx);
	}
	BigInteger* result = (new(ctx) BigInteger(-1, resLength, resDigits, ctx));
	result->cutOffLeadingZeroes(ctx);
	return result;
}
}}

