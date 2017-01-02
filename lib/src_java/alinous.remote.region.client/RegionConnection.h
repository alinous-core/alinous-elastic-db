#ifndef ALINOUS_REMOTE_REGION_CLIENT_REGIONCONNECTION_H_
#define ALINOUS_REMOTE_REGION_CLIENT_REGIONCONNECTION_H_
namespace alinous {namespace remote {namespace socket {
class SocketConnectionPool;}}}

namespace alinous {namespace remote {namespace region {namespace client {
class RegionConnectionInfo;}}}}

namespace alinous {namespace net {
class AlinousSocket;}}

namespace alinous {namespace remote {namespace region {namespace command {
class NodeRegionConnectCommand;}}}}

namespace alinous {namespace remote {namespace region {namespace command {
class AbstractNodeRegionCommand;}}}}

namespace alinous {namespace db {
class AlinousDbException;}}

namespace alinous {namespace remote {namespace socket {
class ISocketConnection;}}}

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

namespace alinous {namespace remote {namespace region {namespace client {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::java::io::IOException;
using ::java::net::UnknownHostException;
using ::alinous::db::AlinousDbException;
using ::alinous::net::AlinousSocket;
using ::alinous::remote::region::command::AbstractNodeRegionCommand;
using ::alinous::remote::region::command::NodeRegionConnectCommand;
using ::alinous::remote::socket::ISocketConnection;
using ::alinous::remote::socket::SocketConnectionPool;
using ::alinous::system::AlinousException;



class RegionConnection final : public ISocketConnection, public virtual IObject {
public:
	RegionConnection(const RegionConnection& base) = default;
public:
	RegionConnection(SocketConnectionPool* pool, RegionConnectionInfo* info, ThreadContext* ctx) throw() ;
	void __construct_impl(SocketConnectionPool* pool, RegionConnectionInfo* info, ThreadContext* ctx) throw() ;
	virtual ~RegionConnection() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	SocketConnectionPool* pool;
	RegionConnectionInfo* info;
	AlinousSocket* socket;
public:
	void connect(ThreadContext* ctx) final;
	void close(ThreadContext* ctx) throw()  final;
	void dispose(ThreadContext* ctx) throw()  final;
	AlinousSocket* getSocket(ThreadContext* ctx) throw()  final;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}}}

#endif /* end of ALINOUS_REMOTE_REGION_CLIENT_REGIONCONNECTION_H_ */
