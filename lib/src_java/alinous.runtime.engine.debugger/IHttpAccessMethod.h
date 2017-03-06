#ifndef ALINOUS_RUNTIME_ENGINE_DEBUGGER_IHTTPACCESSMETHOD_H_
#define ALINOUS_RUNTIME_ENGINE_DEBUGGER_IHTTPACCESSMETHOD_H_
namespace alinous {namespace runtime {namespace engine {namespace debugger {
class AlinousServerDebugHttpResponse;}}}}

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
using ::alinous::system::AlinousException;



class IHttpAccessMethod : public virtual IObject {
public:
	IHttpAccessMethod(const IHttpAccessMethod& base) = default;
public:
	IHttpAccessMethod(ThreadContext* ctx) throw() ;
	void __construct_impl(ThreadContext* ctx) throw() ;
	virtual ~IHttpAccessMethod() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
public:
	virtual AlinousServerDebugHttpResponse* httpPost(String* httpHost, Map<String,String>* params, ThreadContext* ctx) = 0;
	virtual bool checkHealth(String* httpHost, ThreadContext* ctx) throw()  = 0;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx);
};

}}}}

#endif /* end of ALINOUS_RUNTIME_ENGINE_DEBUGGER_IHTTPACCESSMETHOD_H_ */
