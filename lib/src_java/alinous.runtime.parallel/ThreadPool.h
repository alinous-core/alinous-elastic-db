#ifndef ALINOUS_RUNTIME_PARALLEL_THREADPOOL_H_
#define ALINOUS_RUNTIME_PARALLEL_THREADPOOL_H_
namespace alinous{namespace annotation{
class OneSource;
}}
namespace alinous {namespace runtime {namespace parallel {
class LaunchJoin;}}}

namespace alinous {namespace runtime {namespace parallel {
class AlinousThread;}}}

namespace java {namespace lang {
class InterruptedException;}}

namespace java {namespace util {
template <typename  T> class Stack;}}

namespace alinous {namespace lock {
class LockObject;}}

namespace java {namespace lang {
class IObject;
}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace runtime {namespace parallel {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::java::util::Stack;
using ::alinous::lock::LockObject;



class ThreadPool final : public virtual IObject {
public:
	ThreadPool(const ThreadPool& base) = default;
public:
	ThreadPool(int maxThread, String* name, ThreadContext* ctx) throw() ;
	void __construct_impl(int maxThread, String* name, ThreadContext* ctx) throw() ;
	virtual ~ThreadPool() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	Stack<AlinousThread>* threads;
	int maxThread;
	LockObject* lock;
	int waiting;
public:
	void dispose(ThreadContext* ctx) throw() ;
	AlinousThread* borrow(bool autoReturn, ThreadContext* ctx) throw() ;
	void putBack(AlinousThread* thread, ThreadContext* ctx) throw() ;
	int getMaxThread(ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx);
};

}}}

#endif /* end of ALINOUS_RUNTIME_PARALLEL_THREADPOOL_H_ */
