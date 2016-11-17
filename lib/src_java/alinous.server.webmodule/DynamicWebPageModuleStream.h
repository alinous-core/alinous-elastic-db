#ifndef ALINOUS_SERVER_WEBMODULE_DYNAMICWEBPAGEMODULESTREAM_H_
#define ALINOUS_SERVER_WEBMODULE_DYNAMICWEBPAGEMODULESTREAM_H_
namespace alinous {namespace server {namespace http {
class HttpHeaderProcessor;}}}

namespace alinous {namespace web {namespace htmlxml {namespace module {
class AlinousWebHtmlXmlModule;}}}}

namespace alinous {namespace runtime {
class AlinousModule;}}

namespace java {namespace io {
class OutputStream;}}

namespace alinous {namespace system {
class AlinousCore;}}

namespace alinous {namespace runtime {namespace engine {
class ScriptMachine;}}}

namespace java {namespace util {
template <typename  T, typename V> class HashMap;}}

namespace alinous {namespace server {namespace http {namespace params {
class AbstractHttpParameter;}}}}

namespace alinous {namespace runtime {namespace dom {
class IAlinousVariable;}}}

namespace java {namespace io {
class StringWriter;}}

namespace alinous {namespace server {namespace http {
class IContentByteStream;}}}

namespace java {namespace io {
class IOException;}}

namespace alinous {namespace db {namespace table {
class DatabaseException;}}}

namespace alinous {namespace system {
class AlinousException;}}

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
using ::java::io::IOException;
using ::java::io::OutputStream;
using ::java::io::StringWriter;
using ::java::util::HashMap;
using ::alinous::db::table::DatabaseException;
using ::alinous::runtime::AlinousModule;
using ::alinous::runtime::dom::IAlinousVariable;
using ::alinous::runtime::engine::ScriptMachine;
using ::alinous::server::http::HttpHeaderProcessor;
using ::alinous::server::http::IContentByteStream;
using ::alinous::server::http::params::AbstractHttpParameter;
using ::alinous::system::AlinousCore;
using ::alinous::system::AlinousException;
using ::alinous::web::htmlxml::module::AlinousWebHtmlXmlModule;



class DynamicWebPageModuleStream final : public IContentByteStream, public virtual IObject {
public:
	DynamicWebPageModuleStream(const DynamicWebPageModuleStream& base) = default;
public:
	DynamicWebPageModuleStream(HttpHeaderProcessor* httpRequest, AlinousWebHtmlXmlModule* htmlModule, AlinousModule* alnsModule, ThreadContext* ctx) throw() ;
	void __construct_impl(HttpHeaderProcessor* httpRequest, AlinousWebHtmlXmlModule* htmlModule, AlinousModule* alnsModule, ThreadContext* ctx) throw() ;
	virtual ~DynamicWebPageModuleStream() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	AlinousModule* alnsModule;
	AlinousWebHtmlXmlModule* htmlModule;
	HttpHeaderProcessor* httpRequest;
	IArrayObjectPrimitive<char>* outString;
public:
	int length(ThreadContext* ctx) throw()  final;
	void output(OutputStream* outStream, ThreadContext* ctx) final;
	void prepare(AlinousCore* core, bool debug, ThreadContext* ctx) final;
	String* getContentType(ThreadContext* ctx) throw()  final;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}}

#endif /* end of ALINOUS_SERVER_WEBMODULE_DYNAMICWEBPAGEMODULESTREAM_H_ */
