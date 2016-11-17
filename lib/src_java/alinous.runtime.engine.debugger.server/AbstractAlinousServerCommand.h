#ifndef ALINOUS_RUNTIME_ENGINE_DEBUGGER_SERVER_ABSTRACTALINOUSSERVERCOMMAND_H_
#define ALINOUS_RUNTIME_ENGINE_DEBUGGER_SERVER_ABSTRACTALINOUSSERVERCOMMAND_H_
namespace alinous {namespace runtime {namespace engine {namespace debugger {namespace server {
class ICommandSender;}}}}}

namespace alinous {namespace runtime {namespace engine {
class ScriptMachine;}}}

namespace java {namespace util {
template <typename  T> class List;}}

namespace alinous {namespace runtime {namespace engine {namespace debugger {namespace server {
class IServerCommand;}}}}}

namespace java {namespace util {
template <typename  T> class Iterator;}}

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
using ::java::util::Iterator;
using ::java::util::List;
using ::alinous::runtime::engine::ScriptMachine;



class AbstractAlinousServerCommand : public IServerCommand, public virtual IObject {
public:
	AbstractAlinousServerCommand(const AbstractAlinousServerCommand& base) = default;
public:
	AbstractAlinousServerCommand(long long threadId, ThreadContext* ctx) throw() ;
	void __construct_impl(long long threadId, ThreadContext* ctx) throw() ;
	virtual ~AbstractAlinousServerCommand() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	long long threadId;
public:
	long long getThreadId(ThreadContext* ctx) throw()  final;
	virtual void sendCommand(ICommandSender* notifier, ScriptMachine* context, ThreadContext* ctx);
	bool containsThread(long long threadId, List<IServerCommand>* needfinish, bool remove, ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}}}}

#endif /* end of ALINOUS_RUNTIME_ENGINE_DEBUGGER_SERVER_ABSTRACTALINOUSSERVERCOMMAND_H_ */
