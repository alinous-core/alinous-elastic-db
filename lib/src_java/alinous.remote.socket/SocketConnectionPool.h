#ifndef ALINOUS_REMOTE_SOCKET_SOCKETCONNECTIONPOOL_H_
#define ALINOUS_REMOTE_SOCKET_SOCKETCONNECTIONPOOL_H_
namespace alinous {namespace remote {namespace socket {
class ISocketConnectionFactory;}}}

namespace alinous {namespace remote {namespace socket {
class ISocketConnection;}}}

namespace java {namespace util {
template <typename  T> class Stack;}}

namespace alinous {namespace lock {
class LockObject;}}

namespace java {namespace io {
class IOException;}}

namespace alinous {namespace net {
class UnknownHostException;}}

namespace alinous {namespace db {
class AlinousDbException;}}

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
using ::java::util::Stack;
using ::alinous::db::AlinousDbException;
using ::alinous::lock::LockObject;



class SocketConnectionPool final : public virtual IObject {
public:
	SocketConnectionPool(const SocketConnectionPool& base) = default;
public:
	SocketConnectionPool(ISocketConnectionFactory* factory, ThreadContext* ctx) throw() ;
	void __construct_impl(ISocketConnectionFactory* factory, ThreadContext* ctx) throw() ;
	virtual ~SocketConnectionPool() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	Stack<ISocketConnection>* connections;
	LockObject* lockObject;
	ISocketConnectionFactory* factory;
public:
	ISocketConnection* getConnection(ThreadContext* ctx);
	void returnConnection(ISocketConnection* con, ThreadContext* ctx) throw() ;
	void dispose(ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}}

#endif /* end of ALINOUS_REMOTE_SOCKET_SOCKETCONNECTIONPOOL_H_ */
