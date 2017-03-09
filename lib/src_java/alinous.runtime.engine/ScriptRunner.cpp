#include "include/global.h"


#include "alinous.compile/IAlinousElementVisitor.h"
#include "alinous.compile.analyse/SourceValidator.h"
#include "alinous.compile/IAlinousVisitorContainer.h"
#include "alinous.compile/AbstractSrcElement.h"
#include "alinous.remote.socket/ICommandData.h"
#include "alinous.compile/IAlinousElement.h"
#include "alinous.compile/IStatement.h"
#include "alinous.buffer.storage/FileStorageEntryBuilder.h"
#include "alinous.buffer.storage/FileStorageEntryFetcher.h"
#include "alinous.compile/ExpressionSourceId.h"
#include "alinous.db.table/DatabaseException.h"
#include "alinous.html/IDomObject.h"
#include "alinous.html/DomNode.h"
#include "alinous.remote.socket/NetworkBinaryBuffer.h"
#include "alinous.system/AlinousException.h"
#include "alinous.btree/IValueFetcher.h"
#include "alinous.btree/IBTreeValue.h"
#include "alinous.compile.declare/AlinousName.h"
#include "alinous.compile.stmt/AbstractAlinousStatement.h"
#include "alinous.compile.stmt/TypedVariableDeclare.h"
#include "alinous.compile.analyse/SubVariableDeclareHolder.h"
#include "alinous.compile.declare/IDeclare.h"
#include "alinous.runtime.dom/IDomVariableContainer.h"
#include "alinous.runtime.dom/IAlinousVariable.h"
#include "alinous.runtime.dom/IDomVariable.h"
#include "alinous.runtime.dom.typed/ITypedVariable.h"
#include "alinous.compile.declare.function/FunctionArgumentsListDefine.h"
#include "alinous.compile.stmt/StatementList.h"
#include "alinous.compile.stmt/StatementBlock.h"
#include "alinous.runtime.engine.debugger/AlinousScriptDebugger.h"
#include "alinous.system/AlinousCore.h"
#include "alinous.runtime/AlinousModule.h"
#include "alinous.compile.stmt/AssignmentStatement.h"
#include "alinous.compile.stmt/ExpressionStatement.h"
#include "alinous.compile.stmt/ReturnStatement.h"
#include "alinous.runtime.dom.typed/ITypedCaller.h"
#include "alinous.runtime.dom.typed/AbstractTypedVariable.h"
#include "alinous.runtime.dom.typed/TypedVariableArray.h"
#include "alinous.runtime.dom.typed/TimestampVariable.h"
#include "alinous.runtime.dom.typed/TimeVariable.h"
#include "alinous.runtime.dom.typed/ShortVariable.h"
#include "alinous.runtime.dom.typed/LongVariable.h"
#include "alinous.runtime.dom.typed/IntegerVariable.h"
#include "alinous.runtime.dom.typed/FloatVariable.h"
#include "alinous.runtime.dom.typed/DoubleVariable.h"
#include "alinous.runtime.dom.typed/CharVariable.h"
#include "alinous.runtime.dom.typed/StringVariable.h"
#include "alinous.runtime.dom.typed/BoolVariable.h"
#include "alinous.runtime.variant/VariantValue.h"
#include "alinous.runtime.dom.typed/ByteVariable.h"
#include "alinous.runtime.engine/AlinousStatementRunner.h"
#include "alinous.compile.sql/TableAndSchema.h"
#include "alinous.compile.sql.analyze/ScanTableIdentifier.h"
#include "alinous.compile.sql.analyze/ScanTableColumnIdentifier.h"
#include "alinous.compile.sql.ddl/CheckDefinition.h"
#include "alinous.db.table/TableColumnMetadata.h"
#include "alinous.db.table/IDatabaseRecord.h"
#include "alinous.db.table/TablePartitionKey.h"
#include "alinous.db.table/TablePartitionKeyCollection.h"
#include "alinous.db.table/TablePartitionRange.h"
#include "alinous.db.table/TablePartitionRangeCollection.h"
#include "alinous.db.table/TableMetadata.h"
#include "alinous.compile.sql.analyze/ScanTableMetadata.h"
#include "alinous.compile.sql/ISqlStatement.h"
#include "alinous.compile.expression/IExpression.h"
#include "alinous.compile.sql.expression/ISQLExpression.h"
#include "alinous.compile.sql.parts/ISQLExpressionPart.h"
#include "alinous.compile.sql.parts/AbstractExpressionPart.h"
#include "alinous.compile.sql.parts/SQLExpressionList.h"
#include "alinous.compile.sql.select/SQLGroupBy.h"
#include "alinous.compile.sql.select/SQLLimitOffset.h"
#include "alinous.compile.sql.select/SQLWhere.h"
#include "alinous.db.trx.scan/ITableTargetScanner.h"
#include "alinous.compile.sql.analyze/IndexColumnMatchCondition.h"
#include "alinous.compile.sql.expression.blexp/ISQLBoolExpression.h"
#include "alinous.compile.sql.expression.blexp/AbstractSQLBooleanExpression.h"
#include "alinous.compile.sql.select.join/SQLJoinCondition.h"
#include "alinous.compile.sql.select.join/IJoin.h"
#include "alinous.compile.sql.select.join/IJoinTarget.h"
#include "alinous.compile.sql.select.join/AbstractJoinTarget.h"
#include "alinous.compile.sql.select.join/TableJoinTarget.h"
#include "alinous.compile.sql/AbstractSQLStatement.h"
#include "alinous.compile.sql/CreateIndexStatement.h"
#include "alinous.db.trx/DbVersionContext.h"
#include "alinous.db.trx.cache/CulumnOrder.h"
#include "alinous.db.trx.cache/TrxRecordsCache.h"
#include "alinous.db.trx.cache/TrxStorageManager.h"
#include "alinous.compile.sql/InsertValues.h"
#include "alinous.compile.sql/InsertStatement.h"
#include "alinous.compile.sql.result/SelectResultDescription.h"
#include "alinous.compile.sql.select/SQLFrom.h"
#include "alinous.compile.sql/SelectStatement.h"
#include "alinous.compile.sql/UpdateSet.h"
#include "alinous.compile.sql/UpdateStatement.h"
#include "alinous.db/ITableSchema.h"
#include "alinous.db/TableSchema.h"
#include "alinous.db.trx/DbTransaction.h"
#include "alinous.db.trx.scan/ScanResultRecord.h"
#include "alinous.compile.sql.analyze/SQLAnalyseContext.h"
#include "alinous.compile.sql/BeginStatement.h"
#include "alinous.compile.sql/CommitStatement.h"
#include "alinous.compile.sql.ddl/DdlColumnDescriptor.h"
#include "alinous.compile.sql.ddl/PrimaryKeys.h"
#include "alinous.compile.sql.ddl/ShardKeys.h"
#include "alinous.compile.sql.ddl/Unique.h"
#include "alinous.compile.sql/CreateTableStatement.h"
#include "alinous.compile.sql/DeleteStatement.h"
#include "alinous.compile.sql/DropIndexStatement.h"
#include "alinous.compile.sql/DropTableStatement.h"
#include "alinous.compile.sql/RollbackStatement.h"
#include "alinous.runtime.engine/SQLStatementRunner.h"
#include "alinous.runtime.engine/ScriptMachine.h"
#include "alinous.compile.declare.function/FunctionArgumentDefine.h"
#include "alinous.compile.analyse/VariableDeclareHolder.h"
#include "alinous.compile.expression/DomVariableDescriptor.h"
#include "alinous.runtime.dom/DomVariable.h"
#include "alinous.runtime.dom.typed/BigDecimalVariable.h"
#include "alinous.compile.analyse/AlinousType.h"
#include "alinous.compile.declare.function/AlinousFunction.h"
#include "alinous.compile.declare/ClassMemberModifiers.h"
#include "alinous.compile.declare/IClassMember.h"
#include "alinous.compile.declare/AbstractClassMember.h"
#include "alinous.compile.declare/ClassMethodFunction.h"
#include "alinous.compile.declare/AlinousClass.h"
#include "alinous.compile/Token.h"
#include "alinous.runtime/ExecutionException.h"
#include "alinous.runtime.dom/VariableException.h"
#include "alinous.compile.analyse/SrcAnalyseContext.h"
#include "alinous.compile/AlinousSrc.h"
#include "alinous.runtime.engine/ScriptRunner.h"

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
				AlinousCore* core = machine->getCore(ctx);
				AlinousScriptDebugger* debugger = core->getDebugger(ctx);
				debugger->endAlinousOperation(machine, ctx);
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
	throw (new(ctx) AlinousException(ConstStr::getCNST_STR_1263(), ctx));
}
void ScriptRunner::__cleanUp(ThreadContext* ctx){
}
}}}

