#ifndef ALINOUS_DB_TABLE_LOCKMONITOR_DB_TABLELOCKMANAGERLIST_H_
#define ALINOUS_DB_TABLE_LOCKMONITOR_DB_TABLELOCKMANAGERLIST_H_
namespace alinous {namespace db {namespace table {namespace lockmonitor {namespace db {
class TableLockMamager;}}}}}

namespace alinous {namespace db {namespace table {
class IDatabaseTable;}}}

namespace java {namespace util {
class BitSet;}}

namespace alinous {namespace db {namespace table {namespace lockmonitor {namespace db {
class TableLockHashDb;}}}}}

namespace alinous {namespace db {namespace table {namespace lockmonitor {
class ConcurrentGatePool;}}}}

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
using ::java::util::BitSet;
using ::alinous::db::table::IDatabaseTable;
using ::alinous::db::table::lockmonitor::ConcurrentGatePool;
using ::alinous::db::table::lockmonitor::IThreadLocker;
using ::alinous::db::table::lockmonitor::TableLock;



class TableLockManagerList final : public virtual IObject {
public:
	TableLockManagerList(const TableLockManagerList& base) = default;
public:
	TableLockManagerList(ThreadContext* ctx) throw() ;
	void __construct_impl(ThreadContext* ctx) throw() ;
	virtual ~TableLockManagerList() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	ArrayList<TableLockMamager>* list;
public:
	TableLockMamager* getTableLockmanager(IDatabaseTable* table, BitSet* bitset, int hashcode, TableLockHashDb* hashDb, ConcurrentGatePool* gatePool, ThreadContext* ctx) throw() ;
	TableLock* releaseLock(IDatabaseTable* table, BitSet* bitset, int hashcode, IThreadLocker* locker, ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx);
};

}}}}}

#endif /* end of ALINOUS_DB_TABLE_LOCKMONITOR_DB_TABLELOCKMANAGERLIST_H_ */
