#ifndef ALINOUS_NUMERIC_BIGINTEGER_H_
#define ALINOUS_NUMERIC_BIGINTEGER_H_
namespace alinous{namespace annotation{
class OneSource;
}}
namespace alinous {namespace numeric {
class BigInteger;}}

namespace java {namespace util {
class Random;}}

namespace java {namespace lang {
class IllegalArgumentException;}}

namespace java {namespace lang {
class NullPointerException;}}

namespace java {namespace lang {
class NumberFormatException;}}

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
using ::java::util::Random;



class BigInteger final : public Number, public Comparable<BigInteger> {
public:
	BigInteger(const BigInteger& base) = default;
public:
	BigInteger(int numBits, Random* rnd, ThreadContext* ctx) throw() ;
	void __construct_impl(int numBits, Random* rnd, ThreadContext* ctx) throw() ;
	BigInteger(int bitLength, int certainty, Random* rnd, ThreadContext* ctx) throw() ;
	void __construct_impl(int bitLength, int certainty, Random* rnd, ThreadContext* ctx) throw() ;
	BigInteger(String* val, ThreadContext* ctx) throw() ;
	void __construct_impl(String* val, ThreadContext* ctx) throw() ;
	BigInteger(String* val, int radix, ThreadContext* ctx) throw() ;
	void __construct_impl(String* val, int radix, ThreadContext* ctx) throw() ;
	BigInteger(int signum, IArrayObjectPrimitive<char>* magnitude, ThreadContext* ctx) throw() ;
	void __construct_impl(int signum, IArrayObjectPrimitive<char>* magnitude, ThreadContext* ctx) throw() ;
	BigInteger(IArrayObjectPrimitive<char>* val, ThreadContext* ctx) throw() ;
	void __construct_impl(IArrayObjectPrimitive<char>* val, ThreadContext* ctx) throw() ;
	BigInteger(int sign, int value, ThreadContext* ctx) throw() ;
	void __construct_impl(int sign, int value, ThreadContext* ctx) throw() ;
	BigInteger(int sign, int numberLength, IArrayObjectPrimitive<int>* digits, ThreadContext* ctx) throw() ;
	void __construct_impl(int sign, int numberLength, IArrayObjectPrimitive<int>* digits, ThreadContext* ctx) throw() ;
	BigInteger(int sign, long long val, ThreadContext* ctx) throw() ;
	void __construct_impl(int sign, long long val, ThreadContext* ctx) throw() ;
	BigInteger(int signum, IArrayObjectPrimitive<int>* digits, ThreadContext* ctx) throw() ;
	void __construct_impl(int signum, IArrayObjectPrimitive<int>* digits, ThreadContext* ctx) throw() ;
	virtual ~BigInteger() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
public:
	IArrayObjectPrimitive<int>* digits;
	int numberLength;
	int sign;
private:
	int firstNonzeroDigit;
	int _hashCode;
public:
	static BigInteger* ZERO;
	static BigInteger* ONE;
	static BigInteger* TEN;
	static BigInteger* MINUS_ONE;
	constexpr static const int EQUALS{0};
	constexpr static const int GREATER{1};
	constexpr static const int LESS{-1};
	static IArrayObject<BigInteger>* SMALL_VALUES;
	static IArrayObject<BigInteger>* TWO_POWS;
public:
	IArrayObjectPrimitive<char>* toByteArray(ThreadContext* ctx) throw() ;
	BigInteger* abs(ThreadContext* ctx) throw() ;
	BigInteger* negate(ThreadContext* ctx) throw() ;
	BigInteger* add(BigInteger* val, ThreadContext* ctx) throw() ;
	BigInteger* subtract(BigInteger* val, ThreadContext* ctx) throw() ;
	int signum(ThreadContext* ctx) throw() ;
	BigInteger* shiftRight(int n, ThreadContext* ctx) throw() ;
	BigInteger* shiftLeft(int n, ThreadContext* ctx) throw() ;
	int bitLength(ThreadContext* ctx) throw() ;
	bool testBit(int n, ThreadContext* ctx) throw() ;
	BigInteger* setBit(int n, ThreadContext* ctx) throw() ;
	BigInteger* clearBit(int n, ThreadContext* ctx) throw() ;
	BigInteger* flipBit(int n, ThreadContext* ctx) throw() ;
	int getLowestSetBit(ThreadContext* ctx) throw() ;
	int bitCount(ThreadContext* ctx) throw() ;
	BigInteger* _not(ThreadContext* ctx) throw() ;
	BigInteger* _and(BigInteger* val, ThreadContext* ctx) throw() ;
	BigInteger* _or(BigInteger* val, ThreadContext* ctx) throw() ;
	BigInteger* _xor(BigInteger* val, ThreadContext* ctx) throw() ;
	BigInteger* andNot(BigInteger* val, ThreadContext* ctx) throw() ;
	int intValue(ThreadContext* ctx) throw()  final;
	long long longValue(ThreadContext* ctx) throw()  final;
	float floatValue(ThreadContext* ctx) throw()  final;
	double doubleValue(ThreadContext* ctx) throw()  final;
	int compareTo(BigInteger* val, ThreadContext* ctx) throw() ;
	BigInteger* min(BigInteger* val, ThreadContext* ctx) throw() ;
	BigInteger* max(BigInteger* val, ThreadContext* ctx) throw() ;
	int hashCode(ThreadContext* ctx) throw() ;
	bool equals(IObject* x, ThreadContext* ctx) throw() ;
	String* toString(ThreadContext* ctx) throw() ;
	String* toString(int radix, ThreadContext* ctx) throw() ;
	BigInteger* gcd(BigInteger* val, ThreadContext* ctx) throw() ;
	BigInteger* multiply(BigInteger* val, ThreadContext* ctx) throw() ;
	BigInteger* pow(int exp, ThreadContext* ctx) throw() ;
	IArrayObject<BigInteger>* divideAndRemainder(BigInteger* divisor, ThreadContext* ctx) throw() ;
	BigInteger* divide(BigInteger* divisor, ThreadContext* ctx) throw() ;
	BigInteger* remainder(BigInteger* divisor, ThreadContext* ctx) throw() ;
	BigInteger* modInverse(BigInteger* m, ThreadContext* ctx) throw() ;
	BigInteger* modPow(BigInteger* exponent, BigInteger* m, ThreadContext* ctx) throw() ;
	BigInteger* mod(BigInteger* m, ThreadContext* ctx) throw() ;
	bool isProbablePrime(int certainty, ThreadContext* ctx) throw() ;
	BigInteger* nextProbablePrime(ThreadContext* ctx) throw() ;
	BigInteger* shiftLeftOneBit(ThreadContext* ctx) throw() ;
	bool equalsArrays(IArrayObjectPrimitive<int>* b, ThreadContext* ctx) throw() ;
	void cutOffLeadingZeroes(ThreadContext* ctx) throw() ;
	bool isOne(ThreadContext* ctx) throw() ;
	int getFirstNonzeroDigit(ThreadContext* ctx) throw() ;
	BigInteger* copy(ThreadContext* ctx) throw() ;
	void unCache(ThreadContext* ctx) throw() ;
private:
	void putBytesPositiveToIntegers(IArrayObjectPrimitive<char>* byteValues, ThreadContext* ctx) throw() ;
	void putBytesNegativeToIntegers(IArrayObjectPrimitive<char>* byteValues, ThreadContext* ctx) throw() ;
public:
	static void staticInit(ThreadContext* ctx) throw() ;
	static BigInteger* valueOf(long long val, ThreadContext* ctx) throw() ;
	static BigInteger* probablePrime(int bitLength, Random* rnd, ThreadContext* ctx) throw() ;
	static BigInteger* getPowerOfTwo(int exp, ThreadContext* ctx) throw() ;
private:
	static void setFromString(BigInteger* bi, String* val, int radix, ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx);
	class ValueCompare {
	public:
		int operator() (BigInteger* _this, BigInteger* val, ThreadContext* ctx) const throw();
	};
};

}}

#endif /* end of ALINOUS_NUMERIC_BIGINTEGER_H_ */
