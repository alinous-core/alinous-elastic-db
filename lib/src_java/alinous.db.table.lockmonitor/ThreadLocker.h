#ifndef ALINOUS_DB_TABLE_LOCKMONITOR_THREADLOCKER_H_
#define ALINOUS_DB_TABLE_LOCKMONITOR_THREADLOCKER_H_
namespace alinous {namespace db {namespace table {namespace lockmonitor {
class TableLock;}}}}

namespace alinous {namespace db {namespace table {namespace lockmonitor {
class RowLock;}}}}

namespace alinous {namespace db {namespace table {
class IDatabaseTable;}}}

namespace alinous {namespace db {namespace table {namespace lockmonitor {
class IThreadLocker;}}}}

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



class ThreadLocker final : public IThreadLocker, public virtual IObject {
public:
	ThreadLocker(const ThreadLocker& base) = default;
public:
	ThreadLocker(ThreadContext* ctx) throw()  : IObject(ctx), IThreadLocker(ctx), tableLocks(GCUtils<ArrayList<TableLock> >::ins(this, (new(ctx) ArrayList<TableLock>(ctx)), ctx, __FILEW__, __LINE__, L"")), rowLocks(GCUtils<ArrayList<RowLock> >::ins(this, (new(ctx) ArrayList<RowLock>(ctx)), ctx, __FILEW__, __LINE__, L""))
	{
	}
	void __construct_impl(ThreadContext* ctx) throw() 
	{
	}
	virtual ~ThreadLocker() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	ArrayList<TableLock>* tableLocks;
	ArrayList<RowLock>* rowLocks;
public:
	void dispose(ThreadContext* ctx) final;
	void updateLockTable(IDatabaseTable* table, ThreadContext* ctx) final;
	void updateUnlockTable(IDatabaseTable* table, ThreadContext* ctx) final;
	void shareLockTable(IDatabaseTable* table, ThreadContext* ctx) final;
	void shareUnlockTable(IDatabaseTable* table, ThreadContext* ctx) final;
	void shareLockRow(IDatabaseTable* table, long long oid, ThreadContext* ctx) final;
	void shareUnlockRow(IDatabaseTable* table, long long oid, ThreadContext* ctx) final;
	void updateLockRow(IDatabaseTable* table, long long oid, ThreadContext* ctx) final;
	void updateUnlockRow(IDatabaseTable* table, long long oid, ThreadContext* ctx) final;
	ArrayList<TableLock>* getTableLocks(ThreadContext* ctx) throw()  final;
	ArrayList<RowLock>* getRowLocks(ThreadContext* ctx) throw()  final;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}}}

#endif /* end of ALINOUS_DB_TABLE_LOCKMONITOR_THREADLOCKER_H_ */
