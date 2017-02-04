#include "includes.h"


namespace alinous {namespace compile {





bool AlinousElementNetworkFactory::__init_done = __init_static_variables();
bool AlinousElementNetworkFactory::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"AlinousElementNetworkFactory", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 AlinousElementNetworkFactory::~AlinousElementNetworkFactory() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void AlinousElementNetworkFactory::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
}
IAlinousElement* AlinousElementNetworkFactory::formNetworkData(NetworkBinaryBuffer* buff, ThreadContext* ctx)
{
	IAlinousElement* element = nullptr;
	int type = buff->getInt(ctx);
	switch(type) {
	case ICommandData::__AlinousName:
		element = (new(ctx) AlinousName(ctx));
		break ;
	case ICommandData::__AlinousSrc:
		element = (new(ctx) AlinousSrc(ctx));
		break ;
	case ICommandData::__CheckDefinition:
		element = (new(ctx) CheckDefinition(ctx));
		break ;
	case ICommandData::__ColumnTypeDescriptor:
		element = (new(ctx) ColumnTypeDescriptor(ctx));
		break ;
	case ICommandData::__DdlColumnDescriptor:
		element = (new(ctx) DdlColumnDescriptor(ctx));
		break ;
	case ICommandData::__AlinousClass:
		element = (new(ctx) AlinousClass(ctx));
		break ;
	case ICommandData::__AlinousFunction:
		element = (new(ctx) AlinousFunction(ctx));
		break ;
	case ICommandData::__ClassExtends:
		element = (new(ctx) ClassExtends(ctx));
		break ;
	case ICommandData::__ClassImplements:
		element = (new(ctx) ClassImplements(ctx));
		break ;
	case ICommandData::__ClassMemberModifiers:
		element = (new(ctx) ClassMemberModifiers(ctx));
		break ;
	case ICommandData::__FunctionArgumentDefine:
		element = (new(ctx) FunctionArgumentDefine(ctx));
		break ;
	case ICommandData::__FunctionArgumentsListDefine:
		element = (new(ctx) FunctionArgumentsListDefine(ctx));
		break ;
	case ICommandData::__ClassMemberVariable:
		element = (new(ctx) ClassMemberVariable(ctx));
		break ;
	case ICommandData::__ClassMethodFunction:
		element = (new(ctx) ClassMethodFunction(ctx));
		break ;
	case ICommandData::__ReturnValueDefinition:
		element = (new(ctx) ReturnValueDefinition(ctx));
		break ;
	case ICommandData::__ThrowsDefine:
		element = (new(ctx) ThrowsDefine(ctx));
		break ;
	case ICommandData::__DomIndexSegment:
		element = (new(ctx) DomIndexSegment(ctx));
		break ;
	case ICommandData::__DomNameSegment:
		element = (new(ctx) DomNameSegment(ctx));
		break ;
	case ICommandData::__AndExpression:
		element = (new(ctx) AndExpression(ctx));
		break ;
	case ICommandData::__ConditionalAndExpression:
		element = (new(ctx) ConditionalAndExpression(ctx));
		break ;
	case ICommandData::__ConditionalOrExpression:
		element = (new(ctx) ConditionalOrExpression(ctx));
		break ;
	case ICommandData::__ExclusiveOrExpression:
		element = (new(ctx) ExclusiveOrExpression(ctx));
		break ;
	case ICommandData::__InclusiveOrExpression:
		element = (new(ctx) InclusiveOrExpression(ctx));
		break ;
	case ICommandData::__EqualityExpression:
		element = (new(ctx) EqualityExpression(ctx));
		break ;
	case ICommandData::__InstanceOfExpression:
		element = (new(ctx) InstanceOfExpression(ctx));
		break ;
	case ICommandData::__RelationalExpression:
		element = (new(ctx) RelationalExpression(ctx));
		break ;
	case ICommandData::__AdditiveExpression:
		element = (new(ctx) AdditiveExpression(ctx));
		break ;
	case ICommandData::__MultiplicativeExpression:
		element = (new(ctx) MultiplicativeExpression(ctx));
		break ;
	case ICommandData::__ShiftExpression:
		element = (new(ctx) ShiftExpression(ctx));
		break ;
	case ICommandData::__AllocationExpression:
		element = (new(ctx) AllocationExpression(ctx));
		break ;
	case ICommandData::__BitReverseExpression:
		element = (new(ctx) BitReverseExpression(ctx));
		break ;
	case ICommandData::__BooleanSubExpression:
		element = (new(ctx) BooleanSubExpression(ctx));
		break ;
	case ICommandData::__CastExpression:
		element = (new(ctx) CastExpression(ctx));
		break ;
	case ICommandData::__ConditionalExpression:
		element = (new(ctx) ConditionalExpression(ctx));
		break ;
	case ICommandData::__ExpStreamCast:
		element = (new(ctx) ExpStreamCast(ctx));
		break ;
	case ICommandData::__ExpStreamParenthesis:
		element = (new(ctx) ExpStreamParenthesis(ctx));
		break ;
	case ICommandData::__ExpStreamSegment:
		element = (new(ctx) ExpStreamSegment(ctx));
		break ;
	case ICommandData::__FunctionArguments:
		element = (new(ctx) FunctionArguments(ctx));
		break ;
	case ICommandData::__FunctionCallExpression:
		element = (new(ctx) FunctionCallExpression(ctx));
		break ;
	case ICommandData::__Literal:
		element = (new(ctx) Literal(ctx));
		break ;
	case ICommandData::__BooleanLiteral:
		element = (new(ctx) BooleanLiteral(ctx));
		break ;
	case ICommandData::__NullLiteral:
		element = (new(ctx) NullLiteral(ctx));
		break ;
	case ICommandData::__ParenthesisExpression:
		element = (new(ctx) ParenthesisExpression(ctx));
		break ;
	case ICommandData::__PreDecrementExpression:
		element = (new(ctx) PreDecrementExpression(ctx));
		break ;
	case ICommandData::__PreIncrementExpression:
		element = (new(ctx) PreIncrementExpression(ctx));
		break ;
	case ICommandData::__SubExpression:
		element = (new(ctx) SubExpression(ctx));
		break ;
	case ICommandData::__UnaryExpression:
		element = (new(ctx) UnaryExpression(ctx));
		break ;
	case ICommandData::__DomVariableDescriptor:
		element = (new(ctx) DomVariableDescriptor(ctx));
		break ;
	case ICommandData::__ExpressionStream:
		element = (new(ctx) ExpressionStream(ctx));
		break ;
	case ICommandData::__SQLAdditiveExpression:
		element = (new(ctx) SQLAdditiveExpression(ctx));
		break ;
	case ICommandData::__SQLMultiplicativeExpression:
		element = (new(ctx) SQLMultiplicativeExpression(ctx));
		break ;
	case ICommandData::__SQLSubqueryExpression:
		element = (new(ctx) SQLSubqueryExpression(ctx));
		break ;
	case ICommandData::__SQLColumnIdentifier:
		element = (new(ctx) SQLColumnIdentifier(ctx));
		break ;
	case ICommandData::__SQLLiteral:
		element = (new(ctx) SQLLiteral(ctx));
		break ;
	case ICommandData::__SQLParenthesisExpression:
		element = (new(ctx) SQLParenthesisExpression(ctx));
		break ;
	case ICommandData::__InsertValues:
		element = (new(ctx) InsertValues(ctx));
		break ;
	case ICommandData::__SQLAndExpression:
		element = (new(ctx) SQLAndExpression(ctx));
		break ;
	case ICommandData::__SQLOrExpression:
		element = (new(ctx) SQLOrExpression(ctx));
		break ;
	case ICommandData::__SQLBooleanLiteral:
		element = (new(ctx) SQLBooleanLiteral(ctx));
		break ;
	case ICommandData::__SQLBoolSubExpression:
		element = (new(ctx) SQLBoolSubExpression(ctx));
		break ;
	case ICommandData::__SQLEqualityExpression:
		element = (new(ctx) SQLEqualityExpression(ctx));
		break ;
	case ICommandData::__SQLInExpression:
		element = (new(ctx) SQLInExpression(ctx));
		break ;
	case ICommandData::__SQLIsNullExpression:
		element = (new(ctx) SQLIsNullExpression(ctx));
		break ;
	case ICommandData::__SQLJoinCondition:
		element = (new(ctx) SQLJoinCondition(ctx));
		break ;
	case ICommandData::__SQLLikeExpression:
		element = (new(ctx) SQLLikeExpression(ctx));
		break ;
	case ICommandData::__SQLNotExpression:
		element = (new(ctx) SQLNotExpression(ctx));
		break ;
	case ICommandData::__SQLRelationalExpression:
		element = (new(ctx) SQLRelationalExpression(ctx));
		break ;
	case ICommandData::__SQLSubExpression:
		element = (new(ctx) SQLSubExpression(ctx));
		break ;
	case ICommandData::__SQLExpressionList:
		element = (new(ctx) SQLExpressionList(ctx));
		break ;
	case ICommandData::__SQLExpressionListAll:
		element = (new(ctx) SQLExpressionListAll(ctx));
		break ;
	case ICommandData::__SQLExpressionStream:
		element = (new(ctx) SQLExpressionStream(ctx));
		break ;
	case ICommandData::__SQLFrom:
		element = (new(ctx) SQLFrom(ctx));
		break ;
	case ICommandData::__SQLGroupBy:
		element = (new(ctx) SQLGroupBy(ctx));
		break ;
	case ICommandData::__UpdateSet:
		element = (new(ctx) UpdateSet(ctx));
		break ;
	case ICommandData::__IncludePreprocessor:
		element = (new(ctx) IncludePreprocessor(ctx));
		break ;
	case ICommandData::__AssignmentStatement:
		element = (new(ctx) AssignmentStatement(ctx));
		break ;
	case ICommandData::__BreakStatement:
		element = (new(ctx) BreakStatement(ctx));
		break ;
	case ICommandData::__CaseStatement:
		element = (new(ctx) CaseStatement(ctx));
		break ;
	case ICommandData::__DefaultStatement:
		element = (new(ctx) DefaultStatement(ctx));
		break ;
	case ICommandData::__CatchBlock:
		element = (new(ctx) CatchBlock(ctx));
		break ;
	case ICommandData::__ContinueStatement:
		element = (new(ctx) ContinueStatement(ctx));
		break ;
	case ICommandData::__DoWhileStatement:
		element = (new(ctx) DoWhileStatement(ctx));
		break ;
	case ICommandData::__ExpressionStatement:
		element = (new(ctx) ExpressionStatement(ctx));
		break ;
	case ICommandData::__FinallyBlock:
		element = (new(ctx) FinallyBlock(ctx));
		break ;
	case ICommandData::__ForStatement:
		element = (new(ctx) ForStatement(ctx));
		break ;
	case ICommandData::__ForUpdatePart:
		element = (new(ctx) ForUpdatePart(ctx));
		break ;
	case ICommandData::__IfStatement:
		element = (new(ctx) IfStatement(ctx));
		break ;
	case ICommandData::__LabeledStatement:
		element = (new(ctx) LabeledStatement(ctx));
		break ;
	case ICommandData::__ReturnStatement:
		element = (new(ctx) ReturnStatement(ctx));
		break ;
	case ICommandData::__StatementBlock:
		element = (new(ctx) StatementBlock(ctx));
		break ;
	case ICommandData::__StatementList:
		element = (new(ctx) StatementList(ctx));
		break ;
	case ICommandData::__SwitchCasePart:
		element = (new(ctx) SwitchCasePart(ctx));
		break ;
	case ICommandData::__SwitchStatement:
		element = (new(ctx) SwitchStatement(ctx));
		break ;
	case ICommandData::__ThrowStatement:
		element = (new(ctx) ThrowStatement(ctx));
		break ;
	case ICommandData::__TryBlock:
		element = (new(ctx) TryBlock(ctx));
		break ;
	case ICommandData::__TypedVariableDeclare:
		element = (new(ctx) TypedVariableDeclare(ctx));
		break ;
	case ICommandData::__WhileStatement:
		element = (new(ctx) WhileStatement(ctx));
		break ;
	case ICommandData::__BeginStatement:
		element = (new(ctx) BeginStatement(ctx));
		break ;
	case ICommandData::__CommitStatement:
		element = (new(ctx) CommitStatement(ctx));
		break ;
	case ICommandData::__CreateIndexStatement:
		element = (new(ctx) CreateIndexStatement(ctx));
		break ;
	case ICommandData::__CreateTableStatement:
		element = (new(ctx) CreateTableStatement(ctx));
		break ;
	case ICommandData::__DeleteStatement:
		element = (new(ctx) DeleteStatement(ctx));
		break ;
	case ICommandData::__DropIndexStatement:
		element = (new(ctx) DropIndexStatement(ctx));
		break ;
	case ICommandData::__DropTableStatement:
		element = (new(ctx) DropTableStatement(ctx));
		break ;
	case ICommandData::__InsertStatement:
		element = (new(ctx) InsertStatement(ctx));
		break ;
	case ICommandData::__RollbackStatement:
		element = (new(ctx) RollbackStatement(ctx));
		break ;
	case ICommandData::__UpdateStatement:
		element = (new(ctx) UpdateStatement(ctx));
		break ;
	case ICommandData::__InnerJoin:
		element = (new(ctx) InnerJoin(ctx));
		break ;
	case ICommandData::__CrossJoin:
		element = (new(ctx) CrossJoin(ctx));
		break ;
	case ICommandData::__RightJoin:
		element = (new(ctx) RightJoin(ctx));
		break ;
	case ICommandData::__NaturalJoin:
		element = (new(ctx) NaturalJoin(ctx));
		break ;
	case ICommandData::__DomVariableJoinTarget:
		element = (new(ctx) DomVariableJoinTarget(ctx));
		break ;
	case ICommandData::__JoinSubQueryTarget:
		element = (new(ctx) JoinSubQueryTarget(ctx));
		break ;
	case ICommandData::__TableJoinTarget:
		element = (new(ctx) TableJoinTarget(ctx));
		break ;
	case ICommandData::__WrappedJoinTarget:
		element = (new(ctx) WrappedJoinTarget(ctx));
		break ;
	case ICommandData::__SelectStatement:
		element = (new(ctx) SelectStatement(ctx));
		break ;
	case ICommandData::__TableList:
		element = (new(ctx) TableList(ctx));
		break ;
	case ICommandData::__PrimaryKeys:
		element = (new(ctx) PrimaryKeys(ctx));
		break ;
	case ICommandData::__SQLLimitOffset:
		element = (new(ctx) SQLLimitOffset(ctx));
		break ;
	case ICommandData::__SQLWhere:
		element = (new(ctx) SQLWhere(ctx));
		break ;
	case ICommandData::__Unique:
		element = (new(ctx) Unique(ctx));
		break ;
	case ICommandData::__AlinousModule:
		element = (new(ctx) AlinousModule(ctx));
		break ;
	case ICommandData::__NotExpression:
		element = (new(ctx) NotExpression(ctx));
		break ;
	case ICommandData::__AlinousModulePackage:
		element = (new(ctx) AlinousModulePackage(ctx));
		break ;
	case ICommandData::__VirtualTable:
		element = (new(ctx) VirtualTable(ctx));
		break ;
	case ICommandData::__LeftJoin:
		element = (new(ctx) LeftJoin(ctx));
		break ;
	case ICommandData::__ShardKeys:
		element = (new(ctx) ShardKeys(ctx));
		break ;
	case ICommandData::__SubShardKeys:
		element = (new(ctx) SubShardKeys(ctx));
		break ;
	default:
		return nullptr;
		break;
	}
	element->readData(buff, ctx);
	return element;
}
}}

