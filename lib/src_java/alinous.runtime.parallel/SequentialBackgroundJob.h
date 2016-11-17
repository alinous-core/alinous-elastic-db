#ifndef ALINOUS_RUNTIME_PARALLEL_SEQUENTIALBACKGROUNDJOB_H_
#define ALINOUS_RUNTIME_PARALLEL_SEQUENTIALBACKGROUNDJOB_H_
namespace alinous{namespace annotation{
class OneSource;
}}
namespace alinous {namespace runtime {namespace parallel {
class SequentialBackgroundJob;}}}

namespace alinous {namespace runtime {namespace parallel {
class ThreadPool;}}}

namespace alinous {namespace runtime {namespace parallel {
class LaunchJoin;}}}

namespace alinous {namespace runtime {namespace parallel {
class IThreadAction;}}}

namespace java {namespace lang {
class Throwable;}}

namespace java {namespace util {
template <typename  T> class LinkedList;}}

namespace alinous {namespace lock {
class LockObject;}}

namespace alinous {namespace runtime {namespace parallel {
class AlinousThread;}}}

namespace java {namespace lang {
class InterruptedException;}}

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



class SequentialBackgroundJob final : public virtual IObject {
public:
	class QueueExecutor;
	SequentialBackgroundJob(const SequentialBackgroundJob& base) = default;
public:
	SequentialBackgroundJob(ThreadContext* ctx) throw()  : IObject(ctx), actions(GCUtils<LinkedList<IThreadAction> >::ins(this, (new(ctx) LinkedList<IThreadAction>(ctx)), ctx, __FILEW__, __LINE__, L"")), actionLock(__GC_INS(this, (new(ctx) LockObject(ctx)), LockObject)), pool(nullptr), executor(nullptr), executing(0), lastException(nullptr)
	{
	}
	void __construct_impl(ThreadContext* ctx) throw() 
	{
	}
	virtual ~SequentialBackgroundJob() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	LinkedList<IThreadAction>* actions;
	LockObject* actionLock;
	ThreadPool* pool;
	AlinousThread* executor;
	bool executing;
	Throwable* lastException;
public:
	SequentialBackgroundJob* init(ThreadPool* pool, ThreadContext* ctx);
	void addJob(IThreadAction* action, ThreadContext* ctx) throw() ;
	void execLoop(LaunchJoin* launchJoin, ThreadContext* ctx);
	void joinAndEnd(ThreadContext* ctx) throw() ;
	Throwable* getLastException(ThreadContext* ctx) throw() ;
public:



	class QueueExecutor final : public IThreadAction, public virtual IObject {
	public:
		QueueExecutor(const QueueExecutor& base) = default;
	public:
		QueueExecutor(LaunchJoin* launchJoin, SequentialBackgroundJob* _this, ThreadContext* ctx) throw() ;
		void __construct_impl(LaunchJoin* launchJoin, SequentialBackgroundJob* _this, ThreadContext* ctx) throw() ;
		virtual ~QueueExecutor() throw();
		virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
	private:
		LaunchJoin* launchJoin;
		SequentialBackgroundJob* _this;
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

#endif /* end of ALINOUS_RUNTIME_PARALLEL_SEQUENTIALBACKGROUNDJOB_H_ */
