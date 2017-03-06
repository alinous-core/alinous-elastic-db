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





constexpr const int AbstractExpression::SHIFT_LEFT;
constexpr const int AbstractExpression::SHIFT_RIGHT;
constexpr const int AbstractExpression::SHIFT_RIGHT_UNSIGNED;
constexpr const int AbstractExpression::PLUS;
constexpr const int AbstractExpression::MINUS;
constexpr const int AbstractExpression::MUL;
constexpr const int AbstractExpression::DIV;
constexpr const int AbstractExpression::MOD;
bool AbstractExpression::__init_done = __init_static_variables();
bool AbstractExpression::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"AbstractExpression", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 AbstractExpression::AbstractExpression(ThreadContext* ctx) throw()  : IObject(ctx), IExpression(ctx)
{
}
void AbstractExpression::__construct_impl(ThreadContext* ctx) throw() 
{
}
 AbstractExpression::~AbstractExpression() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void AbstractExpression::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
	IExpression::__releaseRegerences(true, ctx);
}
int AbstractExpression::getLine(ThreadContext* ctx) throw() 
{
	return IExpression::getLine(ctx);
}
int AbstractExpression::getStartPosition(ThreadContext* ctx) throw() 
{
	return IExpression::getStartPosition(ctx);
}
int AbstractExpression::getEndLine(ThreadContext* ctx) throw() 
{
	return IExpression::getEndLine(ctx);
}
int AbstractExpression::getEndPosition(ThreadContext* ctx) throw() 
{
	return IExpression::getEndPosition(ctx);
}
AbstractSrcElement* AbstractExpression::getParent(ThreadContext* ctx) throw() 
{
	return IExpression::getParent(ctx);
}
void AbstractExpression::setParent(AbstractSrcElement* parent, ThreadContext* ctx) throw() 
{
	IExpression::setParent(parent, ctx);
}
bool AbstractExpression::isSQLExp(ThreadContext* ctx) throw() 
{
	return false;
}
int AbstractExpression::operatorFromString(String* opStr, ThreadContext* ctx) throw() 
{
	if(opStr->equals(ConstStr::getCNST_STR_1002(), ctx))
	{
		return AbstractExpression::SHIFT_LEFT;
	}
		else 
	{
		if(opStr->equals(ConstStr::getCNST_STR_1003(), ctx))
		{
			return AbstractExpression::SHIFT_RIGHT;
		}
				else 
		{
			if(opStr->equals(ConstStr::getCNST_STR_1004(), ctx))
			{
				return AbstractExpression::SHIFT_RIGHT_UNSIGNED;
			}
						else 
			{
				if(opStr->equals(ConstStr::getCNST_STR_1005(), ctx))
				{
					return AbstractExpression::PLUS;
				}
								else 
				{
					if(opStr->equals(ConstStr::getCNST_STR_98(), ctx))
					{
						return AbstractExpression::MINUS;
					}
										else 
					{
						if(opStr->equals(ConstStr::getCNST_STR_1006(), ctx))
						{
							return AbstractExpression::MUL;
						}
												else 
						{
							if(opStr->equals(ConstStr::getCNST_STR_1007(), ctx))
							{
								return AbstractExpression::DIV;
							}
														else 
							{
								if(opStr->equals(ConstStr::getCNST_STR_1008(), ctx))
								{
									return AbstractExpression::MOD;
								}
							}
						}
					}
				}
			}
		}
	}
	return -1;
}
void AbstractExpression::__cleanUp(ThreadContext* ctx){
}
}}}

