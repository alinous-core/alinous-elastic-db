#ifndef ALINOUS_RUNTIME_ENGINE_DEBUGGER_CLIENT_CLIENTREQUESTFACTORY_H_
#define ALINOUS_RUNTIME_ENGINE_DEBUGGER_CLIENT_CLIENTREQUESTFACTORY_H_
namespace alinous {namespace runtime {namespace engine {namespace debugger {namespace client {
class IClientRequest;}}}}}

namespace java {namespace util {
template <typename  T, typename V> class Map;}}

namespace alinous {namespace runtime {namespace engine {namespace debugger {namespace client {
class TerminateServerRequest;}}}}}

namespace alinous {namespace runtime {namespace engine {namespace debugger {namespace client {
class StatusThreadRequest;}}}}}

namespace alinous {namespace runtime {namespace engine {namespace debugger {namespace client {
class ClearBreakpointsRequest;}}}}}

namespace alinous {namespace runtime {namespace engine {namespace debugger {namespace client {
class AddBreakpointsRequest;}}}}}

namespace alinous {namespace runtime {namespace engine {namespace debugger {namespace client {
class SetupAllBreakPointsRequest;}}}}}

namespace alinous {namespace runtime {namespace engine {namespace debugger {namespace client {
class ResumeRequest;}}}}}

namespace alinous {namespace runtime {namespace engine {namespace debugger {namespace client {
class StepOverRequest;}}}}}

namespace alinous {namespace runtime {namespace engine {namespace debugger {namespace client {
class StepInRequest;}}}}}

namespace alinous {namespace runtime {namespace engine {namespace debugger {namespace client {
class StepReturnRequest;}}}}}

namespace alinous {namespace runtime {namespace engine {namespace debugger {
class AlinousDebugCommandSender;}}}}

namespace java {namespace lang {
class IObject;
}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace runtime {namespace engine {namespace debugger {namespace client {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::java::util::Map;
using ::alinous::runtime::engine::debugger::AlinousDebugCommandSender;



class ClientRequestFactory final : public virtual IObject {
public:
	ClientRequestFactory(const ClientRequestFactory& base) = default;
public:
	ClientRequestFactory(ThreadContext* ctx) throw()  : IObject(ctx)
	{
	}
	void __construct_impl(ThreadContext* ctx) throw() 
	{
	}
	virtual ~ClientRequestFactory() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
public:
	static IClientRequest* createRequest(Map<String,String>* params, ThreadContext* ctx) throw() ;
	static IClientRequest* createDefault(ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}}}}

#endif /* end of ALINOUS_RUNTIME_ENGINE_DEBUGGER_CLIENT_CLIENTREQUESTFACTORY_H_ */
