#ifndef ALINOUS_REMOTE_DB_CLIENT_COMMAND_DDL_CREATESCHEMACOMMAND_H_
#define ALINOUS_REMOTE_DB_CLIENT_COMMAND_DDL_CREATESCHEMACOMMAND_H_
namespace alinous {namespace remote {namespace db {namespace server {
class RemoteTableStorageServer;}}}}

namespace java {namespace io {
class BufferedOutputStream;}}

namespace alinous {namespace system {
class AlinousException;}}

namespace java {namespace io {
class OutputStream;}}

namespace alinous {namespace remote {namespace socket {
class NetworkBinaryBuffer;}}}

namespace java {namespace io {
class InputStream;}}

namespace alinous {namespace remote {namespace db {namespace client {namespace command {
class AbstractRemoteStorageCommand;}}}}}

namespace java {namespace io {
class IOException;}}

namespace alinous {namespace remote {namespace db {namespace client {namespace command {
class RemoteStorageConnectCommand;}}}}}

namespace alinous {namespace runtime {namespace dom {
class VariableException;}}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace remote {namespace db {namespace client {namespace command {namespace ddl {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::java::io::BufferedOutputStream;
using ::java::io::IOException;
using ::java::io::InputStream;
using ::java::io::OutputStream;
using ::alinous::remote::db::client::command::AbstractRemoteStorageCommand;
using ::alinous::remote::db::client::command::RemoteStorageConnectCommand;
using ::alinous::remote::db::server::RemoteTableStorageServer;
using ::alinous::remote::socket::NetworkBinaryBuffer;
using ::alinous::runtime::dom::VariableException;
using ::alinous::system::AlinousException;



class CreateSchemaCommand final : public AbstractRemoteStorageCommand {
public:
	CreateSchemaCommand(const CreateSchemaCommand& base) = default;
public:
	CreateSchemaCommand(ThreadContext* ctx) throw() ;
	void __construct_impl(ThreadContext* ctx) throw() ;
	virtual ~CreateSchemaCommand() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	String* schemaName;
public:
	void executeOnServer(RemoteTableStorageServer* tableStorageServer, BufferedOutputStream* outStream, ThreadContext* ctx) final;
	void readFromStream(InputStream* stream, int remain, ThreadContext* ctx) final;
	String* getSchemaName(ThreadContext* ctx) throw() ;
	void setSchemaName(String* schemaName, ThreadContext* ctx) throw() ;
	void writeByteStream(OutputStream* out, ThreadContext* ctx) final;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx);
};

}}}}}}

#endif /* end of ALINOUS_REMOTE_DB_CLIENT_COMMAND_DDL_CREATESCHEMACOMMAND_H_ */
