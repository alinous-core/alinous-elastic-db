#include "includes.h"


namespace java {namespace lang {





constexpr const double Double::MAX_VALUE;
constexpr const double Double::MIN_VALUE;
double Double::NaN = 0;
double Double::POSITIVE_INFINITY = 0;
double Double::NEGATIVE_INFINITY = 0;
constexpr const int Double::SIZE;
long long Double::DOUBLE_EXPONENT_MASK = 0;
long long Double::DOUBLE_MANTISSA_MASK = 0;
long long Double::DOUBLE_NAN_BITS = 0;
bool Double::__init_done = __init_static_variables();
bool Double::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"Double", L"__init_static_variables");
		Double::NaN = 0.0 / 0.0;
		Double::POSITIVE_INFINITY = 1.0 / 0.0;
		Double::NEGATIVE_INFINITY = -1.0 / 0.0;
		Double::DOUBLE_EXPONENT_MASK = 0x7FF0000000000000L;
		Double::DOUBLE_MANTISSA_MASK = 0x000FFFFFFFFFFFFFL;
		Double::DOUBLE_NAN_BITS = DOUBLE_EXPONENT_MASK | 0x0008000000000000L;
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 Double::Double(double value, ThreadContext* ctx) throw()  : IObject(ctx), Number(ctx), Comparable<Double>(ctx), value(0)
{
	this->value = value;
}
void Double::__construct_impl(double value, ThreadContext* ctx) throw() 
{
	this->value = value;
}
 Double::Double(String* string, ThreadContext* ctx) : IObject(ctx), Number(ctx), Comparable<Double>(ctx), value(0)
{
	__construct_impl(parseDouble(string, ctx), ctx);
}
void Double::__construct_impl(String* string, ThreadContext* ctx)
{
	__construct_impl(parseDouble(string, ctx), ctx);
}
 Double::~Double() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void Double::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"Double", L"~Double");
	if(!prepare){
		return;
	}
	Number::__releaseRegerences(true, ctx);
}
int Double::compareTo(Double* object, ThreadContext* ctx) throw() 
{
	return compare(value, object->value, ctx);
}
char Double::byteValue(ThreadContext* ctx) throw() 
{
	return ((char)value);
}
double Double::doubleValue(ThreadContext* ctx) throw() 
{
	return value;
}
bool Double::equals(IObject* object, ThreadContext* ctx) throw() 
{
	return (object == this) || (((dynamic_cast<Double*>(object) != 0)) && (doubleToLongBits(this->value, ctx) == doubleToLongBits((dynamic_cast<Double*>(object))->value, ctx)));
}
float Double::floatValue(ThreadContext* ctx) throw() 
{
	return ((float)value);
}
int Double::hashCode(ThreadContext* ctx) throw() 
{
	long long v = doubleToLongBits(value, ctx);
	return ((int)(v ^ (((unsigned long long)v)>> 32)));
}
int Double::intValue(ThreadContext* ctx) throw() 
{
	return ((int)value);
}
bool Double::isInfinite(ThreadContext* ctx) throw() 
{
	return isInfinite(value, ctx);
}
bool Double::isNaN(ThreadContext* ctx) throw() 
{
	return isNaN(value, ctx);
}
long long Double::longValue(ThreadContext* ctx) throw() 
{
	return ((long long)value);
}
short Double::shortValue(ThreadContext* ctx) throw() 
{
	return ((short)value);
}
String* Double::toString(ThreadContext* ctx) throw() 
{
	return Double::toString(value, ctx);
}
long long Double::doubleToLongBits(double value, ThreadContext* ctx) throw() 
{
	int arraySize = 8;
	ByteBuffer* buffer = ByteBuffer::allocate(arraySize, ctx);
	buffer->putDouble(value, ctx);
	buffer->position(0, ctx);
	long long longValue = buffer->getLong(ctx);
	if((longValue & DOUBLE_EXPONENT_MASK) == DOUBLE_EXPONENT_MASK)
	{
		long long tmp = longValue & DOUBLE_MANTISSA_MASK;
		if(tmp > (long long)0)
		{
			return DOUBLE_NAN_BITS;
		}
	}
	return longValue;
}
long long Double::doubleToRawLongBits(double value, ThreadContext* ctx) throw() 
{
	int arraySize = 8;
	ByteBuffer* buffer = ByteBuffer::allocate(arraySize, ctx);
	buffer->putDouble(value, ctx);
	buffer->position(0, ctx);
	return buffer->getLong(ctx);
}
bool Double::isInfinite(double d, ThreadContext* ctx) throw() 
{
	return (d == POSITIVE_INFINITY) || (d == NEGATIVE_INFINITY);
}
bool Double::isNaN(double d, ThreadContext* ctx) throw() 
{
	return d != d;
}
double Double::longBitsToDouble(long long bits, ThreadContext* ctx) throw() 
{
	int arraySize = 8;
	ByteBuffer* buffer = ByteBuffer::allocate(arraySize, ctx);
	buffer->putLong(bits, ctx);
	buffer->position(0, ctx);
	return buffer->getDouble(ctx);
}
double Double::parseDouble(String* string, ThreadContext* ctx)
{
	{
		try
		{
			return FloatingPointParser::doparseDouble(string, ctx);
		}
		catch(PatternSyntaxException* e)
		{
			throw (new(ctx) NumberFormatException(ctx));
		}
	}
}
String* Double::toString(double d, ThreadContext* ctx) throw() 
{
	return NumberConverter::convert(d, ctx);
}
Double* Double::valueOf(String* string, ThreadContext* ctx)
{
	return (new(ctx) Double(parseDouble(string, ctx), ctx));
}
int Double::compare(double double1, double double2, ThreadContext* ctx) throw() 
{
	if(double1 > double2)
	{
		return 1;
	}
	if(double2 > double1)
	{
		return -1;
	}
	if(double1 == double2 && 0.0 != (float)double1)
	{
		return 0;
	}
	if(isNaN(double1, ctx))
	{
		if(isNaN(double2, ctx))
		{
			return 0;
		}
		return 1;
	}
		else 
	{
		if(isNaN(double2, ctx))
		{
			return -1;
		}
	}
	long long d1 = doubleToRawLongBits(double1, ctx);
	long long d2 = doubleToRawLongBits(double2, ctx);
	return ((int)((d1 >> 63) - (d2 >> 63)));
}
Double* Double::valueOf(double d, ThreadContext* ctx) throw() 
{
	return (new(ctx) Double(d, ctx));
}
String* Double::toHexString(double d, ThreadContext* ctx) throw() 
{
	if(d != d)
	{
		return ConstStr::getCNST_STR_359();
	}
	if(d == POSITIVE_INFINITY)
	{
		return ConstStr::getCNST_STR_358();
	}
	if(d == NEGATIVE_INFINITY)
	{
		return ConstStr::getCNST_STR_373();
	}
	long long bitValue = doubleToLongBits(d, ctx);
	bool negative = (bitValue & 0x8000000000000000L) != (long long)0;
	long long exponent = ((unsigned long long)(bitValue & 0x7FF0000000000000L))>> 52;
	long long significand = bitValue & 0x000FFFFFFFFFFFFFL;
	if(exponent == (long long)0 && significand == (long long)0)
	{
		return (negative ? ConstStr::getCNST_STR_374() : ConstStr::getCNST_STR_375());
	}
	StringBuilder* hexString = (new(ctx) StringBuilder(10, ctx));
	if(negative)
	{
		hexString->append(ConstStr::getCNST_STR_323(), ctx);
	}
		else 
	{
		hexString->append(ConstStr::getCNST_STR_322(), ctx);
	}
	if(exponent == (long long)0)
	{
		hexString->append(ConstStr::getCNST_STR_67(), ctx);
		int fractionDigits = 13;
		while((significand != (long long)0) && ((significand & 0xF) == (long long)0))
		{
			significand = ((unsigned long long)significand) >> 4;
			fractionDigits -- ;
		}
		String* hexSignificand = Long::toHexString(significand, ctx);
		if(significand != (long long)0 && fractionDigits > hexSignificand->length(ctx))
		{
			int digitDiff = fractionDigits - hexSignificand->length(ctx);
			while(digitDiff-- != 0)
			{
				hexString->append(L'0', ctx);
			}
		}
		hexString->append(hexSignificand, ctx);
		hexString->append(ConstStr::getCNST_STR_376(), ctx);
	}
		else 
	{
		hexString->append(ConstStr::getCNST_STR_377(), ctx);
		int fractionDigits = 13;
		while((significand != (long long)0) && ((significand & 0xF) == (long long)0))
		{
			significand = ((unsigned long long)significand) >> 4;
			fractionDigits -- ;
		}
		String* hexSignificand = Long::toHexString(significand, ctx);
		if(significand != (long long)0 && fractionDigits > hexSignificand->length(ctx))
		{
			int digitDiff = fractionDigits - hexSignificand->length(ctx);
			while(digitDiff-- != 0)
			{
				hexString->append(L'0', ctx);
			}
		}
		hexString->append(hexSignificand, ctx);
		hexString->append(L'p', ctx);
		hexString->append(Long::toString(exponent - 1023, ctx), ctx);
	}
	return hexString->toString(ctx);
}
int Double::ValueCompare::operator() (Double* _this, Double* object, ThreadContext* ctx) const throw()
{
	return _this->compareTo(object, ctx);
}
}}

