#ifndef ALINOUS_REMOTE_MONITOR_CLIENT_REMOTECOMMITIDPUBLISHER_H_
#define ALINOUS_REMOTE_MONITOR_CLIENT_REMOTECOMMITIDPUBLISHER_H_
namespace alinous {namespace system {namespace config {namespace remote {
class MonitorRef;}}}}

namespace alinous {namespace remote {namespace monitor {namespace client {
class RemoteCommitIdPublisher;}}}}

namespace alinous {namespace db {
class AlinousDbException;}}

namespace java {namespace lang {
class NumberFormatException;}}

namespace alinous {namespace remote {namespace monitor {namespace client {
class MonitorConnectionInfo;}}}}

namespace alinous {namespace remote {namespace monitor {namespace client {
class MonitorClientConnectionFactory;}}}}

namespace alinous {namespace remote {namespace socket {
class SocketConnectionPool;}}}

namespace alinous {namespace remote {namespace monitor {namespace command {namespace commitId {
class GetMaxCommitIdCommand;}}}}}

namespace alinous {namespace remote {namespace socket {
class ISocketConnection;}}}

namespace alinous {namespace net {
class UnknownHostException;}}

namespace java {namespace io {
class IOException;}}

namespace alinous {namespace remote {namespace monitor {namespace command {namespace commitId {
class NewCommitIdCommand;}}}}}

namespace alinous {namespace db {
class ICommidIdPublisher;}}

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
using ::alinous::db::ICommidIdPublisher;
using ::alinous::remote::monitor::command::commitId::GetMaxCommitIdCommand;
using ::alinous::remote::monitor::command::commitId::NewCommitIdCommand;
using ::alinous::remote::socket::ISocketConnection;
using ::alinous::remote::socket::SocketConnectionPool;
using ::alinous::system::config::remote::MonitorRef;



class RemoteCommitIdPublisher final : public ICommidIdPublisher, public virtual IObject {
public:
	RemoteCommitIdPublisher(const RemoteCommitIdPublisher& base) = default;
public:
	RemoteCommitIdPublisher(MonitorRef* monitorRef, ThreadContext* ctx) throw() ;
	void __construct_impl(MonitorRef* monitorRef, ThreadContext* ctx) throw() ;
	virtual ~RemoteCommitIdPublisher() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	String* url;
	MonitorConnectionInfo* info;
	SocketConnectionPool* pool;
public:
	RemoteCommitIdPublisher* init(ThreadContext* ctx);
	void setMaxCommitId(long long maxCommitId, ThreadContext* ctx) throw()  final;
	long long getMaxCommitId(ThreadContext* ctx) final;
	long long newCommitId(ThreadContext* ctx) final;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}}}

#endif /* end of ALINOUS_REMOTE_MONITOR_CLIENT_REMOTECOMMITIDPUBLISHER_H_ */
