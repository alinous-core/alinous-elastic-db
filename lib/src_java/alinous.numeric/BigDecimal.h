#ifndef ALINOUS_NUMERIC_BIGDECIMAL_H_
#define ALINOUS_NUMERIC_BIGDECIMAL_H_
namespace alinous{namespace annotation{
class OneSource;
}}
namespace alinous {namespace numeric {
class BigDecimal;}}

namespace java {namespace lang {
class StringBuilder;}}

namespace java {namespace lang {
class NullPointerException;}}

namespace java {namespace lang {
class NumberFormatException;}}

namespace alinous {namespace numeric {
class BigInteger;}}

namespace alinous {namespace numeric {
class MathContext;}}

namespace alinous {namespace numeric {
class RoundingMode;}}

namespace alinous {namespace lock {
class LockObject;}}

namespace java {namespace lang {
class Number;}}

namespace java {namespace lang {
template <typename  T> class Comparable;}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace numeric {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::alinous::lock::LockObject;



class BigDecimal final : public Number, public Comparable<BigDecimal> {
public:
	BigDecimal(const BigDecimal& base) = default;
public:
	BigDecimal(long long smallValue, int scale, ThreadContext* ctx) throw() ;
	void __construct_impl(long long smallValue, int scale, ThreadContext* ctx) throw() ;
	BigDecimal(int smallValue, int scale, ThreadContext* ctx) throw() ;
	void __construct_impl(int smallValue, int scale, ThreadContext* ctx) throw() ;
	BigDecimal(IArrayObjectPrimitive<wchar_t>* in, int offset, int len, ThreadContext* ctx) throw() ;
	void __construct_impl(IArrayObjectPrimitive<wchar_t>* in, int offset, int len, ThreadContext* ctx) throw() ;
	BigDecimal(IArrayObjectPrimitive<wchar_t>* in, int offset, int len, MathContext* mc, ThreadContext* ctx) throw() ;
	void __construct_impl(IArrayObjectPrimitive<wchar_t>* in, int offset, int len, MathContext* mc, ThreadContext* ctx) throw() ;
	BigDecimal(IArrayObjectPrimitive<wchar_t>* in, ThreadContext* ctx) throw() ;
	void __construct_impl(IArrayObjectPrimitive<wchar_t>* in, ThreadContext* ctx) throw() ;
	BigDecimal(IArrayObjectPrimitive<wchar_t>* in, MathContext* mc, ThreadContext* ctx) throw() ;
	void __construct_impl(IArrayObjectPrimitive<wchar_t>* in, MathContext* mc, ThreadContext* ctx) throw() ;
	BigDecimal(String* val, ThreadContext* ctx) throw() ;
	void __construct_impl(String* val, ThreadContext* ctx) throw() ;
	BigDecimal(String* val, MathContext* mc, ThreadContext* ctx) throw() ;
	void __construct_impl(String* val, MathContext* mc, ThreadContext* ctx) throw() ;
	BigDecimal(double val, ThreadContext* ctx) throw() ;
	void __construct_impl(double val, ThreadContext* ctx) throw() ;
	BigDecimal(double val, MathContext* mc, ThreadContext* ctx) throw() ;
	void __construct_impl(double val, MathContext* mc, ThreadContext* ctx) throw() ;
	BigDecimal(BigInteger* val, ThreadContext* ctx) throw() ;
	void __construct_impl(BigInteger* val, ThreadContext* ctx) throw() ;
	BigDecimal(BigInteger* val, MathContext* mc, ThreadContext* ctx) throw() ;
	void __construct_impl(BigInteger* val, MathContext* mc, ThreadContext* ctx) throw() ;
	BigDecimal(BigInteger* unscaledVal, int scale, ThreadContext* ctx) throw() ;
	void __construct_impl(BigInteger* unscaledVal, int scale, ThreadContext* ctx) throw() ;
	BigDecimal(BigInteger* unscaledVal, int scale, MathContext* mc, ThreadContext* ctx) throw() ;
	void __construct_impl(BigInteger* unscaledVal, int scale, MathContext* mc, ThreadContext* ctx) throw() ;
	BigDecimal(int val, ThreadContext* ctx) throw() ;
	void __construct_impl(int val, ThreadContext* ctx) throw() ;
	BigDecimal(int val, MathContext* mc, ThreadContext* ctx) throw() ;
	void __construct_impl(int val, MathContext* mc, ThreadContext* ctx) throw() ;
	BigDecimal(long long val, ThreadContext* ctx) throw() ;
	void __construct_impl(long long val, ThreadContext* ctx) throw() ;
	BigDecimal(long long val, MathContext* mc, ThreadContext* ctx) throw() ;
	void __construct_impl(long long val, MathContext* mc, ThreadContext* ctx) throw() ;
	virtual ~BigDecimal() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	String* toStringImage;
	int _hashCode;
	BigInteger* intVal;
	int _bitLength;
	long long smallValue;
	int _scale;
	int _precision;
public:
	static BigDecimal* ZERO;
	static BigDecimal* ONE;
	static BigDecimal* TEN;
	constexpr static const int ROUND_UP{0};
	constexpr static const int ROUND_DOWN{1};
	constexpr static const int ROUND_CEILING{2};
	constexpr static const int ROUND_FLOOR{3};
	constexpr static const int ROUND_HALF_UP{4};
	constexpr static const int ROUND_HALF_DOWN{5};
	constexpr static const int ROUND_HALF_EVEN{6};
	constexpr static const int ROUND_UNNECESSARY{7};
private:
	constexpr static const double LOG10_2{0.3010299956639812};
	static IArrayObject<BigInteger>* FIVE_POW;
	static IArrayObject<BigInteger>* TEN_POW;
	static const StaticArrayObjectPrimitive<long long> __LONG_TEN_POW;
	static IArrayObjectPrimitive<long long>* LONG_TEN_POW;
	static const StaticArrayObjectPrimitive<long long> __LONG_FIVE_POW;
	static IArrayObjectPrimitive<long long>* LONG_FIVE_POW;
	static IArrayObjectPrimitive<int>* LONG_FIVE_POW_BIT_LENGTH;
	static IArrayObjectPrimitive<int>* LONG_TEN_POW_BIT_LENGTH;
	constexpr static const int BI_SCALED_BY_ZERO_LENGTH{11};
	static IArrayObject<BigDecimal>* BI_SCALED_BY_ZERO;
	static IArrayObject<BigDecimal>* ZERO_SCALED_BY;
	static IArrayObjectPrimitive<wchar_t>* CH_ZEROS;
	static LockObject* initLock;
	static bool initBigDecimalDone;
public:
	BigDecimal* add(BigDecimal* augend, ThreadContext* ctx) throw() ;
	BigDecimal* add(BigDecimal* augend, MathContext* mc, ThreadContext* ctx) throw() ;
	BigDecimal* subtract(BigDecimal* subtrahend, ThreadContext* ctx) throw() ;
	BigDecimal* subtract(BigDecimal* subtrahend, MathContext* mc, ThreadContext* ctx) throw() ;
	BigDecimal* multiply(BigDecimal* multiplicand, ThreadContext* ctx) throw() ;
	BigDecimal* multiply(BigDecimal* multiplicand, MathContext* mc, ThreadContext* ctx) throw() ;
	BigDecimal* divide(BigDecimal* divisor, int scale, int roundingMode, ThreadContext* ctx) throw() ;
	BigDecimal* divide(BigDecimal* divisor, int scale, RoundingMode* roundingMode, ThreadContext* ctx) throw() ;
	BigDecimal* divide(BigDecimal* divisor, int roundingMode, ThreadContext* ctx) throw() ;
	BigDecimal* divide(BigDecimal* divisor, RoundingMode* roundingMode, ThreadContext* ctx) throw() ;
	BigDecimal* divide(BigDecimal* divisor, ThreadContext* ctx) throw() ;
	BigDecimal* divide(BigDecimal* divisor, MathContext* mc, ThreadContext* ctx) throw() ;
	BigDecimal* divideToIntegralValue(BigDecimal* divisor, ThreadContext* ctx) throw() ;
	BigDecimal* divideToIntegralValue(BigDecimal* divisor, MathContext* mc, ThreadContext* ctx) throw() ;
	BigDecimal* remainder(BigDecimal* divisor, ThreadContext* ctx) throw() ;
	BigDecimal* remainder(BigDecimal* divisor, MathContext* mc, ThreadContext* ctx) throw() ;
	IArrayObject<BigDecimal>* divideAndRemainder(BigDecimal* divisor, ThreadContext* ctx) throw() ;
	IArrayObject<BigDecimal>* divideAndRemainder(BigDecimal* divisor, MathContext* mc, ThreadContext* ctx) throw() ;
	BigDecimal* pow(int n, ThreadContext* ctx) throw() ;
	BigDecimal* pow(int n, MathContext* mc, ThreadContext* ctx) throw() ;
	BigDecimal* abs(ThreadContext* ctx) throw() ;
	BigDecimal* abs(MathContext* mc, ThreadContext* ctx) throw() ;
	BigDecimal* negate(ThreadContext* ctx) throw() ;
	BigDecimal* negate(MathContext* mc, ThreadContext* ctx) throw() ;
	BigDecimal* plus(ThreadContext* ctx) throw() ;
	BigDecimal* plus(MathContext* mc, ThreadContext* ctx) throw() ;
	int signum(ThreadContext* ctx) throw() ;
	int scale(ThreadContext* ctx) throw() ;
	int precision(ThreadContext* ctx) throw() ;
	BigInteger* unscaledValue(ThreadContext* ctx) throw() ;
	BigDecimal* round(MathContext* mc, ThreadContext* ctx) throw() ;
	BigDecimal* setScale(int newScale, RoundingMode* roundingMode, ThreadContext* ctx) throw() ;
	BigDecimal* setScale(int newScale, int roundingMode, ThreadContext* ctx) throw() ;
	BigDecimal* setScale(int newScale, ThreadContext* ctx) throw() ;
	BigDecimal* movePointLeft(int n, ThreadContext* ctx) throw() ;
	BigDecimal* movePointRight(int n, ThreadContext* ctx) throw() ;
	BigDecimal* scaleByPowerOfTen(int n, ThreadContext* ctx) throw() ;
	BigDecimal* stripTrailingZeros(ThreadContext* ctx) throw() ;
	int compareTo(BigDecimal* val, ThreadContext* ctx) throw() ;
	bool equals(IObject* x, ThreadContext* ctx) throw() ;
	BigDecimal* min(BigDecimal* val, ThreadContext* ctx) throw() ;
	BigDecimal* max(BigDecimal* val, ThreadContext* ctx) throw() ;
	int hashCode(ThreadContext* ctx) throw() ;
	String* toString(ThreadContext* ctx) throw() ;
	String* toEngineeringString(ThreadContext* ctx) throw() ;
	String* toPlainString(ThreadContext* ctx) throw() ;
	BigInteger* toBigInteger(ThreadContext* ctx) throw() ;
	BigInteger* toBigIntegerExact(ThreadContext* ctx) throw() ;
	long long longValue(ThreadContext* ctx) throw()  final;
	long long longValueExact(ThreadContext* ctx) throw() ;
	int intValue(ThreadContext* ctx) throw()  final;
	int intValueExact(ThreadContext* ctx) throw() ;
	short shortValueExact(ThreadContext* ctx) throw() ;
	char byteValueExact(ThreadContext* ctx) throw() ;
	float floatValue(ThreadContext* ctx) throw()  final;
	double doubleValue(ThreadContext* ctx) throw()  final;
	BigDecimal* ulp(ThreadContext* ctx) throw() ;
private:
	bool isZero(ThreadContext* ctx) throw() ;
	BigDecimal* movePoint(long long newScale, ThreadContext* ctx) throw() ;
	void inplaceRound(MathContext* mc, ThreadContext* ctx) throw() ;
	void smallRound(MathContext* mc, int discardedPrecision, ThreadContext* ctx) throw() ;
	long long valueExact(int bitLengthOfType, ThreadContext* ctx) throw() ;
	int aproxPrecision(ThreadContext* ctx) throw() ;
	BigInteger* getUnscaledValue(ThreadContext* ctx) throw() ;
	void setUnscaledValue(BigInteger* unscaledValue, ThreadContext* ctx) throw() ;
public:
	static void initBigDecimal(ThreadContext* ctx) throw() ;
	static BigDecimal* valueOf(long long unscaledVal, int scale, ThreadContext* ctx) throw() ;
	static BigDecimal* valueOf(long long unscaledVal, ThreadContext* ctx) throw() ;
	static BigDecimal* valueOf(double val, ThreadContext* ctx) throw() ;
private:
	static BigDecimal* addAndMult10(BigDecimal* thisValue, BigDecimal* augend, int diffScale, ThreadContext* ctx) throw() ;
	static BigDecimal* divideBigIntegers(BigInteger* scaledDividend, BigInteger* scaledDivisor, int scale, RoundingMode* roundingMode, ThreadContext* ctx) throw() ;
	static BigDecimal* dividePrimitiveLongs(long long scaledDividend, long long scaledDivisor, int scale, RoundingMode* roundingMode, ThreadContext* ctx) throw() ;
	static int longCompareTo(long long value1, long long value2, ThreadContext* ctx) throw() ;
	static int roundingBehavior(int parityBit, int fraction, RoundingMode* roundingMode, ThreadContext* ctx) throw() ;
	static int toIntScale(long long longScale, ThreadContext* ctx) throw() ;
	static BigDecimal* zeroScaledBy(long long longScale, ThreadContext* ctx) throw() ;
	static int bitLength(long long smallValue, ThreadContext* ctx) throw() ;
	static int bitLength(int smallValue, ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
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
	class ValueCompare {
	public:
		int operator() (BigDecimal* _this, BigDecimal* val, ThreadContext* ctx) const throw();
	};
};

}}

#endif /* end of ALINOUS_NUMERIC_BIGDECIMAL_H_ */
