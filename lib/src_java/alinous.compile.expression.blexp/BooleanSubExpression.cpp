#include "includes.h"


namespace alinous {namespace compile {namespace expression {namespace blexp {





bool BooleanSubExpression::__init_done = __init_static_variables();
bool BooleanSubExpression::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"BooleanSubExpression", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 BooleanSubExpression::BooleanSubExpression(String* op, IExpression* exp, ThreadContext* ctx) throw()  : IObject(ctx), AbstractExpression(ctx), op(0), exp(nullptr)
{
	this->op = AbstractBooleanExpression::operatorFromString(op, ctx);
	__GC_MV(this, &(this->exp), exp, IExpression);
}
void BooleanSubExpression::__construct_impl(String* op, IExpression* exp, ThreadContext* ctx) throw() 
{
	this->op = AbstractBooleanExpression::operatorFromString(op, ctx);
	__GC_MV(this, &(this->exp), exp, IExpression);
}
 BooleanSubExpression::~BooleanSubExpression() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void BooleanSubExpression::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"BooleanSubExpression", L"~BooleanSubExpression");
	__e_obj1.add(this->exp, this);
	exp = nullptr;
	if(!prepare){
		return;
	}
	AbstractExpression::__releaseRegerences(true, ctx);
}
bool BooleanSubExpression::visit(IAlinousElementVisitor* visitor, AbstractSrcElement* parent, ThreadContext* ctx) throw() 
{
	if(!visitor->visit(this, parent, ctx))
	{
		return false;
	}
	if(this->exp != nullptr && !this->exp->visit(visitor, this, ctx))
	{
		return false;
	}
	return false;
}
bool BooleanSubExpression::isConstant(ThreadContext* ctx) throw() 
{
	if(this->exp != nullptr && !this->exp->isConstant(ctx))
	{
		return false;
	}
	return true;
}
bool BooleanSubExpression::analyse(SrcAnalyseContext* context, bool leftValue, ThreadContext* ctx) throw() 
{
	if(this->exp != nullptr)
	{
		this->exp->analyse(context, leftValue, ctx);
	}
	return true;
}
IExpression* BooleanSubExpression::getExp(ThreadContext* ctx) throw() 
{
	return exp;
}
void BooleanSubExpression::setExp(IExpression* exp, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->exp), exp, IExpression);
}
int BooleanSubExpression::getOp(ThreadContext* ctx) throw() 
{
	return op;
}
void BooleanSubExpression::setOp(int op, ThreadContext* ctx) throw() 
{
	this->op = op;
}
IAlinousVariable* BooleanSubExpression::resolveExpression(ScriptMachine* machine, bool debug, ThreadContext* ctx)
{
	return machine->resolveExpression(this->exp, debug, ctx);
}
ExpressionSourceId* BooleanSubExpression::getSourceId(ThreadContext* ctx) throw() 
{
	return (new(ctx) ExpressionSourceId(nullptr, this, (new(ctx) AlinousType(AlinousType::BOOL_TYPE, AlinousType::TYPE_PRIMITIVE, ctx)), ctx));
}
bool BooleanSubExpression::isSQLExp(ThreadContext* ctx) throw() 
{
	return false;
}
int BooleanSubExpression::getExpressionType(ThreadContext* ctx) throw() 
{
	return IExpression::booleanSubExpression;
}
}}}}

