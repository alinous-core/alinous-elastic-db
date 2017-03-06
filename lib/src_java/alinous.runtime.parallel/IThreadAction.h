#ifndef ALINOUS_RUNTIME_PARALLEL_ITHREADACTION_H_
#define ALINOUS_RUNTIME_PARALLEL_ITHREADACTION_H_
namespace alinous{namespace annotation{
class HeaderOnly;
}}
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



class IThreadAction : public virtual IObject {
public:
	IThreadAction(const IThreadAction& base) = default;
public:
	IThreadAction(ThreadContext* ctx) throw() ;
	void __construct_impl(ThreadContext* ctx) throw() ;
	virtual ~IThreadAction() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
public:
	virtual void execute(ThreadContext* ctx) = 0;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx);
};

}}}

#endif /* end of ALINOUS_RUNTIME_PARALLEL_ITHREADACTION_H_ */
