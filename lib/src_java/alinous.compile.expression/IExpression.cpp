#include "include/global.h"


#include "alinous.buffer.storage/FileStorageEntryBuilder.h"
#include "alinous.buffer.storage/FileStorageEntryFetcher.h"
#include "alinous.compile/IAlinousElementVisitor.h"
#include "alinous.compile/IAlinousVisitorContainer.h"
#include "alinous.compile/ExpressionSourceId.h"
#include "alinous.db.table/DatabaseException.h"
#include "alinous.system/AlinousException.h"
#include "alinous.runtime/ExecutionException.h"
#include "alinous.runtime.dom/VariableException.h"
#include "alinous.remote.socket/NetworkBinaryBuffer.h"
#include "alinous.remote.socket/ICommandData.h"
#include "alinous.runtime.dom/IAlinousVariable.h"
#include "alinous.runtime.variant/VariantValue.h"
#include "alinous.compile/AbstractSrcElement.h"
#include "alinous.compile/IAlinousElement.h"
#include "alinous.compile.declare/IDeclare.h"
#include "alinous.compile.declare.function/AlinousFunction.h"
#include "alinous.compile/Token.h"
#include "alinous.compile.expression/IDomSegment.h"
#include "alinous.compile.expression/DomIndexSegment.h"
#include "alinous.compile.expression/DomNameSegment.h"
#include "alinous.runtime.engine/ScriptMachine.h"
#include "alinous.compile.expression/IExpression.h"
#include "alinous.compile.analyse/AlinousType.h"
#include "alinous.compile.declare/AlinousName.h"
#include "alinous.compile.analyse/SrcAnalyseContext.h"
#include "alinous.compile.expression/AbstractExpression.h"
#include "alinous.compile.expression/FunctionArguments.h"
#include "alinous.compile.declare/ClassMemberModifiers.h"
#include "alinous.compile.declare/IClassMember.h"
#include "alinous.compile.declare/AbstractClassMember.h"
#include "alinous.compile.declare/ClassMethodFunction.h"
#include "alinous.compile.declare/AlinousClass.h"
#include "alinous.compile.analyse/DomVariableDeclareSource.h"
#include "alinous.compile.expression/DomVariableDescriptor.h"
#include "alinous.compile.expression/Literal.h"
#include "alinous.compile.expression/SubExpression.h"
#include "alinous.compile.expression/AbstractCollectionExpression.h"
#include "alinous.compile.expression/AdditiveExpression.h"
#include "alinous.compile.expression/MultiplicativeExpression.h"
#include "alinous.compile.expression/ShiftExpression.h"
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

namespace alinous {namespace compile {namespace expression {





constexpr const int IExpression::andExpression;
constexpr const int IExpression::conditionalAndExpression;
constexpr const int IExpression::exclusiveOrExpression;
constexpr const int IExpression::inclusiveOrExpression;
constexpr const int IExpression::equalityExpression;
constexpr const int IExpression::instanceOfExpression;
constexpr const int IExpression::notExpression;
constexpr const int IExpression::relationalExpression;
constexpr const int IExpression::additiveExpression;
constexpr const int IExpression::multiplicativeExpression;
constexpr const int IExpression::shiftExpression;
constexpr const int IExpression::allocationExpressionType;
constexpr const int IExpression::bitReverseExpression;
constexpr const int IExpression::booleanSubExpression;
constexpr const int IExpression::castExpression;
constexpr const int IExpression::conditionalExpression;
constexpr const int IExpression::expStreamCast;
constexpr const int IExpression::expStreamParenthesis;
constexpr const int IExpression::expStreamSegment;
constexpr const int IExpression::functionArguments;
constexpr const int IExpression::functionCallExpression;
constexpr const int IExpression::literalType;
constexpr const int IExpression::booleanLiteral;
constexpr const int IExpression::nullLiteral;
constexpr const int IExpression::parenthesisExpression;
constexpr const int IExpression::preDecrementExpression;
constexpr const int IExpression::preIncrementExpression;
constexpr const int IExpression::subExpression;
constexpr const int IExpression::unaryExpression;
constexpr const int IExpression::domVariableDescriptor;
constexpr const int IExpression::expressionStream;
constexpr const int IExpression::sQLAdditiveExpression;
constexpr const int IExpression::sQLMultiplicativeExpression;
constexpr const int IExpression::sQLSubqueryExpression;
constexpr const int IExpression::sQLColumnIdentifier;
constexpr const int IExpression::sQLLiteralType;
constexpr const int IExpression::sQLParenthesisExpression;
constexpr const int IExpression::insertValues;
constexpr const int IExpression::sQLExpressionStream;
constexpr const int IExpression::sQLFrom;
constexpr const int IExpression::sQLGroupBy;
constexpr const int IExpression::updateSet;
constexpr const int IExpression::sQLAndExpression;
constexpr const int IExpression::sQLOrExpression;
constexpr const int IExpression::sQLBooleanLiteral;
constexpr const int IExpression::sQLBoolSubExpression;
constexpr const int IExpression::sQLEqualityExpression;
constexpr const int IExpression::sQLInExpression;
constexpr const int IExpression::sQLIsNullExpression;
constexpr const int IExpression::sQLJoinCondition;
constexpr const int IExpression::sQLLikeExpression;
constexpr const int IExpression::sQLNotExpression;
constexpr const int IExpression::sQLRelationalExpression;
constexpr const int IExpression::sQLSubExpression;
constexpr const int IExpression::sQLExpressionList;
constexpr const int IExpression::sQLExpressionListAll;
bool IExpression::__init_done = __init_static_variables();
bool IExpression::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"IExpression", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 IExpression::IExpression(ThreadContext* ctx) throw()  : IObject(ctx), IAlinousElement(ctx), IAlinousVisitorContainer(ctx)
{
}
void IExpression::__construct_impl(ThreadContext* ctx) throw() 
{
}
 IExpression::~IExpression() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void IExpression::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
	IAlinousElement::__releaseRegerences(true, ctx);
}
void IExpression::__cleanUp(ThreadContext* ctx){
}
}}}

