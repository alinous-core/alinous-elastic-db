#ifndef ALINOUS_COMPILE_SQL_ISQLSTATEMENT_H_
#define ALINOUS_COMPILE_SQL_ISQLSTATEMENT_H_
namespace alinous{namespace annotation{
class OneSource;
}}
namespace alinous {namespace compile {namespace sql {namespace analyze {
class SQLAnalyseContext;}}}}

namespace alinous {namespace compile {
class IStatement;}}

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
using ::alinous::compile::IStatement;
using ::alinous::compile::sql::analyze::SQLAnalyseContext;
using ::alinous::db::table::DatabaseException;
using ::alinous::system::AlinousException;



class ISqlStatement : public IStatement {
public:
	ISqlStatement(const ISqlStatement& base) = default;
public:
	ISqlStatement(ThreadContext* ctx) throw()  : IObject(ctx), IStatement(ctx)
	{
	}
	void __construct_impl(ThreadContext* ctx) throw() 
	{
	}
	virtual ~ISqlStatement() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
public:
	virtual void analyzeSQL(SQLAnalyseContext* context, bool debug, ThreadContext* ctx) = 0;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}}

#endif /* end of ALINOUS_COMPILE_SQL_ISQLSTATEMENT_H_ */
