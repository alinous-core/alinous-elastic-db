#ifndef ALINOUS_DB_TABLEREGIONMANAGER_H_
#define ALINOUS_DB_TABLEREGIONMANAGER_H_
namespace alinous {namespace db {
class ITableRegion;}}

namespace alinous {namespace db {
class LocalTableRegion;}}

namespace alinous {namespace db {
class TableSchemaCollection;}}

namespace alinous {namespace db {
class ITableSchema;}}

namespace alinous {namespace db {namespace table {
class TableMetadata;}}}

namespace alinous {namespace db {
class AlinousDatabase;}}

namespace alinous {namespace system {
class AlinousCore;}}

namespace java {namespace util {
template <typename  T> class List;}}

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
using ::java::util::ArrayList;
using ::java::util::List;
using ::alinous::btree::BTreeException;
using ::alinous::db::table::DatabaseException;
using ::alinous::db::table::TableMetadata;
using ::alinous::system::AlinousCore;
using ::alinous::system::AlinousException;



class TableRegionManager final : public virtual IObject {
public:
	TableRegionManager(const TableRegionManager& base) = default;
public:
	TableRegionManager(ThreadContext* ctx) throw()  : IObject(ctx), regions(GCUtils<List<ITableRegion> >::ins(this, (new(ctx) ArrayList<ITableRegion>(ctx)), ctx, __FILEW__, __LINE__, L""))
	{
	}
	void __construct_impl(ThreadContext* ctx) throw() 
	{
	}
	virtual ~TableRegionManager() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	List<ITableRegion>* regions;
public:
	void addRegion(ITableRegion* region, ThreadContext* ctx) throw() ;
	LocalTableRegion* getLocalRegion(ThreadContext* ctx) throw() ;
	TableSchemaCollection* getSchema(String* name, ThreadContext* ctx) throw() ;
	void commitCreateTable(String* regionName, String* schemaName, TableMetadata* tblMeta, AlinousDatabase* database, AlinousCore* core, ThreadContext* ctx);
	List<ITableRegion>* getRegions(ThreadContext* ctx) throw() ;
	void dispose(ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}

#endif /* end of ALINOUS_DB_TABLEREGIONMANAGER_H_ */
