#ifndef ALINOUS_SERVER_HTTP_PARAMS_HTTPUPLOADPARAMETER_H_
#define ALINOUS_SERVER_HTTP_PARAMS_HTTPUPLOADPARAMETER_H_
namespace alinous {namespace server {namespace http {namespace params {
class AbstractHttpParameter;}}}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace server {namespace http {namespace params {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;



class HttpUploadParameter final : public AbstractHttpParameter {
public:
	HttpUploadParameter(const HttpUploadParameter& base) = default;
public:
	HttpUploadParameter(String* name, ThreadContext* ctx) throw() ;
	void __construct_impl(String* name, ThreadContext* ctx) throw() ;
	virtual ~HttpUploadParameter() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	String* name;
public:
	String* getName(ThreadContext* ctx) throw()  final;
	String* getStringValue(ThreadContext* ctx) throw()  final;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx);
};

}}}}

#endif /* end of ALINOUS_SERVER_HTTP_PARAMS_HTTPUPLOADPARAMETER_H_ */
