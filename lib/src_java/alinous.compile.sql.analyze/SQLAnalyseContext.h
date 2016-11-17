#ifndef ALINOUS_COMPILE_SQL_ANALYZE_SQLANALYSECONTEXT_H_
#define ALINOUS_COMPILE_SQL_ANALYZE_SQLANALYSECONTEXT_H_
namespace alinous{namespace annotation{
class OneSource;
}}
namespace alinous {namespace db {
class AlinousDatabase;}}

namespace alinous {namespace runtime {namespace engine {
class ScriptMachine;}}}

namespace alinous {namespace compile {namespace sql {namespace analyze {
class ScanTableMetadata;}}}}

namespace alinous {namespace compile {namespace sql {namespace analyze {
class ScanTableColumnIdentifier;}}}}

namespace alinous {namespace compile {namespace sql {namespace expression {
class ISQLExpression;}}}}

namespace alinous {namespace compile {namespace sql {namespace analyze {
class SQLAnalyseContext;}}}}

namespace alinous {namespace db {namespace table {
class DatabaseTable;}}}

namespace java {namespace util {
template <typename  T, typename V> class HashMap;}}

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
using ::java::util::HashMap;
using ::alinous::compile::sql::expression::ISQLExpression;
using ::alinous::db::AlinousDatabase;
using ::alinous::db::table::DatabaseTable;
using ::alinous::runtime::engine::ScriptMachine;



class SQLAnalyseContext final : public virtual IObject {
public:
	SQLAnalyseContext(const SQLAnalyseContext& base) = default;
public:
	SQLAnalyseContext(AlinousDatabase* database, ScriptMachine* machine, ThreadContext* ctx) throw() ;
	void __construct_impl(AlinousDatabase* database, ScriptMachine* machine, ThreadContext* ctx) throw() ;
	virtual ~SQLAnalyseContext() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	AlinousDatabase* database;
	ScriptMachine* machine;
	ArrayList<ScanTableMetadata>* tables;
	HashMap<String,ScanTableMetadata>* asNameMap;
public:
	void addTable(ScanTableMetadata* table, String* asName, ThreadContext* ctx) throw() ;
	ArrayList<ScanTableMetadata>* getTables(ThreadContext* ctx) throw() ;
	AlinousDatabase* getDatabase(ThreadContext* ctx) throw() ;
	ScanTableMetadata* findTableByAsName(String* asname, ThreadContext* ctx) throw() ;
	ScriptMachine* getMachine(ThreadContext* ctx) throw() ;
public:
	static ArrayList<ScanTableColumnIdentifier>* joinList(ArrayList<ScanTableColumnIdentifier>* list, ISQLExpression* exp, ThreadContext* ctx) throw() ;
	static String* findTable(SQLAnalyseContext* context, String* schema, String* column, ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}}}

#endif /* end of ALINOUS_COMPILE_SQL_ANALYZE_SQLANALYSECONTEXT_H_ */
