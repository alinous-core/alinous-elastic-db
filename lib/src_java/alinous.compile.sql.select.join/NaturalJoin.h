#ifndef ALINOUS_COMPILE_SQL_SELECT_JOIN_NATURALJOIN_H_
#define ALINOUS_COMPILE_SQL_SELECT_JOIN_NATURALJOIN_H_
namespace alinous{namespace annotation{
class OneSource;
}}
namespace alinous {namespace compile {namespace sql {namespace analyze {
class SQLAnalyseContext;}}}}

namespace alinous {namespace compile {namespace sql {namespace select {
class SQLWhere;}}}}

namespace alinous {namespace compile {namespace sql {namespace select {
class SQLGroupBy;}}}}

namespace alinous {namespace compile {namespace sql {namespace select {
class SQLLimitOffset;}}}}

namespace alinous {namespace compile {namespace sql {namespace analyze {
class ScanTableColumnIdentifier;}}}}

namespace alinous {namespace system {
class AlinousNotSupportedException;}}

namespace alinous {namespace db {namespace trx {namespace scan {
class ITableTargetScanner;}}}}

namespace alinous {namespace db {namespace trx {
class DbTransaction;}}}

namespace alinous {namespace runtime {namespace engine {
class ScriptMachine;}}}

namespace alinous {namespace compile {namespace analyse {
class SourceValidator;}}}

namespace alinous {namespace remote {namespace socket {
class NetworkBinaryBuffer;}}}

namespace alinous {namespace compile {namespace sql {namespace select {namespace join {
class AbstractSQLJoin;}}}}}

namespace alinous {namespace db {namespace table {
class DatabaseException;}}}

namespace alinous {namespace remote {namespace socket {
class ICommandData;}}}

namespace alinous {namespace runtime {namespace dom {
class VariableException;}}}

namespace alinous {namespace system {
class AlinousException;}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace compile {namespace sql {namespace select {namespace join {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::java::util::ArrayList;
using ::alinous::compile::analyse::SourceValidator;
using ::alinous::compile::sql::analyze::SQLAnalyseContext;
using ::alinous::compile::sql::analyze::ScanTableColumnIdentifier;
using ::alinous::compile::sql::select::SQLGroupBy;
using ::alinous::compile::sql::select::SQLLimitOffset;
using ::alinous::compile::sql::select::SQLWhere;
using ::alinous::db::table::DatabaseException;
using ::alinous::db::trx::DbTransaction;
using ::alinous::db::trx::scan::ITableTargetScanner;
using ::alinous::remote::socket::ICommandData;
using ::alinous::remote::socket::NetworkBinaryBuffer;
using ::alinous::runtime::dom::VariableException;
using ::alinous::runtime::engine::ScriptMachine;
using ::alinous::system::AlinousException;
using ::alinous::system::AlinousNotSupportedException;



class NaturalJoin final : public AbstractSQLJoin {
public:
	NaturalJoin(const NaturalJoin& base) = default;
public:
	NaturalJoin(ThreadContext* ctx) throw()  : IObject(ctx), AbstractSQLJoin(ctx)
	{
	}
	void __construct_impl(ThreadContext* ctx) throw() 
	{
	}
	virtual ~NaturalJoin() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
public:
	void optimizeScan(SQLAnalyseContext* context, SQLWhere* where, SQLGroupBy* groupby, SQLLimitOffset* limit, ArrayList<ScanTableColumnIdentifier>* joinRequest, bool debug, ThreadContext* ctx) final;
	ITableTargetScanner* getScanner(DbTransaction* trx, ScriptMachine* machine, ArrayList<ScanTableColumnIdentifier>* joinRequest, bool debug, ThreadContext* ctx) throw()  final;
	IStatement::StatementType getType(ThreadContext* ctx) throw()  final;
	void validate(SourceValidator* validator, ThreadContext* ctx) throw()  final;
	void readData(NetworkBinaryBuffer* buff, ThreadContext* ctx) final;
	void writeData(NetworkBinaryBuffer* buff, ThreadContext* ctx) throw()  final;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}}}}

#endif /* end of ALINOUS_COMPILE_SQL_SELECT_JOIN_NATURALJOIN_H_ */
