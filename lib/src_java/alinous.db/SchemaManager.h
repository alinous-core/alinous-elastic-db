#ifndef ALINOUS_DB_SCHEMAMANAGER_H_
#define ALINOUS_DB_SCHEMAMANAGER_H_
namespace alinous{namespace annotation{
class OneSource;
}}
namespace alinous {namespace system {
class ISystemLog;}}

namespace alinous {namespace db {
class AlinousDatabase;}}

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

namespace java {namespace util {
template <typename  T, typename V> class HashMap;}}

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
using ::alinous::btree::IBTreeValue;
using ::alinous::btree::IValueFetcher;
using ::alinous::buffer::storage::FileStorageEntryBuilder;
using ::alinous::buffer::storage::FileStorageEntryFetcher;
using ::alinous::db::table::DatabaseException;
using ::alinous::db::table::DatabaseTable;
using ::alinous::db::table::IDatabaseTable;
using ::alinous::db::table::IOidPublisher;
using ::alinous::db::table::TableMetadata;
using ::alinous::system::AlinousException;
using ::alinous::system::ISystemLog;



class SchemaManager final : public IBTreeValue, public virtual IObject {
public:
	SchemaManager(const SchemaManager& base) = default;
public:
	SchemaManager(String* dataDir, ISystemLog* logger, AlinousDatabase* database, ThreadContext* ctx) throw() ;
	void __construct_impl(String* dataDir, ISystemLog* logger, AlinousDatabase* database, ThreadContext* ctx) throw() ;
	virtual ~SchemaManager() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	String* dataDir;
	HashMap<String,TableSchema>* schemas;
	ISystemLog* logger;
	AlinousDatabase* database;
	IOidPublisher* oidPublisher;
public:
	void createTable(String* schemaName, TableMetadata* tableMetadata, ThreadContext* ctx);
	TableSchema* createSchema(String* name, ThreadContext* ctx) throw() ;
	TableSchema* getSchema(String* name, ThreadContext* ctx) throw() ;
	void loadAfterFetch(String* dataDir, ISystemLog* logger, AlinousDatabase* database, ThreadContext* ctx);
	void appendToEntry(FileStorageEntryBuilder* builder, ThreadContext* ctx) throw()  final;
	int diskSize(ThreadContext* ctx) throw()  final;
	bool equals(IObject* obj, ThreadContext* ctx) throw()  final;
	IValueFetcher* getFetcher(ThreadContext* ctx) throw()  final;
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
