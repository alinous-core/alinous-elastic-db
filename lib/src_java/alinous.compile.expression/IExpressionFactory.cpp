#include "include/global.h"


#include "alinous.buffer.storage/FileStorageEntryFetcher.h"
#include "alinous.buffer.storage/FileStorageEntryBuilder.h"
#include "alinous.compile/ExpressionSourceId.h"
#include "alinous.compile/IAlinousElementVisitor.h"
#include "alinous.remote.socket/NetworkBinaryBuffer.h"
#include "alinous.remote.socket/ICommandData.h"
#include "alinous.compile/IAlinousVisitorContainer.h"
#include "alinous.compile/AbstractSrcElement.h"
#include "alinous.compile/IAlinousElement.h"
#include "alinous.compile.declare/IDeclare.h"
#include "alinous.compile.declare/ClassMemberModifiers.h"
#include "alinous.compile.expression/IExpression.h"
#include "alinous.compile.expression/AbstractExpression.h"
#include "alinous.system/AlinousException.h"
#include "alinous.runtime.dom/IAlinousVariable.h"
#include "alinous.runtime.variant/VariantValue.h"
#include "alinous.compile.expression/DomVariableDescriptor.h"
#include "alinous.runtime.engine/ScriptMachine.h"
#include "alinous.compile.expression/FunctionArguments.h"
#include "alinous.compile.expression.expstream/FunctionCallExpression.h"
#include "alinous.compile.declare.function/AlinousFunction.h"
#include "alinous.compile.expression/SubExpression.h"
#include "alinous.compile.expression/AbstractCollectionExpression.h"
#include "alinous.compile.expression/AdditiveExpression.h"
#include "alinous.compile.expression/AllocationExpression.h"
#include "alinous.compile.expression/BitReverseExpression.h"
#include "alinous.compile.expression/Literal.h"
#include "alinous.compile.expression/BooleanLiteral.h"
#include "alinous.compile.expression/CastExpression.h"
#include "alinous.compile.expression/ConditionalExpression.h"
#include "alinous.compile.expression/MultiplicativeExpression.h"
#include "alinous.compile.expression/NullLiteral.h"
#include "alinous.compile.expression/ParenthesisExpression.h"
#include "alinous.compile.expression/PreDecrementExpression.h"
#include "alinous.compile.expression/PreIncrementExpression.h"
#include "alinous.compile.expression/ShiftExpression.h"
#include "alinous.compile.expression/UnaryExpression.h"
#include "alinous.compile.expression.blexp/BooleanSubExpression.h"
#include "alinous.compile.expression.blexp/AbstractBooleanCollectionExpression.h"
#include "alinous.compile.expression.blexp/ConditionalAndExpression.h"
#include "alinous.compile.expression.blexp/ConditionalOrExpression.h"
#include "alinous.compile.expression.blexp/AbstractBooleanExpression.h"
#include "alinous.compile.expression.blexp/EqualityExpression.h"
#include "alinous.compile.expression.blexp/ExclusiveOrExpression.h"
#include "alinous.compile.expression.blexp/InclusiveOrExpression.h"
#include "alinous.compile.expression.blexp/InstanceOfExpression.h"
#include "alinous.compile.expression.blexp/NotExpression.h"
#include "alinous.compile.expression.blexp/RelationalExpression.h"
#include "alinous.compile.expression.expstream/ExpStreamSegment.h"
#include "alinous.compile.expression.expstream/ExpressionStream.h"
#include "alinous.compile.expression.expstream/ExpStreamCast.h"
#include "alinous.compile.expression.expstream/ExpStreamParenthesis.h"
#include "alinous.compile.sql.analyze/ScanTableIdentifier.h"
#include "alinous.compile.sql.analyze/ScanTableColumnIdentifier.h"
#include "alinous.btree/IBTreeValue.h"
#include "alinous.db.trx.scan/ScanResultRecord.h"
#include "alinous.compile.sql.expression/ISQLExpression.h"
#include "alinous.compile.sql.analyze/SQLAnalyseContext.h"
#include "alinous.compile.sql.expression/AbstractSQLExpression.h"
#include "alinous.compile.sql.expression/SQLColumnIdentifier.h"
#include "alinous.compile.sql.expression/SQLExpressionStream.h"
#include "alinous.compile.sql.parts/ISQLExpressionPart.h"
#include "alinous.compile.sql.parts/AbstractExpressionPart.h"
#include "alinous.compile.sql.parts/SQLExpressionList.h"
#include "alinous.compile.sql/InsertValues.h"
#include "alinous.compile.sql/UpdateSet.h"
#include "alinous.compile.sql.analyze/IndexColumnMatchCondition.h"
#include "alinous.compile.sql.expression.blexp/ISQLBoolExpression.h"
#include "alinous.compile.sql.expression.blexp/AbstractSQLBooleanExpression.h"
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
#include "alinous.compile.sql.select/SQLFrom.h"
#include "alinous.compile.sql.select/SQLGroupBy.h"
#include "alinous.compile.sql.select.join/SQLJoinCondition.h"
#include "alinous.compile/AlinousElementNetworkFactory.h"
#include "alinous.compile.declare/IClassMember.h"
#include "alinous.compile.declare/AbstractClassMember.h"
#include "alinous.compile.declare/ClassMethodFunction.h"
#include "alinous.compile/Token.h"
#include "alinous.compile.declare/AlinousClass.h"
#include "alinous.compile.analyse/SrcAnalyseContext.h"
#include "alinous.compile.expression.blexp/AndExpression.h"
#include "alinous.compile.expression/IExpressionFactory.h"

