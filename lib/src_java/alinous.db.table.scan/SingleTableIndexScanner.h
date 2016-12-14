#ifndef ALINOUS_DB_TABLE_SCAN_SINGLETABLEINDEXSCANNER_H_
#define ALINOUS_DB_TABLE_SCAN_SINGLETABLEINDEXSCANNER_H_
namespace alinous{namespace annotation{
class OneSource;
}}
namespace alinous {namespace db {namespace table {namespace scan {
class SingleTableIndexScanner;}}}}

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

namespace alinous {namespace db {namespace table {
class TableMetadata;}}}

namespace alinous {namespace db {namespace trx {namespace cache {
class TrxRecordsCache;}}}}

namespace alinous {namespace db {namespace table {namespace scan {
class TableIndexScanner;}}}}

namespace alinous {namespace db {namespace trx {namespace cache {
class TrxRecordCacheIndexScanner;}}}}

namespace alinous {namespace db {namespace trx {namespace scan {
class ScanResultRecord;}}}}

namespace alinous {namespace db {namespace trx {namespace scan {
class ScanResultIndexKey;}}}}

namespace alinous {namespace system {
class ISystemLog;}}

namespace alinous {namespace db {namespace trx {namespace scan {
class IFilterScanner;}}}}

namespace java {namespace io {
class IOException;}}

namespace alinous {namespace db {
class AlinousDbException;}}

namespace alinous {namespace db {namespace table {
class DatabaseException;}}}

namespace alinous {namespace db {namespace table {
class IDatabaseRecord;}}}

namespace alinous {namespace db {namespace trx {namespace scan {
class ScanException;}}}}

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
using ::alinous::compile::sql::analyze::ScanTableIdentifier;
using ::alinous::db::AlinousDbException;
using ::alinous::db::table::DatabaseException;
using ::alinous::db::table::IDatabaseRecord;
using ::alinous::db::table::IDatabaseTable;
using ::alinous::db::table::IScannableIndex;
using ::alinous::db::table::TableMetadata;
using ::alinous::db::trx::DbTransaction;
using ::alinous::db::trx::cache::TrxRecordCacheIndex;
using ::alinous::db::trx::cache::TrxRecordCacheIndexScanner;
using ::alinous::db::trx::cache::TrxRecordsCache;
using ::alinous::db::trx::scan::IFilterScanner;
using ::alinous::db::trx::scan::ScanException;
using ::alinous::db::trx::scan::ScanResultIndexKey;
using ::alinous::db::trx::scan::ScanResultRecord;
using ::alinous::system::ISystemLog;



class SingleTableIndexScanner final : public IFilterScanner, public virtual IObject {
public:
	SingleTableIndexScanner(const SingleTableIndexScanner& base) = default;
public:
	SingleTableIndexScanner(ThreadContext* ctx) throw()  : IObject(ctx), IFilterScanner(ctx), trx(nullptr), scanner(nullptr), insertScanner(nullptr), updateScanner(nullptr), result(nullptr)
	{
	}
	void __construct_impl(ThreadContext* ctx) throw() 
	{
	}
	virtual ~SingleTableIndexScanner() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	DbTransaction* trx;
	TableIndexScanner* scanner;
	TrxRecordCacheIndexScanner* insertScanner;
	TrxRecordCacheIndexScanner* updateScanner;
	ScanResultRecord* result;
public:
	SingleTableIndexScanner* init(ScanTableIdentifier* tableId, DbTransaction* trx, IScannableIndex* index, IDatabaseTable* tableStore, TrxRecordCacheIndex* insertCacheindex, TrxRecordCacheIndex* updateCacheindex, int lockMode, ThreadContext* ctx);
	bool hasNext(bool debug, ThreadContext* ctx) final;
	ScanResultRecord* next(bool debug, ThreadContext* ctx) final;
	void startScan(ScanResultIndexKey* indexKeyValue, ThreadContext* ctx) final;
	void endScan(ThreadContext* ctx) final;
	void dispose(ISystemLog* logger, ThreadContext* ctx) final;
private:
	void startsWithKey(ScanResultIndexKey* indexKeyValue, ThreadContext* ctx);
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}}}

#endif /* end of ALINOUS_DB_TABLE_SCAN_SINGLETABLEINDEXSCANNER_H_ */
