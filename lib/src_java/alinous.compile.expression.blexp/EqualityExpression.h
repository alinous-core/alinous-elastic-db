#ifndef ALINOUS_COMPILE_EXPRESSION_BLEXP_EQUALITYEXPRESSION_H_
#define ALINOUS_COMPILE_EXPRESSION_BLEXP_EQUALITYEXPRESSION_H_
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

namespace alinous {namespace runtime {namespace dom {namespace typed {
class IntegerVariable;}}}}

namespace alinous {namespace compile {
class ExpressionSourceId;}}

namespace alinous {namespace compile {namespace analyse {
class AlinousType;}}}

namespace alinous {namespace remote {namespace socket {
class NetworkBinaryBuffer;}}}

namespace alinous {namespace compile {
class IAlinousElement;}}

namespace alinous {namespace runtime {namespace dom {
class VariableException;}}}

namespace alinous {namespace compile {namespace expression {namespace blexp {
class AbstractBooleanExpression;}}}}

namespace alinous {namespace compile {
class AlinousElementNetworkFactory;}}

namespace alinous {namespace db {namespace table {
class DatabaseException;}}}

namespace alinous {namespace remote {namespace socket {
class ICommandData;}}}

namespace alinous {namespace system {
class AlinousException;}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace compile {namespace expression {namespace blexp {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::alinous::compile::AbstractSrcElement;
using ::alinous::compile::AlinousElementNetworkFactory;
using ::alinous::compile::ExpressionSourceId;
using ::alinous::compile::IAlinousElement;
using ::alinous::compile::IAlinousElementVisitor;
using ::alinous::compile::analyse::AlinousType;
using ::alinous::compile::analyse::SrcAnalyseContext;
using ::alinous::compile::expression::IExpression;
using ::alinous::db::table::DatabaseException;
using ::alinous::remote::socket::ICommandData;
using ::alinous::remote::socket::NetworkBinaryBuffer;
using ::alinous::runtime::dom::IAlinousVariable;
using ::alinous::runtime::dom::VariableException;
using ::alinous::runtime::dom::typed::IntegerVariable;
using ::alinous::runtime::engine::ScriptMachine;
using ::alinous::system::AlinousException;



class EqualityExpression final : public AbstractBooleanExpression {
public:
	EqualityExpression(const EqualityExpression& base) = default;
public:
	EqualityExpression(ThreadContext* ctx) throw()  : IObject(ctx), AbstractBooleanExpression(ctx), left(nullptr), ope(0), right(nullptr)
	{
	}
	void __construct_impl(ThreadContext* ctx) throw() 
	{
	}
	virtual ~EqualityExpression() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	IExpression* left;
	int ope;
	IExpression* right;
public:
	constexpr static const int EQ{1};
	constexpr static const int NOT_EQ{2};
public:
	bool visit(IAlinousElementVisitor* visitor, AbstractSrcElement* parent, ThreadContext* ctx) throw()  final;
	bool isConstant(ThreadContext* ctx) throw()  final;
	bool analyse(SrcAnalyseContext* context, bool leftValue, ThreadContext* ctx) throw()  final;
	IExpression* getLeft(ThreadContext* ctx) throw() ;
	void setLeft(IExpression* left, ThreadContext* ctx) throw() ;
	IExpression* getRight(ThreadContext* ctx) throw() ;
	void setRight(IExpression* right, ThreadContext* ctx) throw() ;
	int getOpe(ThreadContext* ctx) throw() ;
	void setOpe(String* opeStr, ThreadContext* ctx) throw() ;
	IAlinousVariable* resolveExpression(ScriptMachine* machine, bool debug, ThreadContext* ctx) final;
	ExpressionSourceId* getSourceId(ThreadContext* ctx) throw()  final;
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

}}}}

#endif /* end of ALINOUS_COMPILE_EXPRESSION_BLEXP_EQUALITYEXPRESSION_H_ */
