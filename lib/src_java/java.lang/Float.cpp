#include "include/global.h"


#include "com.google.re2j/PatternSyntaxException.h"
#include "java.harmoney/HexStringParser.h"
#include "java.harmoney/FloatingPointParser.h"
#include "java.harmoney/NumberConverter.h"
#include "java.lang/Number.h"
#include "java.lang/Comparable.h"
#include "java.lang/Float.h"

namespace java {namespace lang {





constexpr const float Float::MAX_VALUE;
constexpr const float Float::MIN_VALUE;
float Float::NaN = 0;
float Float::POSITIVE_INFINITY = 0;
float Float::NEGATIVE_INFINITY = 0;
constexpr const int Float::SIZE;
int Float::SINGLE_EXPONENT_MASK = 0;
int Float::SINGLE_MANTISSA_MASK = 0;
int Float::SINGLE_NAN_BITS = 0;
bool Float::__init_done = __init_static_variables();
bool Float::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"Float", L"__init_static_variables");
		Float::NaN = 0.0f / 0.0f;
		Float::POSITIVE_INFINITY = 1.0f / 0.0f;
		Float::NEGATIVE_INFINITY = -1.0f / 0.0f;
		Float::SINGLE_EXPONENT_MASK = 0x7F800000;
		Float::SINGLE_MANTISSA_MASK = 0x007FFFFF;
		Float::SINGLE_NAN_BITS = (SINGLE_EXPONENT_MASK | 0x00400000);
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 Float::Float(float value, ThreadContext* ctx) throw()  : IObject(ctx), Number(ctx), Comparable<Float>(ctx), value(0)
{
	this->value = value;
}
void Float::__construct_impl(float value, ThreadContext* ctx) throw() 
{
	this->value = value;
}
 Float::Float(double value, ThreadContext* ctx) throw()  : IObject(ctx), Number(ctx), Comparable<Float>(ctx), value(0)
{
	this->value = ((float)value);
}
void Float::__construct_impl(double value, ThreadContext* ctx) throw() 
{
	this->value = ((float)value);
}
 Float::Float(String* string, ThreadContext* ctx) : IObject(ctx), Number(ctx), Comparable<Float>(ctx), value(0)
{
	__construct_impl(parseFloat(string, ctx), ctx);
}
void Float::__construct_impl(String* string, ThreadContext* ctx)
{
	__construct_impl(parseFloat(string, ctx), ctx);
}
 Float::~Float() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void Float::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"Float", L"~Float");
	if(!prepare){
		return;
	}
	Number::__releaseRegerences(true, ctx);
}
int Float::compareTo(Float* object, ThreadContext* ctx) throw() 
{
	return compare(value, object->value, ctx);
}
char Float::byteValue(ThreadContext* ctx) throw() 
{
	return ((char)value);
}
double Float::doubleValue(ThreadContext* ctx) throw() 
{
	return value;
}
bool Float::equals(IObject* object, ThreadContext* ctx) throw() 
{
	return ((object == this) || ((dynamic_cast<Float*>(object) != 0))) && (floatToIntBits(this->value, ctx) == floatToIntBits((dynamic_cast<Float*>(object))->value, ctx));
}
float Float::floatValue(ThreadContext* ctx) throw() 
{
	return value;
}
int Float::hashCode(ThreadContext* ctx) throw() 
{
	return floatToIntBits(value, ctx);
}
int Float::intValue(ThreadContext* ctx) throw() 
{
	return ((int)value);
}
bool Float::isInfinite(ThreadContext* ctx) throw() 
{
	return isInfinite(value, ctx);
}
bool Float::isNaN(ThreadContext* ctx) throw() 
{
	return isNaN(value, ctx);
}
long long Float::longValue(ThreadContext* ctx) throw() 
{
	return ((long long)value);
}
short Float::shortValue(ThreadContext* ctx) throw() 
{
	return ((short)value);
}
String* Float::toString(ThreadContext* ctx) throw() 
{
	return Float::toString(value, ctx);
}
int Float::floatToIntBits(float value, ThreadContext* ctx) throw() 
{
	int arraySize = 8;
	ByteBuffer* buffer = ByteBuffer::allocate(arraySize, ctx);
	buffer->putDouble((double)value, ctx);
	buffer->position(0, ctx);
	int intValue = buffer->getInt(ctx);
	if((intValue & SINGLE_EXPONENT_MASK) == SINGLE_EXPONENT_MASK)
	{
		int tmp = intValue & SINGLE_MANTISSA_MASK;
		if(tmp > 0)
		{
			return SINGLE_NAN_BITS;
		}
	}
	return intValue;
}
int Float::floatToRawIntBits(float value, ThreadContext* ctx) throw() 
{
	int arraySize = Float::SIZE / 8;
	ByteBuffer* buffer = ByteBuffer::allocate(arraySize, ctx);
	buffer->putDouble((double)value, ctx);
	buffer->position(0, ctx);
	return buffer->getInt(ctx);
}
float Float::intBitsToFloat(int bits, ThreadContext* ctx) throw() 
{
	int arraySize = 4;
	ByteBuffer* buffer = ByteBuffer::allocate(arraySize, ctx);
	buffer->putLong((long long)bits, ctx);
	buffer->position(0, ctx);
	return buffer->getFloat(ctx);
}
bool Float::isInfinite(float f, ThreadContext* ctx) throw() 
{
	return (f == POSITIVE_INFINITY) || (f == NEGATIVE_INFINITY);
}
bool Float::isNaN(float f, ThreadContext* ctx) throw() 
{
	return f != f;
}
float Float::parseFloat(String* string, ThreadContext* ctx)
{
	{
		try
		{
			return ((float)FloatingPointParser::doparseDouble(string, ctx));
		}
		catch(PatternSyntaxException* e)
		{
			throw (new(ctx) NullPointerException(ctx));
		}
	}
}
String* Float::toString(float f, ThreadContext* ctx) throw() 
{
	return NumberConverter::convert(((double)f), ctx);
}
Float* Float::valueOf(String* string, ThreadContext* ctx)
{
	return valueOf(parseFloat(string, ctx), ctx);
}
int Float::compare(float float1, float float2, ThreadContext* ctx) throw() 
{
	if(float1 > float2)
	{
		return 1;
	}
	if(float2 > float1)
	{
		return -1;
	}
	if(float1 == float2 && 0.0f != float1)
	{
		return 0;
	}
	if(isNaN(float1, ctx))
	{
		if(isNaN(float2, ctx))
		{
			return 0;
		}
		return 1;
	}
		else 
	{
		if(isNaN(float2, ctx))
		{
			return -1;
		}
	}
	int f1 = floatToRawIntBits(float1, ctx);
	int f2 = floatToRawIntBits(float2, ctx);
	return (f1 >> 31) - (f2 >> 31);
}
Float* Float::valueOf(float f, ThreadContext* ctx) throw() 
{
	return (new(ctx) Float(f, ctx));
}
String* Float::toHexString(float f, ThreadContext* ctx) throw() 
{
	if(f != f)
	{
		return ConstStr::getCNST_STR_359();
	}
	if(f == POSITIVE_INFINITY)
	{
		return ConstStr::getCNST_STR_358();
	}
	if(f == NEGATIVE_INFINITY)
	{
		return ConstStr::getCNST_STR_373();
	}
	int bitValue = floatToIntBits(f, ctx);
	bool negative = (bitValue & 0x80000000) != 0;
	int exponent = ((unsigned int)(bitValue & 0x7f800000))>> 23;
	int significand = (bitValue & 0x007FFFFF) << 1;
	if(exponent == 0 && significand == 0)
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
	if(exponent == 0)
	{
		hexString->append(ConstStr::getCNST_STR_67(), ctx);
		int fractionDigits = 6;
		while((significand != 0) && ((significand & 0xF) == 0))
		{
			significand = ((unsigned int)significand) >> 4;
			fractionDigits -- ;
		}
		String* hexSignificand = Integer::toHexString(significand, ctx);
		if(significand != 0 && fractionDigits > hexSignificand->length(ctx))
		{
			int digitDiff = fractionDigits - hexSignificand->length(ctx);
			while(digitDiff-- != 0)
			{
				hexString->append(L'0', ctx);
			}
		}
		hexString->append(hexSignificand, ctx);
		hexString->append(ConstStr::getCNST_STR_379(), ctx);
	}
		else 
	{
		hexString->append(ConstStr::getCNST_STR_377(), ctx);
		int fractionDigits = 6;
		while((significand != 0) && ((significand & 0xF) == 0))
		{
			significand = ((unsigned int)significand) >> 4;
			fractionDigits -- ;
		}
		String* hexSignificand = Integer::toHexString(significand, ctx);
		if(significand != 0 && fractionDigits > hexSignificand->length(ctx))
		{
			int digitDiff = fractionDigits - hexSignificand->length(ctx);
			while(digitDiff-- != 0)
			{
				hexString->append(L'0', ctx);
			}
		}
		hexString->append(hexSignificand, ctx);
		hexString->append(L'p', ctx);
		hexString->append(Integer::toString(exponent - 127, ctx), ctx);
	}
	return hexString->toString(ctx);
}
void Float::__cleanUp(ThreadContext* ctx){
}
int Float::ValueCompare::operator() (Float* _this, Float* object, ThreadContext* ctx) const throw()
{
	return _this->compareTo(object, ctx);
}
}}

