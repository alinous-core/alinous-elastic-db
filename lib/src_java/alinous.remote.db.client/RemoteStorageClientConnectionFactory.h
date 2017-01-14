#ifndef ALINOUS_REMOTE_DB_CLIENT_REMOTESTORAGECLIENTCONNECTIONFACTORY_H_
#define ALINOUS_REMOTE_DB_CLIENT_REMOTESTORAGECLIENTCONNECTIONFACTORY_H_
namespace alinous {namespace remote {namespace db {namespace client {
class RemoteStorageConnectionInfo;}}}}

namespace alinous {namespace remote {namespace socket {
class ISocketConnection;}}}

namespace alinous {namespace remote {namespace socket {
class SocketConnectionPool;}}}

namespace alinous {namespace remote {namespace db {namespace client {
class RemoteStorageConnection;}}}}

namespace alinous {namespace remote {namespace socket {
class ISocketConnectionFactory;}}}

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

namespace alinous {namespace remote {namespace db {namespace client {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::java::io::IOException;
using ::java::net::UnknownHostException;
using ::alinous::remote::socket::ISocketConnection;
using ::alinous::remote::socket::ISocketConnectionFactory;
using ::alinous::remote::socket::SocketConnectionPool;
using ::alinous::system::AlinousException;



class RemoteStorageClientConnectionFactory final : public ISocketConnectionFactory, public virtual IObject {
public:
	RemoteStorageClientConnectionFactory(const RemoteStorageClientConnectionFactory& base) = default;
public:
	RemoteStorageClientConnectionFactory(RemoteStorageConnectionInfo* info, ThreadContext* ctx) throw() ;
	void __construct_impl(RemoteStorageConnectionInfo* info, ThreadContext* ctx) throw() ;
	virtual ~RemoteStorageClientConnectionFactory() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	RemoteStorageConnectionInfo* info;
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

#endif /* end of ALINOUS_REMOTE_DB_CLIENT_REMOTESTORAGECLIENTCONNECTIONFACTORY_H_ */
