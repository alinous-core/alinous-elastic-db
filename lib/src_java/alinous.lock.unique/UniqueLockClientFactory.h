#ifndef ALINOUS_LOCK_UNIQUE_UNIQUELOCKCLIENTFACTORY_H_
#define ALINOUS_LOCK_UNIQUE_UNIQUELOCKCLIENTFACTORY_H_
namespace alinous {namespace lock {namespace unique {
class UniqueExclusiveLockClient;}}}

namespace alinous {namespace lock {namespace unique {
class UniqueExclusiveLockManager;}}}

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



class UniqueLockClientFactory final : public virtual IObject {
public:
	UniqueLockClientFactory(const UniqueLockClientFactory& base) = default;
public:
	UniqueLockClientFactory(ThreadContext* ctx) throw()  : IObject(ctx)
	{
	}
	void __construct_impl(ThreadContext* ctx) throw() 
	{
	}
	virtual ~UniqueLockClientFactory() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
public:
	static UniqueExclusiveLockClient* createClient(UniqueExclusiveLockManager* mgr, ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}}

#endif /* end of ALINOUS_LOCK_UNIQUE_UNIQUELOCKCLIENTFACTORY_H_ */
