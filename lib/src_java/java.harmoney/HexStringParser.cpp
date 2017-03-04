#include "include/global.h"


#include "com.google.re2j/PatternSyntaxException.h"
#include "java.harmoney/FloatingPointParser.h"
#include "java.lang/Number.h"
#include "java.lang/Comparable.h"
#include "java.lang/Double.h"
#include "java.harmoney/NumberConverter.h"
#include "java.lang/Float.h"
#include "java.lang/Long.h"
#include "com.google.re2j/Inst.h"
#include "com.google.re2j/Prog.h"
#include "com.google.re2j/MachineInput.h"
#include "com.google.re2j/Machine.h"
#include "com.google.re2j/RE2.h"
#include "com.google.re2j/Pattern.h"
#include "com.google.re2j/Matcher.h"
#include "java.harmoney/HexStringParser.h"

namespace java {namespace harmoney {





constexpr const int HexStringParser::DOUBLE_EXPONENT_WIDTH;
constexpr const int HexStringParser::DOUBLE_MANTISSA_WIDTH;
constexpr const int HexStringParser::FLOAT_EXPONENT_WIDTH;
constexpr const int HexStringParser::FLOAT_MANTISSA_WIDTH;
constexpr const int HexStringParser::HEX_RADIX;
constexpr const int HexStringParser::MAX_SIGNIFICANT_LENGTH;
String* HexStringParser::HEX_SIGNIFICANT = ConstStr::getCNST_STR_364();
String* HexStringParser::BINARY_EXPONENT = ConstStr::getCNST_STR_365();
String* HexStringParser::FLOAT_TYPE_SUFFIX = ConstStr::getCNST_STR_366();
String* HexStringParser::HEX_PATTERN = nullptr;
Pattern* HexStringParser::PATTERN = nullptr;
bool HexStringParser::__init_done = __init_static_variables();
bool HexStringParser::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"HexStringParser", L"__init_static_variables");
		__GC_MV(nullptr, &(HEX_PATTERN), ConstStr::getCNST_STR_367()->clone(ctx)->append(HEX_SIGNIFICANT, ctx)->append(BINARY_EXPONENT, ctx)->append(FLOAT_TYPE_SUFFIX, ctx)->append(ConstStr::getCNST_STR_368(), ctx), String);
		__GC_MV(nullptr, &(PATTERN), nullptr, Pattern);
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 HexStringParser::HexStringParser(int exponent_width, int mantissa_width, ThreadContext* ctx) throw()  : IObject(ctx), EXPONENT_WIDTH(0), MANTISSA_WIDTH(0), EXPONENT_BASE(0), MAX_EXPONENT(0), MIN_EXPONENT(0), MANTISSA_MASK(0), sign(0), exponent(0), mantissa(0), abandonedNumber(__GC_INS(this, ConstStr::getCNST_STR_4(), String))
{
	this->EXPONENT_WIDTH = exponent_width;
	this->MANTISSA_WIDTH = mantissa_width;
	this->EXPONENT_BASE = ~(-1L << (exponent_width - 1));
	this->MAX_EXPONENT = ~(-1L << exponent_width);
	this->MIN_EXPONENT = -(MANTISSA_WIDTH + 1);
	this->MANTISSA_MASK = ~(-1L << mantissa_width);
}
void HexStringParser::__construct_impl(int exponent_width, int mantissa_width, ThreadContext* ctx) throw() 
{
	this->EXPONENT_WIDTH = exponent_width;
	this->MANTISSA_WIDTH = mantissa_width;
	this->EXPONENT_BASE = ~(-1L << (exponent_width - 1));
	this->MAX_EXPONENT = ~(-1L << exponent_width);
	this->MIN_EXPONENT = -(MANTISSA_WIDTH + 1);
	this->MANTISSA_MASK = ~(-1L << mantissa_width);
}
 HexStringParser::~HexStringParser() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void HexStringParser::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"HexStringParser", L"~HexStringParser");
	__e_obj1.add(this->abandonedNumber, this);
	abandonedNumber = nullptr;
	if(!prepare){
		return;
	}
}
long long HexStringParser::parse(String* hexString, ThreadContext* ctx)
{
	IArrayObject<String>* hexSegments = getSegmentsFromHexString(hexString, ctx);
	String* signStr = hexSegments->get(0);
	String* significantStr = hexSegments->get(1);
	String* exponentStr = hexSegments->get(2);
	parseHexSign(signStr, ctx);
	parseExponent(exponentStr, ctx);
	parseMantissa(significantStr, ctx);
	sign <<= (MANTISSA_WIDTH + EXPONENT_WIDTH);
	exponent <<= MANTISSA_WIDTH;
	return sign | exponent | mantissa;
}
void HexStringParser::parseHexSign(String* signStr, ThreadContext* ctx) throw() 
{
	this->sign = signStr->equals(ConstStr::getCNST_STR_98(), ctx) ? 1 : 0;
}
void HexStringParser::parseExponent(String* exponentStr, ThreadContext* ctx) throw() 
{
	wchar_t leadingChar = exponentStr->charAt(0, ctx);
	int expSign = (leadingChar == L'-' ? -1 : 1);
	if(!Character::isDigit(leadingChar, ctx))
	{
		exponentStr = exponentStr->substring(1, ctx);
	}
	{
		try
		{
			exponent = expSign * Long::parseLong(exponentStr, ctx);
			checkedAddExponent(EXPONENT_BASE, ctx);
		}
		catch(NumberFormatException* e)
		{
			exponent = expSign * Long::MAX_VALUE;
		}
	}
}
void HexStringParser::parseMantissa(String* significantStr, ThreadContext* ctx) throw() 
{
	IArrayObject<String>* strings = significantStr->split(ConstStr::getCNST_STR_361(), ctx);
	String* strIntegerPart = strings->get(0);
	String* strDecimalPart = strings->length > 1 ? strings->get(1) : ConstStr::getCNST_STR_4();
	String* significand = getNormalizedSignificand(strIntegerPart, strDecimalPart, ctx);
	if(significand->equals(ConstStr::getCNST_STR_9(), ctx))
	{
		setZero(ctx);
		return;
	}
	int offset = getOffset(strIntegerPart, strDecimalPart, ctx);
	checkedAddExponent((long long)offset, ctx);
	if(exponent >= MAX_EXPONENT)
	{
		setInfinite(ctx);
		return;
	}
	if(exponent <= MIN_EXPONENT)
	{
		setZero(ctx);
		return;
	}
	if(significand->length(ctx) > MAX_SIGNIFICANT_LENGTH)
	{
		__GC_MV(this, &(abandonedNumber), significand->substring(MAX_SIGNIFICANT_LENGTH, ctx), String);
		significand = significand->substring(0, MAX_SIGNIFICANT_LENGTH, ctx);
	}
	mantissa = Long::parseLong(significand, HEX_RADIX, ctx);
	if(exponent >= (long long)1)
	{
		processNormalNumber(ctx);
	}
		else 
	{
		processSubNormalNumber(ctx);
	}
}
void HexStringParser::setInfinite(ThreadContext* ctx) throw() 
{
	exponent = MAX_EXPONENT;
	mantissa = 0;
}
void HexStringParser::setZero(ThreadContext* ctx) throw() 
{
	exponent = 0;
	mantissa = 0;
}
void HexStringParser::checkedAddExponent(long long offset, ThreadContext* ctx) throw() 
{
	long long result = exponent + offset;
	int expSign = Long::signum(exponent, ctx);
	if(expSign * Long::signum(offset, ctx) > 0 && expSign * Long::signum(result, ctx) < 0)
	{
		exponent = expSign * Long::MAX_VALUE;
	}
		else 
	{
		exponent = result;
	}
}
void HexStringParser::processNormalNumber(ThreadContext* ctx) throw() 
{
	int desiredWidth = MANTISSA_WIDTH + 2;
	fitMantissaInDesiredWidth(desiredWidth, ctx);
	round(ctx);
	mantissa = mantissa & MANTISSA_MASK;
}
void HexStringParser::processSubNormalNumber(ThreadContext* ctx) throw() 
{
	int desiredWidth = MANTISSA_WIDTH + 1;
	desiredWidth += ((int)exponent);
	exponent = 0;
	fitMantissaInDesiredWidth(desiredWidth, ctx);
	round(ctx);
	mantissa = mantissa & MANTISSA_MASK;
}
void HexStringParser::fitMantissaInDesiredWidth(int desiredWidth, ThreadContext* ctx) throw() 
{
	int bitLength = countBitsLength(mantissa, ctx);
	if(bitLength > desiredWidth)
	{
		discardTrailingBits((long long)bitLength - desiredWidth, ctx);
	}
		else 
	{
		mantissa <<= (desiredWidth - bitLength);
	}
}
void HexStringParser::discardTrailingBits(long long num, ThreadContext* ctx) throw() 
{
	long long mask = ~(-1L << num);
	__GC_MV(this, &(abandonedNumber), abandonedNumber + (mantissa & mask), String);
	mantissa >>= num;
}
void HexStringParser::round(ThreadContext* ctx) throw() 
{
	String* result = abandonedNumber->replaceAll(ConstStr::getCNST_STR_362(), ConstStr::getCNST_STR_4(), ctx);
	bool moreThanZero = (result->length(ctx) > 0 ? true : false);
	int lastDiscardedBit = ((int)(mantissa & 1L));
	mantissa >>= 1;
	int tailBitInMantissa = ((int)(mantissa & 1L));
	if(lastDiscardedBit == 1 && (moreThanZero || tailBitInMantissa == 1))
	{
		int oldLength = countBitsLength(mantissa, ctx);
		mantissa += 1L;
		int newLength = countBitsLength(mantissa, ctx);
		if(oldLength >= MANTISSA_WIDTH && newLength > oldLength)
		{
			checkedAddExponent((long long)1, ctx);
		}
	}
}
String* HexStringParser::getNormalizedSignificand(String* strIntegerPart, String* strDecimalPart, ThreadContext* ctx) throw() 
{
	String* significand = strIntegerPart->clone(ctx)->append(strDecimalPart, ctx);
	significand = significand->replaceFirst(ConstStr::getCNST_STR_363(), ConstStr::getCNST_STR_4(), ctx);
	if(significand->length(ctx) == 0)
	{
		significand = ConstStr::getCNST_STR_9();
	}
	return significand;
}
int HexStringParser::getOffset(String* strIntegerPart, String* strDecimalPart, ThreadContext* ctx) throw() 
{
	strIntegerPart = strIntegerPart->replaceFirst(ConstStr::getCNST_STR_363(), ConstStr::getCNST_STR_4(), ctx);
	if(strIntegerPart->length(ctx) != 0)
	{
		String* leadingNumber = strIntegerPart->substring(0, 1, ctx);
		return (strIntegerPart->length(ctx) - 1) * 4 + countBitsLength(Long::parseLong(leadingNumber, HEX_RADIX, ctx), ctx) - 1;
	}
	int i = 0;
	for(i = 0; i < strDecimalPart->length(ctx) && strDecimalPart->charAt(i, ctx) == L'0'; i ++ )
	;
	if(i == strDecimalPart->length(ctx))
	{
		return 0;
	}
	String* leadingNumber = strDecimalPart->substring(i, i + 1, ctx);
	return (-i - 1) * 4 + countBitsLength(Long::parseLong(leadingNumber, HEX_RADIX, ctx), ctx) - 1;
}
int HexStringParser::countBitsLength(long long value, ThreadContext* ctx) throw() 
{
	int leadingZeros = Long::numberOfLeadingZeros(value, ctx);
	return Long::SIZE - leadingZeros;
}
double HexStringParser::parseDouble(String* hexString, ThreadContext* ctx)
{
	HexStringParser* parser = (new(ctx) HexStringParser(DOUBLE_EXPONENT_WIDTH, DOUBLE_MANTISSA_WIDTH, ctx));
	long long result = parser->parse(hexString, ctx);
	return Double::longBitsToDouble(result, ctx);
}
float HexStringParser::parseFloat(String* hexString, ThreadContext* ctx)
{
	HexStringParser* parser = (new(ctx) HexStringParser(FLOAT_EXPONENT_WIDTH, FLOAT_MANTISSA_WIDTH, ctx));
	int result = ((int)parser->parse(hexString, ctx));
	return Float::intBitsToFloat(result, ctx);
}
IArrayObject<String>* HexStringParser::getSegmentsFromHexString(String* hexString, ThreadContext* ctx)
{
	if(PATTERN == nullptr)
	{
		__GC_MV(nullptr, &(PATTERN), Pattern::compile(HEX_PATTERN, ctx), Pattern);
	}
	Matcher* matcher = PATTERN->matcher(hexString, ctx);
	if(!matcher->matches(ctx))
	{
		throw (new(ctx) NumberFormatException(ctx));
	}
	IArrayObject<String>* hexSegments = ArrayAllocator<String>::allocate(ctx, 3);
	hexSegments->set(matcher->group(1, ctx),0, ctx);
	hexSegments->set(matcher->group(2, ctx),1, ctx);
	hexSegments->set(matcher->group(3, ctx),2, ctx);
	return hexSegments;
}
}}

