#ifndef ALINOUS_SERVER_HTTP_HTTPPARAMHANDLER_H_
#define ALINOUS_SERVER_HTTP_HTTPPARAMHANDLER_H_
namespace java {namespace util {
template <typename  T, typename V> class HashMap;}}

namespace alinous {namespace server {namespace http {namespace params {
class AbstractHttpParameter;}}}}

namespace java {namespace io {
class InputStream;}}

namespace alinous {namespace server {namespace http {
class PostUrlEncodedReader;}}}

namespace alinous {namespace server {namespace http {
class MimeFormParameterDecoder;}}}

namespace java {namespace io {
class IOException;}}

namespace java {namespace lang {
class IObject;
}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace server {namespace http {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::java::io::IOException;
using ::java::io::InputStream;
using ::java::util::HashMap;
using ::alinous::server::http::params::AbstractHttpParameter;



class HttpParamHandler final : public virtual IObject {
public:
	HttpParamHandler(const HttpParamHandler& base) = default;
public:
	HttpParamHandler(ThreadContext* ctx) throw() ;
	void __construct_impl(ThreadContext* ctx) throw() ;
	virtual ~HttpParamHandler() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
public:
	static HashMap<String,AbstractHttpParameter>* postParams(InputStream* inStream, int contentLength, String* encode, ThreadContext* ctx);
	static void postMimeParams(InputStream* inStream, int contentLength, String* contentType, ThreadContext* ctx);
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx);
};

}}}

#endif /* end of ALINOUS_SERVER_HTTP_HTTPPARAMHANDLER_H_ */
