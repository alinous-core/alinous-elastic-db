#ifndef ALINOUS_REMOTE_DB_CLIENT_COMMAND_DML_INSERTPREPARECOMMAND_H_
#define ALINOUS_REMOTE_DB_CLIENT_COMMAND_DML_INSERTPREPARECOMMAND_H_
namespace alinous {namespace remote {namespace db {namespace server {
class RemoteTableStorageServer;}}}}

namespace java {namespace io {
class BufferedOutputStream;}}

namespace alinous {namespace system {
class AlinousCore;}}

namespace java {namespace lang {
class Throwable;}}

namespace java {namespace io {
class OutputStream;}}

namespace alinous {namespace remote {namespace socket {
class NetworkBinaryBuffer;}}}

namespace alinous {namespace remote {namespace region {namespace server {namespace schema {namespace strategy {
class UniqueCheckOperation;}}}}}}

namespace alinous {namespace remote {namespace region {namespace client {namespace command {namespace data {
class ClientNetworkRecord;}}}}}}

namespace java {namespace io {
class InputStream;}}

namespace alinous {namespace remote {namespace region {namespace server {namespace schema {
class NodeReference;}}}}}

namespace alinous {namespace db {namespace trx {
class DbVersionContext;}}}

namespace java {namespace util {
template <typename  T> class List;}}

namespace alinous {namespace remote {namespace db {namespace client {namespace command {
class AbstractRemoteStorageCommand;}}}}}

namespace java {namespace io {
class IOException;}}

namespace alinous {namespace runtime {namespace dom {
class VariableException;}}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace remote {namespace db {namespace client {namespace command {namespace dml {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::java::io::BufferedOutputStream;
using ::java::io::IOException;
using ::java::io::InputStream;
using ::java::io::OutputStream;
using ::java::util::ArrayList;
using ::java::util::List;
using ::alinous::db::trx::DbVersionContext;
using ::alinous::remote::db::client::command::AbstractRemoteStorageCommand;
using ::alinous::remote::db::server::RemoteTableStorageServer;
using ::alinous::remote::region::client::command::data::ClientNetworkRecord;
using ::alinous::remote::region::server::schema::NodeReference;
using ::alinous::remote::region::server::schema::strategy::UniqueCheckOperation;
using ::alinous::remote::socket::NetworkBinaryBuffer;
using ::alinous::runtime::dom::VariableException;
using ::alinous::system::AlinousCore;



class InsertPrepareCommand final : public AbstractRemoteStorageCommand {
public:
	InsertPrepareCommand(const InsertPrepareCommand& base) = default;
public:
	InsertPrepareCommand(ThreadContext* ctx) throw() ;
	void __construct_impl(ThreadContext* ctx) throw() ;
	virtual ~InsertPrepareCommand() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	List<UniqueCheckOperation>* uniqueCheckOps;
	List<ClientNetworkRecord>* records;
	long long newCommitId;
	DbVersionContext* vctx;
	String* schemaName;
	String* tableName;
	int isolationLevel;
	NodeReference* nodeAccessRef;
public:
	void executeOnServer(RemoteTableStorageServer* tableStorageServer, BufferedOutputStream* outStream, ThreadContext* ctx) final;
	void readFromStream(InputStream* stream, int remain, ThreadContext* ctx) final;
	void addUniqueCheck(UniqueCheckOperation* op, ThreadContext* ctx) throw() ;
	void addRecord(ClientNetworkRecord* record, ThreadContext* ctx) throw() ;
	NodeReference* getNodeAccessRef(ThreadContext* ctx) throw() ;
	void setNodeAccessRef(NodeReference* nodeAccessRef, ThreadContext* ctx) throw() ;
	long long getNewCommitId(ThreadContext* ctx) throw() ;
	void setNewCommitId(long long newCommitId, ThreadContext* ctx) throw() ;
	DbVersionContext* getVctx(ThreadContext* ctx) throw() ;
	void setVctx(DbVersionContext* vctx, ThreadContext* ctx) throw() ;
	String* getSchemaName(ThreadContext* ctx) throw() ;
	void setSchemaName(String* schemaName, ThreadContext* ctx) throw() ;
	String* getTableName(ThreadContext* ctx) throw() ;
	void setTableName(String* tableName, ThreadContext* ctx) throw() ;
	int getIsolationLevel(ThreadContext* ctx) throw() ;
	void setIsolationLevel(int isolationLevel, ThreadContext* ctx) throw() ;
	void writeByteStream(OutputStream* out, ThreadContext* ctx) final;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx);
};

}}}}}}

#endif /* end of ALINOUS_REMOTE_DB_CLIENT_COMMAND_DML_INSERTPREPARECOMMAND_H_ */
