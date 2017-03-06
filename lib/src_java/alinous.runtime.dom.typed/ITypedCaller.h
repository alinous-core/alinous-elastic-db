#ifndef ALINOUS_RUNTIME_DOM_TYPED_ITYPEDCALLER_H_
#define ALINOUS_RUNTIME_DOM_TYPED_ITYPEDCALLER_H_
namespace alinous{namespace annotation{
class OneSource;
}}
namespace alinous {namespace runtime {namespace dom {
class IAlinousVariable;}}}

namespace alinous {namespace system {
class AlinousException;}}

namespace java {namespace lang {
class IObject;
}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace runtime {namespace dom {namespace typed {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::alinous::runtime::dom::IAlinousVariable;
using ::alinous::system::AlinousException;



class ITypedCaller : public virtual IObject {
public:
	ITypedCaller(const ITypedCaller& base) = default;
public:
	ITypedCaller(ThreadContext* ctx) throw() ;
	void __construct_impl(ThreadContext* ctx) throw() ;
	virtual ~ITypedCaller() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
public:
	virtual IAlinousVariable* add(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx) = 0;
	virtual IAlinousVariable* minus(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx) = 0;
	virtual IAlinousVariable* multiply(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx) = 0;
	virtual IAlinousVariable* div(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx) = 0;
	virtual IAlinousVariable* shiftLeft(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx) = 0;
	virtual IAlinousVariable* shiftRight(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx) = 0;
	virtual IAlinousVariable* shiftRightUnsigned(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx) = 0;
	virtual IAlinousVariable* modulo(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx) = 0;
	virtual IAlinousVariable* substitute(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx) = 0;
	virtual int compareTo(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx) = 0;
	virtual IAlinousVariable* bitOr(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx) = 0;
	virtual IAlinousVariable* bitAnd(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx) = 0;
	virtual IAlinousVariable* bitExor(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx) = 0;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx);
};

}}}}

#endif /* end of ALINOUS_RUNTIME_DOM_TYPED_ITYPEDCALLER_H_ */
