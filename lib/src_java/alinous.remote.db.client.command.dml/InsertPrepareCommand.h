#ifndef ALINOUS_REMOTE_DB_CLIENT_COMMAND_DML_INSERTPREPARECOMMAND_H_
#define ALINOUS_REMOTE_DB_CLIENT_COMMAND_DML_INSERTPREPARECOMMAND_H_
namespace alinous {namespace remote {namespace db {
class RemoteTableStorageServer;}}}

namespace java {namespace io {
class BufferedOutputStream;}}

namespace java {namespace io {
class OutputStream;}}

namespace java {namespace io {
class InputStream;}}

namespace alinous {namespace remote {namespace region {namespace server {namespace schema {namespace strategy {
class UniqueCheckOperation;}}}}}}

namespace alinous {namespace remote {namespace region {namespace client {namespace command {namespace data {
class ClientNetworkRecord;}}}}}}

namespace alinous {namespace remote {namespace region {namespace server {namespace schema {
class NodeReference;}}}}}

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
using ::alinous::remote::db::RemoteTableStorageServer;
using ::alinous::remote::db::client::command::AbstractRemoteStorageCommand;
using ::alinous::remote::region::client::command::data::ClientNetworkRecord;
using ::alinous::remote::region::server::schema::NodeReference;
using ::alinous::remote::region::server::schema::strategy::UniqueCheckOperation;
using ::alinous::runtime::dom::VariableException;



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
	NodeReference* nodeAccessRef;
public:
	void executeOnServer(RemoteTableStorageServer* tableStorageServer, BufferedOutputStream* outStream, ThreadContext* ctx) final;
	void readFromStream(InputStream* stream, int remain, ThreadContext* ctx) final;
	void addUniqueCheck(UniqueCheckOperation* op, ThreadContext* ctx) throw() ;
	void addRecord(ClientNetworkRecord* record, ThreadContext* ctx) throw() ;
	NodeReference* getNodeAccessRef(ThreadContext* ctx) throw() ;
	void setNodeAccessRef(NodeReference* nodeAccessRef, ThreadContext* ctx) throw() ;
	void writeByteStream(OutputStream* out, ThreadContext* ctx) final;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx);
};

}}}}}}

#endif /* end of ALINOUS_REMOTE_DB_CLIENT_COMMAND_DML_INSERTPREPARECOMMAND_H_ */
