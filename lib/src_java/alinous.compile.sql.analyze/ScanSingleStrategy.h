#ifndef ALINOUS_COMPILE_SQL_ANALYZE_SCANSINGLESTRATEGY_H_
#define ALINOUS_COMPILE_SQL_ANALYZE_SCANSINGLESTRATEGY_H_
namespace alinous{namespace annotation{
class OneSource;
}}
namespace alinous {namespace compile {namespace sql {namespace analyze {
class BooleanFilterConditionUtil;}}}}

namespace alinous {namespace compile {namespace sql {namespace analyze {
class ScanTableMetadata;}}}}

namespace alinous {namespace compile {namespace sql {namespace analyze {
class ScanTableIdentifier;}}}}

namespace alinous {namespace db {
class AlinousDatabase;}}

namespace alinous {namespace db {namespace trx {namespace scan {
class ITableTargetScanner;}}}}

namespace alinous {namespace runtime {namespace engine {
class ScriptMachine;}}}

namespace alinous {namespace db {namespace trx {
class DbTransaction;}}}

namespace alinous {namespace compile {namespace sql {namespace analyze {
class ScanTableColumnIdentifier;}}}}

namespace alinous {namespace db {namespace table {
class DatabaseException;}}}

namespace java {namespace io {
class IOException;}}

namespace java {namespace lang {
class InterruptedException;}}

namespace alinous {namespace compile {namespace sql {namespace analyze {
class ScanTableIndexMetadata;}}}}

namespace alinous {namespace system {
class AlinousException;}}

namespace alinous {namespace btree {
class BTreeException;}}

namespace alinous {namespace db {namespace table {namespace scan {
class SingleTableIndexScanner;}}}}

namespace alinous {namespace db {namespace table {
class IDatabaseTable;}}}

namespace alinous {namespace db {namespace trx {namespace cache {
class TrxStorageManager;}}}}

namespace alinous {namespace db {namespace table {
class IScannableIndex;}}}

namespace alinous {namespace db {namespace trx {namespace cache {
class TrxRecordCacheIndex;}}}}

namespace alinous {namespace db {namespace trx {namespace cache {
class TrxRecordsCache;}}}}

namespace alinous {namespace db {
class AlinousDbException;}}

namespace alinous {namespace db {namespace table {
class TableColumnMetadata;}}}

namespace alinous {namespace db {namespace trx {namespace scan {
class ScannedResultIndexScanner;}}}}

namespace alinous {namespace db {namespace trx {namespace scan {
class ScanResult;}}}}

namespace alinous {namespace db {namespace trx {namespace scan {
class ScanResultRecord;}}}}

namespace java {namespace lang {
class Throwable;}}

namespace alinous {namespace compile {namespace sql {namespace analyze {
class InnerNecessaryCondition;}}}}

namespace alinous {namespace compile {namespace sql {namespace analyze {
class IndexScanStrategy;}}}}

namespace alinous {namespace compile {namespace sql {namespace analyze {
class IndexScanStrategyPlan;}}}}

namespace alinous {namespace compile {namespace sql {namespace analyze {namespace scan {
class VoidScanner;}}}}}

namespace alinous {namespace db {namespace trx {namespace scan {
class ScanResultIndexKey;}}}}

namespace alinous {namespace db {namespace table {namespace scan {
class IndexRangeScannerParam;}}}}

namespace alinous {namespace db {namespace table {namespace scan {
class IndexListScannerParam;}}}}

namespace alinous {namespace compile {namespace sql {namespace select {
class SQLWhere;}}}}

namespace alinous {namespace compile {namespace sql {namespace expression {
class ISQLExpression;}}}}

namespace alinous {namespace db {namespace table {namespace scan {
class IndexScannerLockRequirement;}}}}

namespace alinous {namespace db {namespace table {namespace scan {
class ScannerFactory;}}}}

