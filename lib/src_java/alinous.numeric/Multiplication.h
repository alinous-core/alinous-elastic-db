#ifndef ALINOUS_NUMERIC_MULTIPLICATION_H_
#define ALINOUS_NUMERIC_MULTIPLICATION_H_
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



class Multiplication final : public virtual IObject {
public:
	Multiplication(const Multiplication& base) = default;
public:
	Multiplication(ThreadContext* ctx) throw() ;
	void __construct_impl(ThreadContext* ctx) throw() ;
	virtual ~Multiplication() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
public:
	constexpr static const int whenUseKaratsuba{63};
	static const StaticArrayObjectPrimitive<int> __tenPows;
	static IArrayObjectPrimitive<int>* tenPows;
	static const StaticArrayObjectPrimitive<int> __fivePows;
	static IArrayObjectPrimitive<int>* fivePows;
	static IArrayObject<BigInteger>* bigTenPows;
	static IArrayObject<BigInteger>* bigFivePows;
public:
	static void initByBigInt(ThreadContext* ctx) throw() ;
	static BigInteger* multiply(BigInteger* x, BigInteger* y, ThreadContext* ctx) throw() ;
	static BigInteger* karatsuba(BigInteger* op1, BigInteger* op2, ThreadContext* ctx) throw() ;
	static BigInteger* multiplyPAP(BigInteger* a, BigInteger* b, ThreadContext* ctx) throw() ;
	static void multArraysPAP(IArrayObjectPrimitive<int>* aDigits, int aLen, IArrayObjectPrimitive<int>* bDigits, int bLen, IArrayObjectPrimitive<int>* resDigits, ThreadContext* ctx) throw() ;
	static void multPAP(IArrayObjectPrimitive<int>* a, IArrayObjectPrimitive<int>* b, IArrayObjectPrimitive<int>* t, int aLen, int bLen, ThreadContext* ctx) throw() ;
	static int multiplyByInt(IArrayObjectPrimitive<int>* a, int aSize, int factor, ThreadContext* ctx) throw() ;
	static BigInteger* multiplyByPositiveInt(BigInteger* val, int factor, ThreadContext* ctx) throw() ;
	static BigInteger* pow(BigInteger* base, int exponent, ThreadContext* ctx) throw() ;
	static IArrayObjectPrimitive<int>* square(IArrayObjectPrimitive<int>* a, int aLen, IArrayObjectPrimitive<int>* res, ThreadContext* ctx) throw() ;
	static BigInteger* multiplyByTenPow(BigInteger* val, long long exp, ThreadContext* ctx) throw() ;
	static BigInteger* powerOf10(long long exp, ThreadContext* ctx) throw() ;
	static BigInteger* multiplyByFivePow(BigInteger* val, int exp, ThreadContext* ctx) throw() ;
	static long long unsignedMultAddAdd(int a, int b, int c, int d, ThreadContext* ctx) throw() ;
private:
	static int multiplyByInt(IArrayObjectPrimitive<int>* res, IArrayObjectPrimitive<int>* a, int aSize, int factor, ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx);
};

}}

#endif /* end of ALINOUS_NUMERIC_MULTIPLICATION_H_ */
