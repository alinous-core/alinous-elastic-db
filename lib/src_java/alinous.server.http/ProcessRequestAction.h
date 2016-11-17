#ifndef ALINOUS_SERVER_HTTP_PROCESSREQUESTACTION_H_
#define ALINOUS_SERVER_HTTP_PROCESSREQUESTACTION_H_
namespace alinous{namespace annotation{
class GcZone;
}}
namespace java {namespace net {
class Socket;}}

namespace alinous {namespace server {
class AlinousWebContentProcessor;}}

namespace alinous {namespace server {namespace http {
class AlinousHttpServer;}}}

namespace java {namespace io {
class InputStream;}}

namespace java {namespace io {
class BufferedInputStream;}}

namespace alinous {namespace server {namespace http {
class HttpHeaderProcessor;}}}

namespace java {namespace io {
class OutputStream;}}

namespace java {namespace io {
class BufferedOutputStream;}}

namespace alinous {namespace server {
class ContentResult;}}

namespace alinous {namespace system {
class AlinousCore;}}

namespace java {namespace lang {
class Throwable;}}

namespace alinous {namespace server {namespace http {
class IContentByteStream;}}}

namespace java {namespace lang {
class StringBuffer;}}

namespace alinous {namespace runtime {namespace parallel {
class IThreadAction;}}}

namespace java {namespace io {
class IOException;}}

namespace java {namespace lang {
class IObject;
}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace server {namespace http {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::java::io::BufferedInputStream;
using ::java::io::BufferedOutputStream;
using ::java::io::IOException;
using ::java::io::InputStream;
using ::java::io::OutputStream;
using ::java::net::Socket;
using ::alinous::runtime::parallel::IThreadAction;
using ::alinous::server::AlinousWebContentProcessor;
using ::alinous::server::ContentResult;
using ::alinous::system::AlinousCore;



class ProcessRequestAction final : public IThreadAction, public virtual IObject {
public:
	ProcessRequestAction(const ProcessRequestAction& base) = default;
public:
	ProcessRequestAction(Socket* socket, AlinousWebContentProcessor* webProcessor, AlinousHttpServer* server, ThreadContext* ctx) throw() ;
	void __construct_impl(Socket* socket, AlinousWebContentProcessor* webProcessor, AlinousHttpServer* server, ThreadContext* ctx) throw() ;
	virtual ~ProcessRequestAction() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	Socket* socket;
	HttpHeaderProcessor* header;
	AlinousWebContentProcessor* webProcessor;
	AlinousHttpServer* server;
public:
	static String* endStr;
public:
	void execute(ThreadContext* ctx) final;
private:
	void outCodeResult(ContentResult* result, OutputStream* outStream, ThreadContext* ctx);
	void outResponse(int contentLength, OutputStream* outStream, ThreadContext* ctx);
	void out404ResponceHeader(ContentResult* result, OutputStream* outStream, ThreadContext* ctx);
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}}

#endif /* end of ALINOUS_SERVER_HTTP_PROCESSREQUESTACTION_H_ */
