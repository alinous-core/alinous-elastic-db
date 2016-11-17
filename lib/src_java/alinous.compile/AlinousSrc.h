#ifndef ALINOUS_COMPILE_ALINOUSSRC_H_
#define ALINOUS_COMPILE_ALINOUSSRC_H_
namespace alinous{namespace annotation{
class OneSource;
}}
namespace alinous {namespace compile {
class IncludePreprocessor;}}

namespace alinous {namespace compile {namespace declare {
class IDeclare;}}}

namespace alinous {namespace compile {namespace declare {namespace function {
class AlinousFunction;}}}}

namespace alinous {namespace compile {namespace stmt {
class StatementList;}}}

namespace alinous {namespace compile {
class IAlinousElementVisitor;}}

namespace alinous {namespace compile {
class AbstractSrcElement;}}

namespace alinous {namespace compile {namespace analyse {
class SrcAnalyseContext;}}}

namespace alinous {namespace compile {
class IAlinousElement;}}

namespace alinous {namespace compile {
class IAlinousVisitorContainer;}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace compile {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::java::util::ArrayList;
using ::alinous::compile::analyse::SrcAnalyseContext;
using ::alinous::compile::declare::IDeclare;
using ::alinous::compile::declare::function::AlinousFunction;
using ::alinous::compile::stmt::StatementList;



class AlinousSrc final : public IAlinousElement, public IAlinousVisitorContainer {
public:
	AlinousSrc(const AlinousSrc& base) = default;
public:
	AlinousSrc(ThreadContext* ctx) throw()  : IObject(ctx), IAlinousElement(ctx), IAlinousVisitorContainer(ctx), includes(GCUtils<ArrayList<IncludePreprocessor> >::ins(this, (new(ctx) ArrayList<IncludePreprocessor>(ctx)), ctx, __FILEW__, __LINE__, L"")), statements(GCUtils<ArrayList<StatementList> >::ins(this, (new(ctx) ArrayList<StatementList>(ctx)), ctx, __FILEW__, __LINE__, L"")), declares(GCUtils<ArrayList<IDeclare> >::ins(this, (new(ctx) ArrayList<IDeclare>(ctx)), ctx, __FILEW__, __LINE__, L"")), functionDeclares(GCUtils<ArrayList<AlinousFunction> >::ins(this, (new(ctx) ArrayList<AlinousFunction>(ctx)), ctx, __FILEW__, __LINE__, L""))
	{
	}
	void __construct_impl(ThreadContext* ctx) throw() 
	{
	}
	virtual ~AlinousSrc() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	ArrayList<IncludePreprocessor>* includes;
	ArrayList<StatementList>* statements;
	ArrayList<IDeclare>* declares;
	ArrayList<AlinousFunction>* functionDeclares;
public:
	void addInclude(IncludePreprocessor* inc, ThreadContext* ctx) throw() ;
	ArrayList<IncludePreprocessor>* getIncludes(ThreadContext* ctx) throw() ;
	void addDeclare(IDeclare* dec, ThreadContext* ctx) throw() ;
	ArrayList<IDeclare>* getDeclares(ThreadContext* ctx) throw() ;
	void addStatementList(StatementList* list, ThreadContext* ctx) throw() ;
	ArrayList<StatementList>* getStatements(ThreadContext* ctx) throw() ;
	ArrayList<AlinousFunction>* getFunctionDeclares(ThreadContext* ctx) throw() ;
	bool visit(IAlinousElementVisitor* visitor, AbstractSrcElement* parent, ThreadContext* ctx) throw()  final;
	bool analyse(SrcAnalyseContext* context, bool leftValue, ThreadContext* ctx) throw()  final;
	int getLine(ThreadContext* ctx) throw()  final;
	int getStartPosition(ThreadContext* ctx) throw()  final;
	int getEndLine(ThreadContext* ctx) throw()  final;
	int getEndPosition(ThreadContext* ctx) throw()  final;
	AbstractSrcElement* getParent(ThreadContext* ctx) throw()  final;
	void setParent(AbstractSrcElement* parent, ThreadContext* ctx) throw()  final;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}

#endif /* end of ALINOUS_COMPILE_ALINOUSSRC_H_ */
