#ifndef ALINOUS_DB_TABLE_LOCKMONITOR_THREADLOCKER_H_
#define ALINOUS_DB_TABLE_LOCKMONITOR_THREADLOCKER_H_
namespace alinous {namespace db {namespace table {namespace lockmonitor {
class DBThreadMonitor;}}}}

namespace alinous {namespace db {namespace table {
class DatabaseTable;}}}

namespace alinous {namespace db {namespace table {namespace lockmonitor {
class IDatabaseLock;}}}}

namespace alinous {namespace db {namespace table {namespace lockmonitor {
class TableLock;}}}}

namespace alinous {namespace db {namespace table {namespace lockmonitor {
class RowLock;}}}}

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
using ::alinous::db::table::DatabaseTable;



class ThreadLocker final : public virtual IObject {
public:
	ThreadLocker(const ThreadLocker& base) = default;
public:
	ThreadLocker(DBThreadMonitor* monitor, ThreadContext* ctx) throw() ;
	void __construct_impl(DBThreadMonitor* monitor, ThreadContext* ctx) throw() ;
	virtual ~ThreadLocker() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
public:
	IDatabaseLock* blockingLock;
	ArrayList<TableLock>* tableLocks;
	ArrayList<RowLock>* rowLocks;
private:
	DBThreadMonitor* monitor;
public:
	void updateLockTable(DatabaseTable* table, ThreadContext* ctx);
	void updateUnlockTable(DatabaseTable* table, ThreadContext* ctx);
	void shareLockTable(DatabaseTable* table, ThreadContext* ctx);
	void shareUnlockTable(DatabaseTable* table, ThreadContext* ctx);
	void shareLockRow(DatabaseTable* table, long long oid, ThreadContext* ctx);
	void shareUnlockRow(DatabaseTable* table, long long oid, ThreadContext* ctx);
	void updateLockRow(DatabaseTable* table, long long oid, ThreadContext* ctx);
	void updateUnlockRow(DatabaseTable* table, long long oid, ThreadContext* ctx);
	bool checkContention(IDatabaseLock* lock, ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}}}

#endif /* end of ALINOUS_DB_TABLE_LOCKMONITOR_THREADLOCKER_H_ */
