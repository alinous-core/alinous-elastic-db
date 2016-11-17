#ifndef ALINOUS_RUNTIME_ENGINE_DEBUGGER_SERVER_ABSTRACTDEBUGGEROPERATION_H_
#define ALINOUS_RUNTIME_ENGINE_DEBUGGER_SERVER_ABSTRACTDEBUGGEROPERATION_H_
namespace alinous {namespace runtime {namespace engine {namespace debugger {
class DebugThread;}}}}

namespace alinous {namespace runtime {namespace engine {namespace debugger {
class AlinousScriptDebugger;}}}}

namespace alinous {namespace runtime {namespace engine {namespace debugger {
class AlinousDebugEvent;}}}}

namespace alinous {namespace runtime {namespace engine {namespace debugger {namespace server {
class FileBreakpointContainer;}}}}}

namespace java {namespace util {
template <typename  T> class Iterator;}}

namespace alinous {namespace runtime {namespace engine {namespace debugger {namespace server {
class ServerBreakPoint;}}}}}

namespace alinous {namespace runtime {namespace engine {namespace debugger {namespace server {
class IDebuggerOperation;}}}}}

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
using ::java::util::Iterator;
using ::alinous::runtime::engine::debugger::AlinousDebugEvent;
using ::alinous::runtime::engine::debugger::AlinousScriptDebugger;
using ::alinous::runtime::engine::debugger::DebugThread;



class AbstractDebuggerOperation : public IDebuggerOperation, public virtual IObject {
public:
	AbstractDebuggerOperation(const AbstractDebuggerOperation& base) = default;
public:
	AbstractDebuggerOperation(DebugThread* thread, AlinousScriptDebugger* manager, ThreadContext* ctx) throw() ;
	void __construct_impl(DebugThread* thread, AlinousScriptDebugger* manager, ThreadContext* ctx) throw() ;
	virtual ~AbstractDebuggerOperation() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
public:
	AlinousScriptDebugger* debugManager;
	DebugThread* thread;
public:
	long long hitBreakpoint(AlinousDebugEvent* event, ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}}}}

#endif /* end of ALINOUS_RUNTIME_ENGINE_DEBUGGER_SERVER_ABSTRACTDEBUGGEROPERATION_H_ */
