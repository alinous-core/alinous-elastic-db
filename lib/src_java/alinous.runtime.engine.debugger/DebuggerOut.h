#ifndef ALINOUS_RUNTIME_ENGINE_DEBUGGER_DEBUGGEROUT_H_
#define ALINOUS_RUNTIME_ENGINE_DEBUGGER_DEBUGGEROUT_H_
namespace java {namespace lang {
class IObject;
}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace runtime {namespace engine {namespace debugger {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;



class DebuggerOut final : public virtual IObject {
public:
	DebuggerOut(const DebuggerOut& base) = default;
public:
	DebuggerOut(ThreadContext* ctx) throw()  : IObject(ctx)
	{
	}
	void __construct_impl(ThreadContext* ctx) throw() 
	{
	}
	virtual ~DebuggerOut() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
public:
	static void out(String* str, ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}}}

#endif /* end of ALINOUS_RUNTIME_ENGINE_DEBUGGER_DEBUGGEROUT_H_ */
