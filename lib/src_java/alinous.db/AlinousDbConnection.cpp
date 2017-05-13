#include "include/global.h"


#include "alinous.lock/LockObject.h"
#include "alinous.lock/ConcurrentGate.h"
#include "alinous.buffer.storage/IFileStorage.h"
#include "alinous.buffer.storage/FileStorage.h"
#include "alinous.buffer.storage/FileStorageEntryBuilder.h"
#include "alinous.buffer.storage/FileStorageEntryFetcher.h"
#include "alinous.compile/IAlinousElementVisitor.h"
#include "alinous.compile/IAlinousVisitorContainer.h"
#include "alinous.db.table/DatabaseException.h"
#include "alinous.html/IDomObject.h"
#include "alinous.html/DomNode.h"
#include "alinous.remote.socket/NetworkBinaryBuffer.h"
#include "alinous.remote.socket/ICommandData.h"
#include "alinous.numeric/InternalDate.h"
#include "java.sql/Timestamp.h"
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
#include "alinous.runtime.variant/VariantValue.h"
#include "alinous.db.table/IDatabaseRecord.h"
#include "alinous.runtime.dom/DomVariable.h"
#include "alinous.runtime.dom.typed/BigDecimalVariable.h"
#include "alinous.compile.analyse/SourceValidator.h"
#include "alinous.compile/AbstractSrcElement.h"
#include "alinous.compile/IAlinousElement.h"
#include "alinous.compile/IStatement.h"
#include "alinous.compile.declare/IDeclare.h"
#include "alinous.compile.declare.function/AlinousFunction.h"
#include "alinous.db/AlinousDbException.h"
#include "alinous.compile.sql/TableAndSchema.h"
#include "alinous.compile.sql.analyze/ScanTableIdentifier.h"
#include "alinous.compile.sql.analyze/ScanTableColumnIdentifier.h"
#include "alinous.compile.sql.ddl/CheckDefinition.h"
#include "alinous.db.table/TableColumnMetadata.h"
#include "alinous.remote.db.client.command.data/TableClusterData.h"
#include "alinous.db.table/TablePartitionKey.h"
#include "alinous.db.table/TablePartitionKeyCollection.h"
#include "alinous.db.table/TablePartitionRange.h"
#include "alinous.db.table/TablePartitionRangeCollection.h"
#include "alinous.db.table/TableMetadata.h"
#include "alinous.compile.sql.analyze/ScanTableMetadata.h"
#include "java.lang/Comparable.h"
#include "alinous.btree/IBTreeKey.h"
#include "alinous.btree/IBTree.h"
#include "alinous.btree/BTree.h"
#include "alinous.btree/IntKey.h"
#include "alinous.btree/LongValue.h"
#include "alinous.db.table/IOidPublisher.h"
#include "alinous.db.table/LocalOidPublisher.h"
#include "alinous.runtime.parallel/LaunchJoin.h"
#include "alinous.runtime.parallel/IThreadAction.h"
#include "alinous.runtime.parallel/AlinousThread.h"
#include "alinous.runtime.parallel/ThreadPool.h"
#include "alinous.system/ISystemLog.h"
#include "alinous.system/AlinousCore.h"
#include "alinous.compile.expression/IExpression.h"
#include "alinous.compile.sql.expression/ISQLExpression.h"
#include "alinous.compile.sql.parts/ISQLExpressionPart.h"
#include "alinous.compile.sql.parts/AbstractExpressionPart.h"
#include "alinous.compile.sql.parts/SQLExpressionList.h"
#include "alinous.compile.sql/ISqlStatement.h"
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
#include "alinous.db.trx/DbVersionContext.h"
#include "alinous.db.trx.cache/CulumnOrder.h"
#include "alinous.lock.unique/UniqueExclusiveLockManager.h"
#include "alinous.lock.unique/UniqueExclusiveLockClient.h"
#include "alinous.runtime.parallel/SequentialBackgroundJob.h"
#include "alinous.db.trx.cache/TrxRecordsCache.h"
#include "alinous.db/TableSchemaCollection.h"
#include "alinous.db.trx.cache/TrxStorageManager.h"
#include "alinous.compile.sql/InsertValues.h"
#include "alinous.compile.sql/AbstractSQLStatement.h"
#include "alinous.compile.sql/InsertStatement.h"
#include "alinous.compile.sql.result/SelectResultDescription.h"
#include "alinous.compile.sql.select/SQLFrom.h"
#include "alinous.compile.sql/SelectStatement.h"
#include "alinous.compile.sql/UpdateSet.h"
#include "alinous.compile.sql/UpdateStatement.h"
#include "alinous.db.table/DatabaseRecord.h"
#include "java.lang/Number.h"
#include "java.lang/Integer.h"
#include "alinous.db.table/DatabaseTableIdPublisher.h"
#include "alinous.db.table/IBtreeTableIndex.h"
#include "alinous.db.table/IScannableIndex.h"
#include "alinous.db.table/TableIndex.h"
#include "alinous.db.table/DatatableConstants.h"
#include "alinous.db.table/DatatableUpdateCache.h"
#include "alinous.db.table/IDatabaseTable.h"
#include "alinous.db.table/AbstractDatabaseTable.h"
#include "alinous.db.table/DataTableStorageSupport.h"
#include "alinous.db.table/DatatableLockSupport.h"
#include "alinous.db.table/DatatableDDLSupport.h"
#include "alinous.db.table/DatatableUpdateSupport.h"
#include "alinous.db.table.cache/RecordCacheEngine.h"
#include "alinous.db.table.lockmonitor/DatabaseLockException.h"
#include "alinous.db.table/DatabaseTable.h"
#include "alinous.remote.db.client.command.data/SchemaData.h"
#include "alinous.db/ITableSchema.h"
#include "alinous.db/TableSchema.h"
#include "alinous.db.trx/TrxLockContext.h"
#include "alinous.db.trx/DbTransaction.h"
#include "alinous.db.trx/DbTransactionManager.h"
#include "alinous.db.trx/TrxLockManager.h"
#include "alinous.db/ICommidIdPublisher.h"
#include "alinous.system.config/IAlinousConfigElement.h"
#include "alinous.system.config.remote/MonitorRef.h"
#include "alinous.remote.monitor.client/RemoteCommitIdPublisher.h"
#include "alinous.db/ITableRegion.h"
#include "alinous.system.config.remote/RegionRef.h"
#include "alinous.remote.region.client/RemoteRegionRef.h"
#include "alinous.system.config.remote/RegionsRef.h"
#include "alinous.system.config/AlinousDbInstanceInfo.h"
#include "alinous.db/LocalCommitIdPublisher.h"
#include "alinous.db/SchemaManager.h"
#include "alinous.db/LocalTableRegion.h"
#include "alinous.db/TableRegionManager.h"
#include "alinous.compile.sql.ddl/DdlColumnDescriptor.h"
#include "alinous.compile.sql.ddl/PrimaryKeys.h"
#include "alinous.compile.sql.ddl/ShardKeys.h"
#include "alinous.compile.sql.ddl/Unique.h"
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
#include "alinous.runtime/ExecutionException.h"
#include "alinous.runtime.dom/VariableException.h"
#include "alinous.btree/IBTreeNode.h"
#include "alinous.btree/BTreeGlobalCache.h"

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
		acid = IDatabaseDriver::READ_COMMITTED;
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
		throw (new(ctx) AlinousDbException(ConstStr::getCNST_STR_1689(), ctx));
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
						this->database->getCore(ctx)->logError(e1, ctx);
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
				this->database->getCore(ctx)->logError(e, ctx);
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
				this->database->getCore(ctx)->logError(e, ctx);
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
				this->database->getCore(ctx)->logError(e, ctx);
			}
		}
	}
}
void AlinousDbConnection::dropIndex(DropIndexStatement* stmt, ScriptMachine* machine, bool debug, ThreadContext* ctx) throw() 
{
}
void AlinousDbConnection::__cleanUp(ThreadContext* ctx){
}
}}

