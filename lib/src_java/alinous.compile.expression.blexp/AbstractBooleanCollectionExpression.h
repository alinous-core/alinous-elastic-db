#ifndef ALINOUS_COMPILE_EXPRESSION_BLEXP_ABSTRACTBOOLEANCOLLECTIONEXPRESSION_H_
#define ALINOUS_COMPILE_EXPRESSION_BLEXP_ABSTRACTBOOLEANCOLLECTIONEXPRESSION_H_
namespace alinous{namespace annotation{
class NoBlankConstructor;
}}
namespace alinous{namespace annotation{
class OneSource;
}}
namespace alinous {namespace compile {namespace expression {
class IExpression;}}}

namespace alinous {namespace compile {namespace expression {namespace blexp {
class BooleanSubExpression;}}}}

namespace alinous {namespace compile {
class IAlinousElementVisitor;}}

namespace alinous {namespace compile {
class AbstractSrcElement;}}

namespace alinous {namespace compile {namespace analyse {
class SrcAnalyseContext;}}}

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

namespace alinous {namespace buffer {namespace storage {
class FileStorageEntryBuilder;}}}

namespace alinous {namespace buffer {namespace storage {
class FileStorageEntryFetcher;}}}

namespace alinous {namespace compile {namespace expression {
class AbstractExpression;}}}

namespace alinous {namespace compile {
class AlinousElementNetworkFactory;}}

namespace alinous {namespace compile {namespace expression {
class IExpressionFactory;}}}

namespace alinous {namespace system {
class AlinousException;}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace compile {namespace expression {namespace blexp {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::java::util::ArrayList;
using ::alinous::buffer::storage::FileStorageEntryBuilder;
using ::alinous::buffer::storage::FileStorageEntryFetcher;
using ::alinous::compile::AbstractSrcElement;
using ::alinous::compile::AlinousElementNetworkFactory;
using ::alinous::compile::ExpressionSourceId;
using ::alinous::compile::IAlinousElement;
using ::alinous::compile::IAlinousElementVisitor;
using ::alinous::compile::analyse::AlinousType;
using ::alinous::compile::analyse::SrcAnalyseContext;
using ::alinous::compile::expression::AbstractExpression;
using ::alinous::compile::expression::IExpression;
using ::alinous::compile::expression::IExpressionFactory;
using ::alinous::remote::socket::NetworkBinaryBuffer;
using ::alinous::runtime::dom::VariableException;
using ::alinous::system::AlinousException;



class AbstractBooleanCollectionExpression : public AbstractExpression {
public:
	AbstractBooleanCollectionExpression(const AbstractBooleanCollectionExpression& base) = default;
public:
	AbstractBooleanCollectionExpression(ThreadContext* ctx) throw() ;
	void __construct_impl(ThreadContext* ctx) throw() ;
	virtual ~AbstractBooleanCollectionExpression() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
public:
	IExpression* first;
	ArrayList<BooleanSubExpression>* expressions;
public:
	IExpression* getFirst(ThreadContext* ctx) throw() ;
	void setFirst(IExpression* first, ThreadContext* ctx) throw() ;
	ArrayList<BooleanSubExpression>* getExpressions(ThreadContext* ctx) throw() ;
	void addSubExpression(BooleanSubExpression* exp, ThreadContext* ctx) throw() ;
	bool visit(IAlinousElementVisitor* visitor, AbstractSrcElement* parent, ThreadContext* ctx) throw()  final;
	bool isConstant(ThreadContext* ctx) throw()  final;
	bool analyse(SrcAnalyseContext* context, bool leftValue, ThreadContext* ctx) throw()  final;
	ExpressionSourceId* getSourceId(ThreadContext* ctx) throw()  final;
	bool isSQLExp(ThreadContext* ctx) throw()  final;
	void __readData(NetworkBinaryBuffer* buff, ThreadContext* ctx);
	void __writeData(NetworkBinaryBuffer* buff, ThreadContext* ctx);
	int fileSize(ThreadContext* ctx) final;
	void __toFileEntry(FileStorageEntryBuilder* builder, ThreadContext* ctx);
	void fromFileEntry(FileStorageEntryFetcher* fetcher, ThreadContext* ctx) final;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}}}

#endif /* end of ALINOUS_COMPILE_EXPRESSION_BLEXP_ABSTRACTBOOLEANCOLLECTIONEXPRESSION_H_ */
