#include "include/global.h"


#include "alinous.buffer.storage/FileStorageEntryBuilder.h"
#include "alinous.buffer.storage/FileStorageEntryFetcher.h"
#include "alinous.compile/IAlinousElementVisitor.h"
#include "alinous.compile.analyse/SourceValidator.h"
#include "alinous.compile/IAlinousVisitorContainer.h"
#include "alinous.compile/AbstractSrcElement.h"
#include "alinous.remote.socket/ICommandData.h"
#include "alinous.compile/IAlinousElement.h"
#include "alinous.compile/IStatement.h"
#include "alinous.compile.declare/IDeclare.h"
#include "alinous.db.table/DatabaseException.h"
#include "alinous.system/AlinousException.h"
#include "alinous.runtime/ExecutionException.h"
#include "alinous.runtime.dom/VariableException.h"
#include "alinous.remote.socket/NetworkBinaryBuffer.h"
#include "alinous.runtime.dom/IAlinousVariable.h"
#include "alinous.runtime.variant/VariantValue.h"
#include "alinous.compile.stmt/AbstractAlinousStatement.h"
#include "alinous.compile.stmt/StatementList.h"
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
#include "alinous.compile/Token.h"
#include "alinous.compile.expression/IDomSegment.h"
#include "alinous.compile.expression/DomNameSegment.h"
#include "alinous.compile.expression/DomIndexSegment.h"
#include "alinous.compile.expression/DomVariableDescriptor.h"
#include "alinous.compile.declare/ClassMemberModifiers.h"
#include "alinous.compile.declare/IClassMember.h"
#include "alinous.compile.declare/AbstractClassMember.h"
#include "alinous.compile.declare/ClassMemberVariable.h"
#include "alinous.compile.declare.function/FunctionArgumentDefine.h"
#include "alinous.compile.declare.function/FunctionArgumentsListDefine.h"
#include "alinous.compile.declare/VirtualTable.h"
#include "alinous.compile.declare/ClassMethodFunction.h"
#include "alinous.compile.stmt/TypedVariableDeclare.h"
#include "alinous.compile.expression.expstream/ExpStreamSegment.h"
#include "alinous.compile.expression.expstream/ExpressionStream.h"
#include "alinous.compile.expression.expstream/ExpStreamCast.h"
#include "alinous.compile.expression.expstream/ExpStreamParenthesis.h"
#include "alinous.compile.sql.analyze/ScanTableIdentifier.h"
#include "alinous.compile.sql.analyze/ScanTableColumnIdentifier.h"
#include "alinous.btree/IBTreeValue.h"
#include "alinous.compile.sql.analyze/ScanTableColumnMetadata.h"
#include "alinous.compile.sql.analyze/ScanTableIndexMetadata.h"
#include "alinous.compile.sql.analyze/ScanTableMetadata.h"
#include "alinous.compile.sql/ISqlStatement.h"
#include "alinous.compile.sql.expression/ISQLExpression.h"
#include "alinous.compile.sql.parts/ISQLExpressionPart.h"
#include "alinous.compile.sql.parts/AbstractExpressionPart.h"
#include "alinous.compile.sql.parts/SQLExpressionList.h"
#include "alinous.compile.sql.select/SQLGroupBy.h"
#include "alinous.compile.sql.select/SQLLimitOffset.h"
#include "alinous.compile.sql.select/SQLWhere.h"
#include "alinous.system/ISystemLog.h"
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
#include "alinous.compile.sql/InsertStatement.h"
#include "alinous.compile.sql.select/SQLFrom.h"
#include "alinous.compile.sql/SelectStatement.h"
#include "alinous.compile.sql/UpdateSet.h"
#include "alinous.compile.sql/UpdateStatement.h"
#include "alinous.db.trx.scan/ScanResult.h"
#include "alinous.db.trx/DbTransaction.h"
#include "alinous.db.table/IScannableIndex.h"
#include "alinous.db.table/IDatabaseTable.h"
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
#include "alinous.compile.expression/Literal.h"
#include "alinous.compile.expression/BooleanLiteral.h"
#include "alinous.compile.expression/NullLiteral.h"
#include "alinous.compile.expression/ParenthesisExpression.h"
#include "alinous.compile.expression/PreDecrementExpression.h"
#include "alinous.compile.expression/PreIncrementExpression.h"
#include "alinous.compile.expression/UnaryExpression.h"
#include "alinous.compile.expression/IExpressionFactory.h"
#include "alinous.runtime/AlinousModulePackage.h"
#include "alinous.runtime/AlinousModule.h"
#include "alinous.compile/IncludePreprocessor.h"
#include "alinous.compile/AlinousSrc.h"
#include "alinous.compile.stmt/StatementBlock.h"
#include "alinous.runtime.engine/ScriptMachine.h"
#include "alinous.compile/ExpressionSourceId.h"
#include "alinous.compile.declare.function/ReturnValueDefinition.h"
#include "alinous.compile.expression.expstream/FunctionCallExpression.h"
#include "alinous.compile.declare.function/ThrowsDefine.h"
#include "alinous.compile.declare.function/AlinousFunction.h"
#include "alinous.compile.analyse/SrcAnalyseContext.h"
#include "alinous.compile.declare/AlinousName.h"
#include "alinous.compile.declare/ClassImplements.h"
#include "alinous.compile.sql/BeginStatement.h"
#include "alinous.compile.sql/CommitStatement.h"
#include "alinous.compile.sql.ddl/CheckDefinition.h"
#include "alinous.compile.sql.ddl/ColumnTypeDescriptor.h"
#include "alinous.compile.sql.ddl/DdlColumnDescriptor.h"
#include "alinous.compile.sql.ddl/PrimaryKeys.h"
#include "alinous.compile.sql.ddl/ShardKeys.h"
#include "alinous.compile.sql.ddl/Unique.h"
#include "alinous.compile.sql/CreateTableStatement.h"
#include "alinous.compile.sql/DeleteStatement.h"
#include "alinous.compile.sql/DropIndexStatement.h"
#include "alinous.compile.sql/DropTableStatement.h"
#include "alinous.compile.sql/RollbackStatement.h"
#include "alinous.compile.sql.analyze/JoinMatchExpression.h"
#include "alinous.compile.sql.analyze/JoinStrategyPart.h"
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
#include "alinous.compile.declare/AlinousClass.h"
#include "alinous.compile.sql.analyze/JoinStrategy.h"
#include "alinous.compile.sql.analyze/InnerNecessaryCondition.h"
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
#include "alinous.remote.region.client.scan/RemoteTableFullScanner.h"
#include "alinous.remote.region.client.scan/RemoteTableIndexScanner.h"
#include "alinous.db.trx.scan/IFilterScanner.h"
#include "alinous.db.table.scan/TableFullScanner.h"
#include "alinous.db.table.scan/TableIndexScanner.h"
#include "alinous.db.table.scan/IndexEqScanner.h"
#include "alinous.db.table.scan/IndexRangeScanner.h"
#include "alinous.db.table.scan/IndexListScanner.h"
#include "alinous.db.table.scan/ScannerFactory.h"
#include "alinous.db.trx.scan/ScannedResultIndexScanner.h"

