#ifndef ALINOUS_RUNTIME_FUNCTION_SYSTEM_SYSTEMPRINTLN_H_
#define ALINOUS_RUNTIME_FUNCTION_SYSTEM_SYSTEMPRINTLN_H_
namespace alinous{namespace annotation{
class OneSource;
}}
namespace alinous {namespace compile {namespace analyse {
class AlinousType;}}}

namespace alinous {namespace runtime {namespace dom {
class IAlinousVariable;}}}

namespace alinous {namespace runtime {namespace engine {
class ScriptMachine;}}}

namespace alinous {namespace runtime {namespace function {
class AbstractNativeFunction;}}}

namespace alinous {namespace system {
class AlinousException;}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace runtime {namespace function {namespace system {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::java::util::ArrayList;
using ::alinous::compile::analyse::AlinousType;
using ::alinous::runtime::dom::IAlinousVariable;
using ::alinous::runtime::engine::ScriptMachine;
using ::alinous::runtime::function::AbstractNativeFunction;
using ::alinous::system::AlinousException;



class SystemPrintLn final : public AbstractNativeFunction {
public:
	SystemPrintLn(const SystemPrintLn& base) = default;
public:
	SystemPrintLn(ThreadContext* ctx) throw() ;
	void __construct_impl(ThreadContext* ctx) throw() ;
	virtual ~SystemPrintLn() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
public:
	AlinousType* getReturnType(ThreadContext* ctx) throw()  final;
	void execute(ArrayList<IAlinousVariable>* args, ScriptMachine* machine, ThreadContext* ctx) final;
private:
	void doExecute(String* str, ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx);
};

}}}}

#endif /* end of ALINOUS_RUNTIME_FUNCTION_SYSTEM_SYSTEMPRINTLN_H_ */
