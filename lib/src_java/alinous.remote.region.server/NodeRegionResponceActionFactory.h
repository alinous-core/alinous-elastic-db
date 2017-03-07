#ifndef ALINOUS_REMOTE_REGION_SERVER_NODEREGIONRESPONCEACTIONFACTORY_H_
#define ALINOUS_REMOTE_REGION_SERVER_NODEREGIONRESPONCEACTIONFACTORY_H_
namespace alinous {namespace remote {namespace region {namespace server {
class NodeRegionServer;}}}}

namespace alinous {namespace runtime {namespace parallel {
class IThreadAction;}}}

namespace java {namespace net {
class Socket;}}

namespace alinous {namespace remote {namespace socket {
class SocketServer;}}}

namespace alinous {namespace remote {namespace region {namespace server {
class NodeRegionResponceAction;}}}}

namespace alinous {namespace remote {namespace socket {
class ISocketActionFactory;}}}

namespace java {namespace lang {
class IObject;
}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace remote {namespace region {namespace server {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::java::net::Socket;
using ::alinous::remote::socket::ISocketActionFactory;
using ::alinous::remote::socket::SocketServer;
using ::alinous::runtime::parallel::IThreadAction;



class NodeRegionResponceActionFactory final : public ISocketActionFactory, public virtual IObject {
public:
	NodeRegionResponceActionFactory(const NodeRegionResponceActionFactory& base) = default;
public:
	NodeRegionResponceActionFactory(NodeRegionServer* storageNodeRegionServer, ThreadContext* ctx) throw() ;
	void __construct_impl(NodeRegionServer* storageNodeRegionServer, ThreadContext* ctx) throw() ;
	virtual ~NodeRegionResponceActionFactory() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	NodeRegionServer* storageNodeRegionServer;
public:
	NodeRegionServer* getStorageNodeRegionServer(ThreadContext* ctx) throw() ;
	IThreadAction* getAction(Socket* socket, SocketServer* server, ThreadContext* ctx) throw()  final;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx);
};

}}}}

#endif /* end of ALINOUS_REMOTE_REGION_SERVER_NODEREGIONRESPONCEACTIONFACTORY_H_ */
