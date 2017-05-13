#include "include/global.h"


#include "alinous.buffer.storage/FileStorageEntryBuilder.h"
#include "alinous.buffer.storage/FileStorageEntryFetcher.h"
#include "alinous.compile/IAlinousElementVisitor.h"
#include "alinous.compile/IAlinousVisitorContainer.h"
#include "alinous.compile/Token.h"
#include "alinous.system/AlinousException.h"
#include "alinous.runtime/ExecutionException.h"
#include "alinous.runtime.dom/VariableException.h"
#include "alinous.remote.socket/NetworkBinaryBuffer.h"
#include "alinous.remote.socket/ICommandData.h"
#include "alinous.compile/ExpressionSourceId.h"
#include "alinous.runtime.dom/IAlinousVariable.h"
#include "alinous.runtime.variant/VariantValue.h"
#include "alinous.compile/AbstractSrcElement.h"
#include "alinous.compile/IAlinousElement.h"
#include "alinous.compile.declare/IDeclare.h"
#include "alinous.compile.analyse/SourceValidator.h"
#include "alinous.compile/IStatement.h"
#include "alinous.compile.expression/IExpression.h"
#include "alinous.compile.expression/AbstractExpression.h"
#include "alinous.compile.expression.blexp/BooleanSubExpression.h"
#include "alinous.compile.expression.blexp/AbstractBooleanCollectionExpression.h"
#include "alinous.compile.expression.blexp/AndExpression.h"
#include "alinous.compile.expression.blexp/ConditionalAndExpression.h"
#include "alinous.compile.expression.blexp/ConditionalOrExpression.h"
#include "alinous.compile.expression.blexp/AbstractBooleanExpression.h"
#include "alinous.compile.expression.blexp/EqualityExpression.h"
#include "alinous.compile.expression.blexp/ExclusiveOrExpression.h"
#include "alinous.compile.expression.blexp/InclusiveOrExpression.h"
#include "alinous.compile.expression.blexp/InstanceOfExpression.h"
#include "alinous.compile.expression.blexp/NotExpression.h"
#include "alinous.compile.expression.blexp/RelationalExpression.h"
#include "alinous.compile.expression/FunctionArguments.h"
#include "alinous.compile.declare/ClassMemberModifiers.h"
#include "alinous.compile.declare/IClassMember.h"
#include "alinous.compile.declare/AbstractClassMember.h"
#include "alinous.compile.declare/ClassMemberVariable.h"
#include "alinous.compile.expression/IDomSegment.h"
#include "alinous.compile.expression/DomIndexSegment.h"
#include "alinous.compile.expression/Literal.h"
#include "alinous.compile.stmt/AbstractAlinousStatement.h"
#include "alinous.compile.stmt/TypedVariableDeclare.h"
#include "alinous.compile.expression.expstream/ExpStreamSegment.h"
#include "alinous.compile.expression.expstream/ExpressionStream.h"
#include "alinous.compile.expression.expstream/ExpStreamCast.h"
#include "alinous.compile.expression.expstream/ExpStreamParenthesis.h"
#include "alinous.compile.sql/TableAndSchema.h"
#include "alinous.compile.sql.analyze/ScanTableIdentifier.h"
#include "alinous.compile.sql.analyze/ScanTableColumnIdentifier.h"
#include "alinous.btree/IBTreeValue.h"
#include "alinous.compile.sql.ddl/CheckDefinition.h"
#include "alinous.compile.sql.ddl/ColumnTypeDescriptor.h"
#include "alinous.db.table/TableColumnMetadata.h"
#include "alinous.compile.sql.analyze/ScanTableMetadata.h"
#include "alinous.compile.sql/ISqlStatement.h"
#include "alinous.compile.sql.expression/ISQLExpression.h"
#include "alinous.compile.sql.parts/ISQLExpressionPart.h"
#include "alinous.compile.sql.parts/AbstractExpressionPart.h"
#include "alinous.compile.sql.parts/SQLExpressionList.h"
#include "alinous.compile.sql.select/SQLGroupBy.h"
#include "alinous.compile.sql.select/SQLLimitOffset.h"
#include "alinous.compile.sql.select/SQLWhere.h"
#include "java.lang/Comparable.h"
#include "alinous.btree/IBTreeKey.h"
#include "alinous.db.trx.scan/ScanResultIndexKey.h"
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
#include "alinous.compile.sql/InsertStatement.h"
#include "alinous.compile.sql.select/SQLFrom.h"
#include "alinous.compile.sql/SelectStatement.h"
#include "alinous.compile.sql/UpdateSet.h"
#include "alinous.compile.sql/UpdateStatement.h"
#include "alinous.db.trx/DbTransaction.h"
#include "alinous.db.trx.scan/ScanResultRecord.h"
#include "alinous.compile.sql.analyze/SQLAnalyseContext.h"
#include "alinous.compile.sql.expression/AbstractSQLExpression.h"
#include "alinous.compile.sql.expression/SQLColumnIdentifier.h"
#include "alinous.compile.sql.expression/SQLExpressionStream.h"
#include "alinous.compile.sql/InsertValues.h"
#include "alinous.compile.sql.expression/SQLSubExpression.h"
#include "alinous.compile.sql.expression/AbstractSQLCollectionExpression.h"
#include "alinous.compile.sql.expression/SQLAdditiveExpression.h"
#include "alinous.compile.sql.expression/SQLLiteral.h"
#include "alinous.compile.sql.expression/SQLMultiplicativeExpression.h"
#include "alinous.compile.sql.expression/SQLParenthesisExpression.h"
#include "alinous.compile.sql.expression/SQLSubqueryExpression.h"
#include "alinous.compile.sql.expression.blexp/SQLBoolSubExpression.h"
#include "alinous.compile.sql.expression.blexp/AbstractSQLBooleanCollectionExpression.h"
#include "alinous.compile.sql.expression.blexp/SQLAndExpression.h"
#include "alinous.compile.sql.expression.blexp/SQLBooleanLiteral.h"
#include "alinous.compile.sql.expression.blexp/SQLEqualityExpression.h"
#include "alinous.compile.sql.expression.blexp/SQLInExpression.h"
#include "alinous.compile.sql.expression.blexp/SQLIsNullExpression.h"
#include "alinous.compile.sql.expression.blexp/SQLLikeExpression.h"
#include "alinous.compile.sql.expression.blexp/SQLNotExpression.h"
#include "alinous.compile.sql.expression.blexp/SQLOrExpression.h"
#include "alinous.compile.sql.expression.blexp/SQLRelationalExpression.h"
#include "alinous.compile.sql.parts/SQLExpressionListAll.h"
#include "alinous.compile.expression/SubExpression.h"
#include "alinous.compile.expression/AbstractCollectionExpression.h"
#include "alinous.compile.expression/AdditiveExpression.h"
#include "alinous.compile.expression/MultiplicativeExpression.h"
#include "alinous.compile.expression/ShiftExpression.h"
#include "alinous.compile.declare/ClassExtends.h"
#include "alinous.compile.expression/AllocationExpression.h"
#include "alinous.compile.expression/BitReverseExpression.h"
#include "alinous.compile.expression/CastExpression.h"
#include "alinous.compile.expression/ConditionalExpression.h"
#include "alinous.compile.expression/BooleanLiteral.h"
#include "alinous.compile.expression/NullLiteral.h"
#include "alinous.compile.expression/ParenthesisExpression.h"
#include "alinous.compile.expression/PreDecrementExpression.h"
#include "alinous.compile.expression/PreIncrementExpression.h"
#include "alinous.compile.expression/UnaryExpression.h"
#include "alinous.compile.expression/IExpressionFactory.h"
#include "alinous.compile.expression/DomVariableDescriptor.h"
#include "alinous.compile.declare.function/FunctionArgumentDefine.h"
#include "alinous.compile.declare.function/FunctionArgumentsListDefine.h"
#include "alinous.compile.declare.function/ReturnValueDefinition.h"
#include "alinous.compile.stmt/StatementList.h"
#include "alinous.compile.stmt/StatementBlock.h"
#include "alinous.compile.expression.expstream/FunctionCallExpression.h"
#include "alinous.compile.declare.function/ThrowsDefine.h"
#include "alinous.compile.declare.function/AlinousFunction.h"
#include "alinous.runtime/AlinousModulePackage.h"
#include "alinous.runtime/AlinousModule.h"
#include "alinous.compile/IncludePreprocessor.h"
#include "alinous.compile/AlinousSrc.h"
#include "alinous.runtime.engine/ScriptMachine.h"
#include "alinous.compile.expression/DomNameSegment.h"
#include "alinous.compile.declare/AlinousName.h"
#include "alinous.compile.analyse/SrcAnalyseContext.h"
#include "alinous.compile.declare/VirtualTable.h"
#include "alinous.compile.declare/ClassMethodFunction.h"
#include "alinous.compile.declare/ClassImplements.h"
#include "alinous.compile.declare/AlinousClass.h"
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
#include "alinous.compile.sql.analyze/JoinStrategyPart.h"
#include "alinous.compile.sql.analyze/JoinStrategy.h"
#include "alinous.db.trx.scan/ScannedResultIndexScanner.h"
#include "alinous.compile.sql.select.join/AbstractSQLJoin.h"
#include "alinous.compile.sql.select.join/InnerJoin.h"
#include "alinous.compile.sql.select.join/CrossJoin.h"
#include "alinous.compile.sql.select.join/DomVariableJoinTarget.h"
#include "alinous.compile.sql.select.join/JoinSubQueryTarget.h"
#include "alinous.compile.sql.select.join/LeftJoin.h"
#include "alinous.compile.sql.select.join/NaturalJoin.h"
#include "alinous.compile.sql.select.join/RightJoin.h"
#include "alinous.compile.sql.select.join/TableList.h"
#include "alinous.compile.sql.select.join/WrappedJoinTarget.h"
#include "alinous.compile.stmt/AssignmentStatement.h"
#include "alinous.compile.stmt/BreakStatement.h"
#include "alinous.compile.stmt/CaseStatement.h"
#include "alinous.compile.stmt/CatchBlock.h"
#include "alinous.compile.stmt/ContinueStatement.h"
#include "alinous.compile.stmt/DefaultStatement.h"
#include "alinous.compile.stmt/LabeledStatement.h"
#include "alinous.compile.stmt/DoWhileStatement.h"
#include "alinous.compile.stmt/ExpressionStatement.h"
#include "alinous.compile.stmt/FinallyBlock.h"
#include "alinous.compile.stmt/ForUpdatePart.h"
#include "alinous.compile.stmt/ForStatement.h"
#include "alinous.compile.stmt/IfStatement.h"
#include "alinous.compile.stmt/ReturnStatement.h"
#include "alinous.compile.stmt/SwitchCasePart.h"
#include "alinous.compile.stmt/SwitchStatement.h"
#include "alinous.compile.stmt/ThrowStatement.h"
#include "alinous.compile.stmt/TryBlock.h"
#include "alinous.compile.stmt/WhileStatement.h"
#include "alinous.compile/AlinousElementNetworkFactory.h"
#include "alinous.db.table.scan/IndexListScannerParam.h"
#include "alinous.db.table.scan/IndexRangeScannerParam.h"
#include "alinous.remote.region.client.command.dml/ClientScanCommandData.h"

