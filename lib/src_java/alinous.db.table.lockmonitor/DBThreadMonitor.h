#ifndef ALINOUS_DB_TABLE_LOCKMONITOR_DBTHREADMONITOR_H_
#define ALINOUS_DB_TABLE_LOCKMONITOR_DBTHREADMONITOR_H_
namespace alinous {namespace runtime {namespace parallel {
class ThreadPool;}}}

namespace alinous {namespace db {namespace table {namespace lockmonitor {namespace db {
class TableLockHashDb;}}}}}

namespace alinous {namespace db {namespace table {namespace lockmonitor {namespace db {
class RowLockDb;}}}}}

namespace alinous {namespace db {namespace table {namespace lockmonitor {
class ConcurrentGatePool;}}}}

namespace alinous {namespace db {namespace table {namespace lockmonitor {
class IThreadLocker;}}}}

namespace alinous {namespace db {namespace table {namespace lockmonitor {
class ThreadLocker;}}}}

namespace alinous {namespace db {namespace table {
class IDatabaseTable;}}}

namespace alinous {namespace db {namespace table {namespace lockmonitor {namespace db {
class TableLockMamager;}}}}}

namespace alinous {namespace db {namespace table {namespace lockmonitor {
class TableLock;}}}}

namespace java {namespace lang {
class Throwable;}}

namespace alinous {namespace db {namespace table {namespace lockmonitor {
class RowLock;}}}}

namespace alinous {namespace db {namespace table {namespace lockmonitor {namespace db {
class RowLockManager;}}}}}

namespace alinous {namespace lock {
class LockObject;}}

namespace alinous {namespace concurrent {
class SpinMutex;}}

namespace java {namespace lang {
class IObject;
}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace db {namespace table {namespace lockmonitor {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::java::util::ArrayList;
using ::alinous::concurrent::SpinMutex;
using ::alinous::db::table::IDatabaseTable;
using ::alinous::db::table::lockmonitor::db::RowLockDb;
using ::alinous::db::table::lockmonitor::db::RowLockManager;
using ::alinous::db::table::lockmonitor::db::TableLockHashDb;
using ::alinous::db::table::lockmonitor::db::TableLockMamager;
using ::alinous::lock::LockObject;
using ::alinous::runtime::parallel::ThreadPool;



class DBThreadMonitor final : public virtual IObject {
public:
	DBThreadMonitor(const DBThreadMonitor& base) = default;
public:
	DBThreadMonitor(ThreadPool* threadPool, ThreadContext* ctx) throw() ;
	void __construct_impl(ThreadPool* threadPool, ThreadContext* ctx) throw() ;
	virtual ~DBThreadMonitor() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	ArrayList<ThreadLocker>* threads;
	LockObject* threadLock;
	TableLockHashDb* tableLockDb;
	RowLockDb* rowLockDb;
	ConcurrentGatePool* gatePool;
	ThreadPool* threadPool;
	SpinMutex* globalLock;
public:
	IThreadLocker* newThread(ThreadContext* ctx) throw() ;
	void lockTable(IDatabaseTable* table, IThreadLocker* locker, bool update, ThreadContext* ctx);
	void unlockTable(IDatabaseTable* table, IThreadLocker* locker, ThreadContext* ctx);
	void unlockRow(IDatabaseTable* table, long long oid, IThreadLocker* locker, ThreadContext* ctx);
	void lockRow(IDatabaseTable* table, long long oid, IThreadLocker* locker, bool update, ThreadContext* ctx);
	ThreadPool* getThreadPool(ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}}}

#endif /* end of ALINOUS_DB_TABLE_LOCKMONITOR_DBTHREADMONITOR_H_ */
