#ifndef ALINOUS_REMOTE_REGION_CLIENT_REGIONCLIENTCONNECTIONFACTORY_H_
#define ALINOUS_REMOTE_REGION_CLIENT_REGIONCLIENTCONNECTIONFACTORY_H_
namespace alinous {namespace remote {namespace region {namespace client {
class RegionConnectionInfo;}}}}

namespace alinous {namespace remote {namespace socket {
class ISocketConnection;}}}

namespace alinous {namespace remote {namespace socket {
class SocketConnectionPool;}}}

namespace alinous {namespace remote {namespace region {namespace client {
class RegionConnection;}}}}

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

namespace alinous {namespace remote {namespace region {namespace client {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::java::io::IOException;
using ::java::net::UnknownHostException;
using ::alinous::remote::socket::ISocketConnection;
using ::alinous::remote::socket::ISocketConnectionFactory;
using ::alinous::remote::socket::SocketConnectionPool;
using ::alinous::system::AlinousException;



class RegionClientConnectionFactory final : public ISocketConnectionFactory, public virtual IObject {
public:
	RegionClientConnectionFactory(const RegionClientConnectionFactory& base) = default;
public:
	RegionClientConnectionFactory(RegionConnectionInfo* info, ThreadContext* ctx) throw() ;
	void __construct_impl(RegionConnectionInfo* info, ThreadContext* ctx) throw() ;
	virtual ~RegionClientConnectionFactory() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	RegionConnectionInfo* info;
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

#endif /* end of ALINOUS_REMOTE_REGION_CLIENT_REGIONCLIENTCONNECTIONFACTORY_H_ */
