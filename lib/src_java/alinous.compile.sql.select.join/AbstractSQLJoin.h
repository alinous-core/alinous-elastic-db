#ifndef ALINOUS_COMPILE_SQL_SELECT_JOIN_ABSTRACTSQLJOIN_H_
#define ALINOUS_COMPILE_SQL_SELECT_JOIN_ABSTRACTSQLJOIN_H_
namespace alinous{namespace annotation{
class OneSource;
}}
namespace alinous {namespace compile {
class IAlinousElementVisitor;}}

namespace alinous {namespace compile {
class AbstractSrcElement;}}

namespace alinous {namespace compile {namespace analyse {
class SrcAnalyseContext;}}}

namespace alinous {namespace compile {namespace sql {namespace analyze {
class SQLAnalyseContext;}}}}

namespace alinous {namespace compile {namespace sql {namespace select {
class SQLWhere;}}}}

namespace alinous {namespace compile {namespace sql {namespace select {
class SQLGroupBy;}}}}

namespace alinous {namespace compile {namespace sql {namespace select {
class SQLLimitOffset;}}}}

namespace alinous {namespace compile {namespace sql {namespace analyze {
class ScanTableColumnIdentifier;}}}}

namespace alinous {namespace compile {namespace sql {namespace analyze {
class JoinStrategy;}}}}

namespace alinous {namespace compile {namespace sql {namespace expression {
class ISQLExpression;}}}}

namespace alinous {namespace compile {namespace sql {namespace analyze {
class ScanTableMetadata;}}}}

namespace alinous {namespace compile {namespace sql {namespace analyze {
class JoinStrategyPart;}}}}

namespace alinous {namespace compile {namespace sql {namespace analyze {
class JoinMatchExpression;}}}}

namespace alinous {namespace compile {namespace sql {namespace analyze {
class ScanTableIndexMetadata;}}}}

namespace alinous {namespace compile {namespace sql {namespace analyze {
class ScanTableColumnMetadata;}}}}

namespace alinous {namespace compile {namespace sql {namespace select {namespace join {
class IJoin;}}}}}

namespace alinous {namespace compile {namespace sql {namespace select {namespace join {
class SQLJoinCondition;}}}}}

namespace alinous {namespace compile {namespace sql {namespace analyze {
class ScanTableIdentifier;}}}}

namespace alinous {namespace db {namespace trx {namespace scan {
class ITableTargetScanner;}}}}

namespace alinous {namespace db {namespace trx {
class DbTransaction;}}}

namespace alinous {namespace runtime {namespace engine {
class ScriptMachine;}}}

namespace alinous {namespace compile {namespace sql {namespace select {namespace join {namespace scan {
class CrossJoinScanner;}}}}}}

namespace alinous {namespace db {namespace trx {namespace scan {
class ScannedResultIndexScanner;}}}}

namespace alinous {namespace db {namespace trx {namespace scan {
class ScanResult;}}}}

namespace alinous {namespace db {namespace trx {namespace scan {
class ScanResultRecord;}}}}

namespace alinous {namespace db {namespace table {
class DatabaseException;}}}

namespace java {namespace lang {
class Throwable;}}

namespace alinous {namespace compile {namespace sql {namespace select {namespace join {namespace scan {
class RightindexJoinScanner;}}}}}}

namespace alinous {namespace compile {namespace sql {namespace select {namespace join {namespace scan {
class ReverseIndexScanner;}}}}}}

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
using ::alinous::compile::analyse::SrcAnalyseContext;
using ::alinous::compile::sql::analyze::JoinMatchExpression;
using ::alinous::compile::sql::analyze::JoinStrategy;
using ::alinous::compile::sql::analyze::JoinStrategyPart;
using ::alinous::compile::sql::analyze::SQLAnalyseContext;
using ::alinous::compile::sql::analyze::ScanTableColumnIdentifier;
using ::alinous::compile::sql::analyze::ScanTableColumnMetadata;
using ::alinous::compile::sql::analyze::ScanTableIdentifier;
using ::alinous::compile::sql::analyze::ScanTableIndexMetadata;
using ::alinous::compile::sql::analyze::ScanTableMetadata;
using ::alinous::compile::sql::expression::ISQLExpression;
using ::alinous::compile::sql::select::SQLGroupBy;
using ::alinous::compile::sql::select::SQLLimitOffset;
using ::alinous::compile::sql::select::SQLWhere;
using ::alinous::compile::sql::select::join::scan::CrossJoinScanner;
using ::alinous::compile::sql::select::join::scan::ReverseIndexScanner;
using ::alinous::compile::sql::select::join::scan::RightindexJoinScanner;
using ::alinous::db::table::DatabaseException;
using ::alinous::db::trx::DbTransaction;
using ::alinous::db::trx::scan::ITableTargetScanner;
using ::alinous::db::trx::scan::ScanResult;
using ::alinous::db::trx::scan::ScanResultRecord;
using ::alinous::db::trx::scan::ScannedResultIndexScanner;
using ::alinous::runtime::engine::ScriptMachine;
using ::alinous::system::AlinousException;



