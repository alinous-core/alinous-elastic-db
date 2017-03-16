#ifndef ALINOUS_REMOTE_REGION_SERVER_NODEREGIONSERVER_H_
#define ALINOUS_REMOTE_REGION_SERVER_NODEREGIONSERVER_H_
namespace java{namespace net{
class UnknownHostException;
}}
namespace alinous {namespace system {
class AlinousCore;}}

namespace alinous {namespace remote {namespace region {namespace server {namespace schema {
class NodeReferenceManager;}}}}}

namespace java {namespace lang {
class Throwable;}}

namespace alinous {namespace system {
class ISystemLog;}}

namespace alinous {namespace system {namespace config {namespace remote {
class RegionsServer;}}}}

namespace alinous {namespace system {namespace config {namespace remote {
class MonitorRef;}}}}

namespace alinous {namespace remote {namespace region {namespace client {namespace command {namespace data {
class ClientStructureMetadata;}}}}}}

namespace alinous {namespace remote {namespace monitor {namespace client {namespace command {
class GetRegionNodeInfoCommand;}}}}}

namespace alinous {namespace remote {namespace socket {
class ISocketConnection;}}}

namespace alinous {namespace net {
class AlinousSocket;}}

namespace alinous {namespace remote {namespace monitor {namespace client {namespace command {
class AbstractMonitorCommand;}}}}}

namespace alinous {namespace system {
class AlinousException;}}

namespace alinous {namespace remote {namespace monitor {namespace client {namespace command {namespace data {
class RegionInfoData;}}}}}}

namespace alinous {namespace remote {namespace monitor {namespace client {
class MonitorConnectionInfo;}}}}

namespace alinous {namespace remote {namespace monitor {namespace client {
class MonitorClientConnectionFactory;}}}}

namespace alinous {namespace remote {namespace socket {
class SocketConnectionPool;}}}

namespace alinous {namespace remote {namespace region {namespace server {
class NodeRegionResponceActionFactory;}}}}

namespace alinous {namespace remote {namespace socket {
class SocketServer;}}}

namespace alinous {namespace db {namespace table {
class TableMetadata;}}}

namespace alinous {namespace remote {namespace region {namespace client {namespace command {namespace data {
class ClientNetworkRecord;}}}}}}

namespace alinous {namespace db {namespace trx {
class DbVersionContext;}}}

namespace alinous {namespace remote {namespace region {namespace server {namespace tpc {
class RegionInsertExecutor;}}}}}

namespace alinous {namespace remote {namespace monitor {namespace client {namespace command {namespace commitId {
class ReportClusterVersionUpCommand;}}}}}}

namespace java {namespace io {
class IOException;}}

namespace alinous {namespace lock {
class LockObject;}}

namespace alinous {namespace remote {namespace region {namespace server {namespace tpc {
class RegionTpcExecutorPool;}}}}}

namespace java {namespace lang {
class IObject;
}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace remote {namespace region {namespace server {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::java::io::IOException;
using ::java::net::UnknownHostException;
using ::java::util::ArrayList;
using ::alinous::db::table::TableMetadata;
using ::alinous::db::trx::DbVersionContext;
using ::alinous::lock::LockObject;
using ::alinous::net::AlinousSocket;
using ::alinous::remote::monitor::client::MonitorClientConnectionFactory;
using ::alinous::remote::monitor::client::MonitorConnectionInfo;
using ::alinous::remote::monitor::client::command::AbstractMonitorCommand;
using ::alinous::remote::monitor::client::command::GetRegionNodeInfoCommand;
using ::alinous::remote::monitor::client::command::commitId::ReportClusterVersionUpCommand;
using ::alinous::remote::monitor::client::command::data::RegionInfoData;
using ::alinous::remote::region::client::command::data::ClientNetworkRecord;
using ::alinous::remote::region::client::command::data::ClientStructureMetadata;
using ::alinous::remote::region::server::schema::NodeReferenceManager;
using ::alinous::remote::region::server::tpc::RegionInsertExecutor;
using ::alinous::remote::region::server::tpc::RegionTpcExecutorPool;
using ::alinous::remote::socket::ISocketConnection;
using ::alinous::remote::socket::SocketConnectionPool;
using ::alinous::remote::socket::SocketServer;
using ::alinous::system::AlinousCore;
using ::alinous::system::AlinousException;
using ::alinous::system::ISystemLog;
using ::alinous::system::config::remote::MonitorRef;
using ::alinous::system::config::remote::RegionsServer;



class NodeRegionServer final : public virtual IObject {
public:
	NodeRegionServer(const NodeRegionServer& base) = default;
public:
	NodeRegionServer(int port, int maxthread, AlinousCore* core, ThreadContext* ctx) throw() ;
	void __construct_impl(int port, int maxthread, AlinousCore* core, ThreadContext* ctx) throw() ;
	virtual ~NodeRegionServer() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	int port;
	int maxthread;
	NodeReferenceManager* refs;
	SocketServer* socketServer;
	SocketConnectionPool* monitorConnectionPool;
	LockObject* nodeClusterRevisionLock;
	long long nodeClusterRevision;
	String* region;
	AlinousCore* core;
	RegionTpcExecutorPool* insertSessions;
private:
	static String* THREAD_NAME;
public:
	AlinousCore* getCore(ThreadContext* ctx) throw() ;
	void logError(Throwable* e, ThreadContext* ctx) throw() ;
	void initNodes(RegionsServer* srvconf, ThreadContext* ctx);
	long long getClientData(ClientStructureMetadata* data, ThreadContext* ctx);
	void syncScheme(ThreadContext* ctx);
	void syncNodes(ThreadContext* ctx);
	void start(ISystemLog* logger, ThreadContext* ctx) throw() ;
	void dispose(ThreadContext* ctx) throw() ;
	NodeReferenceManager* getRefs(ThreadContext* ctx) throw() ;
	void createSchema(String* schemaName, ThreadContext* ctx);
	void createTable(TableMetadata* metadata, ThreadContext* ctx);
	void insertData(ArrayList<ClientNetworkRecord>* list, long long newCommitId, String* schema, String* table, DbVersionContext* vctx, ThreadContext* ctx);
	void commitUpdateData(long long trxId, ThreadContext* ctx) throw() ;
private:
	void initMonitorRef(MonitorRef* monRef, ThreadContext* ctx) throw() ;
	void checkVersion(DbVersionContext* vctx, ThreadContext* ctx);
	void reportClusterUpdate(ThreadContext* ctx);
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx);
};

}}}}

#endif /* end of ALINOUS_REMOTE_REGION_SERVER_NODEREGIONSERVER_H_ */
