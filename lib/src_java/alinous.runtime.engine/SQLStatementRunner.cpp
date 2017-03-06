#include "include/global.h"


#include "alinous.buffer.storage/FileStorageEntryBuilder.h"
#include "alinous.buffer.storage/FileStorageEntryFetcher.h"
#include "alinous.compile/IAlinousElementVisitor.h"
#include "alinous.compile/IAlinousVisitorContainer.h"
#include "alinous.db.table/DatabaseException.h"
#include "alinous.html/IDomObject.h"
#include "alinous.html/DomNode.h"
#include "alinous.remote.socket/NetworkBinaryBuffer.h"
#include "alinous.remote.socket/ICommandData.h"
#include "alinous.system/AlinousException.h"
#include "alinous.btree/IValueFetcher.h"
#include "alinous.btree/IBTreeValue.h"
#include "alinous.runtime.dom/IDomVariableContainer.h"
#include "alinous.runtime.dom/IAlinousVariable.h"
#include "alinous.runtime.dom/IDomVariable.h"
#include "alinous.runtime.dom.typed/ITypedVariable.h"
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
#include "alinous.runtime.dom.typed/ByteVariable.h"
#include "alinous.runtime.dom.typed/StringVariable.h"
#include "alinous.runtime.dom.typed/BoolVariable.h"
#include "alinous.runtime.engine/AlinousNullPointerException.h"
#include "alinous.runtime.variant/VariantValue.h"
#include "alinous.db.table/IDatabaseRecord.h"
#include "alinous.runtime.dom/DomVariable.h"
#include "alinous.runtime.dom.typed/BigDecimalVariable.h"
#include "alinous.compile.analyse/SourceValidator.h"
#include "alinous.compile/AbstractSrcElement.h"
#include "alinous.compile/IAlinousElement.h"
#include "alinous.compile/IStatement.h"
#include "alinous.compile.declare/IDeclare.h"
#include "alinous.compile.stmt/AbstractAlinousStatement.h"
#include "alinous.compile.stmt/StatementList.h"
#include "alinous.compile.stmt/StatementBlock.h"
#include "alinous.compile.declare.function/AlinousFunction.h"
#include "alinous.db/AlinousDbException.h"
#include "alinous.compile.sql/TableAndSchema.h"
#include "alinous.compile.sql.analyze/ScanTableIdentifier.h"
#include "alinous.compile.sql.analyze/ScanTableColumnIdentifier.h"
#include "alinous.compile.sql.ddl/CheckDefinition.h"
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
#include "alinous.runtime.dom/DomVariableContainer.h"
#include "alinous.runtime.dom.clazz/IAlinousClassVariable.h"
#include "alinous.runtime.dom.clazz/AlinousClassVariable.h"
#include "alinous.runtime.engine/DebugMainFrameSrcElement.h"
#include "alinous.runtime.dom.typed/TypedVariableContainer.h"
#include "alinous.runtime.engine/IStackFrame.h"
#include "alinous.runtime.engine/AbstractStackFrame.h"
#include "alinous.runtime.engine/SubStackFrame.h"
#include "alinous.runtime.engine/MainStackFrame.h"
#include "alinous.db.trx/DbTransaction.h"
#include "alinous.db.trx.scan/ScanResultRecord.h"
#include "alinous.compile.sql.analyze/SQLAnalyseContext.h"
#include "alinous.compile.sql/BeginStatement.h"
#include "alinous.compile.sql/CommitStatement.h"
#include "alinous.compile.sql.ddl/DdlColumnDescriptor.h"
#include "alinous.compile.sql.ddl/PrimaryKeys.h"
#include "alinous.compile.sql.ddl/ShardKeys.h"
#include "alinous.compile.sql.ddl/Unique.h"
#include "alinous.db.table/TablePartitionKey.h"
#include "alinous.db.table/TablePartitionRange.h"
#include "alinous.compile.sql/CreateTableStatement.h"
#include "alinous.compile.sql/DeleteStatement.h"
#include "alinous.compile.sql/DropIndexStatement.h"
#include "alinous.compile.sql/DropTableStatement.h"
#include "alinous.compile.sql/RollbackStatement.h"
#include "alinous.compile.stmt/AssignmentStatement.h"
#include "alinous.compile.stmt/ExpressionStatement.h"
#include "alinous.compile.stmt/ReturnStatement.h"
#include "alinous.compile.stmt/TypedVariableDeclare.h"
#include "alinous.runtime.dbif/IDatabaseConnection.h"
#include "alinous.runtime.dbif/IDatabaseDriver.h"
#include "alinous.runtime.engine/DatabaseHandle.h"
#include "alinous.runtime.engine/SQLStatementRunner.h"
#include "alinous.compile.expression.expstream/IdentifierVariable.h"
#include "alinous.runtime.engine/AlinousStatementRunner.h"
#include "alinous.runtime.engine/ScriptRunner.h"
#include "alinous.runtime/AlinousModule.h"
#include "alinous.server.http.params/AbstractHttpParameter.h"
#include "alinous.server.http.params/HttpArrayParameter.h"
#include "alinous.server.http.params/HttpParameter.h"
#include "alinous.server.http.params/HttpUploadParameter.h"
#include "alinous.runtime.engine/ExpressionStreamBuffer.h"
#include "alinous.runtime.engine/ScriptMachine.h"
#include "alinous.compile/ExpressionSourceId.h"
#include "alinous.compile.expression/DomVariableDescriptor.h"
#include "alinous.compile.declare/AlinousName.h"
#include "alinous.compile.analyse/SrcAnalyseContext.h"
#include "alinous.compile.declare/ClassMemberModifiers.h"
#include "alinous.compile.declare/IClassMember.h"
#include "alinous.compile.declare/AbstractClassMember.h"
#include "alinous.compile.declare/ClassMethodFunction.h"
#include "alinous.compile.declare/AlinousClass.h"
#include "alinous.compile/Token.h"
#include "alinous.runtime.engine/HttpParamHandler.h"

