#ifndef ALINOUS_SYSTEM_FUNCTIONS_ALINOUSFUNCTIONMANAGER_H_
#define ALINOUS_SYSTEM_FUNCTIONS_ALINOUSFUNCTIONMANAGER_H_
namespace alinous{namespace annotation{
class OneSource;
}}
namespace alinous {namespace system {
class AlinousCore;}}

namespace alinous {namespace jdk {namespace functions {
class JavaFunctionManager;}}}

namespace alinous {namespace system {namespace functions {
class NativeFunctionManager;}}}

namespace alinous {namespace runtime {namespace function {
class IAlinousNativeFunction;}}}

namespace alinous {namespace compile {namespace expression {
class FunctionArguments;}}}

namespace alinous {namespace runtime {namespace engine {
class ScriptMachine;}}}

namespace alinous {namespace compile {namespace analyse {
class AlinousType;}}}

namespace alinous {namespace runtime {namespace dom {
class IAlinousVariable;}}}

namespace alinous {namespace runtime {namespace dom {
class IDomVariable;}}}

namespace alinous {namespace compile {namespace expression {
class IExpression;}}}

namespace alinous {namespace system {
class AlinousException;}}

namespace alinous {namespace runtime {namespace dom {
class VariableException;}}}

namespace java {namespace lang {
class Throwable;}}

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
using ::alinous::jdk::functions::JavaFunctionManager;
using ::alinous::runtime::dom::IAlinousVariable;
using ::alinous::runtime::dom::IDomVariable;
using ::alinous::runtime::dom::VariableException;
using ::alinous::runtime::engine::ScriptMachine;
using ::alinous::runtime::function::IAlinousNativeFunction;
using ::alinous::system::AlinousCore;
using ::alinous::system::AlinousException;



class AlinousFunctionManager final : public virtual IObject {
public:
	AlinousFunctionManager(const AlinousFunctionManager& base) = default;
public:
	AlinousFunctionManager(AlinousCore* core, ThreadContext* ctx) throw() ;
	void __construct_impl(AlinousCore* core, ThreadContext* ctx) throw() ;
	virtual ~AlinousFunctionManager() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	AlinousCore* core;
	JavaFunctionManager* javaFunctionManager;
	NativeFunctionManager* nativeFunctions;
public:
	bool isFunctionPrefix(String* name, ThreadContext* ctx) throw() ;
	bool isJavaFunction(String* prefix, String* funcName, ThreadContext* ctx) throw() ;
	bool isNativeFunction(String* prefix, String* funcName, ThreadContext* ctx) throw() ;
	bool invokeNativeFunction(IAlinousNativeFunction* func, FunctionArguments* arguments, ScriptMachine* machine, bool debug, ThreadContext* ctx);
	IAlinousNativeFunction* getNativeFunction(String* prefix, String* funcName, ThreadContext* ctx) throw() ;
	bool invokeFunction(String* prefix, String* funcName, FunctionArguments* arguments, ScriptMachine* machine, bool debug, ThreadContext* ctx);
	AlinousType* getFunctionReturnType(String* prefix, String* name, ThreadContext* ctx) throw() ;
	AlinousCore* getCore(ThreadContext* ctx) throw() ;
	void init(ThreadContext* ctx) throw() ;
	void dispose(ThreadContext* ctx) throw() ;
private:
	bool executeJavaConnector(String* prefix, String* funcName, FunctionArguments* expArguments, ScriptMachine* machine, bool debug, ThreadContext* ctx);
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}}

#endif /* end of ALINOUS_SYSTEM_FUNCTIONS_ALINOUSFUNCTIONMANAGER_H_ */
