#include "includes.h"


namespace alinous {namespace db {





bool AlinousDbConnection::__init_done = __init_static_variables();
bool AlinousDbConnection::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"AlinousDbConnection", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 AlinousDbConnection::AlinousDbConnection(AlinousDatabase* database, ConnectInfo* info, ThreadContext* ctx) throw()  : IObject(ctx), IDatabaseConnection(ctx), autoCommit(0), database(nullptr), trx(nullptr)
{
	this->autoCommit = false;
	__GC_MV(this, &(this->database), database, AlinousDatabase);
}
void AlinousDbConnection::__construct_impl(AlinousDatabase* database, ConnectInfo* info, ThreadContext* ctx) throw() 
{
	this->autoCommit = false;
	__GC_MV(this, &(this->database), database, AlinousDatabase);
}
 AlinousDbConnection::~AlinousDbConnection() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void AlinousDbConnection::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"AlinousDbConnection", L"~AlinousDbConnection");
	__e_obj1.add(this->database, this);
	database = nullptr;
	__e_obj1.add(this->trx, this);
	trx = nullptr;
	if(!prepare){
		return;
	}
}
void AlinousDbConnection::close(ThreadContext* ctx) throw() 
{
	this->database->disConnect(this, ctx);
}
bool AlinousDbConnection::isAutoCommit(ThreadContext* ctx) throw() 
{
	return this->autoCommit;
}
void AlinousDbConnection::begin(int acid, ThreadContext* ctx)
{
	if(acid < 0)
	{
		acid = IDatabaseDriver::SERIALIZABLE;
	}
	__GC_MV(this, &(this->trx), this->database->trxManager->borrowTransaction(acid, ctx), DbTransaction);
	this->autoCommit = false;
	DbVersionContext* vctx = this->trx->getVersionContext(ctx);
	this->database->syncSchemaVersion(vctx, ctx);
}
void AlinousDbConnection::commit(ThreadContext* ctx)
{
	if(this->autoCommit)
	{
		throw (new(ctx) AlinousDbException(ConstStr::getCNST_STR_1684(), ctx));
	}
	if(this->trx != nullptr)
	{
		{
			try
			{
				this->trx->commit(ctx);
			}
			catch(Throwable* e)
			{
				{
					try
					{
						this->trx->close(ctx);
					}
					catch(DatabaseLockException* e1)
					{
						e1->printStackTrace(ctx);
						this->database->getCore(ctx)->getLogger(ctx)->logError(e1, ctx);
					}
				}
				__GC_MV(this, &(this->trx), nullptr, DbTransaction);
				throw e;
			}
		}
		{
			try
			{
				this->trx->close(ctx);
			}
			catch(DatabaseLockException* e)
			{
				e->printStackTrace(ctx);
				this->database->getCore(ctx)->getLogger(ctx)->logError(e, ctx);
			}
		}
		__GC_MV(this, &(this->trx), nullptr, DbTransaction);
	}
	this->autoCommit = true;
}
void AlinousDbConnection::rollback(ThreadContext* ctx) throw() 
{
	if(this->trx != nullptr)
	{
		{
			try
			{
				this->trx->close(ctx);
			}
			catch(DatabaseLockException* e)
			{
				e->printStackTrace(ctx);
				this->database->getCore(ctx)->getLogger(ctx)->logError(e, ctx);
			}
		}
	}
	this->autoCommit = true;
}
void AlinousDbConnection::createTable(CreateTableStatement* stmt, ScriptMachine* machine, bool debug, ThreadContext* ctx)
{
	TableSchema* schema = stmt->createMetadata(machine, debug, ctx);
	this->trx->createTable(schema, ctx);
	if(this->autoCommit)
	{
		{
			try
			{
				this->trx->commit(ctx);
			}
			catch(Throwable* e)
			{
				this->trx->close(ctx);
				throw e;
			}
		}
		this->trx->close(ctx);
	}
}
void AlinousDbConnection::dropTable(DropTableStatement* stmt, ScriptMachine* machine, bool debug, ThreadContext* ctx) throw() 
{
}
void AlinousDbConnection::createSchema(String* schema, ScriptMachine* machine, bool debug, ThreadContext* ctx) throw() 
{
}
void AlinousDbConnection::dropSchema(String* schema, ScriptMachine* machine, bool debug, ThreadContext* ctx) throw() 
{
}
ArrayList<String>* AlinousDbConnection::showAllSchema(ThreadContext* ctx) throw() 
{
	return nullptr;
}
ISQLSelectResult* AlinousDbConnection::selectSQL(SelectStatement* stmt, ScriptMachine* machine, bool debug, ThreadContext* ctx)
{
	SQLAnalyseContext* context = (new(ctx) SQLAnalyseContext(this->database, machine, ctx));
	stmt->analyzeSQL(context, debug, ctx);
	this->trx->select(stmt, machine, debug, ctx);
	return nullptr;
}
void AlinousDbConnection::insertSQL(InsertStatement* stmt, ScriptMachine* machine, bool debug, ThreadContext* ctx)
{
	DbVersionContext* vctx = this->trx->getVersionContext(ctx);
	if(stmt->needsAnalyse(vctx, ctx))
	{
		SQLAnalyseContext* context = (new(ctx) SQLAnalyseContext(this->database, machine, ctx));
		stmt->analyzeSQL(context, debug, ctx);
		stmt->setVctx(vctx, ctx);
	}
	this->trx->insert(stmt, machine, debug, ctx);
	if(this->autoCommit)
	{
		{
			try
			{
				this->trx->commit(ctx);
			}
			catch(Throwable* e)
			{
				this->trx->close(ctx);
				throw e;
			}
		}
		this->trx->close(ctx);
	}
}
void AlinousDbConnection::updateSQL(UpdateStatement* stmt, ScriptMachine* machine, bool debug, ThreadContext* ctx)
{
	SQLAnalyseContext* context = (new(ctx) SQLAnalyseContext(this->database, machine, ctx));
	stmt->analyzeSQL(context, debug, ctx);
	this->trx->update(stmt, machine, debug, ctx);
	if(this->autoCommit)
	{
		{
			try
			{
				this->trx->commit(ctx);
			}
			catch(Throwable* e)
			{
				this->trx->close(ctx);
				throw e;
			}
		}
		this->trx->close(ctx);
	}
}
void AlinousDbConnection::deleteSQL(DeleteStatement* stmt, ScriptMachine* machine, bool debug, ThreadContext* ctx) throw() 
{
}
void AlinousDbConnection::createIndex(CreateIndexStatement* stmt, ScriptMachine* machine, bool debug, ThreadContext* ctx)
{
	this->trx->createIndex(stmt, machine, ctx);
	if(this->autoCommit)
	{
		{
			try
			{
				this->trx->commit(ctx);
			}
			catch(Throwable* e)
			{
				{
					try
					{
						this->trx->close(ctx);
					}
					catch(DatabaseLockException* e1)
					{
						e1->printStackTrace(ctx);
						this->database->getCore(ctx)->getLogger(ctx)->logError(e1, ctx);
					}
				}
				throw e;
			}
		}
		{
			try
			{
				this->trx->close(ctx);
			}
			catch(DatabaseLockException* e)
			{
				e->printStackTrace(ctx);
				this->database->getCore(ctx)->getLogger(ctx)->logError(e, ctx);
			}
		}
	}
}
void AlinousDbConnection::dropIndex(DropIndexStatement* stmt, ScriptMachine* machine, bool debug, ThreadContext* ctx) throw() 
{
}
}}

