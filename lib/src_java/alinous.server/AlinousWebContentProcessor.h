#ifndef ALINOUS_SERVER_ALINOUSWEBCONTENTPROCESSOR_H_
#define ALINOUS_SERVER_ALINOUSWEBCONTENTPROCESSOR_H_
namespace alinous {namespace system {
class AlinousCore;}}

namespace alinous {namespace server {
class MimeResolver;}}

namespace alinous {namespace server {
class ContentResult;}}

namespace alinous {namespace server {namespace http {
class HttpHeaderProcessor;}}}

namespace java {namespace io {
class UnsupportedEncodingException;}}

namespace alinous {namespace server {
class BinaryContentByteStream;}}

namespace alinous {namespace server {namespace webmodule {
class AbstractWebModule;}}}

namespace alinous {namespace server {namespace webmodule {
class WebModuleManager;}}}

namespace alinous {namespace db {namespace table {
class DatabaseException;}}}

namespace alinous {namespace server {namespace debug {
class DebugProcessor;}}}

namespace alinous {namespace system {
class AlinousException;}}

namespace java {namespace lang {
class IObject;
}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace server {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::java::io::UnsupportedEncodingException;
using ::alinous::db::table::DatabaseException;
using ::alinous::server::debug::DebugProcessor;
using ::alinous::server::http::HttpHeaderProcessor;
using ::alinous::server::webmodule::AbstractWebModule;
using ::alinous::server::webmodule::WebModuleManager;
using ::alinous::system::AlinousCore;
using ::alinous::system::AlinousException;



class AlinousWebContentProcessor final : public virtual IObject {
public:
	AlinousWebContentProcessor(const AlinousWebContentProcessor& base) = default;
public:
	AlinousWebContentProcessor(AlinousCore* core, ThreadContext* ctx) throw() ;
	void __construct_impl(AlinousCore* core, ThreadContext* ctx) throw() ;
	virtual ~AlinousWebContentProcessor() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	AlinousCore* core;
	WebModuleManager* webModuleManager;
	MimeResolver* mimeResolver;
public:
	static String* PING_TO_SERVER;
	static String* PING_RETURN;
	static String* DEBUG_CMD_ACCESS;
	static String* HEAD_METHOD;
public:
	AlinousCore* getCore(ThreadContext* ctx) throw() ;
	ContentResult* proccess(HttpHeaderProcessor* request, ThreadContext* ctx);
private:
	String* getExt(String* path, ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx);
};

}}

#endif /* end of ALINOUS_SERVER_ALINOUSWEBCONTENTPROCESSOR_H_ */
