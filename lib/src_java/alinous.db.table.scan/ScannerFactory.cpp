#include "include/global.h"


#include "alinous.buffer.storage/FileStorageEntryBuilder.h"
#include "alinous.buffer.storage/FileStorageEntryFetcher.h"
#include "alinous.compile/ExpressionSourceId.h"
#include "alinous.compile/IAlinousVisitorContainer.h"
#include "alinous.compile/AbstractSrcElement.h"
#include "alinous.remote.socket/ICommandData.h"
#include "alinous.compile/IAlinousElement.h"
#include "alinous.compile.declare/IDeclare.h"
#include "alinous.remote.socket/NetworkBinaryBuffer.h"
#include "alinous.compile.declare.function/AlinousFunction.h"
#include "alinous.compile.declare/ClassMemberModifiers.h"
#include "alinous.compile.declare/IClassMember.h"
#include "alinous.compile.declare/AbstractClassMember.h"
#include "alinous.compile.declare/ClassMethodFunction.h"
#include "alinous.compile/Token.h"
#include "alinous.system/AlinousException.h"
#include "alinous.runtime.dom/IAlinousVariable.h"
#include "alinous.runtime.variant/VariantValue.h"
#include "alinous.db/AlinousDbException.h"
#include "alinous.runtime.engine/ScriptMachine.h"
#include "alinous.compile.declare/AlinousClass.h"
#include "alinous.compile.analyse/SrcAnalyseContext.h"
#include "alinous.compile.expression/IExpression.h"
#include "alinous.compile.sql.analyze/ScanTableIdentifier.h"
#include "alinous.compile.sql.analyze/ScanTableColumnIdentifier.h"
#include "alinous.compile.sql.analyze/ScanTableMetadata.h"
#include "alinous.system/ISystemLog.h"
#include "java.lang/Comparable.h"
#include "alinous.btree/IBTreeKey.h"
#include "alinous.db.trx.scan/ScanResultIndexKey.h"
#include "alinous.btree/IBTreeValue.h"
#include "alinous.db.trx.scan/ScanResultRecord.h"
#include "alinous.db.trx.scan/ITableTargetScanner.h"
#include "alinous.db.trx/DbTransaction.h"
#include "alinous.db.table/IScannableIndex.h"
#include "alinous.db.table/IDatabaseTable.h"
#include "alinous.compile.sql.analyze/SQLAnalyseContext.h"
#include "alinous.compile.sql.expression/ISQLExpression.h"
#include "alinous.compile.sql.analyze/InnerNecessaryCondition.h"
#include "alinous.compile.sql.analyze/JoinMatchExpression.h"
#include "alinous.compile.sql.analyze/IndexColumnMatchCondition.h"
#include "alinous.compile.sql.expression.blexp/ISQLBoolExpression.h"
#include "alinous.compile.sql.expression.blexp/AbstractSQLBooleanExpression.h"
#include "alinous.compile.sql.select.join/SQLJoinCondition.h"
#include "alinous.db.trx.scan/IJoinScanner.h"
#include "alinous.compile.sql.select.join.scan/CrossJoinScanner.h"
#include "alinous.compile.sql.select.join.scan/ReverseIndexScanner.h"
#include "alinous.compile.sql.select.join.scan/RightindexJoinScanner.h"
#include "alinous.db.table/IBtreeTableIndex.h"
#include "alinous.db.trx.cache/TrxRecordCacheIndex.h"
#include "alinous.remote.region.client.scan/AbstractRemoteScanner.h"
#include "alinous.remote.region.client.scan/IRemoteJoinScanner.h"
#include "alinous.remote.region.client/RemoteReverseIndexScanner.h"
#include "alinous.remote.region.client.scan/RemoteCrossJoinScanner.h"
#include "alinous.remote.region.client.scan/RemoteIndexEqScanner.h"
#include "alinous.db.table.scan/IndexListScannerParam.h"
#include "alinous.remote.region.client.scan/RemoteIndexListScanner.h"
#include "alinous.db.table.scan/IndexRangeScannerParam.h"
#include "alinous.remote.region.client.scan/RemoteIndexRangeScanner.h"
#include "alinous.remote.region.client.scan/RemoteRightindexJoinScanner.h"
#include "alinous.remote.region.client.scan/RemoteTableFullScanner.h"
#include "alinous.remote.region.client.scan/RemoteTableIndexScanner.h"
#include "alinous.db.trx.scan/IFilterScanner.h"
#include "alinous.db.table.scan/TableFullScanner.h"
#include "alinous.db.table.scan/TableIndexScanner.h"
#include "alinous.db.table.scan/IndexEqScanner.h"
#include "alinous.db.table.scan/IndexRangeScanner.h"
#include "alinous.db.table.scan/IndexListScanner.h"
#include "alinous.db.table.scan/ScannerFactory.h"

