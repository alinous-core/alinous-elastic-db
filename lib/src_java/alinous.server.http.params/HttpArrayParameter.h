#ifndef ALINOUS_SERVER_HTTP_PARAMS_HTTPARRAYPARAMETER_H_
#define ALINOUS_SERVER_HTTP_PARAMS_HTTPARRAYPARAMETER_H_
namespace alinous {namespace server {namespace http {namespace params {
class AbstractHttpParameter;}}}}

namespace alinous {namespace server {namespace http {namespace params {
class HttpArrayParameter;}}}}

namespace java {namespace lang {
class StringBuffer;}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace server {namespace http {namespace params {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::java::util::ArrayList;



class HttpArrayParameter final : public AbstractHttpParameter {
public:
	HttpArrayParameter(const HttpArrayParameter& base) = default;
public:
	HttpArrayParameter(String* name, ArrayList<String>* values, ThreadContext* ctx) throw() ;
	void __construct_impl(String* name, ArrayList<String>* values, ThreadContext* ctx) throw() ;
	virtual ~HttpArrayParameter() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
public:
	String* name;
	ArrayList<String>* values;
public:
	void addValues(String* value, ThreadContext* ctx) throw() ;
	void addParam(AbstractHttpParameter* newParam, ThreadContext* ctx) throw() ;
	String* getName(ThreadContext* ctx) throw()  final;
	String* getStringValue(ThreadContext* ctx) throw()  final;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx);
};

}}}}

#endif /* end of ALINOUS_SERVER_HTTP_PARAMS_HTTPARRAYPARAMETER_H_ */
