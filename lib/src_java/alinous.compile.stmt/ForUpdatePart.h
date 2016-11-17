#ifndef ALINOUS_COMPILE_STMT_FORUPDATEPART_H_
#define ALINOUS_COMPILE_STMT_FORUPDATEPART_H_
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

namespace alinous {namespace compile {namespace expression {
class IExpression;}}}

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
using ::alinous::compile::analyse::SourceValidator;
using ::alinous::compile::analyse::SrcAnalyseContext;
using ::alinous::compile::expression::IExpression;



class ForUpdatePart final : public AbstractAlinousStatement {
public:
	ForUpdatePart(const ForUpdatePart& base) = default;
public:
	ForUpdatePart(ThreadContext* ctx) throw()  : IObject(ctx), AbstractAlinousStatement(ctx), left(nullptr), right(nullptr), ope(nullptr)
	{
	}
	void __construct_impl(ThreadContext* ctx) throw() 
	{
	}
	virtual ~ForUpdatePart() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	IExpression* left;
	IExpression* right;
	String* ope;
public:
	void validate(SourceValidator* validator, ThreadContext* ctx) throw()  final;
	bool visit(IAlinousElementVisitor* visitor, AbstractSrcElement* parent, ThreadContext* ctx) throw()  final;
	bool analyse(SrcAnalyseContext* context, bool leftValue, ThreadContext* ctx) throw()  final;
	IStatement::StatementType getType(ThreadContext* ctx) throw()  final;
	IExpression* getLeft(ThreadContext* ctx) throw() ;
	void setLeft(IExpression* left, ThreadContext* ctx) throw() ;
	IExpression* getRight(ThreadContext* ctx) throw() ;
	void setRight(IExpression* right, ThreadContext* ctx) throw() ;
	String* getOpe(ThreadContext* ctx) throw() ;
	void setOpe(String* ope, ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}}

#endif /* end of ALINOUS_COMPILE_STMT_FORUPDATEPART_H_ */
