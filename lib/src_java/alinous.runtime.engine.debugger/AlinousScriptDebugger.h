#ifndef ALINOUS_RUNTIME_ENGINE_DEBUGGER_ALINOUSSCRIPTDEBUGGER_H_
#define ALINOUS_RUNTIME_ENGINE_DEBUGGER_ALINOUSSCRIPTDEBUGGER_H_
namespace alinous{namespace annotation{
class OneSource;
}}
namespace alinous{namespace annotation{
class ThreadMonitor;
}}
namespace alinous {namespace system {
class AlinousCore;}}

namespace alinous {namespace runtime {namespace engine {namespace debugger {
class AlinousDebugEventNotifier;}}}}

namespace alinous {namespace runtime {namespace engine {
class ScriptMachine;}}}

namespace alinous {namespace runtime {namespace engine {namespace debugger {
class DebugThread;}}}}

namespace java {namespace lang {
class Long;}}

namespace alinous {namespace runtime {namespace engine {namespace debugger {namespace server {
class NotifyThreadStartCommand;}}}}}

namespace alinous {namespace system {
class AlinousException;}}

namespace alinous {namespace runtime {namespace engine {namespace debugger {namespace server {
class NotifyThreadEndedCommand;}}}}}

namespace alinous {namespace runtime {namespace engine {namespace debugger {namespace server {
class IDebuggerOperation;}}}}}

namespace alinous {namespace compile {
class IStatement;}}

namespace alinous {namespace runtime {namespace engine {namespace debugger {
class AlinousDebugEvent;}}}}

namespace alinous {namespace compile {
class AbstractSrcElement;}}

namespace alinous {namespace compile {namespace expression {
class IExpression;}}}

namespace alinous {namespace runtime {namespace engine {namespace debugger {namespace server {
class FileBreakpointContainer;}}}}}

namespace alinous {namespace runtime {namespace engine {namespace debugger {namespace server {
class ServerBreakPoint;}}}}}

namespace java {namespace util {
template <typename  T> class Iterator;}}

namespace java {namespace util {
template <typename  T, typename V> class HashMap;}}

namespace alinous {namespace lock {
class LockObject;}}

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
using ::java::util::HashMap;
using ::java::util::Iterator;
using ::alinous::compile::AbstractSrcElement;
using ::alinous::compile::IStatement;
using ::alinous::compile::expression::IExpression;
using ::alinous::lock::LockObject;
using ::alinous::runtime::engine::ScriptMachine;
using ::alinous::runtime::engine::debugger::server::FileBreakpointContainer;
using ::alinous::runtime::engine::debugger::server::IDebuggerOperation;
using ::alinous::runtime::engine::debugger::server::NotifyThreadEndedCommand;
using ::alinous::runtime::engine::debugger::server::NotifyThreadStartCommand;
using ::alinous::runtime::engine::debugger::server::ServerBreakPoint;
using ::alinous::system::AlinousCore;
using ::alinous::system::AlinousException;



class AlinousScriptDebugger final : public ThreadMonitor, public virtual IObject {
public:
	AlinousScriptDebugger(const AlinousScriptDebugger& base) = default;
public:
	AlinousScriptDebugger(AlinousCore* core, int debugPort, ThreadContext* ctx) throw() ;
	void __construct_impl(AlinousCore* core, int debugPort, ThreadContext* ctx) throw() ;
	virtual ~AlinousScriptDebugger() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
public:
	AlinousCore* core;
	HashMap<String,FileBreakpointContainer>* breakPointContainers;
	LockObject* lock;
	AlinousDebugEventNotifier* debugEventNotifier;
private:
	HashMap<Long,DebugThread>* threads;
	long long hotThreadId;
public:
	void dispose(ThreadContext* ctx);
	void startAlinousOperation(ScriptMachine* machine, ThreadContext* ctx) throw() ;
	void endAlinousOperation(ScriptMachine* machine, ThreadContext* ctx) throw() ;
	void setOperation(long long threadId, IDebuggerOperation* ope, ThreadContext* ctx) throw() ;
	void notifyBefore(IStatement* srcElement, ScriptMachine* machine, ThreadContext* ctx) throw() ;
	void notifyBeforeExpression(IExpression* srcExp, ScriptMachine* machine, ThreadContext* ctx) throw() ;
	void clearBreakpoints(String* filePath, ThreadContext* ctx) throw() ;
	FileBreakpointContainer* getFileBreakpointContainer(String* filePath, ThreadContext* ctx) throw() ;
	void addBreakPoint(ServerBreakPoint* breakpoint, ThreadContext* ctx) throw() ;
	void setBreakpoints(IArrayObject<ServerBreakPoint>* breakpoints, ThreadContext* ctx) throw() ;
	void clearBreakpoints(ThreadContext* ctx) throw() ;
	void removeBreakpoint(String* filePath, int line, ThreadContext* ctx) throw() ;
	void resume(long long hotThreadId, ThreadContext* ctx) throw() ;
	DebugThread* getDebugThread(long long threadId, ThreadContext* ctx) throw() ;
	long long getHotThreadId(ThreadContext* ctx) throw() ;
	void setHotThreadId(long long hotThreadId, ThreadContext* ctx) throw() ;
	IArrayObject<DebugThread>* getThreads(ThreadContext* ctx) throw() ;
	AlinousDebugEventNotifier* getDebugEventNotifier(ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}}}

#endif /* end of ALINOUS_RUNTIME_ENGINE_DEBUGGER_ALINOUSSCRIPTDEBUGGER_H_ */
