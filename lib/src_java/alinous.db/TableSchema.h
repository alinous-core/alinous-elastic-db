#ifndef ALINOUS_DB_TABLESCHEMA_H_
#define ALINOUS_DB_TABLESCHEMA_H_
namespace alinous{namespace annotation{
class OneSource;
}}
namespace alinous {namespace remote {namespace db {namespace client {namespace command {namespace data {
class SchemaData;}}}}}}

namespace java {namespace util {
template <typename  T> class Iterator;}}

namespace alinous {namespace db {namespace table {
class TableMetadata;}}}

namespace alinous {namespace remote {namespace db {namespace client {namespace command {namespace data {
class TableClusterData;}}}}}}

namespace java {namespace io {
class File;}}

namespace alinous {namespace runtime {namespace parallel {
class ThreadPool;}}}

namespace alinous {namespace system {
class AlinousCore;}}

namespace alinous {namespace btree {
class BTreeGlobalCache;}}

namespace java {namespace lang {
class StringBuilder;}}

namespace alinous {namespace db {namespace table {
class IDatabaseTable;}}}

namespace alinous {namespace db {namespace table {
class DatabaseTable;}}}

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

namespace alinous {namespace db {
class ITableSchema;}}

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
using ::java::io::File;
using ::java::util::HashMap;
using ::java::util::Iterator;
using ::java::util::Set;
using ::alinous::btree::BTreeGlobalCache;
using ::alinous::btree::IBTreeValue;
using ::alinous::btree::IValueFetcher;
using ::alinous::buffer::storage::FileStorageEntryBuilder;
using ::alinous::buffer::storage::FileStorageEntryFetcher;
using ::alinous::db::table::DatabaseException;
using ::alinous::db::table::DatabaseTable;
using ::alinous::db::table::IDatabaseTable;
using ::alinous::db::table::TableMetadata;
using ::alinous::remote::db::client::command::data::SchemaData;
using ::alinous::remote::db::client::command::data::TableClusterData;
using ::alinous::runtime::parallel::ThreadPool;
using ::alinous::system::AlinousCore;
using ::alinous::system::AlinousException;



class TableSchema final : public IBTreeValue, public ITableSchema, public virtual IObject {
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
	HashMap<String,IDatabaseTable>* tableStores;
	String* regionName;
public:
	SchemaData* toCommandData(String* region, String* host, int port, bool ipv6, ThreadContext* ctx) throw() ;
	void create(ThreadContext* ctx) throw() ;
	void initAfterFetched(String* dataDir, String* schemaName, ThreadPool* threadPool, AlinousCore* core, BTreeGlobalCache* cache, ThreadContext* ctx);
	String* getSchemaDir(ThreadContext* ctx) throw() ;
	void addTableStore(IDatabaseTable* tableStore, ThreadContext* ctx) throw() ;
	IDatabaseTable* getTableStore(String* tableName, ThreadContext* ctx) throw()  final;
	TableMetadata* getDableMetadata(String* tableName, ThreadContext* ctx) throw() ;
	Set<String>* getTableNames(ThreadContext* ctx) throw() ;
	void addTableMetadata(TableMetadata* tblMetadata, ThreadContext* ctx) throw() ;
	void appendToEntry(FileStorageEntryBuilder* builder, ThreadContext* ctx) final;
	int diskSize(ThreadContext* ctx) throw()  final;
	bool equals(IObject* obj, ThreadContext* ctx) throw()  final;
	bool equals(TableSchema* other, ThreadContext* ctx) throw() ;
	IValueFetcher* getFetcher(ThreadContext* ctx) throw()  final;
	String* getregionName(ThreadContext* ctx) throw() ;
	void setRegionName(String* regionName, ThreadContext* ctx) throw() ;
	HashMap<String,IDatabaseTable>* getTableStores(ThreadContext* ctx) throw() ;
public:
	static TableSchema* valueFromFetcher(FileStorageEntryFetcher* fetcher, ThreadContext* ctx);
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx);
};

}}

#endif /* end of ALINOUS_DB_TABLESCHEMA_H_ */
