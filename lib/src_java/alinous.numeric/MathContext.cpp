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





MathContext* MathContext::DECIMAL128 = nullptr;
MathContext* MathContext::DECIMAL32 = nullptr;
MathContext* MathContext::DECIMAL64 = nullptr;
MathContext* MathContext::UNLIMITED = nullptr;
const StaticArrayObjectPrimitive<wchar_t> MathContext::__chPrecision = {L'p', L'r', L'e', L'c', L'i', L's', L'i', L'o', L'n', L'='};
IArrayObjectPrimitive<wchar_t>* MathContext::chPrecision = (IArrayObjectPrimitive<wchar_t>*)const_cast<StaticArrayObjectPrimitive<wchar_t>*>(&__chPrecision);
const StaticArrayObjectPrimitive<wchar_t> MathContext::__chRoundingMode = {L'r', L'o', L'u', L'n', L'd', L'i', L'n', L'g', L'M', L'o', L'd', L'e', L'='};
IArrayObjectPrimitive<wchar_t>* MathContext::chRoundingMode = (IArrayObjectPrimitive<wchar_t>*)const_cast<StaticArrayObjectPrimitive<wchar_t>*>(&__chRoundingMode);
bool MathContext::__init_done = __init_static_variables();
bool MathContext::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"MathContext", L"__init_static_variables");
		__GC_MV(nullptr, &(DECIMAL128), (new(ctx) MathContext(34, RoundingMode::HALF_EVEN, ctx)), MathContext);
		__GC_MV(nullptr, &(DECIMAL32), (new(ctx) MathContext(7, RoundingMode::HALF_EVEN, ctx)), MathContext);
		__GC_MV(nullptr, &(DECIMAL64), (new(ctx) MathContext(16, RoundingMode::HALF_EVEN, ctx)), MathContext);
		__GC_MV(nullptr, &(UNLIMITED), (new(ctx) MathContext(0, RoundingMode::HALF_UP, ctx)), MathContext);
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 MathContext::MathContext(int precision, ThreadContext* ctx) throw()  : IObject(ctx), precision(0), roundingMode(nullptr)
{
	__construct_impl(precision, (new(ctx) RoundingMode(RoundingMode::HALF_UP, ctx)), ctx);
}
void MathContext::__construct_impl(int precision, ThreadContext* ctx) throw() 
{
	__construct_impl(precision, (new(ctx) RoundingMode(RoundingMode::HALF_UP, ctx)), ctx);
}
 MathContext::MathContext(int precision, int roundingMode, ThreadContext* ctx) throw()  : IObject(ctx), precision(0), roundingMode(nullptr)
{
	__construct_impl(precision, (new(ctx) RoundingMode(roundingMode, ctx)), ctx);
}
void MathContext::__construct_impl(int precision, int roundingMode, ThreadContext* ctx) throw() 
{
	__construct_impl(precision, (new(ctx) RoundingMode(roundingMode, ctx)), ctx);
}
 MathContext::MathContext(int precision, RoundingMode* roundingMode, ThreadContext* ctx) throw()  : IObject(ctx), precision(0), roundingMode(nullptr)
{
	if(precision < 0)
	{
		throw (new(ctx) IllegalArgumentException(ConstStr::getCNST_STR_47(), ctx));
	}
	this->precision = precision;
	__GC_MV(this, &(this->roundingMode), roundingMode, RoundingMode);
}
void MathContext::__construct_impl(int precision, RoundingMode* roundingMode, ThreadContext* ctx) throw() 
{
	if(precision < 0)
	{
		throw (new(ctx) IllegalArgumentException(ConstStr::getCNST_STR_47(), ctx));
	}
	this->precision = precision;
	__GC_MV(this, &(this->roundingMode), roundingMode, RoundingMode);
}
 MathContext::MathContext(String* val, ThreadContext* ctx) throw()  : IObject(ctx), precision(0), roundingMode(nullptr)
{
	IArrayObjectPrimitive<wchar_t>* charVal = val->toCharArray(ctx);
	int i = 0;
	int j = 0;
	int digit = 0;
	if((charVal->length < 27) || (charVal->length > 45))
	{
		throw (new(ctx) IllegalArgumentException(ConstStr::getCNST_STR_48(), ctx));
	}
	for(i = 0; (i < chPrecision->length) && (charVal->get(i) == chPrecision->get(i)); i ++ )
	{
		;
	}
	if(i < chPrecision->length)
	{
		throw (new(ctx) IllegalArgumentException(ConstStr::getCNST_STR_48(), ctx));
	}
	digit = Character::digit(charVal->get(i), 10, ctx);
	if(digit == -1)
	{
		throw (new(ctx) IllegalArgumentException(ConstStr::getCNST_STR_48(), ctx));
	}
	this->precision = this->precision * 10 + digit;
	i ++ ;
	do
	{
		digit = Character::digit(charVal->get(i), 10, ctx);
		if(digit == -1)
		{
			if(charVal->get(i) == L' ')
			{
				i ++ ;
				break ;
			}
			throw (new(ctx) IllegalArgumentException(ConstStr::getCNST_STR_48(), ctx));
		}
		this->precision = this->precision * 10 + digit;
		if(this->precision < 0)
		{
			throw (new(ctx) IllegalArgumentException(ConstStr::getCNST_STR_48(), ctx));
		}
		i ++ ;
	}
	while(true);
	for(j = 0; (j < chRoundingMode->length) && (charVal->get(i) == chRoundingMode->get(j)); i ++ , j ++ )
	{
		;
	}
	if(j < chRoundingMode->length)
	{
		throw (new(ctx) IllegalArgumentException(ConstStr::getCNST_STR_48(), ctx));
	}
	__GC_MV(this, &(this->roundingMode), RoundingMode::valueOf(Integer::parseInt(String::valueOf(charVal, i, charVal->length - i, ctx), ctx), ctx), RoundingMode);
}
void MathContext::__construct_impl(String* val, ThreadContext* ctx) throw() 
{
	IArrayObjectPrimitive<wchar_t>* charVal = val->toCharArray(ctx);
	int i = 0;
	int j = 0;
	int digit = 0;
	if((charVal->length < 27) || (charVal->length > 45))
	{
		throw (new(ctx) IllegalArgumentException(ConstStr::getCNST_STR_48(), ctx));
	}
	for(i = 0; (i < chPrecision->length) && (charVal->get(i) == chPrecision->get(i)); i ++ )
	{
		;
	}
	if(i < chPrecision->length)
	{
		throw (new(ctx) IllegalArgumentException(ConstStr::getCNST_STR_48(), ctx));
	}
	digit = Character::digit(charVal->get(i), 10, ctx);
	if(digit == -1)
	{
		throw (new(ctx) IllegalArgumentException(ConstStr::getCNST_STR_48(), ctx));
	}
	this->precision = this->precision * 10 + digit;
	i ++ ;
	do
	{
		digit = Character::digit(charVal->get(i), 10, ctx);
		if(digit == -1)
		{
			if(charVal->get(i) == L' ')
			{
				i ++ ;
				break ;
			}
			throw (new(ctx) IllegalArgumentException(ConstStr::getCNST_STR_48(), ctx));
		}
		this->precision = this->precision * 10 + digit;
		if(this->precision < 0)
		{
			throw (new(ctx) IllegalArgumentException(ConstStr::getCNST_STR_48(), ctx));
		}
		i ++ ;
	}
	while(true);
	for(j = 0; (j < chRoundingMode->length) && (charVal->get(i) == chRoundingMode->get(j)); i ++ , j ++ )
	{
		;
	}
	if(j < chRoundingMode->length)
	{
		throw (new(ctx) IllegalArgumentException(ConstStr::getCNST_STR_48(), ctx));
	}
	__GC_MV(this, &(this->roundingMode), RoundingMode::valueOf(Integer::parseInt(String::valueOf(charVal, i, charVal->length - i, ctx), ctx), ctx), RoundingMode);
}
 MathContext::~MathContext() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void MathContext::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"MathContext", L"~MathContext");
	__e_obj1.add(this->roundingMode, this);
	roundingMode = nullptr;
	if(!prepare){
		return;
	}
}
int MathContext::getPrecision(ThreadContext* ctx) throw() 
{
	return precision;
}
RoundingMode* MathContext::getRoundingMode(ThreadContext* ctx) throw() 
{
	return roundingMode;
}
bool MathContext::equals(IObject* x, ThreadContext* ctx) throw() 
{
	return (((dynamic_cast<MathContext*>(x) != 0)) && ((dynamic_cast<MathContext*>(x))->getPrecision(ctx) == precision) && ((dynamic_cast<MathContext*>(x))->getRoundingMode(ctx) == roundingMode));
}
int MathContext::hashCode(ThreadContext* ctx) throw() 
{
	return ((precision << 3) | roundingMode->getBigDecimalRM(ctx));
}
String* MathContext::toString(ThreadContext* ctx) throw() 
{
	StringBuilder* sb = (new(ctx) StringBuilder(45, ctx));
	sb->append(chPrecision, ctx);
	sb->append(precision, ctx);
	sb->append(L' ', ctx);
	sb->append(chRoundingMode, ctx);
	sb->append(roundingMode, ctx);
	return sb->toString(ctx);
}
}}

