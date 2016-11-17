#ifndef ALINOUS_RUNTIME_ENGINE_DEBUGGER_SERVER_ICOMMANDSENDER_H_
#define ALINOUS_RUNTIME_ENGINE_DEBUGGER_SERVER_ICOMMANDSENDER_H_
namespace alinous {namespace runtime {namespace engine {namespace debugger {namespace server {
class IServerCommand;}}}}}

namespace alinous {namespace runtime {namespace engine {
class ScriptMachine;}}}

namespace alinous {namespace runtime {namespace engine {namespace debugger {
class AlinousScriptDebugger;}}}}

namespace java {namespace io {
class IOException;}}

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
using ::java::io::IOException;
using ::alinous::runtime::engine::ScriptMachine;
using ::alinous::runtime::engine::debugger::AlinousScriptDebugger;



class ICommandSender : public virtual IObject {
public:
	ICommandSender(const ICommandSender& base) = default;
public:
	ICommandSender(ThreadContext* ctx) throw()  : IObject(ctx)
	{
	}
	void __construct_impl(ThreadContext* ctx) throw() 
	{
	}
	virtual ~ICommandSender() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
public:
	virtual void sendCommand(IServerCommand* command, ScriptMachine* context, ThreadContext* ctx) = 0;
	virtual AlinousScriptDebugger* getDebugManager(ThreadContext* ctx) throw()  = 0;
	virtual void debugOut(String* str, ThreadContext* ctx) throw()  = 0;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}}}}

#endif /* end of ALINOUS_RUNTIME_ENGINE_DEBUGGER_SERVER_ICOMMANDSENDER_H_ */
