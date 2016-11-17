#ifndef ALINOUS_DB_TABLE_DATABASETABLE_H_
#define ALINOUS_DB_TABLE_DATABASETABLE_H_
namespace alinous{namespace annotation{
class OneSource;
}}
namespace alinous {namespace db {namespace table {namespace cache {
class RecordCacheEngine;}}}}

namespace alinous {namespace db {namespace table {
class TableIndex;}}}

namespace alinous {namespace compile {namespace sql {namespace analyze {
class ScanTableColumnIdentifier;}}}}

namespace alinous {namespace db {namespace table {
class TableColumnMetadata;}}}

namespace alinous {namespace db {namespace table {
class DatatableUpdateSupport;}}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace db {namespace table {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::java::util::ArrayList;
using ::alinous::compile::sql::analyze::ScanTableColumnIdentifier;
using ::alinous::db::table::cache::RecordCacheEngine;



class DatabaseTable final : public DatatableUpdateSupport {
public:
	DatabaseTable(const DatabaseTable& base) = default;
public:
	DatabaseTable(RecordCacheEngine* cacheEngine, String* schema, String* name, String* baseDir, ThreadContext* ctx) throw() ;
	void __construct_impl(RecordCacheEngine* cacheEngine, String* schema, String* name, String* baseDir, ThreadContext* ctx) throw() ;
	virtual ~DatabaseTable() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
public:
	TableIndex* getTableIndexByColIds(ArrayList<ScanTableColumnIdentifier>* columns, ThreadContext* ctx) throw() ;
	TableIndex* getAbailableIndex(ArrayList<String>* columns, ThreadContext* ctx) throw() ;
	TableIndex* getAbailableIndexByScanColId(ArrayList<ScanTableColumnIdentifier>* columns, ThreadContext* ctx) throw() ;
	TableIndex* getTableIndex(ArrayList<String>* columns, ThreadContext* ctx) throw() ;
private:
	bool matchIndexByIdList(ArrayList<TableColumnMetadata>* columnsMetadataList, ArrayList<ScanTableColumnIdentifier>* columns, ThreadContext* ctx) throw() ;
	bool matchIndexByStrList(ArrayList<TableColumnMetadata>* columnsMetadataList, ArrayList<String>* columns, ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}}

#endif /* end of ALINOUS_DB_TABLE_DATABASETABLE_H_ */
