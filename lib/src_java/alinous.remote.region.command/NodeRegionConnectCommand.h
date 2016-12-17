#ifndef ALINOUS_REMOTE_REGION_COMMAND_NODEREGIONCONNECTCOMMAND_H_
#define ALINOUS_REMOTE_REGION_COMMAND_NODEREGIONCONNECTCOMMAND_H_
namespace java {namespace io {
class OutputStream;}}

namespace java {namespace nio {
class ByteBuffer;}}

namespace java {namespace io {
class InputStream;}}

namespace alinous {namespace remote {namespace region {
class NodeRegionServer;}}}

namespace java {namespace io {
class BufferedOutputStream;}}

namespace alinous {namespace remote {namespace region {namespace command {
class AbstractNodeRegionCommand;}}}}

namespace java {namespace io {
class IOException;}}

namespace alinous {namespace remote {namespace socket {
class NetworkBinalyUtils;}}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace remote {namespace region {namespace command {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::java::io::BufferedOutputStream;
using ::java::io::IOException;
using ::java::io::InputStream;
using ::java::io::OutputStream;
using ::java::nio::ByteBuffer;
using ::alinous::remote::region::NodeRegionServer;
using ::alinous::remote::socket::NetworkBinalyUtils;



class NodeRegionConnectCommand final : public AbstractNodeRegionCommand {
public:
	NodeRegionConnectCommand(const NodeRegionConnectCommand& base) = default;
public:
	NodeRegionConnectCommand(ThreadContext* ctx) throw() ;
	void __construct_impl(ThreadContext* ctx) throw() ;
	virtual ~NodeRegionConnectCommand() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	bool connected;
	int size;
public:
	void readFromStream(InputStream* stream, ThreadContext* ctx) final;
	void executeOnServer(NodeRegionServer* nodeRegionServer, BufferedOutputStream* outStream, ThreadContext* ctx) final;
	bool isConnected(ThreadContext* ctx) throw() ;
	void writeByteStream(OutputStream* out, ThreadContext* ctx) final;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}}}

#endif /* end of ALINOUS_REMOTE_REGION_COMMAND_NODEREGIONCONNECTCOMMAND_H_ */
