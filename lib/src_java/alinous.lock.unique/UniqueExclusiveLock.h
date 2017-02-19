#ifndef ALINOUS_LOCK_UNIQUE_UNIQUEEXCLUSIVELOCK_H_
#define ALINOUS_LOCK_UNIQUE_UNIQUEEXCLUSIVELOCK_H_
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



class UniqueExclusiveLock final : public virtual IObject {
public:
	UniqueExclusiveLock(const UniqueExclusiveLock& base) = default;
public:
	UniqueExclusiveLock(ThreadContext* ctx) throw()  : IObject(ctx)
	{
	}
	void __construct_impl(ThreadContext* ctx) throw() 
	{
	}
	virtual ~UniqueExclusiveLock() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}}

#endif /* end of ALINOUS_LOCK_UNIQUE_UNIQUEEXCLUSIVELOCK_H_ */
