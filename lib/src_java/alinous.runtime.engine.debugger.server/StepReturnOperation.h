#ifndef ALINOUS_RUNTIME_ENGINE_DEBUGGER_SERVER_STEPRETURNOPERATION_H_
#define ALINOUS_RUNTIME_ENGINE_DEBUGGER_SERVER_STEPRETURNOPERATION_H_
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

namespace alinous {namespace runtime {namespace engine {namespace debugger {namespace server {
class AbstractDebuggerOperation;}}}}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace runtime {namespace engine {namespace debugger {namespace server {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::alinous::runtime::engine::MainStackFrame;
using ::alinous::runtime::engine::ScriptMachine;
using ::alinous::runtime::engine::debugger::AlinousDebugEvent;
using ::alinous::runtime::engine::debugger::AlinousScriptDebugger;
using ::alinous::runtime::engine::debugger::DebugThread;



class StepReturnOperation final : public AbstractDebuggerOperation {
public:
	StepReturnOperation(const StepReturnOperation& base) = default;
public:
	StepReturnOperation(DebugThread* thread, AlinousScriptDebugger* manager, long long currentStackId, ThreadContext* ctx) throw() ;
	void __construct_impl(DebugThread* thread, AlinousScriptDebugger* manager, long long currentStackId, ThreadContext* ctx) throw() ;
	virtual ~StepReturnOperation() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	long long currentStackId;
public:
	void handleEvent(AlinousDebugEvent* event, ScriptMachine* machine, ThreadContext* ctx) throw()  final;
	void init(DebugThread* debugThread, AlinousScriptDebugger* manager, ThreadContext* ctx) throw()  final;
	long long getCurrentStackId(ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx);
};

}}}}}

#endif /* end of ALINOUS_RUNTIME_ENGINE_DEBUGGER_SERVER_STEPRETURNOPERATION_H_ */
