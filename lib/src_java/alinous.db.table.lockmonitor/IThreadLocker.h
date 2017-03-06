#ifndef ALINOUS_DB_TABLE_LOCKMONITOR_ITHREADLOCKER_H_
#define ALINOUS_DB_TABLE_LOCKMONITOR_ITHREADLOCKER_H_
namespace alinous {namespace db {namespace table {
class IDatabaseTable;}}}

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



class IThreadLocker : public virtual IObject {
public:
	IThreadLocker(const IThreadLocker& base) = default;
public:
	IThreadLocker(ThreadContext* ctx) throw() ;
	void __construct_impl(ThreadContext* ctx) throw() ;
	virtual ~IThreadLocker() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
public:
	virtual void updateLockTable(IDatabaseTable* table, ThreadContext* ctx) = 0;
	virtual void updateUnlockTable(IDatabaseTable* table, ThreadContext* ctx) = 0;
	virtual void shareLockTable(IDatabaseTable* table, ThreadContext* ctx) = 0;
	virtual void shareUnlockTable(IDatabaseTable* table, ThreadContext* ctx) = 0;
	virtual void shareLockRow(IDatabaseTable* table, long long oid, ThreadContext* ctx) = 0;
	virtual void shareUnlockRow(IDatabaseTable* table, long long oid, ThreadContext* ctx) = 0;
	virtual void updateLockRow(IDatabaseTable* table, long long oid, ThreadContext* ctx) = 0;
	virtual void updateUnlockRow(IDatabaseTable* table, long long oid, ThreadContext* ctx) = 0;
	virtual ArrayList<TableLock>* getTableLocks(ThreadContext* ctx) throw()  = 0;
	virtual ArrayList<RowLock>* getRowLocks(ThreadContext* ctx) throw()  = 0;
	virtual void dispose(ThreadContext* ctx) = 0;
	virtual String* getFullName(ThreadContext* ctx) throw()  = 0;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx);
};

}}}}

#endif /* end of ALINOUS_DB_TABLE_LOCKMONITOR_ITHREADLOCKER_H_ */
