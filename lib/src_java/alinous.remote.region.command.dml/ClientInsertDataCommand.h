#ifndef ALINOUS_REMOTE_REGION_COMMAND_DML_CLIENTINSERTDATACOMMAND_H_
#define ALINOUS_REMOTE_REGION_COMMAND_DML_CLIENTINSERTDATACOMMAND_H_
namespace alinous {namespace remote {namespace region {
class NodeRegionServer;}}}

namespace java {namespace io {
class BufferedOutputStream;}}

namespace alinous {namespace system {
class AlinousException;}}

namespace java {namespace io {
class OutputStream;}}

namespace alinous {namespace remote {namespace socket {
class NetworkBinaryBuffer;}}}

namespace alinous {namespace remote {namespace region {namespace command {namespace data {
class ClientNetworkRecord;}}}}}

namespace java {namespace io {
class InputStream;}}

namespace alinous {namespace db {namespace trx {
class DbVersionContext;}}}

namespace alinous {namespace remote {namespace region {namespace command {
class AbstractNodeRegionCommand;}}}}

namespace java {namespace io {
class IOException;}}

namespace alinous {namespace runtime {namespace dom {
class VariableException;}}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace remote {namespace region {namespace command {namespace dml {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::java::io::BufferedOutputStream;
using ::java::io::IOException;
using ::java::io::InputStream;
using ::java::io::OutputStream;
using ::java::util::ArrayList;
using ::alinous::db::trx::DbVersionContext;
using ::alinous::remote::region::NodeRegionServer;
using ::alinous::remote::region::command::AbstractNodeRegionCommand;
using ::alinous::remote::region::command::data::ClientNetworkRecord;
using ::alinous::remote::socket::NetworkBinaryBuffer;
using ::alinous::runtime::dom::VariableException;
using ::alinous::system::AlinousException;



class ClientInsertDataCommand final : public AbstractNodeRegionCommand {
public:
	ClientInsertDataCommand(const ClientInsertDataCommand& base) = default;
public:
	ClientInsertDataCommand(ThreadContext* ctx) throw() ;
	void __construct_impl(ThreadContext* ctx) throw() ;
	virtual ~ClientInsertDataCommand() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	ArrayList<ClientNetworkRecord>* list;
	long long commitId;
	String* schema;
	String* table;
	DbVersionContext* vctx;
public:
	void executeOnServer(NodeRegionServer* nodeRegionServer, BufferedOutputStream* outStream, ThreadContext* ctx) final;
	void readFromStream(InputStream* stream, int remain, ThreadContext* ctx) final;
	ArrayList<ClientNetworkRecord>* getList(ThreadContext* ctx) throw() ;
	void setList(ArrayList<ClientNetworkRecord>* list, ThreadContext* ctx) throw() ;
	long long getCommitId(ThreadContext* ctx) throw() ;
	void setCommitId(long long commitId, ThreadContext* ctx) throw() ;
	String* getSchema(ThreadContext* ctx) throw() ;
	void setSchema(String* schema, ThreadContext* ctx) throw() ;
	String* getTable(ThreadContext* ctx) throw() ;
	void setTable(String* table, ThreadContext* ctx) throw() ;
	DbVersionContext* getVctx(ThreadContext* ctx) throw() ;
	void setVctx(DbVersionContext* vctx, ThreadContext* ctx) throw() ;
	void writeByteStream(OutputStream* outStream, ThreadContext* ctx) final;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}}}}

#endif /* end of ALINOUS_REMOTE_REGION_COMMAND_DML_CLIENTINSERTDATACOMMAND_H_ */
