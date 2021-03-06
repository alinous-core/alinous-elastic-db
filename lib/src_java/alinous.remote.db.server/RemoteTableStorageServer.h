#ifndef ALINOUS_REMOTE_DB_SERVER_REMOTETABLESTORAGESERVER_H_
#define ALINOUS_REMOTE_DB_SERVER_REMOTETABLESTORAGESERVER_H_
namespace alinous {namespace remote {namespace db {namespace server {namespace trx {
class StorageTransactionManager;}}}}}

namespace alinous {namespace lock {namespace unique {
class UniqueExclusiveLockManager;}}}

namespace alinous {namespace remote {namespace db {namespace server {namespace scan {
class StorageScanSessionManager;}}}}}

namespace alinous {namespace system {
class AlinousCore;}}

namespace alinous {namespace system {namespace config {namespace remote {
class MonitorRef;}}}}

namespace java {namespace io {
class File;}}

namespace alinous {namespace btree {
class BTreeGlobalCache;}}

namespace alinous {namespace system {namespace config {
class AlinousInitException;}}}

namespace alinous {namespace btree {
class BTreeException;}}

namespace alinous {namespace runtime {namespace parallel {
class ThreadPool;}}}

namespace alinous {namespace remote {namespace db {
class MonitorAccess;}}}

namespace alinous {namespace db {
class SchemaManager;}}

namespace alinous {namespace btree {
class BTree;}}

namespace alinous {namespace btree {
class IBTreeValue;}}

namespace alinous {namespace btree {
class LongValue;}}

namespace alinous {namespace db {
class AlinousDbException;}}

namespace java {namespace io {
class IOException;}}

namespace java {namespace lang {
class InterruptedException;}}

namespace alinous {namespace runtime {namespace dom {
class VariableException;}}}

namespace alinous {namespace system {
class AlinousException;}}

namespace alinous {namespace db {namespace table {
class DatabaseException;}}}

namespace alinous {namespace remote {namespace db {
class RemoteStorageResponceActionFactory;}}}

namespace alinous {namespace remote {namespace socket {
class SocketServer;}}}

namespace java {namespace lang {
class Throwable;}}

namespace alinous {namespace system {
class ISystemLog;}}

namespace alinous {namespace remote {namespace db {namespace client {namespace command {namespace data {
class SchemasStructureInfoData;}}}}}}

namespace alinous {namespace db {namespace table {
class TableMetadata;}}}

namespace java {namespace util {
template <typename  T> class List;}}

namespace alinous {namespace remote {namespace region {namespace server {namespace schema {namespace strategy {
class UniqueCheckOperation;}}}}}}

namespace alinous {namespace remote {namespace region {namespace client {namespace command {namespace data {
class ClientNetworkRecord;}}}}}}

namespace alinous {namespace db {namespace trx {
class DbVersionContext;}}}

namespace alinous {namespace db {
class TableSchema;}}

namespace alinous {namespace db {namespace table {
class IDatabaseTable;}}}

namespace alinous {namespace remote {namespace db {namespace server {namespace trx {
class StorageTransaction;}}}}}

namespace alinous {namespace remote {namespace region {namespace server {namespace scan {
class ScanWorkerResult;}}}}}

namespace alinous {namespace remote {namespace region {namespace client {namespace command {namespace dml {
class ClientScanCommandData;}}}}}}

namespace alinous {namespace compile {namespace sql {
class TableAndSchema;}}}

namespace alinous {namespace remote {namespace db {namespace server {namespace scan {
class AbstractStorageScanSession;}}}}}

namespace alinous {namespace btree {
class IntKey;}}

namespace alinous {namespace lock {
class LockObject;}}

namespace alinous {namespace btree {
class IBTreeKey;}}

