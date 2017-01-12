#include "includes.h"


namespace alinous {namespace compile {namespace expression {





bool ConditionalExpression::__init_done = __init_static_variables();
bool ConditionalExpression::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"ConditionalExpression", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 ConditionalExpression::~ConditionalExpression() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void ConditionalExpression::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"ConditionalExpression", L"~ConditionalExpression");
	__e_obj1.add(this->first, this);
	first = nullptr;
	__e_obj1.add(this->exp, this);
	exp = nullptr;
	__e_obj1.add(this->altexp, this);
	altexp = nullptr;
	if(!prepare){
		return;
	}
	AbstractExpression::__releaseRegerences(true, ctx);
}
bool ConditionalExpression::visit(IAlinousElementVisitor* visitor, AbstractSrcElement* parent, ThreadContext* ctx) throw() 
{
	if(!visitor->visit(this, parent, ctx))
	{
		return false;
	}
	if(first != nullptr && !first->visit(visitor, parent, ctx))
	{
		return false;
	}
	if(exp != nullptr && !exp->visit(visitor, parent, ctx))
	{
		return false;
	}
	if(altexp != nullptr && !altexp->visit(visitor, parent, ctx))
	{
		return false;
	}
	return true;
}
bool ConditionalExpression::isConstant(ThreadContext* ctx) throw() 
{
	if(first != nullptr && !first->isConstant(ctx))
	{
		return false;
	}
	if(exp != nullptr && !exp->isConstant(ctx))
	{
		return false;
	}
	if(altexp != nullptr && !altexp->isConstant(ctx))
	{
		return false;
	}
	return true;
}
bool ConditionalExpression::analyse(SrcAnalyseContext* context, bool leftValue, ThreadContext* ctx) throw() 
{
	if(first != nullptr)
	{
		first->analyse(context, leftValue, ctx);
	}
	if(exp != nullptr)
	{
		exp->analyse(context, leftValue, ctx);
	}
	if(exp != nullptr)
	{
		exp->analyse(context, leftValue, ctx);
	}
	return true;
}
IExpression* ConditionalExpression::getFirst(ThreadContext* ctx) throw() 
{
	return first;
}
void ConditionalExpression::setFirst(IExpression* first, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->first), first, IExpression);
}
IExpression* ConditionalExpression::getExp(ThreadContext* ctx) throw() 
{
	return exp;
}
void ConditionalExpression::setExp(IExpression* exp, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->exp), exp, IExpression);
}
IExpression* ConditionalExpression::getAltexp(ThreadContext* ctx) throw() 
{
	return altexp;
}
void ConditionalExpression::setAltexp(IExpression* altexp, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->altexp), altexp, IExpression);
}
IAlinousVariable* ConditionalExpression::resolveExpression(ScriptMachine* machine, bool debug, ThreadContext* ctx)
{
	IAlinousVariable* condition = machine->resolveExpression(this->first, debug, ctx);
	if(condition->isTrue(ctx))
	{
		return machine->resolveExpression(this->exp, debug, ctx);
	}
	return machine->resolveExpression(this->altexp, debug, ctx);
}
ExpressionSourceId* ConditionalExpression::getSourceId(ThreadContext* ctx) throw() 
{
	AlinousType* type = this->exp->getSourceId(ctx)->getType(ctx);
	AlinousType* type2 = this->exp->getSourceId(ctx)->getType(ctx);
	if(type->getType(ctx) < type2->getType(ctx))
	{
		type = type2;
	}
	return (new(ctx) ExpressionSourceId(nullptr, this, type, ctx));
}
bool ConditionalExpression::isSQLExp(ThreadContext* ctx) throw() 
{
	return false;
}
int ConditionalExpression::getExpressionType(ThreadContext* ctx) throw() 
{
	return IExpression::conditionalExpression;
}
void ConditionalExpression::readData(NetworkBinaryBuffer* buff, ThreadContext* ctx)
{
	bool isnull = buff->getBoolean(ctx);
	if(!isnull)
	{
		IAlinousElement* el = AlinousElementNetworkFactory::formNetworkData(buff, ctx);
		if(el == nullptr || !((dynamic_cast<IExpression*>(el) != 0)))
		{
			throw (new(ctx) VariableException(ConstStr::getCNST_STR_980(), ctx));
		}
		__GC_MV(this, &(this->first), static_cast<IExpression*>(el), IExpression);
	}
	isnull = buff->getBoolean(ctx);
	if(!isnull)
	{
		IAlinousElement* el = AlinousElementNetworkFactory::formNetworkData(buff, ctx);
		if(el == nullptr || !((dynamic_cast<IExpression*>(el) != 0)))
		{
			throw (new(ctx) VariableException(ConstStr::getCNST_STR_980(), ctx));
		}
		__GC_MV(this, &(this->exp), static_cast<IExpression*>(el), IExpression);
	}
	isnull = buff->getBoolean(ctx);
	if(!isnull)
	{
		IAlinousElement* el = AlinousElementNetworkFactory::formNetworkData(buff, ctx);
		if(el == nullptr || !((dynamic_cast<IExpression*>(el) != 0)))
		{
			throw (new(ctx) VariableException(ConstStr::getCNST_STR_980(), ctx));
		}
		__GC_MV(this, &(this->altexp), static_cast<IExpression*>(el), IExpression);
	}
}
void ConditionalExpression::writeData(NetworkBinaryBuffer* buff, ThreadContext* ctx) throw() 
{
	buff->putInt(ICommandData::__ConditionalExpression, ctx);
	bool isnull = (this->first == nullptr);
	buff->putBoolean(isnull, ctx);
	if(!isnull)
	{
		this->first->writeData(buff, ctx);
	}
	isnull = (this->exp == nullptr);
	buff->putBoolean(isnull, ctx);
	if(!isnull)
	{
		this->exp->writeData(buff, ctx);
	}
	isnull = (this->altexp == nullptr);
	buff->putBoolean(isnull, ctx);
	if(!isnull)
	{
		this->altexp->writeData(buff, ctx);
	}
}
}}}

