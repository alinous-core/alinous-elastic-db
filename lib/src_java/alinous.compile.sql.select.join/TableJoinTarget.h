#ifndef ALINOUS_COMPILE_SQL_SELECT_JOIN_TABLEJOINTARGET_H_
#define ALINOUS_COMPILE_SQL_SELECT_JOIN_TABLEJOINTARGET_H_
namespace alinous{namespace annotation{
class OneSource;
}}
namespace alinous {namespace compile {
class IAlinousElementVisitor;}}

namespace alinous {namespace compile {
class AbstractSrcElement;}}

namespace alinous {namespace compile {namespace analyse {
class SrcAnalyseContext;}}}

namespace alinous {namespace compile {namespace declare {
class AlinousName;}}}

namespace alinous {namespace compile {namespace sql {namespace analyze {
class SQLAnalyseContext;}}}}

namespace alinous {namespace db {namespace table {
class DatabaseException;}}}

namespace alinous {namespace db {
class AlinousDatabase;}}

namespace alinous {namespace db {namespace table {
class IDatabaseTable;}}}

namespace alinous {namespace compile {namespace sql {namespace analyze {
class ScanTableMetadata;}}}}

namespace alinous {namespace compile {namespace sql {namespace analyze {
class ScanTableIdentifier;}}}}

namespace alinous {namespace compile {namespace sql {
class TableAndSchema;}}}

namespace alinous {namespace compile {namespace sql {namespace select {
class SQLWhere;}}}}

namespace alinous {namespace compile {namespace sql {namespace select {
class SQLGroupBy;}}}}

namespace alinous {namespace compile {namespace sql {namespace select {
class SQLLimitOffset;}}}}

namespace alinous {namespace compile {namespace sql {namespace analyze {
class ScanTableColumnIdentifier;}}}}

namespace alinous {namespace compile {namespace sql {namespace analyze {
class ScanSingleStrategy;}}}}

namespace alinous {namespace db {namespace trx {namespace scan {
class ITableTargetScanner;}}}}

namespace alinous {namespace db {namespace trx {
class DbTransaction;}}}

namespace alinous {namespace runtime {namespace engine {
class ScriptMachine;}}}

namespace alinous {namespace compile {namespace sql {namespace select {namespace join {
class SQLJoinCondition;}}}}}

namespace alinous {namespace compile {namespace analyse {
class SourceValidator;}}}

namespace alinous {namespace compile {namespace sql {namespace select {namespace join {
class AbstractJoinTarget;}}}}}

namespace alinous {namespace system {
class AlinousException;}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace compile {namespace sql {namespace select {namespace join {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::java::util::ArrayList;
using ::alinous::compile::AbstractSrcElement;
using ::alinous::compile::IAlinousElementVisitor;
using ::alinous::compile::analyse::SourceValidator;
using ::alinous::compile::analyse::SrcAnalyseContext;
using ::alinous::compile::declare::AlinousName;
using ::alinous::compile::sql::TableAndSchema;
using ::alinous::compile::sql::analyze::SQLAnalyseContext;
using ::alinous::compile::sql::analyze::ScanSingleStrategy;
using ::alinous::compile::sql::analyze::ScanTableColumnIdentifier;
using ::alinous::compile::sql::analyze::ScanTableIdentifier;
using ::alinous::compile::sql::analyze::ScanTableMetadata;
using ::alinous::compile::sql::select::SQLGroupBy;
using ::alinous::compile::sql::select::SQLLimitOffset;
using ::alinous::compile::sql::select::SQLWhere;
using ::alinous::db::AlinousDatabase;
using ::alinous::db::table::DatabaseException;
using ::alinous::db::table::IDatabaseTable;
using ::alinous::db::trx::DbTransaction;
using ::alinous::db::trx::scan::ITableTargetScanner;
using ::alinous::runtime::engine::ScriptMachine;
using ::alinous::system::AlinousException;



class TableJoinTarget final : public AbstractJoinTarget {
public:
	TableJoinTarget(const TableJoinTarget& base) = default;
public:
	TableJoinTarget(ThreadContext* ctx) throw()  : IObject(ctx), AbstractJoinTarget(ctx), name(nullptr), asName(nullptr), scanMeta(nullptr), tableId(nullptr), strategy(nullptr)
	{
	}
	void __construct_impl(ThreadContext* ctx) throw() 
	{
	}
	virtual ~TableJoinTarget() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	AlinousName* name;
	String* asName;
	ScanTableMetadata* scanMeta;
	ScanTableIdentifier* tableId;
	ScanSingleStrategy* strategy;
public:
	bool visit(IAlinousElementVisitor* visitor, AbstractSrcElement* parent, ThreadContext* ctx) throw()  final;
	bool analyse(SrcAnalyseContext* context, bool leftValue, ThreadContext* ctx) throw()  final;
	AlinousName* getName(ThreadContext* ctx) throw() ;
	void setName(AlinousName* name, ThreadContext* ctx) throw() ;
	String* getAsName(ThreadContext* ctx) throw() ;
	void setAsName(String* asName, ThreadContext* ctx) throw() ;
	bool analyseSQLTables(SQLAnalyseContext* context, bool leftValue, bool debug, ThreadContext* ctx) final;
	void analyzeSQL(SQLAnalyseContext* context, bool debug, ThreadContext* ctx) final;
	bool hasTable(ScanTableIdentifier* table, ThreadContext* ctx) throw()  final;
	void optimizeScan(SQLAnalyseContext* context, SQLWhere* where, SQLGroupBy* groupby, SQLLimitOffset* limit, ArrayList<ScanTableColumnIdentifier>* joinRequest, bool debug, ThreadContext* ctx) final;
	ScanTableMetadata* getScanTableMetadata(ThreadContext* ctx) throw()  final;
	bool isOptimizerCacheable(ThreadContext* ctx) throw()  final;
	ITableTargetScanner* getScanner(DbTransaction* trx, ScriptMachine* machine, ArrayList<ScanTableColumnIdentifier>* joinRequest, bool debug, ThreadContext* ctx) final;
	SQLJoinCondition* getCondition(ThreadContext* ctx) final;
	IStatement::StatementType getType(ThreadContext* ctx) throw()  final;
	void validate(SourceValidator* validator, ThreadContext* ctx) throw()  final;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}}}}

#endif /* end of ALINOUS_COMPILE_SQL_SELECT_JOIN_TABLEJOINTARGET_H_ */
