#ifndef ALINOUS_DB_TABLESCHEMA_H_
#define ALINOUS_DB_TABLESCHEMA_H_
namespace alinous{namespace annotation{
class OneSource;
}}
namespace java {namespace io {
class File;}}

namespace alinous {namespace db {namespace table {namespace cache {
class RecordCacheEngine;}}}}

namespace alinous {namespace db {
class AlinousDatabase;}}

namespace java {namespace lang {
class StringBuilder;}}

namespace java {namespace util {
template <typename  T> class Iterator;}}

namespace alinous {namespace db {namespace table {
class DatabaseTable;}}}

namespace alinous {namespace db {namespace table {
class TableMetadata;}}}

namespace java {namespace util {
template <typename  T> class Set;}}

namespace alinous {namespace db {
class TableSchema;}}

namespace alinous {namespace buffer {namespace storage {
class FileStorageEntryFetcher;}}}

namespace alinous {namespace buffer {namespace storage {
class FileStorageEntryBuilder;}}}

namespace alinous {namespace btree {
class IValueFetcher;}}

namespace java {namespace util {
template <typename  T, typename V> class HashMap;}}

namespace alinous {namespace btree {
class IBTreeValue;}}

namespace alinous {namespace db {namespace table {
class DatabaseException;}}}

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
using ::java::util::HashMap;
using ::java::util::Iterator;
using ::java::util::Set;
using ::alinous::btree::IBTreeValue;
using ::alinous::btree::IValueFetcher;
using ::alinous::buffer::storage::FileStorageEntryBuilder;
using ::alinous::buffer::storage::FileStorageEntryFetcher;
using ::alinous::db::table::DatabaseException;
using ::alinous::db::table::DatabaseTable;
using ::alinous::db::table::TableMetadata;
using ::alinous::db::table::cache::RecordCacheEngine;



class TableSchema final : public IBTreeValue, public virtual IObject {
public:
	TableSchema(const TableSchema& base) = default;
public:
	TableSchema(String* name, String* dataDir, ThreadContext* ctx) throw() ;
	void __construct_impl(String* name, String* dataDir, ThreadContext* ctx) throw() ;
	virtual ~TableSchema() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
public:
	String* name;
private:
	String* dataDir;
	String* schemaDir;
	HashMap<String,TableMetadata>* tables;
	HashMap<String,DatabaseTable>* tableStores;
public:
	void create(ThreadContext* ctx) throw() ;
	void initAfterFetched(RecordCacheEngine* cacheEngine, String* dataDir, String* schemaName, AlinousDatabase* database, ThreadContext* ctx);
	String* getSchemaDir(ThreadContext* ctx) throw() ;
	void addTableStore(DatabaseTable* tableStore, ThreadContext* ctx) throw() ;
	DatabaseTable* getTableStore(String* tableName, ThreadContext* ctx) throw() ;
	TableMetadata* getDableMetadata(String* tableName, ThreadContext* ctx) throw() ;
	Set<String>* getTableNames(ThreadContext* ctx) throw() ;
	void addTableMetadata(TableMetadata* tblMetadata, ThreadContext* ctx) throw() ;
	void appendToEntry(FileStorageEntryBuilder* builder, ThreadContext* ctx) throw()  final;
	int diskSize(ThreadContext* ctx) throw()  final;
	bool equals(IObject* obj, ThreadContext* ctx) throw()  final;
	bool equals(TableSchema* other, ThreadContext* ctx) throw() ;
	IValueFetcher* getFetcher(ThreadContext* ctx) throw()  final;
public:
	static TableSchema* valueFromFetcher(FileStorageEntryFetcher* fetcher, ThreadContext* ctx);
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}

#endif /* end of ALINOUS_DB_TABLESCHEMA_H_ */
