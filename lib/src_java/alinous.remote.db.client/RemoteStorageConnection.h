#ifndef ALINOUS_REMOTE_DB_CLIENT_REMOTESTORAGECONNECTION_H_
#define ALINOUS_REMOTE_DB_CLIENT_REMOTESTORAGECONNECTION_H_
namespace alinous {namespace remote {namespace socket {
class SocketConnectionPool;}}}

namespace alinous {namespace remote {namespace db {namespace client {
class RemoteStorageConnectionInfo;}}}}

namespace alinous {namespace net {
class AlinousSocket;}}

namespace alinous {namespace remote {namespace db {namespace command {
class RemoteStorageConnectCommand;}}}}

namespace alinous {namespace db {
class AlinousDbException;}}

namespace java {namespace io {
class IOException;}}

namespace alinous {namespace remote {namespace db {namespace command {
class FinishRemoteStorageConnectionCommand;}}}}

namespace alinous {namespace remote {namespace socket {
class ISocketConnection;}}}

namespace alinous {namespace net {
class UnknownHostException;}}

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
using ::alinous::db::AlinousDbException;
using ::alinous::net::AlinousSocket;
using ::alinous::remote::db::command::FinishRemoteStorageConnectionCommand;
using ::alinous::remote::db::command::RemoteStorageConnectCommand;
using ::alinous::remote::socket::ISocketConnection;
using ::alinous::remote::socket::SocketConnectionPool;



class RemoteStorageConnection final : public ISocketConnection, public virtual IObject {
public:
	RemoteStorageConnection(const RemoteStorageConnection& base) = default;
public:
	RemoteStorageConnection(SocketConnectionPool* pool, RemoteStorageConnectionInfo* info, ThreadContext* ctx) throw() ;
	void __construct_impl(SocketConnectionPool* pool, RemoteStorageConnectionInfo* info, ThreadContext* ctx) throw() ;
	virtual ~RemoteStorageConnection() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	SocketConnectionPool* pool;
	RemoteStorageConnectionInfo* info;
	AlinousSocket* socket;
public:
	void connect(ThreadContext* ctx) final;
	void close(ThreadContext* ctx) throw()  final;
	void dispose(ThreadContext* ctx) throw()  final;
	AlinousSocket* getSocket(ThreadContext* ctx) throw()  final;
	void shutdown(ThreadContext* ctx) throw()  final;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}}}

#endif /* end of ALINOUS_REMOTE_DB_CLIENT_REMOTESTORAGECONNECTION_H_ */
