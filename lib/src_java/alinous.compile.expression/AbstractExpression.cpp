#include "includes.h"


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
	if(opStr->equals(ConstStr::getCNST_STR_979(), ctx))
	{
		return AbstractExpression::SHIFT_LEFT;
	}
		else 
	{
		if(opStr->equals(ConstStr::getCNST_STR_980(), ctx))
		{
			return AbstractExpression::SHIFT_RIGHT;
		}
				else 
		{
			if(opStr->equals(ConstStr::getCNST_STR_981(), ctx))
			{
				return AbstractExpression::SHIFT_RIGHT_UNSIGNED;
			}
						else 
			{
				if(opStr->equals(ConstStr::getCNST_STR_982(), ctx))
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
						if(opStr->equals(ConstStr::getCNST_STR_983(), ctx))
						{
							return AbstractExpression::MUL;
						}
												else 
						{
							if(opStr->equals(ConstStr::getCNST_STR_984(), ctx))
							{
								return AbstractExpression::DIV;
							}
														else 
							{
								if(opStr->equals(ConstStr::getCNST_STR_985(), ctx))
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
}}}

