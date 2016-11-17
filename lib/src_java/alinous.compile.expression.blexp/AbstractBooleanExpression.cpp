#include "includes.h"


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
	if(opStr->equals(ConstStr::getCNST_STR_989(), ctx))
	{
		return AbstractBooleanExpression::CONDITIONAL_OR;
	}
		else 
	{
		if(opStr->equals(ConstStr::getCNST_STR_990(), ctx))
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
				if(opStr->equals(ConstStr::getCNST_STR_991(), ctx))
				{
					return AbstractBooleanExpression::INCLUSIVE_AND;
				}
								else 
				{
					if(opStr->equals(ConstStr::getCNST_STR_992(), ctx))
					{
						return AbstractBooleanExpression::EXCUSIVE_OR;
					}
				}
			}
		}
	}
	return -1;
}
}}}}

