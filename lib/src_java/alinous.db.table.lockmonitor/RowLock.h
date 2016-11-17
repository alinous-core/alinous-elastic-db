#ifndef ALINOUS_DB_TABLE_LOCKMONITOR_ROWLOCK_H_
#define ALINOUS_DB_TABLE_LOCKMONITOR_ROWLOCK_H_
namespace alinous {namespace db {namespace table {
class DatabaseTable;}}}

namespace alinous {namespace db {namespace table {namespace lockmonitor {
class ThreadLocker;}}}}

namespace alinous {namespace lock {
class ConcurrentGate;}}

namespace alinous {namespace db {namespace table {namespace lockmonitor {
class DatabaseLockException;}}}}

namespace java {namespace lang {
class InterruptedException;}}

namespace alinous {namespace db {namespace table {namespace lockmonitor {
class ConcurrentGatePool;}}}}

namespace alinous {namespace db {namespace table {namespace lockmonitor {
class IDatabaseLock;}}}}

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
using ::alinous::db::table::DatabaseTable;
using ::alinous::lock::ConcurrentGate;



class RowLock final : public IDatabaseLock, public virtual IObject {
public:
	RowLock(const RowLock& base) = default;
public:
	RowLock(DatabaseTable* table, long long oid, bool update, ThreadLocker* locker, ConcurrentGate* gate, ThreadContext* ctx) throw() ;
	void __construct_impl(DatabaseTable* table, long long oid, bool update, ThreadLocker* locker, ConcurrentGate* gate, ThreadContext* ctx) throw() ;
	virtual ~RowLock() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
public:
	bool update;
	DatabaseTable* table;
	long long oid;
	ThreadLocker* locker;
	ConcurrentGate* gate;
	int count;
	bool pushBack;
public:
	void lock(ThreadContext* ctx);
	void unlock(ConcurrentGatePool* gatePool, ThreadContext* ctx);
	int getLockType(ThreadContext* ctx) throw()  final;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}}}

#endif /* end of ALINOUS_DB_TABLE_LOCKMONITOR_ROWLOCK_H_ */
