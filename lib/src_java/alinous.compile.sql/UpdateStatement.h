#ifndef ALINOUS_COMPILE_SQL_UPDATESTATEMENT_H_
#define ALINOUS_COMPILE_SQL_UPDATESTATEMENT_H_
namespace alinous{namespace annotation{
class OneSource;
}}
namespace alinous{namespace annotation{
class ThreadMonitor;
}}
namespace alinous {namespace compile {namespace analyse {
class SourceValidator;}}}

namespace alinous {namespace compile {namespace sql {namespace select {namespace join {
class TableJoinTarget;}}}}}

namespace alinous {namespace compile {namespace declare {
class AlinousName;}}}

namespace alinous {namespace compile {
class IAlinousElementVisitor;}}

namespace alinous {namespace compile {
class AbstractSrcElement;}}

namespace alinous {namespace compile {namespace analyse {
class SrcAnalyseContext;}}}

namespace alinous {namespace compile {namespace sql {
class UpdateSet;}}}

namespace alinous {namespace compile {namespace sql {namespace select {namespace join {
class IJoinTarget;}}}}}

namespace alinous {namespace compile {namespace sql {namespace select {
class SQLWhere;}}}}

namespace alinous {namespace compile {namespace sql {namespace analyze {
class SQLAnalyseContext;}}}}

namespace alinous {namespace compile {namespace sql {
class AbstractSQLStatement;}}}

namespace alinous {namespace db {namespace table {
class DatabaseException;}}}

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
using ::alinous::compile::IAlinousElementVisitor;
using ::alinous::compile::analyse::SourceValidator;
using ::alinous::compile::analyse::SrcAnalyseContext;
using ::alinous::compile::declare::AlinousName;
using ::alinous::compile::sql::analyze::SQLAnalyseContext;
using ::alinous::compile::sql::select::SQLWhere;
using ::alinous::compile::sql::select::join::IJoinTarget;
using ::alinous::compile::sql::select::join::TableJoinTarget;
using ::alinous::db::table::DatabaseException;
using ::alinous::system::AlinousException;



class UpdateStatement final : public AbstractSQLStatement, public ThreadMonitor {
public:
	UpdateStatement(const UpdateStatement& base) = default;
public:
	UpdateStatement(ThreadContext* ctx) throw()  : IObject(ctx), AbstractSQLStatement(ctx), ThreadMonitor(ctx), table(nullptr), sets(GCUtils<ArrayList<UpdateSet> >::ins(this, (new(ctx) ArrayList<UpdateSet>(ctx)), ctx, __FILEW__, __LINE__, L"")), where(nullptr)
	{
	}
	void __construct_impl(ThreadContext* ctx) throw() 
	{
	}
	virtual ~UpdateStatement() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	IJoinTarget* table;
	ArrayList<UpdateSet>* sets;
	SQLWhere* where;
public:
	void validate(SourceValidator* validator, ThreadContext* ctx) throw()  final;
	AlinousName* getTableName(ThreadContext* ctx) throw() ;
	bool visit(IAlinousElementVisitor* visitor, AbstractSrcElement* parent, ThreadContext* ctx) throw()  final;
	bool analyse(SrcAnalyseContext* context, bool leftValue, ThreadContext* ctx) throw()  final;
	void addUpdateSet(UpdateSet* updset, ThreadContext* ctx) throw() ;
	IJoinTarget* getTable(ThreadContext* ctx) throw() ;
	void setTable(IJoinTarget* table, ThreadContext* ctx) throw() ;
	ArrayList<UpdateSet>* getSets(ThreadContext* ctx) throw() ;
	void setSets(ArrayList<UpdateSet>* sets, ThreadContext* ctx) throw() ;
	SQLWhere* getWhere(ThreadContext* ctx) throw() ;
	void setWhere(SQLWhere* where, ThreadContext* ctx) throw() ;
	IStatement::StatementType getType(ThreadContext* ctx) throw()  final;
	void analyzeSQL(SQLAnalyseContext* context, bool debug, ThreadContext* ctx) final;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}}

#endif /* end of ALINOUS_COMPILE_SQL_UPDATESTATEMENT_H_ */
