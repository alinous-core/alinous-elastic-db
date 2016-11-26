#ifndef ALINOUS_REMOTE_REMOTETABLEREGIONHANDLE_H_
#define ALINOUS_REMOTE_REMOTETABLEREGIONHANDLE_H_
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

namespace alinous {namespace remote {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::java::io::IOException;
using ::alinous::btree::BTreeException;
using ::alinous::db::ITableRegion;
using ::alinous::db::TableSchema;
using ::alinous::db::table::DatabaseException;
using ::alinous::db::table::TableMetadata;
using ::alinous::system::AlinousException;



class RemoteTableRegionHandle final : public ITableRegion, public virtual IObject {
public:
	RemoteTableRegionHandle(const RemoteTableRegionHandle& base) = default;
public:
	RemoteTableRegionHandle(String* name, ThreadContext* ctx) throw() ;
	void __construct_impl(String* name, ThreadContext* ctx) throw() ;
	virtual ~RemoteTableRegionHandle() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	String* name;
public:
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

#endif /* end of ALINOUS_REMOTE_REMOTETABLEREGIONHANDLE_H_ */
