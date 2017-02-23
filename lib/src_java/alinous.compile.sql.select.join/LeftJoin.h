#ifndef ALINOUS_COMPILE_SQL_SELECT_JOIN_LEFTJOIN_H_
#define ALINOUS_COMPILE_SQL_SELECT_JOIN_LEFTJOIN_H_
namespace alinous{namespace annotation{
class OneSource;
}}
namespace alinous {namespace db {namespace trx {namespace scan {
class ITableTargetScanner;}}}}

namespace alinous {namespace db {namespace trx {
class DbTransaction;}}}

namespace alinous {namespace runtime {namespace engine {
class ScriptMachine;}}}

namespace alinous {namespace compile {namespace sql {namespace analyze {
class ScanTableColumnIdentifier;}}}}

namespace alinous {namespace compile {namespace sql {namespace analyze {
class JoinStrategyPart;}}}}

namespace alinous {namespace compile {namespace sql {namespace select {namespace join {namespace scan {
class JoinedCollectionScanner;}}}}}}

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
using ::alinous::compile::sql::analyze::JoinStrategyPart;
using ::alinous::compile::sql::analyze::ScanTableColumnIdentifier;
using ::alinous::compile::sql::select::join::scan::JoinedCollectionScanner;
using ::alinous::db::table::DatabaseException;
using ::alinous::db::trx::DbTransaction;
using ::alinous::db::trx::scan::ITableTargetScanner;
using ::alinous::remote::socket::ICommandData;
using ::alinous::remote::socket::NetworkBinaryBuffer;
using ::alinous::runtime::dom::VariableException;
using ::alinous::runtime::engine::ScriptMachine;
using ::alinous::system::AlinousException;



class LeftJoin : public AbstractSQLJoin {
public:
	LeftJoin(const LeftJoin& base) = default;
public:
	LeftJoin(ThreadContext* ctx) throw()  : IObject(ctx), AbstractSQLJoin(ctx)
	{
	}
	void __construct_impl(ThreadContext* ctx) throw() 
	{
	}
	virtual ~LeftJoin() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
public:
	ITableTargetScanner* getScanner(DbTransaction* trx, ScriptMachine* machine, ArrayList<ScanTableColumnIdentifier>* joinRequest, bool debug, ThreadContext* ctx) final;
	IStatement::StatementType getType(ThreadContext* ctx) throw()  final;
	void validate(SourceValidator* validator, ThreadContext* ctx) throw()  final;
	virtual void readData(NetworkBinaryBuffer* buff, ThreadContext* ctx);
	virtual void writeData(NetworkBinaryBuffer* buff, ThreadContext* ctx);
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}}}}

#endif /* end of ALINOUS_COMPILE_SQL_SELECT_JOIN_LEFTJOIN_H_ */
