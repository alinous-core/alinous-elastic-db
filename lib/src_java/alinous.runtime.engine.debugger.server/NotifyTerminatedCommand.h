#ifndef ALINOUS_RUNTIME_ENGINE_DEBUGGER_SERVER_NOTIFYTERMINATEDCOMMAND_H_
#define ALINOUS_RUNTIME_ENGINE_DEBUGGER_SERVER_NOTIFYTERMINATEDCOMMAND_H_
namespace java {namespace io {
class Writer;}}

namespace alinous {namespace runtime {namespace engine {namespace debugger {namespace server {
class AbstractAlinousServerCommand;}}}}}

namespace java {namespace io {
class IOException;}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace runtime {namespace engine {namespace debugger {namespace server {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::java::io::IOException;
using ::java::io::Writer;



class NotifyTerminatedCommand final : public AbstractAlinousServerCommand {
public:
	NotifyTerminatedCommand(const NotifyTerminatedCommand& base) = default;
public:
	NotifyTerminatedCommand(long long threadId, ThreadContext* ctx) throw() ;
	void __construct_impl(long long threadId, ThreadContext* ctx) throw() ;
	virtual ~NotifyTerminatedCommand() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
public:
	static String* CMD_STRING;
public:
	void writeCommand(Writer* writer, ThreadContext* ctx) final;
	String* getName(ThreadContext* ctx) throw()  final;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}}}}

#endif /* end of ALINOUS_RUNTIME_ENGINE_DEBUGGER_SERVER_NOTIFYTERMINATEDCOMMAND_H_ */
