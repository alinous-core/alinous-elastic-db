#ifndef ALINOUS_RUNTIME_PARALLEL_ALINOUSTHREAD_H_
#define ALINOUS_RUNTIME_PARALLEL_ALINOUSTHREAD_H_
namespace alinous{namespace annotation{
class GcZone;
}}
namespace alinous{namespace annotation{
class OneSource;
}}
namespace alinous {namespace runtime {namespace parallel {
class LaunchJoin;}}}

namespace java {namespace lang {
class Thread;}}

namespace alinous {namespace runtime {namespace parallel {
class ThreadPool;}}}

namespace alinous {namespace runtime {namespace parallel {
class IThreadAction;}}}

namespace java {namespace lang {
class InterruptedException;}}

namespace java {namespace lang {
class Throwable;}}

namespace alinous {namespace lock {
class LockObject;}}

namespace java {namespace lang {
class Runnable;}}

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
using ::alinous::lock::LockObject;



class AlinousThread final : public Runnable, public virtual IObject {
public:
	AlinousThread(const AlinousThread& base) = default;
public:
	AlinousThread(LaunchJoin* launchJoin, ThreadContext* ctx) throw() ;
	void __construct_impl(LaunchJoin* launchJoin, ThreadContext* ctx) throw() ;
	AlinousThread(LaunchJoin* launchJoin, ThreadPool* pool, String* name, ThreadContext* ctx) throw() ;
	void __construct_impl(LaunchJoin* launchJoin, ThreadPool* pool, String* name, ThreadContext* ctx) throw() ;
	virtual ~AlinousThread() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	LockObject* lock;
	Thread* thread;
	volatile bool running;
	IThreadAction* action;
	Throwable* lastError;
	ThreadPool* pool;
	volatile bool autoReturn;
	volatile int parentstate;
	volatile bool taskDone;
	LaunchJoin* launchJoin;
public:
	constexpr static const int EXECUTING{0};
	constexpr static const int WAIT{1};
public:
	void execute(IThreadAction* action, ThreadContext* ctx) throw() ;
	void join(ThreadContext* ctx) throw() ;
	void endExecute(ThreadContext* ctx) throw() ;
	void shutdown(ThreadContext* ctx) throw() ;
	void run(ThreadContext* ctx) throw() ;
	bool isRunning(ThreadContext* ctx) throw() ;
	Throwable* getLastError(ThreadContext* ctx) throw() ;
	void setAutoReturn(bool autoReturn, ThreadContext* ctx) throw() ;
private:
	void threadLoop(ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx);
};

}}}

#endif /* end of ALINOUS_RUNTIME_PARALLEL_ALINOUSTHREAD_H_ */
