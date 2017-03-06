#ifndef ALINOUS_COMPILE_SQL_ANALYZE_SCANTABLEMETADATA_H_
#define ALINOUS_COMPILE_SQL_ANALYZE_SCANTABLEMETADATA_H_
namespace alinous{namespace annotation{
class OneSource;
}}
namespace alinous {namespace compile {namespace sql {namespace analyze {
class ScanTableMetadata;}}}}

namespace alinous {namespace compile {namespace sql {namespace analyze {
class ScanTableIdentifier;}}}}

namespace alinous {namespace compile {namespace sql {namespace analyze {
class ScanTableColumnMetadata;}}}}

namespace alinous {namespace compile {namespace sql {namespace analyze {
class ScanTableIndexMetadata;}}}}

namespace alinous {namespace db {namespace table {
class TableMetadata;}}}

namespace alinous {namespace compile {namespace sql {
class TableAndSchema;}}}

namespace alinous {namespace db {namespace table {
class TableColumnMetadata;}}}

namespace alinous {namespace compile {namespace sql {namespace analyze {
class ScanTableColumnIdentifier;}}}}

namespace alinous {namespace db {namespace table {
class TableIndexMetadata;}}}

namespace alinous {namespace compile {namespace sql {namespace expression {
class ISQLExpression;}}}}

namespace java {namespace lang {
class IObject;
}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace compile {namespace sql {namespace analyze {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::java::util::ArrayList;
using ::alinous::compile::sql::TableAndSchema;
using ::alinous::compile::sql::expression::ISQLExpression;
using ::alinous::db::table::TableColumnMetadata;
using ::alinous::db::table::TableIndexMetadata;
using ::alinous::db::table::TableMetadata;



class ScanTableMetadata final : public virtual IObject {
public:
	ScanTableMetadata(const ScanTableMetadata& base) = default;
public:
	ScanTableMetadata(ThreadContext* ctx) throw() ;
	void __construct_impl(ThreadContext* ctx) throw() ;
	ScanTableMetadata(ScanTableIdentifier* table, ThreadContext* ctx) throw() ;
	void __construct_impl(ScanTableIdentifier* table, ThreadContext* ctx) throw() ;
	ScanTableMetadata(TableMetadata* metadata, String* asName, ThreadContext* ctx) throw() ;
	void __construct_impl(TableMetadata* metadata, String* asName, ThreadContext* ctx) throw() ;
	virtual ~ScanTableMetadata() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	ArrayList<ScanTableIdentifier>* table;
	ArrayList<ScanTableColumnMetadata>* columns;
	ArrayList<ScanTableIndexMetadata>* indexes;
	bool dom;
public:
	ScanTableMetadata* copy(ThreadContext* ctx) throw() ;
	bool hasTableColumn(ISQLExpression* exp, ThreadContext* ctx) throw() ;
	ScanTableIdentifier* getRelevantTableId(ISQLExpression* exp, ThreadContext* ctx) throw() ;
	int getColumnOrder(ScanTableColumnIdentifier* colId, ThreadContext* ctx) throw() ;
	ArrayList<ScanTableIndexMetadata>* getAbailableIndexes(ScanTableIdentifier* tableId, ArrayList<ScanTableColumnIdentifier>* columns, ThreadContext* ctx) throw() ;
	void join(ScanTableMetadata* meta, ThreadContext* ctx) throw() ;
	bool hasTable(ScanTableIdentifier* table, ThreadContext* ctx) throw() ;
	bool hasTable(ISQLExpression* exp, ThreadContext* ctx) throw() ;
	void addColumn(ScanTableColumnMetadata* col, ThreadContext* ctx) throw() ;
	void addindex(ScanTableIdentifier* tableId, ArrayList<ScanTableColumnIdentifier>* columns, ThreadContext* ctx) throw() ;
	ArrayList<ScanTableColumnMetadata>* getColumns(ThreadContext* ctx) throw() ;
	ScanTableColumnMetadata* getColumn(ScanTableColumnIdentifier* colId, ThreadContext* ctx) throw() ;
	ScanTableIdentifier* getFirstTableId(ThreadContext* ctx) throw() ;
	String* getSchemaName(ThreadContext* ctx) throw() ;
	String* getTableName(ThreadContext* ctx) throw() ;
	bool isDom(ThreadContext* ctx) throw() ;
	void setDom(bool dom, ThreadContext* ctx) throw() ;
private:
	ArrayList<ScanTableColumnIdentifier>* getColumnIdsFromIndex(ScanTableIdentifier* tableId, TableIndexMetadata* indexMeta, ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx);
};

}}}}

#endif /* end of ALINOUS_COMPILE_SQL_ANALYZE_SCANTABLEMETADATA_H_ */
