#ifndef ALINOUS_DB_TRX_DDL_TRXSCHEMEMANAGER_H_
#define ALINOUS_DB_TRX_DDL_TRXSCHEMEMANAGER_H_
namespace alinous{namespace annotation{
class OneSource;
}}
namespace alinous {namespace db {
class AlinousDatabase;}}

namespace alinous {namespace system {
class ISystemLog;}}

namespace alinous {namespace system {
class AlinousCore;}}

namespace alinous {namespace btree {
class BTreeGlobalCache;}}

namespace alinous {namespace db {
class TableSchema;}}

namespace alinous {namespace db {
class AlinousDbException;}}

namespace java {namespace io {
class IOException;}}

namespace java {namespace lang {
class InterruptedException;}}

namespace alinous {namespace btree {
class BTreeException;}}

namespace alinous {namespace db {namespace table {
class DatabaseException;}}}

namespace alinous {namespace db {namespace trx {
class CreateIndexMetadata;}}}

namespace alinous {namespace db {
class TableSchemaCollection;}}

namespace alinous {namespace db {namespace table {
class IDatabaseTable;}}}

namespace java {namespace lang {
class Throwable;}}

namespace alinous {namespace db {
class TableRegionManager;}}

namespace java {namespace util {
template <typename  T> class Set;}}

namespace java {namespace util {
template <typename  T> class Iterator;}}

namespace alinous {namespace db {namespace table {
class TableMetadata;}}}

namespace alinous {namespace system {
class AlinousException;}}

namespace java {namespace lang {
class IObject;
}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace db {namespace trx {namespace ddl {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::java::io::IOException;
using ::java::util::ArrayList;
using ::java::util::Iterator;
using ::java::util::Set;
using ::alinous::btree::BTreeException;
using ::alinous::btree::BTreeGlobalCache;
using ::alinous::db::AlinousDatabase;
using ::alinous::db::AlinousDbException;
using ::alinous::db::TableRegionManager;
using ::alinous::db::TableSchema;
using ::alinous::db::TableSchemaCollection;
using ::alinous::db::table::DatabaseException;
using ::alinous::db::table::IDatabaseTable;
using ::alinous::db::table::TableMetadata;
using ::alinous::db::trx::CreateIndexMetadata;
using ::alinous::system::AlinousCore;
using ::alinous::system::AlinousException;
using ::alinous::system::ISystemLog;



class TrxSchemeManager final : public virtual IObject {
public:
	TrxSchemeManager(const TrxSchemeManager& base) = default;
public:
	TrxSchemeManager(AlinousDatabase* database, ISystemLog* logger, ThreadContext* ctx) throw() ;
	void __construct_impl(AlinousDatabase* database, ISystemLog* logger, ThreadContext* ctx) throw() ;
	virtual ~TrxSchemeManager() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	ArrayList<TableSchema>* newMetadata;
	ArrayList<TableSchema>* droppedMetadata;
	ArrayList<CreateIndexMetadata>* createIndexMetadata;
	ISystemLog* logger;
	bool hasOperation;
	AlinousDatabase* database;
public:
	void executeCommit(AlinousCore* core, BTreeGlobalCache* cache, ThreadContext* ctx);
	void addIndex(CreateIndexMetadata* meta, ThreadContext* ctx) throw() ;
	void addNewMetadata(TableSchema* metadata, ThreadContext* ctx) throw() ;
	TableMetadata* getTableMetadata(String* schemaName, String* tableName, ThreadContext* ctx) throw() ;
	bool tableExists(String* schemaName, String* tableName, ThreadContext* ctx) throw() ;
	bool isDropped(TableSchema* metadata, ThreadContext* ctx) throw() ;
	void reset(ThreadContext* ctx) throw() ;
	void dispose(ThreadContext* ctx) throw() ;
	bool isHasOperation(ThreadContext* ctx) throw() ;
private:
	void executeCreateIndex(CreateIndexMetadata* meta, AlinousCore* core, BTreeGlobalCache* cache, ThreadContext* ctx) throw() ;
	void executeCreateSchemaAndTable(TableSchema* sc, AlinousCore* core, ThreadContext* ctx);
	TableSchema* getNewSchema(String* schemaName, ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}}}

#endif /* end of ALINOUS_DB_TRX_DDL_TRXSCHEMEMANAGER_H_ */