namespace java {namespace lang {
class IObject;
}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace remote {namespace db {namespace server {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::java::io::File;
using ::java::io::IOException;
using ::java::util::ArrayList;
using ::java::util::List;
using ::alinous::btree::BTree;
using ::alinous::btree::BTreeException;
using ::alinous::btree::BTreeGlobalCache;
using ::alinous::btree::IBTreeKey;
using ::alinous::btree::IBTreeValue;
using ::alinous::btree::IntKey;
using ::alinous::btree::LongValue;
using ::alinous::compile::sql::TableAndSchema;
using ::alinous::db::AlinousDbException;
using ::alinous::db::SchemaManager;
using ::alinous::db::TableSchema;
using ::alinous::db::table::DatabaseException;
using ::alinous::db::table::IDatabaseTable;
using ::alinous::db::table::TableMetadata;
using ::alinous::db::trx::DbVersionContext;
using ::alinous::lock::LockObject;
using ::alinous::lock::unique::UniqueExclusiveLockManager;
using ::alinous::remote::db::MonitorAccess;
using ::alinous::remote::db::RemoteStorageResponceActionFactory;
using ::alinous::remote::db::client::command::data::SchemasStructureInfoData;
using ::alinous::remote::db::server::scan::AbstractStorageScanSession;
using ::alinous::remote::db::server::scan::StorageScanSessionManager;
using ::alinous::remote::db::server::trx::StorageTransaction;
using ::alinous::remote::db::server::trx::StorageTransactionManager;
using ::alinous::remote::region::client::command::data::ClientNetworkRecord;
using ::alinous::remote::region::client::command::dml::ClientScanCommandData;
using ::alinous::remote::region::server::scan::ScanWorkerResult;
using ::alinous::remote::region::server::schema::strategy::UniqueCheckOperation;
using ::alinous::remote::socket::SocketServer;
using ::alinous::runtime::dom::VariableException;
using ::alinous::runtime::parallel::ThreadPool;
using ::alinous::system::AlinousCore;
using ::alinous::system::AlinousException;
using ::alinous::system::ISystemLog;
using ::alinous::system::config::AlinousInitException;
using ::alinous::system::config::remote::MonitorRef;



class RemoteTableStorageServer final : public virtual IObject {
public:
	RemoteTableStorageServer(const RemoteTableStorageServer& base) = default;
public:
	RemoteTableStorageServer(int port, int maxthread, String* datadir, ThreadContext* ctx) throw() ;
	void __construct_impl(int port, int maxthread, String* datadir, ThreadContext* ctx) throw() ;
	virtual ~RemoteTableStorageServer() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
public:
	SchemaManager* schemas;
private:
	int BLOCK_SIZE;
	int nodeCapacity;
	long long capacity;
	int port;
	int maxthread;
	String* dataDir;
	SocketServer* socketServer;
	BTreeGlobalCache* btreeCache;
	ThreadPool* workerThreadsPool;
	AlinousCore* core;
	BTree* dbconfig;
	File* configFile;
	LockObject* schemaVersionLock;
	long long schemaVersion;
	MonitorAccess* monitorAccess;
	StorageTransactionManager* storageTrxManager;
	UniqueExclusiveLockManager* uniqueExclusiveLock;
	StorageScanSessionManager* scanSessionManager;
public:
	const static IntKey __SCHEMA;
	constexpr static IntKey* SCHEMA{const_cast<IntKey*>(&__SCHEMA)};
	const static IntKey __SCHEMA_VERSION;
	constexpr static IntKey* SCHEMA_VERSION{const_cast<IntKey*>(&__SCHEMA_VERSION)};
private:
	static String* THREAD_NAME;
public:
	void init(AlinousCore* core, MonitorRef* monitorRef, ThreadContext* ctx);
	bool exists(ThreadContext* ctx) throw() ;
	void start(AlinousCore* core, ThreadContext* ctx);
	void dispose(ThreadContext* ctx) throw() ;
	UniqueExclusiveLockManager* getUniqueExclusiveLock(ThreadContext* ctx) throw() ;
	AlinousCore* getCore(ThreadContext* ctx) throw() ;
	void logError(Throwable* e, ThreadContext* ctx) throw() ;
	long long getSchemeInfo(SchemasStructureInfoData* data, String* region, String* host, int port, bool ipv6, ThreadContext* ctx) throw() ;
	void reportMaxOids(ThreadContext* ctx);
	void createSchema(String* schemaName, ThreadContext* ctx);
	void createTable(TableMetadata* metadata, ThreadContext* ctx);
	void prepareInsert(String* schemaName, String* tableName, long long newCommitId, List<UniqueCheckOperation>* uniqueCheckOps, List<ClientNetworkRecord>* records, DbVersionContext* vctx, int isolationLevel, ThreadContext* ctx);
	void commitDmlTransaction(long long newCommitId, DbVersionContext* vctx, ThreadContext* ctx);
	ThreadPool* getWorkerThreadsPool(ThreadContext* ctx) throw() ;
	MonitorAccess* getMonitorAccess(ThreadContext* ctx) throw() ;
	ScanWorkerResult* scan(DbVersionContext* vctx, ClientScanCommandData* data, ThreadContext* ctx);
	void clearRowLocks(DbVersionContext* vctx, ThreadContext* ctx) throw() ;
private:
	void initInstance(AlinousCore* core, ThreadContext* ctx);
	File* getConfigFile(ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx);
};

}}}}

#endif /* end of ALINOUS_REMOTE_DB_SERVER_REMOTETABLESTORAGESERVER_H_ */
