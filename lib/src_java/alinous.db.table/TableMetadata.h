#ifndef ALINOUS_DB_TABLE_TABLEMETADATA_H_
#define ALINOUS_DB_TABLE_TABLEMETADATA_H_
namespace alinous{namespace annotation{
class OneSource;
}}
namespace alinous {namespace remote {namespace db {namespace command {namespace data {
class TableClusterData;}}}}}

namespace alinous {namespace remote {namespace db {namespace command {namespace data {
class StorageNodeData;}}}}}

namespace alinous {namespace db {namespace table {
class TableMetadata;}}}

namespace java {namespace util {
template <typename  T> class Set;}}

namespace java {namespace util {
template <typename  T> class Iterator;}}

namespace alinous {namespace db {namespace table {
class TableColumnMetadata;}}}

namespace alinous {namespace db {namespace table {
class TableIndexMetadata;}}}

namespace alinous {namespace compile {namespace sql {namespace ddl {
class CheckDefinition;}}}}

namespace alinous {namespace buffer {namespace storage {
class FileStorageEntryBuilder;}}}

namespace alinous {namespace buffer {namespace storage {
class FileStorageEntryFetcher;}}}

namespace alinous {namespace remote {namespace socket {
class NetworkBinaryBuffer;}}}

namespace alinous {namespace runtime {namespace dom {
class VariableException;}}}

namespace alinous {namespace db {
class AlinousDbException;}}

namespace alinous {namespace compile {
class IAlinousElement;}}

namespace alinous {namespace db {namespace table {
class TablePartitionMaxValue;}}}

namespace java {namespace util {
template <typename  T, typename V> class HashMap;}}

namespace alinous {namespace remote {namespace socket {
class ICommandData;}}}

namespace alinous {namespace compile {
class AlinousElementNetworkFactory;}}

namespace alinous {namespace system {
class AlinousException;}}

namespace java {namespace lang {
class IObject;
}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace db {namespace table {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::java::util::ArrayList;
using ::java::util::HashMap;
using ::java::util::Iterator;
using ::java::util::Set;
using ::alinous::buffer::storage::FileStorageEntryBuilder;
using ::alinous::buffer::storage::FileStorageEntryFetcher;
using ::alinous::compile::AlinousElementNetworkFactory;
using ::alinous::compile::IAlinousElement;
using ::alinous::compile::sql::ddl::CheckDefinition;
using ::alinous::db::AlinousDbException;
using ::alinous::remote::db::command::data::StorageNodeData;
using ::alinous::remote::db::command::data::TableClusterData;
using ::alinous::remote::socket::ICommandData;
using ::alinous::remote::socket::NetworkBinaryBuffer;
using ::alinous::runtime::dom::VariableException;
using ::alinous::system::AlinousException;



class TableMetadata final : public ICommandData, public virtual IObject {
public:
	TableMetadata(const TableMetadata& base) = default;
public:
	TableMetadata(String* tableName, ThreadContext* ctx) throw() ;
	void __construct_impl(String* tableName, ThreadContext* ctx) throw() ;
	TableMetadata(String* schema, String* tableName, ThreadContext* ctx) throw() ;
	void __construct_impl(String* schema, String* tableName, ThreadContext* ctx) throw() ;
	virtual ~TableMetadata() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	HashMap<String,TableColumnMetadata>* columns;
	ArrayList<TableColumnMetadata>* columnsList;
	ArrayList<TableColumnMetadata>* primaryKeys;
	ArrayList<TableIndexMetadata>* indexes;
	ArrayList<TableColumnMetadata>* uniqueList;
	String* schema;
	String* tableName;
	ArrayList<CheckDefinition>* checks;
	ArrayList<TableColumnMetadata>* shardKeys;
	ArrayList<TableColumnMetadata>* subShardKeys;
	TablePartitionMaxValue* maxPartitionValue;
public:
	TableClusterData* toCommandData(String* region, String* host, int port, bool ipv6, ThreadContext* ctx) throw() ;
	bool checkEquals(TableMetadata* metadata, ThreadContext* ctx) throw() ;
	int fileSize(ThreadContext* ctx);
	void toFileEntry(FileStorageEntryBuilder* builder, ThreadContext* ctx);
	void readData(NetworkBinaryBuffer* buff, ThreadContext* ctx) final;
	void writeData(NetworkBinaryBuffer* buff, ThreadContext* ctx) throw()  final;
	void addindex(TableIndexMetadata* indexMeta, ThreadContext* ctx) throw() ;
	void addColumn(String* name, int type, int length, ThreadContext* ctx) throw() ;
	void addColumn(TableColumnMetadata* meta, ThreadContext* ctx) throw() ;
	ArrayList<TableColumnMetadata>* getColumnsList(ThreadContext* ctx) throw() ;
	int size(ThreadContext* ctx) throw() ;
	TableColumnMetadata* getColumnByName(String* name, ThreadContext* ctx) throw() ;
	int getColumnOrder(String* columnName, ThreadContext* ctx) throw() ;
	int getColumnCount(ThreadContext* ctx) throw() ;
	ArrayList<TableIndexMetadata>* getIndexes(ThreadContext* ctx) throw() ;
	String* getSchema(ThreadContext* ctx) throw() ;
	void setSchema(String* schema, ThreadContext* ctx) throw() ;
	String* getTableName(ThreadContext* ctx) throw() ;
	ArrayList<TableColumnMetadata>* getPrimaryKeys(ThreadContext* ctx) throw() ;
	void addPrimaryKey(String* col, ThreadContext* ctx);
	void addPrimaryKey(TableColumnMetadata* colmeta, ThreadContext* ctx);
	ArrayList<CheckDefinition>* getChecks(ThreadContext* ctx) throw() ;
	void setChecks(ArrayList<CheckDefinition>* checks, ThreadContext* ctx) throw() ;
	TablePartitionMaxValue* getMaxPartitionValue(ThreadContext* ctx) throw() ;
	void setMaxPartitionValue(TablePartitionMaxValue* maxPartitionValue, ThreadContext* ctx) throw() ;
	void addShardKey(String* col, ThreadContext* ctx);
	void addSubShardKey(String* col, ThreadContext* ctx);
	bool checkHasIndex(ArrayList<String>* columns, String* indexName, ThreadContext* ctx) throw() ;
private:
	bool checkColumnArrays(ArrayList<String>* columns, TableIndexMetadata* index, ThreadContext* ctx) throw() ;
public:
	static TableMetadata* loadFromFetcher(FileStorageEntryFetcher* fetcher, ThreadContext* ctx);
	static TableMetadata* fromNetwork(NetworkBinaryBuffer* buff, ThreadContext* ctx);
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}}

#endif /* end of ALINOUS_DB_TABLE_TABLEMETADATA_H_ */
