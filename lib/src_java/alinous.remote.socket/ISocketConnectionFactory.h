#ifndef ALINOUS_REMOTE_SOCKET_ISOCKETCONNECTIONFACTORY_H_
#define ALINOUS_REMOTE_SOCKET_ISOCKETCONNECTIONFACTORY_H_
namespace alinous {namespace remote {namespace socket {
class ISocketConnection;}}}

namespace alinous {namespace remote {namespace socket {
class SocketConnectionPool;}}}

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

namespace alinous {namespace remote {namespace socket {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::java::io::IOException;
using ::java::net::UnknownHostException;
using ::alinous::system::AlinousException;



class ISocketConnectionFactory : public virtual IObject {
public:
	ISocketConnectionFactory(const ISocketConnectionFactory& base) = default;
public:
	ISocketConnectionFactory(ThreadContext* ctx) throw()  : IObject(ctx)
	{
	}
	void __construct_impl(ThreadContext* ctx) throw() 
	{
	}
	virtual ~ISocketConnectionFactory() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
public:
	virtual ISocketConnection* newConnection(SocketConnectionPool* pool, ThreadContext* ctx) = 0;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}}

#endif /* end of ALINOUS_REMOTE_SOCKET_ISOCKETCONNECTIONFACTORY_H_ */
