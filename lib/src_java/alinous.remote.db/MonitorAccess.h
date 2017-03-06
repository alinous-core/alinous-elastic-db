#ifndef ALINOUS_REMOTE_DB_MONITORACCESS_H_
#define ALINOUS_REMOTE_DB_MONITORACCESS_H_
namespace java{namespace net{
class UnknownHostException;
}}
namespace alinous {namespace system {namespace config {namespace remote {
class MonitorRef;}}}}

namespace alinous {namespace remote {namespace monitor {namespace client {
class MonitorConnectionInfo;}}}}

namespace alinous {namespace remote {namespace monitor {namespace client {
class MonitorClientConnectionFactory;}}}}

namespace alinous {namespace remote {namespace socket {
class SocketConnectionPool;}}}

namespace alinous {namespace remote {namespace monitor {namespace client {namespace command {namespace commitId {
class ReportSchemaVersionCommand;}}}}}}

namespace alinous {namespace remote {namespace socket {
class ISocketConnection;}}}

namespace alinous {namespace net {
class AlinousSocket;}}

namespace alinous {namespace remote {namespace monitor {namespace client {namespace command {
class AbstractMonitorCommand;}}}}}

namespace alinous {namespace system {
class AlinousException;}}

namespace java {namespace io {
class IOException;}}

namespace java {namespace lang {
class IObject;
}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace remote {namespace db {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::java::io::IOException;
using ::java::net::UnknownHostException;
using ::alinous::net::AlinousSocket;
using ::alinous::remote::monitor::client::MonitorClientConnectionFactory;
using ::alinous::remote::monitor::client::MonitorConnectionInfo;
using ::alinous::remote::monitor::client::command::AbstractMonitorCommand;
using ::alinous::remote::monitor::client::command::commitId::ReportSchemaVersionCommand;
using ::alinous::remote::socket::ISocketConnection;
using ::alinous::remote::socket::SocketConnectionPool;
using ::alinous::system::AlinousException;
using ::alinous::system::config::remote::MonitorRef;



class MonitorAccess final : public virtual IObject {
public:
	MonitorAccess(const MonitorAccess& base) = default;
public:
	MonitorAccess(MonitorRef* monitorRef, ThreadContext* ctx) throw() ;
	void __construct_impl(MonitorRef* monitorRef, ThreadContext* ctx) throw() ;
	virtual ~MonitorAccess() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	MonitorRef* monitorRef;
	SocketConnectionPool* pool;
public:
	void init(ThreadContext* ctx) throw() ;
	void reportSchemaUpdated(ThreadContext* ctx);
	void dispose(ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx);
};

}}}

#endif /* end of ALINOUS_REMOTE_DB_MONITORACCESS_H_ */
