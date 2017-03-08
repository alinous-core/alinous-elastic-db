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
#include "alinous.compile.sql.analyze/ScanTableMetadata.h"
#include "alinous.compile.sql/ISqlStatement.h"
#include "alinous.compile.sql.expression/ISQLExpression.h"
#include "alinous.compile.sql.parts/ISQLExpressionPart.h"
#include "alinous.compile.sql.parts/AbstractExpressionPart.h"
#include "alinous.compile.sql.parts/SQLExpressionList.h"
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
#include "alinous.compile.sql/AbstractSQLStatement.h"
#include "alinous.compile.sql/CreateIndexStatement.h"
#include "alinous.compile.sql/InsertStatement.h"
#include "alinous.compile.sql/UpdateSet.h"
#include "alinous.compile.sql/UpdateStatement.h"
#include "alinous.compile.sql.expression/AbstractSQLExpression.h"
#include "alinous.compile.sql.expression/SQLColumnIdentifier.h"
#include "alinous.compile.sql.expression/SQLExpressionStream.h"
#include "alinous.compile.sql.parts/SQLExpressionListAll.h"
#include "alinous.compile.sql.result/SelectResultDescription.h"
#include "alinous.db.trx/DbTransaction.h"
#include "alinous.db.trx.scan/ScanResultRecord.h"
#include "alinous.compile.sql.analyze/SQLAnalyseContext.h"
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
#include "alinous.compile.sql.select/SQLFrom.h"
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
#include "alinous.compile.declare/AlinousClass.h"
#include "alinous.compile.sql/SelectStatement.h"

