#ifndef ALINOUS_REMOTE_REGION_SERVER_SCHEMA_NODEREFERENCE_H_
#define ALINOUS_REMOTE_REGION_SERVER_SCHEMA_NODEREFERENCE_H_
namespace java{namespace net{
class UnknownHostException;
}}
namespace alinous {namespace remote {namespace db {namespace client {
class RemoteStorageConnectionInfo;}}}}

namespace alinous {namespace remote {namespace db {namespace client {
class RemoteStorageClientConnectionFactory;}}}}

namespace alinous {namespace remote {namespace socket {
class SocketConnectionPool;}}}

namespace alinous {namespace remote {namespace db {namespace client {namespace command {namespace data {
class SchemasStructureInfoData;}}}}}}

namespace alinous {namespace remote {namespace db {namespace client {namespace command {
class GetTableSchemeCommand;}}}}}

namespace alinous {namespace remote {namespace socket {
class ISocketConnection;}}}

namespace alinous {namespace net {
class AlinousSocket;}}

namespace alinous {namespace remote {namespace db {namespace client {namespace command {
class AbstractRemoteStorageCommand;}}}}}

namespace alinous {namespace system {
class AlinousException;}}

namespace java {namespace io {
class IOException;}}

namespace alinous {namespace remote {namespace db {namespace client {namespace command {namespace ddl {
class CreateSchemaCommand;}}}}}}

namespace alinous {namespace db {namespace table {
class TableMetadata;}}}

namespace alinous {namespace remote {namespace db {namespace client {namespace command {namespace ddl {
class CreateTableCommand;}}}}}}

namespace alinous {namespace remote {namespace region {namespace server {namespace schema {
class NodeReference;}}}}}

namespace java {namespace lang {
class IObject;
}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace remote {namespace region {namespace server {namespace schema {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::java::io::IOException;
using ::java::net::UnknownHostException;
using ::alinous::db::table::TableMetadata;
using ::alinous::net::AlinousSocket;
using ::alinous::remote::db::client::RemoteStorageClientConnectionFactory;
using ::alinous::remote::db::client::RemoteStorageConnectionInfo;
using ::alinous::remote::db::client::command::AbstractRemoteStorageCommand;
using ::alinous::remote::db::client::command::GetTableSchemeCommand;
using ::alinous::remote::db::client::command::data::SchemasStructureInfoData;
using ::alinous::remote::db::client::command::ddl::CreateSchemaCommand;
using ::alinous::remote::db::client::command::ddl::CreateTableCommand;
using ::alinous::remote::socket::ISocketConnection;
using ::alinous::remote::socket::SocketConnectionPool;
using ::alinous::system::AlinousException;



class NodeReference final : public virtual IObject {
public:
	NodeReference(const NodeReference& base) = default;
public:
	NodeReference(String* host, int port, bool ipv6, ThreadContext* ctx) throw() ;
	void __construct_impl(String* host, int port, bool ipv6, ThreadContext* ctx) throw() ;
	virtual ~NodeReference() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	String* host;
	int port;
	bool ipv6;
	SocketConnectionPool* nodeConnectionPool;
public:
	void initConnectionPool(ThreadContext* ctx) throw() ;
	void dispose(ThreadContext* ctx) throw() ;
	SchemasStructureInfoData* getSchemeInfo(String* region, ThreadContext* ctx);
	void createSchema(String* schemaName, ThreadContext* ctx);
	void createTable(TableMetadata* meta, ThreadContext* ctx);
	String* getHost(ThreadContext* ctx) throw() ;
	int getPort(ThreadContext* ctx) throw() ;
	bool isIpv6(ThreadContext* ctx) throw() ;
	bool equals(String* host, int port, bool ipv6, ThreadContext* ctx) throw() ;
	bool equals(IObject* obj, ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx);
};

}}}}}

#endif /* end of ALINOUS_REMOTE_REGION_SERVER_SCHEMA_NODEREFERENCE_H_ */
