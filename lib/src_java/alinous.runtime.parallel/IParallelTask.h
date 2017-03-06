#ifndef ALINOUS_RUNTIME_PARALLEL_IPARALLELTASK_H_
#define ALINOUS_RUNTIME_PARALLEL_IPARALLELTASK_H_
namespace alinous{namespace annotation{
class OneSource;
}}
namespace alinous {namespace runtime {namespace parallel {
class IParallelTask;}}}

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



class IParallelTask : public virtual IObject {
public:
	IParallelTask(const IParallelTask& base) = default;
public:
	IParallelTask(ThreadContext* ctx) throw() ;
	void __construct_impl(ThreadContext* ctx) throw() ;
	virtual ~IParallelTask() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
public:
	virtual bool beforeStart(IParallelTask* task, ThreadContext* ctx) throw()  = 0;
	virtual void postExecute(ThreadContext* ctx) throw()  = 0;
	virtual void execute(ThreadContext* ctx) throw()  = 0;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx);
};

}}}

#endif /* end of ALINOUS_RUNTIME_PARALLEL_IPARALLELTASK_H_ */
