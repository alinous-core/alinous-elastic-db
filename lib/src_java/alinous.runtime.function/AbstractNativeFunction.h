#ifndef ALINOUS_RUNTIME_FUNCTION_ABSTRACTNATIVEFUNCTION_H_
#define ALINOUS_RUNTIME_FUNCTION_ABSTRACTNATIVEFUNCTION_H_
namespace alinous{namespace annotation{
class OneSource;
}}
namespace alinous {namespace compile {namespace analyse {
class AlinousType;}}}

namespace alinous {namespace runtime {namespace function {
class IAlinousNativeFunction;}}}

namespace java {namespace lang {
class IObject;
}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace runtime {namespace function {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::java::util::ArrayList;
using ::alinous::compile::analyse::AlinousType;



class AbstractNativeFunction : public IAlinousNativeFunction, public virtual IObject {
public:
	AbstractNativeFunction(const AbstractNativeFunction& base) = default;
public:
	AbstractNativeFunction(ThreadContext* ctx) throw() ;
	void __construct_impl(ThreadContext* ctx) throw() ;
	virtual ~AbstractNativeFunction() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
public:
	String* prefix;
	String* name;
	ArrayList<AlinousType>* argumentMetadata;
public:
	ArrayList<AlinousType>* getArgumentMetadata(ThreadContext* ctx) throw()  final;
	String* getPrefix(ThreadContext* ctx) throw()  final;
	String* getName(ThreadContext* ctx) throw()  final;
	AlinousType* makeDomType(ThreadContext* ctx) throw() ;
	AlinousType* makeByteType(ThreadContext* ctx) throw() ;
	AlinousType* makeShortType(ThreadContext* ctx) throw() ;
	AlinousType* makeCharType(ThreadContext* ctx) throw() ;
	AlinousType* makeIntType(ThreadContext* ctx) throw() ;
	AlinousType* makeLongType(ThreadContext* ctx) throw() ;
	AlinousType* makeFloatType(ThreadContext* ctx) throw() ;
	AlinousType* makeDoubleType(ThreadContext* ctx) throw() ;
	AlinousType* makeStringType(ThreadContext* ctx) throw() ;
	AlinousType* makeTimeType(ThreadContext* ctx) throw() ;
	AlinousType* makeTimestampType(ThreadContext* ctx) throw() ;
	AlinousType* makeBigDecimalType(ThreadContext* ctx) throw() ;
	AlinousType* makeVoidType(ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx);
};

}}}

#endif /* end of ALINOUS_RUNTIME_FUNCTION_ABSTRACTNATIVEFUNCTION_H_ */
