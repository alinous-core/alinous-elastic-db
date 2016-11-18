#ifndef ALINOUS_DB_TABLE_ABSTRACTDATABASETABLE_H_
#define ALINOUS_DB_TABLE_ABSTRACTDATABASETABLE_H_
namespace alinous{namespace annotation{
class OneSource;
}}
namespace java {namespace lang {
class Integer;}}

namespace alinous {namespace db {namespace table {
class TableMetadata;}}}

namespace alinous {namespace lock {
class ConcurrentGate;}}

namespace java {namespace sql {
class Timestamp;}}

namespace alinous {namespace db {
class AlinousDatabase;}}

namespace alinous {namespace buffer {namespace storage {
class FileStorage;}}}

namespace java {namespace io {
class File;}}

namespace alinous {namespace btree {
class BTree;}}

namespace alinous {namespace db {namespace table {
class DatabaseException;}}}

namespace java {namespace lang {
class Throwable;}}

namespace alinous {namespace db {namespace table {
class DatatableUpdateCache;}}}

namespace java {namespace io {
class IOException;}}

namespace alinous {namespace btree {
class BTreeException;}}

namespace java {namespace lang {
class InterruptedException;}}

namespace alinous {namespace db {
class AlinousDbException;}}

namespace alinous {namespace db {namespace table {
class TableIndex;}}}

namespace alinous {namespace runtime {namespace dom {
class VariableException;}}}

namespace alinous {namespace buffer {namespace storage {
class FileStorageEntryWriter;}}}

namespace alinous {namespace buffer {namespace storage {
class FileStorageEntryBuilder;}}}

namespace alinous {namespace buffer {namespace storage {
class FileStorageEntry;}}}

namespace java {namespace lang {
class StringBuilder;}}

namespace alinous {namespace buffer {namespace storage {
class FileStorageEntryReader;}}}

namespace alinous {namespace buffer {namespace storage {
class FileStorageEntryFetcher;}}}

namespace alinous {namespace db {namespace table {
class DatabaseTable;}}}

namespace alinous {namespace db {namespace table {
class IDatabaseTable;}}}

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
using ::java::io::File;
using ::java::io::IOException;
using ::java::sql::Timestamp;
using ::java::util::ArrayList;
using ::alinous::btree::BTree;
using ::alinous::btree::BTreeException;
using ::alinous::buffer::storage::FileStorage;
using ::alinous::buffer::storage::FileStorageEntry;
using ::alinous::buffer::storage::FileStorageEntryBuilder;
using ::alinous::buffer::storage::FileStorageEntryFetcher;
using ::alinous::buffer::storage::FileStorageEntryReader;
using ::alinous::buffer::storage::FileStorageEntryWriter;
using ::alinous::db::AlinousDatabase;
using ::alinous::db::AlinousDbException;
using ::alinous::lock::ConcurrentGate;
using ::alinous::runtime::dom::VariableException;



class AbstractDatabaseTable : public IDatabaseTable, public virtual IObject {
public:
	AbstractDatabaseTable(const AbstractDatabaseTable& base) = default;
public:
	AbstractDatabaseTable(String* schema, String* name, String* baseDir, ThreadContext* ctx) throw() ;
	void __construct_impl(String* schema, String* name, String* baseDir, ThreadContext* ctx) throw() ;
	virtual ~AbstractDatabaseTable() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
public:
	Integer* tableId;
	TableMetadata* metadata;
	ArrayList<TableIndex>* indexes;
	TableIndex* primaryIndex;
	String* name;
	String* baseDir;
	String* oidIndexPath;
	String* dataStoragePath;
	BTree* oidIndex;
	FileStorage* dataStorage;
	ConcurrentGate* storageLock;
	Timestamp* schmeUpdated;
	DatatableUpdateCache* updateHistoryCache;
public:
	void open(AlinousDatabase* database, ThreadContext* ctx) final;
	void open(bool loadscheme, AlinousDatabase* database, ThreadContext* ctx);
	void close(ThreadContext* ctx) throw()  final;
	TableMetadata* getMetadata(ThreadContext* ctx) throw()  final;
	ArrayList<TableIndex>* getIndexes(ThreadContext* ctx) throw()  final;
	String* getName(ThreadContext* ctx) throw()  final;
	String* getSchemaName(ThreadContext* ctx) throw() ;
	String* getBaseDir(ThreadContext* ctx) throw() ;
	bool equals(IObject* obj, ThreadContext* ctx) throw() ;
	Timestamp* getSchmeUpdated(ThreadContext* ctx) throw() ;
	DatatableUpdateCache* getUpdateHistoryCache(ThreadContext* ctx) throw() ;
	TableIndex* getPrimaryIndex(ThreadContext* ctx) throw()  final;
	int getColumnCount(ThreadContext* ctx) throw()  final;
	FileStorage* getDataStorage(ThreadContext* ctx) throw() ;
	BTree* getOidIndex(ThreadContext* ctx) throw() ;
	Integer* getTableId(ThreadContext* ctx) throw()  final;
	void setTableId(Integer* tableId, ThreadContext* ctx) throw() ;
	void syncScheme(ThreadContext* ctx);
	String* getDataStorageName(ThreadContext* ctx) throw() ;
	int indexSchemeSize(ThreadContext* ctx) throw() ;
	void syncIndexScheme(FileStorageEntryBuilder* builder, ThreadContext* ctx);
	void loadScheme(ThreadContext* ctx);
	String* getOidIndexName(ThreadContext* ctx) throw() ;
private:
	void loadIndexes(FileStorageEntryFetcher* fetcher, ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}}

#endif /* end of ALINOUS_DB_TABLE_ABSTRACTDATABASETABLE_H_ */
