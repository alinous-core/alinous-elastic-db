#ifndef ALINOUS_COMPILE_STMT_FORSTATEMENT_H_
#define ALINOUS_COMPILE_STMT_FORSTATEMENT_H_
namespace alinous{namespace annotation{
class OneSource;
}}
namespace alinous {namespace compile {namespace analyse {
class SourceValidator;}}}

namespace alinous {namespace compile {
class IAlinousElementVisitor;}}

namespace alinous {namespace compile {
class AbstractSrcElement;}}

namespace alinous {namespace compile {namespace analyse {
class SrcAnalyseContext;}}}

namespace alinous {namespace compile {namespace stmt {
class LabeledStatement;}}}

namespace alinous {namespace compile {
class IStatement;}}

namespace alinous {namespace compile {namespace expression {
class IExpression;}}}

namespace alinous {namespace compile {namespace stmt {
class ForUpdatePart;}}}

namespace alinous {namespace compile {namespace stmt {
class AbstractAlinousStatement;}}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace compile {namespace stmt {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::alinous::compile::AbstractSrcElement;
using ::alinous::compile::IAlinousElementVisitor;
using ::alinous::compile::IStatement;
using ::alinous::compile::analyse::SourceValidator;
using ::alinous::compile::analyse::SrcAnalyseContext;
using ::alinous::compile::expression::IExpression;



class ForStatement final : public AbstractAlinousStatement {
public:
	ForStatement(const ForStatement& base) = default;
public:
	ForStatement(ThreadContext* ctx) throw()  : IObject(ctx), AbstractAlinousStatement(ctx), label(nullptr), initStatement(nullptr), condition(nullptr), updatePart(nullptr), exec(nullptr)
	{
	}
	void __construct_impl(ThreadContext* ctx) throw() 
	{
	}
	virtual ~ForStatement() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	LabeledStatement* label;
	IStatement* initStatement;
	IExpression* condition;
	ForUpdatePart* updatePart;
	IStatement* exec;
public:
	void validate(SourceValidator* validator, ThreadContext* ctx) throw()  final;
	bool visit(IAlinousElementVisitor* visitor, AbstractSrcElement* parent, ThreadContext* ctx) throw()  final;
	bool analyse(SrcAnalyseContext* context, bool leftValue, ThreadContext* ctx) throw()  final;
	IStatement::StatementType getType(ThreadContext* ctx) throw()  final;
	LabeledStatement* getLabel(ThreadContext* ctx) throw() ;
	void setLabel(LabeledStatement* label, ThreadContext* ctx) throw() ;
	IStatement* getInitStatement(ThreadContext* ctx) throw() ;
	void setInitStatement(IStatement* initStatement, ThreadContext* ctx) throw() ;
	IExpression* getCondition(ThreadContext* ctx) throw() ;
	void setCondition(IExpression* condition, ThreadContext* ctx) throw() ;
	ForUpdatePart* getUpdatePart(ThreadContext* ctx) throw() ;
	void setUpdatePart(ForUpdatePart* updatePart, ThreadContext* ctx) throw() ;
	IStatement* getExec(ThreadContext* ctx) throw() ;
	void setExec(IStatement* exec, ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}}

#endif /* end of ALINOUS_COMPILE_STMT_FORSTATEMENT_H_ */
