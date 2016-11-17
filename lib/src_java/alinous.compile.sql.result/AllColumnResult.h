#ifndef ALINOUS_COMPILE_SQL_RESULT_ALLCOLUMNRESULT_H_
#define ALINOUS_COMPILE_SQL_RESULT_ALLCOLUMNRESULT_H_
namespace alinous {namespace compile {namespace sql {namespace analyze {
class ScanTableMetadata;}}}}

namespace alinous {namespace runtime {namespace dom {
class DomVariable;}}}

namespace alinous {namespace db {namespace trx {namespace scan {
class ScanResultRecord;}}}}

namespace alinous {namespace runtime {namespace engine {
class ScriptMachine;}}}

namespace alinous {namespace compile {namespace sql {namespace analyze {
class ScanTableColumnMetadata;}}}}

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
using ::java::util::ArrayList;
using ::alinous::compile::sql::analyze::ScanTableColumnMetadata;
using ::alinous::compile::sql::analyze::ScanTableMetadata;
using ::alinous::db::trx::scan::ScanResultRecord;
using ::alinous::runtime::dom::DomVariable;
using ::alinous::runtime::engine::ScriptMachine;
using ::alinous::runtime::variant::VariantValue;



class AllColumnResult final : public AbstructSelectResult {
public:
	AllColumnResult(const AllColumnResult& base) = default;
public:
	AllColumnResult(ScanTableMetadata* metadata, ThreadContext* ctx) throw() ;
	void __construct_impl(ScanTableMetadata* metadata, ThreadContext* ctx) throw() ;
	virtual ~AllColumnResult() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
public:
	ScanTableMetadata* metadata;
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

#endif /* end of ALINOUS_COMPILE_SQL_RESULT_ALLCOLUMNRESULT_H_ */
