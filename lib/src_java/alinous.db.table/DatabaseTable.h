#ifndef ALINOUS_DB_TABLE_DATABASETABLE_H_
#define ALINOUS_DB_TABLE_DATABASETABLE_H_
namespace alinous{namespace annotation{
class OneSource;
}}
namespace alinous {namespace runtime {namespace parallel {
class ThreadPool;}}}

namespace alinous {namespace db {namespace table {namespace cache {
class RecordCacheEngine;}}}}

namespace alinous {namespace db {namespace table {namespace lockmonitor {
class DBThreadMonitor;}}}}

namespace alinous {namespace db {namespace table {
class IScannableIndex;}}}

namespace java {namespace util {
template <typename  T> class List;}}

namespace alinous {namespace db {namespace table {
class TableColumnMetadata;}}}

namespace alinous {namespace compile {namespace sql {namespace analyze {
class ScanTableColumnIdentifier;}}}}

namespace alinous {namespace db {namespace table {namespace lockmonitor {
class IThreadLocker;}}}}

namespace alinous {namespace db {namespace trx {
class DbTransaction;}}}

namespace alinous {namespace remote {namespace region {namespace client {namespace command {
class AbstractNodeRegionCommand;}}}}}

namespace alinous {namespace db {namespace table {
class DatatableUpdateSupport;}}}

namespace alinous {namespace db {
class AlinousDbException;}}

namespace alinous {namespace db {namespace table {namespace lockmonitor {
class DatabaseLockException;}}}}

namespace alinous {namespace system {
class AlinousException;}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace db {namespace table {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::java::util::ArrayList;
using ::java::util::List;
using ::alinous::compile::sql::analyze::ScanTableColumnIdentifier;
using ::alinous::db::AlinousDbException;
using ::alinous::db::table::cache::RecordCacheEngine;
using ::alinous::db::table::lockmonitor::DBThreadMonitor;
using ::alinous::db::table::lockmonitor::DatabaseLockException;
using ::alinous::db::table::lockmonitor::IThreadLocker;
using ::alinous::db::trx::DbTransaction;
using ::alinous::remote::region::client::command::AbstractNodeRegionCommand;
using ::alinous::runtime::parallel::ThreadPool;
using ::alinous::system::AlinousException;



class DatabaseTable final : public DatatableUpdateSupport {
public:
	DatabaseTable(const DatabaseTable& base) = default;
public:
	DatabaseTable(String* schema, String* name, String* baseDir, ThreadPool* threadPool, ThreadContext* ctx);
	void __construct_impl(String* schema, String* name, String* baseDir, ThreadPool* threadPool, ThreadContext* ctx);
	virtual ~DatabaseTable() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	DBThreadMonitor* monitor;
public:
	IScannableIndex* getTableUniqueIndexByCols(List<TableColumnMetadata>* columns, ThreadContext* ctx) throw()  final;
	IScannableIndex* getTableIndexByColIds(ArrayList<ScanTableColumnIdentifier>* columns, ThreadContext* ctx) throw()  final;
	IScannableIndex* getAbailableIndex(ArrayList<String>* columns, ThreadContext* ctx) throw()  final;
	IScannableIndex* getAbailableIndexByScanColId(ArrayList<ScanTableColumnIdentifier>* columns, ThreadContext* ctx) throw()  final;
	IScannableIndex* getTableIndex(ArrayList<String>* columns, ThreadContext* ctx) throw()  final;
	IThreadLocker* newThreadLocker(String* fullName, ThreadContext* ctx) throw()  final;
	void updateLockTable(IThreadLocker* locker, ThreadContext* ctx) final;
	void updateUnlockTable(IThreadLocker* locker, ThreadContext* ctx) final;
	void shareLockTable(IThreadLocker* locker, ThreadContext* ctx) final;
	void shareUnlockTable(IThreadLocker* locker, ThreadContext* ctx) final;
	void shareLockRow(long long oid, IThreadLocker* locker, ThreadContext* ctx) final;
	void shareUnlockRow(long long oid, IThreadLocker* locker, ThreadContext* ctx) final;
	void updateLockRow(long long oid, IThreadLocker* locker, ThreadContext* ctx) final;
	void updateUnlockRow(long long oid, IThreadLocker* locker, ThreadContext* ctx) final;
	void finishCommitSession(DbTransaction* trx, long long newCommitId, ThreadContext* ctx) final;
	AbstractNodeRegionCommand* sendCommand(AbstractNodeRegionCommand* cmd, ThreadContext* ctx) final;
private:
	bool matchUniqueIndexByIdList(ArrayList<TableColumnMetadata>* columnsMetadataList, List<TableColumnMetadata>* columns, ThreadContext* ctx) throw() ;
	bool matchIndexByIdList(ArrayList<TableColumnMetadata>* columnsMetadataList, ArrayList<ScanTableColumnIdentifier>* columns, ThreadContext* ctx) throw() ;
	bool matchIndexByStrList(ArrayList<TableColumnMetadata>* columnsMetadataList, ArrayList<String>* columns, ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx);
};

}}}

#endif /* end of ALINOUS_DB_TABLE_DATABASETABLE_H_ */
