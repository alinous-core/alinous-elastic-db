#ifndef ALINOUS_DB_TABLE_LOCKMONITOR_CONCURRENTGATEPOOL_H_
#define ALINOUS_DB_TABLE_LOCKMONITOR_CONCURRENTGATEPOOL_H_
namespace alinous{namespace annotation{
class ThreadMonitor;
}}
namespace alinous {namespace concurrent {
class SpinMutex;}}

namespace alinous {namespace lock {
class ConcurrentGate;}}

namespace java {namespace util {
template <typename  T> class Stack;}}

namespace java {namespace lang {
class IObject;
}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace db {namespace table {namespace lockmonitor {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::java::util::Stack;
using ::alinous::concurrent::SpinMutex;
using ::alinous::lock::ConcurrentGate;



class ConcurrentGatePool final : public ThreadMonitor, public virtual IObject {
public:
	ConcurrentGatePool(const ConcurrentGatePool& base) = default;
public:
	ConcurrentGatePool(int maxPool, ThreadContext* ctx) throw() ;
	void __construct_impl(int maxPool, ThreadContext* ctx) throw() ;
	virtual ~ConcurrentGatePool() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	Stack<ConcurrentGate>* stack;
	int maxPool;
	SpinMutex* mutex;
public:
	ConcurrentGate* borrow(ThreadContext* ctx) throw() ;
	void pushBack(ConcurrentGate* gate, ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx);
};

}}}}

#endif /* end of ALINOUS_DB_TABLE_LOCKMONITOR_CONCURRENTGATEPOOL_H_ */
