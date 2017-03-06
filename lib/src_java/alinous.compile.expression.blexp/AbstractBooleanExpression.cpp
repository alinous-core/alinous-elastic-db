#include "include/global.h"


#include "alinous.buffer.storage/FileStorageEntryBuilder.h"
#include "alinous.buffer.storage/FileStorageEntryFetcher.h"
#include "alinous.compile/IAlinousElementVisitor.h"
#include "alinous.compile/IAlinousVisitorContainer.h"
#include "alinous.compile/ExpressionSourceId.h"
#include "alinous.system/AlinousException.h"
#include "alinous.runtime/ExecutionException.h"
#include "alinous.runtime.dom/VariableException.h"
#include "alinous.remote.socket/NetworkBinaryBuffer.h"
#include "alinous.remote.socket/ICommandData.h"
#include "alinous.runtime.dom/IAlinousVariable.h"
#include "alinous.compile/AbstractSrcElement.h"
#include "alinous.compile/IAlinousElement.h"
#include "alinous.compile.declare/IDeclare.h"
#include "alinous.compile.declare.function/AlinousFunction.h"
#include "alinous.runtime.engine/ScriptMachine.h"
#include "alinous.compile.expression/IExpression.h"
#include "alinous.compile.analyse/AlinousType.h"
#include "alinous.compile.declare/AlinousName.h"
#include "alinous.compile.analyse/SrcAnalyseContext.h"
#include "alinous.compile.declare/ClassMemberModifiers.h"
#include "alinous.compile.declare/IClassMember.h"
#include "alinous.compile.declare/AbstractClassMember.h"
#include "alinous.compile.declare/ClassMethodFunction.h"
#include "alinous.compile.declare/AlinousClass.h"
#include "alinous.compile/Token.h"
#include "alinous.compile.expression/AbstractExpression.h"
#include "alinous.compile.expression.blexp/AbstractBooleanExpression.h"
#include "alinous.compile.expression.blexp/NotExpression.h"
#include "alinous.compile.expression.blexp/BooleanSubExpression.h"
#include "alinous.compile.expression.blexp/AbstractBooleanCollectionExpression.h"
#include "alinous.compile.expression.blexp/InclusiveOrExpression.h"
#include "alinous.compile.expression.blexp/RelationalExpression.h"
#include "alinous.compile.expression.blexp/ExclusiveOrExpression.h"
#include "alinous.compile.expression.blexp/InstanceOfExpression.h"
#include "alinous.compile.expression.blexp/ConditionalOrExpression.h"
#include "alinous.compile.expression.blexp/EqualityExpression.h"
#include "alinous.compile.expression.blexp/ConditionalAndExpression.h"
#include "alinous.compile.expression.blexp/AndExpression.h"

namespace alinous {namespace compile {namespace expression {namespace blexp {





constexpr const int AbstractBooleanExpression::CONDITIONAL_OR;
constexpr const int AbstractBooleanExpression::CONDITIONAL_AND;
constexpr const int AbstractBooleanExpression::INCLUSIVE_OR;
constexpr const int AbstractBooleanExpression::INCLUSIVE_AND;
constexpr const int AbstractBooleanExpression::EXCUSIVE_OR;
bool AbstractBooleanExpression::__init_done = __init_static_variables();
bool AbstractBooleanExpression::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"AbstractBooleanExpression", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 AbstractBooleanExpression::AbstractBooleanExpression(ThreadContext* ctx) throw()  : IObject(ctx), AbstractExpression(ctx)
{
}
void AbstractBooleanExpression::__construct_impl(ThreadContext* ctx) throw() 
{
}
 AbstractBooleanExpression::~AbstractBooleanExpression() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void AbstractBooleanExpression::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
	AbstractExpression::__releaseRegerences(true, ctx);
}
bool AbstractBooleanExpression::isSQLExp(ThreadContext* ctx) throw() 
{
	return false;
}
int AbstractBooleanExpression::operatorFromString(String* opStr, ThreadContext* ctx) throw() 
{
	if(opStr->equals(ConstStr::getCNST_STR_1013(), ctx))
	{
		return AbstractBooleanExpression::CONDITIONAL_OR;
	}
		else 
	{
		if(opStr->equals(ConstStr::getCNST_STR_1014(), ctx))
		{
			return AbstractBooleanExpression::CONDITIONAL_AND;
		}
				else 
		{
			if(opStr->equals(ConstStr::getCNST_STR_77(), ctx))
			{
				return AbstractBooleanExpression::INCLUSIVE_OR;
			}
						else 
			{
				if(opStr->equals(ConstStr::getCNST_STR_1015(), ctx))
				{
					return AbstractBooleanExpression::INCLUSIVE_AND;
				}
								else 
				{
					if(opStr->equals(ConstStr::getCNST_STR_1016(), ctx))
					{
						return AbstractBooleanExpression::EXCUSIVE_OR;
					}
				}
			}
		}
	}
	return -1;
}
void AbstractBooleanExpression::__cleanUp(ThreadContext* ctx){
}
}}}}

