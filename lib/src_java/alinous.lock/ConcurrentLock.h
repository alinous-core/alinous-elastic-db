#ifndef ALINOUS_LOCK_CONCURRENTLOCK_H_
#define ALINOUS_LOCK_CONCURRENTLOCK_H_
namespace alinous{namespace annotation{
class HeaderOnly;
}}
namespace alinous{namespace annotation{
class ThreadMonitor;
}}
namespace alinous {namespace concurrent {
class Mutex;}}

namespace alinous {namespace lock {
class ILock;}}

namespace alinous {namespace lock {
class UpdateLock;}}

namespace alinous {namespace lock {
class ShareLock;}}

namespace alinous {namespace lock {
class IConcurrentLockManager;}}

namespace java {namespace lang {
class IObject;
}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace lock {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::alinous::concurrent::Mutex;



class ConcurrentLock final : public IConcurrentLockManager, public ThreadMonitor, public virtual IObject {
public:
	ConcurrentLock(const ConcurrentLock& base) = default;
public:
	ConcurrentLock(ThreadContext* ctx) throw() ;
	void __construct_impl(ThreadContext* ctx) throw() ;
	virtual ~ConcurrentLock() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	ILock* currentLock;
	Mutex* sem;
	int shareCount;
	int maxShare;
	int updWaitCnt;
public:
	UpdateLock* updateLock(ThreadContext* ctx);
	void endUpdateLock(ThreadContext* ctx) final;
	ShareLock* shareLock(ThreadContext* ctx);
	void endShareLock(ThreadContext* ctx) final;
private:
	ILock* tryLock(bool upd, ThreadContext* ctx);
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}

#endif /* end of ALINOUS_LOCK_CONCURRENTLOCK_H_ */
