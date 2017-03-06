#ifndef ALINOUS_NUMERIC_DIVISION_H_
#define ALINOUS_NUMERIC_DIVISION_H_
namespace alinous{namespace annotation{
class OneSource;
}}
namespace alinous {namespace numeric {
class BigInteger;}}

namespace java {namespace lang {
class IObject;
}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace numeric {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;



class Division final : public virtual IObject {
public:
	Division(const Division& base) = default;
public:
	Division(ThreadContext* ctx) throw() ;
	void __construct_impl(ThreadContext* ctx) throw() ;
	virtual ~Division() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
public:
	static IArrayObjectPrimitive<int>* divide(IArrayObjectPrimitive<int>* quot, int quotLength, IArrayObjectPrimitive<int>* a, int aLength, IArrayObjectPrimitive<int>* b, int bLength, ThreadContext* ctx) throw() ;
	static int divideArrayByInt(IArrayObjectPrimitive<int>* dest, IArrayObjectPrimitive<int>* src, int srcLength, int divisor, ThreadContext* ctx) throw() ;
	static int remainderArrayByInt(IArrayObjectPrimitive<int>* src, int srcLength, int divisor, ThreadContext* ctx) throw() ;
	static int remainder(BigInteger* dividend, int divisor, ThreadContext* ctx) throw() ;
	static long long divideLongByInt(long long a, int b, ThreadContext* ctx) throw() ;
	static IArrayObject<BigInteger>* divideAndRemainderByInteger(BigInteger* val, int divisor, int divisorSign, ThreadContext* ctx) throw() ;
	static int multiplyAndSubtract(IArrayObjectPrimitive<int>* a, int start, IArrayObjectPrimitive<int>* b, int bLen, int c, ThreadContext* ctx) throw() ;
	static BigInteger* gcdBinary(BigInteger* op1, BigInteger* op2, ThreadContext* ctx) throw() ;
	static long long gcdBinary(long long op1, long long op2, ThreadContext* ctx) throw() ;
	static BigInteger* modInverseMontgomery(BigInteger* a, BigInteger* p, ThreadContext* ctx) throw() ;
	static BigInteger* squareAndMultiply(BigInteger* x2, BigInteger* a2, BigInteger* exponent, BigInteger* modulus, int n2, ThreadContext* ctx) throw() ;
	static BigInteger* modInverseHars(BigInteger* a, BigInteger* m, ThreadContext* ctx) throw() ;
	static BigInteger* slidingWindow(BigInteger* x2, BigInteger* a2, BigInteger* exponent, BigInteger* modulus, int n2, ThreadContext* ctx) throw() ;
	static BigInteger* oddModPow(BigInteger* base, BigInteger* exponent, BigInteger* modulus, ThreadContext* ctx) throw() ;
	static BigInteger* evenModPow(BigInteger* base, BigInteger* exponent, BigInteger* modulus, ThreadContext* ctx) throw() ;
	static BigInteger* pow2ModPow(BigInteger* base, BigInteger* exponent, int j, ThreadContext* ctx) throw() ;
	static BigInteger* monPro(BigInteger* a, BigInteger* b, BigInteger* modulus, int n2, ThreadContext* ctx) throw() ;
	static BigInteger* finalSubtraction(IArrayObjectPrimitive<int>* res, BigInteger* modulus, ThreadContext* ctx) throw() ;
	static BigInteger* modPow2Inverse(BigInteger* x, int n, ThreadContext* ctx) throw() ;
	static void inplaceModPow2(BigInteger* x, int n, ThreadContext* ctx) throw() ;
private:
	static int calcN(BigInteger* a, ThreadContext* ctx) throw() ;
	static void monReduction(IArrayObjectPrimitive<int>* res, BigInteger* modulus, int n2, ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx);
};

}}

#endif /* end of ALINOUS_NUMERIC_DIVISION_H_ */
