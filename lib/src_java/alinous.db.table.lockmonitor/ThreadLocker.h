#ifndef ALINOUS_DB_TABLE_LOCKMONITOR_THREADLOCKER_H_
#define ALINOUS_DB_TABLE_LOCKMONITOR_THREADLOCKER_H_
namespace alinous {namespace db {namespace table {
class IDatabaseTable;}}}

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
using ::alinous::db::table::IDatabaseTable;



class ThreadLocker final : public virtual IObject {
public:
	ThreadLocker(const ThreadLocker& base) = default;
public:
	ThreadLocker(ThreadContext* ctx) throw()  : IObject(ctx), blockingLock(nullptr), tableLocks(GCUtils<ArrayList<TableLock> >::ins(this, (new(ctx) ArrayList<TableLock>(ctx)), ctx, __FILEW__, __LINE__, L"")), rowLocks(GCUtils<ArrayList<RowLock> >::ins(this, (new(ctx) ArrayList<RowLock>(ctx)), ctx, __FILEW__, __LINE__, L""))
	{
	}
	void __construct_impl(ThreadContext* ctx) throw() 
	{
	}
	virtual ~ThreadLocker() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
public:
	IDatabaseLock* blockingLock;
	ArrayList<TableLock>* tableLocks;
	ArrayList<RowLock>* rowLocks;
public:
	void updateLockTable(IDatabaseTable* table, ThreadContext* ctx);
	void updateUnlockTable(IDatabaseTable* table, ThreadContext* ctx);
	void shareLockTable(IDatabaseTable* table, ThreadContext* ctx);
	void shareUnlockTable(IDatabaseTable* table, ThreadContext* ctx);
	void shareLockRow(IDatabaseTable* table, long long oid, ThreadContext* ctx);
	void shareUnlockRow(IDatabaseTable* table, long long oid, ThreadContext* ctx);
	void updateLockRow(IDatabaseTable* table, long long oid, ThreadContext* ctx);
	void updateUnlockRow(IDatabaseTable* table, long long oid, ThreadContext* ctx);
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
