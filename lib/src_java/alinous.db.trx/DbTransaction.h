#ifndef ALINOUS_DB_TRX_DBTRANSACTION_H_
#define ALINOUS_DB_TRX_DBTRANSACTION_H_
namespace alinous{namespace annotation{
class OneSource;
}}
namespace alinous {namespace db {namespace table {
class IDatabaseRecord;}}}

namespace alinous {namespace db {namespace table {
class IDatabaseTable;}}}

namespace alinous {namespace db {namespace trx {
class DbTransactionManager;}}}

namespace alinous {namespace db {
class AlinousDatabase;}}

namespace alinous {namespace system {
class AlinousCore;}}

namespace alinous {namespace db {namespace trx {namespace ddl {
class TrxSchemeManager;}}}}

namespace alinous {namespace db {namespace trx {namespace cache {
class TrxStorageManager;}}}}

namespace alinous {namespace db {namespace trx {namespace scan {
class ScanResult;}}}}

namespace alinous {namespace compile {namespace sql {namespace analyze {
class ScanTableMetadata;}}}}

namespace alinous {namespace compile {namespace sql {
class SelectStatement;}}}

namespace alinous {namespace runtime {namespace engine {
class ScriptMachine;}}}

namespace alinous {namespace compile {namespace sql {namespace select {
class SQLGroupBy;}}}}

namespace alinous {namespace compile {namespace sql {namespace analyze {
class ScanTableColumnIdentifier;}}}}

namespace alinous {namespace db {namespace trx {namespace scan {
class ScanResultIndex;}}}}

namespace alinous {namespace db {namespace trx {namespace scan {
class ITableTargetScanner;}}}}

namespace alinous {namespace db {namespace trx {namespace scan {
class ScanResultRecord;}}}}

namespace alinous {namespace btree {
class IBTree;}}

namespace alinous {namespace btree {namespace scan {
class BTreeScanner;}}}

namespace alinous {namespace system {
class AlinousException;}}

namespace java {namespace lang {
class Throwable;}}

namespace alinous {namespace runtime {namespace dom {
class DomArray;}}}

namespace alinous {namespace compile {namespace sql {namespace result {
class SelectResultDescription;}}}}

namespace alinous {namespace runtime {namespace dom {
class DomVariable;}}}

namespace alinous {namespace compile {namespace sql {
class UpdateStatement;}}}

namespace alinous {namespace compile {namespace declare {
class AlinousName;}}}

namespace alinous {namespace db {namespace table {namespace lockmonitor {
class DatabaseLockException;}}}}

namespace alinous {namespace compile {namespace sql {namespace select {namespace join {
class IJoinTarget;}}}}}

namespace alinous {namespace compile {namespace sql {namespace select {
class SQLWhere;}}}}

namespace alinous {namespace compile {namespace sql {namespace expression {
class ISQLExpression;}}}}

namespace alinous {namespace runtime {namespace variant {
class VariantValue;}}}

namespace alinous {namespace compile {namespace sql {
class UpdateSet;}}}

namespace alinous {namespace db {namespace trx {namespace cache {
class TrxRecordsCache;}}}}

namespace alinous {namespace db {namespace trx {namespace cache {
class CachedRecord;}}}}

namespace alinous {namespace compile {namespace sql {
class InsertStatement;}}}

namespace alinous {namespace runtime {namespace dom {
class IDomVariable;}}}

namespace alinous {namespace db {namespace trx {namespace cache {
class CulumnOrder;}}}}

namespace alinous {namespace compile {namespace sql {
class CreateIndexStatement;}}}

namespace alinous {namespace compile {namespace sql {
class TableAndSchema;}}}

namespace alinous {namespace db {namespace trx {
class CreateIndexMetadata;}}}

namespace alinous {namespace db {namespace table {
class TableMetadata;}}}

namespace alinous {namespace db {
class AlinousDbException;}}

namespace java {namespace io {
class IOException;}}

namespace alinous {namespace btree {
class BTreeException;}}

namespace alinous {namespace db {
class TableSchema;}}

namespace alinous {namespace db {
class TableSchemaCollection;}}

namespace java {namespace lang {
class InterruptedException;}}

namespace alinous {namespace runtime {namespace dom {
class VariableException;}}}

namespace alinous {namespace system {
class ISystemLog;}}

namespace alinous {namespace runtime {namespace parallel {
class ThreadPool;}}}

namespace alinous {namespace db {namespace trx {
class DbTransaction;}}}

namespace alinous {namespace db {namespace trx {
class TrxLockContext;}}}

namespace alinous {namespace db {namespace table {
class DatabaseException;}}}

namespace alinous {namespace db {namespace table {namespace scan {
class IndexScannerLockRequirement;}}}}

