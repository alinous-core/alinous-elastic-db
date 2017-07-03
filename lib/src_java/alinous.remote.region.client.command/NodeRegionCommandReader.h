#ifndef ALINOUS_REMOTE_REGION_CLIENT_COMMAND_NODEREGIONCOMMANDREADER_H_
#define ALINOUS_REMOTE_REGION_CLIENT_COMMAND_NODEREGIONCOMMANDREADER_H_
namespace alinous {namespace remote {namespace region {namespace client {namespace command {
class AbstractNodeRegionCommand;}}}}}

namespace java {namespace io {
class InputStream;}}

namespace alinous {namespace remote {namespace region {namespace client {namespace command {
class NodeRegionFinishConnectionCommand;}}}}}

namespace alinous {namespace remote {namespace region {namespace client {namespace command {
class NodeRegionTerminateCommand;}}}}}

namespace alinous {namespace remote {namespace region {namespace client {namespace command {
class NodeRegionVoidCommand;}}}}}

namespace alinous {namespace remote {namespace region {namespace client {namespace command {
class NodeRegionConnectCommand;}}}}}

namespace alinous {namespace remote {namespace region {namespace client {namespace command {
class GetSchemaFromRegionCommand;}}}}}

namespace alinous {namespace remote {namespace region {namespace client {namespace command {namespace ddl {
class RegionCreateSchemaCommand;}}}}}}

namespace alinous {namespace remote {namespace region {namespace client {namespace command {namespace ddl {
class RegionCreateTableCommand;}}}}}}

namespace alinous {namespace remote {namespace region {namespace client {namespace command {namespace dml {
class ClientInsertDataCommand;}}}}}}

namespace alinous {namespace remote {namespace region {namespace client {namespace command {namespace dml {
class ClientTpcCommitSessionCommand;}}}}}}

namespace alinous {namespace remote {namespace region {namespace client {namespace command {namespace dml {
class ClientScanCommand;}}}}}}

namespace alinous {namespace remote {namespace region {namespace client {namespace command {namespace dml {
class ClientScanEndCommand;}}}}}}

namespace alinous {namespace remote {namespace region {namespace client {namespace command {namespace dml {
class ClientClearSelectSessionCommand;}}}}}}

namespace alinous {namespace system {
class AlinousException;}}

namespace java {namespace io {
class IOException;}}

namespace alinous {namespace remote {namespace socket {
class NetworkBinalyUtils;}}}

namespace java {namespace lang {
class IObject;
}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace remote {namespace region {namespace client {namespace command {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::java::io::IOException;
using ::java::io::InputStream;
using ::alinous::remote::region::client::command::ddl::RegionCreateSchemaCommand;
using ::alinous::remote::region::client::command::ddl::RegionCreateTableCommand;
using ::alinous::remote::region::client::command::dml::ClientClearSelectSessionCommand;
using ::alinous::remote::region::client::command::dml::ClientInsertDataCommand;
using ::alinous::remote::region::client::command::dml::ClientScanCommand;
using ::alinous::remote::region::client::command::dml::ClientScanEndCommand;
using ::alinous::remote::region::client::command::dml::ClientTpcCommitSessionCommand;
using ::alinous::remote::socket::NetworkBinalyUtils;
using ::alinous::system::AlinousException;



class NodeRegionCommandReader final : public virtual IObject {
public:
	NodeRegionCommandReader(const NodeRegionCommandReader& base) = default;
public:
	NodeRegionCommandReader(ThreadContext* ctx) throw() ;
	void __construct_impl(ThreadContext* ctx) throw() ;
	virtual ~NodeRegionCommandReader() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
public:
	static AbstractNodeRegionCommand* readFromStream(InputStream* stream, ThreadContext* ctx);
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx);
};

}}}}}

#endif /* end of ALINOUS_REMOTE_REGION_CLIENT_COMMAND_NODEREGIONCOMMANDREADER_H_ */
