#ifndef ALINOUS_RUNTIME_ENGINE_DEBUGGER_ALINOUSDEBUGEVENTNOTIFIER_H_
#define ALINOUS_RUNTIME_ENGINE_DEBUGGER_ALINOUSDEBUGEVENTNOTIFIER_H_
namespace alinous {namespace runtime {namespace engine {namespace debugger {
class AlinousScriptDebugger;}}}}

namespace java {namespace lang {
class Thread;}}

namespace java {namespace lang {
class InterruptedException;}}

namespace alinous {namespace runtime {namespace engine {namespace debugger {namespace server {
class IServerCommand;}}}}}

namespace alinous {namespace runtime {namespace engine {
class ScriptMachine;}}}

namespace java {namespace lang {
class Throwable;}}

namespace java {namespace net {
class Socket;}}

namespace java {namespace io {
class OutputStream;}}

namespace java {namespace io {
class Writer;}}

namespace java {namespace io {
class PrintWriter;}}

namespace java {namespace io {
class IOException;}}

namespace java {namespace util {
template <typename  T> class List;}}

namespace java {namespace util {
template <typename  T> class LinkedList;}}

namespace alinous {namespace lock {
class LockObject;}}

namespace java {namespace lang {
class Runnable;}}

namespace alinous {namespace runtime {namespace engine {namespace debugger {namespace server {
class ICommandSender;}}}}}

namespace alinous {namespace system {
class AlinousException;}}

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
using ::java::io::IOException;
using ::java::io::OutputStream;
using ::java::io::PrintWriter;
using ::java::io::Writer;
using ::java::net::Socket;
using ::java::util::LinkedList;
using ::java::util::List;
using ::alinous::lock::LockObject;
using ::alinous::runtime::engine::ScriptMachine;
using ::alinous::runtime::engine::debugger::server::ICommandSender;
using ::alinous::runtime::engine::debugger::server::IServerCommand;
using ::alinous::system::AlinousException;



class AlinousDebugEventNotifier final : public Runnable, public ICommandSender, public virtual IObject {
public:
	AlinousDebugEventNotifier(const AlinousDebugEventNotifier& base) = default;
public:
	AlinousDebugEventNotifier(AlinousScriptDebugger* debugManager, ThreadContext* ctx) throw() ;
	void __construct_impl(AlinousScriptDebugger* debugManager, ThreadContext* ctx) throw() ;
	virtual ~AlinousDebugEventNotifier() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	int port;
	List<IServerCommand>* commandqueue;
	LockObject* lock;
	bool loop;
	AlinousScriptDebugger* debugManager;
	Thread* th;
public:
	constexpr static const bool debugDebugger{false};
public:
	void dispose(ThreadContext* ctx);
	void notifyToClient(IServerCommand* command, ScriptMachine* machine, ThreadContext* ctx);
	void run(ThreadContext* ctx) throw() ;
	void sendCommand(IServerCommand* command, ScriptMachine* context, ThreadContext* ctx) final;
	IServerCommand* fetch(ThreadContext* ctx) throw() ;
	int getPort(ThreadContext* ctx) throw() ;
	void setPort(int port, ThreadContext* ctx) throw() ;
	void debugOut(String* str, ThreadContext* ctx) throw()  final;
	AlinousScriptDebugger* getDebugManager(ThreadContext* ctx) throw()  final;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}}}

#endif /* end of ALINOUS_RUNTIME_ENGINE_DEBUGGER_ALINOUSDEBUGEVENTNOTIFIER_H_ */
