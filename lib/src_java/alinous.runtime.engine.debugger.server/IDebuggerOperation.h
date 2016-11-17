#ifndef ALINOUS_RUNTIME_ENGINE_DEBUGGER_SERVER_IDEBUGGEROPERATION_H_
#define ALINOUS_RUNTIME_ENGINE_DEBUGGER_SERVER_IDEBUGGEROPERATION_H_
namespace alinous {namespace runtime {namespace engine {namespace debugger {
class AlinousDebugEvent;}}}}

namespace alinous {namespace runtime {namespace engine {
class ScriptMachine;}}}

namespace alinous {namespace runtime {namespace engine {namespace debugger {
class DebugThread;}}}}

namespace alinous {namespace runtime {namespace engine {namespace debugger {
class AlinousScriptDebugger;}}}}

namespace java {namespace lang {
class IObject;
}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace runtime {namespace engine {namespace debugger {namespace server {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::alinous::runtime::engine::ScriptMachine;
using ::alinous::runtime::engine::debugger::AlinousDebugEvent;
using ::alinous::runtime::engine::debugger::AlinousScriptDebugger;
using ::alinous::runtime::engine::debugger::DebugThread;



class IDebuggerOperation : public virtual IObject {
public:
	IDebuggerOperation(const IDebuggerOperation& base) = default;
public:
	IDebuggerOperation(ThreadContext* ctx) throw()  : IObject(ctx)
	{
	}
	void __construct_impl(ThreadContext* ctx) throw() 
	{
	}
	virtual ~IDebuggerOperation() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
public:
	virtual void handleEvent(AlinousDebugEvent* event, ScriptMachine* machine, ThreadContext* ctx) throw()  = 0;
	virtual void init(DebugThread* debugThread, AlinousScriptDebugger* manager, ThreadContext* ctx) throw()  = 0;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}}}}

#endif /* end of ALINOUS_RUNTIME_ENGINE_DEBUGGER_SERVER_IDEBUGGEROPERATION_H_ */
