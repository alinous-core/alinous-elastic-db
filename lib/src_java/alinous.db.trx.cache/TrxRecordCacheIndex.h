#ifndef ALINOUS_DB_TRX_CACHE_TRXRECORDCACHEINDEX_H_
#define ALINOUS_DB_TRX_CACHE_TRXRECORDCACHEINDEX_H_
namespace alinous{namespace annotation{
class OneSource;
}}
namespace alinous {namespace db {namespace table {
class TableColumnMetadata;}}}

namespace alinous {namespace btreememory {
class BTreeOnMemory;}}

namespace alinous {namespace db {
class AlinousDatabase;}}

namespace java {namespace io {
class File;}}

namespace alinous {namespace system {
class AlinousCore;}}

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

namespace alinous {namespace db {namespace table {
class IDatabaseRecord;}}}

namespace alinous {namespace db {namespace table {
class BTreeIndexKey;}}}

namespace alinous {namespace btree {
class LongValue;}}

namespace java {namespace lang {
class StringBuilder;}}

namespace alinous {namespace btree {
class IBTree;}}

namespace alinous {namespace db {namespace table {
class IBtreeTableIndex;}}}

namespace alinous {namespace btree {
class IBTreeValue;}}

namespace alinous {namespace system {
class AlinousException;}}

namespace java {namespace lang {
class IObject;
}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace db {namespace trx {namespace cache {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::java::io::File;
using ::java::io::IOException;
using ::java::util::ArrayList;
using ::alinous::btree::BTree;
using ::alinous::btree::BTreeException;
using ::alinous::btree::IBTree;
using ::alinous::btree::IBTreeValue;
using ::alinous::btree::LongValue;
using ::alinous::btreememory::BTreeOnMemory;
using ::alinous::db::AlinousDatabase;
using ::alinous::db::AlinousDbException;
using ::alinous::db::table::BTreeIndexKey;
using ::alinous::db::table::IBtreeTableIndex;
using ::alinous::db::table::IDatabaseRecord;
using ::alinous::db::table::TableColumnMetadata;
using ::alinous::system::AlinousCore;
using ::alinous::system::AlinousException;



class TrxRecordCacheIndex final : public IBtreeTableIndex, public virtual IObject {
public:
	TrxRecordCacheIndex(const TrxRecordCacheIndex& base) = default;
public:
	TrxRecordCacheIndex(String* name, String* baseDir, ArrayList<TableColumnMetadata>* metadata, ThreadContext* ctx) throw() ;
	void __construct_impl(String* name, String* baseDir, ArrayList<TableColumnMetadata>* metadata, ThreadContext* ctx) throw() ;
	virtual ~TrxRecordCacheIndex() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	String* name;
	String* baseDir;
	ArrayList<TableColumnMetadata>* columns;
	String* filePath;
	IBTree* storage;
public:
	constexpr static const int capacity{1024};
	constexpr static const int BLOCK_SIZE{128};
	constexpr static const int maxCache{256};
public:
	void createIndex(ThreadContext* ctx);
	void switchToDisk(AlinousDatabase* database, ThreadContext* ctx);
	bool isOpened(ThreadContext* ctx) throw() ;
	void addIndexValue(IDatabaseRecord* record, long long oid, ThreadContext* ctx);
	void open(AlinousDatabase* database, ThreadContext* ctx);
	void close(ThreadContext* ctx);
	void dispose(ThreadContext* ctx) throw() ;
	ArrayList<TableColumnMetadata>* getColumns(ThreadContext* ctx) throw()  final;
	IBTree* getStorage(ThreadContext* ctx) throw() ;
private:
	void setPath(ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx);
};

}}}}

#endif /* end of ALINOUS_DB_TRX_CACHE_TRXRECORDCACHEINDEX_H_ */
