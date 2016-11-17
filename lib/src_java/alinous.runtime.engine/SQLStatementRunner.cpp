#include "includes.h"


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
}}}

