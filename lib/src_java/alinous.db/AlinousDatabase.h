#ifndef ALINOUS_DB_ALINOUSDATABASE_H_
#define ALINOUS_DB_ALINOUSDATABASE_H_
namespace java{namespace net{
class UnknownHostException;
}}
namespace alinous{namespace annotation{
class OneSource;
}}
namespace alinous {namespace db {
class LocalCommitIdPublisher;}}

namespace alinous {namespace system {
class AlinousCore;}}

namespace alinous {namespace runtime {namespace parallel {
class ThreadPool;}}}

namespace alinous {namespace db {namespace trx {
class DbTransactionManager;}}}

namespace java {namespace io {
class File;}}

namespace alinous {namespace btree {
class BTreeGlobalCache;}}

namespace alinous {namespace btree {
class BTree;}}

namespace alinous {namespace db {
class AlinousDbException;}}

namespace java {namespace io {
class IOException;}}

namespace java {namespace lang {
class InterruptedException;}}

namespace alinous {namespace btree {
class BTreeException;}}

namespace alinous {namespace db {namespace trx {
class TrxLockContext;}}}

namespace alinous {namespace system {namespace config {
class AlinousDbInstanceInfo;}}}

namespace alinous {namespace db {namespace table {
class LocalOidPublisher;}}}

namespace alinous {namespace db {
class LocalTableRegion;}}

namespace alinous {namespace db {
class SchemaManager;}}

namespace alinous {namespace btree {
class LongValue;}}

namespace alinous {namespace runtime {namespace dom {
class VariableException;}}}

namespace alinous {namespace system {
class AlinousException;}}

namespace alinous {namespace lock {namespace unique {
class UniqueExclusiveLockClient;}}}

namespace alinous {namespace db {namespace trx {
class DbVersionContext;}}}

namespace alinous {namespace btree {
class IBTreeNode;}}

namespace alinous {namespace btree {
class IBTreeValue;}}

namespace alinous {namespace system {
class ISystemLog;}}

namespace java {namespace lang {
class Throwable;}}

namespace alinous {namespace runtime {namespace parallel {
class LaunchJoin;}}}

namespace alinous {namespace runtime {namespace parallel {
class AlinousThread;}}}

namespace alinous {namespace system {namespace config {namespace remote {
class MonitorRef;}}}}

namespace alinous {namespace remote {namespace monitor {namespace client {
class RemoteCommitIdPublisher;}}}}

namespace alinous {namespace db {namespace trx {
class TrxLockManager;}}}

namespace alinous {namespace db {
class TableRegionManager;}}

namespace alinous {namespace lock {namespace unique {
class UniqueExclusiveLockManager;}}}

namespace alinous {namespace db {namespace table {
class IOidPublisher;}}}

namespace alinous {namespace system {namespace config {namespace remote {
class RegionsRef;}}}}

namespace java {namespace util {
template <typename  T> class List;}}

namespace alinous {namespace system {namespace config {namespace remote {
class RegionRef;}}}}

namespace alinous {namespace remote {namespace region {namespace client {
class RemoteRegionRef;}}}}

namespace alinous {namespace db {
class ITableRegion;}}

namespace alinous {namespace db {
class TableSchemaCollection;}}

namespace alinous {namespace db {namespace table {
class IDatabaseTable;}}}

namespace alinous {namespace compile {namespace declare {
class AlinousName;}}}

namespace alinous {namespace db {
class AlinousDbConnection;}}

namespace alinous {namespace db {
class ConnectInfo;}}

namespace alinous {namespace btree {
class IntKey;}}

namespace alinous {namespace lock {
class LockObject;}}

namespace alinous {namespace db {
class ICommidIdPublisher;}}

namespace alinous {namespace btree {
class IBTreeKey;}}

namespace alinous {namespace lock {namespace unique {
class UniqueLockClientFactory;}}}

namespace alinous {namespace system {namespace utils {
class FileUtils;}}}

