#ifndef ALINOUS_REMOTE_REGION_NODEREGIONRESPONCEACTION_H_
#define ALINOUS_REMOTE_REGION_NODEREGIONRESPONCEACTION_H_
namespace alinous {namespace remote {namespace region {
class NodeRegionServer;}}}

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

namespace alinous {namespace remote {namespace region {namespace command {
class AbstractNodeRegionCommand;}}}}

namespace alinous {namespace system {
class AlinousException;}}

namespace alinous {namespace runtime {namespace parallel {
class IThreadAction;}}}

namespace java {namespace io {
class IOException;}}

namespace alinous {namespace remote {namespace region {namespace command {
class NodeRegionCommandReader;}}}}

namespace java {namespace lang {
class IObject;
}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace remote {namespace region {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::java::io::BufferedInputStream;
using ::java::io::BufferedOutputStream;
using ::java::io::IOException;
using ::java::io::InputStream;
using ::java::io::OutputStream;
using ::java::net::Socket;
using ::alinous::remote::region::command::AbstractNodeRegionCommand;
using ::alinous::remote::region::command::NodeRegionCommandReader;
using ::alinous::remote::socket::SocketServer;
using ::alinous::runtime::parallel::IThreadAction;
using ::alinous::system::AlinousException;



class NodeRegionResponceAction final : public IThreadAction, public virtual IObject {
public:
	NodeRegionResponceAction(const NodeRegionResponceAction& base) = default;
public:
	NodeRegionResponceAction(NodeRegionServer* nodeRegionServer, Socket* socket, SocketServer* server, ThreadContext* ctx) throw() ;
	void __construct_impl(NodeRegionServer* nodeRegionServer, Socket* socket, SocketServer* server, ThreadContext* ctx) throw() ;
	virtual ~NodeRegionResponceAction() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	Socket* socket;
	SocketServer* server;
	NodeRegionServer* nodeRegionServer;
public:
	void execute(ThreadContext* ctx) final;
private:
	void handleCommand(BufferedInputStream* stream, BufferedOutputStream* outStream, ThreadContext* ctx);
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}}

#endif /* end of ALINOUS_REMOTE_REGION_NODEREGIONRESPONCEACTION_H_ */
