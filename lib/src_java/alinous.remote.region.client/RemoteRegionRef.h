#ifndef ALINOUS_REMOTE_REGION_CLIENT_REMOTEREGIONREF_H_
#define ALINOUS_REMOTE_REGION_CLIENT_REMOTEREGIONREF_H_
namespace alinous {namespace system {namespace config {namespace remote {
class RegionRef;}}}}

namespace alinous {namespace db {
class ICommidIdPublisher;}}

namespace alinous {namespace db {
class AlinousDbException;}}

namespace java {namespace lang {
class NumberFormatException;}}

namespace alinous {namespace remote {namespace region {namespace client {
class RegionConnectionInfo;}}}}

namespace alinous {namespace remote {namespace region {namespace client {
class RegionClientConnectionFactory;}}}}

namespace alinous {namespace remote {namespace socket {
class SocketConnectionPool;}}}

namespace alinous {namespace remote {namespace region {namespace command {
class GetSchemaFromRegionCommand;}}}}

namespace alinous {namespace remote {namespace socket {
class ISocketConnection;}}}

namespace alinous {namespace net {
class AlinousSocket;}}

namespace alinous {namespace remote {namespace region {namespace command {
class AbstractNodeRegionCommand;}}}}

namespace alinous {namespace system {
class AlinousException;}}

namespace alinous {namespace remote {namespace region {namespace command {namespace data {
class ClientStructureMetadata;}}}}}

namespace java {namespace util {
template <typename  T, typename V> class Map;}}

namespace alinous {namespace remote {namespace region {namespace command {namespace data {
class ClientSchemaData;}}}}}

namespace java {namespace util {
template <typename  T> class Iterator;}}

namespace alinous {namespace remote {namespace region {namespace client {
class RemoteTableScheme;}}}}

namespace alinous {namespace db {
class ITableSchema;}}

namespace alinous {namespace remote {namespace region {namespace command {namespace ddl {
class RegionCreateSchemaCommand;}}}}}

namespace alinous {namespace net {
class UnknownHostException;}}

namespace java {namespace io {
class IOException;}}

namespace alinous {namespace db {namespace table {
class TableMetadata;}}}

namespace alinous {namespace runtime {namespace parallel {
class ThreadPool;}}}

namespace alinous {namespace system {
class AlinousCore;}}

namespace alinous {namespace btree {
class BTreeGlobalCache;}}

namespace alinous {namespace remote {namespace region {namespace command {namespace ddl {
class RegionCreateTableCommand;}}}}}

namespace alinous {namespace lock {
class LockObject;}}

namespace java {namespace util {
template <typename  T, typename V> class HashMap;}}

namespace alinous {namespace db {
class ITableRegion;}}

namespace alinous {namespace btree {
class BTreeException;}}

namespace alinous {namespace db {namespace table {
class DatabaseException;}}}

namespace java {namespace lang {
class IObject;
}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace remote {namespace region {namespace client {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::java::io::IOException;
using ::java::net::UnknownHostException;
using ::java::util::HashMap;
using ::java::util::Iterator;
using ::java::util::Map;
using ::alinous::btree::BTreeException;
using ::alinous::btree::BTreeGlobalCache;
using ::alinous::db::AlinousDbException;
using ::alinous::db::ICommidIdPublisher;
using ::alinous::db::ITableRegion;
using ::alinous::db::ITableSchema;
using ::alinous::db::table::DatabaseException;
using ::alinous::db::table::TableMetadata;
using ::alinous::lock::LockObject;
using ::alinous::net::AlinousSocket;
using ::alinous::remote::region::command::AbstractNodeRegionCommand;
using ::alinous::remote::region::command::GetSchemaFromRegionCommand;
using ::alinous::remote::region::command::data::ClientSchemaData;
using ::alinous::remote::region::command::data::ClientStructureMetadata;
using ::alinous::remote::region::command::ddl::RegionCreateSchemaCommand;
using ::alinous::remote::region::command::ddl::RegionCreateTableCommand;
using ::alinous::remote::socket::ISocketConnection;
using ::alinous::remote::socket::SocketConnectionPool;
using ::alinous::runtime::parallel::ThreadPool;
using ::alinous::system::AlinousCore;
using ::alinous::system::AlinousException;
using ::alinous::system::config::remote::RegionRef;



class RemoteRegionRef final : public ITableRegion, public virtual IObject {
public:
	RemoteRegionRef(const RemoteRegionRef& base) = default;
public:
	RemoteRegionRef(RegionRef* ref, ICommidIdPublisher* commitIdPublisher, ThreadContext* ctx) throw() ;
	void __construct_impl(RegionRef* ref, ICommidIdPublisher* commitIdPublisher, ThreadContext* ctx) throw() ;
	virtual ~RemoteRegionRef() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	SocketConnectionPool* regionAccessPool;
	String* url;
	String* name;
	RegionConnectionInfo* info;
	LockObject* schemeLock;
	Map<String,RemoteTableScheme>* schemes;
	long long schemeVersion;
public:
	void init(ThreadContext* ctx);
	void dispose(ThreadContext* ctx) throw()  final;
	void syncSchemes(ThreadContext* ctx) final;
	int getRegionType(ThreadContext* ctx) throw()  final;
	String* getRegionName(ThreadContext* ctx) throw()  final;
	ITableSchema* getSchema(String* name, ThreadContext* ctx) throw()  final;
	void createSchema(String* schemaName, ThreadContext* ctx) final;
	void createTable(String* schemaName, TableMetadata* tblMeta, ThreadPool* threadPool, AlinousCore* core, BTreeGlobalCache* cache, ThreadContext* ctx) final;
	long long getSchemeVersion(ThreadContext* ctx) throw() ;
	void setSchemeVersion(long long schemeVersion, ThreadContext* ctx) throw() ;
private:
	void initRegionServerAcess(ThreadContext* ctx);
	void synschemeData(ClientStructureMetadata* data, ThreadContext* ctx) throw() ;
	RemoteTableScheme* findOrCreateSchema(String* schemaName, ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}}}

#endif /* end of ALINOUS_REMOTE_REGION_CLIENT_REMOTEREGIONREF_H_ */
