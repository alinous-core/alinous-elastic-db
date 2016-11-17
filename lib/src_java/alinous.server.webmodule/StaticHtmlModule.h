#ifndef ALINOUS_SERVER_WEBMODULE_STATICHTMLMODULE_H_
#define ALINOUS_SERVER_WEBMODULE_STATICHTMLMODULE_H_
namespace alinous {namespace web {namespace htmlxml {namespace module {
class AlinousWebHtmlXmlModule;}}}}

namespace alinous {namespace server {namespace http {
class IContentByteStream;}}}

namespace alinous {namespace server {namespace http {
class HttpHeaderProcessor;}}}

namespace alinous {namespace server {namespace webmodule {
class StaticHtmlModuleStream;}}}

namespace alinous {namespace system {
class AlinousCore;}}

namespace alinous {namespace server {namespace webmodule {
class AbstractWebModule;}}}

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
using ::alinous::web::htmlxml::module::AlinousWebHtmlXmlModule;



class StaticHtmlModule final : public AbstractWebModule {
public:
	StaticHtmlModule(const StaticHtmlModule& base) = default;
public:
	StaticHtmlModule(AlinousWebHtmlXmlModule* htmlModule, String* path, ThreadContext* ctx) throw() ;
	void __construct_impl(AlinousWebHtmlXmlModule* htmlModule, String* path, ThreadContext* ctx) throw() ;
	virtual ~StaticHtmlModule() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	AlinousWebHtmlXmlModule* htmlModule;
public:
	IContentByteStream* getContentStream(HttpHeaderProcessor* httpRequest, ThreadContext* ctx) throw()  final;
	void prepare(AlinousCore* core, ThreadContext* ctx) throw()  final;
	bool isDirty(ThreadContext* ctx) throw()  final;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}}

#endif /* end of ALINOUS_SERVER_WEBMODULE_STATICHTMLMODULE_H_ */
