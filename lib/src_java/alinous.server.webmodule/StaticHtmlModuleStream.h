#ifndef ALINOUS_SERVER_WEBMODULE_STATICHTMLMODULESTREAM_H_
#define ALINOUS_SERVER_WEBMODULE_STATICHTMLMODULESTREAM_H_
namespace alinous {namespace server {namespace http {
class HttpHeaderProcessor;}}}

namespace alinous {namespace web {namespace htmlxml {namespace module {
class AlinousWebHtmlXmlModule;}}}}

namespace java {namespace io {
class UnsupportedEncodingException;}}

namespace java {namespace io {
class OutputStream;}}

namespace alinous {namespace system {
class AlinousCore;}}

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
using ::java::io::UnsupportedEncodingException;
using ::alinous::db::table::DatabaseException;
using ::alinous::server::http::HttpHeaderProcessor;
using ::alinous::server::http::IContentByteStream;
using ::alinous::system::AlinousCore;
using ::alinous::system::AlinousException;
using ::alinous::web::htmlxml::module::AlinousWebHtmlXmlModule;



class StaticHtmlModuleStream final : public IContentByteStream, public virtual IObject {
public:
	StaticHtmlModuleStream(const StaticHtmlModuleStream& base) = default;
public:
	StaticHtmlModuleStream(HttpHeaderProcessor* httpRequest, AlinousWebHtmlXmlModule* htmlModule, ThreadContext* ctx) throw() ;
	void __construct_impl(HttpHeaderProcessor* httpRequest, AlinousWebHtmlXmlModule* htmlModule, ThreadContext* ctx) throw() ;
	virtual ~StaticHtmlModuleStream() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	AlinousWebHtmlXmlModule* htmlModule;
	IArrayObjectPrimitive<char>* buff;
public:
	int length(ThreadContext* ctx) throw()  final;
	void output(OutputStream* outStream, ThreadContext* ctx) final;
	void prepare(AlinousCore* core, bool debug, ThreadContext* ctx) final;
	String* getContentType(ThreadContext* ctx) throw()  final;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx);
};

}}}

#endif /* end of ALINOUS_SERVER_WEBMODULE_STATICHTMLMODULESTREAM_H_ */
