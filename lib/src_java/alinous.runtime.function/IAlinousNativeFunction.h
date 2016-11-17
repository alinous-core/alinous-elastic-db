#ifndef ALINOUS_RUNTIME_FUNCTION_IALINOUSNATIVEFUNCTION_H_
#define ALINOUS_RUNTIME_FUNCTION_IALINOUSNATIVEFUNCTION_H_
namespace alinous{namespace annotation{
class OneSource;
}}
namespace alinous {namespace compile {namespace analyse {
class AlinousType;}}}

namespace alinous {namespace runtime {namespace dom {
class IAlinousVariable;}}}

namespace alinous {namespace runtime {namespace engine {
class ScriptMachine;}}}

namespace alinous {namespace system {
class AlinousException;}}

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
using ::alinous::runtime::dom::IAlinousVariable;
using ::alinous::runtime::engine::ScriptMachine;
using ::alinous::system::AlinousException;



class IAlinousNativeFunction : public virtual IObject {
public:
	IAlinousNativeFunction(const IAlinousNativeFunction& base) = default;
public:
	IAlinousNativeFunction(ThreadContext* ctx) throw()  : IObject(ctx)
	{
	}
	void __construct_impl(ThreadContext* ctx) throw() 
	{
	}
	virtual ~IAlinousNativeFunction() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
public:
	virtual String* getPrefix(ThreadContext* ctx) throw()  = 0;
	virtual String* getName(ThreadContext* ctx) throw()  = 0;
	virtual ArrayList<AlinousType>* getArgumentMetadata(ThreadContext* ctx) throw()  = 0;
	virtual AlinousType* getReturnType(ThreadContext* ctx) throw()  = 0;
	virtual void execute(ArrayList<IAlinousVariable>* args, ScriptMachine* machine, ThreadContext* ctx) = 0;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}}

#endif /* end of ALINOUS_RUNTIME_FUNCTION_IALINOUSNATIVEFUNCTION_H_ */
