#ifndef ALINOUS_SERVER_WEBMODULE_DIRECTMODULE_H_
#define ALINOUS_SERVER_WEBMODULE_DIRECTMODULE_H_
namespace alinous {namespace runtime {
class AlinousModule;}}

namespace alinous {namespace server {namespace http {
class IContentByteStream;}}}

namespace alinous {namespace server {namespace http {
class HttpHeaderProcessor;}}}

namespace alinous {namespace server {namespace webmodule {
class DirectModuleStream;}}}

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
using ::alinous::runtime::AlinousModule;
using ::alinous::server::http::HttpHeaderProcessor;
using ::alinous::server::http::IContentByteStream;
using ::alinous::system::AlinousCore;



class DirectModule final : public AbstractWebModule {
public:
	DirectModule(const DirectModule& base) = default;
public:
	DirectModule(AlinousModule* alnsModule, String* path, ThreadContext* ctx) throw() ;
	void __construct_impl(AlinousModule* alnsModule, String* path, ThreadContext* ctx) throw() ;
	virtual ~DirectModule() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	AlinousModule* alnsModule;
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

#endif /* end of ALINOUS_SERVER_WEBMODULE_DIRECTMODULE_H_ */
