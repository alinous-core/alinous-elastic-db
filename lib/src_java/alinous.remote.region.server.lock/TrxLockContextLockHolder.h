#ifndef ALINOUS_REMOTE_REGION_SERVER_LOCK_TRXLOCKCONTEXTLOCKHOLDER_H_
#define ALINOUS_REMOTE_REGION_SERVER_LOCK_TRXLOCKCONTEXTLOCKHOLDER_H_
namespace alinous {namespace remote {namespace region {namespace server {namespace lock {
class IRemoteTableLock;}}}}}

namespace alinous {namespace db {
class AlinousDbException;}}

namespace java {namespace lang {
class InterruptedException;}}

namespace java {namespace lang {
class IObject;
}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace remote {namespace region {namespace server {namespace lock {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::alinous::db::AlinousDbException;



class TrxLockContextLockHolder final : public virtual IObject {
public:
	TrxLockContextLockHolder(const TrxLockContextLockHolder& base) = default;
public:
	TrxLockContextLockHolder(IRemoteTableLock* remoteLock, ThreadContext* ctx) throw() ;
	void __construct_impl(IRemoteTableLock* remoteLock, ThreadContext* ctx) throw() ;
	virtual ~TrxLockContextLockHolder() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	IRemoteTableLock* remoteLock;
	int shareCount;
	int updateCount;
public:
	void shareLock(ThreadContext* ctx);
	void shareUnlock(ThreadContext* ctx) throw() ;
	void updateLock(ThreadContext* ctx);
	void updateUnlock(ThreadContext* ctx);
	void clearLocks(ThreadContext* ctx) throw() ;
	void incShareCount(ThreadContext* ctx) throw() ;
	void decShareCount(ThreadContext* ctx) throw() ;
	void incUpdateCount(ThreadContext* ctx) throw() ;
	void decUpdateCount(ThreadContext* ctx) throw() ;
	int getShareCount(ThreadContext* ctx) throw() ;
	int getUpdateCount(ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx);
};

}}}}}

#endif /* end of ALINOUS_REMOTE_REGION_SERVER_LOCK_TRXLOCKCONTEXTLOCKHOLDER_H_ */
