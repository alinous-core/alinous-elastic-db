#ifndef ALINOUS_RUNTIME_ENGINE_DEBUGGER_CLIENT_ICLIENTREQUEST_H_
#define ALINOUS_RUNTIME_ENGINE_DEBUGGER_CLIENT_ICLIENTREQUEST_H_
namespace java {namespace util {
template <typename  T, typename V> class Map;}}

namespace alinous {namespace runtime {namespace engine {namespace debugger {
class AlinousServerDebugHttpResponse;}}}}

namespace alinous {namespace runtime {namespace engine {namespace debugger {
class AlinousScriptDebugger;}}}}

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
using ::alinous::runtime::engine::debugger::AlinousScriptDebugger;
using ::alinous::runtime::engine::debugger::AlinousServerDebugHttpResponse;



class IClientRequest : public virtual IObject {
public:
	IClientRequest(const IClientRequest& base) = default;
public:
	IClientRequest(ThreadContext* ctx) throw()  : IObject(ctx)
	{
	}
	void __construct_impl(ThreadContext* ctx) throw() 
	{
	}
	virtual ~IClientRequest() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
public:
	static String* CMD_TERMINATE;
	static String* CMD_STATUS_THREAD;
	static String* CMD_CLEAR_BREAKPOINTS;
	static String* CMD_SETUP_ALL_BREAKPOINTS;
	static String* CMD_ADD_BREAKPOINTS;
	static String* CMD_RESUME;
	static String* CMD_STEP_OVER;
	static String* CMD_STEP_IN;
	static String* CMD_STEP_RETURN;
public:
	virtual String* getCommand(ThreadContext* ctx) throw()  = 0;
	virtual Map<String,String>* getParamMap(ThreadContext* ctx) throw()  = 0;
	virtual void importParams(Map<String,String>* params, ThreadContext* ctx) throw()  = 0;
	virtual AlinousServerDebugHttpResponse* executeRequest(AlinousScriptDebugger* debugManager, ThreadContext* ctx) throw()  = 0;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}}}}

#endif /* end of ALINOUS_RUNTIME_ENGINE_DEBUGGER_CLIENT_ICLIENTREQUEST_H_ */
