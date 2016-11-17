#ifndef ALINOUS_COMPILE_SQL_RESULT_COLUMNRESULT_H_
#define ALINOUS_COMPILE_SQL_RESULT_COLUMNRESULT_H_
namespace alinous {namespace compile {namespace sql {namespace expression {
class ISQLExpression;}}}}

namespace alinous {namespace compile {namespace sql {namespace analyze {
class ScanTableColumnIdentifier;}}}}

namespace alinous {namespace runtime {namespace dom {
class DomVariable;}}}

namespace alinous {namespace db {namespace trx {namespace scan {
class ScanResultRecord;}}}}

namespace alinous {namespace runtime {namespace engine {
class ScriptMachine;}}}

namespace alinous {namespace runtime {namespace variant {
class VariantValue;}}}

namespace alinous {namespace compile {namespace sql {namespace result {
class AbstructSelectResult;}}}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace compile {namespace sql {namespace result {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::alinous::compile::sql::analyze::ScanTableColumnIdentifier;
using ::alinous::compile::sql::expression::ISQLExpression;
using ::alinous::db::trx::scan::ScanResultRecord;
using ::alinous::runtime::dom::DomVariable;
using ::alinous::runtime::engine::ScriptMachine;
using ::alinous::runtime::variant::VariantValue;



class ColumnResult final : public AbstructSelectResult {
public:
	ColumnResult(const ColumnResult& base) = default;
public:
	ColumnResult(int colOrder, ISQLExpression* sqlexp, ScanTableColumnIdentifier* colId, ThreadContext* ctx) throw() ;
	void __construct_impl(int colOrder, ISQLExpression* sqlexp, ScanTableColumnIdentifier* colId, ThreadContext* ctx) throw() ;
	virtual ~ColumnResult() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
public:
	ScanTableColumnIdentifier* colId;
private:
	int colOrder;
public:
	void fetchFromRecord(DomVariable* domVariable, ScanResultRecord* srecord, ScriptMachine* machine, bool debug, ThreadContext* ctx) throw()  final;
	int getType(ThreadContext* ctx) throw()  final;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}}}

#endif /* end of ALINOUS_COMPILE_SQL_RESULT_COLUMNRESULT_H_ */
