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
#include "alinous.compile/ExpressionSourceId.h"
#include "alinous.system/AlinousException.h"
#include "alinous.runtime/ExecutionException.h"
#include "alinous.runtime.dom/VariableException.h"
#include "alinous.remote.socket/NetworkBinaryBuffer.h"
#include "alinous.runtime.dom/IAlinousVariable.h"
#include "alinous.runtime.variant/VariantValue.h"
#include "alinous.compile.declare/IDeclare.h"
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
#include "alinous.compile.analyse/SubVariableDeclareHolder.h"
#include "alinous.compile/Token.h"
#include "alinous.compile.expression/IDomSegment.h"
#include "alinous.compile.expression/DomNameSegment.h"
#include "alinous.compile.expression/DomIndexSegment.h"
#include "alinous.compile.expression/DomVariableDescriptor.h"
#include "alinous.compile.declare.function/FunctionArgumentDefine.h"
#include "alinous.compile.analyse/VariableDeclareHolder.h"
#include "alinous.compile.declare/ClassMemberModifiers.h"
#include "alinous.compile.declare/IClassMember.h"
#include "alinous.compile.declare/AbstractClassMember.h"
#include "alinous.compile.declare/ClassMemberVariable.h"
#include "alinous.compile.declare.function/FunctionArgumentsListDefine.h"
#include "alinous.compile.declare.function/ReturnValueDefinition.h"
#include "alinous.compile.stmt/StatementBlock.h"
#include "alinous.compile.expression.expstream/FunctionCallExpression.h"
#include "alinous.compile.declare/VirtualTable.h"
#include "alinous.compile.declare/ClassMethodFunction.h"
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
#include "alinous.runtime.engine/ScriptMachine.h"
#include "alinous.compile.analyse/AlinousType.h"
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
#include "alinous.compile.stmt/TypedVariableDeclare.h"