namespace alinous {namespace runtime {namespace engine {





bool SQLStatementRunner::__init_done = __init_static_variables();
bool SQLStatementRunner::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"SQLStatementRunner", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 SQLStatementRunner::SQLStatementRunner(ThreadContext* ctx) throw()  : IObject(ctx)
{
}
void SQLStatementRunner::__construct_impl(ThreadContext* ctx) throw() 
{
}
 SQLStatementRunner::~SQLStatementRunner() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void SQLStatementRunner::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
}
bool SQLStatementRunner::executeCreateTableStatement(CreateTableStatement* stmt, ScriptMachine* machine, bool debug, ThreadContext* ctx)
{
	DatabaseHandle* handle = machine->getCurrentDbHandle(ctx);
	IDatabaseConnection* con = handle->getCon(ctx);
	IDatabaseDriver* driver = handle->getDbdriver(ctx);
	driver->createTable(con, stmt, machine, debug, ctx);
	return false;
}
bool SQLStatementRunner::executeDropTableStatement(DropTableStatement* stmt, ScriptMachine* machine, bool debug, ThreadContext* ctx) throw() 
{
	DatabaseHandle* handle = machine->getCurrentDbHandle(ctx);
	IDatabaseConnection* con = handle->getCon(ctx);
	IDatabaseDriver* driver = handle->getDbdriver(ctx);
	driver->dropTable(con, stmt, machine, debug, ctx);
	return false;
}
bool SQLStatementRunner::executeBeginStatement(BeginStatement* stmt, ScriptMachine* machine, bool debug, ThreadContext* ctx)
{
	DatabaseHandle* handle = machine->getCurrentDbHandle(ctx);
	IDatabaseConnection* con = handle->getCon(ctx);
	IDatabaseDriver* driver = handle->getDbdriver(ctx);
	int acid = driver->getDefaultAcid(ctx);
	int beginIsolationLevel = stmt->getIsolationLevel(ctx);
	if(beginIsolationLevel > 0)
	{
		acid = beginIsolationLevel;
	}
	driver->begin(con, acid, ctx);
	return false;
}
bool SQLStatementRunner::executeCommitStatement(CommitStatement* stmt, ScriptMachine* machine, bool debug, ThreadContext* ctx)
{
	DatabaseHandle* handle = machine->getCurrentDbHandle(ctx);
	IDatabaseConnection* con = handle->getCon(ctx);
	IDatabaseDriver* driver = handle->getDbdriver(ctx);
	driver->commit(con, ctx);
	return false;
}
bool SQLStatementRunner::executeRollbackStatement(RollbackStatement* stmt, ScriptMachine* machine, bool debug, ThreadContext* ctx)
{
	DatabaseHandle* handle = machine->getCurrentDbHandle(ctx);
	IDatabaseConnection* con = handle->getCon(ctx);
	IDatabaseDriver* driver = handle->getDbdriver(ctx);
	driver->rollback(con, ctx);
	return false;
}
bool SQLStatementRunner::executeInsertStatement(InsertStatement* stmt, ScriptMachine* machine, bool debug, ThreadContext* ctx)
{
	DatabaseHandle* handle = machine->getCurrentDbHandle(ctx);
	IDatabaseConnection* con = handle->getCon(ctx);
	IDatabaseDriver* driver = handle->getDbdriver(ctx);
	driver->insertSQL(con, stmt, machine, debug, ctx);
	return false;
}
bool SQLStatementRunner::executeDeleteStatement(DeleteStatement* stmt, ScriptMachine* machine, bool debug, ThreadContext* ctx)
{
	DatabaseHandle* handle = machine->getCurrentDbHandle(ctx);
	IDatabaseConnection* con = handle->getCon(ctx);
	IDatabaseDriver* driver = handle->getDbdriver(ctx);
	driver->deleteSQL(con, stmt, machine, debug, ctx);
	return false;
}
bool SQLStatementRunner::executeUpdateStatement(UpdateStatement* stmt, ScriptMachine* machine, bool debug, ThreadContext* ctx)
{
	DatabaseHandle* handle = machine->getCurrentDbHandle(ctx);
	IDatabaseConnection* con = handle->getCon(ctx);
	IDatabaseDriver* driver = handle->getDbdriver(ctx);
	driver->updateSQL(con, stmt, machine, debug, ctx);
	return false;
}
bool SQLStatementRunner::executeSelectStatement(SelectStatement* stmt, ScriptMachine* machine, bool debug, ThreadContext* ctx)
{
	DatabaseHandle* handle = machine->getCurrentDbHandle(ctx);
	IDatabaseConnection* con = handle->getCon(ctx);
	IDatabaseDriver* driver = handle->getDbdriver(ctx);
	driver->selectSQL(con, stmt, machine, debug, ctx);
	return false;
}
bool SQLStatementRunner::executeCreateIndexStatement(CreateIndexStatement* stmt, ScriptMachine* machine, bool debug, ThreadContext* ctx)
{
	DatabaseHandle* handle = machine->getCurrentDbHandle(ctx);
	IDatabaseConnection* con = handle->getCon(ctx);
	IDatabaseDriver* driver = handle->getDbdriver(ctx);
	driver->createIndex(con, stmt, machine, debug, ctx);
	return false;
}
bool SQLStatementRunner::executeDropIndexStatement(DropIndexStatement* stmt, ScriptMachine* machine, bool debug, ThreadContext* ctx) throw() 
{
	DatabaseHandle* handle = machine->getCurrentDbHandle(ctx);
	IDatabaseConnection* con = handle->getCon(ctx);
	IDatabaseDriver* driver = handle->getDbdriver(ctx);
	driver->dropIndex(con, stmt, machine, debug, ctx);
	return false;
}
void SQLStatementRunner::__cleanUp(ThreadContext* ctx){
}
}}}

