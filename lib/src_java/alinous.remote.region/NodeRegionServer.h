#ifndef ALINOUS_REMOTE_REGION_NODEREGIONSERVER_H_
#define ALINOUS_REMOTE_REGION_NODEREGIONSERVER_H_
namespace alinous {namespace remote {namespace region {
class NodeReferenceManager;}}}

namespace alinous {namespace system {namespace config {namespace remote {
class RegionsServer;}}}}

namespace alinous {namespace system {namespace config {namespace remote {
class MonitorRef;}}}}

namespace alinous {namespace remote {namespace monitor {namespace command {
class GetRegionNodeInfoCommand;}}}}

namespace alinous {namespace remote {namespace socket {
class ISocketConnection;}}}

namespace alinous {namespace net {
class AlinousSocket;}}

namespace alinous {namespace remote {namespace monitor {namespace client {
class MonitorConnectionInfo;}}}}

namespace alinous {namespace remote {namespace monitor {namespace client {
class MonitorClientConnectionFactory;}}}}

namespace alinous {namespace remote {namespace socket {
class SocketConnectionPool;}}}

namespace alinous {namespace system {
class ISystemLog;}}

namespace alinous {namespace remote {namespace region {
class NodeRegionResponceActionFactory;}}}

namespace alinous {namespace remote {namespace socket {
class SocketServer;}}}

namespace java {namespace io {
class IOException;}}

namespace alinous {namespace net {
class UnknownHostException;}}

namespace alinous {namespace system {
class AlinousException;}}

namespace java {namespace lang {
class IObject;
}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace remote {namespace region {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::java::io::IOException;
using ::java::net::UnknownHostException;
using ::alinous::net::AlinousSocket;
using ::alinous::remote::monitor::client::MonitorClientConnectionFactory;
using ::alinous::remote::monitor::client::MonitorConnectionInfo;
using ::alinous::remote::monitor::command::GetRegionNodeInfoCommand;
using ::alinous::remote::socket::ISocketConnection;
using ::alinous::remote::socket::SocketConnectionPool;
using ::alinous::remote::socket::SocketServer;
using ::alinous::system::AlinousException;
using ::alinous::system::ISystemLog;
using ::alinous::system::config::remote::MonitorRef;
using ::alinous::system::config::remote::RegionsServer;



class NodeRegionServer final : public virtual IObject {
public:
	NodeRegionServer(const NodeRegionServer& base) = default;
public:
	NodeRegionServer(int port, int maxthread, ThreadContext* ctx) throw() ;
	void __construct_impl(int port, int maxthread, ThreadContext* ctx) throw() ;
	virtual ~NodeRegionServer() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	int port;
	int maxthread;
	NodeReferenceManager* refs;
	SocketServer* socketServer;
	SocketConnectionPool* monitorConnectionPool;
private:
	static String* THREAD_NAME;
public:
	void initNodes(RegionsServer* srvconf, ThreadContext* ctx);
	void syncNodes(ThreadContext* ctx);
	void start(ISystemLog* logger, ThreadContext* ctx) throw() ;
	void dispose(ThreadContext* ctx) throw() ;
	NodeReferenceManager* getRefs(ThreadContext* ctx) throw() ;
private:
	void initMonitorRef(MonitorRef* monRef, ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}}

#endif /* end of ALINOUS_REMOTE_REGION_NODEREGIONSERVER_H_ */
