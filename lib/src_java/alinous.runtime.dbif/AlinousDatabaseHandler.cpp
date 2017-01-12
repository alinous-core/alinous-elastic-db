#include "includes.h"


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
		trxTmpDir = dataDir->clone(ctx)->append(ConstStr::getCNST_STR_1099(), ctx);
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
}}}

