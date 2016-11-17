#ifndef ALINOUS_RUNTIME_ENGINE_DEBUGGER_DEBUGTHREAD_H_
#define ALINOUS_RUNTIME_ENGINE_DEBUGGER_DEBUGTHREAD_H_
namespace alinous {namespace runtime {namespace engine {
class ScriptMachine;}}}

namespace alinous {namespace runtime {namespace engine {namespace debugger {
class AlinousScriptDebugger;}}}}

namespace alinous {namespace runtime {namespace engine {namespace debugger {namespace server {
class RunningOperation;}}}}}

namespace alinous {namespace runtime {namespace engine {namespace debugger {
class DebugThread;}}}}

namespace alinous {namespace html {
class DomNode;}}

namespace alinous {namespace html {namespace xpath {
class IVariableValue;}}}

namespace java {namespace util {
template <typename  T> class Stack;}}

namespace alinous {namespace runtime {namespace engine {
class MainStackFrame;}}}

namespace alinous {namespace html {
class Attribute;}}

namespace alinous {namespace runtime {namespace engine {namespace debugger {namespace server {
class IDebuggerOperation;}}}}}

namespace alinous {namespace runtime {namespace engine {namespace debugger {
class AlinousDebugEvent;}}}}

namespace alinous {namespace runtime {namespace engine {namespace debugger {
class DebugStackFrame;}}}}

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
using ::java::util::ArrayList;
using ::java::util::Stack;
using ::alinous::html::Attribute;
using ::alinous::html::DomNode;
using ::alinous::html::xpath::IVariableValue;
using ::alinous::lock::LockObject;
using ::alinous::runtime::engine::MainStackFrame;
using ::alinous::runtime::engine::ScriptMachine;
using ::alinous::runtime::engine::debugger::server::IDebuggerOperation;
using ::alinous::runtime::engine::debugger::server::RunningOperation;



class DebugThread final : public virtual IObject {
public:
	DebugThread(const DebugThread& base) = default;
public:
	DebugThread(ThreadContext* ctx) throw()  : IObject(ctx), threadId(0), machine(nullptr), operation(nullptr), status(0), sem(__GC_INS(this, (new(ctx) LockObject(ctx)), LockObject)), stackFrames(nullptr)
	{
	}
	void __construct_impl(ThreadContext* ctx) throw() 
	{
	}
	DebugThread(long long threadId, ScriptMachine* machine, ThreadContext* ctx) throw() ;
	void __construct_impl(long long threadId, ScriptMachine* machine, ThreadContext* ctx) throw() ;
	virtual ~DebugThread() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
public:
	long long threadId;
	ScriptMachine* machine;
private:
	IDebuggerOperation* operation;
	int status;
	LockObject* sem;
	Stack<MainStackFrame>* stackFrames;
public:
	constexpr static const int STATUS_NONE{0};
	constexpr static const int STATUS_RUNNING{1};
	constexpr static const int STATUS_SUSPEND{10};
	static String* TAG_THREAD;
	static String* ATTR_THREAD_ID;
	static String* ATTR_STATUS;
public:
	void outDebugXml(DomNode* parentNode, ThreadContext* ctx) throw() ;
	IDebuggerOperation* getOperation(ThreadContext* ctx) throw() ;
	void setOperation(IDebuggerOperation* ope, AlinousScriptDebugger* manager, ThreadContext* ctx) throw() ;
	void handleEvent(AlinousDebugEvent* event, ScriptMachine* machine, ThreadContext* ctx) throw() ;
	long long getThreadId(ThreadContext* ctx) throw() ;
	void suspend(ThreadContext* ctx);
	void resume(ThreadContext* ctx) throw() ;
	int getStatus(ThreadContext* ctx) throw() ;
	void terminate(ThreadContext* ctx) throw() ;
	IArrayObject<DebugStackFrame>* getStackFrames(ThreadContext* ctx) throw() ;
private:
	void init(AlinousScriptDebugger* manager, ThreadContext* ctx) throw() ;
public:
	static DebugThread* importFromDebugXml(DomNode* node, ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}}}

#endif /* end of ALINOUS_RUNTIME_ENGINE_DEBUGGER_DEBUGTHREAD_H_ */
