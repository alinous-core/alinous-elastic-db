#ifndef ALINOUS_REMOTE_REGION_CLIENT_DATABASETABLECLIENT_H_
#define ALINOUS_REMOTE_REGION_CLIENT_DATABASETABLECLIENT_H_
namespace java {namespace lang {
class Integer;}}

namespace alinous {namespace db {namespace table {
class IScannableIndex;}}}

namespace alinous {namespace compile {namespace sql {namespace analyze {
class ScanTableColumnIdentifier;}}}}

namespace alinous {namespace db {namespace table {
class TableMetadata;}}}

namespace alinous {namespace db {namespace table {
class IDatabaseRecord;}}}

namespace alinous {namespace db {namespace table {namespace lockmonitor {
class IThreadLocker;}}}}

namespace alinous {namespace system {
class AlinousCore;}}

namespace alinous {namespace btree {
class BTreeGlobalCache;}}

namespace alinous {namespace runtime {namespace parallel {
class ThreadPool;}}}

namespace alinous {namespace db {namespace trx {namespace cache {
class CachedRecord;}}}}

namespace alinous {namespace runtime {namespace parallel {
class SequentialBackgroundJob;}}}

namespace alinous {namespace system {
class ISystemLog;}}

namespace alinous {namespace db {namespace table {
class IDatabaseTable;}}}

namespace java {namespace io {
class IOException;}}

namespace alinous {namespace btree {
class BTreeException;}}

namespace alinous {namespace db {
class AlinousDbException;}}

namespace alinous {namespace db {namespace table {
class DatabaseException;}}}

namespace alinous {namespace db {namespace table {namespace lockmonitor {
class DatabaseLockException;}}}}

namespace alinous {namespace runtime {namespace dom {
class VariableException;}}}

namespace alinous {namespace system {
class AlinousException;}}

namespace java {namespace lang {
class IObject;
}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace remote {namespace region {namespace client {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::java::io::IOException;
using ::java::util::ArrayList;
using ::alinous::btree::BTreeException;
using ::alinous::btree::BTreeGlobalCache;
using ::alinous::compile::sql::analyze::ScanTableColumnIdentifier;
using ::alinous::db::AlinousDbException;
using ::alinous::db::table::DatabaseException;
using ::alinous::db::table::IDatabaseRecord;
using ::alinous::db::table::IDatabaseTable;
using ::alinous::db::table::IScannableIndex;
using ::alinous::db::table::TableMetadata;
using ::alinous::db::table::lockmonitor::DatabaseLockException;
using ::alinous::db::table::lockmonitor::IThreadLocker;
using ::alinous::db::trx::cache::CachedRecord;
using ::alinous::runtime::dom::VariableException;
using ::alinous::runtime::parallel::SequentialBackgroundJob;
using ::alinous::runtime::parallel::ThreadPool;
using ::alinous::system::AlinousCore;
using ::alinous::system::AlinousException;
using ::alinous::system::ISystemLog;



class DatabaseTableClient final : public IDatabaseTable, public virtual IObject {
public:
	DatabaseTableClient(const DatabaseTableClient& base) = default;
public:
	DatabaseTableClient(ThreadContext* ctx) throw()  : IObject(ctx), IDatabaseTable(ctx)
	{
	}
	void __construct_impl(ThreadContext* ctx) throw() 
	{
	}
	virtual ~DatabaseTableClient() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
public:
	Integer* getTableId(ThreadContext* ctx) throw()  final;
	int getColumnCount(ThreadContext* ctx) throw()  final;
	IScannableIndex* getTableIndexByColIds(ArrayList<ScanTableColumnIdentifier>* colIdList, ThreadContext* ctx) throw()  final;
	IScannableIndex* getPrimaryIndex(ThreadContext* ctx) throw()  final;
	TableMetadata* getMetadata(ThreadContext* ctx) throw()  final;
	IDatabaseRecord* loadRecord(long long position, ThreadContext* ctx) final;
	IScannableIndex* getAbailableIndex(ArrayList<String>* columnsStr, ThreadContext* ctx) throw()  final;
	IScannableIndex* getAbailableIndexByScanColId(ArrayList<ScanTableColumnIdentifier>* joinRequest, ThreadContext* ctx) throw()  final;
	IScannableIndex* getTableIndex(ArrayList<String>* columns, ThreadContext* ctx) throw()  final;
	IThreadLocker* newThreadLocker(String* fullName, ThreadContext* ctx) throw()  final;
	void updateUnlockRow(long long oid, IThreadLocker* locker, ThreadContext* ctx) final;
	void updateLockRow(long long oid, IThreadLocker* locker, ThreadContext* ctx) final;
	void shareUnlockRow(long long oid, IThreadLocker* locker, ThreadContext* ctx) final;
	void shareLockRow(long long oid, IThreadLocker* locker, ThreadContext* ctx) final;
	void shareUnlockTable(IThreadLocker* locker, ThreadContext* ctx) final;
	void shareLockTable(IThreadLocker* locker, ThreadContext* ctx) final;
	void updateUnlockTable(IThreadLocker* locker, ThreadContext* ctx) final;
	void updateLockTable(IThreadLocker* locker, ThreadContext* ctx) final;
	bool hasLaterVersion(long long oid, long long currentId, ThreadContext* ctx) final;
	bool hasLaterVersionBefore(long long oid, long long maxCommitId, long long currentCommitId, ThreadContext* ctx) final;
	String* getName(ThreadContext* ctx) throw()  final;
	void open(AlinousCore* core, BTreeGlobalCache* cache, ThreadContext* ctx) final;
	void createTable(TableMetadata* metadata, ThreadPool* threadPool, AlinousCore* core, BTreeGlobalCache* cache, ThreadContext* ctx) final;
	void lockStorage(ThreadContext* ctx) final;
	void unlockStorage(ThreadContext* ctx) final;
	ArrayList<IScannableIndex>* getIndexes(ThreadContext* ctx) throw()  final;
	void insertData(CachedRecord* record, long long newCommitId, IArrayObject<SequentialBackgroundJob>* jobs, ISystemLog* logger, ThreadContext* ctx) final;
	void updateData(CachedRecord* record, long long newCommitId, IArrayObject<SequentialBackgroundJob>* jobs, ISystemLog* logger, ThreadContext* ctx) final;
	void createIndex(String* getindexName, ArrayList<String>* columns, AlinousCore* core, BTreeGlobalCache* cache, ThreadContext* ctx) final;
	void close(ThreadContext* ctx) throw()  final;
	String* getFullName(ThreadContext* ctx) throw()  final;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}}}

#endif /* end of ALINOUS_REMOTE_REGION_CLIENT_DATABASETABLECLIENT_H_ */
