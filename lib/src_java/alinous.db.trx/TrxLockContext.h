#ifndef ALINOUS_DB_TRX_TRXLOCKCONTEXT_H_
#define ALINOUS_DB_TRX_TRXLOCKCONTEXT_H_
namespace java {namespace util {
template <typename  T> class Iterator;}}

namespace alinous {namespace db {namespace table {namespace lockmonitor {
class IThreadLocker;}}}}

namespace alinous {namespace db {namespace table {
class IDatabaseTable;}}}

namespace java {namespace util {
template <typename  T, typename V> class Map;}}

namespace java {namespace util {
template <typename  T, typename V> class HashMap;}}

namespace alinous {namespace db {namespace table {namespace lockmonitor {
class DatabaseLockException;}}}}

namespace java {namespace lang {
class IObject;
}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace db {namespace trx {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::java::util::HashMap;
using ::java::util::Iterator;
using ::java::util::Map;
using ::alinous::db::table::IDatabaseTable;
using ::alinous::db::table::lockmonitor::DatabaseLockException;
using ::alinous::db::table::lockmonitor::IThreadLocker;



class TrxLockContext final : public virtual IObject {
public:
	TrxLockContext(const TrxLockContext& base) = default;
public:
	TrxLockContext(ThreadContext* ctx) throw() ;
	void __construct_impl(ThreadContext* ctx) throw() ;
	virtual ~TrxLockContext() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	Map<String,IThreadLocker>* map;
public:
	void reset(ThreadContext* ctx);
	void shareLockTable(IDatabaseTable* tableStore, ThreadContext* ctx);
	void shareUnlockTable(IDatabaseTable* tableStore, ThreadContext* ctx);
	void shareUnlockRow(IDatabaseTable* tableStore, long long oid, ThreadContext* ctx);
	void updateUnlockRow(IDatabaseTable* tableStore, long long oid, ThreadContext* ctx);
	void shareLockRow(IDatabaseTable* tableStore, long long oid, ThreadContext* ctx);
	void updateLockRow(IDatabaseTable* tableStore, long long oid, ThreadContext* ctx);
private:
	IThreadLocker* getLocker(IDatabaseTable* tableStore, ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx);
};

}}}

#endif /* end of ALINOUS_DB_TRX_TRXLOCKCONTEXT_H_ */
