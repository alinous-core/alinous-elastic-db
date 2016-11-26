#ifndef ALINOUS_DB_TRX_TRXLOCKCONTEXT_H_
#define ALINOUS_DB_TRX_TRXLOCKCONTEXT_H_
namespace alinous {namespace db {namespace table {
class IDatabaseTable;}}}

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
using ::alinous::db::table::IDatabaseTable;
using ::alinous::db::table::lockmonitor::DatabaseLockException;



class TrxLockContext final : public virtual IObject {
public:
	TrxLockContext(const TrxLockContext& base) = default;
public:
	TrxLockContext(ThreadContext* ctx) throw()  : IObject(ctx)
	{
	}
	void __construct_impl(ThreadContext* ctx) throw() 
	{
	}
	virtual ~TrxLockContext() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
public:
	void shareLockTable(IDatabaseTable* tableStore, ThreadContext* ctx);
	void shareUnlockTable(IDatabaseTable* tableStore, ThreadContext* ctx) throw() ;
	void shareUnlockRow(IDatabaseTable* tableStore, long long oid, ThreadContext* ctx) throw() ;
	void updateUnlockRow(IDatabaseTable* tableStore, long long oid, ThreadContext* ctx) throw() ;
	void shareLockRow(IDatabaseTable* tableStore, long long oid, ThreadContext* ctx) throw() ;
	void updateLockRow(IDatabaseTable* tableStore, long long oid, ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}}

#endif /* end of ALINOUS_DB_TRX_TRXLOCKCONTEXT_H_ */
