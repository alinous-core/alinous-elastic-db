#ifndef ALINOUS_DB_SCHEMAMANAGER_H_
#define ALINOUS_DB_SCHEMAMANAGER_H_
namespace alinous{namespace annotation{
class OneSource;
}}
namespace alinous {namespace system {
class ISystemLog;}}

namespace alinous {namespace runtime {namespace parallel {
class ThreadPool;}}}

namespace alinous {namespace system {
class AlinousCore;}}

namespace alinous {namespace btree {
class BTreeGlobalCache;}}

namespace alinous {namespace db {namespace table {
class TableMetadata;}}}

namespace alinous {namespace db {
class TableSchema;}}

namespace alinous {namespace db {namespace table {
class IDatabaseTable;}}}

namespace alinous {namespace db {namespace table {
class DatabaseTable;}}}

namespace alinous {namespace db {
class SchemaManager;}}

namespace alinous {namespace buffer {namespace storage {
class FileStorageEntryFetcher;}}}

namespace java {namespace util {
template <typename  T> class Iterator;}}

namespace alinous {namespace buffer {namespace storage {
class FileStorageEntryBuilder;}}}

namespace alinous {namespace btree {
class IValueFetcher;}}

namespace alinous {namespace remote {namespace db {namespace command {namespace data {
class SchemasStructureInfoData;}}}}}

namespace alinous {namespace remote {namespace db {namespace command {namespace data {
class SchemaData;}}}}}

namespace java {namespace util {
template <typename  T, typename V> class HashMap;}}

namespace alinous {namespace lock {
class LockObject;}}

namespace alinous {namespace db {namespace table {
class IOidPublisher;}}}

namespace alinous {namespace btree {
class IBTreeValue;}}

namespace java {namespace io {
class IOException;}}

namespace alinous {namespace btree {
class BTreeException;}}

namespace alinous {namespace db {namespace table {
class DatabaseException;}}}

namespace alinous {namespace system {
class AlinousException;}}

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
using ::java::io::IOException;
using ::java::util::HashMap;
using ::java::util::Iterator;
using ::alinous::btree::BTreeException;
using ::alinous::btree::BTreeGlobalCache;
using ::alinous::btree::IBTreeValue;
using ::alinous::btree::IValueFetcher;
using ::alinous::buffer::storage::FileStorageEntryBuilder;
using ::alinous::buffer::storage::FileStorageEntryFetcher;
using ::alinous::db::table::DatabaseException;
using ::alinous::db::table::DatabaseTable;
using ::alinous::db::table::IDatabaseTable;
using ::alinous::db::table::IOidPublisher;
using ::alinous::db::table::TableMetadata;
using ::alinous::lock::LockObject;
using ::alinous::remote::db::command::data::SchemaData;
using ::alinous::remote::db::command::data::SchemasStructureInfoData;
using ::alinous::runtime::parallel::ThreadPool;
using ::alinous::system::AlinousCore;
using ::alinous::system::AlinousException;
using ::alinous::system::ISystemLog;



class SchemaManager final : public IBTreeValue, public virtual IObject {
public:
	SchemaManager(const SchemaManager& base) = default;
public:
	SchemaManager(String* dataDir, ISystemLog* logger, ThreadPool* threadPool, AlinousCore* core, BTreeGlobalCache* cache, ThreadContext* ctx) throw() ;
	void __construct_impl(String* dataDir, ISystemLog* logger, ThreadPool* threadPool, AlinousCore* core, BTreeGlobalCache* cache, ThreadContext* ctx) throw() ;
	virtual ~SchemaManager() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	String* dataDir;
	HashMap<String,TableSchema>* schemas;
	LockObject* schemeLock;
	ISystemLog* logger;
	ThreadPool* threadPool;
	IOidPublisher* oidPublisher;
public:
	void createTable(String* schemaName, TableMetadata* tableMetadata, ThreadPool* threadPool, AlinousCore* core, BTreeGlobalCache* cache, ThreadContext* ctx);
	TableSchema* createSchema(String* name, ThreadContext* ctx) throw() ;
	TableSchema* getSchema(String* name, ThreadContext* ctx) throw() ;
	void loadAfterFetch(String* dataDir, ISystemLog* logger, ThreadPool* threadPool, AlinousCore* core, BTreeGlobalCache* cache, ThreadContext* ctx);
	void appendToEntry(FileStorageEntryBuilder* builder, ThreadContext* ctx) final;
	int diskSize(ThreadContext* ctx) throw()  final;
	bool equals(IObject* obj, ThreadContext* ctx) throw()  final;
	IValueFetcher* getFetcher(ThreadContext* ctx) throw()  final;
	void getSchemaData(SchemasStructureInfoData* data, String* region, ThreadContext* ctx) throw() ;
private:
	void doCreateTable(String* schemaName, TableMetadata* tableMetadata, ThreadPool* threadPool, AlinousCore* core, BTreeGlobalCache* cache, ThreadContext* ctx);
public:
	static SchemaManager* valueFromFetcher(FileStorageEntryFetcher* fetcher, ThreadContext* ctx);
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}

#endif /* end of ALINOUS_DB_SCHEMAMANAGER_H_ */
