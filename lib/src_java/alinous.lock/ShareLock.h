#ifndef ALINOUS_LOCK_SHARELOCK_H_
#define ALINOUS_LOCK_SHARELOCK_H_
namespace alinous{namespace annotation{
class HeaderOnly;
}}
namespace alinous {namespace lock {
class IConcurrentLockManager;}}

namespace alinous {namespace lock {
class ShareLock;}}

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



class ShareLock final : public ILock, public virtual IObject {
public:
	ShareLock(const ShareLock& base) = default;
public:
	ShareLock(IConcurrentLockManager* parent, ThreadContext* ctx) throw() ;
	void __construct_impl(IConcurrentLockManager* parent, ThreadContext* ctx) throw() ;
	virtual ~ShareLock() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	IConcurrentLockManager* parent;
	int cnt;
public:
	ShareLock* inc(ThreadContext* ctx) throw() ;
	int dec(ThreadContext* ctx) throw() ;
	void unlock(ThreadContext* ctx) final;
	int getCnt(ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}

#endif /* end of ALINOUS_LOCK_SHARELOCK_H_ */
