#ifndef ALINOUS_COMPILE_SQL_RESULT_SELECTRESULTDESCRIPTION_H_
#define ALINOUS_COMPILE_SQL_RESULT_SELECTRESULTDESCRIPTION_H_
namespace alinous {namespace compile {namespace sql {namespace parts {
class SQLExpressionList;}}}}

namespace alinous {namespace compile {namespace sql {namespace analyze {
class ScanTableMetadata;}}}}

namespace alinous {namespace compile {namespace sql {namespace expression {
class ISQLExpression;}}}}

namespace alinous {namespace compile {namespace sql {namespace parts {
class SQLExpressionListAll;}}}}

namespace alinous {namespace compile {namespace sql {namespace result {
class AllColumnResult;}}}}

namespace alinous {namespace compile {namespace sql {namespace analyze {
class ScanTableColumnIdentifier;}}}}

namespace alinous {namespace compile {namespace sql {namespace result {
class ColumnResult;}}}}

namespace alinous {namespace compile {namespace sql {namespace expression {
class SQLExpressionStream;}}}}

namespace alinous {namespace compile {namespace sql {namespace result {
class FunctionResult;}}}}

namespace alinous {namespace runtime {namespace dom {
class DomVariable;}}}

namespace alinous {namespace db {namespace trx {namespace scan {
class ScanResultRecord;}}}}

namespace alinous {namespace runtime {namespace engine {
class ScriptMachine;}}}

namespace alinous {namespace compile {namespace sql {namespace result {
class AbstructSelectResult;}}}}

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

namespace alinous {namespace compile {namespace sql {namespace result {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::java::util::ArrayList;
using ::alinous::compile::sql::analyze::ScanTableColumnIdentifier;
using ::alinous::compile::sql::analyze::ScanTableMetadata;
using ::alinous::compile::sql::expression::ISQLExpression;
using ::alinous::compile::sql::expression::SQLExpressionStream;
using ::alinous::compile::sql::parts::SQLExpressionList;
using ::alinous::compile::sql::parts::SQLExpressionListAll;
using ::alinous::db::table::DatabaseException;
using ::alinous::db::trx::scan::ScanResultRecord;
using ::alinous::runtime::dom::DomVariable;
using ::alinous::runtime::engine::ScriptMachine;
using ::alinous::system::AlinousException;



class SelectResultDescription final : public virtual IObject {
public:
	SelectResultDescription(const SelectResultDescription& base) = default;
public:
	SelectResultDescription(SQLExpressionList* list, ScanTableMetadata* metadata, ThreadContext* ctx) throw() ;
	void __construct_impl(SQLExpressionList* list, ScanTableMetadata* metadata, ThreadContext* ctx) throw() ;
	virtual ~SelectResultDescription() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	ArrayList<AbstructSelectResult>* list;
public:
	DomVariable* fetchDom(ScanResultRecord* srecord, ScriptMachine* machine, bool debug, ThreadContext* ctx);
	ArrayList<ScanTableColumnIdentifier>* getGroupByIndexColumns(ThreadContext* ctx);
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}}}

#endif /* end of ALINOUS_COMPILE_SQL_RESULT_SELECTRESULTDESCRIPTION_H_ */
