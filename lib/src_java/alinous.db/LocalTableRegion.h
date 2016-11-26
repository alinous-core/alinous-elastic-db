#ifndef ALINOUS_DB_LOCALTABLEREGION_H_
#define ALINOUS_DB_LOCALTABLEREGION_H_
namespace alinous {namespace db {namespace table {namespace cache {
class RecordCacheEngine;}}}}

namespace alinous {namespace system {
class ISystemLog;}}

namespace alinous {namespace db {
class AlinousDatabase;}}

namespace alinous {namespace db {
class SchemaManager;}}

namespace alinous {namespace db {
class TableSchema;}}

namespace alinous {namespace db {namespace table {
class TableMetadata;}}}

namespace alinous {namespace db {
class ITableRegion;}}

namespace java {namespace io {
class IOException;}}

namespace alinous {namespace btree {
class BTreeException;}}

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
using ::java::io::IOException;
using ::alinous::btree::BTreeException;
using ::alinous::db::table::DatabaseException;
using ::alinous::db::table::TableMetadata;
using ::alinous::db::table::cache::RecordCacheEngine;
using ::alinous::system::AlinousException;
using ::alinous::system::ISystemLog;



class LocalTableRegion final : public ITableRegion, public virtual IObject {
public:
	LocalTableRegion(const LocalTableRegion& base) = default;
public:
	LocalTableRegion(RecordCacheEngine* cacheEngine, String* dataDir, ISystemLog* logger, AlinousDatabase* database, ThreadContext* ctx) throw() ;
	void __construct_impl(RecordCacheEngine* cacheEngine, String* dataDir, ISystemLog* logger, AlinousDatabase* database, ThreadContext* ctx) throw() ;
	virtual ~LocalTableRegion() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
public:
	SchemaManager* schemas;
public:
	SchemaManager* getSchemaManager(ThreadContext* ctx) throw() ;
	int getRegionType(ThreadContext* ctx) throw()  final;
	String* getRegionName(ThreadContext* ctx) throw()  final;
	TableSchema* getSchema(String* name, ThreadContext* ctx) throw()  final;
	void createSchema(String* schemaName, ThreadContext* ctx) throw()  final;
	void createTable(String* schemaName, TableMetadata* tblMeta, ThreadContext* ctx) final;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}

#endif /* end of ALINOUS_DB_LOCALTABLEREGION_H_ */
