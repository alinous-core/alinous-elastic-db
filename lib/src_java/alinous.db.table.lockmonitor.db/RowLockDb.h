#ifndef ALINOUS_DB_TABLE_LOCKMONITOR_DB_ROWLOCKDB_H_
#define ALINOUS_DB_TABLE_LOCKMONITOR_DB_ROWLOCKDB_H_
namespace alinous {namespace db {namespace table {namespace lockmonitor {namespace db {
class RowLockManagerList;}}}}}

namespace alinous {namespace db {namespace table {namespace lockmonitor {namespace db {
class RowLockManager;}}}}}

namespace alinous {namespace db {namespace table {
class DatabaseTable;}}}

namespace alinous {namespace db {namespace table {namespace lockmonitor {
class ConcurrentGatePool;}}}}

namespace alinous {namespace db {namespace table {namespace lockmonitor {
class RowLock;}}}}

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
using ::alinous::db::table::lockmonitor::RowLock;
using ::alinous::db::table::lockmonitor::ThreadLocker;



class RowLockDb final : public virtual IObject {
public:
	RowLockDb(const RowLockDb& base) = default;
public:
	RowLockDb(int MAX_HASH, ThreadContext* ctx) throw() ;
	void __construct_impl(int MAX_HASH, ThreadContext* ctx) throw() ;
	virtual ~RowLockDb() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
public:
	long long MAX_HASH;
	long long MAX_HASH_MASK;
	int numElements;
private:
	IArrayObject<RowLockManagerList>* arrays;
	BitSet* bitset;
public:
	RowLockManager* getRowLockManager(DatabaseTable* table, long long oid, ConcurrentGatePool* gatePool, ThreadContext* ctx) throw() ;
	RowLock* releaseLock(DatabaseTable* table, long long oid, ThreadLocker* locker, ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}}}}

#endif /* end of ALINOUS_DB_TABLE_LOCKMONITOR_DB_ROWLOCKDB_H_ */
