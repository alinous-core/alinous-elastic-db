#ifndef ALINOUS_DB_TABLE_LOCKMONITOR_ROWLOCK_H_
#define ALINOUS_DB_TABLE_LOCKMONITOR_ROWLOCK_H_
namespace alinous {namespace db {namespace table {
class IDatabaseTable;}}}

namespace alinous {namespace db {namespace table {namespace lockmonitor {
class IThreadLocker;}}}}

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
using ::alinous::db::table::IDatabaseTable;
using ::alinous::lock::ConcurrentGate;



class RowLock final : public IDatabaseLock, public virtual IObject {
public:
	RowLock(const RowLock& base) = default;
public:
	RowLock(IDatabaseTable* table, long long oid, bool update, IThreadLocker* locker, ConcurrentGate* gate, ThreadContext* ctx) throw() ;
	void __construct_impl(IDatabaseTable* table, long long oid, bool update, IThreadLocker* locker, ConcurrentGate* gate, ThreadContext* ctx) throw() ;
	virtual ~RowLock() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
public:
	bool update;
	IDatabaseTable* table;
	long long oid;
	IThreadLocker* locker;
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
	static void __cleanUp(ThreadContext* ctx);
};

}}}}

#endif /* end of ALINOUS_DB_TABLE_LOCKMONITOR_ROWLOCK_H_ */
