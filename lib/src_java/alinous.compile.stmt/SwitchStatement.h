#ifndef ALINOUS_COMPILE_STMT_SWITCHSTATEMENT_H_
#define ALINOUS_COMPILE_STMT_SWITCHSTATEMENT_H_
namespace alinous{namespace annotation{
class OneSource;
}}
namespace alinous {namespace compile {namespace analyse {
class SourceValidator;}}}

namespace alinous {namespace compile {
class IAlinousElementVisitor;}}

namespace alinous {namespace compile {
class AbstractSrcElement;}}

namespace alinous {namespace compile {namespace stmt {
class SwitchCasePart;}}}

namespace alinous {namespace compile {namespace analyse {
class SrcAnalyseContext;}}}

namespace alinous {namespace compile {namespace expression {
class IExpression;}}}

namespace alinous {namespace compile {namespace stmt {
class LabeledStatement;}}}

namespace alinous {namespace remote {namespace socket {
class NetworkBinaryBuffer;}}}

namespace alinous {namespace compile {
class IAlinousElement;}}

namespace alinous {namespace runtime {namespace dom {
class VariableException;}}}

namespace alinous {namespace compile {namespace stmt {
class AbstractAlinousStatement;}}}

namespace alinous {namespace compile {
class AlinousElementNetworkFactory;}}

namespace alinous {namespace remote {namespace socket {
class ICommandData;}}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace compile {namespace stmt {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::java::util::ArrayList;
using ::alinous::compile::AbstractSrcElement;
using ::alinous::compile::AlinousElementNetworkFactory;
using ::alinous::compile::IAlinousElement;
using ::alinous::compile::IAlinousElementVisitor;
using ::alinous::compile::analyse::SourceValidator;
using ::alinous::compile::analyse::SrcAnalyseContext;
using ::alinous::compile::expression::IExpression;
using ::alinous::remote::socket::ICommandData;
using ::alinous::remote::socket::NetworkBinaryBuffer;
using ::alinous::runtime::dom::VariableException;



class SwitchStatement final : public AbstractAlinousStatement {
public:
	SwitchStatement(const SwitchStatement& base) = default;
public:
	SwitchStatement(ThreadContext* ctx) throw()  : IObject(ctx), AbstractAlinousStatement(ctx), label(nullptr), exp(nullptr), caseParts(GCUtils<ArrayList<SwitchCasePart> >::ins(this, (new(ctx) ArrayList<SwitchCasePart>(ctx)), ctx, __FILEW__, __LINE__, L""))
	{
	}
	void __construct_impl(ThreadContext* ctx) throw() 
	{
	}
	virtual ~SwitchStatement() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	LabeledStatement* label;
	IExpression* exp;
	ArrayList<SwitchCasePart>* caseParts;
public:
	IStatement::StatementType getType(ThreadContext* ctx) throw()  final;
	void validate(SourceValidator* validator, ThreadContext* ctx) throw()  final;
	bool visit(IAlinousElementVisitor* visitor, AbstractSrcElement* parent, ThreadContext* ctx) throw()  final;
	bool analyse(SrcAnalyseContext* context, bool leftValue, ThreadContext* ctx) throw()  final;
	ArrayList<SwitchCasePart>* getCaseParts(ThreadContext* ctx) throw() ;
	void addCasePart(SwitchCasePart* part, ThreadContext* ctx) throw() ;
	IExpression* getExp(ThreadContext* ctx) throw() ;
	void setExp(IExpression* exp, ThreadContext* ctx) throw() ;
	LabeledStatement* getLabel(ThreadContext* ctx) throw() ;
	void setLabel(LabeledStatement* label, ThreadContext* ctx) throw() ;
	void readData(NetworkBinaryBuffer* buff, ThreadContext* ctx) final;
	void writeData(NetworkBinaryBuffer* buff, ThreadContext* ctx) final;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}}

#endif /* end of ALINOUS_COMPILE_STMT_SWITCHSTATEMENT_H_ */
