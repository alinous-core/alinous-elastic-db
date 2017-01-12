#ifndef ALINOUS_COMPILE_EXPRESSION_FUNCTIONARGUMENTS_H_
#define ALINOUS_COMPILE_EXPRESSION_FUNCTIONARGUMENTS_H_
namespace alinous{namespace annotation{
class OneSource;
}}
namespace alinous {namespace compile {
class IAlinousElementVisitor;}}

namespace alinous {namespace compile {
class AbstractSrcElement;}}

namespace alinous {namespace compile {namespace analyse {
class SrcAnalyseContext;}}}

namespace alinous {namespace compile {namespace expression {
class IExpression;}}}

namespace alinous {namespace runtime {namespace dom {
class IAlinousVariable;}}}

namespace alinous {namespace runtime {namespace engine {
class ScriptMachine;}}}

namespace alinous {namespace system {
class AlinousNotSupportedException;}}

namespace alinous {namespace compile {
class ExpressionSourceId;}}

namespace alinous {namespace remote {namespace socket {
class NetworkBinaryBuffer;}}}

namespace alinous {namespace compile {
class IAlinousElement;}}

namespace alinous {namespace runtime {namespace dom {
class VariableException;}}}

namespace alinous {namespace compile {namespace expression {
class AbstractExpression;}}}

namespace alinous {namespace compile {
class AlinousElementNetworkFactory;}}

namespace alinous {namespace remote {namespace socket {
class ICommandData;}}}

namespace alinous {namespace system {
class AlinousException;}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace compile {namespace expression {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::java::util::ArrayList;
using ::alinous::compile::AbstractSrcElement;
using ::alinous::compile::AlinousElementNetworkFactory;
using ::alinous::compile::ExpressionSourceId;
using ::alinous::compile::IAlinousElement;
using ::alinous::compile::IAlinousElementVisitor;
using ::alinous::compile::analyse::SrcAnalyseContext;
using ::alinous::remote::socket::ICommandData;
using ::alinous::remote::socket::NetworkBinaryBuffer;
using ::alinous::runtime::dom::IAlinousVariable;
using ::alinous::runtime::dom::VariableException;
using ::alinous::runtime::engine::ScriptMachine;
using ::alinous::system::AlinousException;
using ::alinous::system::AlinousNotSupportedException;



class FunctionArguments final : public AbstractExpression {
public:
	FunctionArguments(const FunctionArguments& base) = default;
public:
	FunctionArguments(ThreadContext* ctx) throw()  : IObject(ctx), AbstractExpression(ctx), arguments(GCUtils<ArrayList<IExpression> >::ins(this, (new(ctx) ArrayList<IExpression>(ctx)), ctx, __FILEW__, __LINE__, L""))
	{
	}
	void __construct_impl(ThreadContext* ctx) throw() 
	{
	}
	virtual ~FunctionArguments() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
public:
	ArrayList<IExpression>* arguments;
public:
	bool visit(IAlinousElementVisitor* visitor, AbstractSrcElement* parent, ThreadContext* ctx) throw()  final;
	bool isConstant(ThreadContext* ctx) throw()  final;
	bool analyse(SrcAnalyseContext* context, bool leftValue, ThreadContext* ctx) throw()  final;
	void addArgument(IExpression* exp, ThreadContext* ctx) throw() ;
	int getArgumentSize(ThreadContext* ctx) throw() ;
	IAlinousVariable* resolveExpression(ScriptMachine* machine, bool debug, ThreadContext* ctx) final;
	ExpressionSourceId* getSourceId(ThreadContext* ctx) throw()  final;
	bool isSQLExp(ThreadContext* ctx) throw()  final;
	int getExpressionType(ThreadContext* ctx) throw()  final;
	void readData(NetworkBinaryBuffer* buff, ThreadContext* ctx) final;
	void writeData(NetworkBinaryBuffer* buff, ThreadContext* ctx) throw()  final;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}}

#endif /* end of ALINOUS_COMPILE_EXPRESSION_FUNCTIONARGUMENTS_H_ */
