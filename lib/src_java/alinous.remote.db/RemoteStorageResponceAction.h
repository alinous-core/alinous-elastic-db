#ifndef ALINOUS_REMOTE_DB_REMOTESTORAGERESPONCEACTION_H_
#define ALINOUS_REMOTE_DB_REMOTESTORAGERESPONCEACTION_H_
namespace alinous {namespace remote {namespace db {
class RemoteTableStorageServer;}}}

namespace java {namespace net {
class Socket;}}

namespace alinous {namespace remote {namespace socket {
class SocketServer;}}}

namespace java {namespace io {
class InputStream;}}

namespace java {namespace io {
class BufferedInputStream;}}

namespace java {namespace io {
class OutputStream;}}

namespace java {namespace io {
class BufferedOutputStream;}}

namespace java {namespace lang {
class Throwable;}}

namespace alinous {namespace remote {namespace db {namespace client {namespace command {
class AbstractRemoteStorageCommand;}}}}}

namespace alinous {namespace system {
class AlinousException;}}

namespace alinous {namespace runtime {namespace parallel {
class IThreadAction;}}}

namespace java {namespace io {
class IOException;}}

namespace alinous {namespace remote {namespace db {namespace client {namespace command {
class RemoteStorageCommandReader;}}}}}

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
using ::java::io::BufferedInputStream;
using ::java::io::BufferedOutputStream;
using ::java::io::IOException;
using ::java::io::InputStream;
using ::java::io::OutputStream;
using ::java::net::Socket;
using ::alinous::remote::db::client::command::AbstractRemoteStorageCommand;
using ::alinous::remote::db::client::command::RemoteStorageCommandReader;
using ::alinous::remote::socket::SocketServer;
using ::alinous::runtime::parallel::IThreadAction;
using ::alinous::system::AlinousException;



class RemoteStorageResponceAction final : public IThreadAction, public virtual IObject {
public:
	RemoteStorageResponceAction(const RemoteStorageResponceAction& base) = default;
public:
	RemoteStorageResponceAction(RemoteTableStorageServer* tableStorageServer, Socket* socket, SocketServer* server, ThreadContext* ctx) throw() ;
	void __construct_impl(RemoteTableStorageServer* tableStorageServer, Socket* socket, SocketServer* server, ThreadContext* ctx) throw() ;
	virtual ~RemoteStorageResponceAction() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	Socket* socket;
	SocketServer* server;
	RemoteTableStorageServer* tableStorageServer;
public:
	void execute(ThreadContext* ctx) final;
private:
	void handleCommand(BufferedInputStream* stream, BufferedOutputStream* outStream, ThreadContext* ctx);
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx);
};

}}}

#endif /* end of ALINOUS_REMOTE_DB_REMOTESTORAGERESPONCEACTION_H_ */