namespace alinous {namespace compile {namespace expression {





constexpr const int IExpressionFactory::__SQLAdditiveExpression;
constexpr const int IExpressionFactory::__SQLMultiplicativeExpression;
constexpr const int IExpressionFactory::__SQLSubqueryExpression;
constexpr const int IExpressionFactory::__SQLColumnIdentifier;
constexpr const int IExpressionFactory::__SQLLiteral;
constexpr const int IExpressionFactory::__SQLParenthesisExpression;
constexpr const int IExpressionFactory::__InsertValues;
constexpr const int IExpressionFactory::__SQLAndExpression;
constexpr const int IExpressionFactory::__SQLOrExpression;
constexpr const int IExpressionFactory::__SQLBooleanLiteral;
constexpr const int IExpressionFactory::__SQLBoolSubExpression;
constexpr const int IExpressionFactory::__SQLEqualityExpression;
constexpr const int IExpressionFactory::__SQLInExpression;
constexpr const int IExpressionFactory::__SQLIsNullExpression;
constexpr const int IExpressionFactory::__SQLJoinCondition;
constexpr const int IExpressionFactory::__SQLLikeExpression;
constexpr const int IExpressionFactory::__SQLNotExpression;
constexpr const int IExpressionFactory::__SQLRelationalExpression;
constexpr const int IExpressionFactory::__SQLSubExpression;
constexpr const int IExpressionFactory::__SQLExpressionList;
constexpr const int IExpressionFactory::__SQLExpressionListAll;
constexpr const int IExpressionFactory::__SQLExpressionStream;
constexpr const int IExpressionFactory::__SQLFrom;
constexpr const int IExpressionFactory::__SQLGroupBy;
constexpr const int IExpressionFactory::__UpdateSet;
constexpr const int IExpressionFactory::__AndExpression;
constexpr const int IExpressionFactory::__ConditionalAndExpression;
constexpr const int IExpressionFactory::__ConditionalOrExpression;
constexpr const int IExpressionFactory::__ExclusiveOrExpression;
constexpr const int IExpressionFactory::__InclusiveOrExpression;
constexpr const int IExpressionFactory::__EqualityExpression;
constexpr const int IExpressionFactory::__InstanceOfExpression;
constexpr const int IExpressionFactory::__NotExpression;
constexpr const int IExpressionFactory::__RelationalExpression;
constexpr const int IExpressionFactory::__AdditiveExpression;
constexpr const int IExpressionFactory::__MultiplicativeExpression;
constexpr const int IExpressionFactory::__ShiftExpression;
constexpr const int IExpressionFactory::__AllocationExpression;
constexpr const int IExpressionFactory::__BitReverseExpression;
constexpr const int IExpressionFactory::__BooleanSubExpression;
constexpr const int IExpressionFactory::__CastExpression;
constexpr const int IExpressionFactory::__ConditionalExpression;
constexpr const int IExpressionFactory::__ExpStreamCast;
constexpr const int IExpressionFactory::__ExpStreamParenthesis;
constexpr const int IExpressionFactory::__ExpStreamSegment;
constexpr const int IExpressionFactory::__FunctionArguments;
constexpr const int IExpressionFactory::__FunctionCallExpression;
constexpr const int IExpressionFactory::__Literal;
constexpr const int IExpressionFactory::__BooleanLiteral;
constexpr const int IExpressionFactory::__NullLiteral;
constexpr const int IExpressionFactory::__ParenthesisExpression;
constexpr const int IExpressionFactory::__PreDecrementExpression;
constexpr const int IExpressionFactory::__PreIncrementExpression;
constexpr const int IExpressionFactory::__SubExpression;
constexpr const int IExpressionFactory::__UnaryExpression;
constexpr const int IExpressionFactory::__DomVariableDescriptor;
constexpr const int IExpressionFactory::__ExpressionStream;
bool IExpressionFactory::__init_done = __init_static_variables();
bool IExpressionFactory::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"IExpressionFactory", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 IExpressionFactory::IExpressionFactory(ThreadContext* ctx) throw()  : IObject(ctx)
{
}
void IExpressionFactory::__construct_impl(ThreadContext* ctx) throw() 
{
}
 IExpressionFactory::~IExpressionFactory() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void IExpressionFactory::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
}
IExpression* IExpressionFactory::fromFetcher(FileStorageEntryFetcher* fetcher, ThreadContext* ctx)
{
	IExpression* exp = nullptr;
	int type = fetcher->fetchInt(ctx);
	switch(type) {
	case __SQLAdditiveExpression:
		exp = (new(ctx) SQLAdditiveExpression(ctx));
		break ;
	case __SQLMultiplicativeExpression:
		exp = (new(ctx) SQLMultiplicativeExpression(ctx));
		break ;
	case __SQLSubqueryExpression:
		exp = (new(ctx) SQLSubqueryExpression(ctx));
		break ;
	case __SQLColumnIdentifier:
		exp = (new(ctx) SQLColumnIdentifier(ctx));
		break ;
	case __SQLLiteral:
		exp = (new(ctx) SQLLiteral(ctx));
		break ;
	case __SQLParenthesisExpression:
		exp = (new(ctx) SQLParenthesisExpression(ctx));
		break ;
	case __InsertValues:
		exp = (new(ctx) InsertValues(ctx));
		break ;
	case __SQLAndExpression:
		exp = (new(ctx) SQLAndExpression(ctx));
		break ;
	case __SQLOrExpression:
		exp = (new(ctx) SQLOrExpression(ctx));
		break ;
	case __SQLBooleanLiteral:
		exp = (new(ctx) SQLBooleanLiteral(ctx));
		break ;
	case __SQLBoolSubExpression:
		exp = (new(ctx) SQLBoolSubExpression(ctx));
		break ;
	case __SQLEqualityExpression:
		exp = (new(ctx) SQLEqualityExpression(ctx));
		break ;
	case __SQLInExpression:
		exp = (new(ctx) SQLInExpression(ctx));
		break ;
	case __SQLIsNullExpression:
		exp = (new(ctx) SQLIsNullExpression(ctx));
		break ;
	case __SQLJoinCondition:
		exp = (new(ctx) SQLJoinCondition(ctx));
		break ;
	case __SQLLikeExpression:
		exp = (new(ctx) SQLLikeExpression(ctx));
		break ;
	case __SQLNotExpression:
		exp = (new(ctx) SQLNotExpression(ctx));
		break ;
	case __SQLRelationalExpression:
		exp = (new(ctx) SQLRelationalExpression(ctx));
		break ;
	case __SQLSubExpression:
		exp = (new(ctx) SQLSubExpression(ctx));
		break ;
	case __SQLExpressionList:
		exp = (new(ctx) SQLExpressionList(ctx));
		break ;
	case __SQLExpressionListAll:
		exp = (new(ctx) SQLExpressionListAll(ctx));
		break ;
	case __SQLExpressionStream:
		exp = (new(ctx) SQLExpressionStream(ctx));
		break ;
	case __SQLFrom:
		exp = (new(ctx) SQLFrom(ctx));
		break ;
	case __SQLGroupBy:
		exp = (new(ctx) SQLGroupBy(ctx));
		break ;
	case __UpdateSet:
		exp = (new(ctx) UpdateSet(ctx));
		break ;
	case __AndExpression:
		exp = (new(ctx) AndExpression(ctx));
		break ;
	case __ConditionalAndExpression:
		exp = (new(ctx) ConditionalAndExpression(ctx));
		break ;
	case __ConditionalOrExpression:
		exp = (new(ctx) ConditionalOrExpression(ctx));
		break ;
	case __ExclusiveOrExpression:
		exp = (new(ctx) ExclusiveOrExpression(ctx));
		break ;
	case __InclusiveOrExpression:
		exp = (new(ctx) InclusiveOrExpression(ctx));
		break ;
	case __EqualityExpression:
		exp = (new(ctx) EqualityExpression(ctx));
		break ;
	case __InstanceOfExpression:
		exp = (new(ctx) InstanceOfExpression(ctx));
		break ;
	case __NotExpression:
		exp = (new(ctx) NotExpression(ctx));
		break ;
	case __RelationalExpression:
		exp = (new(ctx) RelationalExpression(ctx));
		break ;
	case __AdditiveExpression:
		exp = (new(ctx) AdditiveExpression(ctx));
		break ;
	case __MultiplicativeExpression:
		exp = (new(ctx) MultiplicativeExpression(ctx));
		break ;
	case __ShiftExpression:
		exp = (new(ctx) ShiftExpression(ctx));
		break ;
	case __AllocationExpression:
		exp = (new(ctx) AllocationExpression(ctx));
		break ;
	case __BitReverseExpression:
		exp = (new(ctx) BitReverseExpression(ctx));
		break ;
	case __BooleanSubExpression:
		exp = (new(ctx) BooleanSubExpression(ctx));
		break ;
	case __CastExpression:
		exp = (new(ctx) CastExpression(ctx));
		break ;
	case __ConditionalExpression:
		exp = (new(ctx) ConditionalExpression(ctx));
		break ;
	case __ExpStreamCast:
		exp = (new(ctx) ExpStreamCast(ctx));
		break ;
	case __ExpStreamParenthesis:
		exp = (new(ctx) ExpStreamParenthesis(ctx));
		break ;
	case __ExpStreamSegment:
		exp = (new(ctx) ExpStreamSegment(ctx));
		break ;
	case __FunctionArguments:
		exp = (new(ctx) FunctionArguments(ctx));
		break ;
	case __FunctionCallExpression:
		exp = (new(ctx) FunctionCallExpression(ctx));
		break ;
	case __Literal:
		exp = (new(ctx) Literal(ctx));
		break ;
	case __BooleanLiteral:
		exp = (new(ctx) BooleanLiteral(ctx));
		break ;
	case __NullLiteral:
		exp = (new(ctx) NullLiteral(ctx));
		break ;
	case __ParenthesisExpression:
		exp = (new(ctx) ParenthesisExpression(ctx));
		break ;
	case __PreDecrementExpression:
		exp = (new(ctx) PreDecrementExpression(ctx));
		break ;
	case __PreIncrementExpression:
		exp = (new(ctx) PreIncrementExpression(ctx));
		break ;
	case __SubExpression:
		exp = (new(ctx) SubExpression(ctx));
		break ;
	case __UnaryExpression:
		exp = (new(ctx) UnaryExpression(ctx));
		break ;
	case __DomVariableDescriptor:
		exp = (new(ctx) DomVariableDescriptor(ctx));
		break ;
	case __ExpressionStream:
		exp = (new(ctx) ExpressionStream(ctx));
		break ;
	default:
		return nullptr;
		break;
	}
	exp->fromFileEntry(fetcher, ctx);
	return exp;
}
void IExpressionFactory::__cleanUp(ThreadContext* ctx){
}
}}}