namespace alinous {namespace remote {namespace region {namespace client {namespace command {namespace dml {





bool ClientScanCommandData::__init_done = __init_static_variables();
bool ClientScanCommandData::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"ClientScanCommandData", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 ClientScanCommandData::ClientScanCommandData(ThreadContext* ctx) throw()  : IObject(ctx), ICommandData(ctx), vctx(nullptr), table(nullptr), lockMode(0), isolationLevel(0), primaryIndex(0), fullscan(0), indexColmns(nullptr), exp(nullptr), listParam(nullptr), eqKey(nullptr), rangeParam(nullptr)
{
}
void ClientScanCommandData::__construct_impl(ThreadContext* ctx) throw() 
{
}
 ClientScanCommandData::~ClientScanCommandData() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void ClientScanCommandData::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"ClientScanCommandData", L"~ClientScanCommandData");
	__e_obj1.add(this->vctx, this);
	vctx = nullptr;
	__e_obj1.add(this->table, this);
	table = nullptr;
	__e_obj1.add(this->indexColmns, this);
	indexColmns = nullptr;
	__e_obj1.add(this->exp, this);
	exp = nullptr;
	__e_obj1.add(this->listParam, this);
	listParam = nullptr;
	__e_obj1.add(this->eqKey, this);
	eqKey = nullptr;
	__e_obj1.add(this->rangeParam, this);
	rangeParam = nullptr;
	if(!prepare){
		return;
	}
}
void ClientScanCommandData::readData(NetworkBinaryBuffer* buff, ThreadContext* ctx)
{
	bool isnull = buff->getBoolean(ctx);
	if(!isnull)
	{
		__GC_MV(this, &(this->vctx), DbVersionContext::fromNetwork(buff, ctx), DbVersionContext);
	}
	isnull = buff->getBoolean(ctx);
	if(!isnull)
	{
		__GC_MV(this, &(this->table), TableAndSchema::fromNetwork(buff, ctx), TableAndSchema);
	}
	this->lockMode = buff->getInt(ctx);
	this->isolationLevel = buff->getInt(ctx);
	this->fullscan = buff->getBoolean(ctx);
	this->primaryIndex = buff->getBoolean(ctx);
	isnull = buff->getBoolean(ctx);
	if(!isnull)
	{
		GCUtils<ArrayList<TableColumnMetadata> >::mv(this, &(this->indexColmns), (new(ctx) ArrayList<TableColumnMetadata>(ctx)), ctx);
		int maxLoop = buff->getInt(ctx);
		for(int i = 0; i != maxLoop; ++i)
		{
			TableColumnMetadata* col = TableColumnMetadata::fromNetwork(buff, ctx);
			this->indexColmns->add(col, ctx);
		}
	}
	isnull = buff->getBoolean(ctx);
	if(!isnull)
	{
		IAlinousElement* el = AlinousElementNetworkFactory::formNetworkData(buff, ctx);
		if(el == nullptr || !((dynamic_cast<ISQLExpression*>(el) != 0)))
		{
			throw (new(ctx) VariableException(ConstStr::getCNST_STR_1126(), ctx));
		}
		__GC_MV(this, &(this->exp), static_cast<ISQLExpression*>(el), ISQLExpression);
	}
	isnull = buff->getBoolean(ctx);
	if(!isnull)
	{
		__GC_MV(this, &(this->listParam), IndexListScannerParam::fromNetwork(buff, ctx), IndexListScannerParam);
	}
	isnull = buff->getBoolean(ctx);
	if(!isnull)
	{
		__GC_MV(this, &(this->eqKey), ScanResultIndexKey::fromNetwork(buff, ctx), ScanResultIndexKey);
	}
	isnull = buff->getBoolean(ctx);
	if(!isnull)
	{
		__GC_MV(this, &(this->rangeParam), IndexRangeScannerParam::fromNetwork(buff, ctx), IndexRangeScannerParam);
	}
}
void ClientScanCommandData::writeData(NetworkBinaryBuffer* buff, ThreadContext* ctx)
{
	bool isnull = (this->vctx == nullptr);
	buff->putBoolean(isnull, ctx);
	if(!isnull)
	{
		this->vctx->writeData(buff, ctx);
	}
	isnull = (this->table == nullptr);
	buff->putBoolean(isnull, ctx);
	if(!isnull)
	{
		this->table->writeData(buff, ctx);
	}
	buff->putInt(this->lockMode, ctx);
	buff->putInt(this->isolationLevel, ctx);
	buff->putBoolean(this->fullscan, ctx);
	buff->putBoolean(this->primaryIndex, ctx);
	isnull = (this->indexColmns == nullptr);
	buff->putBoolean(isnull, ctx);
	if(!isnull)
	{
		int maxLoop = this->indexColmns->size(ctx);
		buff->putInt(maxLoop, ctx);
		for(int i = 0; i != maxLoop; ++i)
		{
			TableColumnMetadata* col = this->indexColmns->get(i, ctx);
			col->writeData(buff, ctx);
		}
	}
	isnull = (this->exp == nullptr);
	buff->putBoolean(isnull, ctx);
	if(!isnull)
	{
		this->exp->writeData(buff, ctx);
	}
	isnull = (this->listParam == nullptr);
	buff->putBoolean(isnull, ctx);
	if(!isnull)
	{
		this->listParam->writeData(buff, ctx);
	}
	isnull = (this->eqKey == nullptr);
	buff->putBoolean(isnull, ctx);
	if(!isnull)
	{
		this->eqKey->writeData(buff, ctx);
	}
	isnull = (this->rangeParam == nullptr);
	buff->putBoolean(isnull, ctx);
	if(!isnull)
	{
		this->rangeParam->writeData(buff, ctx);
	}
}
DbVersionContext* ClientScanCommandData::getVctx(ThreadContext* ctx) throw() 
{
	return vctx;
}
void ClientScanCommandData::setVctx(DbVersionContext* vctx, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->vctx), vctx, DbVersionContext);
}
TableAndSchema* ClientScanCommandData::getTable(ThreadContext* ctx) throw() 
{
	return table;
}
void ClientScanCommandData::setTable(TableAndSchema* table, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->table), table, TableAndSchema);
}
int ClientScanCommandData::getLockMode(ThreadContext* ctx) throw() 
{
	return lockMode;
}
void ClientScanCommandData::setLockMode(int lockMode, ThreadContext* ctx) throw() 
{
	this->lockMode = lockMode;
}
bool ClientScanCommandData::isPrimaryIndex(ThreadContext* ctx) throw() 
{
	return primaryIndex;
}
void ClientScanCommandData::setPrimaryIndex(bool primaryIndex, ThreadContext* ctx) throw() 
{
	this->primaryIndex = primaryIndex;
}
bool ClientScanCommandData::isFullscan(ThreadContext* ctx) throw() 
{
	return fullscan;
}
void ClientScanCommandData::setFullscan(bool fullscan, ThreadContext* ctx) throw() 
{
	this->fullscan = fullscan;
}
ArrayList<TableColumnMetadata>* ClientScanCommandData::getIndexColmns(ThreadContext* ctx) throw() 
{
	return indexColmns;
}
void ClientScanCommandData::setIndexColmns(ArrayList<TableColumnMetadata>* indexColmns, ThreadContext* ctx) throw() 
{
	GCUtils<ArrayList<TableColumnMetadata> >::mv(this, &(this->indexColmns), indexColmns, ctx);
}
ISQLExpression* ClientScanCommandData::getExp(ThreadContext* ctx) throw() 
{
	return exp;
}
void ClientScanCommandData::setExp(ISQLExpression* exp, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->exp), exp, ISQLExpression);
}
IndexListScannerParam* ClientScanCommandData::getListParam(ThreadContext* ctx) throw() 
{
	return listParam;
}
void ClientScanCommandData::setListParam(IndexListScannerParam* listParam, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->listParam), listParam, IndexListScannerParam);
}
ScanResultIndexKey* ClientScanCommandData::getEqKey(ThreadContext* ctx) throw() 
{
	return eqKey;
}
void ClientScanCommandData::setEqKey(ScanResultIndexKey* eqKey, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->eqKey), eqKey, ScanResultIndexKey);
}
IndexRangeScannerParam* ClientScanCommandData::getRangeParam(ThreadContext* ctx) throw() 
{
	return rangeParam;
}
void ClientScanCommandData::setRangeParam(IndexRangeScannerParam* rangeParam, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->rangeParam), rangeParam, IndexRangeScannerParam);
}
int ClientScanCommandData::getIsolationLevel(ThreadContext* ctx) throw() 
{
	return isolationLevel;
}
void ClientScanCommandData::setIsolationLevel(int isolationLevel, ThreadContext* ctx) throw() 
{
	this->isolationLevel = isolationLevel;
}
ClientScanCommandData* ClientScanCommandData::fromNetwork(NetworkBinaryBuffer* buff, ThreadContext* ctx)
{
	ClientScanCommandData* data = (new(ctx) ClientScanCommandData(ctx));
	data->readData(buff, ctx);
	return data;
}
void ClientScanCommandData::__cleanUp(ThreadContext* ctx){
}
}}}}}}

