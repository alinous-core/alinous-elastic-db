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
#include "alinous.db.table/DatabaseException.h"
#include "alinous.html/IDomObject.h"
#include "alinous.html/DomNode.h"
#include "alinous.system/AlinousException.h"
#include "alinous.runtime/ExecutionException.h"
#include "alinous.runtime.dom/VariableException.h"
#include "alinous.remote.socket/NetworkBinaryBuffer.h"
#include "alinous.btree/IValueFetcher.h"
#include "alinous.btree/IBTreeValue.h"
#include "alinous.compile.analyse/SubVariableDeclareHolder.h"
#include "alinous.compile.stmt/AbstractAlinousStatement.h"
#include "alinous.compile.stmt/TypedVariableDeclare.h"
#include "alinous.compile.analyse/VariableDeclareHolder.h"
#include "alinous.runtime.dom/IDomVariableContainer.h"
#include "alinous.runtime.dom/IAlinousVariable.h"
#include "alinous.runtime.dom/IDomVariable.h"
#include "alinous.compile.declare/IDeclare.h"
#include "alinous.compile.stmt/StatementList.h"
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
#include "alinous.compile.declare.function/FunctionArgumentsListDefine.h"
#include "alinous.compile.declare.function/ReturnValueDefinition.h"
#include "alinous.compile.stmt/StatementBlock.h"
#include "alinous.compile/Token.h"
#include "alinous.compile.expression/IDomSegment.h"
#include "alinous.compile.expression/DomNameSegment.h"
#include "alinous.compile.expression/DomIndexSegment.h"
#include "alinous.runtime.dom/DomVariableContainer.h"
#include "alinous.runtime.dom.typed/TypedVariableContainer.h"
#include "alinous.runtime.engine/IStackFrame.h"
#include "alinous.runtime.engine/AbstractStackFrame.h"
#include "alinous.runtime.engine/SubStackFrame.h"
#include "alinous.runtime.engine/MainStackFrame.h"
#include "alinous.compile.expression.expstream/FunctionCallExpression.h"
#include "alinous.compile.declare/VirtualTable.h"
#include "alinous.compile.declare/ClassMethodFunction.h"
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
#include "alinous.compile.expression/DomVariableDescriptor.h"
#include "alinous.runtime.dom/DomVariable.h"
#include "alinous.runtime.dom.typed/BigDecimalVariable.h"
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
#include "alinous.runtime.dom.clazz/IAlinousClassVariable.h"
#include "alinous.compile.declare.function/FunctionArgumentDefine.h"

