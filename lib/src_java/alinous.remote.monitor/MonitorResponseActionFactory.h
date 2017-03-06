#ifndef ALINOUS_REMOTE_MONITOR_MONITORRESPONSEACTIONFACTORY_H_
#define ALINOUS_REMOTE_MONITOR_MONITORRESPONSEACTIONFACTORY_H_
namespace alinous {namespace remote {namespace monitor {
class TransactionMonitorServer;}}}

namespace alinous {namespace runtime {namespace parallel {
class IThreadAction;}}}

namespace java {namespace net {
class Socket;}}

namespace alinous {namespace remote {namespace socket {
class SocketServer;}}}

namespace alinous {namespace remote {namespace monitor {
class MonitorResponceAction;}}}

namespace alinous {namespace remote {namespace socket {
class ISocketActionFactory;}}}

namespace java {namespace lang {
class IObject;
}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace remote {namespace monitor {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::java::net::Socket;
using ::alinous::remote::socket::ISocketActionFactory;
using ::alinous::remote::socket::SocketServer;
using ::alinous::runtime::parallel::IThreadAction;



class MonitorResponseActionFactory final : public ISocketActionFactory, public virtual IObject {
public:
	MonitorResponseActionFactory(const MonitorResponseActionFactory& base) = default;
public:
	MonitorResponseActionFactory(TransactionMonitorServer* monitorServer, ThreadContext* ctx) throw() ;
	void __construct_impl(TransactionMonitorServer* monitorServer, ThreadContext* ctx) throw() ;
	virtual ~MonitorResponseActionFactory() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	TransactionMonitorServer* monitorServer;
public:
	IThreadAction* getAction(Socket* socket, SocketServer* server, ThreadContext* ctx) throw()  final;
	TransactionMonitorServer* getMonitorServer(ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx);
};

}}}

#endif /* end of ALINOUS_REMOTE_MONITOR_MONITORRESPONSEACTIONFACTORY_H_ */
