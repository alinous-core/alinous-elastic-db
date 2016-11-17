#ifndef ALINOUS_COMPILE_EXPRESSION_EXPSTREAM_FUNCTIONCALLEXPRESSION_H_
#define ALINOUS_COMPILE_EXPRESSION_EXPSTREAM_FUNCTIONCALLEXPRESSION_H_
namespace alinous{namespace annotation{
class NoBlankConstructor;
}}
namespace alinous{namespace annotation{
class OneSource;
}}
namespace alinous {namespace compile {
class IAlinousElementVisitor;}}

namespace alinous {namespace compile {
class AbstractSrcElement;}}

namespace alinous {namespace compile {namespace expression {
class FunctionArguments;}}}

namespace alinous {namespace compile {namespace analyse {
class SrcAnalyseContext;}}}

namespace alinous {namespace compile {namespace analyse {
class ExpressionStreamResult;}}}

namespace alinous {namespace compile {namespace analyse {
class AlinousType;}}}

namespace alinous {namespace compile {namespace declare {
class AlinousClass;}}}

namespace alinous {namespace runtime {namespace dom {
class IAlinousVariable;}}}

namespace alinous {namespace runtime {namespace engine {
class ScriptMachine;}}}

namespace alinous {namespace system {namespace functions {
class AlinousFunctionManager;}}}

namespace alinous {namespace system {
class AlinousNotSupportedException;}}

namespace alinous {namespace runtime {namespace dom {namespace clazz {
class AlinousClassVariable;}}}}

namespace alinous {namespace compile {namespace declare {
class ClassMethodFunction;}}}

namespace alinous {namespace compile {namespace declare {namespace function {
class AlinousFunction;}}}}

namespace alinous {namespace compile {namespace declare {namespace function {
class FunctionArgumentDefine;}}}}

namespace alinous {namespace compile {namespace expression {
class IExpression;}}}

namespace alinous {namespace system {
class AlinousException;}}

namespace alinous {namespace runtime {namespace engine {
class MainStackFrame;}}}

namespace alinous {namespace compile {namespace stmt {
class StatementList;}}}

namespace java {namespace lang {
class Throwable;}}

namespace alinous {namespace compile {
class ExpressionSourceId;}}

namespace alinous {namespace runtime {namespace function {
class IAlinousNativeFunction;}}}

namespace alinous {namespace compile {namespace expression {
class AbstractExpression;}}}

namespace alinous {namespace db {namespace table {
class DatabaseException;}}}

namespace alinous {namespace runtime {namespace engine {
class ScriptRunner;}}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace compile {namespace expression {namespace expstream {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::java::util::ArrayList;
using ::alinous::compile::AbstractSrcElement;
using ::alinous::compile::ExpressionSourceId;
using ::alinous::compile::IAlinousElementVisitor;
using ::alinous::compile::analyse::AlinousType;
using ::alinous::compile::analyse::ExpressionStreamResult;
using ::alinous::compile::analyse::SrcAnalyseContext;
using ::alinous::compile::declare::AlinousClass;
using ::alinous::compile::declare::ClassMethodFunction;
using ::alinous::compile::declare::function::AlinousFunction;
using ::alinous::compile::declare::function::FunctionArgumentDefine;
using ::alinous::compile::expression::AbstractExpression;
using ::alinous::compile::expression::FunctionArguments;
using ::alinous::compile::expression::IExpression;
using ::alinous::compile::stmt::StatementList;
using ::alinous::db::table::DatabaseException;
using ::alinous::runtime::dom::IAlinousVariable;
using ::alinous::runtime::dom::clazz::AlinousClassVariable;
using ::alinous::runtime::engine::MainStackFrame;
using ::alinous::runtime::engine::ScriptMachine;
using ::alinous::runtime::engine::ScriptRunner;
using ::alinous::runtime::function::IAlinousNativeFunction;
using ::alinous::system::AlinousException;
using ::alinous::system::AlinousNotSupportedException;
using ::alinous::system::functions::AlinousFunctionManager;



class FunctionCallExpression final : public AbstractExpression {
public:
	FunctionCallExpression(const FunctionCallExpression& base) = default;
public:
	FunctionCallExpression(ThreadContext* ctx) throw() ;
	void __construct_impl(ThreadContext* ctx) throw() ;
	virtual ~FunctionCallExpression() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
public:
	String* body;
private:
	FunctionArguments* arguments;
	int functionType;
	AlinousType* analysedType;
	AlinousFunction* sourceFunction;
	IAlinousNativeFunction* nativeFunction;
	ClassMethodFunction* memberMethod;
	String* javaFuncPrefix;
private:
	constexpr static const int SOURCE_FUNTION{0};
	constexpr static const int NATIVE_FUNTION{1};
	constexpr static const int JAVA_FUNTION{2};
	constexpr static const int CLASS_METHOD{3};
	constexpr static const int CLASS_STATIC_METHOD{4};
public:
	bool visit(IAlinousElementVisitor* visitor, AbstractSrcElement* parent, ThreadContext* ctx) throw()  final;
	bool isConstant(ThreadContext* ctx) throw()  final;
	FunctionArguments* getArguments(ThreadContext* ctx) throw() ;
	void setArguments(FunctionArguments* arguments, ThreadContext* ctx) throw() ;
	bool analyse(SrcAnalyseContext* context, bool leftValue, ThreadContext* ctx) throw()  final;
	IAlinousVariable* resolveExpression(ScriptMachine* machine, bool debug, ThreadContext* ctx) final;
	ExpressionSourceId* getSourceId(ThreadContext* ctx) throw()  final;
	int getExpressionType(ThreadContext* ctx) throw()  final;
private:
	bool analyseSourceAndJavaFunction(String* prefix, SrcAnalyseContext* context, ThreadContext* ctx) throw() ;
	IAlinousVariable* executeMemberMethod(ScriptMachine* machine, bool debug, ThreadContext* ctx);
	IAlinousVariable* executeStaticMethod(ScriptMachine* machine, bool debug, ThreadContext* ctx);
	IAlinousVariable* executeSourceFunction(AlinousFunction* func, ScriptMachine* machine, bool debug, ThreadContext* ctx);
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}}}

#endif /* end of ALINOUS_COMPILE_EXPRESSION_EXPSTREAM_FUNCTIONCALLEXPRESSION_H_ */
