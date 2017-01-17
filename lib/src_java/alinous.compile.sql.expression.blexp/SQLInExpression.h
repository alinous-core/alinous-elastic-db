#ifndef ALINOUS_COMPILE_SQL_EXPRESSION_BLEXP_SQLINEXPRESSION_H_
#define ALINOUS_COMPILE_SQL_EXPRESSION_BLEXP_SQLINEXPRESSION_H_
namespace alinous{namespace annotation{
class NoBlankConstructor;
}}
namespace alinous{namespace annotation{
class OneSource;
}}
namespace alinous {namespace compile {
class IAlinousElementVisitor;}}

namespace alinous {namespace compile {
class AbstractSrcElement;}}

namespace alinous {namespace compile {namespace analyse {
class SrcAnalyseContext;}}}

namespace alinous {namespace compile {namespace sql {namespace expression {
class ISQLExpression;}}}}

namespace alinous {namespace compile {namespace sql {namespace parts {
class SQLExpressionList;}}}}

namespace alinous {namespace runtime {namespace dom {
class IAlinousVariable;}}}

namespace alinous {namespace runtime {namespace engine {
class ScriptMachine;}}}

namespace alinous {namespace system {
class AlinousNotSupportedException;}}

namespace alinous {namespace compile {
class ExpressionSourceId;}}

namespace alinous {namespace compile {namespace analyse {
class AlinousType;}}}

namespace alinous {namespace compile {namespace sql {namespace analyze {
class SQLAnalyseContext;}}}}

namespace alinous {namespace compile {namespace sql {namespace analyze {
class ScanTableColumnIdentifier;}}}}

namespace alinous {namespace db {namespace table {
class DatabaseException;}}}

namespace alinous {namespace compile {namespace sql {namespace analyze {
class ScanTableIdentifier;}}}}

namespace alinous {namespace compile {namespace sql {namespace analyze {
class IndexColumnMatchCondition;}}}}

namespace alinous {namespace runtime {namespace variant {
class VariantValue;}}}

namespace alinous {namespace db {namespace trx {namespace scan {
class ScanResultRecord;}}}}

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
class AbstractSQLBooleanExpression;}}}}}

namespace alinous {namespace compile {
class AlinousElementNetworkFactory;}}

namespace alinous {namespace compile {namespace expression {
class IExpressionFactory;}}}

namespace alinous {namespace remote {namespace socket {
class ICommandData;}}}

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
using ::alinous::compile::sql::analyze::IndexColumnMatchCondition;
using ::alinous::compile::sql::analyze::SQLAnalyseContext;
using ::alinous::compile::sql::analyze::ScanTableIdentifier;
using ::alinous::compile::sql::analyze::ScanTableColumnIdentifier;
using ::alinous::compile::sql::expression::ISQLExpression;
using ::alinous::compile::sql::parts::SQLExpressionList;
using ::alinous::db::table::DatabaseException;
using ::alinous::db::trx::scan::ScanResultRecord;
using ::alinous::remote::socket::ICommandData;
using ::alinous::remote::socket::NetworkBinaryBuffer;
using ::alinous::runtime::dom::IAlinousVariable;
using ::alinous::runtime::dom::VariableException;
using ::alinous::runtime::engine::ScriptMachine;
using ::alinous::runtime::variant::VariantValue;
using ::alinous::system::AlinousException;
using ::alinous::system::AlinousNotSupportedException;



class SQLInExpression final : public AbstractSQLBooleanExpression {
public:
	SQLInExpression(const SQLInExpression& base) = default;
public:
	SQLInExpression(ThreadContext* ctx) throw() ;
	void __construct_impl(ThreadContext* ctx) throw() ;
	virtual ~SQLInExpression() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	ISQLExpression* first;
	SQLExpressionList* list;
public:
	bool visit(IAlinousElementVisitor* visitor, AbstractSrcElement* parent, ThreadContext* ctx) throw()  final;
	bool isConstant(ThreadContext* ctx) throw()  final;
	bool analyse(SrcAnalyseContext* context, bool leftValue, ThreadContext* ctx) throw()  final;
	ISQLExpression* getFirst(ThreadContext* ctx) throw() ;
	void setFirst(ISQLExpression* first, ThreadContext* ctx) throw() ;
	SQLExpressionList* getList(ThreadContext* ctx) throw() ;
	void setList(SQLExpressionList* list, ThreadContext* ctx) throw() ;
	IAlinousVariable* resolveExpression(ScriptMachine* machine, bool debug, ThreadContext* ctx) final;
	ExpressionSourceId* getSourceId(ThreadContext* ctx) throw()  final;
	bool analyseSQL(SQLAnalyseContext* context, bool leftValue, bool debug, ThreadContext* ctx) final;
	bool hasTable(ScanTableIdentifier* table, ThreadContext* ctx) throw()  final;
	ArrayList<ScanTableColumnIdentifier>* getColumns(ThreadContext* ctx) throw()  final;
	bool hasSubExp(ThreadContext* ctx) throw()  final;
	bool isJoinCondition(ThreadContext* ctx) throw()  final;
	void collectJoinCondition(ArrayList<ISQLExpression>* list, ThreadContext* ctx) throw()  final;
	bool isColumnIdentifier(ThreadContext* ctx) throw()  final;
	ArrayList<ScanTableColumnIdentifier>* getIndexTargetColumn(ThreadContext* ctx) throw()  final;
	IndexColumnMatchCondition* getIndexScanPart(ThreadContext* ctx) throw()  final;
	ScanTableColumnIdentifier* toColumnIdentifier(ThreadContext* ctx) throw()  final;
	VariantValue* resolveSQLExpression(ScanResultRecord* record, ScriptMachine* machine, bool debug, ThreadContext* ctx) final;
	bool hasArrayResult(ThreadContext* ctx) throw()  final;
	ArrayList<VariantValue>* resolveSQLExpressionAsArray(ScanResultRecord* record, ScriptMachine* machine, bool debug, ThreadContext* ctx) final;
	int getExpressionType(ThreadContext* ctx) throw()  final;
	void readData(NetworkBinaryBuffer* buff, ThreadContext* ctx) final;
	void writeData(NetworkBinaryBuffer* buff, ThreadContext* ctx) throw()  final;
	int fileSize(ThreadContext* ctx) final;
	void toFileEntry(FileStorageEntryBuilder* builder, ThreadContext* ctx) final;
	void fromFileEntry(FileStorageEntryFetcher* fetcher, ThreadContext* ctx) final;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}}}}

#endif /* end of ALINOUS_COMPILE_SQL_EXPRESSION_BLEXP_SQLINEXPRESSION_H_ */
