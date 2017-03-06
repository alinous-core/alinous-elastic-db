#ifndef ALINOUS_SERVER_HTTP_HTTPHEADERPROCESSOR_H_
#define ALINOUS_SERVER_HTTP_HTTPHEADERPROCESSOR_H_
namespace alinous{namespace annotation{
class GcZone;
}}
namespace java {namespace io {
class InputStream;}}

namespace alinous {namespace system {
class AlinousException;}}

namespace java {namespace lang {
class NumberFormatException;}}

namespace java {namespace lang {
class StringBuffer;}}

namespace java {namespace util {
template <typename  T, typename V> class HashMap;}}

namespace alinous {namespace server {namespace http {namespace params {
class AbstractHttpParameter;}}}}

namespace java {namespace io {
class IOException;}}

namespace java {namespace io {
class UnsupportedEncodingException;}}

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
using ::java::io::UnsupportedEncodingException;
using ::java::util::HashMap;
using ::alinous::server::http::params::AbstractHttpParameter;
using ::alinous::system::AlinousException;



class HttpHeaderProcessor final : public virtual IObject {
public:
	HttpHeaderProcessor(const HttpHeaderProcessor& base) = default;
public:
	HttpHeaderProcessor(InputStream* stream, ThreadContext* ctx) throw() ;
	void __construct_impl(InputStream* stream, ThreadContext* ctx) throw() ;
	virtual ~HttpHeaderProcessor() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
public:
	HashMap<String,AbstractHttpParameter>* params;
private:
	InputStream* stream;
	HashMap<String,String>* requestHeaders;
	String* protocol;
	String* path;
	String* method;
public:
	void process(ThreadContext* ctx);
	HashMap<String,String>* getRequestHeaders(ThreadContext* ctx) throw() ;
	String* getProtocol(ThreadContext* ctx) throw() ;
	String* getPath(ThreadContext* ctx) throw() ;
	String* getMethod(ThreadContext* ctx) throw() ;
private:
	void parseGetParams(ThreadContext* ctx);
	void parseFirstLine(String* line, ThreadContext* ctx);
	void parseLine(String* line, ThreadContext* ctx);
	String* readLine(InputStream* inStream, ThreadContext* ctx);
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx);
};

}}}

#endif /* end of ALINOUS_SERVER_HTTP_HTTPHEADERPROCESSOR_H_ */
