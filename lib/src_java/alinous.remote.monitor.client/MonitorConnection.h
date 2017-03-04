#ifndef ALINOUS_REMOTE_MONITOR_CLIENT_MONITORCONNECTION_H_
#define ALINOUS_REMOTE_MONITOR_CLIENT_MONITORCONNECTION_H_
namespace java{namespace net{
class UnknownHostException;
}}
namespace alinous {namespace remote {namespace socket {
class SocketConnectionPool;}}}

namespace alinous {namespace remote {namespace monitor {namespace client {
class MonitorConnectionInfo;}}}}

namespace alinous {namespace net {
class AlinousSocket;}}

namespace alinous {namespace remote {namespace monitor {namespace command {
class MonitorConnectCommand;}}}}

namespace alinous {namespace remote {namespace monitor {namespace command {
class AbstractMonitorCommand;}}}}

namespace alinous {namespace db {
class AlinousDbException;}}

namespace java {namespace io {
class IOException;}}

namespace alinous {namespace remote {namespace monitor {namespace command {
class FinishConnectionCommand;}}}}

namespace alinous {namespace system {
class AlinousException;}}

namespace alinous {namespace remote {namespace socket {
class ISocketConnection;}}}

namespace java {namespace lang {
class IObject;
}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace remote {namespace monitor {namespace client {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::java::io::IOException;
using ::java::net::UnknownHostException;
using ::alinous::db::AlinousDbException;
using ::alinous::net::AlinousSocket;
using ::alinous::remote::monitor::command::AbstractMonitorCommand;
using ::alinous::remote::monitor::command::FinishConnectionCommand;
using ::alinous::remote::monitor::command::MonitorConnectCommand;
using ::alinous::remote::socket::ISocketConnection;
using ::alinous::remote::socket::SocketConnectionPool;
using ::alinous::system::AlinousException;



class MonitorConnection final : public ISocketConnection, public virtual IObject {
public:
	MonitorConnection(const MonitorConnection& base) = default;
public:
	MonitorConnection(SocketConnectionPool* pool, MonitorConnectionInfo* info, ThreadContext* ctx) throw() ;
	void __construct_impl(SocketConnectionPool* pool, MonitorConnectionInfo* info, ThreadContext* ctx) throw() ;
	virtual ~MonitorConnection() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	SocketConnectionPool* pool;
	MonitorConnectionInfo* info;
	AlinousSocket* socket;
public:
	void connect(ThreadContext* ctx) final;
	AlinousSocket* getSocket(ThreadContext* ctx) throw()  final;
	void close(ThreadContext* ctx) throw()  final;
	void dispose(ThreadContext* ctx) throw()  final;
	void shutdown(ThreadContext* ctx) throw()  final;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}}}

#endif /* end of ALINOUS_REMOTE_MONITOR_CLIENT_MONITORCONNECTION_H_ */