class AbstractSQLJoin : public IJoin {
public:
	AbstractSQLJoin(const AbstractSQLJoin& base) = default;
public:
	AbstractSQLJoin(ThreadContext* ctx) throw()  : IObject(ctx), IJoin(ctx), left(nullptr), right(nullptr), condition(nullptr), joinStrategy(nullptr), bestParts(nullptr), crossjoin(false), scanMetadata(nullptr)
	{
	}
	void __construct_impl(ThreadContext* ctx) throw() 
	{
	}
	virtual ~AbstractSQLJoin() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
public:
	IJoin* left;
	IJoin* right;
	SQLJoinCondition* condition;
	JoinStrategy* joinStrategy;
	ArrayList<JoinStrategyPart>* bestParts;
	bool crossjoin;
	ScanTableMetadata* scanMetadata;
public:
	bool visit(IAlinousElementVisitor* visitor, AbstractSrcElement* parent, ThreadContext* ctx) throw()  final;
	bool analyse(SrcAnalyseContext* context, bool leftValue, ThreadContext* ctx) throw()  final;
	virtual void optimizeScan(SQLAnalyseContext* context, SQLWhere* where, SQLGroupBy* groupby, SQLLimitOffset* limit, ArrayList<ScanTableColumnIdentifier>* joinRequest, bool debug, ThreadContext* ctx);
	IJoin* getLeft(ThreadContext* ctx) throw() ;
	virtual void setLeft(IJoin* left, ThreadContext* ctx) throw() ;
	IJoin* getRight(ThreadContext* ctx) throw() ;
	virtual void setRight(IJoin* right, ThreadContext* ctx) throw() ;
	SQLJoinCondition* getCondition(ThreadContext* ctx) throw()  final;
	void setCondition(SQLJoinCondition* condition, ThreadContext* ctx) throw() ;
	bool analyseSQLTables(SQLAnalyseContext* context, bool leftValue, bool debug, ThreadContext* ctx) final;
	void analyzeSQL(SQLAnalyseContext* context, bool debug, ThreadContext* ctx) final;
	bool hasTable(ScanTableIdentifier* table, ThreadContext* ctx) throw()  final;
	ScanTableMetadata* getScanTableMetadata(ThreadContext* ctx) throw()  final;
	bool isOptimizerCacheable(ThreadContext* ctx) throw()  final;
	int getLine(ThreadContext* ctx) throw()  final;
	int getStartPosition(ThreadContext* ctx) throw()  final;
	int getEndLine(ThreadContext* ctx) throw()  final;
	int getEndPosition(ThreadContext* ctx) throw()  final;
	AbstractSrcElement* getParent(ThreadContext* ctx) throw()  final;
	void setParent(AbstractSrcElement* parent, ThreadContext* ctx) throw()  final;
	ITableTargetScanner* getCrossJoinsScanner(DbTransaction* trx, ScriptMachine* machine, ArrayList<ScanTableColumnIdentifier>* joinRequest, bool debug, ThreadContext* ctx);
	ScannedResultIndexScanner* toResultScanner(DbTransaction* trx, ITableTargetScanner* scanner, ArrayList<ScanTableColumnIdentifier>* joinRequest, ScanTableMetadata* tableMeta, bool debug, ThreadContext* ctx);
	ITableTargetScanner* getJoinStrategyScanner(DbTransaction* trx, ScriptMachine* machine, JoinStrategyPart* part, bool inner, bool debug, ThreadContext* ctx);
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}}}}

#endif /* end of ALINOUS_COMPILE_SQL_SELECT_JOIN_ABSTRACTSQLJOIN_H_ */
