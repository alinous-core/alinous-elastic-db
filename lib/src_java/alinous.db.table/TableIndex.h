#ifndef ALINOUS_DB_TABLE_TABLEINDEX_H_
#define ALINOUS_DB_TABLE_TABLEINDEX_H_
namespace alinous{namespace annotation{
class OneSource;
}}
namespace alinous {namespace db {namespace table {
class TableColumnMetadata;}}}

namespace alinous {namespace db {
class AlinousDatabase;}}

namespace java {namespace io {
class File;}}

namespace alinous {namespace btree {
class BTree;}}

namespace alinous {namespace compile {namespace sql {namespace analyze {
class ScanTableColumnIdentifier;}}}}

namespace alinous {namespace db {namespace table {
class DatabaseRecord;}}}

namespace alinous {namespace db {namespace table {
class BTreeIndexKey;}}}

namespace alinous {namespace db {namespace table {
class TableIndexValue;}}}

namespace alinous {namespace db {
class AlinousDbException;}}

namespace java {namespace io {
class IOException;}}

namespace java {namespace lang {
class InterruptedException;}}

namespace alinous {namespace btree {
class BTreeException;}}

namespace java {namespace lang {
class StringBuilder;}}

namespace alinous {namespace db {namespace table {
class TableIndex;}}}

namespace alinous {namespace buffer {namespace storage {
class FileStorageEntryFetcher;}}}

namespace alinous {namespace buffer {namespace storage {
class FileStorageEntryBuilder;}}}

namespace alinous {namespace db {namespace table {
class IBtreeTableIndex;}}}

namespace alinous {namespace btree {
class IBTreeValue;}}

namespace alinous {namespace runtime {namespace dom {
class VariableException;}}}

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
using ::java::util::ArrayList;
using ::alinous::btree::BTree;
using ::alinous::btree::BTreeException;
using ::alinous::btree::IBTreeValue;
using ::alinous::buffer::storage::FileStorageEntryBuilder;
using ::alinous::buffer::storage::FileStorageEntryFetcher;
using ::alinous::compile::sql::analyze::ScanTableColumnIdentifier;
using ::alinous::db::AlinousDatabase;
using ::alinous::db::AlinousDbException;
using ::alinous::runtime::dom::VariableException;



class TableIndex final : public IBtreeTableIndex, public virtual IObject {
public:
	TableIndex(const TableIndex& base) = default;
public:
	TableIndex(String* name, String* baseDir, bool primary, ArrayList<TableColumnMetadata>* metadata, ThreadContext* ctx) throw() ;
	void __construct_impl(String* name, String* baseDir, bool primary, ArrayList<TableColumnMetadata>* metadata, ThreadContext* ctx) throw() ;
	virtual ~TableIndex() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
public:
	String* name;
	BTree* storage;
private:
	String* baseDir;
	bool primary;
	ArrayList<TableColumnMetadata>* columns;
	String* filePath;
public:
	constexpr static const int capacity{1024};
	constexpr static const int BLOCK_SIZE{128};
	constexpr static const int maxCache{256};
public:
	bool isOpened(ThreadContext* ctx) throw() ;
	void open(AlinousDatabase* database, ThreadContext* ctx);
	void close(ThreadContext* ctx);
	bool isAvailable(ArrayList<String>* columnsStr, ThreadContext* ctx) throw() ;
	bool isAvailableByScanId(ArrayList<ScanTableColumnIdentifier>* columnIds, ThreadContext* ctx) throw() ;
	void addIndexValue(DatabaseRecord* record, ThreadContext* ctx);
	void createIndex(AlinousDatabase* database, ThreadContext* ctx);
	int archiveSize(ThreadContext* ctx) throw() ;
	void appendToEntry(FileStorageEntryBuilder* builder, ThreadContext* ctx);
	ArrayList<TableColumnMetadata>* getColumns(ThreadContext* ctx) throw()  final;
private:
	void setPath(ThreadContext* ctx) throw() ;
public:
	static TableIndex* valueFromFetcher(FileStorageEntryFetcher* fetcher, String* baseDir, ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}}

#endif /* end of ALINOUS_DB_TABLE_TABLEINDEX_H_ */
