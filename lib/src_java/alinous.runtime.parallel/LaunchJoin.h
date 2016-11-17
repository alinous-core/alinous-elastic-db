#ifndef ALINOUS_RUNTIME_PARALLEL_LAUNCHJOIN_H_
#define ALINOUS_RUNTIME_PARALLEL_LAUNCHJOIN_H_
namespace alinous{namespace annotation{
class OneSource;
}}
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
using ::alinous::lock::LockObject;



class LaunchJoin final : public virtual IObject {
public:
	LaunchJoin(const LaunchJoin& base) = default;
public:
	LaunchJoin(int count, ThreadContext* ctx) throw() ;
	void __construct_impl(int count, ThreadContext* ctx) throw() ;
	virtual ~LaunchJoin() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	volatile int count;
	volatile int max;
	LockObject* sync;
public:
	void parentJoin(ThreadContext* ctx);
	void childrenJoin(ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}}

#endif /* end of ALINOUS_RUNTIME_PARALLEL_LAUNCHJOIN_H_ */
