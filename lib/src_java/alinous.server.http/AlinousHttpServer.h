#ifndef ALINOUS_SERVER_HTTP_ALINOUSHTTPSERVER_H_
#define ALINOUS_SERVER_HTTP_ALINOUSHTTPSERVER_H_
namespace alinous{namespace annotation{
class GcZone;
}}
namespace alinous {namespace system {
class AlinousCore;}}

namespace alinous {namespace server {
class AlinousWebContentProcessor;}}

namespace alinous {namespace runtime {namespace parallel {
class ThreadPool;}}}

namespace java {namespace lang {
class Thread;}}

namespace java {namespace lang {
class InterruptedException;}}

namespace alinous {namespace http {namespace client {
class HttpClient;}}}

namespace alinous {namespace http {namespace client {
class HttpRequestHeaders;}}}

namespace alinous {namespace net {
class UnknownHostException;}}

namespace java {namespace io {
class IOException;}}

namespace alinous {namespace system {
class AlinousException;}}

namespace alinous {namespace net {
class AlinousServerSocket;}}

namespace java {namespace lang {
class Throwable;}}

namespace java {namespace net {
class Socket;}}

namespace alinous {namespace runtime {namespace parallel {
class AlinousThread;}}}

namespace alinous {namespace server {namespace http {
class ProcessRequestAction;}}}

namespace alinous {namespace lock {
class LockObject;}}

namespace java {namespace lang {
class Runnable;}}

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
using ::java::io::IOException;
using ::java::net::Socket;
using ::alinous::http::client::HttpClient;
using ::alinous::http::client::HttpRequestHeaders;
using ::alinous::lock::LockObject;
using ::alinous::net::AlinousServerSocket;
using ::alinous::net::UnknownHostException;
using ::alinous::runtime::parallel::AlinousThread;
using ::alinous::runtime::parallel::ThreadPool;
using ::alinous::server::AlinousWebContentProcessor;
using ::alinous::system::AlinousCore;
using ::alinous::system::AlinousException;



class AlinousHttpServer final : public Runnable, public virtual IObject {
public:
	AlinousHttpServer(const AlinousHttpServer& base) = default;
public:
	AlinousHttpServer(int port, AlinousCore* core, int maxThread, ThreadContext* ctx) throw() ;
	void __construct_impl(int port, AlinousCore* core, int maxThread, ThreadContext* ctx) throw() ;
	virtual ~AlinousHttpServer() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	AlinousCore* core;
	int port;
	AlinousServerSocket* serverSocket;
	ThreadPool* threadPool;
	Thread* thread;
	bool running;
	AlinousWebContentProcessor* webProccessor;
	LockObject* refLock;
	int refs;
public:
	void startServer(ThreadContext* ctx) throw() ;
	void stopServer(ThreadContext* ctx) throw() ;
	void run(ThreadContext* ctx) throw() ;
	void dec(ThreadContext* ctx) throw() ;
private:
	void handleRequest(ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx);
};

}}}

#endif /* end of ALINOUS_SERVER_HTTP_ALINOUSHTTPSERVER_H_ */
