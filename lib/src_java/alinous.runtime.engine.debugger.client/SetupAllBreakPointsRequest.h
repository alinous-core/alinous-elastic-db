#ifndef ALINOUS_RUNTIME_ENGINE_DEBUGGER_CLIENT_SETUPALLBREAKPOINTSREQUEST_H_
#define ALINOUS_RUNTIME_ENGINE_DEBUGGER_CLIENT_SETUPALLBREAKPOINTSREQUEST_H_
namespace alinous {namespace runtime {namespace engine {namespace debugger {namespace server {
class ServerBreakPoint;}}}}}

namespace alinous {namespace runtime {namespace engine {namespace debugger {
class AlinousServerDebugHttpResponse;}}}}

namespace alinous {namespace runtime {namespace engine {namespace debugger {
class AlinousScriptDebugger;}}}}

namespace java {namespace util {
template <typename  T> class Iterator;}}

namespace java {namespace util {
template <typename  T, typename V> class Map;}}

namespace java {namespace util {
template <typename  T, typename V> class HashMap;}}

namespace java {namespace util {
template <typename  T> class List;}}

namespace alinous {namespace runtime {namespace engine {namespace debugger {namespace client {
class IClientRequest;}}}}}

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
using ::java::util::ArrayList;
using ::java::util::HashMap;
using ::java::util::Iterator;
using ::java::util::List;
using ::java::util::Map;
using ::alinous::runtime::engine::debugger::AlinousScriptDebugger;
using ::alinous::runtime::engine::debugger::AlinousServerDebugHttpResponse;
using ::alinous::runtime::engine::debugger::server::ServerBreakPoint;



class SetupAllBreakPointsRequest final : public IClientRequest, public virtual IObject {
public:
	SetupAllBreakPointsRequest(const SetupAllBreakPointsRequest& base) = default;
public:
	SetupAllBreakPointsRequest(ThreadContext* ctx) throw() ;
	void __construct_impl(ThreadContext* ctx) throw() ;
	virtual ~SetupAllBreakPointsRequest() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	List<ServerBreakPoint>* breakpoints;
public:
	void addBreakpoint(ServerBreakPoint* breakpoint, ThreadContext* ctx) throw() ;
	AlinousServerDebugHttpResponse* executeRequest(AlinousScriptDebugger* debugManager, ThreadContext* ctx) throw()  final;
	String* getCommand(ThreadContext* ctx) throw()  final;
	Map<String,String>* getParamMap(ThreadContext* ctx) throw()  final;
	void importParams(Map<String,String>* params, ThreadContext* ctx) throw()  final;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx);
};

}}}}}

#endif /* end of ALINOUS_RUNTIME_ENGINE_DEBUGGER_CLIENT_SETUPALLBREAKPOINTSREQUEST_H_ */
