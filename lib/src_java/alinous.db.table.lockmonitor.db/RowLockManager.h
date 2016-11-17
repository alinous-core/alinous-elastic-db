#ifndef ALINOUS_DB_TABLE_LOCKMONITOR_DB_ROWLOCKMANAGER_H_
#define ALINOUS_DB_TABLE_LOCKMONITOR_DB_ROWLOCKMANAGER_H_
namespace alinous {namespace db {namespace table {
class DatabaseTable;}}}

namespace alinous {namespace lock {
class ConcurrentGate;}}

namespace alinous {namespace db {namespace table {namespace lockmonitor {
class RowLock;}}}}

namespace alinous {namespace db {namespace table {namespace lockmonitor {
class ThreadLocker;}}}}

namespace alinous {namespace db {namespace table {namespace lockmonitor {
class IDatabaseLock;}}}}

namespace java {namespace lang {
class IObject;
}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace db {namespace table {namespace lockmonitor {namespace db {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::java::util::ArrayList;
using ::alinous::db::table::DatabaseTable;
using ::alinous::db::table::lockmonitor::IDatabaseLock;
using ::alinous::db::table::lockmonitor::RowLock;
using ::alinous::db::table::lockmonitor::ThreadLocker;
using ::alinous::lock::ConcurrentGate;



class RowLockManager final : public virtual IObject {
public:
	RowLockManager(const RowLockManager& base) = default;
public:
	RowLockManager(DatabaseTable* table, long long oid, ConcurrentGate* concurrentGate, ThreadContext* ctx) throw() ;
	void __construct_impl(DatabaseTable* table, long long oid, ConcurrentGate* concurrentGate, ThreadContext* ctx) throw() ;
	virtual ~RowLockManager() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
public:
	DatabaseTable* table;
	long long oid;
	ArrayList<RowLock>* list;
private:
	ConcurrentGate* concurrentGate;
public:
	ConcurrentGate* getConcurrentGate(ThreadContext* ctx) throw() ;
	RowLock* newLock(ThreadLocker* locker, bool update, ThreadContext* ctx) throw() ;
	bool checkDedLock(ThreadLocker* locker, ThreadContext* ctx) throw() ;
	RowLock* releaseLock(ThreadLocker* locker, ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}}}}

#endif /* end of ALINOUS_DB_TABLE_LOCKMONITOR_DB_ROWLOCKMANAGER_H_ */
