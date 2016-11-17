#ifndef ALINOUS_RUNTIME_ENGINE_DEBUGGER_CLIENT_ADDBREAKPOINTSREQUEST_H_
#define ALINOUS_RUNTIME_ENGINE_DEBUGGER_CLIENT_ADDBREAKPOINTSREQUEST_H_
namespace alinous {namespace runtime {namespace engine {namespace debugger {namespace server {
class ServerBreakPoint;}}}}}

namespace alinous {namespace runtime {namespace engine {namespace debugger {
class AlinousServerDebugHttpResponse;}}}}

namespace alinous {namespace runtime {namespace engine {namespace debugger {
class AlinousScriptDebugger;}}}}

namespace java {namespace util {
template <typename  T, typename V> class Map;}}

namespace java {namespace util {
template <typename  T, typename V> class HashMap;}}

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
using ::java::util::HashMap;
using ::java::util::Map;
using ::alinous::runtime::engine::debugger::AlinousScriptDebugger;
using ::alinous::runtime::engine::debugger::AlinousServerDebugHttpResponse;
using ::alinous::runtime::engine::debugger::server::ServerBreakPoint;



class AddBreakpointsRequest final : public IClientRequest, public virtual IObject {
public:
	AddBreakpointsRequest(const AddBreakpointsRequest& base) = default;
public:
	AddBreakpointsRequest(ThreadContext* ctx) throw()  : IObject(ctx), IClientRequest(ctx), breakpoint(nullptr)
	{
	}
	void __construct_impl(ThreadContext* ctx) throw() 
	{
	}
	AddBreakpointsRequest(ServerBreakPoint* breakpoint, ThreadContext* ctx) throw() ;
	void __construct_impl(ServerBreakPoint* breakpoint, ThreadContext* ctx) throw() ;
	virtual ~AddBreakpointsRequest() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	ServerBreakPoint* breakpoint;
public:
	static String* LINE;
	static String* FILE_PATH;
public:
	AlinousServerDebugHttpResponse* executeRequest(AlinousScriptDebugger* debugManager, ThreadContext* ctx) throw()  final;
	String* getCommand(ThreadContext* ctx) throw()  final;
	Map<String,String>* getParamMap(ThreadContext* ctx) throw()  final;
	void importParams(Map<String,String>* params, ThreadContext* ctx) throw()  final;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}}}}

#endif /* end of ALINOUS_RUNTIME_ENGINE_DEBUGGER_CLIENT_ADDBREAKPOINTSREQUEST_H_ */
