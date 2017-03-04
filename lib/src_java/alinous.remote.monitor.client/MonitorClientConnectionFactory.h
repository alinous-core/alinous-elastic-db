#ifndef ALINOUS_REMOTE_MONITOR_CLIENT_MONITORCLIENTCONNECTIONFACTORY_H_
#define ALINOUS_REMOTE_MONITOR_CLIENT_MONITORCLIENTCONNECTIONFACTORY_H_
namespace java{namespace net{
class UnknownHostException;
}}
namespace alinous {namespace remote {namespace monitor {namespace client {
class MonitorConnectionInfo;}}}}

namespace alinous {namespace remote {namespace socket {
class ISocketConnection;}}}

namespace alinous {namespace remote {namespace socket {
class SocketConnectionPool;}}}

namespace alinous {namespace remote {namespace monitor {namespace client {
class MonitorConnection;}}}}

namespace alinous {namespace remote {namespace socket {
class ISocketConnectionFactory;}}}

namespace java {namespace io {
class IOException;}}

namespace alinous {namespace system {
class AlinousException;}}

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
using ::alinous::remote::socket::ISocketConnection;
using ::alinous::remote::socket::ISocketConnectionFactory;
using ::alinous::remote::socket::SocketConnectionPool;
using ::alinous::system::AlinousException;



class MonitorClientConnectionFactory final : public ISocketConnectionFactory, public virtual IObject {
public:
	MonitorClientConnectionFactory(const MonitorClientConnectionFactory& base) = default;
public:
	MonitorClientConnectionFactory(MonitorConnectionInfo* info, ThreadContext* ctx) throw() ;
	void __construct_impl(MonitorConnectionInfo* info, ThreadContext* ctx) throw() ;
	virtual ~MonitorClientConnectionFactory() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	MonitorConnectionInfo* info;
public:
	ISocketConnection* newConnection(SocketConnectionPool* pool, ThreadContext* ctx) final;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}}}

#endif /* end of ALINOUS_REMOTE_MONITOR_CLIENT_MONITORCLIENTCONNECTIONFACTORY_H_ */
