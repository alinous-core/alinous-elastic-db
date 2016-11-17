#ifndef ALINOUS_RUNTIME_PARALLEL_CONCURRENTTASKEXEXUTOR_H_
#define ALINOUS_RUNTIME_PARALLEL_CONCURRENTTASKEXEXUTOR_H_
namespace alinous{namespace annotation{
class OneSource;
}}
namespace alinous {namespace runtime {namespace parallel {
class ThreadPool;}}}

namespace alinous {namespace runtime {namespace parallel {
class LaunchJoin;}}}

namespace alinous {namespace runtime {namespace parallel {
class IParallelTask;}}}

namespace alinous {namespace runtime {namespace parallel {
class ConcurrentTaskQueue;}}}

namespace java {namespace lang {
class InterruptedException;}}

namespace java {namespace util {
template <typename  T> class LinkedList;}}

namespace alinous {namespace lock {
class LockObject;}}

namespace alinous {namespace runtime {namespace parallel {
class AlinousThread;}}}

namespace alinous {namespace runtime {namespace parallel {
class ConcurrentTaskExexutor;}}}

namespace alinous {namespace runtime {namespace parallel {
class IThreadAction;}}}

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
using ::java::util::LinkedList;
using ::alinous::lock::LockObject;



class ConcurrentTaskExexutor final : public virtual IObject {
public:
	class FinalyzerEntryPoint;
	class LauncherEntryPoint;
	ConcurrentTaskExexutor(const ConcurrentTaskExexutor& base) = default;
public:
	ConcurrentTaskExexutor(ThreadPool* pool, ThreadContext* ctx) throw() ;
	void __construct_impl(ThreadPool* pool, ThreadContext* ctx) throw() ;
	virtual ~ConcurrentTaskExexutor() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	LinkedList<ConcurrentTaskQueue>* queue;
	LinkedList<ConcurrentTaskQueue>* readyQueue;
	LockObject* sync;
	AlinousThread* finalizer;
	LaunchJoin* finalizerLaunchJoin;
	AlinousThread* launcher;
	LaunchJoin* launcherLaunchJoin;
	bool finalizerEnds;
	ConcurrentTaskQueue* lastTask;
	ThreadPool* pool;
public:
	void begin(ThreadContext* ctx);
	void startTask(IParallelTask* task, ThreadContext* ctx) throw() ;
	void flush(ThreadContext* ctx);
	void dispose(ThreadContext* ctx) throw() ;
private:
	void finalizeLoop(ThreadContext* ctx);
	void launcherLoop(ThreadContext* ctx);
	void asyncStart(ThreadContext* ctx);
public:



	class FinalyzerEntryPoint final : public IThreadAction, public virtual IObject {
	public:
		FinalyzerEntryPoint(const FinalyzerEntryPoint& base) = default;
	public:
		FinalyzerEntryPoint(ConcurrentTaskExexutor* exec, ThreadContext* ctx) throw() ;
		void __construct_impl(ConcurrentTaskExexutor* exec, ThreadContext* ctx) throw() ;
		virtual ~FinalyzerEntryPoint() throw();
		virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
	private:
		ConcurrentTaskExexutor* executor;
	public:
		void execute(ThreadContext* ctx) throw()  final;
	public:
		static bool __init_done;
		static bool __init_static_variables();
	public:
		static void __cleanUp(ThreadContext* ctx){
		}
	};




	class LauncherEntryPoint final : public IThreadAction, public virtual IObject {
	public:
		LauncherEntryPoint(const LauncherEntryPoint& base) = default;
	public:
		LauncherEntryPoint(ConcurrentTaskExexutor* exec, ThreadContext* ctx) throw() ;
		void __construct_impl(ConcurrentTaskExexutor* exec, ThreadContext* ctx) throw() ;
		virtual ~LauncherEntryPoint() throw();
		virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
	private:
		ConcurrentTaskExexutor* exec;
	public:
		void execute(ThreadContext* ctx) throw()  final;
	public:
		static bool __init_done;
		static bool __init_static_variables();
	public:
		static void __cleanUp(ThreadContext* ctx){
		}
	};

	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}}

#endif /* end of ALINOUS_RUNTIME_PARALLEL_CONCURRENTTASKEXEXUTOR_H_ */
