#include "include/global.h"


#include "alinous.buffer.storage/FileStorageEntryBuilder.h"
#include "alinous.buffer.storage/FileStorageEntryFetcher.h"
#include "alinous.btree/IValueFetcher.h"
#include "alinous.btree/IBTreeValue.h"
#include "alinous.compile.sql.analyze/ScanTableIdentifier.h"
#include "alinous.compile.sql.analyze/ScanTableColumnIdentifier.h"
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
#include "alinous.compile/ExpressionSourceId.h"
#include "alinous.runtime.dom/IAlinousVariable.h"
#include "alinous.runtime.variant/VariantValue.h"
#include "alinous.db.table/TableMetadata.h"
#include "alinous.compile.sql.analyze/ScanTableMetadata.h"
#include "alinous.db.table/IDatabaseRecord.h"
#include "alinous.db.trx/TrxLockContext.h"
#include "alinous.db.trx.scan/ScanResultRecord.h"
#include "alinous.compile.expression/IExpression.h"
#include "alinous.compile.sql.expression/ISQLExpression.h"
#include "alinous.compile.sql.analyze/SQLAnalyseContext.h"
#include "alinous.compile.sql/ISqlStatement.h"
#include "alinous.compile.sql.select/SQLGroupBy.h"
#include "alinous.compile.sql.select/SQLLimitOffset.h"
#include "alinous.compile.sql.select/SQLWhere.h"
#include "alinous.system/ISystemLog.h"
#include "alinous.db.trx.scan/ITableTargetScanner.h"
#include "alinous.compile.sql.analyze/IndexColumnMatchCondition.h"
#include "alinous.compile.sql.expression.blexp/ISQLBoolExpression.h"
#include "alinous.compile.sql.expression.blexp/AbstractSQLBooleanExpression.h"
#include "alinous.compile.sql.select.join/SQLJoinCondition.h"
#include "alinous.compile.sql.select.join/IJoin.h"
#include "alinous.compile.sql.select.join/IJoinTarget.h"
#include "alinous.runtime.parallel/ThreadPool.h"
#include "alinous.system/AlinousCore.h"
#include "alinous.db/ITableSchema.h"
#include "alinous.db/TableSchema.h"
#include "alinous.compile.sql/AbstractSQLStatement.h"
#include "alinous.compile.sql/CreateTableStatement.h"
#include "alinous.compile.sql/DeleteStatement.h"
#include "alinous.compile.sql/DropIndexStatement.h"
#include "alinous.compile.sql/DropTableStatement.h"
#include "alinous.db.trx/DbVersionContext.h"
#include "alinous.db.trx/DbTransactionManager.h"
#include "alinous.remote.region.client/TableAccessStatusListner.h"
#include "alinous.db.trx/DbTransaction.h"
#include "alinous.remote.region.client.transaction/AbstractRemoteClientTransaction.h"
#include "alinous.db.trx.cache/TrxStorageManager.h"
#include "alinous.compile.sql/InsertStatement.h"
#include "alinous.compile.sql/SelectStatement.h"
#include "alinous.compile.sql/UpdateStatement.h"
#include "alinous.runtime.dbif/ISQLSelectResult.h"
#include "alinous.runtime.dbif/IDatabaseConnection.h"
#include "alinous.system.config/IAlinousConfigElement.h"
#include "alinous.system.config/AlinousDbInstanceInfo.h"
#include "alinous.runtime.dbif/IDatabaseDriver.h"
#include "alinous.runtime.engine/ScriptMachine.h"
#include "alinous.compile.declare/ClassMemberModifiers.h"
#include "alinous.compile.declare/IClassMember.h"
#include "alinous.compile.declare/AbstractClassMember.h"
#include "alinous.compile.declare/ClassMethodFunction.h"
#include "alinous.compile.declare/AlinousClass.h"
#include "alinous.compile/Token.h"
#include "alinous.compile.sql/CreateIndexStatement.h"
#include "alinous.db.trx.ddl/TrxSchemeManager.h"
#include "alinous.db.trx.scan/ScanResult.h"
#include "alinous.lock.unique/UniqueExclusiveLockClient.h"
#include "alinous.db.table/IDatabaseTable.h"
#include "alinous.db/AlinousDatabase.h"
#include "alinous.remote.region.client.transaction/RemoteClientReadCommittedTrx.h"
#include "alinous.remote.region.client.transaction/RemoteClientSerializableTrx.h"
#include "alinous.remote.region.client.transaction/RemoteClientRepeatableReadTrx.h"
#include "alinous.db.trx/ReadCommittedTransaction.h"
#include "alinous.db.trx/RepeatableReadTransaction.h"
#include "alinous.db.trx/SerializableTransaction.h"
#include "alinous.db.trx/DbTransactionFactory.h"

namespace alinous {namespace db {namespace trx {





bool DbTransactionFactory::__init_done = __init_static_variables();
bool DbTransactionFactory::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"DbTransactionFactory", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 DbTransactionFactory::DbTransactionFactory(ThreadContext* ctx) throw()  : IObject(ctx)
{
}
void DbTransactionFactory::__construct_impl(ThreadContext* ctx) throw() 
{
}
 DbTransactionFactory::~DbTransactionFactory() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void DbTransactionFactory::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
}
DbTransaction* DbTransactionFactory::newTransaction(int acid, DbTransactionManager* mgr, String* tmpDir, AlinousDatabase* database, AlinousCore* core, long long commitId, DbVersionContext* vctx, ThreadContext* ctx) throw() 
{
	if(database->isRemote(ctx))
	{
		return newRemoteTransaction(acid, mgr, tmpDir, database, core, commitId, vctx, ctx);
	}
	DbTransaction* trx = nullptr;
	switch(acid) {
	case IDatabaseDriver::READ_COMMITTED:
		trx = (new(ctx) ReadCommittedTransaction(mgr, tmpDir, database, core, commitId, vctx, ctx));
		break ;
	case IDatabaseDriver::REPEATABLE_READ:
		trx = (new(ctx) RepeatableReadTransaction(mgr, tmpDir, database, core, commitId, vctx, ctx));
		break ;
	case IDatabaseDriver::SERIALIZABLE:
	default:
		trx = (new(ctx) SerializableTransaction(mgr, tmpDir, database, core, commitId, vctx, ctx));
		break ;
	}
	return trx;
}
DbTransaction* DbTransactionFactory::newRemoteTransaction(int acid, DbTransactionManager* mgr, String* tmpDir, AlinousDatabase* database, AlinousCore* core, long long commitId, DbVersionContext* vctx, ThreadContext* ctx) throw() 
{
	DbTransaction* trx = nullptr;
	switch(acid) {
	case IDatabaseDriver::READ_COMMITTED:
		trx = (new(ctx) RemoteClientReadCommittedTrx(mgr, tmpDir, database, core, commitId, vctx, ctx));
		break ;
	case IDatabaseDriver::REPEATABLE_READ:
		trx = (new(ctx) RemoteClientRepeatableReadTrx(mgr, tmpDir, database, core, commitId, vctx, ctx));
		break ;
	case IDatabaseDriver::SERIALIZABLE:
	default:
		trx = (new(ctx) RemoteClientSerializableTrx(mgr, tmpDir, database, core, commitId, vctx, ctx));
		break ;
	}
	return trx;
}
void DbTransactionFactory::__cleanUp(ThreadContext* ctx){
}
}}}

