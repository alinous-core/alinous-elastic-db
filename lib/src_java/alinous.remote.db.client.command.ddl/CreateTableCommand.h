#ifndef ALINOUS_REMOTE_DB_CLIENT_COMMAND_DDL_CREATETABLECOMMAND_H_
#define ALINOUS_REMOTE_DB_CLIENT_COMMAND_DDL_CREATETABLECOMMAND_H_
namespace alinous {namespace remote {namespace db {
class RemoteTableStorageServer;}}}

namespace java {namespace io {
class BufferedOutputStream;}}

namespace java {namespace lang {
class InterruptedException;}}

namespace alinous {namespace btree {
class BTreeException;}}

namespace alinous {namespace db {namespace table {
class DatabaseException;}}}

namespace alinous {namespace system {
class AlinousException;}}

namespace java {namespace io {
class OutputStream;}}

namespace alinous {namespace remote {namespace socket {
class NetworkBinaryBuffer;}}}

namespace java {namespace io {
class InputStream;}}

namespace alinous {namespace db {namespace table {
class TableMetadata;}}}

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
using ::alinous::btree::BTreeException;
using ::alinous::db::table::DatabaseException;
using ::alinous::db::table::TableMetadata;
using ::alinous::remote::db::RemoteTableStorageServer;
using ::alinous::remote::db::client::command::AbstractRemoteStorageCommand;
using ::alinous::remote::db::client::command::RemoteStorageConnectCommand;
using ::alinous::remote::socket::NetworkBinaryBuffer;
using ::alinous::runtime::dom::VariableException;
using ::alinous::system::AlinousException;



class CreateTableCommand final : public AbstractRemoteStorageCommand {
public:
	CreateTableCommand(const CreateTableCommand& base) = default;
public:
	CreateTableCommand(ThreadContext* ctx) throw() ;
	void __construct_impl(ThreadContext* ctx) throw() ;
	virtual ~CreateTableCommand() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	TableMetadata* metadaata;
public:
	void executeOnServer(RemoteTableStorageServer* tableStorageServer, BufferedOutputStream* outStream, ThreadContext* ctx) final;
	void readFromStream(InputStream* stream, int remain, ThreadContext* ctx) final;
	TableMetadata* getMetadaata(ThreadContext* ctx) throw() ;
	void setMetadaata(TableMetadata* metadaata, ThreadContext* ctx) throw() ;
	void writeByteStream(OutputStream* out, ThreadContext* ctx) final;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx);
};

}}}}}}

#endif /* end of ALINOUS_REMOTE_DB_CLIENT_COMMAND_DDL_CREATETABLECOMMAND_H_ */
