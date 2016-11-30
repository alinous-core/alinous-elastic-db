#ifndef ALINOUS_DB_TABLE_SCAN_INDEXLISTSCANNER_H_
#define ALINOUS_DB_TABLE_SCAN_INDEXLISTSCANNER_H_
namespace alinous{namespace annotation{
class OneSource;
}}
namespace alinous {namespace db {namespace table {namespace scan {
class IndexListScanner;}}}}

namespace alinous {namespace compile {namespace sql {namespace analyze {
class ScanTableIdentifier;}}}}

namespace alinous {namespace db {namespace trx {
class DbTransaction;}}}

namespace alinous {namespace db {namespace table {
class IScannableIndex;}}}

namespace alinous {namespace db {namespace table {
class IDatabaseTable;}}}

namespace alinous {namespace db {namespace trx {namespace cache {
class TrxRecordCacheIndex;}}}}

namespace alinous {namespace db {namespace table {namespace scan {
class IndexListScannerParam;}}}}

namespace alinous {namespace compile {namespace sql {namespace analyze {
class InnerNecessaryCondition;}}}}

namespace alinous {namespace runtime {namespace engine {
class ScriptMachine;}}}

namespace alinous {namespace db {namespace table {
class TableMetadata;}}}

namespace alinous {namespace db {namespace trx {namespace cache {
class TrxRecordsCache;}}}}

namespace alinous {namespace db {namespace table {namespace scan {
class TableIndexScanner;}}}}

namespace alinous {namespace db {namespace trx {namespace cache {
class TrxRecordCacheIndexScanner;}}}}

namespace alinous {namespace db {namespace trx {namespace scan {
class ScanResultIndexKey;}}}}

namespace alinous {namespace db {namespace table {
class TableColumnMetadata;}}}

namespace alinous {namespace runtime {namespace variant {
class VariantValue;}}}

namespace alinous {namespace db {namespace trx {namespace scan {
class ScanResultRecord;}}}}

namespace alinous {namespace system {
class ISystemLog;}}

namespace alinous {namespace db {namespace trx {namespace scan {
class ITableTargetScanner;}}}}

namespace java {namespace io {
class IOException;}}

namespace alinous {namespace db {
class AlinousDbException;}}

namespace alinous {namespace db {namespace table {
class DatabaseException;}}}

namespace alinous {namespace db {namespace table {
class IDatabaseRecord;}}}

namespace alinous {namespace db {namespace table {namespace lockmonitor {
class DatabaseLockException;}}}}

namespace alinous {namespace db {namespace trx {namespace scan {
class ScanException;}}}}

namespace alinous {namespace system {
class AlinousException;}}

namespace java {namespace lang {
class IObject;
}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace db {namespace table {namespace scan {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::java::io::IOException;
using ::java::util::ArrayList;
using ::alinous::compile::sql::analyze::InnerNecessaryCondition;
using ::alinous::compile::sql::analyze::ScanTableIdentifier;
using ::alinous::db::AlinousDbException;
using ::alinous::db::table::DatabaseException;
using ::alinous::db::table::IDatabaseRecord;
using ::alinous::db::table::IDatabaseTable;
using ::alinous::db::table::IScannableIndex;
using ::alinous::db::table::TableColumnMetadata;
using ::alinous::db::table::TableMetadata;
using ::alinous::db::table::lockmonitor::DatabaseLockException;
using ::alinous::db::trx::DbTransaction;
using ::alinous::db::trx::cache::TrxRecordCacheIndex;
using ::alinous::db::trx::cache::TrxRecordCacheIndexScanner;
using ::alinous::db::trx::cache::TrxRecordsCache;
using ::alinous::db::trx::scan::ITableTargetScanner;
using ::alinous::db::trx::scan::ScanException;
using ::alinous::db::trx::scan::ScanResultIndexKey;
using ::alinous::db::trx::scan::ScanResultRecord;
using ::alinous::runtime::engine::ScriptMachine;
using ::alinous::runtime::variant::VariantValue;
using ::alinous::system::AlinousException;
using ::alinous::system::ISystemLog;



class IndexListScanner final : public ITableTargetScanner, public virtual IObject {
public:
	IndexListScanner(const IndexListScanner& base) = default;
public:
	IndexListScanner(ThreadContext* ctx) throw()  : IObject(ctx), ITableTargetScanner(ctx), trx(nullptr), machine(nullptr), scanner(nullptr), insertScanner(nullptr), updateScanner(nullptr), param(nullptr), effectiveKeyLength(0), meta(nullptr), result(nullptr), necessaryCondition(nullptr), currentKey(nullptr)
	{
	}
	void __construct_impl(ThreadContext* ctx) throw() 
	{
	}
	virtual ~IndexListScanner() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	DbTransaction* trx;
	ScriptMachine* machine;
	TableIndexScanner* scanner;
	TrxRecordCacheIndexScanner* insertScanner;
	TrxRecordCacheIndexScanner* updateScanner;
	IndexListScannerParam* param;
	int effectiveKeyLength;
	ArrayList<TableColumnMetadata>* meta;
	ScanResultRecord* result;
	InnerNecessaryCondition* necessaryCondition;
	ScanResultIndexKey* currentKey;
public:
	IndexListScanner* init(ScanTableIdentifier* tableId, DbTransaction* trx, IScannableIndex* index, IDatabaseTable* tableStore, TrxRecordCacheIndex* insertCacheindex, TrxRecordCacheIndex* updateCacheindex, int lockMode, IndexListScannerParam* param, int effectiveKeyLength, InnerNecessaryCondition* necessaryCondition, ScriptMachine* machine, ThreadContext* ctx);
	void startScan(ScanResultIndexKey* indexKeyValue, ThreadContext* ctx) final;
	bool hasNext(bool debug, ThreadContext* ctx) final;
	void endScan(ThreadContext* ctx) final;
	ScanResultRecord* next(bool debug, ThreadContext* ctx) final;
	void dispose(ISystemLog* logger, ThreadContext* ctx) final;
private:
	void startNextKey(ThreadContext* ctx);
	void onceCloseScan(ThreadContext* ctx);
	bool hasNext4CurrentKey(bool debug, ThreadContext* ctx);
	bool checkEquals(ThreadContext* ctx) throw() ;
	bool satisfyNececity(bool debug, ThreadContext* ctx);
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}}}

#endif /* end of ALINOUS_DB_TABLE_SCAN_INDEXLISTSCANNER_H_ */