namespace java {namespace lang {
class IObject;
}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace db {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::java::io::File;
using ::java::io::IOException;
using ::java::net::UnknownHostException;
using ::java::util::ArrayList;
using ::java::util::List;
using ::alinous::btree::BTree;
using ::alinous::btree::BTreeException;
using ::alinous::btree::BTreeGlobalCache;
using ::alinous::btree::IBTreeKey;
using ::alinous::btree::IBTreeNode;
using ::alinous::btree::IBTreeValue;
using ::alinous::btree::IntKey;
using ::alinous::btree::LongValue;
using ::alinous::compile::declare::AlinousName;
using ::alinous::db::table::IDatabaseTable;
using ::alinous::db::table::IOidPublisher;
using ::alinous::db::table::LocalOidPublisher;
using ::alinous::db::trx::DbTransactionManager;
using ::alinous::db::trx::DbVersionContext;
using ::alinous::db::trx::TrxLockContext;
using ::alinous::db::trx::TrxLockManager;
using ::alinous::lock::LockObject;
using ::alinous::lock::unique::UniqueExclusiveLockClient;
using ::alinous::lock::unique::UniqueExclusiveLockManager;
using ::alinous::lock::unique::UniqueLockClientFactory;
using ::alinous::remote::monitor::client::RemoteCommitIdPublisher;
using ::alinous::remote::region::client::RemoteRegionRef;
using ::alinous::runtime::dom::VariableException;
using ::alinous::runtime::parallel::AlinousThread;
using ::alinous::runtime::parallel::LaunchJoin;
using ::alinous::runtime::parallel::ThreadPool;
using ::alinous::system::AlinousCore;
using ::alinous::system::AlinousException;
using ::alinous::system::ISystemLog;
using ::alinous::system::config::AlinousDbInstanceInfo;
using ::alinous::system::config::remote::MonitorRef;
using ::alinous::system::config::remote::RegionRef;
using ::alinous::system::config::remote::RegionsRef;
using ::alinous::system::utils::FileUtils;



class AlinousDatabase final : public virtual IObject {
public:
	AlinousDatabase(const AlinousDatabase& base) = default;
public:
	AlinousDatabase(ThreadContext* ctx) throw() ;
	void __construct_impl(ThreadContext* ctx) throw() ;
	virtual ~AlinousDatabase() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
public:
	LockObject* instanceConfigLock;
	DbTransactionManager* trxManager;
	TrxLockManager* trxLockManager;
	ICommidIdPublisher* commitIdPublisher;
	ThreadPool* workerThreadsPool;
private:
	AlinousCore* core;
	bool remote;
	String* dataDir;
	BTree* dbconfig;
	File* configFile;
	IOidPublisher* oidPublisher;
	AlinousThread* trxWriterThread;
	BTreeGlobalCache* btreeCache;
	TableRegionManager* regionManager;
	UniqueExclusiveLockManager* uniqueExclusiveLockManager;
public:
	const static IntKey __SCHEMA;
	constexpr static IntKey* SCHEMA{const_cast<IntKey*>(&__SCHEMA)};
	const static IntKey __USERS;
	constexpr static IntKey* USERS{const_cast<IntKey*>(&__USERS)};
	const static IntKey __MAX_COMMIT_ID;
	constexpr static IntKey* MAX_COMMIT_ID{const_cast<IntKey*>(&__MAX_COMMIT_ID)};
	const static IntKey __MAX_OID_ID;
	constexpr static IntKey* MAX_OID_ID{const_cast<IntKey*>(&__MAX_OID_ID)};
public:
	void construct(AlinousCore* core, String* dataDir, String* trxTmpDir, int maxConnection, ThreadContext* ctx);
	TrxLockContext* newLockContext(ThreadContext* ctx) throw() ;
	void initInstance(AlinousDbInstanceInfo* instanceConfig, ThreadContext* ctx);
	long long getCommitId(ThreadContext* ctx);
	long long newCommitId(ThreadContext* ctx);
	UniqueExclusiveLockClient* newUniqueExclusiveLockClient(ThreadContext* ctx) throw() ;
	DbVersionContext* newTransactionContext(ThreadContext* ctx);
	void syncScheme(ThreadContext* ctx);
	void open(AlinousDbInstanceInfo* instanceConfig, ThreadContext* ctx);
	TableSchemaCollection* getSchema(String* name, ThreadContext* ctx) throw() ;
	IDatabaseTable* getTable(AlinousName* tableName, String* currentSchema, ThreadContext* ctx) throw() ;
	IDatabaseTable* getTable(String* schemaName, String* tableName, ThreadContext* ctx) throw() ;
	void closeDatabase(ThreadContext* ctx) throw() ;
	AlinousDbConnection* connect(ConnectInfo* info, ThreadContext* ctx) throw() ;
	void disConnect(AlinousDbConnection* con, ThreadContext* ctx) throw() ;
	void dropInstance(ThreadContext* ctx) throw() ;
	bool exists(ThreadContext* ctx) throw() ;
	AlinousCore* getCore(ThreadContext* ctx) throw() ;
	BTreeGlobalCache* getBtreeCache(ThreadContext* ctx) throw() ;
	TableRegionManager* getRegionManager(ThreadContext* ctx) throw() ;
	bool isRemote(ThreadContext* ctx) throw() ;
	void syncSchemaVersion(DbVersionContext* vctx, ThreadContext* ctx);
	IOidPublisher* getOidPublisher(ThreadContext* ctx) throw() ;
private:
	File* getConfigFile(ThreadContext* ctx) throw() ;
	void openLocal(ThreadContext* ctx);
	void openRegions(AlinousDbInstanceInfo* instanceConfig, ThreadContext* ctx);
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx);
};

}}

#endif /* end of ALINOUS_DB_ALINOUSDATABASE_H_ */
