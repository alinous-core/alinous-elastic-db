#ifndef ALINOUS_RUNTIME_ENGINE_SCRIPTRUNNER_H_
#define ALINOUS_RUNTIME_ENGINE_SCRIPTRUNNER_H_
namespace alinous{namespace annotation{
class OneSource;
}}
namespace alinous {namespace runtime {namespace engine {
class SQLStatementRunner;}}}

namespace alinous {namespace runtime {namespace engine {
class AlinousStatementRunner;}}}

namespace alinous {namespace runtime {
class AlinousModule;}}

namespace alinous {namespace runtime {namespace engine {
class ScriptMachine;}}}

namespace alinous {namespace compile {
class AlinousSrc;}}

namespace alinous {namespace compile {namespace declare {
class AlinousClass;}}}

namespace alinous {namespace compile {namespace stmt {
class StatementList;}}}

namespace alinous {namespace compile {
class IStatement;}}

namespace alinous {namespace compile {namespace stmt {
class AssignmentStatement;}}}

namespace alinous {namespace compile {namespace stmt {
class ExpressionStatement;}}}

namespace alinous {namespace compile {namespace stmt {
class ReturnStatement;}}}

namespace alinous {namespace compile {namespace stmt {
class StatementBlock;}}}

namespace alinous {namespace compile {namespace stmt {
class TypedVariableDeclare;}}}

namespace alinous {namespace compile {namespace sql {
class BeginStatement;}}}

namespace alinous {namespace compile {namespace sql {
class CommitStatement;}}}

namespace alinous {namespace compile {namespace sql {
class CreateTableStatement;}}}

namespace alinous {namespace compile {namespace sql {
class DeleteStatement;}}}

namespace alinous {namespace compile {namespace sql {
class DropTableStatement;}}}

namespace alinous {namespace compile {namespace sql {
class InsertStatement;}}}

namespace alinous {namespace compile {namespace sql {
class RollbackStatement;}}}

namespace alinous {namespace compile {namespace sql {
class SelectStatement;}}}

namespace alinous {namespace compile {namespace sql {
class UpdateStatement;}}}

namespace alinous {namespace compile {namespace sql {
class CreateIndexStatement;}}}

namespace alinous {namespace compile {namespace sql {
class DropIndexStatement;}}}

namespace alinous {namespace system {
class AlinousException;}}

namespace alinous {namespace db {namespace table {
class DatabaseException;}}}

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
using ::java::util::ArrayList;
using ::alinous::compile::AlinousSrc;
using ::alinous::compile::IStatement;
using ::alinous::compile::declare::AlinousClass;
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
using ::alinous::compile::stmt::AssignmentStatement;
using ::alinous::compile::stmt::ExpressionStatement;
using ::alinous::compile::stmt::ReturnStatement;
using ::alinous::compile::stmt::StatementBlock;
using ::alinous::compile::stmt::StatementList;
using ::alinous::compile::stmt::TypedVariableDeclare;
using ::alinous::db::table::DatabaseException;
using ::alinous::runtime::AlinousModule;
using ::alinous::system::AlinousException;



class ScriptRunner final : public virtual IObject {
public:
	ScriptRunner(const ScriptRunner& base) = default;
public:
	ScriptRunner(ThreadContext* ctx) throw() ;
	void __construct_impl(ThreadContext* ctx) throw() ;
	virtual ~ScriptRunner() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	SQLStatementRunner* sqlRunner;
	AlinousStatementRunner* alinousStmtRunner;
public:
	void run(AlinousModule* module, ScriptMachine* machine, bool debug, ThreadContext* ctx);
	void initMachine(ScriptMachine* machine, ThreadContext* ctx) throw() ;
	void initStatic(AlinousClass* clazz, ScriptMachine* machine, bool debug, ThreadContext* ctx);
private:
	void executeMainScript(ArrayList<StatementList>* statements, ScriptMachine* machine, bool debug, ThreadContext* ctx);
public:
	static bool executeStatementList(StatementList* stmtList, ScriptMachine* machine, bool debug, ThreadContext* ctx);
	static bool executeStatement(IStatement* stmt, ScriptMachine* machine, bool debug, ThreadContext* ctx);
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}}

#endif /* end of ALINOUS_RUNTIME_ENGINE_SCRIPTRUNNER_H_ */
