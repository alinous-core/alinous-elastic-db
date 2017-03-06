#ifndef ALINOUS_SERVER_HTTP_POSTURLENCODEDREADER_H_
#define ALINOUS_SERVER_HTTP_POSTURLENCODEDREADER_H_
namespace java {namespace io {
class InputStream;}}

namespace java {namespace util {
template <typename  T, typename V> class HashMap;}}

namespace alinous {namespace server {namespace http {namespace params {
class AbstractHttpParameter;}}}}

namespace alinous {namespace server {namespace http {namespace params {
class HttpArrayParameter;}}}}

namespace java {namespace io {
class IOException;}}

namespace java {namespace io {
class UnsupportedEncodingException;}}

namespace alinous {namespace server {namespace http {namespace params {
class ParamFactory;}}}}

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
using ::java::util::ArrayList;
using ::java::util::HashMap;
using ::alinous::server::http::params::AbstractHttpParameter;
using ::alinous::server::http::params::HttpArrayParameter;
using ::alinous::server::http::params::ParamFactory;



class PostUrlEncodedReader final : public virtual IObject {
public:
	PostUrlEncodedReader(const PostUrlEncodedReader& base) = default;
public:
	PostUrlEncodedReader(InputStream* inStream, int contentLength, ThreadContext* ctx) throw() ;
	void __construct_impl(InputStream* inStream, int contentLength, ThreadContext* ctx) throw() ;
	virtual ~PostUrlEncodedReader() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	InputStream* inStream;
	int contentLength;
public:
	HashMap<String,AbstractHttpParameter>* parse(String* encode, ThreadContext* ctx);
public:
	static HashMap<String,AbstractHttpParameter>* parseString(String* content, String* encode, ThreadContext* ctx);
private:
	static void putParam(HashMap<String,AbstractHttpParameter>* params, AbstractHttpParameter* p, ThreadContext* ctx) throw() ;
	static ArrayList<String>* split(String* content, String* ch, ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx);
};

}}}

#endif /* end of ALINOUS_SERVER_HTTP_POSTURLENCODEDREADER_H_ */
