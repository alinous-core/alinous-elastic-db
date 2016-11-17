#ifndef ALINOUS_COMPILE_SQL_RESULT_ABSTRUCTSELECTRESULT_H_
#define ALINOUS_COMPILE_SQL_RESULT_ABSTRUCTSELECTRESULT_H_
namespace alinous {namespace runtime {namespace dom {
class DomVariable;}}}

namespace alinous {namespace db {namespace trx {namespace scan {
class ScanResultRecord;}}}}

namespace alinous {namespace runtime {namespace engine {
class ScriptMachine;}}}

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
using ::alinous::db::table::DatabaseException;
using ::alinous::db::trx::scan::ScanResultRecord;
using ::alinous::runtime::dom::DomVariable;
using ::alinous::runtime::engine::ScriptMachine;
using ::alinous::system::AlinousException;



class AbstructSelectResult : public virtual IObject {
public:
	AbstructSelectResult(const AbstructSelectResult& base) = default;
public:
	AbstructSelectResult(ThreadContext* ctx) throw()  : IObject(ctx), outputName(nullptr)
	{
	}
	void __construct_impl(ThreadContext* ctx) throw() 
	{
	}
	virtual ~AbstructSelectResult() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
public:
	String* outputName;
public:
	constexpr static const int ALL_COLUMNS{1};
	constexpr static const int COLUMN{2};
	constexpr static const int FUNCTION{3};
public:
	virtual int getType(ThreadContext* ctx) throw()  = 0;
	virtual void fetchFromRecord(DomVariable* domVariable, ScanResultRecord* srecord, ScriptMachine* machine, bool debug, ThreadContext* ctx) = 0;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}}}

#endif /* end of ALINOUS_COMPILE_SQL_RESULT_ABSTRUCTSELECTRESULT_H_ */
