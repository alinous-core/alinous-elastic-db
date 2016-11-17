#ifndef ALINOUS_COMPILE_ANALYSE_SRCANALYSECONTEXT_H_
#define ALINOUS_COMPILE_ANALYSE_SRCANALYSECONTEXT_H_
namespace alinous{namespace annotation{
class OneSource;
}}
namespace alinous {namespace runtime {
class AlinousModule;}}

namespace alinous {namespace system {namespace functions {
class AlinousFunctionManager;}}}

namespace alinous {namespace compile {namespace sql {namespace functions {
class SQLFunctionManager;}}}}

namespace alinous {namespace compile {namespace analyse {
class SourceValidator;}}}

namespace alinous {namespace compile {namespace analyse {
class AlinousType;}}}

namespace alinous {namespace runtime {namespace function {
class IAlinousNativeFunction;}}}

namespace java {namespace lang {
class StringBuffer;}}

namespace alinous {namespace compile {namespace declare {namespace function {
class AlinousFunction;}}}}

namespace alinous {namespace compile {namespace analyse {
class ExpressionStreamResult;}}}

namespace alinous {namespace compile {namespace declare {
class AlinousClass;}}}

namespace alinous {namespace compile {namespace declare {
class AlinousName;}}}

namespace alinous {namespace compile {namespace analyse {
class VariableDeclareHolder;}}}

namespace java {namespace util {
template <typename  T> class Stack;}}

namespace alinous {namespace compile {namespace analyse {
class ClassDeclareHolder;}}}

namespace java {namespace lang {
class IObject;
}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace compile {namespace analyse {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::java::util::Stack;
using ::alinous::compile::declare::AlinousClass;
using ::alinous::compile::declare::AlinousName;
using ::alinous::compile::declare::function::AlinousFunction;
using ::alinous::compile::sql::functions::SQLFunctionManager;
using ::alinous::runtime::AlinousModule;
using ::alinous::runtime::function::IAlinousNativeFunction;
using ::alinous::system::functions::AlinousFunctionManager;



class SrcAnalyseContext final : public virtual IObject {
public:
	SrcAnalyseContext(const SrcAnalyseContext& base) = default;
public:
	SrcAnalyseContext(AlinousModule* module, AlinousFunctionManager* functionManager, SQLFunctionManager* sqlFunctionManager, ThreadContext* ctx) throw() ;
	void __construct_impl(AlinousModule* module, AlinousFunctionManager* functionManager, SQLFunctionManager* sqlFunctionManager, ThreadContext* ctx) throw() ;
	virtual ~SrcAnalyseContext() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
public:
	SQLFunctionManager* sqlFunctionManager;
private:
	Stack<VariableDeclareHolder>* variableDeclares;
	ClassDeclareHolder* classDeclareHolder;
	SourceValidator* sourceValidator;
	AlinousModule* module;
	AlinousFunctionManager* functionManager;
	Stack<ExpressionStreamResult>* expStreamStack;
public:
	AlinousType* getFunctionReturnType(String* prefix, String* name, ThreadContext* ctx) throw() ;
	IAlinousNativeFunction* getNativeFuncion(String* prefix, String* name, ThreadContext* ctx) throw() ;
	bool isJavaFunction(String* prefix, String* funcName, ThreadContext* ctx) throw() ;
	bool isNativeFunction(String* prefix, String* funcName, ThreadContext* ctx) throw() ;
	bool isSourceFunction(String* prefix, String* funcName, ThreadContext* ctx) throw() ;
	AlinousFunction* getSourceFunction(String* prefix, String* funcName, ThreadContext* ctx) throw() ;
	bool isFunctionPrefix(String* name, ThreadContext* ctx) throw() ;
	ExpressionStreamResult* getExpressionStreamResult(ThreadContext* ctx) throw() ;
	void newExpressionStream(ThreadContext* ctx) throw() ;
	ExpressionStreamResult* endExpressionStream(ThreadContext* ctx) throw() ;
	AlinousClass* findClassDeclare(AlinousName* className, ThreadContext* ctx) throw() ;
	void addClassDeclare(AlinousClass* clazz, ThreadContext* ctx) throw() ;
	void newStack(ThreadContext* ctx) throw() ;
	void endStack(ThreadContext* ctx) throw() ;
	VariableDeclareHolder* getCurrentStack(ThreadContext* ctx) throw() ;
	SourceValidator* getSourceValidator(ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}}

#endif /* end of ALINOUS_COMPILE_ANALYSE_SRCANALYSECONTEXT_H_ */
