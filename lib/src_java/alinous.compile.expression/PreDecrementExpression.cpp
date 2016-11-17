#include "includes.h"


namespace alinous {namespace compile {namespace expression {





bool PreDecrementExpression::__init_done = __init_static_variables();
bool PreDecrementExpression::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"PreDecrementExpression", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 PreDecrementExpression::~PreDecrementExpression() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void PreDecrementExpression::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"PreDecrementExpression", L"~PreDecrementExpression");
	__e_obj1.add(this->exp, this);
	exp = nullptr;
	if(!prepare){
		return;
	}
	AbstractExpression::__releaseRegerences(true, ctx);
}
bool PreDecrementExpression::visit(IAlinousElementVisitor* visitor, AbstractSrcElement* parent, ThreadContext* ctx) throw() 
{
	if(!visitor->visit(this, parent, ctx))
	{
		return false;
	}
	if(this->exp != nullptr && !this->exp->visit(visitor, this, ctx))
	{
		return false;
	}
	return true;
}
bool PreDecrementExpression::analyse(SrcAnalyseContext* context, bool leftValue, ThreadContext* ctx) throw() 
{
	if(this->exp != nullptr)
	{
		return this->exp->analyse(context, leftValue, ctx);
	}
	return true;
}
IExpression* PreDecrementExpression::getExp(ThreadContext* ctx) throw() 
{
	return exp;
}
void PreDecrementExpression::setExp(IExpression* exp, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->exp), exp, IExpression);
}
bool PreDecrementExpression::isConstant(ThreadContext* ctx) throw() 
{
	if(this->exp != nullptr && !this->exp->isConstant(ctx))
	{
		return false;
	}
	return true;
}
IAlinousVariable* PreDecrementExpression::resolveExpression(ScriptMachine* machine, bool debug, ThreadContext* ctx)
{
	IAlinousVariable* variable = machine->resolveExpression(this->exp, debug, ctx);
	if(variable == nullptr || variable->isArray(ctx))
	{
		throw (new(ctx) VariableException(ConstStr::getCNST_STR_973(), ctx));
	}
	if(variable->isNull(ctx))
	{
		throw (new(ctx) AlinousNullPointerException(ctx));
	}
	IntegerVariable* operand = (new(ctx) IntegerVariable(1, ctx));
	IAlinousVariable* val = variable->minus(operand, ctx);
	variable->substitute(val, ctx);
	return variable;
}
ExpressionSourceId* PreDecrementExpression::getSourceId(ThreadContext* ctx) throw() 
{
	return (new(ctx) ExpressionSourceId(nullptr, this, this->exp->getSourceId(ctx)->getType(ctx), ctx));
}
bool PreDecrementExpression::isSQLExp(ThreadContext* ctx) throw() 
{
	return false;
}
int PreDecrementExpression::getExpressionType(ThreadContext* ctx) throw() 
{
	return IExpression::preDecrementExpression;
}
}}}

