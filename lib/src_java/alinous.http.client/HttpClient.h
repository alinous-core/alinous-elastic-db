#ifndef ALINOUS_HTTP_CLIENT_HTTPCLIENT_H_
#define ALINOUS_HTTP_CLIENT_HTTPCLIENT_H_
namespace alinous {namespace net {
class AlinousSocket;}}

namespace alinous {namespace http {namespace client {
class HttpRequestHeaders;}}}

namespace java {namespace io {
class OutputStream;}}

namespace java {namespace io {
class OutputStreamWriter;}}

namespace java {namespace lang {
class StringBuffer;}}

namespace java {namespace io {
class InputStream;}}

namespace java {namespace io {
class ByteArrayOutputStream;}}

namespace alinous {namespace system {
class AlinousException;}}

namespace java {namespace lang {
class NumberFormatException;}}

namespace java {namespace io {
class IOException;}}

namespace java {namespace util {
template <typename  T, typename V> class HashMap;}}

namespace alinous {namespace net {
class UnknownHostException;}}

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
using ::java::io::ByteArrayOutputStream;
using ::java::io::IOException;
using ::java::io::InputStream;
using ::java::io::OutputStream;
using ::java::io::OutputStreamWriter;
using ::java::util::HashMap;
using ::alinous::net::AlinousSocket;
using ::alinous::net::UnknownHostException;
using ::alinous::system::AlinousException;



class HttpClient : public virtual IObject {
public:
	HttpClient(const HttpClient& base) = default;
public:
	HttpClient(ThreadContext* ctx) throw() ;
	void __construct_impl(ThreadContext* ctx) throw() ;
	virtual ~HttpClient() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
public:
	AlinousSocket* socket;
	HashMap<String,String>* responseHeader;
	int chunkSize;
	IArrayObjectPrimitive<char>* buf;
	ByteArrayOutputStream* resultStream;
public:
	void get(String* host, int port, String* path, HttpRequestHeaders* headers, ThreadContext* ctx);
	void dispose(ThreadContext* ctx) throw() ;
	HashMap<String,String>* getResponseHeader(ThreadContext* ctx) throw() ;
	ByteArrayOutputStream* getResultStream(ThreadContext* ctx) throw() ;
	virtual void connect(String* host, int port, ThreadContext* ctx);
	void readByContentLength(String* contentLength, InputStream* inStream, ThreadContext* ctx);
	void readChunkedContent(InputStream* inStream, ThreadContext* ctx);
	void readWhileChunkSize(InputStream* inStream, ThreadContext* ctx);
	void parseHeader(InputStream* inStream, ThreadContext* ctx);
	void analyseHeaderLine(String* line, ThreadContext* ctx);
private:
	String* readLine(InputStream* inStream, ThreadContext* ctx);
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}}

#endif /* end of ALINOUS_HTTP_CLIENT_HTTPCLIENT_H_ */
