#ifndef ALINOUS_LOCK_CONCURRENTGATE_H_
#define ALINOUS_LOCK_CONCURRENTGATE_H_
namespace alinous{namespace annotation{
class HeaderOnly;
}}
namespace alinous {namespace concurrent {
class Mutex;}}

namespace alinous {namespace lock {
class LockObject;}}

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



class ConcurrentGate final : public virtual IObject {
public:
	ConcurrentGate(const ConcurrentGate& base) = default;
public:
	ConcurrentGate(ThreadContext* ctx) throw() ;
	void __construct_impl(ThreadContext* ctx) throw() ;
	virtual ~ConcurrentGate() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	bool isOpened;
	int counter;
	int roomWaiter;
	Mutex* doorKeeperLock;
	LockObject* stateLock;
	LockObject* roomLock;
public:
	void enter(ThreadContext* ctx);
	void open(ThreadContext* ctx);
	void exit(ThreadContext* ctx) throw() ;
	void close(ThreadContext* ctx);
	void dispose(ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}

#endif /* end of ALINOUS_LOCK_CONCURRENTGATE_H_ */
