#ifndef ALINOUS_DB_TABLE_IDATABASETABLE_H_
#define ALINOUS_DB_TABLE_IDATABASETABLE_H_
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

namespace alinous {namespace db {
class AlinousDatabase;}}

namespace alinous {namespace db {namespace trx {namespace cache {
class CachedRecord;}}}}

namespace alinous {namespace runtime {namespace parallel {
class SequentialBackgroundJob;}}}

namespace alinous {namespace system {
class ISystemLog;}}

namespace java {namespace io {
class IOException;}}

namespace alinous {namespace btree {
class BTreeException;}}

namespace alinous {namespace db {
class AlinousDbException;}}

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

namespace alinous {namespace db {namespace table {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::java::io::IOException;
using ::java::util::ArrayList;
using ::alinous::btree::BTreeException;
using ::alinous::compile::sql::analyze::ScanTableColumnIdentifier;
using ::alinous::db::AlinousDatabase;
using ::alinous::db::AlinousDbException;
using ::alinous::db::table::lockmonitor::DatabaseLockException;
using ::alinous::db::table::lockmonitor::IThreadLocker;
using ::alinous::db::trx::cache::CachedRecord;
using ::alinous::runtime::dom::VariableException;
using ::alinous::runtime::parallel::SequentialBackgroundJob;
using ::alinous::system::AlinousException;
using ::alinous::system::ISystemLog;



class IDatabaseTable : public virtual IObject {
public:
	IDatabaseTable(const IDatabaseTable& base) = default;
public:
	IDatabaseTable(ThreadContext* ctx) throw()  : IObject(ctx)
	{
	}
	void __construct_impl(ThreadContext* ctx) throw() 
	{
	}
	virtual ~IDatabaseTable() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
public:
	virtual Integer* getTableId(ThreadContext* ctx) throw()  = 0;
	virtual int getColumnCount(ThreadContext* ctx) throw()  = 0;
	virtual IScannableIndex* getTableIndexByColIds(ArrayList<ScanTableColumnIdentifier>* colIdList, ThreadContext* ctx) throw()  = 0;
	virtual IScannableIndex* getPrimaryIndex(ThreadContext* ctx) throw()  = 0;
	virtual TableMetadata* getMetadata(ThreadContext* ctx) throw()  = 0;
	virtual IDatabaseRecord* loadRecord(long long position, ThreadContext* ctx) = 0;
	virtual IScannableIndex* getAbailableIndex(ArrayList<String>* columnsStr, ThreadContext* ctx) throw()  = 0;
	virtual IScannableIndex* getAbailableIndexByScanColId(ArrayList<ScanTableColumnIdentifier>* joinRequest, ThreadContext* ctx) throw()  = 0;
	virtual IThreadLocker* newThreadLocker(String* fullName, ThreadContext* ctx) throw()  = 0;
	virtual bool hasLaterVersion(long long oid, long long currentId, ThreadContext* ctx) = 0;
	virtual bool hasLaterVersionBefore(long long oid, long long maxCommitId, long long currentCommitId, ThreadContext* ctx) = 0;
	virtual String* getName(ThreadContext* ctx) throw()  = 0;
	virtual void open(AlinousDatabase* database, ThreadContext* ctx) = 0;
	virtual void createTable(TableMetadata* tableMetadata, AlinousDatabase* database, ThreadContext* ctx) = 0;
	virtual void lockStorage(ThreadContext* ctx) = 0;
	virtual void unlockStorage(ThreadContext* ctx) = 0;
	virtual ArrayList<IScannableIndex>* getIndexes(ThreadContext* ctx) throw()  = 0;
	virtual void insertData(CachedRecord* record, long long newCommitId, IArrayObject<SequentialBackgroundJob>* jobs, ISystemLog* logger, ThreadContext* ctx) = 0;
	virtual void updateData(CachedRecord* record, long long newCommitId, IArrayObject<SequentialBackgroundJob>* jobs, ISystemLog* logger, ThreadContext* ctx) = 0;
	virtual void createIndex(String* getindexName, ArrayList<String>* columns, AlinousDatabase* database, ThreadContext* ctx) = 0;
	virtual void close(ThreadContext* ctx) throw()  = 0;
	virtual String* getFullName(ThreadContext* ctx) throw()  = 0;
	virtual void updateUnlockRow(long long oid, IThreadLocker* locker, ThreadContext* ctx) = 0;
	virtual void updateLockRow(long long oid, IThreadLocker* locker, ThreadContext* ctx) = 0;
	virtual void shareUnlockRow(long long oid, IThreadLocker* locker, ThreadContext* ctx) = 0;
	virtual void shareLockRow(long long oid, IThreadLocker* locker, ThreadContext* ctx) = 0;
	virtual void shareUnlockTable(IThreadLocker* locker, ThreadContext* ctx) = 0;
	virtual void shareLockTable(IThreadLocker* locker, ThreadContext* ctx) = 0;
	virtual void updateUnlockTable(IThreadLocker* locker, ThreadContext* ctx) = 0;
	virtual void updateLockTable(IThreadLocker* locker, ThreadContext* ctx) = 0;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}}

#endif /* end of ALINOUS_DB_TABLE_IDATABASETABLE_H_ */
