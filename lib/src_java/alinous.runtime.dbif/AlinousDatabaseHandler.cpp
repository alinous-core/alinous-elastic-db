#include "include/global.h"


#include "alinous.compile/IAlinousElementVisitor.h"
#include "alinous.compile.analyse/SourceValidator.h"
#include "alinous.compile/IAlinousVisitorContainer.h"
#include "alinous.compile/AbstractSrcElement.h"
#include "alinous.remote.socket/ICommandData.h"
#include "alinous.compile/IAlinousElement.h"
#include "alinous.compile/IStatement.h"
#include "alinous.compile.declare/IDeclare.h"
#include "alinous.remote.socket/NetworkBinaryBuffer.h"
#include "alinous.compile.declare.function/AlinousFunction.h"
#include "alinous.compile.analyse/SrcAnalyseContext.h"
#include "alinous.buffer.storage/FileStorageEntryBuilder.h"
#include "alinous.buffer.storage/FileStorageEntryFetcher.h"
#include "alinous.compile/ExpressionSourceId.h"
#include "alinous.db.table/DatabaseException.h"
#include "alinous.runtime.dom/IAlinousVariable.h"
#include "alinous.runtime.variant/VariantValue.h"
#include "alinous.compile.sql.analyze/ScanTableIdentifier.h"
#include "alinous.compile.sql.analyze/ScanTableColumnIdentifier.h"
#include "alinous.btree/IBTreeValue.h"
#include "alinous.compile.sql.analyze/ScanTableMetadata.h"
#include "alinous.system/AlinousCore.h"
#include "alinous.system.config/IAlinousConfigElement.h"
#include "alinous.system.config/AlinousDbInstanceInfo.h"
#include "alinous.compile.sql/ISqlStatement.h"
#include "alinous.compile.expression/IExpression.h"
#include "alinous.compile.sql.expression/ISQLExpression.h"
#include "alinous.compile.sql.select/SQLGroupBy.h"
#include "alinous.compile.sql.select/SQLLimitOffset.h"
#include "alinous.compile.sql.select/SQLWhere.h"
#include "alinous.compile.sql/AbstractSQLStatement.h"
#include "alinous.compile.sql/InsertStatement.h"
#include "alinous.compile.sql.analyze/IndexColumnMatchCondition.h"
#include "alinous.compile.sql.expression.blexp/ISQLBoolExpression.h"
#include "alinous.compile.sql.expression.blexp/AbstractSQLBooleanExpression.h"
#include "alinous.compile.sql.select.join/SQLJoinCondition.h"
#include "alinous.db.trx.scan/ITableTargetScanner.h"
#include "alinous.compile.sql.select.join/IJoin.h"
#include "alinous.compile.sql.select.join/IJoinTarget.h"
#include "alinous.compile.sql/SelectStatement.h"
#include "alinous.compile.sql/UpdateStatement.h"
#include "alinous.db.trx/DbTransaction.h"
#include "alinous.compile.sql/CreateTableStatement.h"
#include "alinous.compile.sql/DeleteStatement.h"
#include "alinous.compile.sql/DropIndexStatement.h"
#include "alinous.compile.sql/DropTableStatement.h"
#include "alinous.runtime.dbif/ISQLSelectResult.h"
#include "alinous.runtime.dbif/IDatabaseDriver.h"
#include "alinous.db/ConnectInfo.h"
#include "alinous.runtime.dbif/IDatabaseConnection.h"
#include "alinous.db/AlinousDbConnection.h"
#include "alinous.db/AlinousDatabase.h"
#include "alinous.db.trx.scan/ScanResultRecord.h"
#include "alinous.compile.sql.analyze/SQLAnalyseContext.h"
#include "alinous.compile.sql/CreateIndexStatement.h"
#include "alinous.runtime.engine/ScriptMachine.h"
#include "alinous.compile.declare/ClassMemberModifiers.h"
#include "alinous.compile.declare/IClassMember.h"
#include "alinous.compile.declare/AbstractClassMember.h"
#include "alinous.compile.declare/ClassMethodFunction.h"
#include "alinous.compile.declare/AlinousClass.h"
#include "alinous.compile/Token.h"
#include "alinous.system/AlinousException.h"
#include "alinous.db/AlinousDbException.h"
#include "alinous.runtime.dbif/AlinousDatabaseHandler.h"
#include "alinous.runtime.dbif/DataSourceManager.h"

