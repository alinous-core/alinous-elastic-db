#include "include/global.h"


#include "alinous.remote.socket/NetworkBinaryBuffer.h"
#include "alinous.lock/LockObject.h"
#include "alinous.runtime.parallel/ThreadPool.h"
#include "alinous.compile/AbstractSrcElement.h"
#include "alinous.system/AlinousException.h"
#include "alinous.system/ISystemLog.h"
#include "alinous.remote.socket/ISocketActionFactory.h"
#include "alinous.remote.socket/SocketServer.h"
#include "alinous.remote.socket/ISocketConnection.h"
#include "alinous.remote.socket/ISocketConnectionFactory.h"
#include "alinous.remote.socket/SocketConnectionPool.h"
#include "alinous.remote.socket/NetworkBinalyUtils.h"
#include "alinous.remote.socket/ICommandData.h"
#include "alinous.runtime.dom/IAlinousVariable.h"
#include "alinous.runtime.dom/NetworkAlinousVariableFactory.h"
#include "alinous.runtime/ExecutionException.h"
#include "alinous.runtime.dom/VariableException.h"

namespace alinous {namespace remote {namespace socket {




constexpr const int ICommandData::__IdentifierVariable;
constexpr const int ICommandData::__VariantValue;
constexpr const int ICommandData::__DocumentVariable;
constexpr const int ICommandData::__DomArray;
constexpr const int ICommandData::__DomVariable;
constexpr const int ICommandData::__BigDecimalVariable;
constexpr const int ICommandData::__BoolVariable;
constexpr const int ICommandData::__ByteVariable;
constexpr const int ICommandData::__CharVariable;
constexpr const int ICommandData::__DoubleVariable;
constexpr const int ICommandData::__FloatVariable;
constexpr const int ICommandData::__IntegerVariable;
constexpr const int ICommandData::__LongVariable;
constexpr const int ICommandData::__ShortVariable;
constexpr const int ICommandData::__StringVariable;
constexpr const int ICommandData::__TimestampVariable;
constexpr const int ICommandData::__TimeVariable;
constexpr const int ICommandData::__TypedVariableArray;
constexpr const int ICommandData::__AlinousClassVariable;
constexpr const int ICommandData::__AlinousName;
constexpr const int ICommandData::__AlinousSrc;
constexpr const int ICommandData::__CheckDefinition;
constexpr const int ICommandData::__ColumnTypeDescriptor;
constexpr const int ICommandData::__DdlColumnDescriptor;
constexpr const int ICommandData::__AlinousClass;
constexpr const int ICommandData::__AlinousFunction;
constexpr const int ICommandData::__ClassExtends;
constexpr const int ICommandData::__ClassImplements;
constexpr const int ICommandData::__ClassMemberModifiers;
constexpr const int ICommandData::__FunctionArgumentDefine;
constexpr const int ICommandData::__FunctionArgumentsListDefine;
constexpr const int ICommandData::__ClassMemberVariable;
constexpr const int ICommandData::__ClassMethodFunction;
constexpr const int ICommandData::__ReturnValueDefinition;
constexpr const int ICommandData::__ThrowsDefine;
constexpr const int ICommandData::__DomIndexSegment;
constexpr const int ICommandData::__DomNameSegment;
constexpr const int ICommandData::__AndExpression;
constexpr const int ICommandData::__ConditionalAndExpression;
constexpr const int ICommandData::__ConditionalOrExpression;
constexpr const int ICommandData::__ExclusiveOrExpression;
constexpr const int ICommandData::__InclusiveOrExpression;
constexpr const int ICommandData::__EqualityExpression;
constexpr const int ICommandData::__InstanceOfExpression;
constexpr const int ICommandData::__RelationalExpression;
constexpr const int ICommandData::__AdditiveExpression;
constexpr const int ICommandData::__MultiplicativeExpression;
constexpr const int ICommandData::__ShiftExpression;
constexpr const int ICommandData::__AllocationExpression;
constexpr const int ICommandData::__BitReverseExpression;
constexpr const int ICommandData::__BooleanSubExpression;
constexpr const int ICommandData::__CastExpression;
constexpr const int ICommandData::__ConditionalExpression;
constexpr const int ICommandData::__ExpStreamCast;
constexpr const int ICommandData::__ExpStreamParenthesis;
constexpr const int ICommandData::__ExpStreamSegment;
constexpr const int ICommandData::__FunctionArguments;
constexpr const int ICommandData::__FunctionCallExpression;
constexpr const int ICommandData::__Literal;
constexpr const int ICommandData::__BooleanLiteral;
constexpr const int ICommandData::__NullLiteral;
constexpr const int ICommandData::__ParenthesisExpression;
constexpr const int ICommandData::__PreDecrementExpression;
constexpr const int ICommandData::__PreIncrementExpression;
constexpr const int ICommandData::__SubExpression;
constexpr const int ICommandData::__UnaryExpression;
constexpr const int ICommandData::__DomVariableDescriptor;
constexpr const int ICommandData::__ExpressionStream;
constexpr const int ICommandData::__SQLAdditiveExpression;
constexpr const int ICommandData::__SQLMultiplicativeExpression;
constexpr const int ICommandData::__SQLSubqueryExpression;
constexpr const int ICommandData::__SQLColumnIdentifier;
constexpr const int ICommandData::__SQLLiteral;
constexpr const int ICommandData::__SQLParenthesisExpression;
constexpr const int ICommandData::__InsertValues;
constexpr const int ICommandData::__SQLAndExpression;
constexpr const int ICommandData::__SQLOrExpression;
constexpr const int ICommandData::__SQLBooleanLiteral;
constexpr const int ICommandData::__SQLBoolSubExpression;
constexpr const int ICommandData::__SQLEqualityExpression;
constexpr const int ICommandData::__SQLInExpression;
constexpr const int ICommandData::__SQLIsNullExpression;
constexpr const int ICommandData::__SQLJoinCondition;
constexpr const int ICommandData::__SQLLikeExpression;
constexpr const int ICommandData::__SQLNotExpression;
constexpr const int ICommandData::__SQLRelationalExpression;
constexpr const int ICommandData::__SQLSubExpression;
constexpr const int ICommandData::__SQLExpressionList;
constexpr const int ICommandData::__SQLExpressionListAll;
constexpr const int ICommandData::__SQLExpressionStream;
constexpr const int ICommandData::__SQLFrom;
constexpr const int ICommandData::__SQLGroupBy;
constexpr const int ICommandData::__UpdateSet;
constexpr const int ICommandData::__IncludePreprocessor;
constexpr const int ICommandData::__AssignmentStatement;
constexpr const int ICommandData::__BreakStatement;
constexpr const int ICommandData::__CaseStatement;
constexpr const int ICommandData::__DefaultStatement;
constexpr const int ICommandData::__CatchBlock;
constexpr const int ICommandData::__ContinueStatement;
constexpr const int ICommandData::__DoWhileStatement;
constexpr const int ICommandData::__ExpressionStatement;
constexpr const int ICommandData::__FinallyBlock;
constexpr const int ICommandData::__ForStatement;
constexpr const int ICommandData::__ForUpdatePart;
constexpr const int ICommandData::__IfStatement;
constexpr const int ICommandData::__LabeledStatement;
constexpr const int ICommandData::__ReturnStatement;
constexpr const int ICommandData::__StatementBlock;
constexpr const int ICommandData::__StatementList;
constexpr const int ICommandData::__SwitchCasePart;
constexpr const int ICommandData::__SwitchStatement;
constexpr const int ICommandData::__ThrowStatement;
constexpr const int ICommandData::__TryBlock;
constexpr const int ICommandData::__TypedVariableDeclare;
constexpr const int ICommandData::__WhileStatement;
constexpr const int ICommandData::__BeginStatement;
constexpr const int ICommandData::__CommitStatement;
constexpr const int ICommandData::__CreateIndexStatement;
constexpr const int ICommandData::__CreateTableStatement;
constexpr const int ICommandData::__DeleteStatement;
constexpr const int ICommandData::__DropIndexStatement;
constexpr const int ICommandData::__DropTableStatement;
constexpr const int ICommandData::__InsertStatement;
constexpr const int ICommandData::__RollbackStatement;
constexpr const int ICommandData::__UpdateStatement;
constexpr const int ICommandData::__InnerJoin;
constexpr const int ICommandData::__CrossJoin;
constexpr const int ICommandData::__RightJoin;
constexpr const int ICommandData::__NaturalJoin;
constexpr const int ICommandData::__DomVariableJoinTarget;
constexpr const int ICommandData::__JoinSubQueryTarget;
constexpr const int ICommandData::__TableJoinTarget;
constexpr const int ICommandData::__WrappedJoinTarget;
constexpr const int ICommandData::__SelectStatement;
constexpr const int ICommandData::__TableList;
constexpr const int ICommandData::__PrimaryKeys;
constexpr const int ICommandData::__SQLLimitOffset;
constexpr const int ICommandData::__SQLWhere;
constexpr const int ICommandData::__Unique;
constexpr const int ICommandData::__AlinousModule;
constexpr const int ICommandData::__NotExpression;
constexpr const int ICommandData::__AlinousModulePackage;
constexpr const int ICommandData::__VirtualTable;
constexpr const int ICommandData::__LeftJoin;
constexpr const int ICommandData::__ShardKeys;
constexpr const int ICommandData::__SubShardKeys;
bool ICommandData::__init_done = __init_static_variables();
bool ICommandData::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"ICommandData", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 ICommandData::ICommandData(ThreadContext* ctx) throw()  : IObject(ctx)
{
}
void ICommandData::__construct_impl(ThreadContext* ctx) throw() 
{
}
 ICommandData::~ICommandData() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void ICommandData::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
}
void ICommandData::__cleanUp(ThreadContext* ctx){
}
}}}

