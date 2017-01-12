#ifndef ALINOUS_COMPILE_STMT_BREAKSTATEMENT_H_
#define ALINOUS_COMPILE_STMT_BREAKSTATEMENT_H_
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

namespace alinous {namespace remote {namespace socket {
class NetworkBinaryBuffer;}}}

namespace alinous {namespace compile {namespace stmt {
class AbstractAlinousStatement;}}}

namespace alinous {namespace remote {namespace socket {
class ICommandData;}}}

namespace alinous {namespace runtime {namespace dom {
class VariableException;}}}

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
using ::alinous::remote::socket::ICommandData;
using ::alinous::remote::socket::NetworkBinaryBuffer;
using ::alinous::runtime::dom::VariableException;



class BreakStatement final : public AbstractAlinousStatement {
public:
	BreakStatement(const BreakStatement& base) = default;
public:
	BreakStatement(ThreadContext* ctx) throw()  : IObject(ctx), AbstractAlinousStatement(ctx), label(nullptr)
	{
	}
	void __construct_impl(ThreadContext* ctx) throw() 
	{
	}
	virtual ~BreakStatement() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	String* label;
public:
	IStatement::StatementType getType(ThreadContext* ctx) throw()  final;
	void validate(SourceValidator* validator, ThreadContext* ctx) throw()  final;
	bool visit(IAlinousElementVisitor* visitor, AbstractSrcElement* parent, ThreadContext* ctx) throw()  final;
	bool analyse(SrcAnalyseContext* context, bool leftValue, ThreadContext* ctx) throw()  final;
	String* getLabel(ThreadContext* ctx) throw() ;
	void setLabel(String* label, ThreadContext* ctx) throw() ;
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

#endif /* end of ALINOUS_COMPILE_STMT_BREAKSTATEMENT_H_ */