namespace alinous {namespace db {namespace table {namespace scan {





bool ScannerFactory::__init_done = __init_static_variables();
bool ScannerFactory::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"ScannerFactory", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 ScannerFactory::ScannerFactory(ThreadContext* ctx) throw()  : IObject(ctx)
{
}
void ScannerFactory::__construct_impl(ThreadContext* ctx) throw() 
{
}
 ScannerFactory::~ScannerFactory() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void ScannerFactory::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
}
ITableTargetScanner* ScannerFactory::getTableFullScanner(ScanTableIdentifier* tableId, DbTransaction* trx, IDatabaseTable* tableStore, int lockMode, ThreadContext* ctx)
{
	if(trx->isRemote(ctx))
	{
		return (new(ctx) RemoteTableFullScanner(ctx))->init(tableId, trx, tableStore, lockMode, ctx);
	}
	return (new(ctx) TableFullScanner(ctx))->init(tableId, trx, tableStore, lockMode, ctx);
}
ITableTargetScanner* ScannerFactory::getTableIndexScanner(ScanTableIdentifier* tableId, DbTransaction* trx, IScannableIndex* index, IDatabaseTable* tableStore, int lockMode, ThreadContext* ctx)
{
	if(trx->isRemote(ctx))
	{
		return (new(ctx) RemoteTableIndexScanner(ctx))->init(tableId, trx, index, tableStore, lockMode, ctx);
	}
	return (new(ctx) TableIndexScanner(ctx))->init(tableId, trx, index, tableStore, lockMode, ctx);
}
ITableTargetScanner* ScannerFactory::getIndexEqScanner(ScanTableIdentifier* tableId, DbTransaction* trx, IScannableIndex* index, IDatabaseTable* tableStore, TrxRecordCacheIndex* insertCacheindex, TrxRecordCacheIndex* updateCacheindex, int lockMode, ScanResultIndexKey* eqKey, int effectiveKeyLength, InnerNecessaryCondition* necessaryCondition, ScriptMachine* machine, ThreadContext* ctx)
{
	if(trx->isRemote(ctx))
	{
		return (new(ctx) RemoteIndexEqScanner(ctx))->init(tableId, trx, index, tableStore, insertCacheindex, updateCacheindex, lockMode, eqKey, effectiveKeyLength, necessaryCondition, machine, ctx);
	}
	return (new(ctx) IndexEqScanner(ctx))->init(tableId, trx, index, tableStore, insertCacheindex, updateCacheindex, lockMode, eqKey, effectiveKeyLength, necessaryCondition, machine, ctx);
}
ITableTargetScanner* ScannerFactory::getIndexRangeScanner(ScanTableIdentifier* tableId, DbTransaction* trx, IScannableIndex* index, IDatabaseTable* tableStore, TrxRecordCacheIndex* insertCacheindex, TrxRecordCacheIndex* updateCacheindex, int lockMode, IndexRangeScannerParam* param, int effectiveKeyLength, InnerNecessaryCondition* necessaryCondition, ScriptMachine* machine, ThreadContext* ctx)
{
	if(trx->isRemote(ctx))
	{
		return (new(ctx) RemoteIndexRangeScanner(ctx))->init(tableId, trx, index, tableStore, insertCacheindex, updateCacheindex, lockMode, param, effectiveKeyLength, necessaryCondition, machine, ctx);
	}
	return (new(ctx) IndexRangeScanner(ctx))->init(tableId, trx, index, tableStore, insertCacheindex, updateCacheindex, lockMode, param, effectiveKeyLength, necessaryCondition, machine, ctx);
}
ITableTargetScanner* ScannerFactory::getIndexListScanner(ScanTableIdentifier* tableId, DbTransaction* trx, IScannableIndex* index, IDatabaseTable* tableStore, TrxRecordCacheIndex* insertCacheindex, TrxRecordCacheIndex* updateCacheindex, int lockMode, IndexListScannerParam* param, int effectiveKeyLength, InnerNecessaryCondition* necessaryCondition, ScriptMachine* machine, ThreadContext* ctx)
{
	if(trx->isRemote(ctx))
	{
		return (new(ctx) RemoteIndexListScanner(ctx))->init(tableId, trx, index, tableStore, insertCacheindex, updateCacheindex, lockMode, param, effectiveKeyLength, necessaryCondition, machine, ctx);
	}
	return (new(ctx) IndexListScanner(ctx))->init(tableId, trx, index, tableStore, insertCacheindex, updateCacheindex, lockMode, param, effectiveKeyLength, necessaryCondition, machine, ctx);
}
ITableTargetScanner* ScannerFactory::getCrossJoinScanner(DbTransaction* trx, ITableTargetScanner* left, ITableTargetScanner* right, ScanTableMetadata* leftMetadata, ScanTableMetadata* rightMetadata, ScriptMachine* machine, ThreadContext* ctx) throw() 
{
	if(trx->isRemote(ctx))
	{
		return (new(ctx) RemoteCrossJoinScanner(ctx))->init(trx, left, right, leftMetadata, rightMetadata, machine, ctx);
	}
	return (new(ctx) CrossJoinScanner(ctx))->init(trx, left, right, leftMetadata, rightMetadata, machine, ctx);
}
ITableTargetScanner* ScannerFactory::getRightindexJoinScanner(DbTransaction* trx, ITableTargetScanner* left, ITableTargetScanner* right, ScanTableMetadata* leftMetadata, ScanTableMetadata* rightMetadata, bool inner, JoinMatchExpression* match, SQLJoinCondition* condition, ScriptMachine* machine, ThreadContext* ctx) throw() 
{
	if(trx->isRemote(ctx))
	{
		return (new(ctx) RemoteRightindexJoinScanner(ctx))->init(trx, left, right, leftMetadata, rightMetadata, inner, match, condition, machine, ctx);
	}
	return (new(ctx) RightindexJoinScanner(ctx))->init(trx, left, right, leftMetadata, rightMetadata, inner, match, condition, machine, ctx);
}
ITableTargetScanner* ScannerFactory::getReverseIndexScanner(DbTransaction* trx, ITableTargetScanner* left, ITableTargetScanner* right, ScanTableMetadata* leftMetadata, ScanTableMetadata* rightMetadata, bool inner, JoinMatchExpression* match, SQLJoinCondition* condition, ScriptMachine* machine, ThreadContext* ctx) throw() 
{
	if(trx->isRemote(ctx))
	{
		return (new(ctx) RemoteReverseIndexScanner(ctx))->init(trx, left, right, leftMetadata, rightMetadata, inner, match, condition, machine, ctx);
	}
	return (new(ctx) ReverseIndexScanner(ctx))->init(trx, left, right, leftMetadata, rightMetadata, inner, match, condition, machine, ctx);
}
void ScannerFactory::__cleanUp(ThreadContext* ctx){
}
}}}}

