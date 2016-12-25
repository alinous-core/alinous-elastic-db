#ifndef ALINOUS_REMOTE_DB_REMOTETABLESTORAGESERVER_H_
#define ALINOUS_REMOTE_DB_REMOTETABLESTORAGESERVER_H_
namespace alinous {namespace system {
class AlinousCore;}}

namespace alinous {namespace btree {
class BTreeGlobalCache;}}

namespace alinous {namespace system {namespace config {
class AlinousInitException;}}}

namespace alinous {namespace btree {
class BTreeException;}}

namespace alinous {namespace runtime {namespace parallel {
class ThreadPool;}}}

namespace alinous {namespace remote {namespace db {
class RemoteStorageResponceActionFactory;}}}

namespace alinous {namespace remote {namespace socket {
class SocketServer;}}}

namespace alinous {namespace db {
class SchemaManager;}}

namespace alinous {namespace btree {
class IntKey;}}

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
using ::alinous::btree::BTreeException;
using ::alinous::btree::BTreeGlobalCache;
using ::alinous::btree::IntKey;
using ::alinous::db::SchemaManager;
using ::alinous::remote::socket::SocketServer;
using ::alinous::runtime::parallel::ThreadPool;
using ::alinous::system::AlinousCore;
using ::alinous::system::config::AlinousInitException;



class RemoteTableStorageServer final : public virtual IObject {
public:
	RemoteTableStorageServer(const RemoteTableStorageServer& base) = default;
public:
	RemoteTableStorageServer(int port, int maxthread, String* datadir, ThreadContext* ctx) throw() ;
	void __construct_impl(int port, int maxthread, String* datadir, ThreadContext* ctx) throw() ;
	virtual ~RemoteTableStorageServer() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
public:
	SchemaManager* schemas;
private:
	int port;
	int maxthread;
	String* datadir;
	SocketServer* socketServer;
	BTreeGlobalCache* btreeCache;
	ThreadPool* workerThreadsPool;
	AlinousCore* core;
public:
	const static IntKey __SCHEMA;
	constexpr static IntKey* SCHEMA{const_cast<IntKey*>(&__SCHEMA)};
private:
	static String* THREAD_NAME;
public:
	void init(AlinousCore* core, ThreadContext* ctx) throw() ;
	void start(AlinousCore* core, ThreadContext* ctx);
	void dispose(ThreadContext* ctx) throw() ;
	AlinousCore* getCore(ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}}

#endif /* end of ALINOUS_REMOTE_DB_REMOTETABLESTORAGESERVER_H_ */
