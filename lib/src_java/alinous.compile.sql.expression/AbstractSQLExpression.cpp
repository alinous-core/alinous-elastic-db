#include "includes.h"


namespace alinous {namespace compile {namespace sql {namespace expression {





constexpr const int AbstractSQLExpression::PLUS;
constexpr const int AbstractSQLExpression::MINUS;
constexpr const int AbstractSQLExpression::MUL;
constexpr const int AbstractSQLExpression::DIV;
constexpr const int AbstractSQLExpression::MOD;
bool AbstractSQLExpression::__init_done = __init_static_variables();
bool AbstractSQLExpression::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"AbstractSQLExpression", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 AbstractSQLExpression::~AbstractSQLExpression() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void AbstractSQLExpression::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"AbstractSQLExpression", L"~AbstractSQLExpression");
	__e_obj1.add(this->asName, this);
	asName = nullptr;
	if(!prepare){
		return;
	}
	ISQLExpression::__releaseRegerences(true, ctx);
}
int AbstractSQLExpression::getLine(ThreadContext* ctx) throw() 
{
	return ISQLExpression::getLine(ctx);
}
int AbstractSQLExpression::getStartPosition(ThreadContext* ctx) throw() 
{
	return ISQLExpression::getStartPosition(ctx);
}
int AbstractSQLExpression::getEndLine(ThreadContext* ctx) throw() 
{
	return ISQLExpression::getEndLine(ctx);
}
int AbstractSQLExpression::getEndPosition(ThreadContext* ctx) throw() 
{
	return ISQLExpression::getEndPosition(ctx);
}
AbstractSrcElement* AbstractSQLExpression::getParent(ThreadContext* ctx) throw() 
{
	return ISQLExpression::getParent(ctx);
}
void AbstractSQLExpression::setParent(AbstractSrcElement* parent, ThreadContext* ctx) throw() 
{
	ISQLExpression::setParent(parent, ctx);
}
bool AbstractSQLExpression::isSQLExp(ThreadContext* ctx) throw() 
{
	return true;
}
String* AbstractSQLExpression::getAsName(ThreadContext* ctx) throw() 
{
	return this->asName;
}
void AbstractSQLExpression::setAsName(String* name, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->asName), name, String);
}
int AbstractSQLExpression::operatorFromString(String* opStr, ThreadContext* ctx) throw() 
{
	if(opStr->equals(ConstStr::getCNST_STR_982(), ctx))
	{
		return AbstractBooleanExpression::PLUS;
	}
		else 
	{
		if(opStr->equals(ConstStr::getCNST_STR_98(), ctx))
		{
			return AbstractBooleanExpression::MINUS;
		}
				else 
		{
			if(opStr->equals(ConstStr::getCNST_STR_983(), ctx))
			{
				return AbstractBooleanExpression::MUL;
			}
						else 
			{
				if(opStr->equals(ConstStr::getCNST_STR_984(), ctx))
				{
					return AbstractBooleanExpression::DIV;
				}
								else 
				{
					if(opStr->equals(ConstStr::getCNST_STR_985(), ctx))
					{
						return AbstractBooleanExpression::MOD;
					}
				}
			}
		}
	}
	return -1;
}
}}}}

