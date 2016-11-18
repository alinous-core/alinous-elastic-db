#ifndef ALINOUS_DB_TABLE_LOCKMONITOR_DB_ROWLOCKMANAGERLIST_H_
#define ALINOUS_DB_TABLE_LOCKMONITOR_DB_ROWLOCKMANAGERLIST_H_
namespace alinous {namespace db {namespace table {namespace lockmonitor {namespace db {
class RowLockManager;}}}}}

namespace alinous {namespace db {namespace table {
class IDatabaseTable;}}}

namespace java {namespace util {
class BitSet;}}

namespace alinous {namespace db {namespace table {namespace lockmonitor {namespace db {
class RowLockDb;}}}}}

namespace alinous {namespace db {namespace table {namespace lockmonitor {
class ConcurrentGatePool;}}}}

namespace alinous {namespace db {namespace table {namespace lockmonitor {
class RowLock;}}}}

namespace alinous {namespace db {namespace table {namespace lockmonitor {
class ThreadLocker;}}}}

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
using ::alinous::db::table::lockmonitor::RowLock;
using ::alinous::db::table::lockmonitor::ThreadLocker;



class RowLockManagerList final : public virtual IObject {
public:
	RowLockManagerList(const RowLockManagerList& base) = default;
public:
	RowLockManagerList(ThreadContext* ctx) throw()  : IObject(ctx), list(GCUtils<ArrayList<RowLockManager> >::ins(this, (new(ctx) ArrayList<RowLockManager>(ctx)), ctx, __FILEW__, __LINE__, L""))
	{
	}
	void __construct_impl(ThreadContext* ctx) throw() 
	{
	}
	virtual ~RowLockManagerList() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	ArrayList<RowLockManager>* list;
public:
	RowLockManager* getRowLockManager(IDatabaseTable* table, long long oid, BitSet* bitset, int hashcode, RowLockDb* hashDb, ConcurrentGatePool* getePool, ThreadContext* ctx) throw() ;
	RowLock* releaseLock(IDatabaseTable* table, long long oid, BitSet* bitset, int hashcode, ThreadLocker* locker, ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}}}}

#endif /* end of ALINOUS_DB_TABLE_LOCKMONITOR_DB_ROWLOCKMANAGERLIST_H_ */
