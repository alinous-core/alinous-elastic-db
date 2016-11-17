#ifndef ALINOUS_NUMERIC_LOGICAL_H_
#define ALINOUS_NUMERIC_LOGICAL_H_
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



class Logical final : public virtual IObject {
public:
	Logical(const Logical& base) = default;
public:
	Logical(ThreadContext* ctx) throw()  : IObject(ctx)
	{
	}
	void __construct_impl(ThreadContext* ctx) throw() 
	{
	}
	virtual ~Logical() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
public:
	static BigInteger* _not(BigInteger* val, ThreadContext* ctx) throw() ;
	static BigInteger* _and(BigInteger* val, BigInteger* that, ThreadContext* ctx) throw() ;
	static BigInteger* andPositive(BigInteger* val, BigInteger* that, ThreadContext* ctx) throw() ;
	static BigInteger* andDiffSigns(BigInteger* positive, BigInteger* negative, ThreadContext* ctx) throw() ;
	static BigInteger* andNegative(BigInteger* longer, BigInteger* shorter, ThreadContext* ctx) throw() ;
	static BigInteger* andNot(BigInteger* val, BigInteger* that, ThreadContext* ctx) throw() ;
	static BigInteger* andNotPositive(BigInteger* val, BigInteger* that, ThreadContext* ctx) throw() ;
	static BigInteger* andNotPositiveNegative(BigInteger* positive, BigInteger* negative, ThreadContext* ctx) throw() ;
	static BigInteger* andNotNegativePositive(BigInteger* negative, BigInteger* positive, ThreadContext* ctx) throw() ;
	static BigInteger* andNotNegative(BigInteger* val, BigInteger* that, ThreadContext* ctx) throw() ;
	static BigInteger* _or(BigInteger* val, BigInteger* that, ThreadContext* ctx) throw() ;
	static BigInteger* orPositive(BigInteger* longer, BigInteger* shorter, ThreadContext* ctx) throw() ;
	static BigInteger* orNegative(BigInteger* val, BigInteger* that, ThreadContext* ctx) throw() ;
	static BigInteger* orDiffSigns(BigInteger* positive, BigInteger* negative, ThreadContext* ctx) throw() ;
	static BigInteger* _xor(BigInteger* val, BigInteger* that, ThreadContext* ctx) throw() ;
	static BigInteger* xorPositive(BigInteger* longer, BigInteger* shorter, ThreadContext* ctx) throw() ;
	static BigInteger* xorNegative(BigInteger* val, BigInteger* that, ThreadContext* ctx) throw() ;
	static BigInteger* xorDiffSigns(BigInteger* positive, BigInteger* negative, ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}

#endif /* end of ALINOUS_NUMERIC_LOGICAL_H_ */
