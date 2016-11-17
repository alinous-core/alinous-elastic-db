#ifndef JAVA_HARMONEY_HEXSTRINGPARSER_H_
#define JAVA_HARMONEY_HEXSTRINGPARSER_H_
namespace alinous{namespace annotation{
class HeaderOnly;
}}
namespace java {namespace harmoney {
class HexStringParser;}}

namespace com {namespace google {namespace re2j {
class Matcher;}}}

namespace java {namespace lang {
class NumberFormatException;}}

namespace com {namespace google {namespace re2j {
class Pattern;}}}

namespace java {namespace lang {
class Character;}}

namespace java {namespace lang {
class Double;}}

namespace java {namespace lang {
class Float;}}

namespace java {namespace lang {
class Long;}}

namespace com {namespace google {namespace re2j {
class PatternSyntaxException;}}}

namespace java {namespace lang {
class IObject;
}}

namespace alinous {
class ThreadContext;
}

namespace java {namespace harmoney {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::com::google::re2j::Matcher;
using ::com::google::re2j::Pattern;
using ::com::google::re2j::PatternSyntaxException;



class HexStringParser final : public virtual IObject {
public:
	HexStringParser(const HexStringParser& base) = default;
public:
	HexStringParser(int exponent_width, int mantissa_width, ThreadContext* ctx) throw() ;
	void __construct_impl(int exponent_width, int mantissa_width, ThreadContext* ctx) throw() ;
	virtual ~HexStringParser() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	int EXPONENT_WIDTH;
	int MANTISSA_WIDTH;
	long long EXPONENT_BASE;
	long long MAX_EXPONENT;
	long long MIN_EXPONENT;
	long long MANTISSA_MASK;
	long long sign;
	long long exponent;
	long long mantissa;
	String* abandonedNumber;
private:
	constexpr static const int DOUBLE_EXPONENT_WIDTH{11};
	constexpr static const int DOUBLE_MANTISSA_WIDTH{52};
	constexpr static const int FLOAT_EXPONENT_WIDTH{8};
	constexpr static const int FLOAT_MANTISSA_WIDTH{23};
	constexpr static const int HEX_RADIX{16};
	constexpr static const int MAX_SIGNIFICANT_LENGTH{15};
	static String* HEX_SIGNIFICANT;
	static String* BINARY_EXPONENT;
	static String* FLOAT_TYPE_SUFFIX;
	static String* HEX_PATTERN;
	static Pattern* PATTERN;
private:
	long long parse(String* hexString, ThreadContext* ctx);
	void parseHexSign(String* signStr, ThreadContext* ctx) throw() ;
	void parseExponent(String* exponentStr, ThreadContext* ctx) throw() ;
	void parseMantissa(String* significantStr, ThreadContext* ctx) throw() ;
	void setInfinite(ThreadContext* ctx) throw() ;
	void setZero(ThreadContext* ctx) throw() ;
	void checkedAddExponent(long long offset, ThreadContext* ctx) throw() ;
	void processNormalNumber(ThreadContext* ctx) throw() ;
	void processSubNormalNumber(ThreadContext* ctx) throw() ;
	void fitMantissaInDesiredWidth(int desiredWidth, ThreadContext* ctx) throw() ;
	void discardTrailingBits(long long num, ThreadContext* ctx) throw() ;
	void round(ThreadContext* ctx) throw() ;
	String* getNormalizedSignificand(String* strIntegerPart, String* strDecimalPart, ThreadContext* ctx) throw() ;
	int getOffset(String* strIntegerPart, String* strDecimalPart, ThreadContext* ctx) throw() ;
	int countBitsLength(long long value, ThreadContext* ctx) throw() ;
public:
	static double parseDouble(String* hexString, ThreadContext* ctx);
	static float parseFloat(String* hexString, ThreadContext* ctx);
private:
	static IArrayObject<String>* getSegmentsFromHexString(String* hexString, ThreadContext* ctx);
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
		GCUtils<String>::dec(nullptr, HexStringParser::HEX_PATTERN, ctx, __FILEW__, __LINE__, L"String");
		GCUtils<Pattern>::dec(nullptr, HexStringParser::PATTERN, ctx, __FILEW__, __LINE__, L"Pattern");
	}
};

}}

#endif /* end of JAVA_HARMONEY_HEXSTRINGPARSER_H_ */
