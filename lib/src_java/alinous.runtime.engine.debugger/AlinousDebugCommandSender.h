#ifndef ALINOUS_RUNTIME_ENGINE_DEBUGGER_ALINOUSDEBUGCOMMANDSENDER_H_
#define ALINOUS_RUNTIME_ENGINE_DEBUGGER_ALINOUSDEBUGCOMMANDSENDER_H_
namespace alinous {namespace runtime {namespace engine {namespace debugger {
class IHttpAccessMethod;}}}}

namespace alinous {namespace runtime {namespace engine {namespace debugger {
class AlinousServerDebugHttpResponse;}}}}

namespace alinous {namespace runtime {namespace engine {namespace debugger {namespace client {
class IClientRequest;}}}}}

namespace java {namespace util {
template <typename  T, typename V> class Map;}}

namespace java {namespace io {
class IOException;}}

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
using ::java::util::Map;
using ::alinous::runtime::engine::debugger::client::IClientRequest;
using ::alinous::system::AlinousException;



class AlinousDebugCommandSender final : public virtual IObject {
public:
	AlinousDebugCommandSender(const AlinousDebugCommandSender& base) = default;
public:
	AlinousDebugCommandSender(String* httpHost, IHttpAccessMethod* httpAccessMethod, ThreadContext* ctx) throw() ;
	void __construct_impl(String* httpHost, IHttpAccessMethod* httpAccessMethod, ThreadContext* ctx) throw() ;
	virtual ~AlinousDebugCommandSender() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	IHttpAccessMethod* httpAccessMethod;
	String* httpHost;
public:
	static String* COMMAND;
public:
	bool checkPortOpened(ThreadContext* ctx) throw() ;
	AlinousServerDebugHttpResponse* sendCommand(IClientRequest* request, ThreadContext* ctx);
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx);
};

}}}}

#endif /* end of ALINOUS_RUNTIME_ENGINE_DEBUGGER_ALINOUSDEBUGCOMMANDSENDER_H_ */
