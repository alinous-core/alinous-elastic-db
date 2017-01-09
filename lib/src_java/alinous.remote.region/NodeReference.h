#ifndef ALINOUS_REMOTE_REGION_NODEREFERENCE_H_
#define ALINOUS_REMOTE_REGION_NODEREFERENCE_H_
namespace alinous {namespace remote {namespace db {namespace client {
class RemoteStorageConnectionInfo;}}}}

namespace alinous {namespace remote {namespace db {namespace client {
class RemoteStorageClientConnectionFactory;}}}}

namespace alinous {namespace remote {namespace socket {
class SocketConnectionPool;}}}

namespace alinous {namespace remote {namespace region {
class NodeReference;}}}

namespace java {namespace lang {
class IObject;
}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace remote {namespace region {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::alinous::remote::db::client::RemoteStorageClientConnectionFactory;
using ::alinous::remote::db::client::RemoteStorageConnectionInfo;
using ::alinous::remote::socket::SocketConnectionPool;



class NodeReference final : public virtual IObject {
public:
	NodeReference(const NodeReference& base) = default;
public:
	NodeReference(String* host, int port, bool ipv6, ThreadContext* ctx) throw() ;
	void __construct_impl(String* host, int port, bool ipv6, ThreadContext* ctx) throw() ;
	virtual ~NodeReference() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	String* host;
	int port;
	bool ipv6;
	SocketConnectionPool* nodeConnectionPool;
public:
	void initConnectionPool(ThreadContext* ctx) throw() ;
	void dispose(ThreadContext* ctx) throw() ;
	String* getHost(ThreadContext* ctx) throw() ;
	int getPort(ThreadContext* ctx) throw() ;
	bool isIpv6(ThreadContext* ctx) throw() ;
	bool equals(String* host, int port, bool ipv6, ThreadContext* ctx) throw() ;
	bool equals(IObject* obj, ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}}

#endif /* end of ALINOUS_REMOTE_REGION_NODEREFERENCE_H_ */
