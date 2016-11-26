#ifndef ALINOUS_DB_TABLE_LOCKMONITOR_TABLELOCK_H_
#define ALINOUS_DB_TABLE_LOCKMONITOR_TABLELOCK_H_
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



class TableLock final : public IDatabaseLock, public virtual IObject {
public:
	TableLock(const TableLock& base) = default;
public:
	TableLock(bool update, IDatabaseTable* table, IThreadLocker* locker, ConcurrentGate* gate, ThreadContext* ctx) throw() ;
	void __construct_impl(bool update, IDatabaseTable* table, IThreadLocker* locker, ConcurrentGate* gate, ThreadContext* ctx) throw() ;
	virtual ~TableLock() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
public:
	bool update;
	IDatabaseTable* table;
	IThreadLocker* locker;
	int count;
	bool pushBack;
private:
	ConcurrentGate* gate;
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

#endif /* end of ALINOUS_DB_TABLE_LOCKMONITOR_TABLELOCK_H_ */
