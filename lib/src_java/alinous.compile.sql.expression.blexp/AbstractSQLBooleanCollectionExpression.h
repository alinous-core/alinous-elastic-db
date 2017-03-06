#ifndef ALINOUS_COMPILE_SQL_EXPRESSION_BLEXP_ABSTRACTSQLBOOLEANCOLLECTIONEXPRESSION_H_
#define ALINOUS_COMPILE_SQL_EXPRESSION_BLEXP_ABSTRACTSQLBOOLEANCOLLECTIONEXPRESSION_H_
namespace alinous{namespace annotation{
class OneSource;
}}
namespace alinous {namespace compile {namespace sql {namespace expression {
class ISQLExpression;}}}}

namespace alinous {namespace compile {namespace sql {namespace expression {namespace blexp {
class SQLBoolSubExpression;}}}}}

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

namespace alinous {namespace compile {namespace sql {namespace analyze {
class SQLAnalyseContext;}}}}

namespace alinous {namespace compile {namespace sql {namespace analyze {
class ScanTableIdentifier;}}}}

namespace alinous {namespace compile {namespace sql {namespace analyze {
class ScanTableColumnIdentifier;}}}}

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
class IExpression;}}}

namespace alinous {namespace compile {namespace sql {namespace expression {namespace blexp {
class ISQLBoolExpression;}}}}}

namespace alinous {namespace compile {
class AlinousElementNetworkFactory;}}

namespace alinous {namespace compile {namespace expression {
class IExpressionFactory;}}}

namespace alinous {namespace db {namespace table {
class DatabaseException;}}}

namespace alinous {namespace system {
class AlinousException;}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace compile {namespace sql {namespace expression {namespace blexp {

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
using ::alinous::compile::expression::IExpression;
using ::alinous::compile::expression::IExpressionFactory;
using ::alinous::compile::sql::analyze::SQLAnalyseContext;
using ::alinous::compile::sql::analyze::ScanTableIdentifier;
using ::alinous::compile::sql::analyze::ScanTableColumnIdentifier;
using ::alinous::compile::sql::expression::ISQLExpression;
using ::alinous::db::table::DatabaseException;
using ::alinous::remote::socket::NetworkBinaryBuffer;
using ::alinous::runtime::dom::VariableException;
using ::alinous::system::AlinousException;



class AbstractSQLBooleanCollectionExpression : public ISQLBoolExpression {
public:
	AbstractSQLBooleanCollectionExpression(const AbstractSQLBooleanCollectionExpression& base) = default;
public:
	AbstractSQLBooleanCollectionExpression(ThreadContext* ctx) throw() ;
	void __construct_impl(ThreadContext* ctx) throw() ;
	AbstractSQLBooleanCollectionExpression(ArrayList<ISQLExpression>* list, String* op, ThreadContext* ctx) throw() ;
	void __construct_impl(ArrayList<ISQLExpression>* list, String* op, ThreadContext* ctx) throw() ;
	virtual ~AbstractSQLBooleanCollectionExpression() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
public:
	ISQLExpression* first;
	ArrayList<SQLBoolSubExpression>* expressions;
	String* asName;
public:
	constexpr static const int AND_EXP{1};
	constexpr static const int OR_EXP{2};
public:
	virtual int getContainerType(ThreadContext* ctx) throw()  = 0;
	ISQLExpression* getFirst(ThreadContext* ctx) throw() ;
	void setFirst(ISQLExpression* first, ThreadContext* ctx) throw() ;
	ArrayList<SQLBoolSubExpression>* getExpressions(ThreadContext* ctx) throw() ;
	void addSubExpression(SQLBoolSubExpression* exp, ThreadContext* ctx) throw() ;
	bool visit(IAlinousElementVisitor* visitor, AbstractSrcElement* parent, ThreadContext* ctx) throw()  final;
	bool isConstant(ThreadContext* ctx) throw()  final;
	bool analyse(SrcAnalyseContext* context, bool leftValue, ThreadContext* ctx) throw()  final;
	ExpressionSourceId* getSourceId(ThreadContext* ctx) throw()  final;
	bool analyseSQL(SQLAnalyseContext* context, bool leftValue, bool debug, ThreadContext* ctx) final;
	bool hasTable(ScanTableIdentifier* table, ThreadContext* ctx) throw()  final;
	ArrayList<ScanTableColumnIdentifier>* getColumns(ThreadContext* ctx) throw()  final;
	bool hasSubExp(ThreadContext* ctx) throw()  final;
	int getLine(ThreadContext* ctx) throw()  final;
	int getStartPosition(ThreadContext* ctx) throw()  final;
	int getEndLine(ThreadContext* ctx) throw()  final;
	int getEndPosition(ThreadContext* ctx) throw()  final;
	AbstractSrcElement* getParent(ThreadContext* ctx) throw()  final;
	void setParent(AbstractSrcElement* parent, ThreadContext* ctx) throw()  final;
	bool isSQLExp(ThreadContext* ctx) throw()  final;
	String* getAsName(ThreadContext* ctx) throw()  final;
	void setAsName(String* name, ThreadContext* ctx) throw()  final;
	void __readData(NetworkBinaryBuffer* buff, ThreadContext* ctx);
	void __writeData(NetworkBinaryBuffer* buff, ThreadContext* ctx);
	int fileSize(ThreadContext* ctx) final;
	void __toFileEntry(FileStorageEntryBuilder* builder, ThreadContext* ctx);
	void fromFileEntry(FileStorageEntryFetcher* fetcher, ThreadContext* ctx) final;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx);
};

}}}}}

#endif /* end of ALINOUS_COMPILE_SQL_EXPRESSION_BLEXP_ABSTRACTSQLBOOLEANCOLLECTIONEXPRESSION_H_ */
