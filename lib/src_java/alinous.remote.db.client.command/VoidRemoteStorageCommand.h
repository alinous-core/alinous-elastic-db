#ifndef ALINOUS_REMOTE_DB_CLIENT_COMMAND_VOIDREMOTESTORAGECOMMAND_H_
#define ALINOUS_REMOTE_DB_CLIENT_COMMAND_VOIDREMOTESTORAGECOMMAND_H_
namespace java {namespace io {
class InputStream;}}

namespace java {namespace io {
class OutputStream;}}

namespace alinous {namespace remote {namespace socket {
class NetworkBinaryBuffer;}}}

namespace alinous {namespace remote {namespace db {
class RemoteTableStorageServer;}}}

namespace java {namespace io {
class BufferedOutputStream;}}

namespace alinous {namespace remote {namespace db {namespace client {namespace command {
class AbstractRemoteStorageCommand;}}}}}

namespace java {namespace io {
class IOException;}}

namespace alinous {namespace remote {namespace monitor {namespace client {namespace command {
class AbstractMonitorCommand;}}}}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace remote {namespace db {namespace client {namespace command {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::java::io::BufferedOutputStream;
using ::java::io::IOException;
using ::java::io::InputStream;
using ::java::io::OutputStream;
using ::alinous::remote::db::RemoteTableStorageServer;
using ::alinous::remote::monitor::client::command::AbstractMonitorCommand;
using ::alinous::remote::socket::NetworkBinaryBuffer;



class VoidRemoteStorageCommand final : public AbstractRemoteStorageCommand {
public:
	VoidRemoteStorageCommand(const VoidRemoteStorageCommand& base) = default;
public:
	VoidRemoteStorageCommand(ThreadContext* ctx) throw() ;
	void __construct_impl(ThreadContext* ctx) throw() ;
	virtual ~VoidRemoteStorageCommand() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
public:
	void readFromStream(InputStream* stream, int remain, ThreadContext* ctx) final;
	void executeOnServer(RemoteTableStorageServer* tableStorageServer, BufferedOutputStream* outStream, ThreadContext* ctx) final;
	void writeByteStream(OutputStream* out, ThreadContext* ctx) final;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx);
};

}}}}}

#endif /* end of ALINOUS_REMOTE_DB_CLIENT_COMMAND_VOIDREMOTESTORAGECOMMAND_H_ */
