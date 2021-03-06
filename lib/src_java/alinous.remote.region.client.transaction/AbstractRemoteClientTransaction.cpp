#include "include/global.h"


#include "alinous.btree/BTreeException.h"
#include "alinous.buffer.storage/FileStorageEntryBuilder.h"
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
#include "alinous.buffer.storage/FileStorageEntryFetcher.h"
#include "alinous.compile/ExpressionSourceId.h"
#include "alinous.system/AlinousException.h"
#include "alinous.runtime.dom/IAlinousVariable.h"
#include "alinous.runtime.variant/VariantValue.h"
#include "alinous.db/AlinousDbException.h"
#include "alinous.system/ISystemLog.h"
#include "alinous.system/AlinousCore.h"
#include "alinous.runtime.engine/ScriptMachine.h"
#include "alinous.compile.expression/IExpression.h"
#include "alinous.compile.declare/ClassMemberModifiers.h"
#include "alinous.compile.declare/IClassMember.h"
#include "alinous.compile.declare/AbstractClassMember.h"
#include "alinous.compile.declare/ClassMethodFunction.h"
#include "alinous.compile.declare/AlinousClass.h"
#include "alinous.compile/Token.h"
#include "alinous.runtime/ExecutionException.h"
#include "alinous.runtime.dom/VariableException.h"
#include "alinous.btree/IValueFetcher.h"
#include "alinous.btree/IBTreeValue.h"
#include "alinous.compile.sql.analyze/ScanTableIdentifier.h"
#include "alinous.compile.sql.analyze/ScanTableColumnIdentifier.h"
#include "alinous.db.table/TableMetadata.h"
#include "alinous.compile.sql.analyze/ScanTableMetadata.h"
#include "alinous.db.table/IDatabaseRecord.h"
#include "alinous.db.trx/TrxLockContext.h"
#include "alinous.db.trx.scan/ScanResultRecord.h"
#include "alinous.compile.sql.expression/ISQLExpression.h"
#include "alinous.compile.sql.analyze/SQLAnalyseContext.h"
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
#include "alinous.compile.sql/AbstractSQLStatement.h"
#include "alinous.compile.sql/CreateIndexStatement.h"
#include "alinous.db.trx/DbVersionContext.h"
#include "alinous.db/ITableSchema.h"
#include "alinous.db/TableSchemaCollection.h"
#include "alinous.remote.region.client/TableAccessStatusListner.h"
#include "alinous.db.trx.cache/TrxStorageManager.h"
#include "alinous.compile.sql/InsertStatement.h"
#include "alinous.compile.sql/SelectStatement.h"
#include "alinous.compile.sql/UpdateStatement.h"
#include "alinous.runtime.parallel/ThreadPool.h"
#include "alinous.db/TableSchema.h"
#include "alinous.db.trx.ddl/TrxSchemeManager.h"
#include "alinous.db.trx.scan/ScanResult.h"
#include "alinous.lock.unique/UniqueExclusiveLockClient.h"
#include "alinous.db.trx/DbTransactionManager.h"
#include "alinous.db.trx/DbTransaction.h"
#include "alinous.db.table/IDatabaseTable.h"
#include "alinous.db/AlinousDatabase.h"
#include "alinous.remote.region.client.transaction/AbstractRemoteClientTransaction.h"

namespace alinous {namespace remote {namespace region {namespace client {namespace transaction {





bool AbstractRemoteClientTransaction::__init_done = __init_static_variables();
bool AbstractRemoteClientTransaction::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"AbstractRemoteClientTransaction", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 AbstractRemoteClientTransaction::AbstractRemoteClientTransaction(DbTransactionManager* mgr, String* tmpDir, AlinousDatabase* database, AlinousCore* core, long long commitId, DbVersionContext* vctx, ThreadContext* ctx) throw()  : IObject(ctx), DbTransaction(mgr, tmpDir, database, core, commitId, vctx, ctx), accessListner(nullptr)
{
	__GC_MV(this, &(this->accessListner), (new(ctx) TableAccessStatusListner(ctx)), TableAccessStatusListner);
}
void AbstractRemoteClientTransaction::__construct_impl(DbTransactionManager* mgr, String* tmpDir, AlinousDatabase* database, AlinousCore* core, long long commitId, DbVersionContext* vctx, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->accessListner), (new(ctx) TableAccessStatusListner(ctx)), TableAccessStatusListner);
}
 AbstractRemoteClientTransaction::~AbstractRemoteClientTransaction() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void AbstractRemoteClientTransaction::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"AbstractRemoteClientTransaction", L"~AbstractRemoteClientTransaction");
	__e_obj1.add(this->accessListner, this);
	accessListner = nullptr;
	if(!prepare){
		return;
	}
	DbTransaction::__releaseRegerences(true, ctx);
}
bool AbstractRemoteClientTransaction::isRemote(ThreadContext* ctx) throw() 
{
	return true;
}
void AbstractRemoteClientTransaction::createTable(TableSchema* schema, ThreadContext* ctx)
{
	if(schema->getregionName(ctx) == nullptr)
	{
		throw (new(ctx) AlinousDbException(ConstStr::getCNST_STR_3610(), ctx));
	}
	DbTransaction::createTable(schema, ctx);
}
TableAccessStatusListner* AbstractRemoteClientTransaction::getAccessListner(ThreadContext* ctx) throw() 
{
	return accessListner;
}
void AbstractRemoteClientTransaction::commitUpdateInsert(long long newCommitId, ThreadContext* ctx)
{
	if(this->trxStorageManager->isHasOperation(ctx))
	{
		{
			try
			{
				this->trxStorageManager->commitRemote(this, newCommitId, this->accessListner, ctx);
			}
			catch(IOException* e)
			{
				(new(ctx) AlinousDbException(ConstStr::getCNST_STR_1692(), e, ctx));
			}
			catch(InterruptedException* e)
			{
				(new(ctx) AlinousDbException(ConstStr::getCNST_STR_1692(), e, ctx));
			}
			catch(VariableException* e)
			{
				(new(ctx) AlinousDbException(ConstStr::getCNST_STR_1692(), e, ctx));
			}
			catch(BTreeException* e)
			{
				(new(ctx) AlinousDbException(ConstStr::getCNST_STR_1692(), e, ctx));
			}
		}
	}
	List<String>* commitList = this->accessListner->getUncommitedTables(ctx);
	int maxLoop = commitList->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		String* fullName = commitList->get(i, ctx);
		IDatabaseTable* table = getTable(fullName, ctx);
		table->cleanSelectLocks(this, newCommitId, ctx);
	}
	this->trxStorageManager->reset(ctx);
}
IDatabaseTable* AbstractRemoteClientTransaction::getTable(String* fullName, ThreadContext* ctx) throw() 
{
	AlinousDatabase* database = this->database;
	IArrayObject<String>* names = fullName->split(ConstStr::getCNST_STR_361(), ctx);
	TableSchemaCollection* schema = database->getSchema(names->get(0), ctx);
	IDatabaseTable* table = schema->getTableStore(names->get(1), ctx);
	return table;
}
void AbstractRemoteClientTransaction::__cleanUp(ThreadContext* ctx){
}
}}}}}

