#ifndef ALINOUS_SERVER_HTTP_PARAMS_PARAMFACTORY_H_
#define ALINOUS_SERVER_HTTP_PARAMS_PARAMFACTORY_H_
namespace alinous {namespace server {namespace http {namespace params {
class AbstractHttpParameter;}}}}

namespace alinous {namespace server {namespace http {namespace params {
class HttpArrayParameter;}}}}

namespace alinous {namespace server {namespace http {namespace params {
class HttpParameter;}}}}

namespace java {namespace io {
class UnsupportedEncodingException;}}

namespace alinous {namespace net {
class URLDecoder;}}

namespace java {namespace lang {
class IObject;
}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace server {namespace http {namespace params {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::java::io::UnsupportedEncodingException;
using ::java::util::ArrayList;
using ::alinous::net::URLDecoder;



class ParamFactory final : public virtual IObject {
public:
	ParamFactory(const ParamFactory& base) = default;
public:
	ParamFactory(ThreadContext* ctx) throw() ;
	void __construct_impl(ThreadContext* ctx) throw() ;
	virtual ~ParamFactory() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
public:
	static AbstractHttpParameter* getParam(String* enckey, String* encvalue, String* encode, ThreadContext* ctx);
private:
	static ArrayList<String>* split(String* content, String* ch, String* encode, ThreadContext* ctx);
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx);
};

}}}}

#endif /* end of ALINOUS_SERVER_HTTP_PARAMS_PARAMFACTORY_H_ */
