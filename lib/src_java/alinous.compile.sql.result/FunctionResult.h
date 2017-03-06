#ifndef ALINOUS_COMPILE_SQL_RESULT_FUNCTIONRESULT_H_
#define ALINOUS_COMPILE_SQL_RESULT_FUNCTIONRESULT_H_
namespace alinous {namespace compile {namespace sql {namespace expression {
class SQLExpressionStream;}}}}

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

namespace alinous {namespace db {namespace table {
class DatabaseException;}}}

namespace alinous {namespace system {
class AlinousException;}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace compile {namespace sql {namespace result {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::alinous::compile::sql::expression::SQLExpressionStream;
using ::alinous::db::table::DatabaseException;
using ::alinous::db::trx::scan::ScanResultRecord;
using ::alinous::runtime::dom::DomVariable;
using ::alinous::runtime::engine::ScriptMachine;
using ::alinous::runtime::variant::VariantValue;
using ::alinous::system::AlinousException;



class FunctionResult final : public AbstructSelectResult {
public:
	FunctionResult(const FunctionResult& base) = default;
public:
	FunctionResult(SQLExpressionStream* sqlexp, ThreadContext* ctx) throw() ;
	void __construct_impl(SQLExpressionStream* sqlexp, ThreadContext* ctx) throw() ;
	virtual ~FunctionResult() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
public:
	SQLExpressionStream* sqlexp;
public:
	void fetchFromRecord(DomVariable* domVariable, ScanResultRecord* srecord, ScriptMachine* machine, bool debug, ThreadContext* ctx) final;
	int getType(ThreadContext* ctx) throw()  final;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx);
};

}}}}

#endif /* end of ALINOUS_COMPILE_SQL_RESULT_FUNCTIONRESULT_H_ */
