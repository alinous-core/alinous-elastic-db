#ifndef ALINOUS_RUNTIME_ENGINE_DEBUGGER_SERVER_RUNNINGOPERATION_H_
#define ALINOUS_RUNTIME_ENGINE_DEBUGGER_SERVER_RUNNINGOPERATION_H_
namespace alinous {namespace runtime {namespace engine {namespace debugger {
class DebugThread;}}}}

namespace alinous {namespace runtime {namespace engine {namespace debugger {
class AlinousScriptDebugger;}}}}

namespace alinous {namespace runtime {namespace engine {namespace debugger {
class AlinousDebugEvent;}}}}

namespace alinous {namespace runtime {namespace engine {
class ScriptMachine;}}}

namespace alinous {namespace runtime {namespace engine {
class MainStackFrame;}}}

namespace alinous {namespace runtime {namespace engine {namespace debugger {
class AlinousDebugEventNotifier;}}}}

namespace alinous {namespace runtime {namespace engine {namespace debugger {namespace server {
class NotifyHitBreakpoint;}}}}}

namespace java {namespace io {
class IOException;}}

namespace java {namespace lang {
class InterruptedException;}}

namespace alinous {namespace runtime {namespace engine {namespace debugger {namespace server {
class AbstractDebuggerOperation;}}}}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace runtime {namespace engine {namespace debugger {namespace server {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::java::io::IOException;
using ::alinous::runtime::engine::MainStackFrame;
using ::alinous::runtime::engine::ScriptMachine;
using ::alinous::runtime::engine::debugger::AlinousDebugEvent;
using ::alinous::runtime::engine::debugger::AlinousDebugEventNotifier;
using ::alinous::runtime::engine::debugger::AlinousScriptDebugger;
using ::alinous::runtime::engine::debugger::DebugThread;



class RunningOperation final : public AbstractDebuggerOperation {
public:
	RunningOperation(const RunningOperation& base) = default;
public:
	RunningOperation(DebugThread* thread, AlinousScriptDebugger* manager, ThreadContext* ctx) throw() ;
	void __construct_impl(DebugThread* thread, AlinousScriptDebugger* manager, ThreadContext* ctx) throw() ;
	virtual ~RunningOperation() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
public:
	void init(DebugThread* debugThread, AlinousScriptDebugger* manager, ThreadContext* ctx) throw()  final;
	void handleEvent(AlinousDebugEvent* event, ScriptMachine* machine, ThreadContext* ctx) throw()  final;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}}}}

#endif /* end of ALINOUS_RUNTIME_ENGINE_DEBUGGER_SERVER_RUNNINGOPERATION_H_ */
