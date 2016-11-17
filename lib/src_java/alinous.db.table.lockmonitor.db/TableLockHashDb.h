#ifndef ALINOUS_DB_TABLE_LOCKMONITOR_DB_TABLELOCKHASHDB_H_
#define ALINOUS_DB_TABLE_LOCKMONITOR_DB_TABLELOCKHASHDB_H_
namespace alinous {namespace db {namespace table {namespace lockmonitor {namespace db {
class TableLockManagerList;}}}}}

namespace alinous {namespace db {namespace table {namespace lockmonitor {namespace db {
class TableLockMamager;}}}}}

namespace alinous {namespace db {namespace table {
class DatabaseTable;}}}

namespace alinous {namespace db {namespace table {namespace lockmonitor {
class ConcurrentGatePool;}}}}

namespace alinous {namespace db {namespace table {namespace lockmonitor {
class TableLock;}}}}

namespace alinous {namespace db {namespace table {namespace lockmonitor {
class ThreadLocker;}}}}

namespace java {namespace util {
class BitSet;}}

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
using ::java::util::BitSet;
using ::alinous::db::table::DatabaseTable;
using ::alinous::db::table::lockmonitor::ConcurrentGatePool;
using ::alinous::db::table::lockmonitor::TableLock;
using ::alinous::db::table::lockmonitor::ThreadLocker;



class TableLockHashDb final : public virtual IObject {
public:
	TableLockHashDb(const TableLockHashDb& base) = default;
public:
	TableLockHashDb(int MAX_HASH, ThreadContext* ctx) throw() ;
	void __construct_impl(int MAX_HASH, ThreadContext* ctx) throw() ;
	virtual ~TableLockHashDb() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
public:
	long long MAX_HASH;
	long long MAX_HASH_MASK;
private:
	IArrayObject<TableLockManagerList>* arrays;
	BitSet* bitset;
	int numElements;
public:
	int size(ThreadContext* ctx) throw() ;
	void inc(ThreadContext* ctx) throw() ;
	TableLockMamager* getTableLockManager(DatabaseTable* table, ConcurrentGatePool* gatePool, ThreadContext* ctx) throw() ;
	TableLock* releaseLock(DatabaseTable* table, ThreadLocker* locker, ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}}}}

#endif /* end of ALINOUS_DB_TABLE_LOCKMONITOR_DB_TABLELOCKHASHDB_H_ */
