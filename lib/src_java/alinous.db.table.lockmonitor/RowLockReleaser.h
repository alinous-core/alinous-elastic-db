#ifndef ALINOUS_DB_TABLE_LOCKMONITOR_ROWLOCKRELEASER_H_
#define ALINOUS_DB_TABLE_LOCKMONITOR_ROWLOCKRELEASER_H_
namespace alinous {namespace db {namespace table {namespace lockmonitor {
class DBThreadMonitor;}}}}

namespace alinous {namespace db {namespace table {
class IDatabaseTable;}}}

namespace alinous {namespace db {namespace table {namespace lockmonitor {
class ThreadLocker;}}}}

namespace alinous {namespace runtime {namespace parallel {
class IThreadAction;}}}

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
using ::alinous::runtime::parallel::IThreadAction;



class RowLockReleaser final : public IThreadAction, public virtual IObject {
public:
	RowLockReleaser(const RowLockReleaser& base) = default;
public:
	RowLockReleaser(DBThreadMonitor* monitor, IDatabaseTable* table, long long oid, ThreadLocker* locker, ThreadContext* ctx) throw() ;
	void __construct_impl(DBThreadMonitor* monitor, IDatabaseTable* table, long long oid, ThreadLocker* locker, ThreadContext* ctx) throw() ;
	virtual ~RowLockReleaser() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
public:
	IDatabaseTable* table;
	long long oid;
	ThreadLocker* locker;
	DBThreadMonitor* monitor;
public:
	void execute(ThreadContext* ctx) final;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}}}

#endif /* end of ALINOUS_DB_TABLE_LOCKMONITOR_ROWLOCKRELEASER_H_ */
