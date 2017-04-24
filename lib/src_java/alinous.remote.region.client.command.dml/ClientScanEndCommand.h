#ifndef ALINOUS_REMOTE_REGION_CLIENT_COMMAND_DML_CLIENTSCANENDCOMMAND_H_
#define ALINOUS_REMOTE_REGION_CLIENT_COMMAND_DML_CLIENTSCANENDCOMMAND_H_
namespace alinous {namespace remote {namespace region {namespace server {
class NodeRegionServer;}}}}

namespace java {namespace io {
class BufferedOutputStream;}}

namespace java {namespace io {
class OutputStream;}}

namespace alinous {namespace remote {namespace socket {
class NetworkBinaryBuffer;}}}

namespace java {namespace io {
class InputStream;}}

namespace alinous {namespace remote {namespace region {namespace client {namespace command {
class AbstractNodeRegionCommand;}}}}}

namespace java {namespace io {
class IOException;}}

namespace alinous {namespace runtime {namespace dom {
class VariableException;}}}

namespace alinous {namespace system {
class AlinousException;}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace remote {namespace region {namespace client {namespace command {namespace dml {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::java::io::BufferedOutputStream;
using ::java::io::IOException;
using ::java::io::InputStream;
using ::java::io::OutputStream;
using ::alinous::remote::region::client::command::AbstractNodeRegionCommand;
using ::alinous::remote::region::server::NodeRegionServer;
using ::alinous::remote::socket::NetworkBinaryBuffer;
using ::alinous::runtime::dom::VariableException;
using ::alinous::system::AlinousException;



class ClientScanEndCommand final : public AbstractNodeRegionCommand {
public:
	ClientScanEndCommand(const ClientScanEndCommand& base) = default;
public:
	ClientScanEndCommand(ThreadContext* ctx) throw() ;
	void __construct_impl(ThreadContext* ctx) throw() ;
	virtual ~ClientScanEndCommand() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	long long trxId;
public:
	void executeOnServer(NodeRegionServer* nodeRegionServer, BufferedOutputStream* outStream, ThreadContext* ctx) final;
	void readFromStream(InputStream* stream, int remain, ThreadContext* ctx) final;
	long long getTrxId(ThreadContext* ctx) throw() ;
	void setTrxId(long long trxId, ThreadContext* ctx) throw() ;
	void writeByteStream(OutputStream* outStream, ThreadContext* ctx) final;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx);
};

}}}}}}

#endif /* end of ALINOUS_REMOTE_REGION_CLIENT_COMMAND_DML_CLIENTSCANENDCOMMAND_H_ */