namespace alinous {namespace compile {namespace sql {





bool SelectStatement::__init_done = __init_static_variables();
bool SelectStatement::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"SelectStatement", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 SelectStatement::SelectStatement(ThreadContext* ctx) throw()  : IObject(ctx), IJoinTarget(ctx), ThreadMonitor(ctx), intoDesc(nullptr), resultDesc(nullptr), groupByDesc(nullptr), list(nullptr), into(nullptr), from(nullptr), where(nullptr), groupBy(nullptr), limitOffset(nullptr)
{
}
void SelectStatement::__construct_impl(ThreadContext* ctx) throw() 
{
}
 SelectStatement::~SelectStatement() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void SelectStatement::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"SelectStatement", L"~SelectStatement");
	__e_obj1.add(this->intoDesc, this);
	intoDesc = nullptr;
	__e_obj1.add(this->resultDesc, this);
	resultDesc = nullptr;
	__e_obj1.add(this->groupByDesc, this);
	groupByDesc = nullptr;
	__e_obj1.add(this->list, this);
	list = nullptr;
	__e_obj1.add(this->into, this);
	into = nullptr;
	__e_obj1.add(this->from, this);
	from = nullptr;
	__e_obj1.add(this->where, this);
	where = nullptr;
	__e_obj1.add(this->groupBy, this);
	groupBy = nullptr;
	__e_obj1.add(this->limitOffset, this);
	limitOffset = nullptr;
	if(!prepare){
		return;
	}
	IJoinTarget::__releaseRegerences(true, ctx);
}
void SelectStatement::validate(SourceValidator* validator, ThreadContext* ctx) throw() 
{
}
bool SelectStatement::visit(IAlinousElementVisitor* visitor, AbstractSrcElement* parent, ThreadContext* ctx) throw() 
{
	if(!visitor->visit(this, parent, ctx))
	{
		return false;
	}
	if(this->list != nullptr && !this->list->visit(visitor, this, ctx))
	{
		return false;
	}
	if(this->from != nullptr && !this->from->visit(visitor, this, ctx))
	{
		return false;
	}
	if(this->where != nullptr && !this->where->visit(visitor, this, ctx))
	{
		return false;
	}
	if(this->groupBy != nullptr && !this->groupBy->visit(visitor, this, ctx))
	{
		return false;
	}
	if(this->limitOffset != nullptr && !this->limitOffset->visit(visitor, this, ctx))
	{
		return false;
	}
	return true;
}
bool SelectStatement::analyse(SrcAnalyseContext* context, bool leftValue, ThreadContext* ctx) throw() 
{
	if(this->list != nullptr)
	{
		this->list->analyse(context, leftValue, ctx);
	}
	if(this->from != nullptr)
	{
		this->from->analyse(context, leftValue, ctx);
	}
	if(this->where != nullptr)
	{
		this->where->analyse(context, leftValue, ctx);
	}
	if(this->groupBy != nullptr)
	{
		this->groupBy->analyse(context, leftValue, ctx);
	}
	if(this->limitOffset != nullptr)
	{
		this->limitOffset->analyse(context, leftValue, ctx);
	}
	if(this->into != nullptr)
	{
		__GC_MV(this, &(this->intoDesc), this->into->toDomVariableDescriptor(ctx), DomVariableDescriptor);
	}
	return true;
}
SQLExpressionList* SelectStatement::getList(ThreadContext* ctx) throw() 
{
	return list;
}
void SelectStatement::setList(SQLExpressionList* list, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->list), list, SQLExpressionList);
}
SQLFrom* SelectStatement::getFrom(ThreadContext* ctx) throw() 
{
	return from;
}
void SelectStatement::setFrom(SQLFrom* from, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->from), from, SQLFrom);
}
SQLGroupBy* SelectStatement::getGroupBy(ThreadContext* ctx) throw() 
{
	return groupBy;
}
void SelectStatement::setGroupBy(SQLGroupBy* groupBy, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->groupBy), groupBy, SQLGroupBy);
}
SQLLimitOffset* SelectStatement::getLimitOffset(ThreadContext* ctx) throw() 
{
	return limitOffset;
}
void SelectStatement::setLimitOffset(SQLLimitOffset* limitOffset, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->limitOffset), limitOffset, SQLLimitOffset);
}
SQLWhere* SelectStatement::getWhere(ThreadContext* ctx) throw() 
{
	return where;
}
void SelectStatement::setWhere(SQLWhere* where, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->where), where, SQLWhere);
}
IStatement::StatementType SelectStatement::getType(ThreadContext* ctx) throw() 
{
	return StatementType::SELECT;
}
void SelectStatement::analyzeSQL(SQLAnalyseContext* context, bool debug, ThreadContext* ctx)
{
	{
		SynchronizedBlockObj __synchronized_2(this, ctx);
		if(this->list != nullptr)
		{
			this->list->analyseSQL(context, false, debug, ctx);
		}
		if(this->from != nullptr)
		{
			this->from->analyseSQL(context, false, debug, ctx);
		}
		if(this->where != nullptr && this->where->getCondition(ctx) != nullptr)
		{
			this->where->getCondition(ctx)->analyseSQL(context, false, debug, ctx);
		}
		if(this->groupBy != nullptr)
		{
			this->groupBy->analyseSQL(context, false, debug, ctx);
		}
	}
	optimizeScan(context, this->where, this->groupBy, this->limitOffset, nullptr, debug, ctx);
}
void SelectStatement::optimizeScan(SQLAnalyseContext* context, SQLWhere* where, SQLGroupBy* groupby, SQLLimitOffset* limit, ArrayList<ScanTableColumnIdentifier>* joinRequest, bool debug, ThreadContext* ctx)
{
	IJoin* join = this->from->getJoin(ctx);
	if(join != nullptr)
	{
		join->optimizeScan(context, where, groupby, limit, joinRequest, debug, ctx);
	}
	ScanTableMetadata* metadata = join->getScanTableMetadata(ctx);
	__GC_MV(this, &(this->resultDesc), (new(ctx) SelectResultDescription(this->list, metadata, ctx)), SelectResultDescription);
	if(this->groupBy != nullptr)
	{
		__GC_MV(this, &(this->groupByDesc), (new(ctx) SelectResultDescription(this->groupBy->getGroupList(ctx), metadata, ctx)), SelectResultDescription);
	}
}
bool SelectStatement::analyseSQLTables(SQLAnalyseContext* context, bool leftValue, bool debug, ThreadContext* ctx)
{
	return true;
}
bool SelectStatement::hasTable(ScanTableIdentifier* table, ThreadContext* ctx) throw() 
{
	return false;
}
ScanTableMetadata* SelectStatement::getScanTableMetadata(ThreadContext* ctx) throw() 
{
	return nullptr;
}
bool SelectStatement::isOptimizerCacheable(ThreadContext* ctx) throw() 
{
	return this->from->getJoin(ctx)->isOptimizerCacheable(ctx);
}
ITableTargetScanner* SelectStatement::getScanner(DbTransaction* trx, ScriptMachine* machine, ArrayList<ScanTableColumnIdentifier>* joinRequest, bool debug, ThreadContext* ctx)
{
	IJoin* join = this->from->getJoin(ctx);
	if(join != nullptr)
	{
		return join->getScanner(trx, machine, joinRequest, debug, ctx);
	}
	return nullptr;
}
AlinousName* SelectStatement::getInto(ThreadContext* ctx) throw() 
{
	return into;
}
void SelectStatement::setInto(AlinousName* into, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->into), into, AlinousName);
}
SQLJoinCondition* SelectStatement::getCondition(ThreadContext* ctx)
{
	return nullptr;
}
int SelectStatement::getLine(ThreadContext* ctx) throw() 
{
	return IJoinTarget::getLine(ctx);
}
int SelectStatement::getStartPosition(ThreadContext* ctx) throw() 
{
	return IJoinTarget::getStartPosition(ctx);
}
int SelectStatement::getEndLine(ThreadContext* ctx) throw() 
{
	return IJoinTarget::getEndLine(ctx);
}
int SelectStatement::getEndPosition(ThreadContext* ctx) throw() 
{
	return IJoinTarget::getEndPosition(ctx);
}
AbstractSrcElement* SelectStatement::getParent(ThreadContext* ctx) throw() 
{
	return IJoinTarget::getParent(ctx);
}
void SelectStatement::setParent(AbstractSrcElement* parent, ThreadContext* ctx) throw() 
{
	IJoinTarget::setParent(parent, ctx);
}
void SelectStatement::readData(NetworkBinaryBuffer* buff, ThreadContext* ctx)
{
	bool isnull = buff->getBoolean(ctx);
	if(!isnull)
	{
		IAlinousElement* el = AlinousElementNetworkFactory::formNetworkData(buff, ctx);
		if(el == nullptr || !((dynamic_cast<SQLExpressionList*>(el) != 0)))
		{
			throw (new(ctx) VariableException(ConstStr::getCNST_STR_1039(), ctx));
		}
		__GC_MV(this, &(this->list), static_cast<SQLExpressionList*>(el), SQLExpressionList);
	}
	isnull = buff->getBoolean(ctx);
	if(!isnull)
	{
		IAlinousElement* el = AlinousElementNetworkFactory::formNetworkData(buff, ctx);
		if(el == nullptr || !((dynamic_cast<AlinousName*>(el) != 0)))
		{
			throw (new(ctx) VariableException(ConstStr::getCNST_STR_970(), ctx));
		}
		__GC_MV(this, &(this->into), static_cast<AlinousName*>(el), AlinousName);
	}
	isnull = buff->getBoolean(ctx);
	if(!isnull)
	{
		IAlinousElement* el = AlinousElementNetworkFactory::formNetworkData(buff, ctx);
		if(el == nullptr || !((dynamic_cast<SQLWhere*>(el) != 0)))
		{
			throw (new(ctx) VariableException(ConstStr::getCNST_STR_1041(), ctx));
		}
		__GC_MV(this, &(this->where), static_cast<SQLWhere*>(el), SQLWhere);
	}
	isnull = buff->getBoolean(ctx);
	if(!isnull)
	{
		IAlinousElement* el = AlinousElementNetworkFactory::formNetworkData(buff, ctx);
		if(el == nullptr || !((dynamic_cast<SQLGroupBy*>(el) != 0)))
		{
			throw (new(ctx) VariableException(ConstStr::getCNST_STR_1042(), ctx));
		}
		__GC_MV(this, &(this->groupBy), static_cast<SQLGroupBy*>(el), SQLGroupBy);
	}
	isnull = buff->getBoolean(ctx);
	if(!isnull)
	{
		IAlinousElement* el = AlinousElementNetworkFactory::formNetworkData(buff, ctx);
		if(el == nullptr || !((dynamic_cast<SQLLimitOffset*>(el) != 0)))
		{
			throw (new(ctx) VariableException(ConstStr::getCNST_STR_1043(), ctx));
		}
		__GC_MV(this, &(this->limitOffset), static_cast<SQLLimitOffset*>(el), SQLLimitOffset);
	}
}
void SelectStatement::writeData(NetworkBinaryBuffer* buff, ThreadContext* ctx)
{
	buff->putInt(ICommandData::__SelectStatement, ctx);
	bool isnull = (this->list == nullptr);
	buff->putBoolean(isnull, ctx);
	if(!isnull)
	{
		this->list->writeData(buff, ctx);
	}
	isnull = (this->into == nullptr);
	buff->putBoolean(isnull, ctx);
	if(!isnull)
	{
		this->into->writeData(buff, ctx);
	}
	isnull = (this->from == nullptr);
	buff->putBoolean(isnull, ctx);
	if(!isnull)
	{
		this->from->writeData(buff, ctx);
	}
	isnull = (this->where == nullptr);
	buff->putBoolean(isnull, ctx);
	if(!isnull)
	{
		this->where->writeData(buff, ctx);
	}
	isnull = (this->groupBy == nullptr);
	buff->putBoolean(isnull, ctx);
	if(!isnull)
	{
		this->groupBy->writeData(buff, ctx);
	}
	isnull = (this->limitOffset == nullptr);
	buff->putBoolean(isnull, ctx);
	if(!isnull)
	{
		this->limitOffset->writeData(buff, ctx);
	}
}
void SelectStatement::__cleanUp(ThreadContext* ctx){
}
}}}

