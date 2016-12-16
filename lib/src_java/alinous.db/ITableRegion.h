#ifndef ALINOUS_DB_ITABLEREGION_H_
#define ALINOUS_DB_ITABLEREGION_H_
namespace alinous {namespace db {
class TableSchema;}}

namespace alinous {namespace db {namespace table {
class TableMetadata;}}}

namespace alinous {namespace runtime {namespace parallel {
class ThreadPool;}}}

namespace alinous {namespace system {
class AlinousCore;}}

namespace alinous {namespace btree {
class BTreeGlobalCache;}}

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
using ::alinous::btree::BTreeGlobalCache;
using ::alinous::db::table::DatabaseException;
using ::alinous::db::table::TableMetadata;
using ::alinous::runtime::parallel::ThreadPool;
using ::alinous::system::AlinousCore;
using ::alinous::system::AlinousException;



class ITableRegion : public virtual IObject {
public:
	ITableRegion(const ITableRegion& base) = default;
public:
	ITableRegion(ThreadContext* ctx) throw()  : IObject(ctx)
	{
	}
	void __construct_impl(ThreadContext* ctx) throw() 
	{
	}
	virtual ~ITableRegion() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
public:
	static int LOCAL_REGION;
	static int REMOTE_REGION;
public:
	virtual int getRegionType(ThreadContext* ctx) throw()  = 0;
	virtual String* getRegionName(ThreadContext* ctx) throw()  = 0;
	virtual TableSchema* getSchema(String* name, ThreadContext* ctx) throw()  = 0;
	virtual void createSchema(String* schemaName, ThreadContext* ctx) throw()  = 0;
	virtual void createTable(String* schemaName, TableMetadata* tblMeta, ThreadPool* threadPool, AlinousCore* core, BTreeGlobalCache* cache, ThreadContext* ctx) = 0;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}

#endif /* end of ALINOUS_DB_ITABLEREGION_H_ */
