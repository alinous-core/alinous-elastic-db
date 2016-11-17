#ifndef ALINOUS_DB_TRX_CACHE_TRXSTORAGEMANAGER_H_
#define ALINOUS_DB_TRX_CACHE_TRXSTORAGEMANAGER_H_
namespace alinous{namespace annotation{
class OneSource;
}}
namespace alinous {namespace db {namespace trx {
class DbTransaction;}}}

namespace java {namespace io {
class File;}}

namespace alinous {namespace db {namespace trx {namespace cache {
class TrxRecordsCache;}}}}

namespace alinous {namespace db {namespace table {
class TableMetadata;}}}

namespace alinous {namespace db {
class AlinousDbException;}}

namespace java {namespace util {
template <typename  T, typename V> class HashMap;}}

namespace alinous {namespace db {
class AlinousDatabase;}}

namespace java {namespace util {
template <typename  T> class Iterator;}}

namespace alinous {namespace db {
class TableSchema;}}

namespace alinous {namespace db {namespace table {
class DatabaseTable;}}}

namespace alinous {namespace system {
class AlinousException;}}

namespace alinous {namespace db {namespace trx {
class CreateIndexMetadata;}}}

namespace alinous {namespace compile {namespace sql {
class TableAndSchema;}}}

namespace java {namespace lang {
class InterruptedException;}}

namespace alinous {namespace runtime {namespace dom {
class VariableException;}}}

namespace java {namespace io {
class IOException;}}

namespace alinous {namespace btree {
class BTreeException;}}

namespace alinous {namespace system {namespace utils {
class FileUtils;}}}

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
using ::java::util::HashMap;
using ::java::util::Iterator;
using ::alinous::btree::BTreeException;
using ::alinous::compile::sql::TableAndSchema;
using ::alinous::db::AlinousDatabase;
using ::alinous::db::AlinousDbException;
using ::alinous::db::TableSchema;
using ::alinous::db::table::DatabaseTable;
using ::alinous::db::table::TableMetadata;
using ::alinous::db::trx::CreateIndexMetadata;
using ::alinous::db::trx::DbTransaction;
using ::alinous::runtime::dom::VariableException;
using ::alinous::system::AlinousException;
using ::alinous::system::utils::FileUtils;



class TrxStorageManager final : public virtual IObject {
public:
	TrxStorageManager(const TrxStorageManager& base) = default;
public:
	TrxStorageManager(String* tmpDir, DbTransaction* trx, ThreadContext* ctx) throw() ;
	void __construct_impl(String* tmpDir, DbTransaction* trx, ThreadContext* ctx) throw() ;
	virtual ~TrxStorageManager() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	String* tmpDir;
	bool hasOperation;
	HashMap<String,HashMap<String,TrxRecordsCache>>* insertStorages;
	HashMap<String,HashMap<String,TrxRecordsCache>>* updateStorages;
	DbTransaction* trx;
public:
	TrxRecordsCache* getInsertCache(String* schema, String* table, ThreadContext* ctx);
	TrxRecordsCache* getUpdateCache(String* schema, String* table, ThreadContext* ctx);
	TrxRecordsCache* getUpdateCacheWithCreate(String* schema, String* table, ThreadContext* ctx);
	TrxRecordsCache* getInsertCacheWithCreate(String* schema, String* table, ThreadContext* ctx);
	void commit(long long newCommitId, ThreadContext* ctx);
	bool isHasOperation(ThreadContext* ctx) throw() ;
	void setHasOperation(bool hasOperation, ThreadContext* ctx) throw() ;
	void reset(ThreadContext* ctx) throw() ;
	void dispose(ThreadContext* ctx) throw() ;
	void addIndex(CreateIndexMetadata* createMeta, TableMetadata* tblmetadata, AlinousDatabase* database, ThreadContext* ctx);
private:
	void initStorage(ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}}}

#endif /* end of ALINOUS_DB_TRX_CACHE_TRXSTORAGEMANAGER_H_ */
