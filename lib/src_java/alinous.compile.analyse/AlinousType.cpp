#include "include/global.h"


#include "alinous.numeric/InternalDate.h"
#include "alinous.numeric/TimeOnlyTimestamp.h"
#include "java.sql/Timestamp.h"
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
#include "alinous.db.table/DatabaseException.h"
#include "alinous.html/IDomObject.h"
#include "alinous.html/DomNode.h"
#include "java.lang/Number.h"
#include "java.lang/Comparable.h"
#include "alinous.numeric/BigDecimal.h"
#include "alinous.btree/IValueFetcher.h"
#include "alinous.btree/IBTreeValue.h"
#include "alinous.runtime.dom/IAlinousVariable.h"
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
#include "alinous.runtime.dom/IDomVariableContainer.h"
#include "alinous.runtime.dom/IDomVariable.h"
#include "alinous.runtime.dom/DomVariable.h"
#include "alinous.runtime.dom.typed/BigDecimalVariable.h"
#include "alinous.compile/AbstractSrcElement.h"
#include "alinous.compile/IAlinousElement.h"
#include "alinous.compile.declare/IDeclare.h"
#include "alinous.compile.analyse/SourceValidator.h"
#include "alinous.compile/IStatement.h"
#include "alinous.runtime.dom.clazz/IAlinousClassVariable.h"
#include "alinous.compile.declare.function/FunctionArgumentDefine.h"
#include "alinous.compile.declare.function/FunctionArgumentsListDefine.h"
#include "alinous.compile.declare.function/ReturnValueDefinition.h"
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
#include "alinous.runtime.dom.clazz/AlinousClassVariable.h"
#include "alinous.compile.declare/ClassMemberModifiers.h"
#include "alinous.compile.declare/IClassMember.h"
#include "alinous.compile.declare/AbstractClassMember.h"
#include "alinous.compile.declare/ClassMemberVariable.h"
#include "alinous.compile.expression/IDomSegment.h"
#include "alinous.compile.expression/DomIndexSegment.h"
#include "alinous.compile.expression/Literal.h"
#include "alinous.compile.stmt/AbstractAlinousStatement.h"
#include "alinous.compile.stmt/TypedVariableDeclare.h"
#include "alinous.runtime.dom/DocumentVariable.h"
#include "alinous.compile.expression.expstream/ExpStreamSegment.h"
#include "alinous.compile.expression.expstream/ExpressionStream.h"
#include "alinous.compile.expression.expstream/ExpStreamCast.h"
#include "alinous.compile.expression.expstream/ExpStreamParenthesis.h"
#include "alinous.compile.sql.analyze/ScanTableIdentifier.h"
#include "alinous.compile.sql.analyze/ScanTableColumnIdentifier.h"
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
#include "alinous.compile.expression/FunctionArguments.h"
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
#include "alinous.compile/ExpressionSourceId.h"
#include "alinous.compile.expression/DomVariableDescriptor.h"
#include "alinous.compile.expression/DomNameSegment.h"
#include "alinous.compile.declare/AlinousName.h"
#include "alinous.compile.analyse/SrcAnalyseContext.h"
#include "alinous.compile.declare/VirtualTable.h"
#include "alinous.compile.declare/ClassMethodFunction.h"
#include "alinous.compile.declare/ClassImplements.h"
#include "alinous.compile.declare/AlinousClass.h"
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
#include "alinous.compile.analyse/AlinousType.h"

