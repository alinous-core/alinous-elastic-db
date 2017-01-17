#include "includes.h"


namespace alinous {namespace runtime {namespace engine {





bool ScriptRunner::__init_done = __init_static_variables();
bool ScriptRunner::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"ScriptRunner", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 ScriptRunner::ScriptRunner(ThreadContext* ctx) throw()  : IObject(ctx), sqlRunner(nullptr), alinousStmtRunner(nullptr)
{
	__GC_MV(this, &(this->sqlRunner), (new(ctx) SQLStatementRunner(ctx)), SQLStatementRunner);
	__GC_MV(this, &(this->alinousStmtRunner), (new(ctx) AlinousStatementRunner(ctx)), AlinousStatementRunner);
}
void ScriptRunner::__construct_impl(ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->sqlRunner), (new(ctx) SQLStatementRunner(ctx)), SQLStatementRunner);
	__GC_MV(this, &(this->alinousStmtRunner), (new(ctx) AlinousStatementRunner(ctx)), AlinousStatementRunner);
}
 ScriptRunner::~ScriptRunner() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void ScriptRunner::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"ScriptRunner", L"~ScriptRunner");
	__e_obj1.add(this->sqlRunner, this);
	sqlRunner = nullptr;
	__e_obj1.add(this->alinousStmtRunner, this);
	alinousStmtRunner = nullptr;
	if(!prepare){
		return;
	}
}
void ScriptRunner::run(AlinousModule* module, ScriptMachine* machine, bool debug, ThreadContext* ctx)
{
	AlinousSrc* src = module->getModuleSource(ctx);
	machine->setAlinousStmtRunner(this->alinousStmtRunner, ctx);
	machine->setSqlRunner(this->sqlRunner, ctx);
	executeMainScript(src->getStatements(ctx), machine, debug, ctx);
}
void ScriptRunner::initMachine(ScriptMachine* machine, ThreadContext* ctx) throw() 
{
	machine->setAlinousStmtRunner(this->alinousStmtRunner, ctx);
	machine->setSqlRunner(this->sqlRunner, ctx);
}
void ScriptRunner::initStatic(AlinousClass* clazz, ScriptMachine* machine, bool debug, ThreadContext* ctx)
{
	clazz->initStatic(machine, debug, ctx);
}
void ScriptRunner::executeMainScript(ArrayList<StatementList>* statements, ScriptMachine* machine, bool debug, ThreadContext* ctx)
{
	if(debug)
	{
		machine->getCore(ctx)->getDebugger(ctx)->startAlinousOperation(machine, ctx);
	}
	{
		std::function<void(void)> finallyLm2= [&, this]()
		{
			if(debug)
			{
				machine->getCore(ctx)->getDebugger(ctx)->endAlinousOperation(machine, ctx);
			}
		};
		Releaser finalyCaller2(finallyLm2);
		try
		{
			int maxLoop = statements->size(ctx);
			for(int i = 0; i != maxLoop; ++i)
			{
				StatementList* stmtList = statements->get(i, ctx);
				executeStatementList(stmtList, machine, debug, ctx);
			}
		}
		catch(...){throw;}
	}
}
bool ScriptRunner::executeStatementList(StatementList* stmtList, ScriptMachine* machine, bool debug, ThreadContext* ctx)
{
	int maxLoop = stmtList->getList(ctx)->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		IStatement* stmt = stmtList->getList(ctx)->get(i, ctx);
		bool controled = executeStatement(stmt, machine, debug, ctx);
		if(controled)
		{
			return true;
		}
	}
	return false;
}
bool ScriptRunner::executeStatement(IStatement* stmt, ScriptMachine* machine, bool debug, ThreadContext* ctx)
{
	if(debug)
	{
		machine->getCore(ctx)->getDebugger(ctx)->notifyBefore(stmt, machine, ctx);
	}
	switch(stmt->getType(ctx)) {
	case IStatement::StatementType::ASSIGN:
		return machine->getAlinousStmtRunner(ctx)->assignStatement(static_cast<AssignmentStatement*>(stmt), machine, debug, ctx);
	case IStatement::StatementType::EXPRESSION:
		return machine->getAlinousStmtRunner(ctx)->expressionStatement(static_cast<ExpressionStatement*>(stmt), machine, debug, ctx);
	case IStatement::StatementType::RETURN:
		return machine->getAlinousStmtRunner(ctx)->returnStatement(static_cast<ReturnStatement*>(stmt), machine, debug, ctx);
	case IStatement::StatementType::BLOCK:
		return machine->getAlinousStmtRunner(ctx)->statementBlock(static_cast<StatementBlock*>(stmt), machine, debug, ctx);
	case IStatement::StatementType::STMT_LIST:
		return machine->getAlinousStmtRunner(ctx)->statementList(static_cast<StatementList*>(stmt), machine, debug, ctx);
	case IStatement::StatementType::TYPED_VARIABLE_DECLARE:
		return machine->getAlinousStmtRunner(ctx)->typedVariableDeclare(static_cast<TypedVariableDeclare*>(stmt), machine, debug, ctx);
	case IStatement::StatementType::FOR_STATEMENT:
		break ;
	case IStatement::StatementType::FOR_UPDATE_STATEMENT_PART:
		break ;
	case IStatement::StatementType::IF_STATEMENT:
		break ;
	case IStatement::StatementType::FINALLY_STATEMENT:
		break ;
	case IStatement::StatementType::LABELED_STATEMENT:
		break ;
	case IStatement::StatementType::TRY_STATEMENT:
		break ;
	case IStatement::StatementType::WHILE_STATEMENT:
		break ;
	case IStatement::StatementType::DO_WHILE_STATEMENT:
		break ;
	case IStatement::StatementType::SWITCH_STATEMENT:
		break ;
	case IStatement::StatementType::CATCH_STATEMENT:
		break ;
	case IStatement::StatementType::BREAK_STATEMENT:
		break ;
	case IStatement::StatementType::THROW_STATEMENT:
		break ;
	case IStatement::StatementType::BEGIN:
		return machine->getSqlRunner(ctx)->executeBeginStatement(static_cast<BeginStatement*>(stmt), machine, debug, ctx);
	case IStatement::StatementType::COMMIT:
		return machine->getSqlRunner(ctx)->executeCommitStatement(static_cast<CommitStatement*>(stmt), machine, debug, ctx);
	case IStatement::StatementType::CREATE_TABLE:
		return machine->getSqlRunner(ctx)->executeCreateTableStatement(static_cast<CreateTableStatement*>(stmt), machine, debug, ctx);
	case IStatement::StatementType::DELETE:
		return machine->getSqlRunner(ctx)->executeDeleteStatement(static_cast<DeleteStatement*>(stmt), machine, debug, ctx);
	case IStatement::StatementType::DROP_TABLE:
		return machine->getSqlRunner(ctx)->executeDropTableStatement(static_cast<DropTableStatement*>(stmt), machine, debug, ctx);
	case IStatement::StatementType::INSERT:
		return machine->getSqlRunner(ctx)->executeInsertStatement(static_cast<InsertStatement*>(stmt), machine, debug, ctx);
	case IStatement::StatementType::ROLLBACK:
		return machine->getSqlRunner(ctx)->executeRollbackStatement(static_cast<RollbackStatement*>(stmt), machine, debug, ctx);
	case IStatement::StatementType::SELECT:
		return machine->getSqlRunner(ctx)->executeSelectStatement(static_cast<SelectStatement*>(stmt), machine, debug, ctx);
	case IStatement::StatementType::UPDATE:
		return machine->getSqlRunner(ctx)->executeUpdateStatement(static_cast<UpdateStatement*>(stmt), machine, debug, ctx);
	case IStatement::StatementType::CREATE_INDEX:
		return machine->getSqlRunner(ctx)->executeCreateIndexStatement(static_cast<CreateIndexStatement*>(stmt), machine, debug, ctx);
	case IStatement::StatementType::DROP_INDEX:
		return machine->getSqlRunner(ctx)->executeDropIndexStatement(static_cast<DropIndexStatement*>(stmt), machine, debug, ctx);
	default:
		break ;
	}
	throw (new(ctx) AlinousException(ConstStr::getCNST_STR_1155(), ctx));
}
}}}

