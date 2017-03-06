#ifndef ALINOUS_NUMERIC_PRIMALITY_H_
#define ALINOUS_NUMERIC_PRIMALITY_H_
namespace alinous{namespace annotation{
class OneSource;
}}
namespace alinous {namespace numeric {
class BigInteger;}}

namespace java {namespace util {
class Random;}}

namespace java {namespace util {
class Arrays;}}

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
using ::java::util::Arrays;
using ::java::util::Random;



class Primality final : public virtual IObject {
public:
	Primality(const Primality& base) = default;
public:
	Primality(ThreadContext* ctx) throw() ;
	void __construct_impl(ThreadContext* ctx) throw() ;
	virtual ~Primality() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	static const StaticArrayObjectPrimitive<int> __primes;
	static IArrayObjectPrimitive<int>* primes;
	static IArrayObject<BigInteger>* BIprimes;
	static const StaticArrayObjectPrimitive<int> __BITS;
	static IArrayObjectPrimitive<int>* BITS;
	static IArrayObjectPrimitive<int>* a0;
	static IArrayObjectPrimitive<int>* a1;
	static const StaticArrayObjectPrimitive<int> __a2;
	static IArrayObjectPrimitive<int>* a2;
	static const StaticArrayObjectPrimitive<int> __a3;
	static IArrayObjectPrimitive<int>* a3;
	static const StaticArrayObjectPrimitive<int> __a4;
	static IArrayObjectPrimitive<int>* a4;
	static const StaticArrayObjectPrimitive<int> __a5;
	static IArrayObjectPrimitive<int>* a5;
	static const StaticArrayObjectPrimitive<int> __a6;
	static IArrayObjectPrimitive<int>* a6;
	static const StaticArrayObjectPrimitive<int> __a7;
	static IArrayObjectPrimitive<int>* a7;
	static const StaticArrayObjectPrimitive<int> __a8;
	static IArrayObjectPrimitive<int>* a8;
	static const StaticArrayObjectPrimitive<int> __a9;
	static IArrayObjectPrimitive<int>* a9;
	static const StaticArrayObjectPrimitive<int> __a10;
	static IArrayObjectPrimitive<int>* a10;
	static IArrayObject<IArrayObjectPrimitive<int>>* offsetPrimes;
public:
	static void initByBigInt(ThreadContext* ctx) throw() ;
	static BigInteger* nextProbablePrime(BigInteger* n, ThreadContext* ctx) throw() ;
	static BigInteger* consBigInteger(int bitLength, int certainty, Random* rnd, ThreadContext* ctx) throw() ;
	static bool isProbablePrime(BigInteger* n, int certainty, ThreadContext* ctx) throw() ;
private:
	static bool millerRabin(BigInteger* n, int t, ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx);
};

}}

#endif /* end of ALINOUS_NUMERIC_PRIMALITY_H_ */
