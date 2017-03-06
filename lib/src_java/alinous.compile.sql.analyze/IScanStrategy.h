#ifndef ALINOUS_COMPILE_SQL_ANALYZE_ISCANSTRATEGY_H_
#define ALINOUS_COMPILE_SQL_ANALYZE_ISCANSTRATEGY_H_
namespace alinous{namespace annotation{
class OneSource;
}}
namespace alinous {namespace compile {namespace sql {namespace select {
class SQLWhere;}}}}

namespace alinous {namespace compile {namespace sql {namespace analyze {
class ScanTableMetadata;}}}}

namespace alinous {namespace db {namespace trx {namespace scan {
class ITableTargetScanner;}}}}

namespace alinous {namespace runtime {namespace engine {
class ScriptMachine;}}}

namespace alinous {namespace db {namespace trx {
class DbTransaction;}}}

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

namespace alinous {namespace compile {namespace sql {namespace analyze {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::alinous::compile::sql::select::SQLWhere;
using ::alinous::db::table::DatabaseException;
using ::alinous::db::trx::DbTransaction;
using ::alinous::db::trx::scan::ITableTargetScanner;
using ::alinous::runtime::engine::ScriptMachine;
using ::alinous::system::AlinousException;



class IScanStrategy : public virtual IObject {
public:
	IScanStrategy(const IScanStrategy& base) = default;
public:
	IScanStrategy(ThreadContext* ctx) throw() ;
	void __construct_impl(ThreadContext* ctx) throw() ;
	virtual ~IScanStrategy() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
public:
	virtual void analyzeFilterCondition(SQLWhere* where, ThreadContext* ctx) throw()  = 0;
	virtual void analyzeIndex(SQLWhere* where, ScanTableMetadata* tableMetadata, ThreadContext* ctx) = 0;
	virtual void optimize(ThreadContext* ctx) throw()  = 0;
	virtual ScanTableMetadata* getTableMetadata(ThreadContext* ctx) throw()  = 0;
	virtual ITableTargetScanner* getScanner(ScriptMachine* machine, DbTransaction* trx, ThreadContext* ctx) = 0;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx);
};

}}}}

#endif /* end of ALINOUS_COMPILE_SQL_ANALYZE_ISCANSTRATEGY_H_ */