namespace alinous {namespace compile {namespace analyse {





constexpr const int AlinousType::TYPE_PRIMITIVE;
constexpr const int AlinousType::TYPE_STANDARD_OBJ;
constexpr const int AlinousType::TYPE_CLASS_OBJ;
constexpr const int AlinousType::TYPE_DOM;
constexpr const int AlinousType::TYPE_VOID;
constexpr const int AlinousType::NULL_TYPE;
constexpr const int AlinousType::BOOL_TYPE;
constexpr const int AlinousType::BYTE_TYPE;
constexpr const int AlinousType::SHORT_TYPE;
constexpr const int AlinousType::CHAR_TYPE;
constexpr const int AlinousType::INT_TYPE;
constexpr const int AlinousType::LONG_TYPE;
constexpr const int AlinousType::FLOAT_TYPE;
constexpr const int AlinousType::DOUBLE_TYPE;
constexpr const int AlinousType::TIME;
constexpr const int AlinousType::TIMESTAMP;
constexpr const int AlinousType::BIGDECIMAL;
constexpr const int AlinousType::STRING_TYPE;
constexpr const int AlinousType::OBJECT_TYPE;
bool AlinousType::__init_done = __init_static_variables();
bool AlinousType::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"AlinousType", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 AlinousType::AlinousType(AlinousClass* clazz, ThreadContext* ctx) throw()  : IObject(ctx), ICommandData(ctx), typeClass(0), clazz(nullptr), type(0), dimension(0)
{
	__GC_MV(this, &(this->clazz), clazz, AlinousClass);
	this->typeClass = TYPE_CLASS_OBJ;
}
void AlinousType::__construct_impl(AlinousClass* clazz, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->clazz), clazz, AlinousClass);
	this->typeClass = TYPE_CLASS_OBJ;
}
 AlinousType::AlinousType(int type, int typeClass, ThreadContext* ctx) throw()  : IObject(ctx), ICommandData(ctx), typeClass(0), clazz(nullptr), type(0), dimension(0)
{
	this->type = type;
	this->typeClass = typeClass;
}
void AlinousType::__construct_impl(int type, int typeClass, ThreadContext* ctx) throw() 
{
	this->type = type;
	this->typeClass = typeClass;
}
 AlinousType::AlinousType(ThreadContext* ctx) throw()  : IObject(ctx), ICommandData(ctx), typeClass(0), clazz(nullptr), type(0), dimension(0)
{
	this->typeClass = TYPE_DOM;
	this->type = -1;
}
void AlinousType::__construct_impl(ThreadContext* ctx) throw() 
{
	this->typeClass = TYPE_DOM;
	this->type = -1;
}
 AlinousType::~AlinousType() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void AlinousType::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"AlinousType", L"~AlinousType");
	__e_obj1.add(this->clazz, this);
	clazz = nullptr;
	if(!prepare){
		return;
	}
}
int AlinousType::getTypeClass(ThreadContext* ctx) throw() 
{
	return typeClass;
}
AlinousClass* AlinousType::getClazz(ThreadContext* ctx) throw() 
{
	return clazz;
}
int AlinousType::getType(ThreadContext* ctx) throw() 
{
	return type;
}
IAlinousVariable* AlinousType::makeDefault(ThreadContext* ctx) throw() 
{
	if(this->dimension == 0)
	{
		switch(this->typeClass) {
		case TYPE_PRIMITIVE:
			return returnPrimitive(ctx);
		case TYPE_STANDARD_OBJ:
			return returnStandardVariable(ctx);
		case TYPE_CLASS_OBJ:
			return returnClasssVariable(ctx);
		case TYPE_DOM:
			return (new(ctx) DocumentVariable(ctx));
		case TYPE_VOID:
		default:
			break ;
		}
	}
	TypedVariableArray* arratVar = (new(ctx) TypedVariableArray(ctx));
	return arratVar;
}
int AlinousType::getDimension(ThreadContext* ctx) throw() 
{
	return dimension;
}
void AlinousType::setDimension(int dimension, ThreadContext* ctx) throw() 
{
	this->dimension = dimension;
}
void AlinousType::readData(NetworkBinaryBuffer* buff, ThreadContext* ctx)
{
	this->typeClass = buff->getInt(ctx);
	bool isnull = buff->getBoolean(ctx);
	if(!isnull)
	{
		IAlinousElement* el = AlinousElementNetworkFactory::formNetworkData(buff, ctx);
		if(el == nullptr || !((dynamic_cast<AlinousClass*>(el) != 0)))
		{
			throw (new(ctx) VariableException(ConstStr::getCNST_STR_1065(), ctx));
		}
		__GC_MV(this, &(this->clazz), static_cast<AlinousClass*>(el), AlinousClass);
	}
	this->type = buff->getInt(ctx);
	this->dimension = buff->getInt(ctx);
}
void AlinousType::writeData(NetworkBinaryBuffer* buff, ThreadContext* ctx)
{
	buff->putInt(this->typeClass, ctx);
	bool isnull = (this->clazz == nullptr);
	buff->putBoolean(isnull, ctx);
	if(!isnull)
	{
		this->clazz->writeData(buff, ctx);
	}
	buff->putInt(this->type, ctx);
	buff->putInt(this->dimension, ctx);
}
IAlinousVariable* AlinousType::returnClasssVariable(ThreadContext* ctx) throw() 
{
	AlinousClassVariable* val = (new(ctx) AlinousClassVariable(this->clazz, ctx));
	return val;
}
IAlinousVariable* AlinousType::returnStandardVariable(ThreadContext* ctx) throw() 
{
	switch(this->type) {
	case TIME:
		return (new(ctx) TimeVariable((new(ctx) TimeOnlyTimestamp(System::currentTimeMillis(ctx), ctx)), ctx));
	case TIMESTAMP:
		return (new(ctx) TimestampVariable((new(ctx) Timestamp(System::currentTimeMillis(ctx), ctx)), ctx));
	case BIGDECIMAL:
		return (new(ctx) BigDecimalVariable((new(ctx) BigDecimal(0, ctx)), ctx));
	case STRING_TYPE:
		return (new(ctx) StringVariable(ctx));
	default:
		break ;
	}
	return nullptr;
}
IAlinousVariable* AlinousType::returnPrimitive(ThreadContext* ctx) throw() 
{
	switch(this->type) {
	case BOOL_TYPE:
		return (new(ctx) BoolVariable(ctx));
	case BYTE_TYPE:
		return (new(ctx) ByteVariable(ctx));
	case SHORT_TYPE:
		return (new(ctx) ShortVariable(ctx));
	case CHAR_TYPE:
		return (new(ctx) CharVariable(ctx));
	case INT_TYPE:
		return (new(ctx) IntegerVariable(ctx));
	case LONG_TYPE:
		return (new(ctx) LongVariable(ctx));
	case FLOAT_TYPE:
		return (new(ctx) FloatVariable(ctx));
	case DOUBLE_TYPE:
		return (new(ctx) DoubleVariable(ctx));
	case NULL_TYPE:
	default:
		break ;
	}
	return nullptr;
}
void AlinousType::fillArray(int level, ScriptMachine* machine, TypedVariableArray* parent, AlinousType* analysedType, ArrayList<IExpression>* arrayCapacity, bool debug, ThreadContext* ctx)
{
	IExpression* exp = arrayCapacity->get(level, ctx);
	IAlinousVariable* capV = exp->resolveExpression(machine, debug, ctx);
	int fillCap = capV->getIntValue(ctx);
	if(level == (arrayCapacity->size(ctx) - 1))
	{
		fillLeafArray(fillCap, parent, analysedType, ctx);
		return;
	}
	int newLevel = level + 1;
	for(int i = 0; i != fillCap; ++i)
	{
		TypedVariableArray* arratVar = (new(ctx) TypedVariableArray(ctx));
		parent->addElement(arratVar, ctx);
		fillArray(newLevel, machine, arratVar, analysedType, arrayCapacity, debug, ctx);
	}
	return;
}
TypedVariableArray* AlinousType::fillLeafArray(int count, TypedVariableArray* arrayVar, AlinousType* analysedType, ThreadContext* ctx)
{
	for(int i = 0; i != count; ++i)
	{
		ITypedVariable* variable = newBlankVariable(analysedType, ctx);
		arrayVar->addElement(variable, ctx);
	}
	return arrayVar;
}
ITypedVariable* AlinousType::newBlankVariable(AlinousType* analysedType, ThreadContext* ctx)
{
	switch(analysedType->getTypeClass(ctx)) {
	case AlinousType::TYPE_STANDARD_OBJ:
		switch(analysedType->getType(ctx)) {
		case AlinousType::STRING_TYPE:
			return (new(ctx) StringVariable(ctx));
		case AlinousType::TIME:
			return (new(ctx) TimeVariable(ctx));
		case AlinousType::TIMESTAMP:
			return (new(ctx) TimestampVariable(ctx));
		case AlinousType::BIGDECIMAL:
			return (new(ctx) BigDecimalVariable(ctx));
		default:
			break ;
		}
		break ;
	case AlinousType::TYPE_CLASS_OBJ:
		return (new(ctx) AlinousClassVariable(analysedType->getClazz(ctx), ctx));
	case AlinousType::TYPE_PRIMITIVE:
		switch(analysedType->getType(ctx)) {
		case AlinousType::BOOL_TYPE:
			return (new(ctx) BoolVariable(ctx));
		case AlinousType::BYTE_TYPE:
			return (new(ctx) ByteVariable(ctx));
		case AlinousType::SHORT_TYPE:
			return (new(ctx) ShortVariable(ctx));
		case AlinousType::CHAR_TYPE:
			return (new(ctx) CharVariable(ctx));
		case AlinousType::INT_TYPE:
			return (new(ctx) IntegerVariable(ctx));
		case AlinousType::LONG_TYPE:
			return (new(ctx) LongVariable(ctx));
		case AlinousType::FLOAT_TYPE:
			return (new(ctx) FloatVariable(ctx));
		case AlinousType::DOUBLE_TYPE:
			return (new(ctx) DoubleVariable(ctx));
		case AlinousType::NULL_TYPE:
		default:
			break ;
		}
	default:
		break ;
	}
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1064(), ctx));
}
void AlinousType::__cleanUp(ThreadContext* ctx){
}
}}}

