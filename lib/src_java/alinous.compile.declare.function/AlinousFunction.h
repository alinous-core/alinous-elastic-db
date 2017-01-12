#ifndef ALINOUS_COMPILE_DECLARE_FUNCTION_ALINOUSFUNCTION_H_
#define ALINOUS_COMPILE_DECLARE_FUNCTION_ALINOUSFUNCTION_H_
namespace alinous{namespace annotation{
class OneSource;
}}
namespace alinous {namespace compile {namespace declare {namespace function {
class AlinousFunction;}}}}

namespace alinous {namespace compile {
class IAlinousElementVisitor;}}

namespace alinous {namespace compile {
class AbstractSrcElement;}}

namespace alinous {namespace compile {namespace analyse {
class SrcAnalyseContext;}}}

namespace alinous {namespace compile {namespace analyse {
class AlinousType;}}}

namespace alinous {namespace compile {namespace expression {namespace expstream {
class FunctionCallExpression;}}}}

namespace alinous {namespace compile {
class IStatement;}}

namespace alinous {namespace compile {namespace analyse {namespace tools {
class FunctionCallCollector;}}}}

namespace java {namespace lang {
class StringBuffer;}}

namespace alinous {namespace compile {namespace declare {
class AlinousName;}}}

namespace alinous {namespace compile {namespace declare {namespace function {
class ReturnValueDefinition;}}}}

namespace alinous {namespace compile {namespace declare {namespace function {
class FunctionArgumentsListDefine;}}}}

namespace alinous {namespace compile {namespace declare {namespace function {
class ThrowsDefine;}}}}

namespace alinous {namespace compile {namespace stmt {
class StatementBlock;}}}

namespace alinous {namespace remote {namespace socket {
class NetworkBinaryBuffer;}}}

namespace alinous {namespace compile {
class IAlinousElement;}}

namespace alinous {namespace runtime {namespace dom {
class VariableException;}}}

namespace alinous {namespace compile {namespace declare {
class IDeclare;}}}

namespace alinous {namespace compile {
class AlinousElementNetworkFactory;}}

namespace alinous {namespace remote {namespace socket {
class ICommandData;}}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace compile {namespace declare {namespace function {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::alinous::compile::AbstractSrcElement;
using ::alinous::compile::AlinousElementNetworkFactory;
using ::alinous::compile::IAlinousElement;
using ::alinous::compile::IAlinousElementVisitor;
using ::alinous::compile::IStatement;
using ::alinous::compile::analyse::AlinousType;
using ::alinous::compile::analyse::SrcAnalyseContext;
using ::alinous::compile::analyse::tools::FunctionCallCollector;
using ::alinous::compile::declare::AlinousName;
using ::alinous::compile::declare::IDeclare;
using ::alinous::compile::expression::expstream::FunctionCallExpression;
using ::alinous::compile::stmt::StatementBlock;
using ::alinous::remote::socket::ICommandData;
using ::alinous::remote::socket::NetworkBinaryBuffer;
using ::alinous::runtime::dom::VariableException;



class AlinousFunction final : public IDeclare {
public:
	AlinousFunction(const AlinousFunction& base) = default;
public:
	AlinousFunction(ThreadContext* ctx) throw()  : IObject(ctx), IDeclare(ctx), name(nullptr), returnType(nullptr), arguments(nullptr), throwsDefine(nullptr), block(nullptr), analysedReturnType(nullptr)
	{
	}
	void __construct_impl(ThreadContext* ctx) throw() 
	{
	}
	virtual ~AlinousFunction() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	AlinousName* name;
	ReturnValueDefinition* returnType;
	FunctionArgumentsListDefine* arguments;
	ThrowsDefine* throwsDefine;
	StatementBlock* block;
	AlinousType* analysedReturnType;
public:
	String* getFunctionName(ThreadContext* ctx) throw() ;
	bool sameSig(AlinousFunction* other, ThreadContext* ctx) throw() ;
	bool visit(IAlinousElementVisitor* visitor, AbstractSrcElement* parent, ThreadContext* ctx) throw()  final;
	bool analyse(SrcAnalyseContext* context, bool leftValue, ThreadContext* ctx) throw()  final;
	FunctionCallExpression* callSuperConstructor(ThreadContext* ctx) throw() ;
	String* toString(ThreadContext* ctx) throw() ;
	AlinousName* getName(ThreadContext* ctx) throw() ;
	void setName(AlinousName* name, ThreadContext* ctx) throw() ;
	ReturnValueDefinition* getReturnType(ThreadContext* ctx) throw() ;
	void setReturnType(ReturnValueDefinition* returnType, ThreadContext* ctx) throw() ;
	FunctionArgumentsListDefine* getArguments(ThreadContext* ctx) throw() ;
	void setArguments(FunctionArgumentsListDefine* arguments, ThreadContext* ctx) throw() ;
	ThrowsDefine* getThrowsDefine(ThreadContext* ctx) throw() ;
	void setThrowsDefine(ThrowsDefine* throwsDefine, ThreadContext* ctx) throw() ;
	StatementBlock* getBlock(ThreadContext* ctx) throw() ;
	void setBlock(StatementBlock* block, ThreadContext* ctx) throw() ;
	AlinousType* getAnalysedReturnType(ThreadContext* ctx) throw() ;
	int getLine(ThreadContext* ctx) throw()  final;
	int getStartPosition(ThreadContext* ctx) throw()  final;
	int getEndLine(ThreadContext* ctx) throw()  final;
	int getEndPosition(ThreadContext* ctx) throw()  final;
	AbstractSrcElement* getParent(ThreadContext* ctx) throw()  final;
	void setParent(AbstractSrcElement* parent, ThreadContext* ctx) throw()  final;
	void readData(NetworkBinaryBuffer* buff, ThreadContext* ctx) final;
	void writeData(NetworkBinaryBuffer* buff, ThreadContext* ctx) throw()  final;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}}}

#endif /* end of ALINOUS_COMPILE_DECLARE_FUNCTION_ALINOUSFUNCTION_H_ */