namespace java {namespace lang {
class IObject;
}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace compile {namespace sql {namespace analyze {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::java::io::IOException;
using ::java::util::ArrayList;
using ::alinous::btree::BTreeException;
using ::alinous::compile::sql::analyze::scan::VoidScanner;
using ::alinous::compile::sql::expression::ISQLExpression;
using ::alinous::compile::sql::select::SQLWhere;
using ::alinous::db::AlinousDatabase;
using ::alinous::db::AlinousDbException;
using ::alinous::db::table::DatabaseException;
using ::alinous::db::table::IDatabaseTable;
using ::alinous::db::table::IScannableIndex;
using ::alinous::db::table::TableColumnMetadata;
using ::alinous::db::table::scan::IndexListScannerParam;
using ::alinous::db::table::scan::IndexRangeScannerParam;
using ::alinous::db::table::scan::IndexScannerLockRequirement;
using ::alinous::db::table::scan::ScannerFactory;
using ::alinous::db::table::scan::SingleTableIndexScanner;
using ::alinous::db::trx::DbTransaction;
using ::alinous::db::trx::cache::TrxRecordCacheIndex;
using ::alinous::db::trx::cache::TrxRecordsCache;
using ::alinous::db::trx::cache::TrxStorageManager;
using ::alinous::db::trx::scan::ITableTargetScanner;
using ::alinous::db::trx::scan::ScanResult;
using ::alinous::db::trx::scan::ScanResultIndexKey;
using ::alinous::db::trx::scan::ScanResultRecord;
using ::alinous::db::trx::scan::ScannedResultIndexScanner;
using ::alinous::runtime::engine::ScriptMachine;
using ::alinous::system::AlinousException;



class ScanSingleStrategy final : public virtual IObject {
public:
	ScanSingleStrategy(const ScanSingleStrategy& base) = default;
public:
	ScanSingleStrategy(ScanTableMetadata* table, ScanTableIdentifier* tableId, AlinousDatabase* database, ThreadContext* ctx) throw() ;
	void __construct_impl(ScanTableMetadata* table, ScanTableIdentifier* tableId, AlinousDatabase* database, ThreadContext* ctx) throw() ;
	virtual ~ScanSingleStrategy() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
public:
	ArrayList<InnerNecessaryCondition>* filterConditions;
	ScanTableMetadata* table;
	AlinousDatabase* database;
private:
	ScanTableIdentifier* tableId;
	ArrayList<ScanTableColumnIdentifier>* joinRequest;
public:
	ITableTargetScanner* getScanner(ScriptMachine* machine, DbTransaction* trx, ArrayList<ScanTableColumnIdentifier>* joinRequest, bool debug, ThreadContext* ctx);
	void optimize(ThreadContext* ctx) throw() ;
	void analyzeFilterCondition(SQLWhere* where, ThreadContext* ctx) throw() ;
	void analyzeIndex(SQLWhere* where, ScanTableMetadata* tableMetadata, bool debug, ThreadContext* ctx);
private:
	ITableTargetScanner* getNoWhereConditionScanner(ScriptMachine* machine, DbTransaction* trx, ArrayList<ScanTableColumnIdentifier>* joinRequest, bool debug, ThreadContext* ctx);
	SingleTableIndexScanner* getIndexScanner(DbTransaction* trx, ScanTableIndexMetadata* indexMeta, ThreadContext* ctx);
	ITableTargetScanner* getFullScanScanner(DbTransaction* trx, ThreadContext* ctx);
	ITableTargetScanner* getCachedFullScanScanner(DbTransaction* trx, ArrayList<ScanTableColumnIdentifier>* joinRequest, bool debug, ThreadContext* ctx);
	ScannedResultIndexScanner* toCachedScanner(DbTransaction* trx, ArrayList<ScanTableColumnIdentifier>* joinRequest, ITableTargetScanner* scanner, bool debug, ThreadContext* ctx);
	ITableTargetScanner* necessaryCollectionScanner(ScriptMachine* machine, DbTransaction* trx, ArrayList<ScanTableColumnIdentifier>* joinRequest, bool debug, ThreadContext* ctx);
	ITableTargetScanner* initOnTheFlyScanner(ScriptMachine* machine, IndexScanStrategyPlan* plan, DbTransaction* trx, ArrayList<ScanTableColumnIdentifier>* joinRequest, InnerNecessaryCondition* necessaryCnd, bool debug, ThreadContext* ctx);
	ITableTargetScanner* initOnTheFlyScanner4Join(ScriptMachine* machine, IndexScanStrategyPlan* plan, DbTransaction* trx, ArrayList<ScanTableColumnIdentifier>* joinRequest, InnerNecessaryCondition* necessaryCnd, ThreadContext* ctx);
public:
	static void includes(BooleanFilterConditionUtil* arg0, ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx);
};

}}}}

#endif /* end of ALINOUS_COMPILE_SQL_ANALYZE_SCANSINGLESTRATEGY_H_ */
