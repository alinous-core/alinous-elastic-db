#ifndef ALINOUS_SYSTEM_FUNCTIONS_NATIVEFUNCTIONMANAGER_H_
#define ALINOUS_SYSTEM_FUNCTIONS_NATIVEFUNCTIONMANAGER_H_
namespace alinous{namespace annotation{
class OneSource;
}}
namespace alinous {namespace runtime {namespace function {
class AlinousNativeFunctionRegistory;}}}

namespace alinous {namespace runtime {namespace function {
class IAlinousNativeFunction;}}}

namespace alinous {namespace compile {namespace expression {
class FunctionArguments;}}}

namespace alinous {namespace runtime {namespace engine {
class ScriptMachine;}}}

namespace alinous {namespace compile {namespace analyse {
class AlinousType;}}}

namespace alinous {namespace system {
class AlinousException;}}

namespace alinous {namespace runtime {namespace dom {
class IAlinousVariable;}}}

namespace alinous {namespace compile {namespace expression {
class IExpression;}}}

namespace alinous {namespace db {namespace table {
class DatabaseException;}}}

namespace java {namespace lang {
class IObject;
}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace system {namespace functions {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::java::util::ArrayList;
using ::alinous::compile::analyse::AlinousType;
using ::alinous::compile::expression::FunctionArguments;
using ::alinous::compile::expression::IExpression;
using ::alinous::db::table::DatabaseException;
using ::alinous::runtime::dom::IAlinousVariable;
using ::alinous::runtime::engine::ScriptMachine;
using ::alinous::runtime::function::AlinousNativeFunctionRegistory;
using ::alinous::runtime::function::IAlinousNativeFunction;
using ::alinous::system::AlinousException;



class NativeFunctionManager final : public virtual IObject {
public:
	NativeFunctionManager(const NativeFunctionManager& base) = default;
public:
	NativeFunctionManager(ThreadContext* ctx) throw()  : IObject(ctx), nativesRegistory(nullptr)
	{
	}
	void __construct_impl(ThreadContext* ctx) throw() 
	{
	}
	virtual ~NativeFunctionManager() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	AlinousNativeFunctionRegistory* nativesRegistory;
public:
	void init(ThreadContext* ctx) throw() ;
	bool isNativeFunctionPrefix(String* prefix, ThreadContext* ctx) throw() ;
	bool isNativeFunction(String* prefix, String* funcName, ThreadContext* ctx) throw() ;
	IAlinousNativeFunction* getNativeFunction(String* prefix, String* funcName, ThreadContext* ctx) throw() ;
	bool invoke(String* prefix, String* funcName, FunctionArguments* arguments, ScriptMachine* machine, bool debug, ThreadContext* ctx);
	bool invoke(IAlinousNativeFunction* func, FunctionArguments* arguments, ScriptMachine* machine, bool debug, ThreadContext* ctx);
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}}

#endif /* end of ALINOUS_SYSTEM_FUNCTIONS_NATIVEFUNCTIONMANAGER_H_ */
