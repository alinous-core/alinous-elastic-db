#ifndef ALINOUS_REMOTE_REGION_CLIENT_SCAN_REMOTEINDEXRANGESCANNER_H_
#define ALINOUS_REMOTE_REGION_CLIENT_SCAN_REMOTEINDEXRANGESCANNER_H_
namespace alinous {namespace remote {namespace region {namespace client {namespace scan {
class RemoteIndexRangeScanner;}}}}}

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
class IndexRangeScannerParam;}}}}

namespace alinous {namespace compile {namespace sql {namespace analyze {
class InnerNecessaryCondition;}}}}

namespace alinous {namespace runtime {namespace engine {
class ScriptMachine;}}}

namespace alinous {namespace db {namespace trx {namespace scan {
class ScanResultIndexKey;}}}}

namespace alinous {namespace db {namespace trx {namespace scan {
class ScanResultRecord;}}}}

namespace alinous {namespace system {
class ISystemLog;}}

namespace alinous {namespace remote {namespace region {namespace client {namespace scan {
class IRemoteScanner;}}}}}

namespace java {namespace io {
class IOException;}}

namespace alinous {namespace db {
class AlinousDbException;}}

namespace alinous {namespace db {namespace table {
class DatabaseException;}}}

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

namespace alinous {namespace remote {namespace region {namespace client {namespace scan {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::java::io::IOException;
using ::alinous::compile::sql::analyze::InnerNecessaryCondition;
using ::alinous::compile::sql::analyze::ScanTableIdentifier;
using ::alinous::db::AlinousDbException;
using ::alinous::db::table::DatabaseException;
using ::alinous::db::table::IDatabaseTable;
using ::alinous::db::table::IScannableIndex;
using ::alinous::db::table::scan::IndexRangeScannerParam;
using ::alinous::db::trx::DbTransaction;
using ::alinous::db::trx::cache::TrxRecordCacheIndex;
using ::alinous::db::trx::scan::ScanException;
using ::alinous::db::trx::scan::ScanResultIndexKey;
using ::alinous::db::trx::scan::ScanResultRecord;
using ::alinous::runtime::engine::ScriptMachine;
using ::alinous::system::AlinousException;
using ::alinous::system::ISystemLog;



class RemoteIndexRangeScanner final : public IRemoteScanner, public virtual IObject {
public:
	RemoteIndexRangeScanner(const RemoteIndexRangeScanner& base) = default;
public:
	RemoteIndexRangeScanner(ThreadContext* ctx) throw() ;
	void __construct_impl(ThreadContext* ctx) throw() ;
	virtual ~RemoteIndexRangeScanner() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
public:
	RemoteIndexRangeScanner* init(ScanTableIdentifier* tableId, DbTransaction* trx, IScannableIndex* index, IDatabaseTable* tableStore, TrxRecordCacheIndex* insertCacheindex, TrxRecordCacheIndex* updateCacheindex, int lockMode, IndexRangeScannerParam* param, int effectiveKeyLength, InnerNecessaryCondition* necessaryCondition, ScriptMachine* machine, ThreadContext* ctx);
	void startScan(ScanResultIndexKey* indexKeyValue, ThreadContext* ctx) final;
	void endScan(ThreadContext* ctx) final;
	bool hasNext(bool debug, ThreadContext* ctx) final;
	ScanResultRecord* next(bool debug, ThreadContext* ctx) final;
	void dispose(ISystemLog* logger, ThreadContext* ctx) final;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx);
};

}}}}}

#endif /* end of ALINOUS_REMOTE_REGION_CLIENT_SCAN_REMOTEINDEXRANGESCANNER_H_ */
