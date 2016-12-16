#ifndef ALINOUS_REMOTE_DB_REMOTETABLESTORAGESERVER_H_
#define ALINOUS_REMOTE_DB_REMOTETABLESTORAGESERVER_H_
namespace alinous {namespace system {
class ISystemLog;}}

namespace alinous {namespace remote {namespace db {
class RemoteStorageResponceActionFactory;}}}

namespace alinous {namespace remote {namespace socket {
class SocketServer;}}}

namespace alinous {namespace db {
class SchemaManager;}}

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
using ::alinous::db::SchemaManager;
using ::alinous::remote::socket::SocketServer;
using ::alinous::system::ISystemLog;



class RemoteTableStorageServer final : public virtual IObject {
public:
	RemoteTableStorageServer(const RemoteTableStorageServer& base) = default;
public:
	RemoteTableStorageServer(int port, int maxthread, ThreadContext* ctx) throw() ;
	void __construct_impl(int port, int maxthread, ThreadContext* ctx) throw() ;
	virtual ~RemoteTableStorageServer() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
public:
	SchemaManager* schemas;
private:
	int port;
	int maxthread;
	SocketServer* socketServer;
private:
	static String* THREAD_NAME;
public:
	void start(ISystemLog* logger, ThreadContext* ctx) throw() ;
	void dispose(ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}}

#endif /* end of ALINOUS_REMOTE_DB_REMOTETABLESTORAGESERVER_H_ */
