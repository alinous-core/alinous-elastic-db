#ifndef ALINOUS_DB_TRX_CACHE_TRXRECORDSCACHE_H_
#define ALINOUS_DB_TRX_CACHE_TRXRECORDSCACHE_H_
namespace alinous{namespace annotation{
class OneSource;
}}
namespace alinous {namespace db {namespace trx {namespace cache {
class TrxRecordsCache;}}}}

namespace alinous {namespace db {namespace table {
class TableMetadata;}}}

namespace alinous {namespace db {namespace trx {
class DbTransaction;}}}

namespace alinous {namespace btreememory {
class BTreeOnMemory;}}

namespace alinous {namespace db {namespace table {
class TableIndexMetadata;}}}

namespace alinous {namespace db {
class AlinousDbException;}}

namespace alinous {namespace runtime {namespace dom {
class VariableException;}}}

namespace java {namespace lang {
class InterruptedException;}}

namespace java {namespace io {
class IOException;}}

namespace alinous {namespace btree {
class BTreeException;}}

namespace alinous {namespace system {
class AlinousException;}}

namespace alinous {namespace db {
class AlinousDatabase;}}

namespace java {namespace io {
class File;}}

namespace alinous {namespace system {
class AlinousCore;}}

namespace alinous {namespace btree {
class BTree;}}

namespace alinous {namespace db {namespace trx {namespace cache {
class TrxRecordCacheIndex;}}}}

namespace java {namespace lang {
class StringBuilder;}}

namespace alinous {namespace compile {namespace sql {namespace analyze {
class ScanTableColumnIdentifier;}}}}

namespace alinous {namespace db {namespace table {
class TableColumnMetadata;}}}

namespace alinous {namespace db {namespace table {
class IDatabaseTable;}}}

namespace alinous {namespace runtime {namespace parallel {
class SequentialBackgroundJob;}}}

namespace alinous {namespace btree {namespace scan {
class BTreeScanner;}}}

namespace alinous {namespace btree {
class IBTreeNode;}}

namespace alinous {namespace btree {
class IBTreeValue;}}

namespace alinous {namespace db {namespace trx {namespace cache {
class CachedRecord;}}}}

namespace java {namespace lang {
class Throwable;}}

namespace alinous {namespace db {namespace table {
class IOidPublisher;}}}

namespace alinous {namespace lock {namespace unique {
class UniqueExclusiveLockClient;}}}

namespace alinous {namespace compile {namespace sql {namespace analyze {
class TableMetadataUniqueCollection;}}}}

namespace alinous {namespace compile {namespace sql {namespace analyze {
class ScanUnique;}}}}

namespace alinous {namespace btree {
class LongKey;}}

namespace alinous {namespace db {namespace trx {namespace scan {
class ScanResultRecord;}}}}

namespace alinous {namespace runtime {namespace dom {
class IDomVariable;}}}

namespace alinous {namespace db {namespace trx {namespace cache {
class CulumnOrder;}}}}

namespace alinous {namespace runtime {namespace dom {
class DomArray;}}}

namespace alinous {namespace system {
class AlinousNotSupportedException;}}

namespace alinous {namespace btree {
class IBTree;}}

namespace alinous {namespace btree {
class IBTreeKey;}}

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
using ::alinous::btree::IBTreeKey;
using ::alinous::btree::IBTreeNode;
using ::alinous::btree::IBTreeValue;
using ::alinous::btree::LongKey;
using ::alinous::btree::scan::BTreeScanner;
using ::alinous::btreememory::BTreeOnMemory;
using ::alinous::compile::sql::analyze::ScanTableColumnIdentifier;
using ::alinous::compile::sql::analyze::ScanUnique;
using ::alinous::compile::sql::analyze::TableMetadataUniqueCollection;
using ::alinous::db::AlinousDatabase;
using ::alinous::db::AlinousDbException;
using ::alinous::db::table::IDatabaseTable;
using ::alinous::db::table::IOidPublisher;
using ::alinous::db::table::TableColumnMetadata;
using ::alinous::db::table::TableIndexMetadata;
using ::alinous::db::table::TableMetadata;
using ::alinous::db::trx::DbTransaction;
using ::alinous::db::trx::scan::ScanResultRecord;
using ::alinous::lock::unique::UniqueExclusiveLockClient;
using ::alinous::runtime::dom::DomArray;
using ::alinous::runtime::dom::IDomVariable;
using ::alinous::runtime::dom::VariableException;
using ::alinous::runtime::parallel::SequentialBackgroundJob;
using ::alinous::system::AlinousCore;
using ::alinous::system::AlinousException;
using ::alinous::system::AlinousNotSupportedException;



class TrxRecordsCache : public virtual IObject {
public:
	TrxRecordsCache(const TrxRecordsCache& base) = default;
public:
	TrxRecordsCache(ThreadContext* ctx) throw() ;
	void __construct_impl(ThreadContext* ctx) throw() ;
	virtual ~TrxRecordsCache() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
public:
	bool insert;
	String* tmpDir;
	String* schema;
	String* tableName;
	String* storagePath;
	IBTree* storage;
	TableMetadata* metadata;
	long long serial;
	DbTransaction* trx;
private:
	ArrayList<TrxRecordCacheIndex>* indexList;
public:
	constexpr static const long long BLOCK_SIZE{256};
public:
	TrxRecordsCache* init(String* tmpDir, String* schema, String* tableName, TableMetadata* metadata, DbTransaction* trx, bool insert, ThreadContext* ctx);
	void switchToDisk(AlinousDatabase* database, ThreadContext* ctx);
	void dispose(ThreadContext* ctx);
	TrxRecordCacheIndex* getCachedIndex(ArrayList<ScanTableColumnIdentifier>* colIdList, ThreadContext* ctx) throw() ;
	virtual bool commitUpdateRecord(AlinousDatabase* db, IDatabaseTable* table, long long newCommitId, ThreadContext* ctx);
	virtual bool commitInsertRecord(DbTransaction* trx, AlinousDatabase* db, IDatabaseTable* table, long long newCommitId, ThreadContext* ctx);
	CachedRecord* getRecordByOid(long long oid, ThreadContext* ctx);
	void insertUpdateRecord(ScanResultRecord* srecord, ThreadContext* ctx);
	void insertRecord(ArrayList<IDomVariable>* values, ArrayList<CulumnOrder>* columns, ThreadContext* ctx);
	void createIndex(String* indexName, ArrayList<String>* columns, TableMetadata* tblMetadata, AlinousDatabase* database, ThreadContext* ctx);
	DbTransaction* getTrx(ThreadContext* ctx) throw() ;
	IBTreeNode* findByKey(LongKey* oidKey, ThreadContext* ctx);
private:
	void setStorageFilePath(ThreadContext* ctx) throw() ;
	bool matchIndexByIdList(ArrayList<TableColumnMetadata>* cachedIndexCols, ArrayList<ScanTableColumnIdentifier>* colIdList, ThreadContext* ctx) throw() ;
	void checkInsertUnique(DbTransaction* trx, IDatabaseTable* table, ThreadContext* ctx);
	void ckeckUniques(UniqueExclusiveLockClient* uniqueLock, TableMetadataUniqueCollection* uniques, CachedRecord* record, ThreadContext* ctx);
	void buildFirstIndex(TrxRecordCacheIndex* newIndex, ThreadContext* ctx);
	CachedRecord* getLastCommitedRecord(IBTreeNode* node, ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx);
};

}}}}

#endif /* end of ALINOUS_DB_TRX_CACHE_TRXRECORDSCACHE_H_ */
