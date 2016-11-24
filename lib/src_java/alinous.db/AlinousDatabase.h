#ifndef ALINOUS_DB_ALINOUSDATABASE_H_
#define ALINOUS_DB_ALINOUSDATABASE_H_
namespace alinous{namespace annotation{
class OneSource;
}}
namespace alinous {namespace db {
class LocalCommitIdPublisher;}}

namespace alinous {namespace system {
class AlinousCore;}}

namespace alinous {namespace db {namespace table {namespace cache {
class RecordCacheEngine;}}}}

namespace alinous {namespace db {
class SchemaManager;}}

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

namespace alinous {namespace db {namespace table {namespace lockmonitor {
class ThreadLocker;}}}}

namespace alinous {namespace btree {
class LongValue;}}

namespace alinous {namespace runtime {namespace dom {
class VariableException;}}}

namespace alinous {namespace btree {
class BTreeLeafNode;}}

namespace alinous {namespace btree {
class IBTreeValue;}}

namespace java {namespace lang {
class Throwable;}}

namespace alinous {namespace runtime {namespace parallel {
class ThreadPool;}}}

namespace alinous {namespace runtime {namespace parallel {
class LaunchJoin;}}}

namespace alinous {namespace runtime {namespace parallel {
class AlinousThread;}}}

namespace alinous {namespace db {namespace table {namespace lockmonitor {
class DBThreadMonitor;}}}}

namespace alinous {namespace db {
class TableSchema;}}

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

namespace alinous {namespace system {
class AlinousException;}}

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
using ::java::util::ArrayList;
using ::alinous::btree::BTree;
using ::alinous::btree::BTreeException;
using ::alinous::btree::BTreeGlobalCache;
using ::alinous::btree::BTreeLeafNode;
using ::alinous::btree::IBTreeKey;
using ::alinous::btree::IBTreeValue;
using ::alinous::btree::IntKey;
using ::alinous::btree::LongValue;
using ::alinous::compile::declare::AlinousName;
using ::alinous::db::table::IDatabaseTable;
using ::alinous::db::table::cache::RecordCacheEngine;
using ::alinous::db::table::lockmonitor::DBThreadMonitor;
using ::alinous::db::table::lockmonitor::ThreadLocker;
using ::alinous::db::trx::DbTransactionManager;
using ::alinous::lock::LockObject;
using ::alinous::runtime::dom::VariableException;
using ::alinous::runtime::parallel::AlinousThread;
using ::alinous::runtime::parallel::LaunchJoin;
using ::alinous::runtime::parallel::ThreadPool;
using ::alinous::system::AlinousCore;
using ::alinous::system::AlinousException;
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
	SchemaManager* schemas;
	DBThreadMonitor* lockManager;
	ICommidIdPublisher* localCommitId;
	ThreadPool* workerThreadsPool;
	DbTransactionManager* trxManager;
private:
	AlinousCore* core;
	String* dataDir;
	BTree* dbconfig;
	File* configFile;
	AlinousThread* trxWriterThread;
	RecordCacheEngine* cahceEngine;
	BTreeGlobalCache* btreeCache;
public:
	const static IntKey __SCHEMA;
	constexpr static IntKey* SCHEMA{const_cast<IntKey*>(&__SCHEMA)};
	const static IntKey __USERS;
	constexpr static IntKey* USERS{const_cast<IntKey*>(&__USERS)};
	const static IntKey __MAX_COMMIT_ID;
	constexpr static IntKey* MAX_COMMIT_ID{const_cast<IntKey*>(&__MAX_COMMIT_ID)};
public:
	void construct(AlinousCore* core, String* dataDir, String* trxTmpDir, int maxConnection, ThreadContext* ctx);
	ThreadLocker* newLockContext(ThreadContext* ctx) throw() ;
	void initInstance(ThreadContext* ctx);
	long long getCommitId(ThreadContext* ctx) throw() ;
	long long newCommitId(ThreadContext* ctx);
	void syncScheme(ThreadContext* ctx);
	void open(ThreadContext* ctx);
	TableSchema* getSchema(String* name, ThreadContext* ctx) throw() ;
	IDatabaseTable* getTable(AlinousName* tableName, String* currentSchema, ThreadContext* ctx) throw() ;
	IDatabaseTable* getTable(String* schemaName, String* tableName, ThreadContext* ctx) throw() ;
	void closeDatabase(ThreadContext* ctx) throw() ;
	AlinousDbConnection* connect(ConnectInfo* info, ThreadContext* ctx) throw() ;
	void disConnect(AlinousDbConnection* con, ThreadContext* ctx) throw() ;
	void dropInstance(ThreadContext* ctx) throw() ;
	bool exists(ThreadContext* ctx) throw() ;
	AlinousCore* getCore(ThreadContext* ctx) throw() ;
	BTreeGlobalCache* getBtreeCache(ThreadContext* ctx) throw() ;
private:
	File* getConfigFile(ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}

#endif /* end of ALINOUS_DB_ALINOUSDATABASE_H_ */
