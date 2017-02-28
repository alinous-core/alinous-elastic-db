#ifndef ALINOUS_LOCK_UNIQUE_UNIQUEEXCLUSIVELOCK_H_
#define ALINOUS_LOCK_UNIQUE_UNIQUEEXCLUSIVELOCK_H_
namespace alinous {namespace lock {
class ConcurrentGate;}}

namespace java {namespace lang {
class IObject;
}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace lock {namespace unique {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::alinous::lock::ConcurrentGate;



class UniqueExclusiveLock final : public virtual IObject {
public:
	UniqueExclusiveLock(const UniqueExclusiveLock& base) = default;
public:
	UniqueExclusiveLock(ThreadContext* ctx) throw() ;
	void __construct_impl(ThreadContext* ctx) throw() ;
	virtual ~UniqueExclusiveLock() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	ConcurrentGate* gate;
public:
	void lock(ThreadContext* ctx);
	void unlock(ThreadContext* ctx);
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}}

#endif /* end of ALINOUS_LOCK_UNIQUE_UNIQUEEXCLUSIVELOCK_H_ */
