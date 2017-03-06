#include "include/global.h"


#include "java.lang/Number.h"
#include "java.lang/Comparable.h"
#include "java.lang/Integer.h"
#include "com.google.re2j/PatternSyntaxException.h"
#include "java.harmoney/HexStringParser.h"
#include "java.harmoney/FloatingPointParser.h"
#include "java.lang/Double.h"
#include "java.harmoney/NumberConverter.h"

namespace java {namespace harmoney {





constexpr const int FloatingPointParser::FLOAT_MIN_EXP;
constexpr const int FloatingPointParser::FLOAT_MAX_EXP;
constexpr const int FloatingPointParser::DOUBLE_MIN_EXP;
constexpr const int FloatingPointParser::DOUBLE_MAX_EXP;
bool FloatingPointParser::__init_done = __init_static_variables();
bool FloatingPointParser::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"FloatingPointParser", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 FloatingPointParser::FloatingPointParser(ThreadContext* ctx) throw()  : IObject(ctx)
{
}
void FloatingPointParser::__construct_impl(ThreadContext* ctx) throw() 
{
}
 FloatingPointParser::~FloatingPointParser() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void FloatingPointParser::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
}
void FloatingPointParser::includes(HexStringParser* arg0, ThreadContext* ctx) throw() 
{
}
double FloatingPointParser::doparseDouble(String* s, ThreadContext* ctx)
{
	s = s->trim(ctx);
	int length = s->length(ctx);
	if(length == 0)
	{
		throw (new(ctx) NumberFormatException(s, ctx));
	}
	wchar_t last = s->charAt(length - 1, ctx);
	if((last == L'y') || (last == L'N'))
	{
		return parseDblName(s, length, ctx);
	}
	if(parseAsHex(s, ctx))
	{
		return HexStringParser::parseDouble(s, ctx);
	}
	FloatingPointParser::StringExponentPair* info = initialParse(s, length, ctx);
	if(ConstStr::getCNST_STR_9()->equals(info->s, ctx) || (info->e + info->s->length(ctx) - 1 < DOUBLE_MIN_EXP))
	{
		return info->negative ? -0.0 : 0.0;
	}
	if((info->e > DOUBLE_MAX_EXP) || (info->e + info->s->length(ctx) - 1 > DOUBLE_MAX_EXP))
	{
		return info->negative ? Double::NEGATIVE_INFINITY : Double::POSITIVE_INFINITY;
	}
	double result = parseDblImpl(info->s, info->e, ctx);
	if(info->negative)
	{
		result = -result;
	}
	return result;
}
double FloatingPointParser::parseDblImpl(String* s, int e, ThreadContext* ctx) throw() 
{
	double dvalue = ((double)Long::parseLong(s, ctx));
	if(e < 0)
	{
		int loop = e * (-1);
		for(int i = 0; i < loop; i ++ )
		{
			dvalue = dvalue / 10;
		}
	}
		else 
	{
		for(int i = 0; i < e; i ++ )
		{
			dvalue = dvalue * 10;
		}
	}
	return dvalue;
}
bool FloatingPointParser::parseAsHex(String* s, ThreadContext* ctx) throw() 
{
	int length = s->length(ctx);
	if(length < 2)
	{
		return false;
	}
	wchar_t first = s->charAt(0, ctx);
	wchar_t second = s->charAt(1, ctx);
	if(first == L'+' || first == L'-')
	{
		if(length < 3)
		{
			return false;
		}
		first = second;
		second = s->charAt(2, ctx);
	}
	return (first == L'0') && (second == L'x' || second == L'X');
}
double FloatingPointParser::parseDblName(String* namedDouble, int length, ThreadContext* ctx) throw() 
{
	if((length != 3) && (length != 4) && (length != 8) && (length != 9))
	{
		throw (new(ctx) NumberFormatException(ctx));
	}
	bool negative = false;
	int cmpstart = 0;
	switch(namedDouble->charAt(0, ctx)) {
	case L'-':
		negative = true;
		cmpstart = 1;
		break ;
	case L'+':
		cmpstart = 1;
		break ;
	default:
		break;
	}
	if(namedDouble->regionMatches(false, cmpstart, ConstStr::getCNST_STR_358(), 0, 8, ctx))
	{
		return negative ? Double::NEGATIVE_INFINITY : Double::POSITIVE_INFINITY;
	}
	if(namedDouble->regionMatches(false, cmpstart, ConstStr::getCNST_STR_359(), 0, 3, ctx))
	{
		return Double::NaN;
	}
	throw (new(ctx) NumberFormatException(ctx));
}
FloatingPointParser::StringExponentPair* FloatingPointParser::initialParse(String* s, int length, ThreadContext* ctx) throw() 
{
	bool negative = false;
	wchar_t c = 0;
	int start = 0;int end = 0;int decimal = 0;int shift = 0;
	int e = 0;
	start = 0;
	if(length == 0)
	{
		throw (new(ctx) NumberFormatException(s, ctx));
	}
	c = s->charAt(length - 1, ctx);
	if(c == L'D' || c == L'd' || c == L'F' || c == L'f')
	{
		length -- ;
		if(length == 0)
		{
			throw (new(ctx) NumberFormatException(s, ctx));
		}
	}
	end = Math::max(s->indexOf((int)L'E', ctx), s->indexOf((int)L'e', ctx), ctx);
	if(end > -1)
	{
		if(end + 1 == length)
		{
			throw (new(ctx) NumberFormatException(s, ctx));
		}
		int exponent_offset = end + 1;
		if(s->charAt(exponent_offset, ctx) == L'+')
		{
			if(s->charAt(exponent_offset + 1, ctx) == L'-')
			{
				throw (new(ctx) NumberFormatException(s, ctx));
			}
			exponent_offset ++ ;
			if(exponent_offset == length)
			{
				throw (new(ctx) NumberFormatException(s, ctx));
			}
		}
		String* strExp = s->substring(exponent_offset, length, ctx);
		{
			try
			{
				e = Integer::parseInt(strExp, ctx);
			}
			catch(NumberFormatException* ex)
			{
				wchar_t ch = 0;
				for(int i = 0; i < strExp->length(ctx); i ++ )
				{
					ch = strExp->charAt(i, ctx);
					if(ch < L'0' || ch > L'9')
					{
						if(i == 0 && ch == L'-')
						{
							continue;
						}
						throw (new(ctx) NumberFormatException(s, ctx));
					}
				}
				e = strExp->charAt(0, ctx) == L'-' ? Integer::MIN_VALUE : Integer::MAX_VALUE;
			}
		}
	}
		else 
	{
		end = length;
	}
	if(length == 0)
	{
		throw (new(ctx) NumberFormatException(s, ctx));
	}
	c = s->charAt(start, ctx);
	if(c == L'-')
	{
		++start;
		--length;
		negative = true;
	}
		else 
	{
		if(c == L'+')
		{
			++start;
			--length;
		}
	}
	if(length == 0)
	{
		throw (new(ctx) NumberFormatException(s, ctx));
	}
	decimal = s->indexOf((int)L'.', ctx);
	if(decimal > -1)
	{
		shift = end - decimal - 1;
		if(e >= 0 || e - Integer::MIN_VALUE > shift)
		{
			e -= shift;
		}
		s = s->substring(start, decimal, ctx)->clone(ctx)->append(s->substring(decimal + 1, end, ctx), ctx);
	}
		else 
	{
		s = s->substring(start, end, ctx);
	}
	length = s->length(ctx);
	if((length) == 0)
	{
		throw (new(ctx) NumberFormatException(ctx));
	}
	end = length;
	while(end > 1 && s->charAt(end - 1, ctx) == L'0')
	--end;
	start = 0;
	while(start < end - 1 && s->charAt(start, ctx) == L'0')
	start ++ ;
	if(end != length || start != 0)
	{
		shift = length - end;
		if(e <= 0 || Integer::MAX_VALUE - e > shift)
		{
			e += shift;
		}
		s = s->substring(start, end, ctx);
	}
	int APPROX_MIN_MAGNITUDE = -359;
	int MAX_DIGITS = 52;
	length = s->length(ctx);
	if(length > MAX_DIGITS && e < APPROX_MIN_MAGNITUDE)
	{
		int d = Math::min(APPROX_MIN_MAGNITUDE - e, length - 1, ctx);
		s = s->substring(0, length - d, ctx);
		e += d;
	}
	return (new(ctx) FloatingPointParser::StringExponentPair(s, e, negative, ctx));
}
void FloatingPointParser::__cleanUp(ThreadContext* ctx){
}
}}

namespace java {namespace harmoney {





bool FloatingPointParser::StringExponentPair::__init_done = __init_static_variables();
bool FloatingPointParser::StringExponentPair::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"FloatingPointParser::StringExponentPair", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 FloatingPointParser::StringExponentPair::StringExponentPair(String* s, int e, bool negative, ThreadContext* ctx) throw()  : IObject(ctx), s(nullptr), e(0), negative(0)
{
	__GC_MV(this, &(this->s), s, String);
	this->e = e;
	this->negative = negative;
}
void FloatingPointParser::StringExponentPair::__construct_impl(String* s, int e, bool negative, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->s), s, String);
	this->e = e;
	this->negative = negative;
}
 FloatingPointParser::StringExponentPair::~StringExponentPair() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void FloatingPointParser::StringExponentPair::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"StringExponentPair", L"~StringExponentPair");
	__e_obj1.add(this->s, this);
	s = nullptr;
	if(!prepare){
		return;
	}
}
void FloatingPointParser::StringExponentPair::__cleanUp(ThreadContext* ctx){
}
}}

