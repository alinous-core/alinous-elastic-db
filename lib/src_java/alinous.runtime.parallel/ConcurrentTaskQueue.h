#ifndef ALINOUS_RUNTIME_PARALLEL_CONCURRENTTASKQUEUE_H_
#define ALINOUS_RUNTIME_PARALLEL_CONCURRENTTASKQUEUE_H_
namespace alinous{namespace annotation{
class OneSource;
}}
namespace alinous {namespace runtime {namespace parallel {
class IParallelTask;}}}

namespace java {namespace util {
template <typename  T> class LinkedList;}}

namespace alinous {namespace runtime {namespace parallel {
class ConcurrentTaskQueue;}}}

namespace alinous {namespace lock {
class LockObject;}}

namespace alinous {namespace runtime {namespace parallel {
class ThreadPool;}}}

namespace alinous {namespace runtime {namespace parallel {
class AlinousThread;}}}

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



class ConcurrentTaskQueue final : public virtual IObject {
public:
	class ThreadEntryPoint;
	ConcurrentTaskQueue(const ConcurrentTaskQueue& base) = default;
public:
	ConcurrentTaskQueue(IParallelTask* task, LinkedList<ConcurrentTaskQueue>* queue, LockObject* sync, ThreadPool* pool, ThreadContext* ctx) throw() ;
	void __construct_impl(IParallelTask* task, LinkedList<ConcurrentTaskQueue>* queue, LockObject* sync, ThreadPool* pool, ThreadContext* ctx) throw() ;
	virtual ~ConcurrentTaskQueue() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	AlinousThread* thread;
	IParallelTask* task;
	LinkedList<ConcurrentTaskQueue>* queue;
	LockObject* sync;
	volatile bool finished;
	ThreadPool* pool;
public:
	void start(ThreadContext* ctx) throw() ;
	void execute(ThreadContext* ctx) throw() ;
	bool beforeStart(ConcurrentTaskQueue* task, ThreadContext* ctx) throw() ;
	void join(ThreadContext* ctx);
	void postExecute(ThreadContext* ctx) throw() ;
	bool isFinished(ThreadContext* ctx) throw() ;
	LinkedList<ConcurrentTaskQueue>* getQueue(ThreadContext* ctx) throw() ;
public:



	class ThreadEntryPoint final : public IThreadAction, public virtual IObject {
	public:
		ThreadEntryPoint(const ThreadEntryPoint& base) = default;
	public:
		ThreadEntryPoint(ConcurrentTaskQueue* queue, ThreadContext* ctx) throw() ;
		void __construct_impl(ConcurrentTaskQueue* queue, ThreadContext* ctx) throw() ;
		virtual ~ThreadEntryPoint() throw();
		virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
	private:
		ConcurrentTaskQueue* _this;
	public:
		void execute(ThreadContext* ctx) throw()  final;
	public:
		static bool __init_done;
		static bool __init_static_variables();
	public:
		static void __cleanUp(ThreadContext* ctx);
	};

	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx);
};

}}}

#endif /* end of ALINOUS_RUNTIME_PARALLEL_CONCURRENTTASKQUEUE_H_ */
