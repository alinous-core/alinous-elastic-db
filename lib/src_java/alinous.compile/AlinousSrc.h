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

namespace alinous {namespace remote {namespace socket {
class NetworkBinaryBuffer;}}}

namespace alinous {namespace compile {
class IAlinousElement;}}

namespace alinous {namespace runtime {namespace dom {
class VariableException;}}}

namespace alinous {namespace compile {
class IAlinousVisitorContainer;}}

namespace alinous {namespace remote {namespace socket {
class ICommandData;}}}

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
using ::alinous::remote::socket::ICommandData;
using ::alinous::remote::socket::NetworkBinaryBuffer;
using ::alinous::runtime::dom::VariableException;



class AlinousSrc final : public IAlinousElement, public IAlinousVisitorContainer {
public:
	AlinousSrc(const AlinousSrc& base) = default;
public:
	AlinousSrc(ThreadContext* ctx) throw() ;
	void __construct_impl(ThreadContext* ctx) throw() ;
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
	void readData(NetworkBinaryBuffer* buff, ThreadContext* ctx) final;
	void writeData(NetworkBinaryBuffer* buff, ThreadContext* ctx) final;
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
	static void __cleanUp(ThreadContext* ctx);
};

}}

#endif /* end of ALINOUS_COMPILE_ALINOUSSRC_H_ */
