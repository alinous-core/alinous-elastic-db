#ifndef ALINOUS_NUMERIC_BITLEVEL_H_
#define ALINOUS_NUMERIC_BITLEVEL_H_
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



class BitLevel final : public virtual IObject {
public:
	BitLevel(const BitLevel& base) = default;
public:
	BitLevel(ThreadContext* ctx) throw()  : IObject(ctx)
	{
	}
	void __construct_impl(ThreadContext* ctx) throw() 
	{
	}
	virtual ~BitLevel() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
public:
	static int bitLength(BigInteger* val, ThreadContext* ctx) throw() ;
	static int bitCount(BigInteger* val, ThreadContext* ctx) throw() ;
	static bool testBit(BigInteger* val, int n, ThreadContext* ctx) throw() ;
	static bool nonZeroDroppedBits(int numberOfBits, IArrayObjectPrimitive<int>* digits, ThreadContext* ctx) throw() ;
	static BigInteger* shiftLeft(BigInteger* source, int count, ThreadContext* ctx) throw() ;
	static void inplaceShiftLeft(BigInteger* val, int count, ThreadContext* ctx) throw() ;
	static void shiftLeft(IArrayObjectPrimitive<int>* result, IArrayObjectPrimitive<int>* source, int intCount, int count, ThreadContext* ctx) throw() ;
	static void shiftLeftOneBit(IArrayObjectPrimitive<int>* result, IArrayObjectPrimitive<int>* source, int srcLen, ThreadContext* ctx) throw() ;
	static BigInteger* shiftLeftOneBit(BigInteger* source, ThreadContext* ctx) throw() ;
	static BigInteger* shiftRight(BigInteger* source, int count, ThreadContext* ctx) throw() ;
	static void inplaceShiftRight(BigInteger* val, int count, ThreadContext* ctx) throw() ;
	static bool shiftRight(IArrayObjectPrimitive<int>* result, int resultLen, IArrayObjectPrimitive<int>* source, int intCount, int count, ThreadContext* ctx) throw() ;
	static BigInteger* flipBit(BigInteger* val, int n, ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}

#endif /* end of ALINOUS_NUMERIC_BITLEVEL_H_ */
