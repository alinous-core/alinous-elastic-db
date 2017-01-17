#ifndef ALINOUS_COMPILE_SQL_EXPRESSION_SQLCOLUMNIDENTIFIER_H_
#define ALINOUS_COMPILE_SQL_EXPRESSION_SQLCOLUMNIDENTIFIER_H_
namespace alinous{namespace annotation{
class OneSource;
}}
namespace alinous {namespace compile {namespace declare {
class AlinousName;}}}

namespace alinous {namespace compile {
class IAlinousElementVisitor;}}

namespace alinous {namespace compile {
class AbstractSrcElement;}}

namespace alinous {namespace runtime {namespace dom {
class IAlinousVariable;}}}

namespace alinous {namespace runtime {namespace engine {
class ScriptMachine;}}}

namespace alinous {namespace runtime {namespace variant {
class VariantValue;}}}

namespace alinous {namespace compile {namespace analyse {
class SrcAnalyseContext;}}}

namespace alinous {namespace compile {
class ExpressionSourceId;}}

namespace alinous {namespace compile {namespace sql {namespace analyze {
class SQLAnalyseContext;}}}}

namespace alinous {namespace db {namespace table {
class DatabaseException;}}}

namespace alinous {namespace db {namespace table {
class IDatabaseTable;}}}

namespace alinous {namespace compile {namespace sql {
class TableAndSchema;}}}

namespace alinous {namespace compile {namespace sql {namespace analyze {
class ScanTableIdentifier;}}}}

namespace alinous {namespace compile {namespace sql {namespace analyze {
class ScanTableColumnIdentifier;}}}}

namespace alinous {namespace compile {namespace sql {namespace analyze {
class ScanTableMetadata;}}}}

namespace alinous {namespace compile {namespace sql {namespace expression {
class ISQLExpression;}}}}

namespace alinous {namespace db {namespace trx {namespace scan {
class ScanResultRecord;}}}}

namespace alinous {namespace system {
class AlinousNotSupportedException;}}

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

namespace alinous {namespace system {
class AlinousException;}}

namespace alinous {namespace compile {namespace sql {namespace expression {
class AbstractSQLExpression;}}}}

namespace alinous {namespace compile {
class AlinousElementNetworkFactory;}}

namespace alinous {namespace compile {namespace expression {
class IExpression;}}}

namespace alinous {namespace compile {namespace expression {
class IExpressionFactory;}}}

