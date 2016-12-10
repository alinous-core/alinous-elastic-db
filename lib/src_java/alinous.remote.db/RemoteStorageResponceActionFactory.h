#ifndef ALINOUS_REMOTE_DB_REMOTESTORAGERESPONCEACTIONFACTORY_H_
#define ALINOUS_REMOTE_DB_REMOTESTORAGERESPONCEACTIONFACTORY_H_
namespace alinous {namespace remote {namespace db {
class RemoteTableStorageServer;}}}

namespace alinous {namespace runtime {namespace parallel {
class IThreadAction;}}}

namespace java {namespace net {
class Socket;}}

namespace alinous {namespace remote {namespace socket {
class SocketServer;}}}

namespace alinous {namespace remote {namespace db {
class RemoteStorageResponceAction;}}}

namespace alinous {namespace remote {namespace socket {
class ISocketActionFactory;}}}

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
using ::java::net::Socket;
using ::alinous::remote::socket::ISocketActionFactory;
using ::alinous::remote::socket::SocketServer;
using ::alinous::runtime::parallel::IThreadAction;



class RemoteStorageResponceActionFactory final : public ISocketActionFactory, public virtual IObject {
public:
	RemoteStorageResponceActionFactory(const RemoteStorageResponceActionFactory& base) = default;
public:
	RemoteStorageResponceActionFactory(RemoteTableStorageServer* remoteTableStorageServer, ThreadContext* ctx) throw() ;
	void __construct_impl(RemoteTableStorageServer* remoteTableStorageServer, ThreadContext* ctx) throw() ;
	virtual ~RemoteStorageResponceActionFactory() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	RemoteTableStorageServer* remoteTableStorageServer;
public:
	RemoteTableStorageServer* getRemoteTableStorageServer(ThreadContext* ctx) throw() ;
	IThreadAction* getAction(Socket* socket, SocketServer* server, ThreadContext* ctx) throw()  final;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}}

#endif /* end of ALINOUS_REMOTE_DB_REMOTESTORAGERESPONCEACTIONFACTORY_H_ */
