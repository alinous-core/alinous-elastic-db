#ifndef ALINOUS_COMPILE_DEBUGPROBESECTION_H_
#define ALINOUS_COMPILE_DEBUGPROBESECTION_H_
namespace java {namespace lang {
class IObject;
}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace compile {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;



class DebugProbeSection final : public virtual IObject {
public:
	DebugProbeSection(const DebugProbeSection& base) = default;
public:
	DebugProbeSection(ThreadContext* ctx) throw()  : IObject(ctx), name(nullptr), _start(0), _end(0)
	{
	}
	void __construct_impl(ThreadContext* ctx) throw() 
	{
	}
	DebugProbeSection(String* name, ThreadContext* ctx) throw() ;
	void __construct_impl(String* name, ThreadContext* ctx) throw() ;
	virtual ~DebugProbeSection() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	String* name;
	long long _start;
	long long _end;
public:
	void print(ThreadContext* ctx) throw() ;
	void start(ThreadContext* ctx) throw() ;
	void end(ThreadContext* ctx) throw() ;
	long long getStart(ThreadContext* ctx) throw() ;
	long long getEnd(ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}

#endif /* end of ALINOUS_COMPILE_DEBUGPROBESECTION_H_ */