namespace alinous {namespace compile {namespace declare {namespace function {



constexpr EnumBase __FunctionArgumentDefine__FunctionArgumentType::__DEFAULT_NULL;
constexpr EnumBase __FunctionArgumentDefine__FunctionArgumentType::DOM_VARIABLE;
constexpr EnumBase __FunctionArgumentDefine__FunctionArgumentType::DOM_ARRAY_VARIABLE;
constexpr EnumBase __FunctionArgumentDefine__FunctionArgumentType::BOOL_TYPE;
constexpr EnumBase __FunctionArgumentDefine__FunctionArgumentType::BYTE_TYPE;
constexpr EnumBase __FunctionArgumentDefine__FunctionArgumentType::SHORT_TYPE;
constexpr EnumBase __FunctionArgumentDefine__FunctionArgumentType::CHAR_TYPE;
constexpr EnumBase __FunctionArgumentDefine__FunctionArgumentType::INT_TYPE;
constexpr EnumBase __FunctionArgumentDefine__FunctionArgumentType::LONG_TYPE;
constexpr EnumBase __FunctionArgumentDefine__FunctionArgumentType::FLOAT_TYPE;
constexpr EnumBase __FunctionArgumentDefine__FunctionArgumentType::DOUBLE_TYPE;
constexpr EnumBase __FunctionArgumentDefine__FunctionArgumentType::STRING_TYPE;
constexpr EnumBase __FunctionArgumentDefine__FunctionArgumentType::TIMESTAMP;
constexpr EnumBase __FunctionArgumentDefine__FunctionArgumentType::TIME;
constexpr EnumBase __FunctionArgumentDefine__FunctionArgumentType::BIGDECIMAL;
constexpr EnumBase __FunctionArgumentDefine__FunctionArgumentType::OBJECT_TYPE;


bool FunctionArgumentDefine::__init_done = __init_static_variables();
bool FunctionArgumentDefine::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"FunctionArgumentDefine", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 FunctionArgumentDefine::FunctionArgumentDefine(ThreadContext* ctx) throw()  : IObject(ctx), IDeclare(ctx), type(nullptr), name(nullptr), domDescriptor(nullptr), analysedType(nullptr)
{
}
void FunctionArgumentDefine::__construct_impl(ThreadContext* ctx) throw() 
{
}
 FunctionArgumentDefine::~FunctionArgumentDefine() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void FunctionArgumentDefine::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"FunctionArgumentDefine", L"~FunctionArgumentDefine");
	__e_obj1.add(this->type, this);
	type = nullptr;
	__e_obj1.add(this->name, this);
	name = nullptr;
	__e_obj1.add(this->domDescriptor, this);
	domDescriptor = nullptr;
	__e_obj1.add(this->analysedType, this);
	analysedType = nullptr;
	if(!prepare){
		return;
	}
	IDeclare::__releaseRegerences(true, ctx);
}
bool FunctionArgumentDefine::sameMethodSig(FunctionArgumentDefine* other, ThreadContext* ctx) throw() 
{
	if(this->domDescriptor != nullptr && other->domDescriptor != nullptr)
	{
		return true;
	}
	if(this->type != nullptr && other->type != nullptr)
	{
		return this->type->equals(other, ctx);
	}
	return false;
}
void FunctionArgumentDefine::putArgument(ScriptMachine* machine, MainStackFrame* frame, IAlinousVariable* variable, bool debug, ThreadContext* ctx)
{
	FunctionArgumentDefine::FunctionArgumentType variableType = getVariableType(ctx);
	switch(variableType) {
	case FunctionArgumentDefine::FunctionArgumentType::DOM_VARIABLE:
		frame->putVariable(machine, this->domDescriptor, variable->toDomVariable(ctx), debug, ctx);
		break ;
	case FunctionArgumentDefine::FunctionArgumentType::DOM_ARRAY_VARIABLE:
		if(variable->getVariableClass(ctx) != IAlinousVariable::CLASS_DOM || (static_cast<IDomVariable*>(variable))->getDomType(ctx) != IDomVariable::TYPE_ARRAY)
		{
			throw (new(ctx) VariableException(ConstStr::getCNST_STR_1103(), ctx));
		}
		frame->putVariable(machine, this->domDescriptor, static_cast<IDomVariable*>(variable), debug, ctx);
		break ;
	case FunctionArgumentDefine::FunctionArgumentType::BOOL_TYPE:
		{
			try
			{
				frame->putTypedVariable(this->name->toString(ctx), variable->toBoolVariable(ctx), ctx);
			}
			catch(AlinousException* e)
			{
				e->setSrcElement(this, ctx);
			}
		}
		break ;
	case FunctionArgumentDefine::FunctionArgumentType::BYTE_TYPE:
		{
			try
			{
				frame->putTypedVariable(this->name->toString(ctx), variable->toByteVariable(ctx), ctx);
			}
			catch(AlinousException* e)
			{
				e->setSrcElement(this, ctx);
			}
		}
		break ;
	case FunctionArgumentDefine::FunctionArgumentType::SHORT_TYPE:
		{
			try
			{
				frame->putTypedVariable(this->name->toString(ctx), variable->toShortVariable(ctx), ctx);
			}
			catch(AlinousException* e)
			{
				e->setSrcElement(this, ctx);
			}
		}
		break ;
	case FunctionArgumentDefine::FunctionArgumentType::CHAR_TYPE:
		{
			try
			{
				frame->putTypedVariable(this->name->toString(ctx), variable->toCharVariable(ctx), ctx);
			}
			catch(AlinousException* e)
			{
				e->setSrcElement(this, ctx);
			}
		}
		break ;
	case FunctionArgumentDefine::FunctionArgumentType::INT_TYPE:
		{
			try
			{
				frame->putTypedVariable(this->name->toString(ctx), variable->toIntVariable(ctx), ctx);
			}
			catch(AlinousException* e)
			{
				e->setSrcElement(this, ctx);
			}
		}
		break ;
	case FunctionArgumentDefine::FunctionArgumentType::LONG_TYPE:
		{
			try
			{
				frame->putTypedVariable(this->name->toString(ctx), variable->toLongVariable(ctx), ctx);
			}
			catch(AlinousException* e)
			{
				e->setSrcElement(this, ctx);
			}
		}
		break ;
	case FunctionArgumentDefine::FunctionArgumentType::FLOAT_TYPE:
		{
			try
			{
				frame->putTypedVariable(this->name->toString(ctx), variable->toFloatVariable(ctx), ctx);
			}
			catch(AlinousException* e)
			{
				e->setSrcElement(this, ctx);
			}
		}
		break ;
	case FunctionArgumentDefine::FunctionArgumentType::DOUBLE_TYPE:
		{
			try
			{
				frame->putTypedVariable(this->name->toString(ctx), variable->toDoubleVariable(ctx), ctx);
			}
			catch(AlinousException* e)
			{
				e->setSrcElement(this, ctx);
			}
		}
		break ;
	case FunctionArgumentDefine::FunctionArgumentType::STRING_TYPE:
		{
			try
			{
				frame->putTypedVariable(this->name->toString(ctx), variable->toStringVariable(ctx), ctx);
			}
			catch(AlinousException* e)
			{
				e->setSrcElement(this, ctx);
			}
		}
		break ;
	case FunctionArgumentDefine::FunctionArgumentType::TIMESTAMP:
		{
			try
			{
				frame->putTypedVariable(this->name->toString(ctx), variable->toTimestampVariable(ctx), ctx);
			}
			catch(AlinousException* e)
			{
				e->setSrcElement(this, ctx);
			}
		}
		break ;
	case FunctionArgumentDefine::FunctionArgumentType::TIME:
		{
			try
			{
				frame->putTypedVariable(this->name->toString(ctx), variable->toTimeVariable(ctx), ctx);
			}
			catch(AlinousException* e)
			{
				e->setSrcElement(this, ctx);
			}
		}
		break ;
	case FunctionArgumentDefine::FunctionArgumentType::BIGDECIMAL:
		{
			try
			{
				frame->putTypedVariable(this->name->toString(ctx), variable->toBigDecimalVariable(ctx), ctx);
			}
			catch(AlinousException* e)
			{
				e->setSrcElement(this, ctx);
			}
		}
		break ;
	case FunctionArgumentDefine::FunctionArgumentType::OBJECT_TYPE:
	default:
		if(!((dynamic_cast<IAlinousClassVariable*>(variable) != 0)))
		{
			throw (new(ctx) VariableException(ConstStr::getCNST_STR_1104(), ctx));
		}
		{
			try
			{
				frame->putTypedVariable(this->name->toString(ctx), static_cast<ITypedVariable*>(variable), ctx);
			}
			catch(AlinousException* e)
			{
				e->setSrcElement(this, ctx);
			}
		}
		break;
	}
}
FunctionArgumentDefine::FunctionArgumentType FunctionArgumentDefine::getVariableType(ThreadContext* ctx) throw() 
{
	if(this->domDescriptor != nullptr)
	{
		if(this->domDescriptor->getPrefix(ctx)->equals(ConstStr::getCNST_STR_1105(), ctx))
		{
			return FunctionArgumentType::DOM_VARIABLE;
		}
				else 
		{
			return FunctionArgumentType::DOM_ARRAY_VARIABLE;
		}
	}
	String* strName = this->type->toString(ctx);
	if(strName->equals(ConstStr::getCNST_STR_1070(), ctx))
	{
		return FunctionArgumentType::BOOL_TYPE;
	}
		else 
	{
		if(strName->equals(ConstStr::getCNST_STR_1071(), ctx))
		{
			return FunctionArgumentType::INT_TYPE;
		}
				else 
		{
			if(strName->equals(ConstStr::getCNST_STR_1072(), ctx))
			{
				return FunctionArgumentType::STRING_TYPE;
			}
						else 
			{
				if(strName->equals(ConstStr::getCNST_STR_1072(), ctx))
				{
					return FunctionArgumentType::STRING_TYPE;
				}
								else 
				{
					if(strName->equals(ConstStr::getCNST_STR_1073(), ctx))
					{
						return FunctionArgumentType::BYTE_TYPE;
					}
										else 
					{
						if(strName->equals(ConstStr::getCNST_STR_1074(), ctx))
						{
							return FunctionArgumentType::SHORT_TYPE;
						}
												else 
						{
							if(strName->equals(ConstStr::getCNST_STR_1075(), ctx))
							{
								return FunctionArgumentType::CHAR_TYPE;
							}
														else 
							{
								if(strName->equals(ConstStr::getCNST_STR_1076(), ctx))
								{
									return FunctionArgumentType::LONG_TYPE;
								}
																else 
								{
									if(strName->equals(ConstStr::getCNST_STR_1077(), ctx))
									{
										return FunctionArgumentType::FLOAT_TYPE;
									}
																		else 
									{
										if(strName->equals(ConstStr::getCNST_STR_1078(), ctx))
										{
											return FunctionArgumentType::DOUBLE_TYPE;
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
	return FunctionArgumentType::OBJECT_TYPE;
}
bool FunctionArgumentDefine::visit(IAlinousElementVisitor* visitor, AbstractSrcElement* parent, ThreadContext* ctx) throw() 
{
	if(!visitor->visit(this, parent, ctx))
	{
		return false;
	}
	if(this->domDescriptor != nullptr && !this->domDescriptor->visit(visitor, this, ctx))
	{
		return false;
	}
	if(this->type != nullptr && !this->type->visit(visitor, this, ctx))
	{
		return false;
	}
	if(this->name != nullptr && !this->name->visit(visitor, this, ctx))
	{
		return false;
	}
	return true;
}
bool FunctionArgumentDefine::analyse(SrcAnalyseContext* context, bool leftValue, ThreadContext* ctx) throw() 
{
	VariableDeclareHolder* mainFrame = context->getCurrentStack(ctx);
	SubVariableDeclareHolder* subFrame = mainFrame->getCurrentSubStack(ctx);
	subFrame->addFunctionArgumentDefine(this, ctx);
	if(this->type == nullptr)
	{
		__GC_MV(this, &(this->analysedType), (new(ctx) AlinousType(ctx)), AlinousType);
	}
		else 
	{
		__GC_MV(this, &(this->analysedType), this->type->toAlinousType(context, ctx), AlinousType);
	}
	return true;
}
String* FunctionArgumentDefine::toString(ThreadContext* ctx) throw() 
{
	StringBuffer* buff = (new(ctx) StringBuffer(ctx));
	if(this->type != nullptr)
	{
		buff->append(this->type->toString(ctx), ctx);
	}
		else 
	{
		buff->append(this->domDescriptor->toString(ctx), ctx);
	}
	return buff->toString(ctx);
}
AlinousName* FunctionArgumentDefine::getType(ThreadContext* ctx) throw() 
{
	return type;
}
void FunctionArgumentDefine::setType(AlinousName* type, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->type), type, AlinousName);
}
AlinousName* FunctionArgumentDefine::getName(ThreadContext* ctx) throw() 
{
	return name;
}
void FunctionArgumentDefine::setName(AlinousName* name, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->name), name, AlinousName);
}
DomVariableDescriptor* FunctionArgumentDefine::getDomDescriptor(ThreadContext* ctx) throw() 
{
	return domDescriptor;
}
void FunctionArgumentDefine::setDomDescriptor(DomVariableDescriptor* domDescriptor, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->domDescriptor), domDescriptor, DomVariableDescriptor);
}
AlinousType* FunctionArgumentDefine::getAnalysedType(ThreadContext* ctx) throw() 
{
	return analysedType;
}
int FunctionArgumentDefine::getLine(ThreadContext* ctx) throw() 
{
	return IDeclare::getLine(ctx);
}
int FunctionArgumentDefine::getStartPosition(ThreadContext* ctx) throw() 
{
	return IDeclare::getStartPosition(ctx);
}
int FunctionArgumentDefine::getEndLine(ThreadContext* ctx) throw() 
{
	return IDeclare::getEndLine(ctx);
}
int FunctionArgumentDefine::getEndPosition(ThreadContext* ctx) throw() 
{
	return IDeclare::getEndPosition(ctx);
}
AbstractSrcElement* FunctionArgumentDefine::getParent(ThreadContext* ctx) throw() 
{
	return IDeclare::getParent(ctx);
}
void FunctionArgumentDefine::setParent(AbstractSrcElement* parent, ThreadContext* ctx) throw() 
{
	IDeclare::setParent(parent, ctx);
}
void FunctionArgumentDefine::readData(NetworkBinaryBuffer* buff, ThreadContext* ctx)
{
	bool isnull = buff->getBoolean(ctx);
	if(!isnull)
	{
		IAlinousElement* el = AlinousElementNetworkFactory::formNetworkData(buff, ctx);
		if(el == nullptr || !((dynamic_cast<AlinousName*>(el) != 0)))
		{
			throw (new(ctx) VariableException(ConstStr::getCNST_STR_1033(), ctx));
		}
		__GC_MV(this, &(this->type), static_cast<AlinousName*>(el), AlinousName);
	}
	isnull = buff->getBoolean(ctx);
	if(!isnull)
	{
		IAlinousElement* el = AlinousElementNetworkFactory::formNetworkData(buff, ctx);
		if(el == nullptr || !((dynamic_cast<AlinousName*>(el) != 0)))
		{
			throw (new(ctx) VariableException(ConstStr::getCNST_STR_1033(), ctx));
		}
		__GC_MV(this, &(this->name), static_cast<AlinousName*>(el), AlinousName);
	}
	isnull = buff->getBoolean(ctx);
	if(!isnull)
	{
		IAlinousElement* el = AlinousElementNetworkFactory::formNetworkData(buff, ctx);
		if(el == nullptr || !((dynamic_cast<DomVariableDescriptor*>(el) != 0)))
		{
			throw (new(ctx) VariableException(ConstStr::getCNST_STR_1049(), ctx));
		}
		__GC_MV(this, &(this->domDescriptor), static_cast<DomVariableDescriptor*>(el), DomVariableDescriptor);
	}
}
void FunctionArgumentDefine::writeData(NetworkBinaryBuffer* buff, ThreadContext* ctx)
{
	buff->putInt(ICommandData::__FunctionArgumentDefine, ctx);
	bool isnull = (this->type == nullptr);
	buff->putBoolean(isnull, ctx);
	if(!isnull)
	{
		this->type->writeData(buff, ctx);
	}
	isnull = (this->name == nullptr);
	buff->putBoolean(isnull, ctx);
	if(!isnull)
	{
		this->name->writeData(buff, ctx);
	}
	isnull = (this->domDescriptor == nullptr);
	buff->putBoolean(isnull, ctx);
	if(!isnull)
	{
		this->domDescriptor->writeData(buff, ctx);
	}
}
void FunctionArgumentDefine::__cleanUp(ThreadContext* ctx){
}
}}}}

