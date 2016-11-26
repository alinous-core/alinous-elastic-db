#ifndef ALINOUS_DB_TRX_TRXLOCKMANAGER_H_
#define ALINOUS_DB_TRX_TRXLOCKMANAGER_H_
namespace alinous {namespace db {namespace trx {
class TrxLockContext;}}}

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



class TrxLockManager final : public virtual IObject {
public:
	TrxLockManager(const TrxLockManager& base) = default;
public:
	TrxLockManager(ThreadContext* ctx) throw()  : IObject(ctx)
	{
	}
	void __construct_impl(ThreadContext* ctx) throw() 
	{
	}
	virtual ~TrxLockManager() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
public:
	TrxLockContext* newLockContext(ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}}

#endif /* end of ALINOUS_DB_TRX_TRXLOCKMANAGER_H_ */
