#ifndef ALINOUS_NUMERIC_ELEMENTARY_H_
#define ALINOUS_NUMERIC_ELEMENTARY_H_
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



class Elementary final : public virtual IObject {
public:
	Elementary(const Elementary& base) = default;
public:
	Elementary(ThreadContext* ctx) throw() ;
	void __construct_impl(ThreadContext* ctx) throw() ;
	virtual ~Elementary() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
public:
	static int compareArrays(IArrayObjectPrimitive<int>* a, IArrayObjectPrimitive<int>* b, int size, ThreadContext* ctx) throw() ;
	static BigInteger* add(BigInteger* op1, BigInteger* op2, ThreadContext* ctx) throw() ;
	static BigInteger* subtract(BigInteger* op1, BigInteger* op2, ThreadContext* ctx) throw() ;
	static void inplaceAdd(BigInteger* op1, BigInteger* op2, ThreadContext* ctx) throw() ;
	static int inplaceAdd(IArrayObjectPrimitive<int>* a, int aSize, int addend, ThreadContext* ctx) throw() ;
	static void inplaceAdd(BigInteger* op1, int addend, ThreadContext* ctx) throw() ;
	static void inplaceSubtract(BigInteger* op1, BigInteger* op2, ThreadContext* ctx) throw() ;
	static void completeInPlaceSubtract(BigInteger* op1, BigInteger* op2, ThreadContext* ctx) throw() ;
	static void completeInPlaceAdd(BigInteger* op1, BigInteger* op2, ThreadContext* ctx) throw() ;
private:
	static void add(IArrayObjectPrimitive<int>* res, IArrayObjectPrimitive<int>* a, int aSize, IArrayObjectPrimitive<int>* b, int bSize, ThreadContext* ctx) throw() ;
	static void subtract(IArrayObjectPrimitive<int>* res, IArrayObjectPrimitive<int>* a, int aSize, IArrayObjectPrimitive<int>* b, int bSize, ThreadContext* ctx) throw() ;
	static IArrayObjectPrimitive<int>* add(IArrayObjectPrimitive<int>* a, int aSize, IArrayObjectPrimitive<int>* b, int bSize, ThreadContext* ctx) throw() ;
	static void inverseSubtract(IArrayObjectPrimitive<int>* res, IArrayObjectPrimitive<int>* a, int aSize, IArrayObjectPrimitive<int>* b, int bSize, ThreadContext* ctx) throw() ;
	static IArrayObjectPrimitive<int>* subtract(IArrayObjectPrimitive<int>* a, int aSize, IArrayObjectPrimitive<int>* b, int bSize, ThreadContext* ctx) throw() ;
	static int unsignedArraysCompare(IArrayObjectPrimitive<int>* a, IArrayObjectPrimitive<int>* b, int aSize, int bSize, ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx);
};

}}

#endif /* end of ALINOUS_NUMERIC_ELEMENTARY_H_ */
