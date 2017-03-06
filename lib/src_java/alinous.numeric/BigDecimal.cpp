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





BigDecimal* BigDecimal::ZERO = nullptr;
BigDecimal* BigDecimal::ONE = nullptr;
BigDecimal* BigDecimal::TEN = nullptr;
constexpr const int BigDecimal::ROUND_UP;
constexpr const int BigDecimal::ROUND_DOWN;
constexpr const int BigDecimal::ROUND_CEILING;
constexpr const int BigDecimal::ROUND_FLOOR;
constexpr const int BigDecimal::ROUND_HALF_UP;
constexpr const int BigDecimal::ROUND_HALF_DOWN;
constexpr const int BigDecimal::ROUND_HALF_EVEN;
constexpr const int BigDecimal::ROUND_UNNECESSARY;
constexpr const double BigDecimal::LOG10_2;
IArrayObject<BigInteger>* BigDecimal::FIVE_POW = nullptr;
IArrayObject<BigInteger>* BigDecimal::TEN_POW = nullptr;
const StaticArrayObjectPrimitive<long long> BigDecimal::__LONG_TEN_POW = {1L, 10L, 100L, 1000L, 10000L, 100000L, 1000000L, 10000000L, 100000000L, 1000000000L, 10000000000L, 100000000000L, 1000000000000L, 10000000000000L, 100000000000000L, 1000000000000000L, 10000000000000000L, 100000000000000000L, 1000000000000000000L};
IArrayObjectPrimitive<long long>* BigDecimal::LONG_TEN_POW = (IArrayObjectPrimitive<long long>*)const_cast<StaticArrayObjectPrimitive<long long>*>(&__LONG_TEN_POW);
const StaticArrayObjectPrimitive<long long> BigDecimal::__LONG_FIVE_POW = {1L, 5L, 25L, 125L, 625L, 3125L, 15625L, 78125L, 390625L, 1953125L, 9765625L, 48828125L, 244140625L, 1220703125L, 6103515625L, 30517578125L, 152587890625L, 762939453125L, 3814697265625L, 19073486328125L, 95367431640625L, 476837158203125L, 2384185791015625L, 11920928955078125L, 59604644775390625L, 298023223876953125L, 1490116119384765625L, 7450580596923828125L};
IArrayObjectPrimitive<long long>* BigDecimal::LONG_FIVE_POW = (IArrayObjectPrimitive<long long>*)const_cast<StaticArrayObjectPrimitive<long long>*>(&__LONG_FIVE_POW);
IArrayObjectPrimitive<int>* BigDecimal::LONG_FIVE_POW_BIT_LENGTH = nullptr;
IArrayObjectPrimitive<int>* BigDecimal::LONG_TEN_POW_BIT_LENGTH = nullptr;
constexpr const int BigDecimal::BI_SCALED_BY_ZERO_LENGTH;
IArrayObject<BigDecimal>* BigDecimal::BI_SCALED_BY_ZERO = nullptr;
IArrayObject<BigDecimal>* BigDecimal::ZERO_SCALED_BY = nullptr;
IArrayObjectPrimitive<wchar_t>* BigDecimal::CH_ZEROS = nullptr;
LockObject* BigDecimal::initLock = nullptr;
bool BigDecimal::initBigDecimalDone = 0;
bool BigDecimal::__init_done = __init_static_variables();
bool BigDecimal::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"BigDecimal", L"__init_static_variables");
		__GC_MV(nullptr, &(ZERO), (new(ctx) BigDecimal(0, 0, ctx)), BigDecimal);
		__GC_MV(nullptr, &(ONE), (new(ctx) BigDecimal(1, 0, ctx)), BigDecimal);
		__GC_MV(nullptr, &(TEN), (new(ctx) BigDecimal(10, 0, ctx)), BigDecimal);
		__GC_MV(nullptr, &(FIVE_POW), nullptr, IArrayObject<BigInteger>);
		__GC_MV(nullptr, &(TEN_POW), nullptr, IArrayObject<BigInteger>);
		__GC_MV(nullptr, &(LONG_FIVE_POW_BIT_LENGTH), (new ArrayObjectPrimitive<int>(ArrayAllocatorPrimitive<int>::allocatep(ctx, LONG_FIVE_POW->length), ctx)), IArrayObjectPrimitive<int>);
		__GC_MV(nullptr, &(LONG_TEN_POW_BIT_LENGTH), (new ArrayObjectPrimitive<int>(ArrayAllocatorPrimitive<int>::allocatep(ctx, LONG_TEN_POW->length), ctx)), IArrayObjectPrimitive<int>);
		__GC_MV(nullptr, &(BI_SCALED_BY_ZERO), (new ArrayObject<BigDecimal>(ArrayAllocator<BigDecimal>::allocate(ctx, BI_SCALED_BY_ZERO_LENGTH), ctx)), IArrayObject<BigDecimal>);
		__GC_MV(nullptr, &(ZERO_SCALED_BY), (new ArrayObject<BigDecimal>(ArrayAllocator<BigDecimal>::allocate(ctx, 11), ctx)), IArrayObject<BigDecimal>);
		__GC_MV(nullptr, &(CH_ZEROS), (new ArrayObjectPrimitive<wchar_t>(ArrayAllocatorPrimitive<wchar_t>::allocatep(ctx, 100), ctx)), IArrayObjectPrimitive<wchar_t>);
		__GC_MV(nullptr, &(initLock), (new(ctx) LockObject(ctx)), LockObject);
		BigDecimal::initBigDecimalDone = false;
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 BigDecimal::BigDecimal(long long smallValue, int scale, ThreadContext* ctx) throw()  : IObject(ctx), Number(ctx), Comparable<BigDecimal>(ctx), toStringImage(nullptr), _hashCode(0), intVal(nullptr), _bitLength(0), smallValue(0), _scale(0), _precision(0)
{
	this->smallValue = smallValue;
	this->_scale = scale;
	this->_bitLength = bitLength(smallValue, ctx);
}
void BigDecimal::__construct_impl(long long smallValue, int scale, ThreadContext* ctx) throw() 
{
	this->smallValue = smallValue;
	this->_scale = scale;
	this->_bitLength = bitLength(smallValue, ctx);
}
 BigDecimal::BigDecimal(int smallValue, int scale, ThreadContext* ctx) throw()  : IObject(ctx), Number(ctx), Comparable<BigDecimal>(ctx), toStringImage(nullptr), _hashCode(0), intVal(nullptr), _bitLength(0), smallValue(0), _scale(0), _precision(0)
{
	this->smallValue = smallValue;
	this->_scale = scale;
	this->_bitLength = bitLength(smallValue, ctx);
}
void BigDecimal::__construct_impl(int smallValue, int scale, ThreadContext* ctx) throw() 
{
	this->smallValue = smallValue;
	this->_scale = scale;
	this->_bitLength = bitLength(smallValue, ctx);
}
 BigDecimal::BigDecimal(IArrayObjectPrimitive<wchar_t>* in, int offset, int len, ThreadContext* ctx) throw()  : IObject(ctx), Number(ctx), Comparable<BigDecimal>(ctx), toStringImage(nullptr), _hashCode(0), intVal(nullptr), _bitLength(0), smallValue(0), _scale(0), _precision(0)
{
	int begin = offset;
	int last = offset + (len - 1);
	String* scaleString = nullptr;
	StringBuilder* unscaledBuffer = 0;
	long long newScale = 0;
	if(in == (IArrayObjectPrimitive<wchar_t>*)nullptr)
	{
		throw (new(ctx) NullPointerException(ctx));
	}
	if((last >= in->length) || (offset < 0) || (len <= 0) || (last < 0))
	{
		throw (new(ctx) NumberFormatException(ctx));
	}
	unscaledBuffer = (new(ctx) StringBuilder(len, ctx));
	int bufLength = 0;
	if((offset <= last) && (in->get(offset) == L'+'))
	{
		offset ++ ;
		begin ++ ;
	}
	int counter = 0;
	bool wasNonZero = false;
	for(; (offset <= last) && (in->get(offset) != L'.') && (in->get(offset) != L'e') && (in->get(offset) != L'E'); offset ++ )
	{
		if(!wasNonZero)
		{
			if(in->get(offset) == L'0')
			{
				counter ++ ;
			}
						else 
			{
				wasNonZero = true;
			}
		}
	}
	unscaledBuffer->append(in, begin, offset - begin, ctx);
	bufLength += offset - begin;
	if((offset <= last) && (in->get(offset) == L'.'))
	{
		offset ++ ;
		begin = offset;
		for(; (offset <= last) && (in->get(offset) != L'e') && (in->get(offset) != L'E'); offset ++ )
		{
			if(!wasNonZero)
			{
				if(in->get(offset) == L'0')
				{
					counter ++ ;
				}
								else 
				{
					wasNonZero = true;
				}
			}
		}
		_scale = offset - begin;
		bufLength += _scale;
		unscaledBuffer->append(in, begin, _scale, ctx);
	}
		else 
	{
		_scale = 0;
	}
	if((offset <= last) && ((in->get(offset) == L'e') || (in->get(offset) == L'E')))
	{
		offset ++ ;
		begin = offset;
		if((offset <= last) && (in->get(offset) == L'+'))
		{
			offset ++ ;
			if((offset <= last) && (in->get(offset) != L'-'))
			{
				begin ++ ;
			}
		}
		scaleString = String::valueOf(in, begin, last + 1 - begin, ctx);
		newScale = ((long long)_scale) - Integer::parseInt(scaleString, ctx);
		_scale = ((int)newScale);
		if(newScale != (long long)_scale)
		{
			throw (new(ctx) NumberFormatException(ctx));
		}
	}
	if(bufLength < 19)
	{
		smallValue = Long::parseLong(unscaledBuffer->toString(ctx), ctx);
		_bitLength = bitLength(smallValue, ctx);
	}
		else 
	{
		setUnscaledValue((new(ctx) BigInteger(unscaledBuffer->toString(ctx), ctx)), ctx);
	}
	_precision = unscaledBuffer->length(ctx) - counter;
	if(unscaledBuffer->charAt(0, ctx) == L'-')
	{
		_precision -- ;
	}
}
void BigDecimal::__construct_impl(IArrayObjectPrimitive<wchar_t>* in, int offset, int len, ThreadContext* ctx) throw() 
{
	int begin = offset;
	int last = offset + (len - 1);
	String* scaleString = nullptr;
	StringBuilder* unscaledBuffer = 0;
	long long newScale = 0;
	if(in == (IArrayObjectPrimitive<wchar_t>*)nullptr)
	{
		throw (new(ctx) NullPointerException(ctx));
	}
	if((last >= in->length) || (offset < 0) || (len <= 0) || (last < 0))
	{
		throw (new(ctx) NumberFormatException(ctx));
	}
	unscaledBuffer = (new(ctx) StringBuilder(len, ctx));
	int bufLength = 0;
	if((offset <= last) && (in->get(offset) == L'+'))
	{
		offset ++ ;
		begin ++ ;
	}
	int counter = 0;
	bool wasNonZero = false;
	for(; (offset <= last) && (in->get(offset) != L'.') && (in->get(offset) != L'e') && (in->get(offset) != L'E'); offset ++ )
	{
		if(!wasNonZero)
		{
			if(in->get(offset) == L'0')
			{
				counter ++ ;
			}
						else 
			{
				wasNonZero = true;
			}
		}
	}
	unscaledBuffer->append(in, begin, offset - begin, ctx);
	bufLength += offset - begin;
	if((offset <= last) && (in->get(offset) == L'.'))
	{
		offset ++ ;
		begin = offset;
		for(; (offset <= last) && (in->get(offset) != L'e') && (in->get(offset) != L'E'); offset ++ )
		{
			if(!wasNonZero)
			{
				if(in->get(offset) == L'0')
				{
					counter ++ ;
				}
								else 
				{
					wasNonZero = true;
				}
			}
		}
		_scale = offset - begin;
		bufLength += _scale;
		unscaledBuffer->append(in, begin, _scale, ctx);
	}
		else 
	{
		_scale = 0;
	}
	if((offset <= last) && ((in->get(offset) == L'e') || (in->get(offset) == L'E')))
	{
		offset ++ ;
		begin = offset;
		if((offset <= last) && (in->get(offset) == L'+'))
		{
			offset ++ ;
			if((offset <= last) && (in->get(offset) != L'-'))
			{
				begin ++ ;
			}
		}
		scaleString = String::valueOf(in, begin, last + 1 - begin, ctx);
		newScale = ((long long)_scale) - Integer::parseInt(scaleString, ctx);
		_scale = ((int)newScale);
		if(newScale != (long long)_scale)
		{
			throw (new(ctx) NumberFormatException(ctx));
		}
	}
	if(bufLength < 19)
	{
		smallValue = Long::parseLong(unscaledBuffer->toString(ctx), ctx);
		_bitLength = bitLength(smallValue, ctx);
	}
		else 
	{
		setUnscaledValue((new(ctx) BigInteger(unscaledBuffer->toString(ctx), ctx)), ctx);
	}
	_precision = unscaledBuffer->length(ctx) - counter;
	if(unscaledBuffer->charAt(0, ctx) == L'-')
	{
		_precision -- ;
	}
}
 BigDecimal::BigDecimal(IArrayObjectPrimitive<wchar_t>* in, int offset, int len, MathContext* mc, ThreadContext* ctx) throw()  : IObject(ctx), Number(ctx), Comparable<BigDecimal>(ctx), toStringImage(nullptr), _hashCode(0), intVal(nullptr), _bitLength(0), smallValue(0), _scale(0), _precision(0)
{
	__construct_impl(in, offset, len, ctx);
	inplaceRound(mc, ctx);
}
void BigDecimal::__construct_impl(IArrayObjectPrimitive<wchar_t>* in, int offset, int len, MathContext* mc, ThreadContext* ctx) throw() 
{
	__construct_impl(in, offset, len, ctx);
	inplaceRound(mc, ctx);
}
 BigDecimal::BigDecimal(IArrayObjectPrimitive<wchar_t>* in, ThreadContext* ctx) throw()  : IObject(ctx), Number(ctx), Comparable<BigDecimal>(ctx), toStringImage(nullptr), _hashCode(0), intVal(nullptr), _bitLength(0), smallValue(0), _scale(0), _precision(0)
{
	__construct_impl(in, 0, in->length, ctx);
}
void BigDecimal::__construct_impl(IArrayObjectPrimitive<wchar_t>* in, ThreadContext* ctx) throw() 
{
	__construct_impl(in, 0, in->length, ctx);
}
 BigDecimal::BigDecimal(IArrayObjectPrimitive<wchar_t>* in, MathContext* mc, ThreadContext* ctx) throw()  : IObject(ctx), Number(ctx), Comparable<BigDecimal>(ctx), toStringImage(nullptr), _hashCode(0), intVal(nullptr), _bitLength(0), smallValue(0), _scale(0), _precision(0)
{
	__construct_impl(in, 0, in->length, ctx);
	inplaceRound(mc, ctx);
}
void BigDecimal::__construct_impl(IArrayObjectPrimitive<wchar_t>* in, MathContext* mc, ThreadContext* ctx) throw() 
{
	__construct_impl(in, 0, in->length, ctx);
	inplaceRound(mc, ctx);
}
 BigDecimal::BigDecimal(String* val, ThreadContext* ctx) throw()  : IObject(ctx), Number(ctx), Comparable<BigDecimal>(ctx), toStringImage(nullptr), _hashCode(0), intVal(nullptr), _bitLength(0), smallValue(0), _scale(0), _precision(0)
{
	__construct_impl(val->toCharArray(ctx), 0, val->length(ctx), ctx);
}
void BigDecimal::__construct_impl(String* val, ThreadContext* ctx) throw() 
{
	__construct_impl(val->toCharArray(ctx), 0, val->length(ctx), ctx);
}
 BigDecimal::BigDecimal(String* val, MathContext* mc, ThreadContext* ctx) throw()  : IObject(ctx), Number(ctx), Comparable<BigDecimal>(ctx), toStringImage(nullptr), _hashCode(0), intVal(nullptr), _bitLength(0), smallValue(0), _scale(0), _precision(0)
{
	__construct_impl(val->toCharArray(ctx), 0, val->length(ctx), ctx);
	inplaceRound(mc, ctx);
}
void BigDecimal::__construct_impl(String* val, MathContext* mc, ThreadContext* ctx) throw() 
{
	__construct_impl(val->toCharArray(ctx), 0, val->length(ctx), ctx);
	inplaceRound(mc, ctx);
}
 BigDecimal::BigDecimal(double val, ThreadContext* ctx) throw()  : IObject(ctx), Number(ctx), Comparable<BigDecimal>(ctx), toStringImage(nullptr), _hashCode(0), intVal(nullptr), _bitLength(0), smallValue(0), _scale(0), _precision(0)
{
	if(Double::isInfinite(val, ctx) || Double::isNaN(val, ctx))
	{
		throw (new(ctx) NumberFormatException(ConstStr::getCNST_STR_62(), ctx));
	}
	long long bits = Double::doubleToLongBits(val, ctx);
	long long mantisa = 0;
	int trailingZeros = 0;
	_scale = 1075 - ((int)((bits >> 52) & 0x7FFL));
	mantisa = (_scale == 1075) ? (bits & 0xFFFFFFFFFFFFFL) << 1 : (bits & 0xFFFFFFFFFFFFFL) | 0x10000000000000L;
	if(mantisa == (long long)0)
	{
		_scale = 0;
		_precision = 1;
	}
	if(_scale > 0)
	{
		trailingZeros = Math::min(_scale, Long::numberOfTrailingZeros(mantisa, ctx), ctx);
		mantisa = ((unsigned long long)mantisa) >> trailingZeros;
		_scale -= trailingZeros;
	}
	if((bits >> 63) != (long long)0)
	{
		mantisa = -mantisa;
	}
	int mantisaBits = bitLength(mantisa, ctx);
	if(_scale < 0)
	{
		_bitLength = mantisaBits == 0 ? 0 : mantisaBits - _scale;
		if(_bitLength < 64)
		{
			smallValue = mantisa << (-_scale);
		}
				else 
		{
			__GC_MV(this, &(intVal), BigInteger::valueOf(mantisa, ctx)->shiftLeft(-_scale, ctx), BigInteger);
		}
		_scale = 0;
	}
		else 
	{
		if(_scale > 0)
		{
			if(_scale < LONG_FIVE_POW->length && mantisaBits + LONG_FIVE_POW_BIT_LENGTH->get(_scale) < 64)
			{
				smallValue = mantisa * LONG_FIVE_POW->get(_scale);
				_bitLength = bitLength(smallValue, ctx);
			}
						else 
			{
				setUnscaledValue(Multiplication::multiplyByFivePow(BigInteger::valueOf(mantisa, ctx), _scale, ctx), ctx);
			}
		}
				else 
		{
			smallValue = mantisa;
			_bitLength = mantisaBits;
		}
	}
}
void BigDecimal::__construct_impl(double val, ThreadContext* ctx) throw() 
{
	if(Double::isInfinite(val, ctx) || Double::isNaN(val, ctx))
	{
		throw (new(ctx) NumberFormatException(ConstStr::getCNST_STR_62(), ctx));
	}
	long long bits = Double::doubleToLongBits(val, ctx);
	long long mantisa = 0;
	int trailingZeros = 0;
	_scale = 1075 - ((int)((bits >> 52) & 0x7FFL));
	mantisa = (_scale == 1075) ? (bits & 0xFFFFFFFFFFFFFL) << 1 : (bits & 0xFFFFFFFFFFFFFL) | 0x10000000000000L;
	if(mantisa == (long long)0)
	{
		_scale = 0;
		_precision = 1;
	}
	if(_scale > 0)
	{
		trailingZeros = Math::min(_scale, Long::numberOfTrailingZeros(mantisa, ctx), ctx);
		mantisa = ((unsigned long long)mantisa) >> trailingZeros;
		_scale -= trailingZeros;
	}
	if((bits >> 63) != (long long)0)
	{
		mantisa = -mantisa;
	}
	int mantisaBits = bitLength(mantisa, ctx);
	if(_scale < 0)
	{
		_bitLength = mantisaBits == 0 ? 0 : mantisaBits - _scale;
		if(_bitLength < 64)
		{
			smallValue = mantisa << (-_scale);
		}
				else 
		{
			__GC_MV(this, &(intVal), BigInteger::valueOf(mantisa, ctx)->shiftLeft(-_scale, ctx), BigInteger);
		}
		_scale = 0;
	}
		else 
	{
		if(_scale > 0)
		{
			if(_scale < LONG_FIVE_POW->length && mantisaBits + LONG_FIVE_POW_BIT_LENGTH->get(_scale) < 64)
			{
				smallValue = mantisa * LONG_FIVE_POW->get(_scale);
				_bitLength = bitLength(smallValue, ctx);
			}
						else 
			{
				setUnscaledValue(Multiplication::multiplyByFivePow(BigInteger::valueOf(mantisa, ctx), _scale, ctx), ctx);
			}
		}
				else 
		{
			smallValue = mantisa;
			_bitLength = mantisaBits;
		}
	}
}
 BigDecimal::BigDecimal(double val, MathContext* mc, ThreadContext* ctx) throw()  : IObject(ctx), Number(ctx), Comparable<BigDecimal>(ctx), toStringImage(nullptr), _hashCode(0), intVal(nullptr), _bitLength(0), smallValue(0), _scale(0), _precision(0)
{
	__construct_impl(val, ctx);
	inplaceRound(mc, ctx);
}
void BigDecimal::__construct_impl(double val, MathContext* mc, ThreadContext* ctx) throw() 
{
	__construct_impl(val, ctx);
	inplaceRound(mc, ctx);
}
 BigDecimal::BigDecimal(BigInteger* val, ThreadContext* ctx) throw()  : IObject(ctx), Number(ctx), Comparable<BigDecimal>(ctx), toStringImage(nullptr), _hashCode(0), intVal(nullptr), _bitLength(0), smallValue(0), _scale(0), _precision(0)
{
	__construct_impl(val, 0, ctx);
}
void BigDecimal::__construct_impl(BigInteger* val, ThreadContext* ctx) throw() 
{
	__construct_impl(val, 0, ctx);
}
 BigDecimal::BigDecimal(BigInteger* val, MathContext* mc, ThreadContext* ctx) throw()  : IObject(ctx), Number(ctx), Comparable<BigDecimal>(ctx), toStringImage(nullptr), _hashCode(0), intVal(nullptr), _bitLength(0), smallValue(0), _scale(0), _precision(0)
{
	__construct_impl(val, ctx);
	inplaceRound(mc, ctx);
}
void BigDecimal::__construct_impl(BigInteger* val, MathContext* mc, ThreadContext* ctx) throw() 
{
	__construct_impl(val, ctx);
	inplaceRound(mc, ctx);
}
 BigDecimal::BigDecimal(BigInteger* unscaledVal, int scale, ThreadContext* ctx) throw()  : IObject(ctx), Number(ctx), Comparable<BigDecimal>(ctx), toStringImage(nullptr), _hashCode(0), intVal(nullptr), _bitLength(0), smallValue(0), _scale(0), _precision(0)
{
	if(unscaledVal == nullptr)
	{
		throw (new(ctx) NullPointerException(ctx));
	}
	this->_scale = scale;
	setUnscaledValue(unscaledVal, ctx);
}
void BigDecimal::__construct_impl(BigInteger* unscaledVal, int scale, ThreadContext* ctx) throw() 
{
	if(unscaledVal == nullptr)
	{
		throw (new(ctx) NullPointerException(ctx));
	}
	this->_scale = scale;
	setUnscaledValue(unscaledVal, ctx);
}
 BigDecimal::BigDecimal(BigInteger* unscaledVal, int scale, MathContext* mc, ThreadContext* ctx) throw()  : IObject(ctx), Number(ctx), Comparable<BigDecimal>(ctx), toStringImage(nullptr), _hashCode(0), intVal(nullptr), _bitLength(0), smallValue(0), _scale(0), _precision(0)
{
	__construct_impl(unscaledVal, scale, ctx);
	inplaceRound(mc, ctx);
}
void BigDecimal::__construct_impl(BigInteger* unscaledVal, int scale, MathContext* mc, ThreadContext* ctx) throw() 
{
	__construct_impl(unscaledVal, scale, ctx);
	inplaceRound(mc, ctx);
}
 BigDecimal::BigDecimal(int val, ThreadContext* ctx) throw()  : IObject(ctx), Number(ctx), Comparable<BigDecimal>(ctx), toStringImage(nullptr), _hashCode(0), intVal(nullptr), _bitLength(0), smallValue(0), _scale(0), _precision(0)
{
	__construct_impl(val, 0, ctx);
}
void BigDecimal::__construct_impl(int val, ThreadContext* ctx) throw() 
{
	__construct_impl(val, 0, ctx);
}
 BigDecimal::BigDecimal(int val, MathContext* mc, ThreadContext* ctx) throw()  : IObject(ctx), Number(ctx), Comparable<BigDecimal>(ctx), toStringImage(nullptr), _hashCode(0), intVal(nullptr), _bitLength(0), smallValue(0), _scale(0), _precision(0)
{
	__construct_impl(val, 0, ctx);
	inplaceRound(mc, ctx);
}
void BigDecimal::__construct_impl(int val, MathContext* mc, ThreadContext* ctx) throw() 
{
	__construct_impl(val, 0, ctx);
	inplaceRound(mc, ctx);
}
 BigDecimal::BigDecimal(long long val, ThreadContext* ctx) throw()  : IObject(ctx), Number(ctx), Comparable<BigDecimal>(ctx), toStringImage(nullptr), _hashCode(0), intVal(nullptr), _bitLength(0), smallValue(0), _scale(0), _precision(0)
{
	__construct_impl(val, 0, ctx);
}
void BigDecimal::__construct_impl(long long val, ThreadContext* ctx) throw() 
{
	__construct_impl(val, 0, ctx);
}
 BigDecimal::BigDecimal(long long val, MathContext* mc, ThreadContext* ctx) throw()  : IObject(ctx), Number(ctx), Comparable<BigDecimal>(ctx), toStringImage(nullptr), _hashCode(0), intVal(nullptr), _bitLength(0), smallValue(0), _scale(0), _precision(0)
{
	__construct_impl(val, ctx);
	inplaceRound(mc, ctx);
}
void BigDecimal::__construct_impl(long long val, MathContext* mc, ThreadContext* ctx) throw() 
{
	__construct_impl(val, ctx);
	inplaceRound(mc, ctx);
}
 BigDecimal::~BigDecimal() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void BigDecimal::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"BigDecimal", L"~BigDecimal");
	__e_obj1.add(this->toStringImage, this);
	toStringImage = nullptr;
	__e_obj1.add(this->intVal, this);
	intVal = nullptr;
	if(!prepare){
		return;
	}
	Number::__releaseRegerences(true, ctx);
}
BigDecimal* BigDecimal::add(BigDecimal* augend, ThreadContext* ctx) throw() 
{
	int diffScale = this->_scale - augend->_scale;
	if(this->isZero(ctx))
	{
		if(diffScale <= 0)
		{
			return augend;
		}
		if(augend->isZero(ctx))
		{
			return this;
		}
	}
		else 
	{
		if(augend->isZero(ctx))
		{
			if(diffScale >= 0)
			{
				return this;
			}
		}
	}
	if(diffScale == 0)
	{
		if(Math::max(this->_bitLength, augend->_bitLength, ctx) + 1 < 64)
		{
			return valueOf(this->smallValue + augend->smallValue, this->_scale, ctx);
		}
		return (new(ctx) BigDecimal(this->getUnscaledValue(ctx)->add(augend->getUnscaledValue(ctx), ctx), this->_scale, ctx));
	}
		else 
	{
		if(diffScale > 0)
		{
			return addAndMult10(this, augend, diffScale, ctx);
		}
				else 
		{
			return addAndMult10(augend, this, -diffScale, ctx);
		}
	}
}
BigDecimal* BigDecimal::add(BigDecimal* augend, MathContext* mc, ThreadContext* ctx) throw() 
{
	BigDecimal* larger = 0;
	BigDecimal* smaller = 0;
	BigInteger* tempBI = 0;
	long long diffScale = ((long long)this->_scale) - augend->_scale;
	int largerSignum = 0;
	if((augend->isZero(ctx)) || (this->isZero(ctx)) || (mc->getPrecision(ctx) == 0))
	{
		return add(augend, ctx)->round(mc, ctx);
	}
	if(this->aproxPrecision(ctx) < (int)diffScale - 1)
	{
		larger = augend;
		smaller = this;
	}
		else 
	{
		if(augend->aproxPrecision(ctx) < (int)-diffScale - 1)
		{
			larger = this;
			smaller = augend;
		}
				else 
		{
			return add(augend, ctx)->round(mc, ctx);
		}
	}
	if(mc->getPrecision(ctx) >= larger->aproxPrecision(ctx))
	{
		return add(augend, ctx)->round(mc, ctx);
	}
	largerSignum = larger->signum(ctx);
	if(largerSignum == smaller->signum(ctx))
	{
		tempBI = Multiplication::multiplyByPositiveInt(larger->getUnscaledValue(ctx), 10, ctx)->add(BigInteger::valueOf((long long)largerSignum, ctx), ctx);
	}
		else 
	{
		tempBI = larger->getUnscaledValue(ctx)->subtract(BigInteger::valueOf((long long)largerSignum, ctx), ctx);
		tempBI = Multiplication::multiplyByPositiveInt(tempBI, 10, ctx)->add(BigInteger::valueOf((long long)largerSignum * 9, ctx), ctx);
	}
	larger = (new(ctx) BigDecimal(tempBI, larger->_scale + 1, ctx));
	return larger->round(mc, ctx);
}
BigDecimal* BigDecimal::subtract(BigDecimal* subtrahend, ThreadContext* ctx) throw() 
{
	int diffScale = this->_scale - subtrahend->_scale;
	if(this->isZero(ctx))
	{
		if(diffScale <= 0)
		{
			return subtrahend->negate(ctx);
		}
		if(subtrahend->isZero(ctx))
		{
			return this;
		}
	}
		else 
	{
		if(subtrahend->isZero(ctx))
		{
			if(diffScale >= 0)
			{
				return this;
			}
		}
	}
	if(diffScale == 0)
	{
		if(Math::max(this->_bitLength, subtrahend->_bitLength, ctx) + 1 < 64)
		{
			return valueOf(this->smallValue - subtrahend->smallValue, this->_scale, ctx);
		}
		return (new(ctx) BigDecimal(this->getUnscaledValue(ctx)->subtract(subtrahend->getUnscaledValue(ctx), ctx), this->_scale, ctx));
	}
		else 
	{
		if(diffScale > 0)
		{
			if(diffScale < LONG_TEN_POW->length && Math::max(this->_bitLength, subtrahend->_bitLength + LONG_TEN_POW_BIT_LENGTH->get(diffScale), ctx) + 1 < 64)
			{
				return valueOf(this->smallValue - subtrahend->smallValue * LONG_TEN_POW->get(diffScale), this->_scale, ctx);
			}
			return (new(ctx) BigDecimal(this->getUnscaledValue(ctx)->subtract(Multiplication::multiplyByTenPow(subtrahend->getUnscaledValue(ctx), (long long)diffScale, ctx), ctx), this->_scale, ctx));
		}
				else 
		{
			diffScale = -diffScale;
			if(diffScale < LONG_TEN_POW->length && Math::max(this->_bitLength + LONG_TEN_POW_BIT_LENGTH->get(diffScale), subtrahend->_bitLength, ctx) + 1 < 64)
			{
				return valueOf(this->smallValue * LONG_TEN_POW->get(diffScale) - subtrahend->smallValue, subtrahend->_scale, ctx);
			}
			return (new(ctx) BigDecimal(Multiplication::multiplyByTenPow(this->getUnscaledValue(ctx), (long long)diffScale, ctx)->subtract(subtrahend->getUnscaledValue(ctx), ctx), subtrahend->_scale, ctx));
		}
	}
}
BigDecimal* BigDecimal::subtract(BigDecimal* subtrahend, MathContext* mc, ThreadContext* ctx) throw() 
{
	long long diffScale = subtrahend->_scale - ((long long)this->_scale);
	int thisSignum = 0;
	BigDecimal* leftOperand = 0;
	BigInteger* tempBI = 0;
	if((subtrahend->isZero(ctx)) || (this->isZero(ctx)) || (mc->getPrecision(ctx) == 0))
	{
		return subtract(subtrahend, ctx)->round(mc, ctx);
	}
	if(subtrahend->aproxPrecision(ctx) < (int)diffScale - 1)
	{
		if(mc->getPrecision(ctx) < this->aproxPrecision(ctx))
		{
			thisSignum = this->signum(ctx);
			if(thisSignum != subtrahend->signum(ctx))
			{
				tempBI = Multiplication::multiplyByPositiveInt(this->getUnscaledValue(ctx), 10, ctx)->add(BigInteger::valueOf((long long)thisSignum, ctx), ctx);
			}
						else 
			{
				tempBI = this->getUnscaledValue(ctx)->subtract(BigInteger::valueOf((long long)thisSignum, ctx), ctx);
				tempBI = Multiplication::multiplyByPositiveInt(tempBI, 10, ctx)->add(BigInteger::valueOf((long long)thisSignum * 9, ctx), ctx);
			}
			leftOperand = (new(ctx) BigDecimal(tempBI, this->_scale + 1, ctx));
			return leftOperand->round(mc, ctx);
		}
	}
	return subtract(subtrahend, ctx)->round(mc, ctx);
}
BigDecimal* BigDecimal::multiply(BigDecimal* multiplicand, ThreadContext* ctx) throw() 
{
	long long newScale = ((long long)this->_scale) + multiplicand->_scale;
	if((this->isZero(ctx)) || (multiplicand->isZero(ctx)))
	{
		return zeroScaledBy(newScale, ctx);
	}
	if(this->_bitLength + multiplicand->_bitLength < 64)
	{
		return valueOf(this->smallValue * multiplicand->smallValue, toIntScale(newScale, ctx), ctx);
	}
	return (new(ctx) BigDecimal(this->getUnscaledValue(ctx)->multiply(multiplicand->getUnscaledValue(ctx), ctx), toIntScale(newScale, ctx), ctx));
}
BigDecimal* BigDecimal::multiply(BigDecimal* multiplicand, MathContext* mc, ThreadContext* ctx) throw() 
{
	BigDecimal* result = multiply(multiplicand, ctx);
	result->inplaceRound(mc, ctx);
	return result;
}
BigDecimal* BigDecimal::divide(BigDecimal* divisor, int scale, int roundingMode, ThreadContext* ctx) throw() 
{
	return divide(divisor, scale, RoundingMode::valueOf(roundingMode, ctx), ctx);
}
BigDecimal* BigDecimal::divide(BigDecimal* divisor, int scale, RoundingMode* roundingMode, ThreadContext* ctx) throw() 
{
	if(roundingMode == nullptr)
	{
		throw (new(ctx) NullPointerException(ctx));
	}
	if(divisor->isZero(ctx))
	{
		throw (new(ctx) ArithmeticException(ConstStr::getCNST_STR_63(), ctx));
	}
	long long diffScale = (((long long)this->_scale) - divisor->_scale) - scale;
	if(this->_bitLength < 64 && divisor->_bitLength < 64)
	{
		if(diffScale == (long long)0)
		{
			return dividePrimitiveLongs(this->smallValue, divisor->smallValue, scale, roundingMode, ctx);
		}
				else 
		{
			if(diffScale > (long long)0)
			{
				if(diffScale < (long long)LONG_TEN_POW->length && divisor->_bitLength + LONG_TEN_POW_BIT_LENGTH->get(((int)diffScale)) < 64)
				{
					return dividePrimitiveLongs(this->smallValue, divisor->smallValue * LONG_TEN_POW->get(((int)diffScale)), scale, roundingMode, ctx);
				}
			}
						else 
			{
				if(-diffScale < (long long)LONG_TEN_POW->length && this->_bitLength + LONG_TEN_POW_BIT_LENGTH->get(((int)-diffScale)) < 64)
				{
					return dividePrimitiveLongs(this->smallValue * LONG_TEN_POW->get(((int)-diffScale)), divisor->smallValue, scale, roundingMode, ctx);
				}
			}
		}
	}
	BigInteger* scaledDividend = this->getUnscaledValue(ctx);
	BigInteger* scaledDivisor = divisor->getUnscaledValue(ctx);
	if(diffScale > (long long)0)
	{
		scaledDivisor = Multiplication::multiplyByTenPow(scaledDivisor, (long long)((int)diffScale), ctx);
	}
		else 
	{
		if(diffScale < (long long)0)
		{
			scaledDividend = Multiplication::multiplyByTenPow(scaledDividend, (long long)((int)-diffScale), ctx);
		}
	}
	return divideBigIntegers(scaledDividend, scaledDivisor, scale, roundingMode, ctx);
}
BigDecimal* BigDecimal::divide(BigDecimal* divisor, int roundingMode, ThreadContext* ctx) throw() 
{
	return divide(divisor, _scale, RoundingMode::valueOf(roundingMode, ctx), ctx);
}
BigDecimal* BigDecimal::divide(BigDecimal* divisor, RoundingMode* roundingMode, ThreadContext* ctx) throw() 
{
	return divide(divisor, _scale, roundingMode, ctx);
}
BigDecimal* BigDecimal::divide(BigDecimal* divisor, ThreadContext* ctx) throw() 
{
	BigInteger* p = this->getUnscaledValue(ctx);
	BigInteger* q = divisor->getUnscaledValue(ctx);
	BigInteger* gcd = 0;
	IArrayObject<BigInteger>* quotAndRem = 0;
	long long diffScale = ((long long)_scale) - divisor->_scale;
	int newScale = 0;
	int k = 0;
	int l = 0;
	int i = 1;
	int lastPow = FIVE_POW->length - 1;
	if(divisor->isZero(ctx))
	{
		throw (new(ctx) ArithmeticException(ConstStr::getCNST_STR_63(), ctx));
	}
	if(p->signum(ctx) == 0)
	{
		return zeroScaledBy(diffScale, ctx);
	}
	gcd = p->gcd(q, ctx);
	p = p->divide(gcd, ctx);
	q = q->divide(gcd, ctx);
	k = q->getLowestSetBit(ctx);
	q = q->shiftRight(k, ctx);
	do
	{
		quotAndRem = q->divideAndRemainder(FIVE_POW->get(i), ctx);
		if(quotAndRem->get(1)->signum(ctx) == 0)
		{
			l += i;
			if(i < lastPow)
			{
				i ++ ;
			}
			q = quotAndRem->get(0);
		}
				else 
		{
			if(i == 1)
			{
				break ;
			}
			i = 1;
		}
	}
	while(true);
	if(!q->abs(ctx)->equals(BigInteger::ONE, ctx))
	{
		throw (new(ctx) ArithmeticException(ConstStr::getCNST_STR_64(), ctx));
	}
	if(q->signum(ctx) < 0)
	{
		p = p->negate(ctx);
	}
	newScale = toIntScale(diffScale + Math::max(k, l, ctx), ctx);
	i = k - l;
	p = (i > 0) ? Multiplication::multiplyByFivePow(p, i, ctx) : p->shiftLeft(-i, ctx);
	return (new(ctx) BigDecimal(p, newScale, ctx));
}
BigDecimal* BigDecimal::divide(BigDecimal* divisor, MathContext* mc, ThreadContext* ctx) throw() 
{
	long long traillingZeros = mc->getPrecision(ctx) + 2L + divisor->aproxPrecision(ctx) - aproxPrecision(ctx);
	long long diffScale = ((long long)_scale) - divisor->_scale;
	long long newScale = diffScale;
	int compRem = 0;
	int i = 1;
	int lastPow = TEN_POW->length - 1;
	BigInteger* integerQuot = 0;
	IArrayObject<BigInteger>* quotAndRem = (IArrayObject<BigInteger>*)new ArrayObject<BigInteger>({getUnscaledValue(ctx)}, ctx);
	if((mc->getPrecision(ctx) == 0) || (this->isZero(ctx)) || (divisor->isZero(ctx)))
	{
		return this->divide(divisor, ctx);
	}
	if(traillingZeros > (long long)0)
	{
		quotAndRem->set(getUnscaledValue(ctx)->multiply(Multiplication::powerOf10(traillingZeros, ctx), ctx),0, ctx);
		newScale += traillingZeros;
	}
	quotAndRem = quotAndRem->get(0)->divideAndRemainder(divisor->getUnscaledValue(ctx), ctx);
	integerQuot = quotAndRem->get(0);
	if(quotAndRem->get(1)->signum(ctx) != 0)
	{
		compRem = quotAndRem->get(1)->shiftLeftOneBit(ctx)->compareTo(divisor->getUnscaledValue(ctx), ctx);
		integerQuot = integerQuot->multiply(BigInteger::TEN, ctx)->add(BigInteger::valueOf((long long)quotAndRem->get(0)->signum(ctx) * (5 + compRem), ctx), ctx);
		newScale ++ ;
	}
		else 
	{
		while(!integerQuot->testBit(0, ctx))
		{
			quotAndRem = integerQuot->divideAndRemainder(TEN_POW->get(i), ctx);
			if((quotAndRem->get(1)->signum(ctx) == 0) && (newScale - i >= diffScale))
			{
				newScale -= i;
				if(i < lastPow)
				{
					i ++ ;
				}
				integerQuot = quotAndRem->get(0);
			}
						else 
			{
				if(i == 1)
				{
					break ;
				}
				i = 1;
			}
		}
	}
	return (new(ctx) BigDecimal(integerQuot, toIntScale(newScale, ctx), mc, ctx));
}
BigDecimal* BigDecimal::divideToIntegralValue(BigDecimal* divisor, ThreadContext* ctx) throw() 
{
	BigInteger* integralValue = 0;
	BigInteger* powerOfTen = 0;
	IArrayObject<BigInteger>* quotAndRem = (IArrayObject<BigInteger>*)new ArrayObject<BigInteger>({getUnscaledValue(ctx)}, ctx);
	long long newScale = ((long long)this->_scale) - divisor->_scale;
	long long tempScale = 0;
	int i = 1;
	int lastPow = TEN_POW->length - 1;
	if(divisor->isZero(ctx))
	{
		throw (new(ctx) ArithmeticException(ConstStr::getCNST_STR_63(), ctx));
	}
	if((divisor->aproxPrecision(ctx) + newScale > this->aproxPrecision(ctx) + 1L) || (this->isZero(ctx)))
	{
		integralValue = BigInteger::ZERO;
	}
		else 
	{
		if(newScale == (long long)0)
		{
			integralValue = getUnscaledValue(ctx)->divide(divisor->getUnscaledValue(ctx), ctx);
		}
				else 
		{
			if(newScale > (long long)0)
			{
				powerOfTen = Multiplication::powerOf10(newScale, ctx);
				integralValue = getUnscaledValue(ctx)->divide(divisor->getUnscaledValue(ctx)->multiply(powerOfTen, ctx), ctx);
				integralValue = integralValue->multiply(powerOfTen, ctx);
			}
						else 
			{
				powerOfTen = Multiplication::powerOf10(-newScale, ctx);
				integralValue = getUnscaledValue(ctx)->multiply(powerOfTen, ctx)->divide(divisor->getUnscaledValue(ctx), ctx);
				while(!integralValue->testBit(0, ctx))
				{
					quotAndRem = integralValue->divideAndRemainder(TEN_POW->get(i), ctx);
					if((quotAndRem->get(1)->signum(ctx) == 0) && (tempScale - i >= newScale))
					{
						tempScale -= i;
						if(i < lastPow)
						{
							i ++ ;
						}
						integralValue = quotAndRem->get(0);
					}
										else 
					{
						if(i == 1)
						{
							break ;
						}
						i = 1;
					}
				}
				newScale = tempScale;
			}
		}
	}
	return ((integralValue->signum(ctx) == 0) ? zeroScaledBy(newScale, ctx) : (new(ctx) BigDecimal(integralValue, toIntScale(newScale, ctx), ctx)));
}
BigDecimal* BigDecimal::divideToIntegralValue(BigDecimal* divisor, MathContext* mc, ThreadContext* ctx) throw() 
{
	int mcPrecision = mc->getPrecision(ctx);
	int diffPrecision = this->precision(ctx) - divisor->precision(ctx);
	int lastPow = TEN_POW->length - 1;
	long long diffScale = ((long long)this->_scale) - divisor->_scale;
	long long newScale = diffScale;
	long long quotPrecision = diffPrecision - diffScale + 1;
	IArrayObject<BigInteger>* quotAndRem = ArrayAllocator<BigInteger>::allocate(ctx, 2);
	if((mcPrecision == 0) || (this->isZero(ctx)) || (divisor->isZero(ctx)))
	{
		return this->divideToIntegralValue(divisor, ctx);
	}
	if(quotPrecision <= (long long)0)
	{
		quotAndRem->set(BigInteger::ZERO,0, ctx);
	}
		else 
	{
		if(diffScale == (long long)0)
		{
			quotAndRem->set(this->getUnscaledValue(ctx)->divide(divisor->getUnscaledValue(ctx), ctx),0, ctx);
		}
				else 
		{
			if(diffScale > (long long)0)
			{
				quotAndRem->set(this->getUnscaledValue(ctx)->divide(divisor->getUnscaledValue(ctx)->multiply(Multiplication::powerOf10(diffScale, ctx), ctx), ctx),0, ctx);
				newScale = Math::min(diffScale, (long long)Math::max(mcPrecision - quotPrecision + 1, 0, ctx), ctx);
				quotAndRem->set(quotAndRem->get(0)->multiply(Multiplication::powerOf10(newScale, ctx), ctx),0, ctx);
			}
						else 
			{
				long long exp = Math::min(-diffScale, Math::max(((long long)mcPrecision) - diffPrecision, (long long)0, ctx), ctx);
				long long compRemDiv = 0;
				quotAndRem = this->getUnscaledValue(ctx)->multiply(Multiplication::powerOf10(exp, ctx), ctx)->divideAndRemainder(divisor->getUnscaledValue(ctx), ctx);
				newScale += exp;
				exp = -newScale;
				if((quotAndRem->get(1)->signum(ctx) != 0) && (exp > (long long)0))
				{
					compRemDiv = ((new(ctx) BigDecimal(quotAndRem->get(1), ctx)))->precision(ctx) + exp - divisor->precision(ctx);
					if(compRemDiv == (long long)0)
					{
						quotAndRem->set(quotAndRem->get(1)->multiply(Multiplication::powerOf10(exp, ctx), ctx)->divide(divisor->getUnscaledValue(ctx), ctx),1, ctx);
						compRemDiv = Math::abs(quotAndRem->get(1)->signum(ctx), ctx);
					}
					if(compRemDiv > (long long)0)
					{
						throw (new(ctx) ArithmeticException(ConstStr::getCNST_STR_65(), ctx));
					}
				}
			}
		}
	}
	if(quotAndRem->get(0)->signum(ctx) == 0)
	{
		return zeroScaledBy(diffScale, ctx);
	}
	BigInteger* strippedBI = quotAndRem->get(0);
	BigDecimal* integralValue = (new(ctx) BigDecimal(quotAndRem->get(0), ctx));
	long long resultPrecision = integralValue->precision(ctx);
	int i = 1;
	while(!strippedBI->testBit(0, ctx))
	{
		quotAndRem = strippedBI->divideAndRemainder(TEN_POW->get(i), ctx);
		if((quotAndRem->get(1)->signum(ctx) == 0) && ((resultPrecision - i >= (long long)mcPrecision) || (newScale - i >= diffScale)))
		{
			resultPrecision -= i;
			newScale -= i;
			if(i < lastPow)
			{
				i ++ ;
			}
			strippedBI = quotAndRem->get(0);
		}
				else 
		{
			if(i == 1)
			{
				break ;
			}
			i = 1;
		}
	}
	if(resultPrecision > (long long)mcPrecision)
	{
		throw (new(ctx) ArithmeticException(ConstStr::getCNST_STR_65(), ctx));
	}
	integralValue->_scale = toIntScale(newScale, ctx);
	integralValue->setUnscaledValue(strippedBI, ctx);
	return integralValue;
}
BigDecimal* BigDecimal::remainder(BigDecimal* divisor, ThreadContext* ctx) throw() 
{
	IArrayObject<BigDecimal>* decimals = divideAndRemainder(divisor, ctx);
	return decimals->get(1);
}
BigDecimal* BigDecimal::remainder(BigDecimal* divisor, MathContext* mc, ThreadContext* ctx) throw() 
{
	IArrayObject<BigDecimal>* decimals = divideAndRemainder(divisor, mc, ctx);
	return decimals->get(1);
}
IArrayObject<BigDecimal>* BigDecimal::divideAndRemainder(BigDecimal* divisor, ThreadContext* ctx) throw() 
{
	IArrayObject<BigDecimal>* quotAndRem = ArrayAllocator<BigDecimal>::allocate(ctx, 2);
	quotAndRem->set(this->divideToIntegralValue(divisor, ctx),0, ctx);
	quotAndRem->set(this->subtract(quotAndRem->get(0)->multiply(divisor, ctx), ctx),1, ctx);
	return quotAndRem;
}
IArrayObject<BigDecimal>* BigDecimal::divideAndRemainder(BigDecimal* divisor, MathContext* mc, ThreadContext* ctx) throw() 
{
	IArrayObject<BigDecimal>* quotAndRem = ArrayAllocator<BigDecimal>::allocate(ctx, 2);
	quotAndRem->set(this->divideToIntegralValue(divisor, mc, ctx),0, ctx);
	quotAndRem->set(this->subtract(quotAndRem->get(0)->multiply(divisor, ctx), ctx),1, ctx);
	return quotAndRem;
}
BigDecimal* BigDecimal::pow(int n, ThreadContext* ctx) throw() 
{
	if(n == 0)
	{
		return ONE;
	}
	if((n < 0) || (n > 999999999))
	{
		throw (new(ctx) ArithmeticException(ConstStr::getCNST_STR_66(), ctx));
	}
	long long newScale = _scale * ((long long)n);
	return ((isZero(ctx)) ? zeroScaledBy(newScale, ctx) : (new(ctx) BigDecimal(getUnscaledValue(ctx)->pow(n, ctx), toIntScale(newScale, ctx), ctx)));
}
BigDecimal* BigDecimal::pow(int n, MathContext* mc, ThreadContext* ctx) throw() 
{
	int m = Math::abs(n, ctx);
	int mcPrecision = mc->getPrecision(ctx);
	int elength = ((int)Math::log10((double)m, ctx)) + 1;
	int oneBitMask = 0;
	BigDecimal* accum = 0;
	MathContext* newPrecision = mc;
	if((n == 0) || ((isZero(ctx)) && (n > 0)))
	{
		return pow(n, ctx);
	}
	if((m > 999999999) || ((mcPrecision == 0) && (n < 0)) || ((mcPrecision > 0) && (elength > mcPrecision)))
	{
		throw (new(ctx) ArithmeticException(ConstStr::getCNST_STR_66(), ctx));
	}
	if(mcPrecision > 0)
	{
		newPrecision = (new(ctx) MathContext(mcPrecision + elength + 1, mc->getRoundingMode(ctx), ctx));
	}
	accum = round(newPrecision, ctx);
	oneBitMask = Integer::highestOneBit(m, ctx) >> 1;
	while(oneBitMask > 0)
	{
		accum = accum->multiply(accum, newPrecision, ctx);
		if((m & oneBitMask) == oneBitMask)
		{
			accum = accum->multiply(this, newPrecision, ctx);
		}
		oneBitMask >>= 1;
	}
	if(n < 0)
	{
		accum = ONE->divide(accum, newPrecision, ctx);
	}
	accum->inplaceRound(mc, ctx);
	return accum;
}
BigDecimal* BigDecimal::abs(ThreadContext* ctx) throw() 
{
	return ((signum(ctx) < 0) ? negate(ctx) : this);
}
BigDecimal* BigDecimal::abs(MathContext* mc, ThreadContext* ctx) throw() 
{
	return round(mc, ctx)->abs(ctx);
}
BigDecimal* BigDecimal::negate(ThreadContext* ctx) throw() 
{
	if(_bitLength < 63 || (_bitLength == 63 && smallValue != Long::MIN_VALUE))
	{
		return valueOf(-smallValue, _scale, ctx);
	}
	return (new(ctx) BigDecimal(getUnscaledValue(ctx)->negate(ctx), _scale, ctx));
}
BigDecimal* BigDecimal::negate(MathContext* mc, ThreadContext* ctx) throw() 
{
	return round(mc, ctx)->negate(ctx);
}
BigDecimal* BigDecimal::plus(ThreadContext* ctx) throw() 
{
	return this;
}
BigDecimal* BigDecimal::plus(MathContext* mc, ThreadContext* ctx) throw() 
{
	return round(mc, ctx);
}
int BigDecimal::signum(ThreadContext* ctx) throw() 
{
	if(_bitLength < 64)
	{
		return Long::signum(this->smallValue, ctx);
	}
	return getUnscaledValue(ctx)->signum(ctx);
}
int BigDecimal::scale(ThreadContext* ctx) throw() 
{
	return _scale;
}
int BigDecimal::precision(ThreadContext* ctx) throw() 
{
	if(_precision > 0)
	{
		return _precision;
	}
	int bitLength = this->_bitLength;
	int decimalDigits = 1;
	double doubleUnsc = 1;
	if(bitLength < 1024)
	{
		if(bitLength >= 64)
		{
			doubleUnsc = getUnscaledValue(ctx)->doubleValue(ctx);
		}
				else 
		{
			if(bitLength >= 1)
			{
				doubleUnsc = smallValue;
			}
		}
		decimalDigits += Math::log10(Math::abs(doubleUnsc, ctx), ctx);
	}
		else 
	{
		decimalDigits += (bitLength - 1) * LOG10_2;
		if(getUnscaledValue(ctx)->divide(Multiplication::powerOf10((long long)decimalDigits, ctx), ctx)->signum(ctx) != 0)
		{
			decimalDigits ++ ;
		}
	}
	_precision = decimalDigits;
	return _precision;
}
BigInteger* BigDecimal::unscaledValue(ThreadContext* ctx) throw() 
{
	return getUnscaledValue(ctx);
}
BigDecimal* BigDecimal::round(MathContext* mc, ThreadContext* ctx) throw() 
{
	BigDecimal* thisBD = (new(ctx) BigDecimal(getUnscaledValue(ctx), _scale, ctx));
	thisBD->inplaceRound(mc, ctx);
	return thisBD;
}
BigDecimal* BigDecimal::setScale(int newScale, RoundingMode* roundingMode, ThreadContext* ctx) throw() 
{
	if(roundingMode == nullptr)
	{
		throw (new(ctx) NullPointerException(ctx));
	}
	long long diffScale = newScale - ((long long)_scale);
	if(diffScale == (long long)0)
	{
		return this;
	}
	if(diffScale > (long long)0)
	{
		if(diffScale < (long long)LONG_TEN_POW->length && (this->_bitLength + LONG_TEN_POW_BIT_LENGTH->get(((int)diffScale))) < 64)
		{
			return valueOf(this->smallValue * LONG_TEN_POW->get(((int)diffScale)), newScale, ctx);
		}
		return (new(ctx) BigDecimal(Multiplication::multiplyByTenPow(getUnscaledValue(ctx), (long long)((int)diffScale), ctx), newScale, ctx));
	}
	if(this->_bitLength < 64 && -diffScale < (long long)LONG_TEN_POW->length)
	{
		return dividePrimitiveLongs(this->smallValue, LONG_TEN_POW->get(((int)-diffScale)), newScale, roundingMode, ctx);
	}
	return divideBigIntegers(this->getUnscaledValue(ctx), Multiplication::powerOf10(-diffScale, ctx), newScale, roundingMode, ctx);
}
BigDecimal* BigDecimal::setScale(int newScale, int roundingMode, ThreadContext* ctx) throw() 
{
	return setScale(newScale, RoundingMode::valueOf(roundingMode, ctx), ctx);
}
BigDecimal* BigDecimal::setScale(int newScale, ThreadContext* ctx) throw() 
{
	return setScale(newScale, RoundingMode::UNNECESSARY, ctx);
}
BigDecimal* BigDecimal::movePointLeft(int n, ThreadContext* ctx) throw() 
{
	return movePoint((long long)_scale + ((long long)n), ctx);
}
BigDecimal* BigDecimal::movePointRight(int n, ThreadContext* ctx) throw() 
{
	return movePoint((long long)_scale - ((long long)n), ctx);
}
BigDecimal* BigDecimal::scaleByPowerOfTen(int n, ThreadContext* ctx) throw() 
{
	long long newScale = _scale - ((long long)n);
	if(_bitLength < 64)
	{
		if(smallValue == (long long)0)
		{
			return zeroScaledBy(newScale, ctx);
		}
		return valueOf(smallValue, toIntScale(newScale, ctx), ctx);
	}
	return (new(ctx) BigDecimal(getUnscaledValue(ctx), toIntScale(newScale, ctx), ctx));
}
BigDecimal* BigDecimal::stripTrailingZeros(ThreadContext* ctx) throw() 
{
	int i = 1;
	int lastPow = TEN_POW->length - 1;
	long long newScale = _scale;
	if(isZero(ctx))
	{
		return (new(ctx) BigDecimal(ConstStr::getCNST_STR_9(), ctx));
	}
	BigInteger* strippedBI = getUnscaledValue(ctx);
	IArrayObject<BigInteger>* quotAndRem = 0;
	while(!strippedBI->testBit(0, ctx))
	{
		quotAndRem = strippedBI->divideAndRemainder(TEN_POW->get(i), ctx);
		if(quotAndRem->get(1)->signum(ctx) == 0)
		{
			newScale -= i;
			if(i < lastPow)
			{
				i ++ ;
			}
			strippedBI = quotAndRem->get(0);
		}
				else 
		{
			if(i == 1)
			{
				break ;
			}
			i = 1;
		}
	}
	return (new(ctx) BigDecimal(strippedBI, toIntScale(newScale, ctx), ctx));
}
int BigDecimal::compareTo(BigDecimal* val, ThreadContext* ctx) throw() 
{
	int thisSign = signum(ctx);
	int valueSign = val->signum(ctx);
	if(thisSign == valueSign)
	{
		if(this->_scale == val->_scale && this->_bitLength < 64 && val->_bitLength < 64)
		{
			return (smallValue < val->smallValue) ? -1 : (smallValue > val->smallValue) ? 1 : 0;
		}
		long long diffScale = ((long long)this->_scale) - val->_scale;
		int diffPrecision = this->aproxPrecision(ctx) - val->aproxPrecision(ctx);
		if(diffPrecision > (int)diffScale + 1)
		{
			return thisSign;
		}
				else 
		{
			if(diffPrecision < (int)diffScale - 1)
			{
				return -thisSign;
			}
						else 
			{
				BigInteger* thisUnscaled = this->getUnscaledValue(ctx);
				BigInteger* valUnscaled = val->getUnscaledValue(ctx);
				if(diffScale < (long long)0)
				{
					thisUnscaled = thisUnscaled->multiply(Multiplication::powerOf10(-diffScale, ctx), ctx);
				}
								else 
				{
					if(diffScale > (long long)0)
					{
						valUnscaled = valUnscaled->multiply(Multiplication::powerOf10(diffScale, ctx), ctx);
					}
				}
				return thisUnscaled->compareTo(valUnscaled, ctx);
			}
		}
	}
		else 
	{
		if(thisSign < valueSign)
		{
			return -1;
		}
				else 
		{
			return 1;
		}
	}
}
bool BigDecimal::equals(IObject* x, ThreadContext* ctx) throw() 
{
	if(this == x)
	{
		return true;
	}
	if((dynamic_cast<BigDecimal*>(x) != 0))
	{
		BigDecimal* x1 = dynamic_cast<BigDecimal*>(x);
		return x1->_scale == _scale && (_bitLength < 64 ? (x1->smallValue == smallValue) : intVal->equals(x1->intVal, ctx));
	}
	return false;
}
BigDecimal* BigDecimal::min(BigDecimal* val, ThreadContext* ctx) throw() 
{
	return ((compareTo(val, ctx) <= 0) ? this : val);
}
BigDecimal* BigDecimal::max(BigDecimal* val, ThreadContext* ctx) throw() 
{
	return ((compareTo(val, ctx) >= 0) ? this : val);
}
int BigDecimal::hashCode(ThreadContext* ctx) throw() 
{
	if(_hashCode != 0)
	{
		return _hashCode;
	}
	if(_bitLength < 64)
	{
		_hashCode = ((int)(smallValue & 0xffffffff));
		_hashCode = 33 * _hashCode + ((int)((smallValue >> 32) & 0xffffffff));
		_hashCode = 17 * _hashCode + _scale;
		return _hashCode;
	}
	_hashCode = 17 * intVal->hashCode(ctx) + _scale;
	return _hashCode;
}
String* BigDecimal::toString(ThreadContext* ctx) throw() 
{
	if(toStringImage != nullptr)
	{
		return toStringImage;
	}
	if(_bitLength < 32)
	{
		__GC_MV(this, &(toStringImage), Conversion::toDecimalScaledString(smallValue, _scale, ctx), String);
		return toStringImage;
	}
	String* intString = getUnscaledValue(ctx)->toString(ctx);
	if(_scale == 0)
	{
		return intString;
	}
	int begin = (getUnscaledValue(ctx)->signum(ctx) < 0) ? 2 : 1;
	int end = intString->length(ctx);
	long long exponent = -((long long)_scale) + end - begin;
	StringBuilder* result = (new(ctx) StringBuilder(ctx));
	result->append(intString, ctx);
	if((_scale > 0) && (exponent >= (long long)-6))
	{
		if(exponent >= (long long)0)
		{
			result->insert(end - _scale, L'.', ctx);
		}
				else 
		{
			result->insert(begin - 1, ConstStr::getCNST_STR_67(), ctx);
			result->insert(begin + 1, CH_ZEROS, 0, -((int)exponent) - 1, ctx);
		}
	}
		else 
	{
		if(end - begin >= 1)
		{
			result->insert(begin, L'.', ctx);
			end ++ ;
		}
		result->insert(end, L'E', ctx);
		if(exponent > (long long)0)
		{
			result->insert(++end, L'+', ctx);
		}
		result->insert(++end, Long::toString(exponent, ctx), ctx);
	}
	__GC_MV(this, &(toStringImage), result->toString(ctx), String);
	return toStringImage;
}
String* BigDecimal::toEngineeringString(ThreadContext* ctx) throw() 
{
	String* intString = getUnscaledValue(ctx)->toString(ctx);
	if(_scale == 0)
	{
		return intString;
	}
	int begin = (getUnscaledValue(ctx)->signum(ctx) < 0) ? 2 : 1;
	int end = intString->length(ctx);
	long long exponent = -((long long)_scale) + end - begin;
	StringBuilder* result = (new(ctx) StringBuilder(intString, ctx));
	if((_scale > 0) && (exponent >= (long long)-6))
	{
		if(exponent >= (long long)0)
		{
			result->insert(end - _scale, L'.', ctx);
		}
				else 
		{
			result->insert(begin - 1, ConstStr::getCNST_STR_67(), ctx);
			result->insert(begin + 1, CH_ZEROS, 0, -((int)exponent) - 1, ctx);
		}
	}
		else 
	{
		int delta = end - begin;
		int rem = ((int)(exponent % 3));
		if(rem != 0)
		{
			if(getUnscaledValue(ctx)->signum(ctx) == 0)
			{
				rem = (rem < 0) ? -rem : 3 - rem;
				exponent += rem;
			}
						else 
			{
				rem = (rem < 0) ? rem + 3 : rem;
				exponent -= rem;
				begin += rem;
			}
			if(delta < 3)
			{
				for(int i = rem - delta; i > 0; i -- )
				{
					result->insert(end++, L'0', ctx);
				}
			}
		}
		if(end - begin >= 1)
		{
			result->insert(begin, L'.', ctx);
			end ++ ;
		}
		if(exponent != (long long)0)
		{
			result->insert(end, L'E', ctx);
			if(exponent > (long long)0)
			{
				result->insert(++end, L'+', ctx);
			}
			result->insert(++end, Long::toString(exponent, ctx), ctx);
		}
	}
	return result->toString(ctx);
}
String* BigDecimal::toPlainString(ThreadContext* ctx) throw() 
{
	String* intStr = getUnscaledValue(ctx)->toString(ctx);
	if((_scale == 0) || ((isZero(ctx)) && (_scale < 0)))
	{
		return intStr;
	}
	int begin = (signum(ctx) < 0) ? 1 : 0;
	int delta = _scale;
	StringBuilder* result = (new(ctx) StringBuilder(intStr->length(ctx) + 1 + Math::abs(_scale, ctx), ctx));
	if(begin == 1)
	{
		result->append(L'-', ctx);
	}
	if(_scale > 0)
	{
		delta -= (intStr->length(ctx) - begin);
		if(delta >= 0)
		{
			result->append(ConstStr::getCNST_STR_67(), ctx);
			for(; delta > CH_ZEROS->length; delta -= CH_ZEROS->length)
			{
				result->append(CH_ZEROS, ctx);
			}
			result->append(CH_ZEROS, 0, delta, ctx);
			result->append(intStr->substring(begin, ctx), ctx);
		}
				else 
		{
			delta = begin - delta;
			result->append(intStr->substring(begin, delta, ctx), ctx);
			result->append(L'.', ctx);
			result->append(intStr->substring(delta, ctx), ctx);
		}
	}
		else 
	{
		result->append(intStr->substring(begin, ctx), ctx);
		for(; delta < -CH_ZEROS->length; delta += CH_ZEROS->length)
		{
			result->append(CH_ZEROS, ctx);
		}
		result->append(CH_ZEROS, 0, -delta, ctx);
	}
	return result->toString(ctx);
}
BigInteger* BigDecimal::toBigInteger(ThreadContext* ctx) throw() 
{
	if((_scale == 0) || (isZero(ctx)))
	{
		return getUnscaledValue(ctx);
	}
		else 
	{
		if(_scale < 0)
		{
			return getUnscaledValue(ctx)->multiply(Multiplication::powerOf10(-((long long)_scale), ctx), ctx);
		}
				else 
		{
			return getUnscaledValue(ctx)->divide(Multiplication::powerOf10((long long)_scale, ctx), ctx);
		}
	}
}
BigInteger* BigDecimal::toBigIntegerExact(ThreadContext* ctx) throw() 
{
	if((_scale == 0) || (isZero(ctx)))
	{
		return getUnscaledValue(ctx);
	}
		else 
	{
		if(_scale < 0)
		{
			return getUnscaledValue(ctx)->multiply(Multiplication::powerOf10(-((long long)_scale), ctx), ctx);
		}
				else 
		{
			IArrayObject<BigInteger>* integerAndFraction = 0;
			if((_scale > aproxPrecision(ctx)) || (_scale > getUnscaledValue(ctx)->getLowestSetBit(ctx)))
			{
				throw (new(ctx) ArithmeticException(ConstStr::getCNST_STR_68(), ctx));
			}
			integerAndFraction = getUnscaledValue(ctx)->divideAndRemainder(Multiplication::powerOf10((long long)_scale, ctx), ctx);
			if(integerAndFraction->get(1)->signum(ctx) != 0)
			{
				throw (new(ctx) ArithmeticException(ConstStr::getCNST_STR_68(), ctx));
			}
			return integerAndFraction->get(0);
		}
	}
}
long long BigDecimal::longValue(ThreadContext* ctx) throw() 
{
	return ((_scale <= -64) || (_scale > aproxPrecision(ctx)) ? 0L : toBigInteger(ctx)->longValue(ctx));
}
long long BigDecimal::longValueExact(ThreadContext* ctx) throw() 
{
	return valueExact(64, ctx);
}
int BigDecimal::intValue(ThreadContext* ctx) throw() 
{
	return ((_scale <= -32) || (_scale > aproxPrecision(ctx)) ? 0 : toBigInteger(ctx)->intValue(ctx));
}
int BigDecimal::intValueExact(ThreadContext* ctx) throw() 
{
	return ((int)valueExact(32, ctx));
}
short BigDecimal::shortValueExact(ThreadContext* ctx) throw() 
{
	return ((short)valueExact(16, ctx));
}
char BigDecimal::byteValueExact(ThreadContext* ctx) throw() 
{
	return ((char)valueExact(8, ctx));
}
float BigDecimal::floatValue(ThreadContext* ctx) throw() 
{
	float floatResult = signum(ctx);
	long long powerOfTwo = this->_bitLength - ((long long)(_scale / LOG10_2));
	if((powerOfTwo < (long long)-149) || (floatResult == 0.0f))
	{
		floatResult *= 0.0f;
	}
		else 
	{
		if(powerOfTwo > (long long)129)
		{
			floatResult *= Float::POSITIVE_INFINITY;
		}
				else 
		{
			floatResult = ((float)doubleValue(ctx));
		}
	}
	return floatResult;
}
double BigDecimal::doubleValue(ThreadContext* ctx) throw() 
{
	int sign = signum(ctx);
	int exponent = 1076;
	int lowestSetBit = 0;
	int discardedSize = 0;
	long long powerOfTwo = this->_bitLength - ((long long)(_scale / LOG10_2));
	long long bits = 0;
	long long tempBits = 0;
	BigInteger* mantisa = 0;
	if((powerOfTwo < (long long)-1074) || (sign == 0))
	{
		return (sign * 0.0);
	}
		else 
	{
		if(powerOfTwo > (long long)1025)
		{
			return (sign * Double::POSITIVE_INFINITY);
		}
	}
	mantisa = getUnscaledValue(ctx)->abs(ctx);
	if(_scale <= 0)
	{
		mantisa = mantisa->multiply(Multiplication::powerOf10((long long)-_scale, ctx), ctx);
	}
		else 
	{
		IArrayObject<BigInteger>* quotAndRem = 0;
		BigInteger* powerOfTen = Multiplication::powerOf10((long long)_scale, ctx);
		int k = 100 - ((int)powerOfTwo);
		int compRem = 0;
		if(k > 0)
		{
			mantisa = mantisa->shiftLeft(k, ctx);
			exponent -= k;
		}
		quotAndRem = mantisa->divideAndRemainder(powerOfTen, ctx);
		compRem = quotAndRem->get(1)->shiftLeftOneBit(ctx)->compareTo(powerOfTen, ctx);
		mantisa = quotAndRem->get(0)->shiftLeft(2, ctx)->add(BigInteger::valueOf((long long)(compRem * (compRem + 3)) / 2 + 1, ctx), ctx);
		exponent -= 2;
	}
	lowestSetBit = mantisa->getLowestSetBit(ctx);
	discardedSize = mantisa->bitLength(ctx) - 54;
	if(discardedSize > 0)
	{
		bits = mantisa->shiftRight(discardedSize, ctx)->longValue(ctx);
		tempBits = bits;
		if((((bits & 1) == (long long)1) && (lowestSetBit < discardedSize)) || ((bits & 3) == (long long)3))
		{
			bits += 2;
		}
	}
		else 
	{
		bits = mantisa->longValue(ctx) << -discardedSize;
		tempBits = bits;
		if((bits & 3) == (long long)3)
		{
			bits += 2;
		}
	}
	if((bits & 0x40000000000000L) == (long long)0)
	{
		bits >>= 1;
		exponent += discardedSize;
	}
		else 
	{
		bits >>= 2;
		exponent += discardedSize + 1;
	}
	if(exponent > 2046)
	{
		return (sign * Double::POSITIVE_INFINITY);
	}
		else 
	{
		if(exponent <= 0)
		{
			if(exponent < -53)
			{
				return (sign * 0.0);
			}
			bits = tempBits >> 1;
			tempBits = bits & (((unsigned int)-1L)>> (63 + exponent));
			bits >>= (-exponent);
			if(((bits & 3) == (long long)3) || (((bits & 1) == (long long)1) && (tempBits != (long long)0) && (lowestSetBit < discardedSize)))
			{
				bits += 1;
			}
			exponent = 0;
			bits >>= 1;
		}
	}
	bits = (sign & 0x8000000000000000L) | (((long long)exponent) << 52) | (bits & 0xFFFFFFFFFFFFFL);
	return Double::longBitsToDouble(bits, ctx);
}
BigDecimal* BigDecimal::ulp(ThreadContext* ctx) throw() 
{
	return valueOf((long long)1, _scale, ctx);
}
bool BigDecimal::isZero(ThreadContext* ctx) throw() 
{
	return _bitLength == 0 && this->smallValue != (long long)-1;
}
BigDecimal* BigDecimal::movePoint(long long newScale, ThreadContext* ctx) throw() 
{
	if(isZero(ctx))
	{
		return zeroScaledBy(Math::max(newScale, (long long)0, ctx), ctx);
	}
	if(newScale >= (long long)0)
	{
		if(_bitLength < 64)
		{
			return valueOf(smallValue, toIntScale(newScale, ctx), ctx);
		}
		return (new(ctx) BigDecimal(getUnscaledValue(ctx), toIntScale(newScale, ctx), ctx));
	}
	if(-newScale < (long long)LONG_TEN_POW->length && _bitLength + LONG_TEN_POW_BIT_LENGTH->get(((int)-newScale)) < 64)
	{
		return valueOf(smallValue * LONG_TEN_POW->get(((int)-newScale)), 0, ctx);
	}
	return (new(ctx) BigDecimal(Multiplication::multiplyByTenPow(getUnscaledValue(ctx), (long long)((int)-newScale), ctx), 0, ctx));
}
void BigDecimal::inplaceRound(MathContext* mc, ThreadContext* ctx) throw() 
{
	int mcPrecision = mc->getPrecision(ctx);
	if(aproxPrecision(ctx) - mcPrecision <= 0 || mcPrecision == 0)
	{
		return;
	}
	int discardedPrecision = precision(ctx) - mcPrecision;
	if((discardedPrecision <= 0))
	{
		return;
	}
	if(this->_bitLength < 64)
	{
		smallRound(mc, discardedPrecision, ctx);
		return;
	}
	BigInteger* sizeOfFraction = Multiplication::powerOf10((long long)discardedPrecision, ctx);
	IArrayObject<BigInteger>* integerAndFraction = getUnscaledValue(ctx)->divideAndRemainder(sizeOfFraction, ctx);
	long long newScale = ((long long)_scale) - discardedPrecision;
	int compRem = 0;
	BigDecimal* tempBD = 0;
	if(integerAndFraction->get(1)->signum(ctx) != 0)
	{
		compRem = (integerAndFraction->get(1)->abs(ctx)->shiftLeftOneBit(ctx)->compareTo(sizeOfFraction, ctx));
		compRem = roundingBehavior(integerAndFraction->get(0)->testBit(0, ctx) ? 1 : 0, integerAndFraction->get(1)->signum(ctx) * (5 + compRem), mc->getRoundingMode(ctx), ctx);
		if(compRem != 0)
		{
			integerAndFraction->set(integerAndFraction->get(0)->add(BigInteger::valueOf((long long)compRem, ctx), ctx),0, ctx);
		}
		tempBD = (new(ctx) BigDecimal(integerAndFraction->get(0), ctx));
		if(tempBD->precision(ctx) > mcPrecision)
		{
			integerAndFraction->set(integerAndFraction->get(0)->divide(BigInteger::TEN, ctx),0, ctx);
			newScale -- ;
		}
	}
	_scale = toIntScale(newScale, ctx);
	_precision = mcPrecision;
	setUnscaledValue(integerAndFraction->get(0), ctx);
}
void BigDecimal::smallRound(MathContext* mc, int discardedPrecision, ThreadContext* ctx) throw() 
{
	long long sizeOfFraction = LONG_TEN_POW->get(discardedPrecision);
	long long newScale = ((long long)_scale) - discardedPrecision;
	long long unscaledVal = smallValue;
	long long integer = unscaledVal / sizeOfFraction;
	long long fraction = unscaledVal % sizeOfFraction;
	int compRem = 0;
	if(fraction != (long long)0)
	{
		compRem = longCompareTo(Math::abs(fraction, ctx) << 1, sizeOfFraction, ctx);
		integer += roundingBehavior((((int)integer)) & 1, Long::signum(fraction, ctx) * (5 + compRem), mc->getRoundingMode(ctx), ctx);
		if(Math::log10((double)Math::abs(integer, ctx), ctx) >= (double)mc->getPrecision(ctx))
		{
			integer /= 10;
			newScale -- ;
		}
	}
	_scale = toIntScale(newScale, ctx);
	_precision = mc->getPrecision(ctx);
	smallValue = integer;
	_bitLength = bitLength(integer, ctx);
	__GC_MV(this, &(intVal), nullptr, BigInteger);
}
long long BigDecimal::valueExact(int bitLengthOfType, ThreadContext* ctx) throw() 
{
	BigInteger* bigInteger = toBigIntegerExact(ctx);
	if(bigInteger->bitLength(ctx) < bitLengthOfType)
	{
		return bigInteger->longValue(ctx);
	}
	throw (new(ctx) ArithmeticException(ConstStr::getCNST_STR_68(), ctx));
}
int BigDecimal::aproxPrecision(ThreadContext* ctx) throw() 
{
	return (_precision > 0) ? _precision : (((int)((this->_bitLength - 1) * LOG10_2))) + 1;
}
BigInteger* BigDecimal::getUnscaledValue(ThreadContext* ctx) throw() 
{
	if(intVal == nullptr)
	{
		__GC_MV(this, &(intVal), BigInteger::valueOf(smallValue, ctx), BigInteger);
	}
	return intVal;
}
void BigDecimal::setUnscaledValue(BigInteger* unscaledValue, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->intVal), unscaledValue, BigInteger);
	this->_bitLength = unscaledValue->bitLength(ctx);
	if(this->_bitLength < 64)
	{
		this->smallValue = unscaledValue->longValue(ctx);
	}
}
void BigDecimal::initBigDecimal(ThreadContext* ctx) throw() 
{
	{
		SynchronizedBlockObj __synchronized_2(initLock, ctx);
		if(initBigDecimalDone)
		{
			return;
		}
		initBigDecimalDone = true;
	}
	BigInteger::staticInit(ctx);
	Multiplication::initByBigInt(ctx);
	Primality::initByBigInt(ctx);
	int i = 0;
	for(; i < ZERO_SCALED_BY->length; i ++ )
	{
		BI_SCALED_BY_ZERO->set((new(ctx) BigDecimal(i, 0, ctx)),i, ctx);
		ZERO_SCALED_BY->set((new(ctx) BigDecimal(0, i, ctx)),i, ctx);
		CH_ZEROS->set(L'0',i, ctx);
	}
	for(; i < CH_ZEROS->length; i ++ )
	{
		CH_ZEROS->set(L'0',i, ctx);
	}
	for(int j = 0; j < LONG_FIVE_POW_BIT_LENGTH->length; j ++ )
	{
		LONG_FIVE_POW_BIT_LENGTH->set(bitLength(LONG_FIVE_POW->get(j), ctx),j, ctx);
	}
	for(int j = 0; j < LONG_TEN_POW_BIT_LENGTH->length; j ++ )
	{
		LONG_TEN_POW_BIT_LENGTH->set(bitLength(LONG_TEN_POW->get(j), ctx),j, ctx);
	}
	__GC_MV(nullptr, &(TEN_POW), Multiplication::bigTenPows, IArrayObject<BigInteger>);
	__GC_MV(nullptr, &(FIVE_POW), Multiplication::bigFivePows, IArrayObject<BigInteger>);
}
BigDecimal* BigDecimal::valueOf(long long unscaledVal, int scale, ThreadContext* ctx) throw() 
{
	initBigDecimal(ctx);
	if(scale == 0)
	{
		return valueOf(unscaledVal, ctx);
	}
	if((unscaledVal == (long long)0) && (scale >= 0) && (scale < ZERO_SCALED_BY->length))
	{
		return ZERO_SCALED_BY->get(scale);
	}
	return (new(ctx) BigDecimal(unscaledVal, scale, ctx));
}
BigDecimal* BigDecimal::valueOf(long long unscaledVal, ThreadContext* ctx) throw() 
{
	initBigDecimal(ctx);
	if((unscaledVal >= (long long)0) && (unscaledVal < (long long)BI_SCALED_BY_ZERO_LENGTH))
	{
		return BI_SCALED_BY_ZERO->get(((int)unscaledVal));
	}
	return (new(ctx) BigDecimal(unscaledVal, 0, ctx));
}
BigDecimal* BigDecimal::valueOf(double val, ThreadContext* ctx) throw() 
{
	initBigDecimal(ctx);
	if(Double::isInfinite(val, ctx) || Double::isNaN(val, ctx))
	{
		throw (new(ctx) NumberFormatException(ConstStr::getCNST_STR_62(), ctx));
	}
	return (new(ctx) BigDecimal(Double::toString(val, ctx), ctx));
}
BigDecimal* BigDecimal::addAndMult10(BigDecimal* thisValue, BigDecimal* augend, int diffScale, ThreadContext* ctx) throw() 
{
	if(diffScale < LONG_TEN_POW->length && Math::max(thisValue->_bitLength, augend->_bitLength + LONG_TEN_POW_BIT_LENGTH->get(diffScale), ctx) + 1 < 64)
	{
		return valueOf(thisValue->smallValue + augend->smallValue * LONG_TEN_POW->get(diffScale), thisValue->_scale, ctx);
	}
	return (new(ctx) BigDecimal(thisValue->getUnscaledValue(ctx)->add(Multiplication::multiplyByTenPow(augend->getUnscaledValue(ctx), (long long)diffScale, ctx), ctx), thisValue->_scale, ctx));
}
BigDecimal* BigDecimal::divideBigIntegers(BigInteger* scaledDividend, BigInteger* scaledDivisor, int scale, RoundingMode* roundingMode, ThreadContext* ctx) throw() 
{
	IArrayObject<BigInteger>* quotAndRem = scaledDividend->divideAndRemainder(scaledDivisor, ctx);
	BigInteger* quotient = quotAndRem->get(0);
	BigInteger* remainder = quotAndRem->get(1);
	if(remainder->signum(ctx) == 0)
	{
		return (new(ctx) BigDecimal(quotient, scale, ctx));
	}
	int sign = scaledDividend->signum(ctx) * scaledDivisor->signum(ctx);
	int compRem = 0;
	if(scaledDivisor->bitLength(ctx) < 63)
	{
		long long rem = remainder->longValue(ctx);
		long long divisor = scaledDivisor->longValue(ctx);
		compRem = longCompareTo(Math::abs(rem, ctx) << 1, Math::abs(divisor, ctx), ctx);
		compRem = roundingBehavior(quotient->testBit(0, ctx) ? 1 : 0, sign * (5 + compRem), roundingMode, ctx);
	}
		else 
	{
		compRem = remainder->abs(ctx)->shiftLeftOneBit(ctx)->compareTo(scaledDivisor->abs(ctx), ctx);
		compRem = roundingBehavior(quotient->testBit(0, ctx) ? 1 : 0, sign * (5 + compRem), roundingMode, ctx);
	}
	if(compRem != 0)
	{
		if(quotient->bitLength(ctx) < 63)
		{
			return valueOf(quotient->longValue(ctx) + compRem, scale, ctx);
		}
		quotient = quotient->add(BigInteger::valueOf((long long)compRem, ctx), ctx);
		return (new(ctx) BigDecimal(quotient, scale, ctx));
	}
	return (new(ctx) BigDecimal(quotient, scale, ctx));
}
BigDecimal* BigDecimal::dividePrimitiveLongs(long long scaledDividend, long long scaledDivisor, int scale, RoundingMode* roundingMode, ThreadContext* ctx) throw() 
{
	long long quotient = scaledDividend / scaledDivisor;
	long long remainder = scaledDividend % scaledDivisor;
	int sign = Long::signum(scaledDividend, ctx) * Long::signum(scaledDivisor, ctx);
	if(remainder != (long long)0)
	{
		int compRem = 0;
		compRem = longCompareTo(Math::abs(remainder, ctx) << 1, Math::abs(scaledDivisor, ctx), ctx);
		quotient += roundingBehavior((((int)quotient)) & 1, sign * (5 + compRem), roundingMode, ctx);
	}
	return valueOf(quotient, scale, ctx);
}
int BigDecimal::longCompareTo(long long value1, long long value2, ThreadContext* ctx) throw() 
{
	return value1 > value2 ? 1 : (value1 < value2 ? -1 : 0);
}
int BigDecimal::roundingBehavior(int parityBit, int fraction, RoundingMode* roundingMode, ThreadContext* ctx) throw() 
{
	int increment = 0;
	switch(roundingMode->getBigDecimalRM(ctx)) {
	case BigDecimal::ROUND_UNNECESSARY:
		if(fraction != 0)
		{
			throw (new(ctx) ArithmeticException(ConstStr::getCNST_STR_68(), ctx));
		}
		break ;
	case BigDecimal::ROUND_UP:
		increment = Integer::signum(fraction, ctx);
		break ;
	case BigDecimal::ROUND_DOWN:
		break ;
	case BigDecimal::ROUND_CEILING:
		increment = Math::max(Integer::signum(fraction, ctx), 0, ctx);
		break ;
	case BigDecimal::ROUND_FLOOR:
		increment = Math::min(Integer::signum(fraction, ctx), 0, ctx);
		break ;
	case BigDecimal::ROUND_HALF_UP:
		if(Math::abs(fraction, ctx) >= 5)
		{
			increment = Integer::signum(fraction, ctx);
		}
		break ;
	case BigDecimal::ROUND_HALF_DOWN:
		if(Math::abs(fraction, ctx) > 5)
		{
			increment = Integer::signum(fraction, ctx);
		}
		break ;
	case BigDecimal::ROUND_HALF_EVEN:
		if(Math::abs(fraction, ctx) + parityBit > 5)
		{
			increment = Integer::signum(fraction, ctx);
		}
		break ;
	}
	return increment;
}
int BigDecimal::toIntScale(long long longScale, ThreadContext* ctx) throw() 
{
	if(longScale < (long long)Integer::MIN_VALUE)
	{
		throw (new(ctx) ArithmeticException(ConstStr::getCNST_STR_69(), ctx));
	}
		else 
	{
		if(longScale > (long long)Integer::MAX_VALUE)
		{
			throw (new(ctx) ArithmeticException(ConstStr::getCNST_STR_70(), ctx));
		}
				else 
		{
			return ((int)longScale);
		}
	}
}
BigDecimal* BigDecimal::zeroScaledBy(long long longScale, ThreadContext* ctx) throw() 
{
	if(longScale == (long long)((int)longScale))
	{
		return valueOf((long long)0, ((int)longScale), ctx);
	}
	if(longScale >= (long long)0)
	{
		return (new(ctx) BigDecimal(0, Integer::MAX_VALUE, ctx));
	}
	return (new(ctx) BigDecimal(0, Integer::MIN_VALUE, ctx));
}
int BigDecimal::bitLength(long long smallValue, ThreadContext* ctx) throw() 
{
	if(smallValue < (long long)0)
	{
		smallValue = ~smallValue;
	}
	return 64 - Long::numberOfLeadingZeros(smallValue, ctx);
}
int BigDecimal::bitLength(int smallValue, ThreadContext* ctx) throw() 
{
	if(smallValue < 0)
	{
		smallValue = ~smallValue;
	}
	return 32 - Integer::numberOfLeadingZeros(smallValue, ctx);
}
void BigDecimal::__cleanUp(ThreadContext* ctx){
	GCUtils<BigDecimal>::dec(nullptr, BigDecimal::ZERO, ctx, __FILEW__, __LINE__, L"BigDecimal");
	GCUtils<BigDecimal>::dec(nullptr, BigDecimal::ONE, ctx, __FILEW__, __LINE__, L"BigDecimal");
	GCUtils<BigDecimal>::dec(nullptr, BigDecimal::TEN, ctx, __FILEW__, __LINE__, L"BigDecimal");
	GCUtils<IArrayObject<BigInteger>>::dec(nullptr, BigDecimal::FIVE_POW, ctx, __FILEW__, __LINE__, L"IArrayObject<BigInteger>");
	GCUtils<IArrayObject<BigInteger>>::dec(nullptr, BigDecimal::TEN_POW, ctx, __FILEW__, __LINE__, L"IArrayObject<BigInteger>");
	GCUtils<IArrayObjectPrimitive<int>>::dec(nullptr, BigDecimal::LONG_FIVE_POW_BIT_LENGTH, ctx, __FILEW__, __LINE__, L"IArrayObjectPrimitive<int>");
	GCUtils<IArrayObjectPrimitive<int>>::dec(nullptr, BigDecimal::LONG_TEN_POW_BIT_LENGTH, ctx, __FILEW__, __LINE__, L"IArrayObjectPrimitive<int>");
	GCUtils<IArrayObject<BigDecimal>>::dec(nullptr, BigDecimal::BI_SCALED_BY_ZERO, ctx, __FILEW__, __LINE__, L"IArrayObject<BigDecimal>");
	GCUtils<IArrayObject<BigDecimal>>::dec(nullptr, BigDecimal::ZERO_SCALED_BY, ctx, __FILEW__, __LINE__, L"IArrayObject<BigDecimal>");
	GCUtils<IArrayObjectPrimitive<wchar_t>>::dec(nullptr, BigDecimal::CH_ZEROS, ctx, __FILEW__, __LINE__, L"IArrayObjectPrimitive<wchar_t>");
	GCUtils<LockObject>::dec(nullptr, BigDecimal::initLock, ctx, __FILEW__, __LINE__, L"LockObject");
}
int BigDecimal::ValueCompare::operator() (BigDecimal* _this, BigDecimal* val, ThreadContext* ctx) const throw()
{
	return _this->compareTo(val, ctx);
}
}}

