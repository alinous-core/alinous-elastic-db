#ifndef ALINOUS_SERVER_HTTP_PARAMS_ABSTRACTHTTPPARAMETER_H_
#define ALINOUS_SERVER_HTTP_PARAMS_ABSTRACTHTTPPARAMETER_H_
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



class AbstractHttpParameter : public virtual IObject {
public:
	AbstractHttpParameter(const AbstractHttpParameter& base) = default;
public:
	AbstractHttpParameter(ThreadContext* ctx) throw() ;
	void __construct_impl(ThreadContext* ctx) throw() ;
	virtual ~AbstractHttpParameter() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
public:
	int paramType;
public:
	constexpr static const int TYPE_NORMAL_PARAM{1};
	constexpr static const int TYPE_ARRAY_PARAM{2};
	constexpr static const int TYPE_FILE_PARAM{3};
public:
	virtual String* getName(ThreadContext* ctx) throw()  = 0;
	virtual String* getStringValue(ThreadContext* ctx) throw()  = 0;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx);
};

}}}}

#endif /* end of ALINOUS_SERVER_HTTP_PARAMS_ABSTRACTHTTPPARAMETER_H_ */
