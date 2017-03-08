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
#include "alinous.html/IDomObject.h"
#include "alinous.html/DomNode.h"
#include "alinous.system/AlinousException.h"
#include "alinous.runtime/ExecutionException.h"
#include "alinous.runtime.dom/VariableException.h"
#include "alinous.remote.socket/NetworkBinaryBuffer.h"
#include "alinous.btree/IValueFetcher.h"
#include "alinous.btree/IBTreeValue.h"
#include "alinous.runtime.dom/IDomVariableContainer.h"
#include "alinous.runtime.dom/IAlinousVariable.h"
#include "alinous.runtime.dom/IDomVariable.h"
#include "alinous.compile.stmt/AbstractAlinousStatement.h"
#include "alinous.compile.stmt/StatementList.h"
#include "alinous.runtime.dom/DomArray.h"
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
#include "alinous.compile.declare.function/FunctionArgumentDefine.h"
#include "alinous.compile.declare.function/FunctionArgumentsListDefine.h"
#include "alinous.compile.declare/VirtualTable.h"
#include "alinous.compile.declare/ClassMethodFunction.h"
#include "alinous.compile/Token.h"
#include "alinous.compile.expression/IDomSegment.h"
#include "alinous.compile.expression/DomNameSegment.h"
#include "alinous.compile.expression/DomIndexSegment.h"
#include "alinous.compile.stmt/TypedVariableDeclare.h"
#include "alinous.compile.expression.expstream/ExpStreamSegment.h"
#include "alinous.compile.expression.expstream/ExpressionStream.h"
#include "alinous.compile.expression.expstream/ExpStreamCast.h"
#include "alinous.compile.expression.expstream/ExpStreamParenthesis.h"
#include "alinous.compile.sql.analyze/ScanTableIdentifier.h"
#include "alinous.compile.sql.analyze/ScanTableColumnIdentifier.h"
#include "alinous.compile.sql.analyze/ScanTableMetadata.h"
#include "alinous.db.table/IDatabaseRecord.h"
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
#include "alinous.compile.sql.select/SQLFrom.h"
#include "alinous.compile.sql/SelectStatement.h"
#include "alinous.compile.sql/UpdateStatement.h"
#include "alinous.db.trx/DbTransaction.h"
#include "alinous.db.trx.scan/ScanResultRecord.h"
#include "alinous.compile.sql.analyze/SQLAnalyseContext.h"
#include "alinous.compile.sql/UpdateSet.h"
#include "alinous.compile.sql.expression/SQLSubExpression.h"
#include "alinous.compile.sql.expression/AbstractSQLCollectionExpression.h"
#include "alinous.compile.sql.expression/SQLAdditiveExpression.h"
#include "alinous.compile.sql.expression/AbstractSQLExpression.h"
#include "alinous.compile.sql.expression/SQLColumnIdentifier.h"
#include "alinous.compile.sql.expression/SQLExpressionStream.h"
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
#include "alinous.compile.expression/DomVariableDescriptor.h"
#include "alinous.runtime.dom/DomVariable.h"
#include "alinous.runtime.dom.typed/BigDecimalVariable.h"
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
#include "alinous.compile.sql/InsertValues.h"

