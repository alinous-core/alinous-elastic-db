#ifndef ALINOUS_DB_TABLE_LOCKMONITOR_DB_TABLELOCKMAMAGER_H_
#define ALINOUS_DB_TABLE_LOCKMONITOR_DB_TABLELOCKMAMAGER_H_
namespace alinous {namespace db {namespace table {
class IDatabaseTable;}}}

namespace alinous {namespace lock {
class ConcurrentGate;}}

namespace alinous {namespace db {namespace table {namespace lockmonitor {
class TableLock;}}}}

namespace alinous {namespace db {namespace table {namespace lockmonitor {
class IThreadLocker;}}}}

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
using ::alinous::db::table::IDatabaseTable;
using ::alinous::db::table::lockmonitor::IThreadLocker;
using ::alinous::db::table::lockmonitor::TableLock;
using ::alinous::lock::ConcurrentGate;



class TableLockMamager final : public virtual IObject {
public:
	TableLockMamager(const TableLockMamager& base) = default;
public:
	TableLockMamager(IDatabaseTable* table, ConcurrentGate* gate, ThreadContext* ctx) throw() ;
	void __construct_impl(IDatabaseTable* table, ConcurrentGate* gate, ThreadContext* ctx) throw() ;
	virtual ~TableLockMamager() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
public:
	ArrayList<TableLock>* list;
private:
	IDatabaseTable* table;
	ConcurrentGate* gate;
public:
	IDatabaseTable* getTable(ThreadContext* ctx) throw() ;
	TableLock* newLock(IThreadLocker* locker, bool update, ThreadContext* ctx) throw() ;
	TableLock* releaseLock(IThreadLocker* locker, ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}}}}

#endif /* end of ALINOUS_DB_TABLE_LOCKMONITOR_DB_TABLELOCKMAMAGER_H_ */
