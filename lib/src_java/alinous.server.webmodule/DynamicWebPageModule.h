#ifndef ALINOUS_SERVER_WEBMODULE_DYNAMICWEBPAGEMODULE_H_
#define ALINOUS_SERVER_WEBMODULE_DYNAMICWEBPAGEMODULE_H_
namespace alinous {namespace web {namespace htmlxml {namespace module {
class AlinousWebHtmlXmlModule;}}}}

namespace alinous {namespace runtime {
class AlinousModule;}}

namespace alinous {namespace server {namespace http {
class IContentByteStream;}}}

namespace alinous {namespace server {namespace http {
class HttpHeaderProcessor;}}}

namespace alinous {namespace server {namespace webmodule {
class DynamicWebPageModuleStream;}}}

namespace alinous {namespace system {
class AlinousCore;}}

namespace alinous {namespace compile {namespace analyse {
class SrcAnalyseContext;}}}

namespace java {namespace lang {
class Throwable;}}

namespace alinous {namespace server {namespace webmodule {
class AbstractWebModule;}}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace server {namespace webmodule {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::alinous::compile::analyse::SrcAnalyseContext;
using ::alinous::runtime::AlinousModule;
using ::alinous::server::http::HttpHeaderProcessor;
using ::alinous::server::http::IContentByteStream;
using ::alinous::system::AlinousCore;
using ::alinous::web::htmlxml::module::AlinousWebHtmlXmlModule;



class DynamicWebPageModule final : public AbstractWebModule {
public:
	DynamicWebPageModule(const DynamicWebPageModule& base) = default;
public:
	DynamicWebPageModule(AlinousWebHtmlXmlModule* htmlModule, AlinousModule* alnsModule, String* path, ThreadContext* ctx) throw() ;
	void __construct_impl(AlinousWebHtmlXmlModule* htmlModule, AlinousModule* alnsModule, String* path, ThreadContext* ctx) throw() ;
	virtual ~DynamicWebPageModule() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	AlinousWebHtmlXmlModule* htmlModule;
	AlinousModule* alnsModule;
public:
	IContentByteStream* getContentStream(HttpHeaderProcessor* httpRequest, ThreadContext* ctx) throw()  final;
	void prepare(AlinousCore* core, ThreadContext* ctx) throw()  final;
	bool isDirty(ThreadContext* ctx) throw()  final;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx);
};

}}}

#endif /* end of ALINOUS_SERVER_WEBMODULE_DYNAMICWEBPAGEMODULE_H_ */
