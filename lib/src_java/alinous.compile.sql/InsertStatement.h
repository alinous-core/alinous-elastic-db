#ifndef ALINOUS_COMPILE_SQL_INSERTSTATEMENT_H_
#define ALINOUS_COMPILE_SQL_INSERTSTATEMENT_H_
namespace alinous{namespace annotation{
class OneSource;
}}
namespace alinous{namespace annotation{
class ThreadMonitor;
}}
namespace alinous {namespace db {namespace trx {namespace cache {
class TrxRecordsCache;}}}}

namespace alinous {namespace runtime {namespace engine {
class ScriptMachine;}}}

namespace alinous {namespace db {namespace trx {namespace cache {
class TrxStorageManager;}}}}

namespace alinous {namespace compile {namespace sql {namespace select {namespace join {
class TableJoinTarget;}}}}}

namespace alinous {namespace db {namespace trx {namespace cache {
class CulumnOrder;}}}}

namespace alinous {namespace compile {namespace sql {namespace expression {
class ISQLExpression;}}}}

namespace alinous {namespace runtime {namespace dom {
class IAlinousVariable;}}}

namespace alinous {namespace runtime {namespace dom {
class IDomVariable;}}}

namespace alinous {namespace compile {namespace sql {
class InsertValues;}}}

namespace alinous {namespace compile {namespace analyse {
class SourceValidator;}}}

namespace alinous {namespace compile {
class IAlinousElementVisitor;}}

namespace alinous {namespace compile {
class AbstractSrcElement;}}

namespace alinous {namespace compile {namespace analyse {
class SrcAnalyseContext;}}}

namespace alinous {namespace compile {namespace sql {namespace select {namespace join {
class IJoinTarget;}}}}}

namespace alinous {namespace compile {namespace sql {namespace parts {
class SQLExpressionList;}}}}

namespace alinous {namespace db {namespace trx {
class DbVersionContext;}}}

namespace alinous {namespace compile {namespace sql {namespace analyze {
class SQLAnalyseContext;}}}}

namespace alinous {namespace remote {namespace socket {
class NetworkBinaryBuffer;}}}

namespace alinous {namespace compile {
class IAlinousElement;}}

namespace alinous {namespace runtime {namespace dom {
class VariableException;}}}

namespace alinous {namespace compile {namespace sql {
class AbstractSQLStatement;}}}

namespace alinous {namespace compile {
class AlinousElementNetworkFactory;}}

namespace alinous {namespace db {
class AlinousDbException;}}

namespace alinous {namespace db {namespace table {
class DatabaseException;}}}

namespace alinous {namespace remote {namespace socket {
class ICommandData;}}}

namespace alinous {namespace system {
class AlinousException;}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace compile {namespace sql {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::java::util::ArrayList;
using ::alinous::compile::AbstractSrcElement;
using ::alinous::compile::AlinousElementNetworkFactory;
using ::alinous::compile::IAlinousElement;
using ::alinous::compile::IAlinousElementVisitor;
using ::alinous::compile::analyse::SourceValidator;
using ::alinous::compile::analyse::SrcAnalyseContext;
using ::alinous::compile::sql::analyze::SQLAnalyseContext;
using ::alinous::compile::sql::expression::ISQLExpression;
using ::alinous::compile::sql::parts::SQLExpressionList;
using ::alinous::compile::sql::select::join::IJoinTarget;
using ::alinous::compile::sql::select::join::TableJoinTarget;
using ::alinous::db::AlinousDbException;
using ::alinous::db::table::DatabaseException;
using ::alinous::db::trx::DbVersionContext;
using ::alinous::db::trx::cache::CulumnOrder;
using ::alinous::db::trx::cache::TrxRecordsCache;
using ::alinous::db::trx::cache::TrxStorageManager;
using ::alinous::remote::socket::ICommandData;
using ::alinous::remote::socket::NetworkBinaryBuffer;
using ::alinous::runtime::dom::IAlinousVariable;
using ::alinous::runtime::dom::IDomVariable;
using ::alinous::runtime::dom::VariableException;
using ::alinous::runtime::engine::ScriptMachine;
using ::alinous::system::AlinousException;



class InsertStatement final : public AbstractSQLStatement, public ThreadMonitor {
public:
	InsertStatement(const InsertStatement& base) = default;
public:
	InsertStatement(ThreadContext* ctx) throw()  : IObject(ctx), AbstractSQLStatement(ctx), ThreadMonitor(ctx), table(nullptr), list(nullptr), values(GCUtils<ArrayList<InsertValues> >::ins(this, (new(ctx) ArrayList<InsertValues>(ctx)), ctx, __FILEW__, __LINE__, L"")), schemeName(nullptr), tblName(nullptr), vctx(nullptr)
	{
	}
	void __construct_impl(ThreadContext* ctx) throw() 
	{
	}
	virtual ~InsertStatement() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	IJoinTarget* table;
	SQLExpressionList* list;
	ArrayList<InsertValues>* values;
	String* schemeName;
	String* tblName;
	DbVersionContext* vctx;
public:
	TrxRecordsCache* getCache(ScriptMachine* machine, TrxStorageManager* trxStorageManager, ThreadContext* ctx);
	ArrayList<CulumnOrder>* getColumnOrder(ScriptMachine* machine, bool debug, ThreadContext* ctx);
	ArrayList<IDomVariable>* getInsertRercords(ScriptMachine* machine, bool debug, ThreadContext* ctx);
	void validate(SourceValidator* validator, ThreadContext* ctx) throw()  final;
	bool visit(IAlinousElementVisitor* visitor, AbstractSrcElement* parent, ThreadContext* ctx) throw()  final;
	bool analyse(SrcAnalyseContext* context, bool leftValue, ThreadContext* ctx) throw()  final;
	void addValue(InsertValues* value, ThreadContext* ctx) throw() ;
	IJoinTarget* getTable(ThreadContext* ctx) throw() ;
	void setTable(IJoinTarget* table, ThreadContext* ctx) throw() ;
	SQLExpressionList* getList(ThreadContext* ctx) throw() ;
	void setList(SQLExpressionList* list, ThreadContext* ctx) throw() ;
	ArrayList<InsertValues>* getValues(ThreadContext* ctx) throw() ;
	IStatement::StatementType getType(ThreadContext* ctx) throw()  final;
	bool needsAnalyse(DbVersionContext* vctx, ThreadContext* ctx) throw() ;
	void analyzeSQL(SQLAnalyseContext* context, bool debug, ThreadContext* ctx) final;
	void readData(NetworkBinaryBuffer* buff, ThreadContext* ctx) final;
	void writeData(NetworkBinaryBuffer* buff, ThreadContext* ctx) throw()  final;
	DbVersionContext* getVctx(ThreadContext* ctx) throw() ;
	void setVctx(DbVersionContext* vctx, ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}}

#endif /* end of ALINOUS_COMPILE_SQL_INSERTSTATEMENT_H_ */
