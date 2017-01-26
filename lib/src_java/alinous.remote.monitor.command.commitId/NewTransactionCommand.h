#ifndef ALINOUS_REMOTE_MONITOR_COMMAND_COMMITID_NEWTRANSACTIONCOMMAND_H_
#define ALINOUS_REMOTE_MONITOR_COMMAND_COMMITID_NEWTRANSACTIONCOMMAND_H_
namespace alinous {namespace remote {namespace monitor {
class TransactionMonitorServer;}}}

namespace java {namespace io {
class BufferedOutputStream;}}

namespace java {namespace io {
class OutputStream;}}

namespace alinous {namespace remote {namespace socket {
class NetworkBinaryBuffer;}}}

namespace java {namespace io {
class InputStream;}}

namespace alinous {namespace remote {namespace monitor {namespace command {
class AbstractMonitorCommand;}}}}

namespace java {namespace io {
class IOException;}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace remote {namespace monitor {namespace command {namespace commitId {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::java::io::BufferedOutputStream;
using ::java::io::IOException;
using ::java::io::InputStream;
using ::java::io::OutputStream;
using ::alinous::remote::monitor::TransactionMonitorServer;
using ::alinous::remote::monitor::command::AbstractMonitorCommand;
using ::alinous::remote::socket::NetworkBinaryBuffer;



class NewTransactionCommand final : public AbstractMonitorCommand {
public:
	NewTransactionCommand(const NewTransactionCommand& base) = default;
public:
	NewTransactionCommand(ThreadContext* ctx) throw() ;
	void __construct_impl(ThreadContext* ctx) throw() ;
	virtual ~NewTransactionCommand() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	long long commitId;
	long long trxId;
	long long schemaVersion;
	long long nodeClusterVersion;
public:
	void executeOnServer(TransactionMonitorServer* monitorServer, BufferedOutputStream* outStream, ThreadContext* ctx) final;
	void readFromStream(InputStream* stream, int remain, ThreadContext* ctx) final;
	long long getCommitId(ThreadContext* ctx) throw() ;
	void setCommitId(long long commitId, ThreadContext* ctx) throw() ;
	long long getTrxId(ThreadContext* ctx) throw() ;
	void setTrxId(long long trxId, ThreadContext* ctx) throw() ;
	long long getSchemaVersion(ThreadContext* ctx) throw() ;
	void setSchemaVersion(long long schemaVersion, ThreadContext* ctx) throw() ;
	long long getNodeClusterVersion(ThreadContext* ctx) throw() ;
	void setNodeClusterVersion(long long nodeClusterVersion, ThreadContext* ctx) throw() ;
	void writeByteStream(OutputStream* out, ThreadContext* ctx) final;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}}}}

#endif /* end of ALINOUS_REMOTE_MONITOR_COMMAND_COMMITID_NEWTRANSACTIONCOMMAND_H_ */
