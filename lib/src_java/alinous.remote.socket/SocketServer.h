#ifndef ALINOUS_REMOTE_SOCKET_SOCKETSERVER_H_
#define ALINOUS_REMOTE_SOCKET_SOCKETSERVER_H_
namespace alinous{namespace annotation{
class GcZone;
}}
namespace alinous {namespace system {
class ISystemLog;}}

namespace alinous {namespace remote {namespace socket {
class SocketActionFactory;}}}

namespace alinous {namespace runtime {namespace parallel {
class ThreadPool;}}}

namespace java {namespace lang {
class Thread;}}

namespace java {namespace lang {
class InterruptedException;}}

namespace alinous {namespace net {
class AlinousServerSocket;}}

namespace java {namespace lang {
class Throwable;}}

namespace java {namespace net {
class Socket;}}

namespace alinous {namespace runtime {namespace parallel {
class AlinousThread;}}}

namespace alinous {namespace runtime {namespace parallel {
class IThreadAction;}}}

namespace java {namespace io {
class IOException;}}

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

namespace alinous {namespace remote {namespace socket {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::java::io::IOException;
using ::java::net::Socket;
using ::alinous::lock::LockObject;
using ::alinous::net::AlinousServerSocket;
using ::alinous::runtime::parallel::AlinousThread;
using ::alinous::runtime::parallel::IThreadAction;
using ::alinous::runtime::parallel::ThreadPool;
using ::alinous::system::ISystemLog;



class SocketServer final : public Runnable, public virtual IObject {
public:
	SocketServer(const SocketServer& base) = default;
public:
	SocketServer(int port, ISystemLog* logger, SocketActionFactory* factory, ThreadContext* ctx) throw() ;
	void __construct_impl(int port, ISystemLog* logger, SocketActionFactory* factory, ThreadContext* ctx) throw() ;
	virtual ~SocketServer() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	int port;
	AlinousServerSocket* serverSocket;
	ThreadPool* threadPool;
	Thread* thread;
	bool running;
	ISystemLog* logger;
	SocketActionFactory* factory;
	LockObject* refLock;
	int refs;
public:
	void start(int maxthread, String* threadName, ThreadContext* ctx) throw() ;
	void dispose(ThreadContext* ctx) throw() ;
	void run(ThreadContext* ctx) throw() ;
	void dec(ThreadContext* ctx) throw() ;
	int getRefs(ThreadContext* ctx) throw() ;
private:
	void handleRequest(ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}}

#endif /* end of ALINOUS_REMOTE_SOCKET_SOCKETSERVER_H_ */
