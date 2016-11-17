#ifndef ALINOUS_SERVER_HTTP_PARAMS_HTTPPARAMETER_H_
#define ALINOUS_SERVER_HTTP_PARAMS_HTTPPARAMETER_H_
namespace alinous {namespace server {namespace http {namespace params {
class AbstractHttpParameter;}}}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace server {namespace http {namespace params {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;



class HttpParameter final : public AbstractHttpParameter {
public:
	HttpParameter(const HttpParameter& base) = default;
public:
	HttpParameter(String* name, String* value, ThreadContext* ctx) throw() ;
	void __construct_impl(String* name, String* value, ThreadContext* ctx) throw() ;
	virtual ~HttpParameter() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
public:
	String* name;
	String* value;
public:
	String* getName(ThreadContext* ctx) throw()  final;
	String* getStringValue(ThreadContext* ctx) throw()  final;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}}}

#endif /* end of ALINOUS_SERVER_HTTP_PARAMS_HTTPPARAMETER_H_ */
