#ifndef ALINOUS_LOCK_LOCKOBJECT_H_
#define ALINOUS_LOCK_LOCKOBJECT_H_
namespace alinous{namespace annotation{
class HeaderOnly;
}}
namespace alinous{namespace annotation{
class ThreadMonitor;
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



class LockObject final : public ThreadMonitor, public virtual IObject {
public:
	LockObject(const LockObject& base) = default;
public:
	LockObject(ThreadContext* ctx) throw() ;
	void __construct_impl(ThreadContext* ctx) throw() ;
	virtual ~LockObject() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx);
};

}}

#endif /* end of ALINOUS_LOCK_LOCKOBJECT_H_ */