namespace alinous {namespace compile {namespace sql {namespace select {namespace join {





bool AbstractSQLJoin::__init_done = __init_static_variables();
bool AbstractSQLJoin::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"AbstractSQLJoin", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 AbstractSQLJoin::AbstractSQLJoin(ThreadContext* ctx) throw()  : IObject(ctx), IJoin(ctx), left(nullptr), right(nullptr), condition(nullptr), joinStrategy(nullptr), bestParts(nullptr), crossjoin(false), scanMetadata(nullptr)
{
}
void AbstractSQLJoin::__construct_impl(ThreadContext* ctx) throw() 
{
}
 AbstractSQLJoin::~AbstractSQLJoin() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void AbstractSQLJoin::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"AbstractSQLJoin", L"~AbstractSQLJoin");
	__e_obj1.add(this->left, this);
	left = nullptr;
	__e_obj1.add(this->right, this);
	right = nullptr;
	__e_obj1.add(this->condition, this);
	condition = nullptr;
	__e_obj1.add(this->joinStrategy, this);
	joinStrategy = nullptr;
	__e_obj1.add(this->bestParts, this);
	bestParts = nullptr;
	__e_obj1.add(this->scanMetadata, this);
	scanMetadata = nullptr;
	if(!prepare){
		return;
	}
	IJoin::__releaseRegerences(true, ctx);
}
bool AbstractSQLJoin::visit(IAlinousElementVisitor* visitor, AbstractSrcElement* parent, ThreadContext* ctx) throw() 
{
	if(!visitor->visit(this, parent, ctx))
	{
		return false;
	}
	if(this->left != nullptr && !this->left->visit(visitor, this, ctx))
	{
		return false;
	}
	if(this->right != nullptr && !this->right->visit(visitor, this, ctx))
	{
		return false;
	}
	if(this->condition != nullptr && !this->condition->visit(visitor, this, ctx))
	{
		return false;
	}
	return true;
}
bool AbstractSQLJoin::analyse(SrcAnalyseContext* context, bool leftValue, ThreadContext* ctx) throw() 
{
	if(this->left != nullptr)
	{
		this->left->analyse(context, leftValue, ctx);
	}
	if(this->right != nullptr)
	{
		this->right->analyse(context, leftValue, ctx);
	}
	if(this->condition != nullptr)
	{
		this->condition->analyse(context, leftValue, ctx);
	}
	return true;
}
void AbstractSQLJoin::optimizeScan(SQLAnalyseContext* context, SQLWhere* where, SQLGroupBy* groupby, SQLLimitOffset* limit, ArrayList<ScanTableColumnIdentifier>* joinRequest, bool debug, ThreadContext* ctx)
{
	__GC_MV(this, &(this->joinStrategy), (new(ctx) JoinStrategy(false, ctx)), JoinStrategy);
	ISQLExpression* joinExp = nullptr;
	if(this->condition != nullptr)
	{
		joinExp = this->condition->getCondition(ctx);
	}
	this->joinStrategy->setJoinCondition(joinExp, ctx);
	if(where != nullptr)
	{
		this->joinStrategy->setWhereCondition(where->getCondition(ctx), ctx);
	}
	ScanTableMetadata* leftMetadata = this->left->getScanTableMetadata(ctx);
	ScanTableMetadata* rightMetadata = this->right->getScanTableMetadata(ctx);
	this->joinStrategy->analyze(context, leftMetadata, rightMetadata, ctx);
	GCUtils<ArrayList<JoinStrategyPart> >::mv(this, &(this->bestParts), this->joinStrategy->getBestParts(ctx), ctx);
	if(this->bestParts == nullptr)
	{
		this->crossjoin = true;
		this->left->optimizeScan(context, where, groupby, limit, nullptr, debug, ctx);
		this->right->optimizeScan(context, where, groupby, limit, nullptr, debug, ctx);
		return;
	}
	JoinStrategyPart* part = this->bestParts->get(0, ctx);
	JoinMatchExpression* exp = part->getBestExp(ctx);
	int indexStatus = exp->getIndexStatus(ctx);
	ScanTableIndexMetadata* leftIndex = nullptr;
	ScanTableIndexMetadata* rightIndex = nullptr;
	switch(indexStatus) {
	case JoinMatchExpression::NO_INDEX:
		{
			this->left->optimizeScan(context, where, groupby, limit, nullptr, debug, ctx);
			this->right->optimizeScan(context, where, groupby, limit, nullptr, debug, ctx);
			ArrayList<ScanTableColumnMetadata>* rightCols = (new(ctx) ArrayList<ScanTableColumnMetadata>(ctx));
			rightCols->add(exp->getRightMetadata(ctx)->getColumn(exp->getRightColumn(ctx), ctx), ctx);
			ScanTableIndexMetadata* rightIndexMeta = (new(ctx) ScanTableIndexMetadata(exp->getRightMetadata(ctx)->getFirstTableId(ctx), rightCols, ctx));
			exp->setRightIndex(rightIndexMeta, ctx);
			break ;
		}
	case JoinMatchExpression::LEFT_INDEX:
		leftIndex = exp->getLeftIndex(ctx);
		this->left->optimizeScan(context, where, groupby, limit, leftIndex->getColumnIds(ctx), debug, ctx);
		this->right->optimizeScan(context, where, groupby, limit, nullptr, debug, ctx);
		break ;
	case JoinMatchExpression::RIGHT_INDEX:
		this->left->optimizeScan(context, where, groupby, limit, nullptr, debug, ctx);
		rightIndex = exp->getRightIndex(ctx);
		this->right->optimizeScan(context, where, groupby, limit, rightIndex->getColumnIds(ctx), debug, ctx);
		break ;
	case JoinMatchExpression::BOTH_INDEX:
		leftIndex = exp->getLeftIndex(ctx);
		this->left->optimizeScan(context, where, groupby, limit, leftIndex->getColumnIds(ctx), debug, ctx);
		rightIndex = exp->getRightIndex(ctx);
		this->right->optimizeScan(context, where, groupby, limit, rightIndex->getColumnIds(ctx), debug, ctx);
		break ;
	}
}
IJoin* AbstractSQLJoin::getLeft(ThreadContext* ctx) throw() 
{
	return left;
}
void AbstractSQLJoin::setLeft(IJoin* left, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->left), left, IJoin);
}
IJoin* AbstractSQLJoin::getRight(ThreadContext* ctx) throw() 
{
	return right;
}
void AbstractSQLJoin::setRight(IJoin* right, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->right), right, IJoin);
}
SQLJoinCondition* AbstractSQLJoin::getCondition(ThreadContext* ctx) throw() 
{
	return condition;
}
void AbstractSQLJoin::setCondition(SQLJoinCondition* condition, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->condition), condition, SQLJoinCondition);
}
bool AbstractSQLJoin::analyseSQLTables(SQLAnalyseContext* context, bool leftValue, bool debug, ThreadContext* ctx)
{
	if(this->left != nullptr)
	{
		this->left->analyseSQLTables(context, leftValue, debug, ctx);
	}
	if(this->right != nullptr)
	{
		this->left->analyseSQLTables(context, leftValue, debug, ctx);
	}
	return true;
}
void AbstractSQLJoin::analyzeSQL(SQLAnalyseContext* context, bool debug, ThreadContext* ctx)
{
	if(this->left != nullptr)
	{
		this->left->analyseSQLTables(context, false, debug, ctx);
		this->left->analyzeSQL(context, debug, ctx);
	}
	if(this->right != nullptr)
	{
		this->right->analyseSQLTables(context, false, debug, ctx);
		this->right->analyzeSQL(context, debug, ctx);
	}
	if(this->condition != nullptr)
	{
		this->condition->analyseSQL(context, false, debug, ctx);
	}
	__GC_MV(this, &(this->scanMetadata), this->left->getScanTableMetadata(ctx)->copy(ctx), ScanTableMetadata);
	ScanTableMetadata* rightData = this->right->getScanTableMetadata(ctx);
	this->scanMetadata->join(rightData, ctx);
}
bool AbstractSQLJoin::hasTable(ScanTableIdentifier* table, ThreadContext* ctx) throw() 
{
	if(this->left != nullptr && this->left->hasTable(table, ctx))
	{
		return true;
	}
	if(this->right != nullptr && this->right->hasTable(table, ctx))
	{
		return true;
	}
	if(this->condition != nullptr && this->condition->hasTable(table, ctx))
	{
		return true;
	}
	return false;
}
ScanTableMetadata* AbstractSQLJoin::getScanTableMetadata(ThreadContext* ctx) throw() 
{
	return this->scanMetadata;
}
bool AbstractSQLJoin::isOptimizerCacheable(ThreadContext* ctx) throw() 
{
	return this->left->isOptimizerCacheable(ctx) && this->right->isOptimizerCacheable(ctx);
}
int AbstractSQLJoin::getLine(ThreadContext* ctx) throw() 
{
	return IJoin::getLine(ctx);
}
int AbstractSQLJoin::getStartPosition(ThreadContext* ctx) throw() 
{
	return IJoin::getStartPosition(ctx);
}
int AbstractSQLJoin::getEndLine(ThreadContext* ctx) throw() 
{
	return IJoin::getEndLine(ctx);
}
int AbstractSQLJoin::getEndPosition(ThreadContext* ctx) throw() 
{
	return IJoin::getEndPosition(ctx);
}
AbstractSrcElement* AbstractSQLJoin::getParent(ThreadContext* ctx) throw() 
{
	return IJoin::getParent(ctx);
}
void AbstractSQLJoin::setParent(AbstractSrcElement* parent, ThreadContext* ctx) throw() 
{
	IJoin::setParent(parent, ctx);
}
void AbstractSQLJoin::__readData(NetworkBinaryBuffer* buff, ThreadContext* ctx)
{
	bool isnull = buff->getBoolean(ctx);
	if(!isnull)
	{
		IAlinousElement* el = AlinousElementNetworkFactory::formNetworkData(buff, ctx);
		if(el == nullptr || !((dynamic_cast<IJoin*>(el) != 0)))
		{
			throw (new(ctx) VariableException(ConstStr::getCNST_STR_1166(), ctx));
		}
		__GC_MV(this, &(this->left), static_cast<IJoin*>(el), IJoin);
	}
	isnull = buff->getBoolean(ctx);
	if(!isnull)
	{
		IAlinousElement* el = AlinousElementNetworkFactory::formNetworkData(buff, ctx);
		if(el == nullptr || !((dynamic_cast<IJoin*>(el) != 0)))
		{
			throw (new(ctx) VariableException(ConstStr::getCNST_STR_1166(), ctx));
		}
		__GC_MV(this, &(this->right), static_cast<IJoin*>(el), IJoin);
	}
	isnull = buff->getBoolean(ctx);
	if(!isnull)
	{
		IAlinousElement* el = AlinousElementNetworkFactory::formNetworkData(buff, ctx);
		if(el == nullptr || !((dynamic_cast<SQLJoinCondition*>(el) != 0)))
		{
			throw (new(ctx) VariableException(ConstStr::getCNST_STR_1175(), ctx));
		}
		__GC_MV(this, &(this->condition), static_cast<SQLJoinCondition*>(el), SQLJoinCondition);
	}
}
void AbstractSQLJoin::__writeData(NetworkBinaryBuffer* buff, ThreadContext* ctx)
{
	bool isnull = (this->left == nullptr);
	buff->putBoolean(isnull, ctx);
	if(!isnull)
	{
		this->left->writeData(buff, ctx);
	}
	isnull = (this->right == nullptr);
	buff->putBoolean(isnull, ctx);
	if(!isnull)
	{
		this->right->writeData(buff, ctx);
	}
	isnull = (this->condition == nullptr);
	buff->putBoolean(isnull, ctx);
	if(!isnull)
	{
		this->condition->writeData(buff, ctx);
	}
}
ITableTargetScanner* AbstractSQLJoin::getCrossJoinsScanner(DbTransaction* trx, ScriptMachine* machine, ArrayList<ScanTableColumnIdentifier>* joinRequest, bool debug, ThreadContext* ctx)
{
	ITableTargetScanner* leftScanner = this->left->getScanner(trx, machine, nullptr, debug, ctx);
	ITableTargetScanner* rightScanner = this->right->getScanner(trx, machine, nullptr, debug, ctx);
	ITableTargetScanner* scanner = ScannerFactory::getCrossJoinScanner(trx, leftScanner, rightScanner, this->left->getScanTableMetadata(ctx), this->right->getScanTableMetadata(ctx), machine, ctx);
	if(joinRequest == nullptr)
	{
		return scanner;
	}
	return toResultScanner(trx, scanner, joinRequest, this->scanMetadata, debug, ctx);
}
ScannedResultIndexScanner* AbstractSQLJoin::toResultScanner(DbTransaction* trx, ITableTargetScanner* scanner, ArrayList<ScanTableColumnIdentifier>* joinRequest, ScanTableMetadata* tableMeta, bool debug, ThreadContext* ctx)
{
	ScanResult* result = trx->newResult(tableMeta, ctx);
	result->addIndex(joinRequest, ctx);
	{
		try
		{
			scanner->startScan(nullptr, ctx);
			while(scanner->hasNext(debug, ctx))
			{
				ScanResultRecord* record = scanner->next(debug, ctx);
				{
					try
					{
						result->addRecord(record, trx, ctx);
					}
					catch(Throwable* e)
					{
						throw (new(ctx) DatabaseException(ConstStr::getCNST_STR_1173(), ctx));
					}
				}
			}
			scanner->endScan(ctx);
		}
		catch(Throwable* e)
		{
			scanner->dispose(trx->getLogger(ctx), ctx);
			throw e;
		}
	}
	scanner->dispose(trx->getLogger(ctx), ctx);
	ScannedResultIndexScanner* resultScanner = (new(ctx) ScannedResultIndexScanner(result, joinRequest, ctx));
	return resultScanner;
}
ITableTargetScanner* AbstractSQLJoin::getJoinStrategyScanner(DbTransaction* trx, ScriptMachine* machine, JoinStrategyPart* part, bool inner, bool debug, ThreadContext* ctx)
{
	JoinMatchExpression* exp = part->getBestExp(ctx);
	int indexStatus = exp->getIndexStatus(ctx);
	ITableTargetScanner* leftScanner = nullptr;
	ITableTargetScanner* rightScanner = nullptr;
	ScanTableIndexMetadata* leftIndex = nullptr;
	ScanTableIndexMetadata* rightIndex = nullptr;
	ArrayList<ScanTableColumnIdentifier>* rightCols = nullptr;
	switch(indexStatus) {
	case JoinMatchExpression::NO_INDEX:
		{
			leftScanner = this->left->getScanner(trx, machine, nullptr, debug, ctx);
			rightCols = (new(ctx) ArrayList<ScanTableColumnIdentifier>(ctx));
			rightCols->add(exp->getRightColumn(ctx), ctx);
			rightScanner = this->right->getScanner(trx, machine, rightCols, debug, ctx);
			return ScannerFactory::getRightindexJoinScanner(trx, leftScanner, rightScanner, left->getScanTableMetadata(ctx), right->getScanTableMetadata(ctx), inner, exp, this->condition, machine, ctx);
		}
	case JoinMatchExpression::LEFT_INDEX:
		leftIndex = exp->getLeftIndex(ctx);
		leftScanner = this->left->getScanner(trx, machine, leftIndex->getColumnIds(ctx), debug, ctx);
		rightScanner = this->right->getScanner(trx, machine, nullptr, debug, ctx);
		return ScannerFactory::getReverseIndexScanner(trx, leftScanner, rightScanner, left->getScanTableMetadata(ctx), right->getScanTableMetadata(ctx), inner, exp, this->condition, machine, ctx);
	case JoinMatchExpression::RIGHT_INDEX:
		leftScanner = this->left->getScanner(trx, machine, nullptr, debug, ctx);
		rightIndex = exp->getRightIndex(ctx);
		rightScanner = this->right->getScanner(trx, machine, rightIndex->getColumnIds(ctx), debug, ctx);
		return ScannerFactory::getRightindexJoinScanner(trx, leftScanner, rightScanner, left->getScanTableMetadata(ctx), right->getScanTableMetadata(ctx), inner, exp, this->condition, machine, ctx);
	case JoinMatchExpression::BOTH_INDEX:
		leftIndex = exp->getLeftIndex(ctx);
		leftScanner = this->left->getScanner(trx, machine, leftIndex->getColumnIds(ctx), debug, ctx);
		rightScanner = this->right->getScanner(trx, machine, nullptr, debug, ctx);
		return ScannerFactory::getReverseIndexScanner(trx, leftScanner, rightScanner, left->getScanTableMetadata(ctx), right->getScanTableMetadata(ctx), inner, exp, this->condition, machine, ctx);
	}
	throw (new(ctx) DatabaseException(ConstStr::getCNST_STR_1174(), ctx));
}
void AbstractSQLJoin::__cleanUp(ThreadContext* ctx){
}
}}}}}

