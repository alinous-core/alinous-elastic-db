#ifndef ALINOUS_REMOTE_REGION_COMMAND_DDL_REGIONCREATETABLECOMMAND_H_
#define ALINOUS_REMOTE_REGION_COMMAND_DDL_REGIONCREATETABLECOMMAND_H_
namespace alinous {namespace remote {namespace region {
class NodeRegionServer;}}}

namespace java {namespace io {
class BufferedOutputStream;}}

namespace java {namespace io {
class OutputStream;}}

namespace alinous {namespace remote {namespace socket {
class NetworkBinaryBuffer;}}}

namespace java {namespace io {
class InputStream;}}

namespace alinous {namespace remote {namespace region {namespace command {
class AbstractNodeRegionCommand;}}}}

namespace java {namespace io {
class IOException;}}

namespace alinous {namespace remote {namespace region {namespace command {
class NodeRegionConnectCommand;}}}}

namespace alinous {namespace runtime {namespace dom {
class VariableException;}}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace remote {namespace region {namespace command {namespace ddl {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::java::io::BufferedOutputStream;
using ::java::io::IOException;
using ::java::io::InputStream;
using ::java::io::OutputStream;
using ::alinous::remote::region::NodeRegionServer;
using ::alinous::remote::region::command::AbstractNodeRegionCommand;
using ::alinous::remote::region::command::NodeRegionConnectCommand;
using ::alinous::remote::socket::NetworkBinaryBuffer;
using ::alinous::runtime::dom::VariableException;



class RegionCreateTableCommand final : public AbstractNodeRegionCommand {
public:
	RegionCreateTableCommand(const RegionCreateTableCommand& base) = default;
public:
	RegionCreateTableCommand(ThreadContext* ctx) throw() ;
	void __construct_impl(ThreadContext* ctx) throw() ;
	virtual ~RegionCreateTableCommand() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
public:
	void executeOnServer(NodeRegionServer* nodeRegionServer, BufferedOutputStream* outStream, ThreadContext* ctx) final;
	void readFromStream(InputStream* stream, int remain, ThreadContext* ctx) final;
	void writeByteStream(OutputStream* out, ThreadContext* ctx) final;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}}}}

#endif /* end of ALINOUS_REMOTE_REGION_COMMAND_DDL_REGIONCREATETABLECOMMAND_H_ */
