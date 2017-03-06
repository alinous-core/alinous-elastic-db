#ifndef ALINOUS_COMPILE_SQL_EXPRESSION_ISQLEXPRESSION_H_
#define ALINOUS_COMPILE_SQL_EXPRESSION_ISQLEXPRESSION_H_
namespace alinous{namespace annotation{
class OneSource;
}}
namespace alinous {namespace compile {namespace sql {namespace analyze {
class SQLAnalyseContext;}}}}

namespace alinous {namespace compile {namespace sql {namespace analyze {
class ScanTableIdentifier;}}}}

namespace alinous {namespace compile {namespace sql {namespace analyze {
class ScanTableColumnIdentifier;}}}}

namespace alinous {namespace compile {namespace sql {namespace expression {
class ISQLExpression;}}}}

namespace alinous {namespace runtime {namespace variant {
class VariantValue;}}}

namespace alinous {namespace db {namespace trx {namespace scan {
class ScanResultRecord;}}}}

namespace alinous {namespace runtime {namespace engine {
class ScriptMachine;}}}

namespace alinous {namespace compile {namespace expression {
class IExpression;}}}

namespace alinous {namespace db {namespace table {
class DatabaseException;}}}

namespace alinous {namespace system {
class AlinousException;}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace compile {namespace sql {namespace expression {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::java::util::ArrayList;
using ::alinous::compile::expression::IExpression;
using ::alinous::compile::sql::analyze::SQLAnalyseContext;
using ::alinous::compile::sql::analyze::ScanTableColumnIdentifier;
using ::alinous::compile::sql::analyze::ScanTableIdentifier;
using ::alinous::db::table::DatabaseException;
using ::alinous::db::trx::scan::ScanResultRecord;
using ::alinous::runtime::engine::ScriptMachine;
using ::alinous::runtime::variant::VariantValue;
using ::alinous::system::AlinousException;



class ISQLExpression : public IExpression {
public:
	ISQLExpression(const ISQLExpression& base) = default;
public:
	ISQLExpression(ThreadContext* ctx) throw() ;
	void __construct_impl(ThreadContext* ctx) throw() ;
	virtual ~ISQLExpression() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
public:
	virtual bool hasSubExp(ThreadContext* ctx) throw()  = 0;
	virtual bool analyseSQL(SQLAnalyseContext* context, bool leftValue, bool debug, ThreadContext* ctx) = 0;
	virtual bool hasTable(ScanTableIdentifier* table, ThreadContext* ctx) throw()  = 0;
	virtual ArrayList<ScanTableColumnIdentifier>* getColumns(ThreadContext* ctx) throw()  = 0;
	virtual bool isJoinCondition(ThreadContext* ctx) throw()  = 0;
	virtual void collectJoinCondition(ArrayList<ISQLExpression>* list, ThreadContext* ctx) throw()  = 0;
	virtual bool isColumnIdentifier(ThreadContext* ctx) throw()  = 0;
	virtual ScanTableColumnIdentifier* toColumnIdentifier(ThreadContext* ctx) throw()  = 0;
	virtual VariantValue* resolveSQLExpression(ScanResultRecord* record, ScriptMachine* machine, bool debug, ThreadContext* ctx) = 0;
	virtual bool hasArrayResult(ThreadContext* ctx) throw()  = 0;
	virtual ArrayList<VariantValue>* resolveSQLExpressionAsArray(ScanResultRecord* record, ScriptMachine* machine, bool debug, ThreadContext* ctx) = 0;
	virtual String* getAsName(ThreadContext* ctx) throw()  = 0;
	virtual void setAsName(String* name, ThreadContext* ctx) throw()  = 0;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx);
};

}}}}

#endif /* end of ALINOUS_COMPILE_SQL_EXPRESSION_ISQLEXPRESSION_H_ */
