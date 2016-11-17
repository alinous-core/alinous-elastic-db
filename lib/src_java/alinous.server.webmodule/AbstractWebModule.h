#ifndef ALINOUS_SERVER_WEBMODULE_ABSTRACTWEBMODULE_H_
#define ALINOUS_SERVER_WEBMODULE_ABSTRACTWEBMODULE_H_
namespace alinous {namespace server {namespace http {
class IContentByteStream;}}}

namespace alinous {namespace server {namespace http {
class HttpHeaderProcessor;}}}

namespace alinous {namespace system {
class AlinousCore;}}

namespace java {namespace lang {
class IObject;
}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace server {namespace webmodule {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::alinous::server::http::HttpHeaderProcessor;
using ::alinous::server::http::IContentByteStream;
using ::alinous::system::AlinousCore;



class AbstractWebModule : public virtual IObject {
public:
	AbstractWebModule(const AbstractWebModule& base) = default;
public:
	AbstractWebModule(long long timeStamp, ThreadContext* ctx) throw() ;
	void __construct_impl(long long timeStamp, ThreadContext* ctx) throw() ;
	virtual ~AbstractWebModule() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
public:
	int moduleType;
	String* path;
	long long timeStamp;
public:
	constexpr static const int DYNAMIC_MODULE{0};
	constexpr static const int BINARY_MODULE{1};
	constexpr static const int STATIC_HTML{2};
	constexpr static const int DIRECT_MODULE{3};
public:
	int getHashKey(ThreadContext* ctx) throw() ;
	virtual IContentByteStream* getContentStream(HttpHeaderProcessor* httpRequest, ThreadContext* ctx) throw()  = 0;
	virtual void prepare(AlinousCore* core, ThreadContext* ctx) throw()  = 0;
	virtual bool isDirty(ThreadContext* ctx) throw()  = 0;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}}

#endif /* end of ALINOUS_SERVER_WEBMODULE_ABSTRACTWEBMODULE_H_ */
