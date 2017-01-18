#ifndef ALINOUS_HTTP_CLIENT_HTTPREQUESTHEADERS_H_
#define ALINOUS_HTTP_CLIENT_HTTPREQUESTHEADERS_H_
namespace java {namespace lang {
class StringBuffer;}}

namespace java {namespace io {
class IOException;}}

namespace java {namespace lang {
class IObject;
}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace http {namespace client {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::java::io::IOException;



class HttpRequestHeaders final : public virtual IObject {
public:
	HttpRequestHeaders(const HttpRequestHeaders& base) = default;
public:
	HttpRequestHeaders(ThreadContext* ctx) throw()  : IObject(ctx), userAgent(nullptr), accept(__GC_INS(this, ConstStr::getCNST_STR_1854(), String)), acceptLanguage(nullptr), acceptEncoding(nullptr), acceptCharset(nullptr), keepAlive(nullptr), connection(nullptr), cookie(nullptr)
	{
	}
	void __construct_impl(ThreadContext* ctx) throw() 
	{
	}
	virtual ~HttpRequestHeaders() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	String* userAgent;
	String* accept;
	String* acceptLanguage;
	String* acceptEncoding;
	String* acceptCharset;
	String* keepAlive;
	String* connection;
	String* cookie;
public:
	void writeHeader(StringBuffer* buff, ThreadContext* ctx);
	String* getUserAgent(ThreadContext* ctx) throw() ;
	void setUserAgent(String* userAgent, ThreadContext* ctx) throw() ;
	String* getAccept(ThreadContext* ctx) throw() ;
	void setAccept(String* accept, ThreadContext* ctx) throw() ;
	String* getAcceptLanguage(ThreadContext* ctx) throw() ;
	void setAcceptLanguage(String* acceptLanguage, ThreadContext* ctx) throw() ;
	String* getAcceptEncoding(ThreadContext* ctx) throw() ;
	void setAcceptEncoding(String* acceptEncoding, ThreadContext* ctx) throw() ;
	String* getAcceptCharset(ThreadContext* ctx) throw() ;
	void setAcceptCharset(String* acceptCharset, ThreadContext* ctx) throw() ;
	String* getKeepAlive(ThreadContext* ctx) throw() ;
	void setKeepAlive(String* keepAlive, ThreadContext* ctx) throw() ;
	String* getConnection(ThreadContext* ctx) throw() ;
	void setConnection(String* connection, ThreadContext* ctx) throw() ;
	String* getCookie(ThreadContext* ctx) throw() ;
	void setCookie(String* cookie, ThreadContext* ctx) throw() ;
private:
	void dowrite(StringBuffer* writer, String* key, String* value, ThreadContext* ctx);
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}}

#endif /* end of ALINOUS_HTTP_CLIENT_HTTPREQUESTHEADERS_H_ */
