#ifndef ALINOUS_SERVER_DEBUG_DEBUGPROCESSOR_H_
#define ALINOUS_SERVER_DEBUG_DEBUGPROCESSOR_H_
namespace alinous {namespace server {
class BinaryContentByteStream;}}

namespace alinous {namespace system {
class AlinousCore;}}

namespace alinous {namespace server {namespace http {
class HttpHeaderProcessor;}}}

namespace alinous {namespace runtime {namespace engine {namespace debugger {
class AlinousScriptDebugger;}}}}

namespace java {namespace util {
template <typename  T, typename V> class Map;}}

namespace java {namespace util {
template <typename  T, typename V> class HashMap;}}

namespace java {namespace util {
template <typename  T> class Iterator;}}

namespace alinous {namespace server {namespace http {namespace params {
class AbstractHttpParameter;}}}}

namespace alinous {namespace server {namespace http {namespace params {
class HttpParameter;}}}}

namespace alinous {namespace runtime {namespace engine {namespace debugger {namespace client {
class IClientRequest;}}}}}

namespace alinous {namespace runtime {namespace engine {namespace debugger {
class AlinousServerDebugHttpResponse;}}}}

namespace java {namespace lang {
class Throwable;}}

namespace alinous {namespace runtime {namespace engine {namespace debugger {namespace client {
class ClientRequestFactory;}}}}}

namespace java {namespace lang {
class IObject;
}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace server {namespace debug {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::java::util::HashMap;
using ::java::util::Iterator;
using ::java::util::Map;
using ::alinous::runtime::engine::debugger::AlinousScriptDebugger;
using ::alinous::runtime::engine::debugger::AlinousServerDebugHttpResponse;
using ::alinous::runtime::engine::debugger::client::ClientRequestFactory;
using ::alinous::runtime::engine::debugger::client::IClientRequest;
using ::alinous::server::BinaryContentByteStream;
using ::alinous::server::http::HttpHeaderProcessor;
using ::alinous::server::http::params::AbstractHttpParameter;
using ::alinous::server::http::params::HttpParameter;
using ::alinous::system::AlinousCore;



class DebugProcessor final : public virtual IObject {
public:
	DebugProcessor(const DebugProcessor& base) = default;
public:
	DebugProcessor(ThreadContext* ctx) throw()  : IObject(ctx)
	{
	}
	void __construct_impl(ThreadContext* ctx) throw() 
	{
	}
	virtual ~DebugProcessor() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
public:
	static BinaryContentByteStream* process(AlinousCore* core, HttpHeaderProcessor* request, ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}}

#endif /* end of ALINOUS_SERVER_DEBUG_DEBUGPROCESSOR_H_ */
