#ifndef ALINOUS_REMOTE_MONITOR_MONITORRESPONCEACTION_H_
#define ALINOUS_REMOTE_MONITOR_MONITORRESPONCEACTION_H_
namespace alinous {namespace remote {namespace monitor {
class TransactionMonitorServer;}}}

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

namespace alinous {namespace remote {namespace monitor {namespace client {namespace command {
class AbstractMonitorCommand;}}}}}

namespace alinous {namespace system {
class AlinousException;}}

namespace alinous {namespace runtime {namespace parallel {
class IThreadAction;}}}

namespace java {namespace io {
class IOException;}}

namespace alinous {namespace remote {namespace monitor {namespace client {namespace command {
class MinitorCommandReader;}}}}}

namespace alinous {namespace runtime {namespace dom {
class VariableException;}}}

namespace java {namespace lang {
class IObject;
}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace remote {namespace monitor {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::java::io::BufferedInputStream;
using ::java::io::BufferedOutputStream;
using ::java::io::IOException;
using ::java::io::InputStream;
using ::java::io::OutputStream;
using ::java::net::Socket;
using ::alinous::remote::monitor::client::command::AbstractMonitorCommand;
using ::alinous::remote::monitor::client::command::MinitorCommandReader;
using ::alinous::remote::socket::SocketServer;
using ::alinous::runtime::dom::VariableException;
using ::alinous::runtime::parallel::IThreadAction;
using ::alinous::system::AlinousException;



class MonitorResponceAction final : public IThreadAction, public virtual IObject {
public:
	MonitorResponceAction(const MonitorResponceAction& base) = default;
public:
	MonitorResponceAction(TransactionMonitorServer* monitorServer, Socket* socket, SocketServer* server, ThreadContext* ctx) throw() ;
	void __construct_impl(TransactionMonitorServer* monitorServer, Socket* socket, SocketServer* server, ThreadContext* ctx) throw() ;
	virtual ~MonitorResponceAction() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	Socket* socket;
	SocketServer* server;
	TransactionMonitorServer* monitorServer;
public:
	void execute(ThreadContext* ctx) final;
private:
	void handleCommand(BufferedInputStream* stream, BufferedOutputStream* outStream, ThreadContext* ctx);
	void handleCommand(AbstractMonitorCommand* cmd, BufferedOutputStream* outStream, ThreadContext* ctx);
	AbstractMonitorCommand* parseCommand(BufferedInputStream* stream, ThreadContext* ctx);
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx);
};

}}}

#endif /* end of ALINOUS_REMOTE_MONITOR_MONITORRESPONCEACTION_H_ */
