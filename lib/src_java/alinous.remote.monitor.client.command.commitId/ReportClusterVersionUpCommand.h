#ifndef ALINOUS_REMOTE_MONITOR_CLIENT_COMMAND_COMMITID_REPORTCLUSTERVERSIONUPCOMMAND_H_
#define ALINOUS_REMOTE_MONITOR_CLIENT_COMMAND_COMMITID_REPORTCLUSTERVERSIONUPCOMMAND_H_
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

namespace alinous {namespace remote {namespace monitor {namespace client {namespace command {
class AbstractMonitorCommand;}}}}}

namespace java {namespace io {
class IOException;}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace remote {namespace monitor {namespace client {namespace command {namespace commitId {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::java::io::BufferedOutputStream;
using ::java::io::IOException;
using ::java::io::InputStream;
using ::java::io::OutputStream;
using ::alinous::remote::monitor::TransactionMonitorServer;
using ::alinous::remote::monitor::client::command::AbstractMonitorCommand;
using ::alinous::remote::socket::NetworkBinaryBuffer;



class ReportClusterVersionUpCommand final : public AbstractMonitorCommand {
public:
	ReportClusterVersionUpCommand(const ReportClusterVersionUpCommand& base) = default;
public:
	ReportClusterVersionUpCommand(ThreadContext* ctx) throw() ;
	void __construct_impl(ThreadContext* ctx) throw() ;
	virtual ~ReportClusterVersionUpCommand() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	long long nodeClusterRevision;
public:
	void executeOnServer(TransactionMonitorServer* monitorServer, BufferedOutputStream* outStream, ThreadContext* ctx) final;
	void readFromStream(InputStream* stream, int remain, ThreadContext* ctx) final;
	long long getNodeClusterRevision(ThreadContext* ctx) throw() ;
	void setNodeClusterRevision(long long nodeClusterRevision, ThreadContext* ctx) throw() ;
	void writeByteStream(OutputStream* out, ThreadContext* ctx) final;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx);
};

}}}}}}

#endif /* end of ALINOUS_REMOTE_MONITOR_CLIENT_COMMAND_COMMITID_REPORTCLUSTERVERSIONUPCOMMAND_H_ */
