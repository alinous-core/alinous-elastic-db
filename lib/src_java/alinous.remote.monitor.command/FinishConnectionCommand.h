#ifndef ALINOUS_REMOTE_MONITOR_COMMAND_FINISHCONNECTIONCOMMAND_H_
#define ALINOUS_REMOTE_MONITOR_COMMAND_FINISHCONNECTIONCOMMAND_H_
namespace java {namespace io {
class InputStream;}}

namespace java {namespace io {
class OutputStream;}}

namespace alinous {namespace remote {namespace socket {
class NetworkBinaryBuffer;}}}

namespace alinous {namespace remote {namespace monitor {
class TransactionMonitorServer;}}}

namespace java {namespace io {
class BufferedOutputStream;}}

namespace alinous {namespace remote {namespace monitor {namespace command {
class AbstractMonitorCommand;}}}}

namespace java {namespace io {
class IOException;}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace remote {namespace monitor {namespace command {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::java::io::BufferedOutputStream;
using ::java::io::IOException;
using ::java::io::InputStream;
using ::java::io::OutputStream;
using ::alinous::remote::monitor::TransactionMonitorServer;
using ::alinous::remote::socket::NetworkBinaryBuffer;



class FinishConnectionCommand final : public AbstractMonitorCommand {
public:
	FinishConnectionCommand(const FinishConnectionCommand& base) = default;
public:
	FinishConnectionCommand(ThreadContext* ctx) throw() ;
	void __construct_impl(ThreadContext* ctx) throw() ;
	virtual ~FinishConnectionCommand() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
public:
	void readFromStream(InputStream* stream, int remain, ThreadContext* ctx) final;
	void executeOnServer(TransactionMonitorServer* monitorServer, BufferedOutputStream* outStream, ThreadContext* ctx) final;
	void writeByteStream(OutputStream* out, ThreadContext* ctx) final;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}}}

#endif /* end of ALINOUS_REMOTE_MONITOR_COMMAND_FINISHCONNECTIONCOMMAND_H_ */
