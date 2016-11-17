#ifndef ALINOUS_RUNTIME_ENGINE_SQLSTATEMENTRUNNER_H_
#define ALINOUS_RUNTIME_ENGINE_SQLSTATEMENTRUNNER_H_
namespace alinous{namespace annotation{
class OneSource;
}}
namespace alinous {namespace compile {namespace sql {
class CreateTableStatement;}}}

namespace alinous {namespace runtime {namespace engine {
class ScriptMachine;}}}

namespace alinous {namespace runtime {namespace engine {
class DatabaseHandle;}}}

namespace alinous {namespace runtime {namespace dbif {
class IDatabaseConnection;}}}

namespace alinous {namespace runtime {namespace dbif {
class IDatabaseDriver;}}}

namespace alinous {namespace compile {namespace sql {
class DropTableStatement;}}}

namespace alinous {namespace compile {namespace sql {
class BeginStatement;}}}

namespace alinous {namespace compile {namespace sql {
class CommitStatement;}}}

namespace alinous {namespace compile {namespace sql {
class RollbackStatement;}}}

namespace alinous {namespace compile {namespace sql {
class InsertStatement;}}}

namespace alinous {namespace compile {namespace sql {
class DeleteStatement;}}}

namespace alinous {namespace compile {namespace sql {
class UpdateStatement;}}}

namespace alinous {namespace compile {namespace sql {
class SelectStatement;}}}

namespace alinous {namespace compile {namespace sql {
class CreateIndexStatement;}}}

namespace alinous {namespace compile {namespace sql {
class DropIndexStatement;}}}

namespace alinous {namespace db {
class AlinousDbException;}}

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

namespace alinous {namespace runtime {namespace engine {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::alinous::compile::sql::BeginStatement;
using ::alinous::compile::sql::CommitStatement;
using ::alinous::compile::sql::CreateIndexStatement;
using ::alinous::compile::sql::CreateTableStatement;
using ::alinous::compile::sql::DeleteStatement;
using ::alinous::compile::sql::DropIndexStatement;
using ::alinous::compile::sql::DropTableStatement;
using ::alinous::compile::sql::InsertStatement;
using ::alinous::compile::sql::RollbackStatement;
using ::alinous::compile::sql::SelectStatement;
using ::alinous::compile::sql::UpdateStatement;
using ::alinous::db::AlinousDbException;
using ::alinous::db::table::DatabaseException;
using ::alinous::runtime::dbif::IDatabaseConnection;
using ::alinous::runtime::dbif::IDatabaseDriver;
using ::alinous::system::AlinousException;



class SQLStatementRunner final : public virtual IObject {
public:
	SQLStatementRunner(const SQLStatementRunner& base) = default;
public:
	SQLStatementRunner(ThreadContext* ctx) throw()  : IObject(ctx)
	{
	}
	void __construct_impl(ThreadContext* ctx) throw() 
	{
	}
	virtual ~SQLStatementRunner() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
public:
	bool executeCreateTableStatement(CreateTableStatement* stmt, ScriptMachine* machine, bool debug, ThreadContext* ctx);
	bool executeDropTableStatement(DropTableStatement* stmt, ScriptMachine* machine, bool debug, ThreadContext* ctx) throw() ;
	bool executeBeginStatement(BeginStatement* stmt, ScriptMachine* machine, bool debug, ThreadContext* ctx);
	bool executeCommitStatement(CommitStatement* stmt, ScriptMachine* machine, bool debug, ThreadContext* ctx);
	bool executeRollbackStatement(RollbackStatement* stmt, ScriptMachine* machine, bool debug, ThreadContext* ctx);
	bool executeInsertStatement(InsertStatement* stmt, ScriptMachine* machine, bool debug, ThreadContext* ctx);
	bool executeDeleteStatement(DeleteStatement* stmt, ScriptMachine* machine, bool debug, ThreadContext* ctx);
	bool executeUpdateStatement(UpdateStatement* stmt, ScriptMachine* machine, bool debug, ThreadContext* ctx);
	bool executeSelectStatement(SelectStatement* stmt, ScriptMachine* machine, bool debug, ThreadContext* ctx);
	bool executeCreateIndexStatement(CreateIndexStatement* stmt, ScriptMachine* machine, bool debug, ThreadContext* ctx);
	bool executeDropIndexStatement(DropIndexStatement* stmt, ScriptMachine* machine, bool debug, ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}}

#endif /* end of ALINOUS_RUNTIME_ENGINE_SQLSTATEMENTRUNNER_H_ */
