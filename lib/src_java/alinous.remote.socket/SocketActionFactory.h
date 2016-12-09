#ifndef ALINOUS_REMOTE_SOCKET_SOCKETACTIONFACTORY_H_
#define ALINOUS_REMOTE_SOCKET_SOCKETACTIONFACTORY_H_
namespace alinous {namespace runtime {namespace parallel {
class IThreadAction;}}}

namespace java {namespace net {
class Socket;}}

namespace alinous {namespace remote {namespace socket {
class SocketServer;}}}

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
using ::java::net::Socket;
using ::alinous::runtime::parallel::IThreadAction;



class SocketActionFactory : public virtual IObject {
public:
	SocketActionFactory(const SocketActionFactory& base) = default;
public:
	SocketActionFactory(ThreadContext* ctx) throw()  : IObject(ctx)
	{
	}
	void __construct_impl(ThreadContext* ctx) throw() 
	{
	}
	virtual ~SocketActionFactory() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
public:
	virtual IThreadAction* getAction(Socket* socket, SocketServer* server, ThreadContext* ctx) throw()  = 0;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}}

#endif /* end of ALINOUS_REMOTE_SOCKET_SOCKETACTIONFACTORY_H_ */