namespace alinous {namespace runtime {namespace dbif {





bool AlinousDatabaseHandler::__init_done = __init_static_variables();
bool AlinousDatabaseHandler::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"AlinousDatabaseHandler", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 AlinousDatabaseHandler::AlinousDatabaseHandler(AlinousDbInstanceInfo* instanceConfig, ThreadContext* ctx) throw()  : IObject(ctx), IDatabaseDriver(ctx), database(nullptr), instanceConfig(nullptr), defaultAcid(0)
{
	__GC_MV(this, &(this->instanceConfig), instanceConfig, AlinousDbInstanceInfo);
	this->defaultAcid = -1;
}
void AlinousDatabaseHandler::__construct_impl(AlinousDbInstanceInfo* instanceConfig, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->instanceConfig), instanceConfig, AlinousDbInstanceInfo);
	this->defaultAcid = -1;
}
 AlinousDatabaseHandler::~AlinousDatabaseHandler() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void AlinousDatabaseHandler::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"AlinousDatabaseHandler", L"~AlinousDatabaseHandler");
	__e_obj1.add(this->database, this);
	database = nullptr;
	__e_obj1.add(this->instanceConfig, this);
	instanceConfig = nullptr;
	if(!prepare){
		return;
	}
}
int AlinousDatabaseHandler::getDefaultAcid(ThreadContext* ctx) throw() 
{
	return this->defaultAcid;
}
void AlinousDatabaseHandler::initDriver(AlinousCore* core, AlinousDbInstanceInfo* instanceConfig, ThreadContext* ctx)
{
	String* dataDir = this->instanceConfig->getDataDir(ctx);
	String* trxTmpDir = this->instanceConfig->getTrxTmpDir(ctx);
	int maxConnection = this->instanceConfig->getMaxConnections(ctx);
	if(trxTmpDir == nullptr)
	{
		trxTmpDir = dataDir->clone(ctx)->append(ConstStr::getCNST_STR_1109(), ctx);
	}
	__GC_MV(this, &(this->database), (new(ctx) AlinousDatabase(ctx)), AlinousDatabase);
	this->database->construct(core, dataDir, trxTmpDir, maxConnection, ctx);
	if(!this->database->exists(ctx))
	{
		this->database->initInstance(instanceConfig, ctx);
	}
	this->database->open(instanceConfig, ctx);
}
void AlinousDatabaseHandler::dispose(ThreadContext* ctx) throw() 
{
	this->database->closeDatabase(ctx);
}
void AlinousDatabaseHandler::createInstance(String* instanceName, ThreadContext* ctx) throw() 
{
}
void AlinousDatabaseHandler::dropInstance(String* instanceName, ThreadContext* ctx) throw() 
{
}
IDatabaseConnection* AlinousDatabaseHandler::connect(ThreadContext* ctx) throw() 
{
	ConnectInfo* info = (new(ctx) ConnectInfo(ctx));
	AlinousDbConnection* con = this->database->connect(info, ctx);
	return con;
}
void AlinousDatabaseHandler::disconnect(IDatabaseConnection* con, bool debug, ThreadContext* ctx) throw() 
{
	con->close(ctx);
}
void AlinousDatabaseHandler::createSchema(IDatabaseConnection* con, String* schema, ScriptMachine* variables, bool debug, ThreadContext* ctx) throw() 
{
	con->createSchema(schema, variables, debug, ctx);
}
void AlinousDatabaseHandler::dropSchema(IDatabaseConnection* con, String* schema, ScriptMachine* variables, bool debug, ThreadContext* ctx) throw() 
{
	con->dropSchema(schema, variables, debug, ctx);
}
ArrayList<String>* AlinousDatabaseHandler::showAllSchema(IDatabaseConnection* con, bool debug, ThreadContext* ctx) throw() 
{
	return con->showAllSchema(ctx);
}
void AlinousDatabaseHandler::createTable(IDatabaseConnection* con, CreateTableStatement* stmt, ScriptMachine* variables, bool debug, ThreadContext* ctx)
{
	con->createTable(stmt, variables, debug, ctx);
}
void AlinousDatabaseHandler::dropTable(IDatabaseConnection* con, DropTableStatement* stmt, ScriptMachine* variables, bool debug, ThreadContext* ctx) throw() 
{
	con->dropTable(stmt, variables, debug, ctx);
}
void AlinousDatabaseHandler::begin(IDatabaseConnection* con, int acid, ThreadContext* ctx)
{
	con->begin(acid, ctx);
}
void AlinousDatabaseHandler::commit(IDatabaseConnection* con, ThreadContext* ctx)
{
	con->commit(ctx);
}
void AlinousDatabaseHandler::rollback(IDatabaseConnection* con, ThreadContext* ctx)
{
	con->rollback(ctx);
}
ISQLSelectResult* AlinousDatabaseHandler::selectSQL(IDatabaseConnection* con, SelectStatement* stmt, ScriptMachine* variables, bool debug, ThreadContext* ctx)
{
	return con->selectSQL(stmt, variables, debug, ctx);
}
void AlinousDatabaseHandler::insertSQL(IDatabaseConnection* con, InsertStatement* stmt, ScriptMachine* variables, bool debug, ThreadContext* ctx)
{
	con->insertSQL(stmt, variables, debug, ctx);
}
void AlinousDatabaseHandler::updateSQL(IDatabaseConnection* con, UpdateStatement* stmt, ScriptMachine* variables, bool debug, ThreadContext* ctx)
{
	con->updateSQL(stmt, variables, debug, ctx);
}
void AlinousDatabaseHandler::deleteSQL(IDatabaseConnection* con, DeleteStatement* stmt, ScriptMachine* variables, bool debug, ThreadContext* ctx)
{
	con->deleteSQL(stmt, variables, debug, ctx);
}
IObject* AlinousDatabaseHandler::getDatabase(ThreadContext* ctx) throw() 
{
	return this->database;
}
void AlinousDatabaseHandler::createIndex(IDatabaseConnection* con, CreateIndexStatement* stmt, ScriptMachine* machine, bool debug, ThreadContext* ctx)
{
	con->createIndex(stmt, machine, debug, ctx);
}
void AlinousDatabaseHandler::dropIndex(IDatabaseConnection* con, DropIndexStatement* stmt, ScriptMachine* machine, bool debug, ThreadContext* ctx) throw() 
{
	con->dropIndex(stmt, machine, debug, ctx);
}
void AlinousDatabaseHandler::__cleanUp(ThreadContext* ctx){
}
}}}

