#ifndef ALINOUS_LOCK_ICONCURRENTLOCKMANAGER_H_
#define ALINOUS_LOCK_ICONCURRENTLOCKMANAGER_H_
namespace alinous{namespace annotation{
class HeaderOnly;
}}
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



class IConcurrentLockManager : public virtual IObject {
public:
	IConcurrentLockManager(const IConcurrentLockManager& base) = default;
public:
	IConcurrentLockManager(ThreadContext* ctx) throw() ;
	void __construct_impl(ThreadContext* ctx) throw() ;
	virtual ~IConcurrentLockManager() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
public:
	virtual void endUpdateLock(ThreadContext* ctx) = 0;
	virtual void endShareLock(ThreadContext* ctx) = 0;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx);
};

}}

#endif /* end of ALINOUS_LOCK_ICONCURRENTLOCKMANAGER_H_ */
