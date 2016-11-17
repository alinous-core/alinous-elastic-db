#ifndef ALINOUS_LOCK_UPDATELOCK_H_
#define ALINOUS_LOCK_UPDATELOCK_H_
namespace alinous{namespace annotation{
class HeaderOnly;
}}
namespace alinous {namespace lock {
class IConcurrentLockManager;}}

namespace alinous {namespace lock {
class ILock;}}

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



class UpdateLock final : public ILock, public virtual IObject {
public:
	UpdateLock(const UpdateLock& base) = default;
public:
	UpdateLock(IConcurrentLockManager* parent, ThreadContext* ctx) throw() ;
	void __construct_impl(IConcurrentLockManager* parent, ThreadContext* ctx) throw() ;
	virtual ~UpdateLock() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
public:
	IConcurrentLockManager* parent;
public:
	void unlock(ThreadContext* ctx) final;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}

#endif /* end of ALINOUS_LOCK_UPDATELOCK_H_ */
