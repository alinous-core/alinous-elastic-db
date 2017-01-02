#ifndef ALINOUS_REMOTE_SOCKET_ISOCKETCONNECTION_H_
#define ALINOUS_REMOTE_SOCKET_ISOCKETCONNECTION_H_
namespace alinous {namespace net {
class AlinousSocket;}}

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
using ::alinous::net::AlinousSocket;
using ::alinous::system::AlinousException;



class ISocketConnection : public virtual IObject {
public:
	ISocketConnection(const ISocketConnection& base) = default;
public:
	ISocketConnection(ThreadContext* ctx) throw()  : IObject(ctx)
	{
	}
	void __construct_impl(ThreadContext* ctx) throw() 
	{
	}
	virtual ~ISocketConnection() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
public:
	virtual void connect(ThreadContext* ctx) = 0;
	virtual void close(ThreadContext* ctx) throw()  = 0;
	virtual void dispose(ThreadContext* ctx) throw()  = 0;
	virtual AlinousSocket* getSocket(ThreadContext* ctx) throw()  = 0;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}}

#endif /* end of ALINOUS_REMOTE_SOCKET_ISOCKETCONNECTION_H_ */
