#ifndef ALINOUS_COMPILE_STMT_SWITCHCASEPART_H_
#define ALINOUS_COMPILE_STMT_SWITCHCASEPART_H_
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
class CaseStatement;}}}

namespace alinous {namespace compile {namespace analyse {
class SrcAnalyseContext;}}}

namespace alinous {namespace compile {namespace stmt {
class StatementList;}}}

namespace alinous {namespace compile {namespace stmt {
class AbstractAlinousStatement;}}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace compile {namespace stmt {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::java::util::ArrayList;
using ::alinous::compile::AbstractSrcElement;
using ::alinous::compile::IAlinousElementVisitor;
using ::alinous::compile::analyse::SourceValidator;
using ::alinous::compile::analyse::SrcAnalyseContext;



class SwitchCasePart final : public AbstractAlinousStatement {
public:
	SwitchCasePart(const SwitchCasePart& base) = default;
public:
	SwitchCasePart(ThreadContext* ctx) throw()  : IObject(ctx), AbstractAlinousStatement(ctx), casesList(GCUtils<ArrayList<CaseStatement> >::ins(this, (new(ctx) ArrayList<CaseStatement>(ctx)), ctx, __FILEW__, __LINE__, L"")), stmtlist(nullptr)
	{
	}
	void __construct_impl(ThreadContext* ctx) throw() 
	{
	}
	virtual ~SwitchCasePart() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	ArrayList<CaseStatement>* casesList;
	StatementList* stmtlist;
public:
	IStatement::StatementType getType(ThreadContext* ctx) throw()  final;
	void validate(SourceValidator* validator, ThreadContext* ctx) throw()  final;
	bool visit(IAlinousElementVisitor* visitor, AbstractSrcElement* parent, ThreadContext* ctx) throw()  final;
	bool analyse(SrcAnalyseContext* context, bool leftValue, ThreadContext* ctx) throw()  final;
	ArrayList<CaseStatement>* getCasesList(ThreadContext* ctx) throw() ;
	void addCase(CaseStatement* caseStmt, ThreadContext* ctx) throw() ;
	StatementList* getStmtlist(ThreadContext* ctx) throw() ;
	void setStmtlist(StatementList* stmtlist, ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}}

#endif /* end of ALINOUS_COMPILE_STMT_SWITCHCASEPART_H_ */