namespace alinous {namespace remote {namespace socket {
class ICommandData;}}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace compile {namespace sql {namespace expression {

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
using ::alinous::compile::analyse::SrcAnalyseContext;
using ::alinous::compile::declare::AlinousName;
using ::alinous::compile::expression::IExpression;
using ::alinous::compile::expression::IExpressionFactory;
using ::alinous::compile::sql::TableAndSchema;
using ::alinous::compile::sql::analyze::SQLAnalyseContext;
using ::alinous::compile::sql::analyze::ScanTableIdentifier;
using ::alinous::compile::sql::analyze::ScanTableMetadata;
using ::alinous::compile::sql::analyze::ScanTableColumnIdentifier;
using ::alinous::db::table::DatabaseException;
using ::alinous::db::table::IDatabaseTable;
using ::alinous::db::trx::scan::ScanResultRecord;
using ::alinous::remote::socket::ICommandData;
using ::alinous::remote::socket::NetworkBinaryBuffer;
using ::alinous::runtime::dom::IAlinousVariable;
using ::alinous::runtime::dom::VariableException;
using ::alinous::runtime::engine::ScriptMachine;
using ::alinous::runtime::variant::VariantValue;
using ::alinous::system::AlinousException;
using ::alinous::system::AlinousNotSupportedException;



class SQLColumnIdentifier final : public AbstractSQLExpression {
public:
	SQLColumnIdentifier(const SQLColumnIdentifier& base) = default;
public:
	SQLColumnIdentifier(ThreadContext* ctx) throw()  : IObject(ctx), AbstractSQLExpression(ctx), distinct(0), id(nullptr), asName(nullptr), resolvedName(nullptr), analysedColumn(nullptr), columnOrder(-1)
	{
	}
	void __construct_impl(ThreadContext* ctx) throw() 
	{
	}
	SQLColumnIdentifier(AlinousName* name, ThreadContext* ctx) throw() ;
	void __construct_impl(AlinousName* name, ThreadContext* ctx) throw() ;
	virtual ~SQLColumnIdentifier() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	bool distinct;
	AlinousName* id;
	String* asName;
	VariantValue* resolvedName;
	ScanTableColumnIdentifier* analysedColumn;
	int columnOrder;
public:
	bool visit(IAlinousElementVisitor* visitor, AbstractSrcElement* parent, ThreadContext* ctx) throw()  final;
	bool isConstant(ThreadContext* ctx) throw()  final;
	bool isDistinct(ThreadContext* ctx) throw() ;
	void setDistinct(bool distinct, ThreadContext* ctx) throw() ;
	AlinousName* getId(ThreadContext* ctx) throw() ;
	void setId(AlinousName* id, ThreadContext* ctx) throw() ;
	String* getAsName(ThreadContext* ctx) throw()  final;
	void setAsName(String* asName, ThreadContext* ctx) throw()  final;
	IAlinousVariable* resolveExpression(ScriptMachine* machine, bool debug, ThreadContext* ctx) final;
	bool analyse(SrcAnalyseContext* context, bool leftValue, ThreadContext* ctx) throw()  final;
	ExpressionSourceId* getSourceId(ThreadContext* ctx) throw()  final;
	bool analyseSQL(SQLAnalyseContext* context, bool leftValue, bool debug, ThreadContext* ctx) final;
	bool hasTable(ScanTableIdentifier* table, ThreadContext* ctx) throw()  final;
	ArrayList<ScanTableColumnIdentifier>* getColumns(ThreadContext* ctx) throw()  final;
	bool hasSubExp(ThreadContext* ctx) throw()  final;
	bool isJoinCondition(ThreadContext* ctx) throw()  final;
	void collectJoinCondition(ArrayList<ISQLExpression>* list, ThreadContext* ctx) throw()  final;
	bool isColumnIdentifier(ThreadContext* ctx) throw()  final;
	ScanTableColumnIdentifier* toColumnIdentifier(ThreadContext* ctx) throw()  final;
	VariantValue* resolveSQLExpression(ScanResultRecord* record, ScriptMachine* machine, bool debug, ThreadContext* ctx) final;
	bool hasArrayResult(ThreadContext* ctx) throw()  final;
	ArrayList<VariantValue>* resolveSQLExpressionAsArray(ScanResultRecord* record, ScriptMachine* machine, bool debug, ThreadContext* ctx) final;
	bool isSQLExp(ThreadContext* ctx) throw()  final;
	int getExpressionType(ThreadContext* ctx) throw()  final;
	void readData(NetworkBinaryBuffer* buff, ThreadContext* ctx) final;
	void writeData(NetworkBinaryBuffer* buff, ThreadContext* ctx) throw()  final;
	int fileSize(ThreadContext* ctx) throw()  final;
	void toFileEntry(FileStorageEntryBuilder* builder, ThreadContext* ctx) throw()  final;
	void fromFileEntry(FileStorageEntryFetcher* fetcher, ThreadContext* ctx) final;
private:
	void analyseColumnOrder(TableAndSchema* tableSc, SQLAnalyseContext* context, ThreadContext* ctx) throw() ;
	bool analyzeAsName(SQLAnalyseContext* context, ArrayList<String>* segments, ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}}}

#endif /* end of ALINOUS_COMPILE_SQL_EXPRESSION_SQLCOLUMNIDENTIFIER_H_ */
