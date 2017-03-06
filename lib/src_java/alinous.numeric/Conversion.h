#ifndef ALINOUS_NUMERIC_CONVERSION_H_
#define ALINOUS_NUMERIC_CONVERSION_H_
namespace alinous{namespace annotation{
class OneSource;
}}
namespace alinous {namespace numeric {
class BigInteger;}}

namespace java {namespace lang {
class StringBuilder;}}

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



class Conversion final : public virtual IObject {
public:
	Conversion(const Conversion& base) = default;
public:
	Conversion(ThreadContext* ctx) throw() ;
	void __construct_impl(ThreadContext* ctx) throw() ;
	virtual ~Conversion() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
public:
	static const StaticArrayObjectPrimitive<int> __digitFitInInt;
	static IArrayObjectPrimitive<int>* digitFitInInt;
	static const StaticArrayObjectPrimitive<int> __bigRadices;
	static IArrayObjectPrimitive<int>* bigRadices;
public:
	static String* bigInteger2String(BigInteger* val, int radix, ThreadContext* ctx) throw() ;
	static String* toDecimalScaledString(BigInteger* val, int scale, ThreadContext* ctx) throw() ;
	static String* toDecimalScaledString(long long value, int scale, ThreadContext* ctx) throw() ;
	static long long divideLongByBillion(long long a, ThreadContext* ctx) throw() ;
	static double bigInteger2Double(BigInteger* val, ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx);
};

}}

#endif /* end of ALINOUS_NUMERIC_CONVERSION_H_ */
