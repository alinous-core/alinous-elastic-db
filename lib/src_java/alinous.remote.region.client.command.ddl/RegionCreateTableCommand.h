#ifndef ALINOUS_REMOTE_REGION_CLIENT_COMMAND_DDL_REGIONCREATETABLECOMMAND_H_
#define ALINOUS_REMOTE_REGION_CLIENT_COMMAND_DDL_REGIONCREATETABLECOMMAND_H_
namespace alinous {namespace remote {namespace region {namespace server {
class NodeRegionServer;}}}}

namespace java {namespace io {
class BufferedOutputStream;}}

namespace alinous {namespace system {
class AlinousCore;}}

namespace alinous {namespace system {
class AlinousException;}}

namespace java {namespace io {
class OutputStream;}}

namespace alinous {namespace remote {namespace socket {
class NetworkBinaryBuffer;}}}

namespace java {namespace io {
class InputStream;}}

namespace java {namespace io {
class IOException;}}

namespace alinous {namespace runtime {namespace dom {
class VariableException;}}}

namespace alinous {namespace db {namespace table {
class TableMetadata;}}}

namespace alinous {namespace remote {namespace region {namespace client {namespace command {
class AbstractNodeRegionCommand;}}}}}

namespace alinous {namespace remote {namespace region {namespace client {namespace command {
class NodeRegionConnectCommand;}}}}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace remote {namespace region {namespace client {namespace command {namespace ddl {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::java::io::BufferedOutputStream;
using ::java::io::IOException;
using ::java::io::InputStream;
using ::java::io::OutputStream;
using ::alinous::db::table::TableMetadata;
using ::alinous::remote::region::client::command::AbstractNodeRegionCommand;
using ::alinous::remote::region::client::command::NodeRegionConnectCommand;
using ::alinous::remote::region::server::NodeRegionServer;
using ::alinous::remote::socket::NetworkBinaryBuffer;
using ::alinous::runtime::dom::VariableException;
using ::alinous::system::AlinousCore;
using ::alinous::system::AlinousException;



class RegionCreateTableCommand final : public AbstractNodeRegionCommand {
public:
	RegionCreateTableCommand(const RegionCreateTableCommand& base) = default;
public:
	RegionCreateTableCommand(ThreadContext* ctx) throw() ;
	void __construct_impl(ThreadContext* ctx) throw() ;
	virtual ~RegionCreateTableCommand() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	TableMetadata* metadata;
public:
	void executeOnServer(NodeRegionServer* nodeRegionServer, BufferedOutputStream* outStream, ThreadContext* ctx) final;
	void readFromStream(InputStream* stream, int remain, ThreadContext* ctx) final;
	TableMetadata* getMetadata(ThreadContext* ctx) throw() ;
	void setMetadata(TableMetadata* metadata, ThreadContext* ctx) throw() ;
	void writeByteStream(OutputStream* outStream, ThreadContext* ctx) final;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx);
};

}}}}}}

#endif /* end of ALINOUS_REMOTE_REGION_CLIENT_COMMAND_DDL_REGIONCREATETABLECOMMAND_H_ */
