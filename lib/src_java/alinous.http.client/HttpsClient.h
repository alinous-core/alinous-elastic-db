#ifndef ALINOUS_HTTP_CLIENT_HTTPSCLIENT_H_
#define ALINOUS_HTTP_CLIENT_HTTPSCLIENT_H_
namespace javax {namespace net {namespace ssl {
class SSLSocketFactory;}}}

namespace alinous {namespace http {namespace client {
class HttpClient;}}}

namespace java {namespace io {
class IOException;}}

namespace alinous {namespace net {
class UnknownHostException;}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace http {namespace client {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::java::io::IOException;
using ::javax::net::ssl::SSLSocketFactory;
using ::alinous::net::UnknownHostException;



class HttpsClient final : public HttpClient {
public:
	HttpsClient(const HttpsClient& base) = default;
public:
	HttpsClient(ThreadContext* ctx) throw()  : IObject(ctx), HttpClient(ctx)
	{
	}
	void __construct_impl(ThreadContext* ctx) throw() 
	{
	}
	virtual ~HttpsClient() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
public:
	void connect(String* host, int port, ThreadContext* ctx) final;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}}

#endif /* end of ALINOUS_HTTP_CLIENT_HTTPSCLIENT_H_ */