namespace alinous {namespace compile {namespace stmt {



constexpr EnumBase __TypedVariableDeclare__VariableType::__DEFAULT_NULL;
constexpr EnumBase __TypedVariableDeclare__VariableType::BOOL_TYPE;
constexpr EnumBase __TypedVariableDeclare__VariableType::BYTE_TYPE;
constexpr EnumBase __TypedVariableDeclare__VariableType::SHORT_TYPE;
constexpr EnumBase __TypedVariableDeclare__VariableType::CHAR_TYPE;
constexpr EnumBase __TypedVariableDeclare__VariableType::INT_TYPE;
constexpr EnumBase __TypedVariableDeclare__VariableType::LONG_TYPE;
constexpr EnumBase __TypedVariableDeclare__VariableType::FLOAT_TYPE;
constexpr EnumBase __TypedVariableDeclare__VariableType::DOUBLE_TYPE;
constexpr EnumBase __TypedVariableDeclare__VariableType::STRING_TYPE;
constexpr EnumBase __TypedVariableDeclare__VariableType::TIMESTAMP;
constexpr EnumBase __TypedVariableDeclare__VariableType::TIME;
constexpr EnumBase __TypedVariableDeclare__VariableType::BIGDECIMAL;
constexpr EnumBase __TypedVariableDeclare__VariableType::OBJECT_TYPE;


bool TypedVariableDeclare::__init_done = __init_static_variables();
bool TypedVariableDeclare::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"TypedVariableDeclare", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 TypedVariableDeclare::TypedVariableDeclare(ThreadContext* ctx) throw()  : IObject(ctx), AbstractAlinousStatement(ctx), typeName(nullptr), name(nullptr), dimension(0), initExp(nullptr), analysedType(nullptr)
{
}
void TypedVariableDeclare::__construct_impl(ThreadContext* ctx) throw() 
{
}
 TypedVariableDeclare::~TypedVariableDeclare() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void TypedVariableDeclare::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"TypedVariableDeclare", L"~TypedVariableDeclare");
	__e_obj1.add(this->typeName, this);
	typeName = nullptr;
	__e_obj1.add(this->name, this);
	name = nullptr;
	__e_obj1.add(this->initExp, this);
	initExp = nullptr;
	__e_obj1.add(this->analysedType, this);
	analysedType = nullptr;
	if(!prepare){
		return;
	}
	AbstractAlinousStatement::__releaseRegerences(true, ctx);
}
void TypedVariableDeclare::setTypeName(AlinousName* typeName, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->typeName), typeName, AlinousName);
	String* strName = this->typeName->toString(ctx);
	if(strName->equals(ConstStr::getCNST_STR_1070(), ctx))
	{
		this->typeEnum = VariableType::BOOL_TYPE;
	}
		else 
	{
		if(strName->equals(ConstStr::getCNST_STR_1071(), ctx))
		{
			this->typeEnum = VariableType::INT_TYPE;
		}
				else 
		{
			if(strName->equals(ConstStr::getCNST_STR_1072(), ctx))
			{
				this->typeEnum = VariableType::STRING_TYPE;
			}
						else 
			{
				if(strName->equals(ConstStr::getCNST_STR_1073(), ctx))
				{
					this->typeEnum = VariableType::BYTE_TYPE;
				}
								else 
				{
					if(strName->equals(ConstStr::getCNST_STR_1074(), ctx))
					{
						this->typeEnum = VariableType::SHORT_TYPE;
					}
										else 
					{
						if(strName->equals(ConstStr::getCNST_STR_1075(), ctx))
						{
							this->typeEnum = VariableType::CHAR_TYPE;
						}
												else 
						{
							if(strName->equals(ConstStr::getCNST_STR_1076(), ctx))
							{
								this->typeEnum = VariableType::LONG_TYPE;
							}
														else 
							{
								if(strName->equals(ConstStr::getCNST_STR_1077(), ctx))
								{
									this->typeEnum = VariableType::FLOAT_TYPE;
								}
																else 
								{
									if(strName->equals(ConstStr::getCNST_STR_1078(), ctx))
									{
										this->typeEnum = VariableType::DOUBLE_TYPE;
									}
																		else 
									{
										if(strName->equals(ConstStr::getCNST_STR_1079(), ctx))
										{
											this->typeEnum = VariableType::TIMESTAMP;
										}
																				else 
										{
											if(strName->equals(ConstStr::getCNST_STR_1080(), ctx))
											{
												this->typeEnum = VariableType::TIME;
											}
																						else 
											{
												if(strName->equals(ConstStr::getCNST_STR_1081(), ctx))
												{
													this->typeEnum = VariableType::BIGDECIMAL;
												}
																								else 
												{
													this->typeEnum = VariableType::OBJECT_TYPE;
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
}
void TypedVariableDeclare::setName(AlinousName* name, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->name), name, AlinousName);
}
IStatement::StatementType TypedVariableDeclare::getType(ThreadContext* ctx) throw() 
{
	return StatementType::TYPED_VARIABLE_DECLARE;
}
void TypedVariableDeclare::validate(SourceValidator* validator, ThreadContext* ctx) throw() 
{
	if(this->name->getSegments(ctx)->size(ctx) != 1)
	{
		validator->addError(ConstStr::getCNST_STR_1082(), this->name, ctx);
	}
}
bool TypedVariableDeclare::visit(IAlinousElementVisitor* visitor, AbstractSrcElement* parent, ThreadContext* ctx) throw() 
{
	if(!visitor->visit(this, parent, ctx))
	{
		return false;
	}
	if(this->typeName != nullptr && !this->typeName->visit(visitor, this, ctx))
	{
		return false;
	}
	if(this->name != nullptr && !this->name->visit(visitor, this, ctx))
	{
		return false;
	}
	if(this->initExp != nullptr && !this->initExp->visit(visitor, this, ctx))
	{
		return false;
	}
	return true;
}
bool TypedVariableDeclare::analyse(SrcAnalyseContext* context, bool leftValue, ThreadContext* ctx) throw() 
{
	VariableDeclareHolder* mainFrame = context->getCurrentStack(ctx);
	SubVariableDeclareHolder* subFrame = mainFrame->getCurrentSubStack(ctx);
	subFrame->addTypedVariableDeclare(this, ctx);
	AlinousClass* clazz = nullptr;
	switch(this->typeEnum) {
	case TypedVariableDeclare::VariableType::BOOL_TYPE:
		__GC_MV(this, &(this->analysedType), (new(ctx) AlinousType(AlinousType::BOOL_TYPE, AlinousType::TYPE_PRIMITIVE, ctx)), AlinousType);
		break ;
	case TypedVariableDeclare::VariableType::INT_TYPE:
		__GC_MV(this, &(this->analysedType), (new(ctx) AlinousType(AlinousType::INT_TYPE, AlinousType::TYPE_PRIMITIVE, ctx)), AlinousType);
		break ;
	case TypedVariableDeclare::VariableType::BYTE_TYPE:
		__GC_MV(this, &(this->analysedType), (new(ctx) AlinousType(AlinousType::BYTE_TYPE, AlinousType::TYPE_PRIMITIVE, ctx)), AlinousType);
		break ;
	case TypedVariableDeclare::VariableType::SHORT_TYPE:
		__GC_MV(this, &(this->analysedType), (new(ctx) AlinousType(AlinousType::SHORT_TYPE, AlinousType::TYPE_PRIMITIVE, ctx)), AlinousType);
		break ;
	case TypedVariableDeclare::VariableType::CHAR_TYPE:
		__GC_MV(this, &(this->analysedType), (new(ctx) AlinousType(AlinousType::CHAR_TYPE, AlinousType::TYPE_PRIMITIVE, ctx)), AlinousType);
		break ;
	case TypedVariableDeclare::VariableType::LONG_TYPE:
		__GC_MV(this, &(this->analysedType), (new(ctx) AlinousType(AlinousType::LONG_TYPE, AlinousType::TYPE_PRIMITIVE, ctx)), AlinousType);
		break ;
	case TypedVariableDeclare::VariableType::FLOAT_TYPE:
		__GC_MV(this, &(this->analysedType), (new(ctx) AlinousType(AlinousType::FLOAT_TYPE, AlinousType::TYPE_PRIMITIVE, ctx)), AlinousType);
		break ;
	case TypedVariableDeclare::VariableType::DOUBLE_TYPE:
		__GC_MV(this, &(this->analysedType), (new(ctx) AlinousType(AlinousType::DOUBLE_TYPE, AlinousType::TYPE_PRIMITIVE, ctx)), AlinousType);
		break ;
	case TypedVariableDeclare::VariableType::STRING_TYPE:
		__GC_MV(this, &(this->analysedType), (new(ctx) AlinousType(AlinousType::STRING_TYPE, AlinousType::TYPE_STANDARD_OBJ, ctx)), AlinousType);
		break ;
	case TypedVariableDeclare::VariableType::TIMESTAMP:
		__GC_MV(this, &(this->analysedType), (new(ctx) AlinousType(AlinousType::TIMESTAMP, AlinousType::TYPE_STANDARD_OBJ, ctx)), AlinousType);
		break ;
	case TypedVariableDeclare::VariableType::TIME:
		__GC_MV(this, &(this->analysedType), (new(ctx) AlinousType(AlinousType::TIME, AlinousType::TYPE_STANDARD_OBJ, ctx)), AlinousType);
		break ;
	case TypedVariableDeclare::VariableType::BIGDECIMAL:
		__GC_MV(this, &(this->analysedType), (new(ctx) AlinousType(AlinousType::BIGDECIMAL, AlinousType::TYPE_STANDARD_OBJ, ctx)), AlinousType);
		break ;
	case TypedVariableDeclare::VariableType::OBJECT_TYPE:
	default:
		clazz = context->findClassDeclare(this->typeName, ctx);
		if(clazz == nullptr)
		{
			context->addError(this->typeName->toString(ctx)->clone(ctx)->append(ConstStr::getCNST_STR_1031(), ctx), this, ctx);
		}
				else 
		{
			__GC_MV(this, &(this->analysedType), (new(ctx) AlinousType(clazz, ctx)), AlinousType);
			this->analysedType->setDimension(this->dimension, ctx);
		}
		break ;
	}
	if(this->initExp != nullptr)
	{
		this->initExp->analyse(context, false, ctx);
	}
	return true;
}
AlinousName* TypedVariableDeclare::getTypeName(ThreadContext* ctx) throw() 
{
	return typeName;
}
AlinousName* TypedVariableDeclare::getName(ThreadContext* ctx) throw() 
{
	return name;
}
TypedVariableDeclare::VariableType TypedVariableDeclare::getTypeEnum(ThreadContext* ctx) throw() 
{
	return typeEnum;
}
IExpression* TypedVariableDeclare::getInitExp(ThreadContext* ctx) throw() 
{
	return initExp;
}
void TypedVariableDeclare::setInitExp(IExpression* initExp, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->initExp), initExp, IExpression);
}
AlinousType* TypedVariableDeclare::getAnalysedType(ThreadContext* ctx) throw() 
{
	return analysedType;
}
int TypedVariableDeclare::getDimension(ThreadContext* ctx) throw() 
{
	return dimension;
}
void TypedVariableDeclare::setDimension(int dimension, ThreadContext* ctx) throw() 
{
	this->dimension = dimension;
}
void TypedVariableDeclare::readData(NetworkBinaryBuffer* buff, ThreadContext* ctx)
{
	bool isnull = buff->getBoolean(ctx);
	if(!isnull)
	{
		IAlinousElement* el = AlinousElementNetworkFactory::formNetworkData(buff, ctx);
		if(el == nullptr || !((dynamic_cast<AlinousName*>(el) != 0)))
		{
			throw (new(ctx) VariableException(ConstStr::getCNST_STR_1033(), ctx));
		}
		__GC_MV(this, &(this->typeName), static_cast<AlinousName*>(el), AlinousName);
	}
	this->dimension = buff->getInt(ctx);
	isnull = buff->getBoolean(ctx);
	if(!isnull)
	{
		IAlinousElement* el = AlinousElementNetworkFactory::formNetworkData(buff, ctx);
		if(el == nullptr || !((dynamic_cast<IExpression*>(el) != 0)))
		{
			throw (new(ctx) VariableException(ConstStr::getCNST_STR_1027(), ctx));
		}
		__GC_MV(this, &(this->initExp), static_cast<IExpression*>(el), IExpression);
	}
	int typeNum = buff->getInt(ctx);
	int2enum(typeNum, ctx);
}
void TypedVariableDeclare::writeData(NetworkBinaryBuffer* buff, ThreadContext* ctx)
{
	buff->putInt(ICommandData::__TypedVariableDeclare, ctx);
	bool isnull = (this->typeName == nullptr);
	buff->putBoolean(isnull, ctx);
	if(!isnull)
	{
		this->typeName->writeData(buff, ctx);
	}
	buff->putInt(this->dimension, ctx);
	isnull = (this->initExp == nullptr);
	buff->putBoolean(isnull, ctx);
	if(!isnull)
	{
		this->initExp->writeData(buff, ctx);
	}
	int typeNum = enum2Int(ctx);
	buff->putInt(typeNum, ctx);
}
int TypedVariableDeclare::enum2Int(ThreadContext* ctx) throw() 
{
	switch(this->typeEnum) {
	case TypedVariableDeclare::VariableType::BOOL_TYPE:
		return 1;
	case TypedVariableDeclare::VariableType::BYTE_TYPE:
		return 2;
	case TypedVariableDeclare::VariableType::SHORT_TYPE:
		return 3;
	case TypedVariableDeclare::VariableType::CHAR_TYPE:
		return 4;
	case TypedVariableDeclare::VariableType::INT_TYPE:
		return 5;
	case TypedVariableDeclare::VariableType::LONG_TYPE:
		return 6;
	case TypedVariableDeclare::VariableType::FLOAT_TYPE:
		return 7;
	case TypedVariableDeclare::VariableType::DOUBLE_TYPE:
		return 8;
	case TypedVariableDeclare::VariableType::STRING_TYPE:
		return 9;
	case TypedVariableDeclare::VariableType::TIMESTAMP:
		return 10;
	case TypedVariableDeclare::VariableType::TIME:
		return 11;
	case TypedVariableDeclare::VariableType::BIGDECIMAL:
		return 12;
	case TypedVariableDeclare::VariableType::OBJECT_TYPE:
		return 13;
	default:
		break ;
	}
	return 13;
}
void TypedVariableDeclare::int2enum(int num, ThreadContext* ctx) throw() 
{
	switch(num) {
	case 1:
		this->typeEnum = VariableType::BOOL_TYPE;
		break ;
	case 2:
		this->typeEnum = VariableType::BYTE_TYPE;
		break ;
	case 3:
		this->typeEnum = VariableType::SHORT_TYPE;
		break ;
	case 4:
		this->typeEnum = VariableType::CHAR_TYPE;
		break ;
	case 5:
		this->typeEnum = VariableType::INT_TYPE;
		break ;
	case 6:
		this->typeEnum = VariableType::LONG_TYPE;
		break ;
	case 7:
		this->typeEnum = VariableType::FLOAT_TYPE;
		break ;
	case 8:
		this->typeEnum = VariableType::DOUBLE_TYPE;
		break ;
	case 9:
		this->typeEnum = VariableType::STRING_TYPE;
		break ;
	case 10:
		this->typeEnum = VariableType::TIMESTAMP;
		break ;
	case 11:
		this->typeEnum = VariableType::TIME;
		break ;
	case 12:
		this->typeEnum = VariableType::BIGDECIMAL;
		break ;
	case 13:
	default:
		this->typeEnum = VariableType::OBJECT_TYPE;
		break ;
	}
}
void TypedVariableDeclare::__cleanUp(ThreadContext* ctx){
}
}}}