namespace alinous {namespace compile {namespace sql {





bool InsertValues::__init_done = __init_static_variables();
bool InsertValues::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"InsertValues", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 InsertValues::InsertValues(ThreadContext* ctx) throw()  : IObject(ctx), ISQLExpression(ctx), ThreadMonitor(ctx), vlist(nullptr), domDesc(nullptr)
{
}
void InsertValues::__construct_impl(ThreadContext* ctx) throw() 
{
}
 InsertValues::~InsertValues() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void InsertValues::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"InsertValues", L"~InsertValues");
	__e_obj1.add(this->vlist, this);
	vlist = nullptr;
	__e_obj1.add(this->domDesc, this);
	domDesc = nullptr;
	if(!prepare){
		return;
	}
	ISQLExpression::__releaseRegerences(true, ctx);
}
IAlinousVariable* InsertValues::resolveExpression(ScriptMachine* machine, bool debug, ThreadContext* ctx)
{
	return nullptr;
}
ExpressionSourceId* InsertValues::getSourceId(ThreadContext* ctx) throw() 
{
	return (new(ctx) ExpressionSourceId(nullptr, this, nullptr, ctx));
}
IDomVariable* InsertValues::getValues(ScriptMachine* machine, bool debug, ThreadContext* ctx)
{
	if(domDesc != nullptr)
	{
		return static_cast<IDomVariable*>(this->domDesc->resolveExpression(machine, debug, ctx));
	}
	DomArray* array = (new(ctx) DomArray(ctx));
	ArrayList<ISQLExpression>* values = this->vlist->getList(ctx);
	int maxLoop = values->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		ISQLExpression* exp = values->get(i, ctx);
		IAlinousVariable* v = exp->resolveExpression(machine, debug, ctx);
		if(v->getVariableClass(ctx) == IAlinousVariable::CLASS_VARIANT)
		{
			DomVariable* dom = (new(ctx) DomVariable(ctx));
			dom->setValue(static_cast<VariantValue*>(v), ctx);
			array->put(dom, ctx);
		}
				else 
		{
			if(v->getVariableClass(ctx) == IAlinousVariable::CLASS_DOM)
			{
				array->put(static_cast<IDomVariable*>(v), ctx);
			}
		}
	}
	return array;
}
bool InsertValues::visit(IAlinousElementVisitor* visitor, AbstractSrcElement* parent, ThreadContext* ctx) throw() 
{
	if(!visitor->visit(this, parent, ctx))
	{
		return false;
	}
	if(this->vlist != nullptr && !this->vlist->visit(visitor, this, ctx))
	{
		return false;
	}
	if(this->domDesc != nullptr && !this->domDesc->visit(visitor, this, ctx))
	{
		return false;
	}
	return true;
}
bool InsertValues::isConstant(ThreadContext* ctx) throw() 
{
	if(this->domDesc != nullptr)
	{
		return false;
	}
	if(this->vlist != nullptr && !this->vlist->isConstant(ctx))
	{
		return false;
	}
	return true;
}
bool InsertValues::analyse(SrcAnalyseContext* context, bool leftValue, ThreadContext* ctx) throw() 
{
	{
		SynchronizedBlockObj __synchronized_2(this, ctx);
		if(this->vlist != nullptr)
		{
			this->vlist->analyse(context, leftValue, ctx);
		}
		if(this->domDesc != nullptr)
		{
			this->domDesc->analyse(context, leftValue, ctx);
		}
	}
	return true;
}
SQLExpressionList* InsertValues::getVlist(ThreadContext* ctx) throw() 
{
	return vlist;
}
void InsertValues::setVlist(SQLExpressionList* vlist, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->vlist), vlist, SQLExpressionList);
}
SQLExpressionStream* InsertValues::getDomDesc(ThreadContext* ctx) throw() 
{
	return domDesc;
}
void InsertValues::setDomDesc(SQLExpressionStream* domDesc, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->domDesc), domDesc, SQLExpressionStream);
}
bool InsertValues::analyseSQL(SQLAnalyseContext* context, bool leftValue, bool debug, ThreadContext* ctx)
{
	{
		SynchronizedBlockObj __synchronized_2(this, ctx);
		if(this->vlist != nullptr)
		{
			this->vlist->analyseSQL(context, leftValue, debug, ctx);
		}
		if(this->domDesc != nullptr)
		{
			this->domDesc->analyseSQL(context, leftValue, debug, ctx);
		}
	}
	return true;
}
bool InsertValues::hasTable(ScanTableIdentifier* table, ThreadContext* ctx) throw() 
{
	return false;
}
ArrayList<ScanTableColumnIdentifier>* InsertValues::getColumns(ThreadContext* ctx) throw() 
{
	return nullptr;
}
bool InsertValues::hasSubExp(ThreadContext* ctx) throw() 
{
	return false;
}
bool InsertValues::isJoinCondition(ThreadContext* ctx) throw() 
{
	return false;
}
void InsertValues::collectJoinCondition(ArrayList<ISQLExpression>* list, ThreadContext* ctx) throw() 
{
}
bool InsertValues::isColumnIdentifier(ThreadContext* ctx) throw() 
{
	return false;
}
ScanTableColumnIdentifier* InsertValues::toColumnIdentifier(ThreadContext* ctx) throw() 
{
	return nullptr;
}
VariantValue* InsertValues::resolveSQLExpression(ScanResultRecord* record, ScriptMachine* machine, bool debug, ThreadContext* ctx) throw() 
{
	return nullptr;
}
int InsertValues::getLine(ThreadContext* ctx) throw() 
{
	return ISQLExpression::getLine(ctx);
}
int InsertValues::getStartPosition(ThreadContext* ctx) throw() 
{
	return ISQLExpression::getStartPosition(ctx);
}
int InsertValues::getEndLine(ThreadContext* ctx) throw() 
{
	return ISQLExpression::getEndLine(ctx);
}
int InsertValues::getEndPosition(ThreadContext* ctx) throw() 
{
	return ISQLExpression::getEndPosition(ctx);
}
AbstractSrcElement* InsertValues::getParent(ThreadContext* ctx) throw() 
{
	return ISQLExpression::getParent(ctx);
}
void InsertValues::setParent(AbstractSrcElement* parent, ThreadContext* ctx) throw() 
{
	ISQLExpression::setParent(parent, ctx);
}
bool InsertValues::hasArrayResult(ThreadContext* ctx) throw() 
{
	return false;
}
ArrayList<VariantValue>* InsertValues::resolveSQLExpressionAsArray(ScanResultRecord* record, ScriptMachine* machine, bool debug, ThreadContext* ctx)
{
	throw (new(ctx) DatabaseException(ConstStr::getCNST_STR_1038(), ctx));
}
bool InsertValues::isSQLExp(ThreadContext* ctx) throw() 
{
	return true;
}
String* InsertValues::getAsName(ThreadContext* ctx) throw() 
{
	return nullptr;
}
void InsertValues::setAsName(String* name, ThreadContext* ctx) throw() 
{
}
int InsertValues::getExpressionType(ThreadContext* ctx) throw() 
{
	return IExpression::insertValues;
}
void InsertValues::readData(NetworkBinaryBuffer* buff, ThreadContext* ctx)
{
	bool isnull = buff->getBoolean(ctx);
	if(!isnull)
	{
		IAlinousElement* el = AlinousElementNetworkFactory::formNetworkData(buff, ctx);
		if(el == nullptr || !((dynamic_cast<SQLExpressionList*>(el) != 0)))
		{
			throw (new(ctx) VariableException(ConstStr::getCNST_STR_1039(), ctx));
		}
		__GC_MV(this, &(this->vlist), static_cast<SQLExpressionList*>(el), SQLExpressionList);
	}
	isnull = buff->getBoolean(ctx);
	if(!isnull)
	{
		IAlinousElement* el = AlinousElementNetworkFactory::formNetworkData(buff, ctx);
		if(el == nullptr || !((dynamic_cast<SQLExpressionStream*>(el) != 0)))
		{
			throw (new(ctx) VariableException(ConstStr::getCNST_STR_1040(), ctx));
		}
		__GC_MV(this, &(this->domDesc), static_cast<SQLExpressionStream*>(el), SQLExpressionStream);
	}
}
void InsertValues::writeData(NetworkBinaryBuffer* buff, ThreadContext* ctx)
{
	buff->putInt(ICommandData::__InsertValues, ctx);
	bool isnull = (this->vlist == nullptr);
	buff->putBoolean(isnull, ctx);
	if(!isnull)
	{
		this->vlist->writeData(buff, ctx);
	}
	isnull = (this->domDesc == nullptr);
	buff->putBoolean(isnull, ctx);
	if(!isnull)
	{
		this->domDesc->writeData(buff, ctx);
	}
}
int InsertValues::fileSize(ThreadContext* ctx)
{
	int total = 4;
	bool isnull = (this->vlist == nullptr);
	total += 1;
	if(!isnull)
	{
		total += this->vlist->fileSize(ctx);
	}
	isnull = (this->domDesc == nullptr);
	total += 1;
	if(!isnull)
	{
		total += this->domDesc->fileSize(ctx);
	}
	return total;
}
void InsertValues::toFileEntry(FileStorageEntryBuilder* builder, ThreadContext* ctx)
{
	builder->putInt(IExpressionFactory::__InsertValues, ctx);
	bool isnull = (this->vlist == nullptr);
	builder->putBoolean(isnull, ctx);
	if(!isnull)
	{
		this->vlist->toFileEntry(builder, ctx);
	}
	isnull = (this->domDesc == nullptr);
	builder->putBoolean(isnull, ctx);
	if(!isnull)
	{
		this->domDesc->toFileEntry(builder, ctx);
	}
}
void InsertValues::fromFileEntry(FileStorageEntryFetcher* fetcher, ThreadContext* ctx)
{
	bool isnull = fetcher->fetchBoolean(ctx);
	if(!isnull)
	{
		IExpression* exp = IExpressionFactory::fromFetcher(fetcher, ctx);
		if(exp != nullptr || !((dynamic_cast<SQLExpressionList*>(exp) != 0)))
		{
			throw (new(ctx) AlinousException(ConstStr::getCNST_STR_1040(), ctx));
		}
		__GC_MV(this, &(this->vlist), static_cast<SQLExpressionList*>(exp), SQLExpressionList);
	}
	isnull = fetcher->fetchBoolean(ctx);
	if(!isnull)
	{
		IExpression* exp = IExpressionFactory::fromFetcher(fetcher, ctx);
		if(exp != nullptr || !((dynamic_cast<SQLExpressionStream*>(exp) != 0)))
		{
			throw (new(ctx) AlinousException(ConstStr::getCNST_STR_1040(), ctx));
		}
		__GC_MV(this, &(this->domDesc), static_cast<SQLExpressionStream*>(exp), SQLExpressionStream);
	}
}
void InsertValues::__cleanUp(ThreadContext* ctx){
}
}}}