namespace java {namespace lang {
class IObject;
}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace db {namespace trx {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::java::io::IOException;
using ::java::util::ArrayList;
using ::alinous::btree::BTreeException;
using ::alinous::btree::IBTree;
using ::alinous::btree::scan::BTreeScanner;
using ::alinous::compile::declare::AlinousName;
using ::alinous::compile::sql::CreateIndexStatement;
using ::alinous::compile::sql::InsertStatement;
using ::alinous::compile::sql::SelectStatement;
using ::alinous::compile::sql::TableAndSchema;
using ::alinous::compile::sql::UpdateSet;
using ::alinous::compile::sql::UpdateStatement;
using ::alinous::compile::sql::analyze::ScanTableColumnIdentifier;
using ::alinous::compile::sql::analyze::ScanTableMetadata;
using ::alinous::compile::sql::expression::ISQLExpression;
using ::alinous::compile::sql::result::SelectResultDescription;
using ::alinous::compile::sql::select::SQLGroupBy;
using ::alinous::compile::sql::select::SQLWhere;
using ::alinous::compile::sql::select::join::IJoinTarget;
using ::alinous::db::AlinousDatabase;
using ::alinous::db::AlinousDbException;
using ::alinous::db::TableSchema;
using ::alinous::db::TableSchemaCollection;
using ::alinous::db::table::DatabaseException;
using ::alinous::db::table::IDatabaseRecord;
using ::alinous::db::table::IDatabaseTable;
using ::alinous::db::table::TableMetadata;
using ::alinous::db::table::lockmonitor::DatabaseLockException;
using ::alinous::db::table::scan::IndexScannerLockRequirement;
using ::alinous::db::trx::cache::CachedRecord;
using ::alinous::db::trx::cache::CulumnOrder;
using ::alinous::db::trx::cache::TrxRecordsCache;
using ::alinous::db::trx::cache::TrxStorageManager;
using ::alinous::db::trx::ddl::TrxSchemeManager;
using ::alinous::db::trx::scan::ITableTargetScanner;
using ::alinous::db::trx::scan::ScanResult;
using ::alinous::db::trx::scan::ScanResultIndex;
using ::alinous::db::trx::scan::ScanResultRecord;
using ::alinous::runtime::dom::DomArray;
using ::alinous::runtime::dom::DomVariable;
using ::alinous::runtime::dom::IDomVariable;
using ::alinous::runtime::dom::VariableException;
using ::alinous::runtime::engine::ScriptMachine;
using ::alinous::runtime::parallel::ThreadPool;
using ::alinous::runtime::variant::VariantValue;
using ::alinous::system::AlinousCore;
using ::alinous::system::AlinousException;
using ::alinous::system::ISystemLog;



class DbTransaction : public virtual IObject {
public:
	DbTransaction(const DbTransaction& base) = default;
public:
	DbTransaction(DbTransactionManager* mgr, String* tmpDir, AlinousDatabase* database, AlinousCore* core, long long commitId, ThreadContext* ctx) throw() ;
	void __construct_impl(DbTransactionManager* mgr, String* tmpDir, AlinousDatabase* database, AlinousCore* core, long long commitId, ThreadContext* ctx) throw() ;
	virtual ~DbTransaction() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
public:
	TrxLockContext* lockContext;
	int lockMode;
	long long commitId;
	DbTransactionManager* trxManager;
	TrxSchemeManager* trxSchema;
	TrxStorageManager* trxStorageManager;
	AlinousDatabase* database;
	ISystemLog* logger;
	DbTransaction* subTransaction;
	int resultSerial;
	String* trxDir;
private:
	long long soidSerial;
	AlinousCore* core;
public:
	virtual bool isVisible(IDatabaseRecord* record, IDatabaseTable* tableStore, ThreadContext* ctx) = 0;
	long long newSoid(ThreadContext* ctx) throw() ;
	ScanResult* newResult(ScanTableMetadata* metadata, ThreadContext* ctx);
	void select(SelectStatement* selectStmt, ScriptMachine* machine, bool debug, ThreadContext* ctx);
	void update(UpdateStatement* update, ScriptMachine* machine, bool debug, ThreadContext* ctx);
	void insert(InsertStatement* stmt, ScriptMachine* machine, bool debug, ThreadContext* ctx);
	void createIndex(CreateIndexStatement* stmt, ScriptMachine* machine, ThreadContext* ctx);
	void createTable(TableSchema* schema, ThreadContext* ctx) throw() ;
	TableMetadata* getMetadata(String* schemaName, String* tableName, ThreadContext* ctx) throw() ;
	void commit(ThreadContext* ctx);
	void close(ThreadContext* ctx);
	void dispose(ThreadContext* ctx) throw() ;
	DbTransactionManager* getTrxManager(ThreadContext* ctx) throw() ;
	TrxSchemeManager* getTrxSchema(ThreadContext* ctx) throw() ;
	TrxStorageManager* getTrxStorageManager(ThreadContext* ctx) throw() ;
	ISystemLog* getLogger(ThreadContext* ctx) throw() ;
	AlinousDatabase* getDatabase(ThreadContext* ctx) throw() ;
	ThreadPool* getThreadPool(ThreadContext* ctx) throw() ;
	bool equals(IObject* obj, ThreadContext* ctx) throw() ;
private:
	void noGroupBySelect(SelectStatement* selectStmt, ScriptMachine* machine, bool debug, ThreadContext* ctx);
	void doUpdate(ScanResultRecord* record, UpdateStatement* update, ScriptMachine* machine, bool debug, ThreadContext* ctx);
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}}

#endif /* end of ALINOUS_DB_TRX_DBTRANSACTION_H_ */
