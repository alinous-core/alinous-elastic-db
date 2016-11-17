#ifndef ALINOUS_COMPILE_EXPRESSION_DOMVARIABLEDESCRIPTOR_H_
#define ALINOUS_COMPILE_EXPRESSION_DOMVARIABLEDESCRIPTOR_H_
namespace alinous{namespace annotation{
class OneSource;
}}
namespace alinous {namespace compile {namespace expression {
class IDomSegment;}}}

namespace alinous {namespace compile {namespace expression {
class DomNameSegment;}}}

namespace alinous {namespace runtime {namespace engine {
class ScriptMachine;}}}

namespace alinous {namespace compile {namespace expression {
class DomIndexSegment;}}}

namespace alinous {namespace runtime {namespace dom {
class IAlinousVariable;}}}

namespace alinous {namespace compile {
class IAlinousElementVisitor;}}

namespace alinous {namespace compile {
class AbstractSrcElement;}}

namespace alinous {namespace compile {namespace analyse {
class SrcAnalyseContext;}}}

namespace alinous {namespace compile {namespace analyse {
class VariableDeclareHolder;}}}

namespace alinous {namespace compile {namespace analyse {
class DomVariableDeclareSource;}}}

namespace java {namespace lang {
class StringBuffer;}}

namespace alinous {namespace compile {
class ExpressionSourceId;}}

namespace alinous {namespace compile {namespace analyse {
class AlinousType;}}}

namespace alinous {namespace compile {namespace expression {
class IExpression;}}}

namespace alinous {namespace db {namespace table {
class DatabaseException;}}}

namespace alinous {namespace runtime {namespace dom {
class IDomVariable;}}}

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
using ::alinous::compile::ExpressionSourceId;
using ::alinous::compile::IAlinousElementVisitor;
using ::alinous::compile::analyse::AlinousType;
using ::alinous::compile::analyse::DomVariableDeclareSource;
using ::alinous::compile::analyse::SrcAnalyseContext;
using ::alinous::compile::analyse::VariableDeclareHolder;
using ::alinous::db::table::DatabaseException;
using ::alinous::runtime::dom::IAlinousVariable;
using ::alinous::runtime::dom::IDomVariable;
using ::alinous::runtime::engine::ScriptMachine;
using ::alinous::system::AlinousException;



class DomVariableDescriptor final : public IExpression {
public:
	DomVariableDescriptor(const DomVariableDescriptor& base) = default;
public:
	DomVariableDescriptor(ThreadContext* ctx) throw()  : IObject(ctx), IExpression(ctx), segments(GCUtils<ArrayList<IDomSegment> >::ins(this, (new(ctx) ArrayList<IDomSegment>(ctx)), ctx, __FILEW__, __LINE__, L"")), prefix(nullptr), domDeclare(nullptr)
	{
	}
	void __construct_impl(ThreadContext* ctx) throw() 
	{
	}
	virtual ~DomVariableDescriptor() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	ArrayList<IDomSegment>* segments;
	String* prefix;
	DomVariableDeclareSource* domDeclare;
public:
	void addSegment(IDomSegment* seg, ThreadContext* ctx) throw() ;
	String* getLastName(ThreadContext* ctx) throw() ;
	int getLastIndex(ScriptMachine* machine, bool debug, ThreadContext* ctx);
	IAlinousVariable* resolveExpression(ScriptMachine* machine, bool debug, ThreadContext* ctx) final;
	bool visit(IAlinousElementVisitor* visitor, AbstractSrcElement* parent, ThreadContext* ctx) throw()  final;
	bool isConstant(ThreadContext* ctx) throw()  final;
	void markLastSegmentAsArray(ThreadContext* ctx) throw() ;
	String* getPrefix(ThreadContext* ctx) throw() ;
	void setPrefix(String* prefix, ThreadContext* ctx) throw() ;
	ArrayList<IDomSegment>* getSegments(ThreadContext* ctx) throw() ;
	bool analyse(SrcAnalyseContext* context, bool leftValue, ThreadContext* ctx) throw()  final;
	String* toString(ThreadContext* ctx) throw() ;
	ExpressionSourceId* getSourceId(ThreadContext* ctx) throw()  final;
	DomVariableDeclareSource* getDomDeclare(ThreadContext* ctx) throw() ;
	int getLine(ThreadContext* ctx) throw()  final;
	int getStartPosition(ThreadContext* ctx) throw()  final;
	int getEndLine(ThreadContext* ctx) throw()  final;
	int getEndPosition(ThreadContext* ctx) throw()  final;
	AbstractSrcElement* getParent(ThreadContext* ctx) throw()  final;
	void setParent(AbstractSrcElement* parent, ThreadContext* ctx) throw()  final;
	bool isSQLExp(ThreadContext* ctx) throw()  final;
	int getExpressionType(ThreadContext* ctx) throw()  final;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}}

#endif /* end of ALINOUS_COMPILE_EXPRESSION_DOMVARIABLEDESCRIPTOR_H_ */
