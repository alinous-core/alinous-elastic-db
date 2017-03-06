#ifndef ALINOUS_RUNTIME_ENGINE_DEBUGGER_SERVER_ISERVERCOMMAND_H_
#define ALINOUS_RUNTIME_ENGINE_DEBUGGER_SERVER_ISERVERCOMMAND_H_
namespace java {namespace io {
class Writer;}}

namespace alinous {namespace runtime {namespace engine {namespace debugger {namespace server {
class ICommandSender;}}}}}

namespace alinous {namespace runtime {namespace engine {
class ScriptMachine;}}}

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
using ::java::io::Writer;
using ::alinous::runtime::engine::ScriptMachine;



class IServerCommand : public virtual IObject {
public:
	IServerCommand(const IServerCommand& base) = default;
public:
	IServerCommand(ThreadContext* ctx) throw() ;
	void __construct_impl(ThreadContext* ctx) throw() ;
	virtual ~IServerCommand() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
public:
	virtual void writeCommand(Writer* writer, ThreadContext* ctx) = 0;
	virtual String* getName(ThreadContext* ctx) throw()  = 0;
	virtual long long getThreadId(ThreadContext* ctx) throw()  = 0;
	virtual void sendCommand(ICommandSender* notifier, ScriptMachine* context, ThreadContext* ctx) = 0;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx);
};

}}}}}

#endif /* end of ALINOUS_RUNTIME_ENGINE_DEBUGGER_SERVER_ISERVERCOMMAND_H_ */
