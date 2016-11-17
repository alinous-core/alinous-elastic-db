#include "includes.h"


namespace alinous {namespace compile {namespace expression {





bool SubExpression::__init_done = __init_static_variables();
bool SubExpression::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"SubExpression", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 SubExpression::SubExpression(String* op, IExpression* exp, ThreadContext* ctx) throw()  : IObject(ctx), AbstractExpression(ctx), op(0), exp(nullptr)
{
	this->op = AbstractExpression::operatorFromString(op, ctx);
	__GC_MV(this, &(this->exp), exp, IExpression);
}
void SubExpression::__construct_impl(String* op, IExpression* exp, ThreadContext* ctx) throw() 
{
	this->op = AbstractExpression::operatorFromString(op, ctx);
	__GC_MV(this, &(this->exp), exp, IExpression);
}
 SubExpression::~SubExpression() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void SubExpression::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"SubExpression", L"~SubExpression");
	__e_obj1.add(this->exp, this);
	exp = nullptr;
	if(!prepare){
		return;
	}
	AbstractExpression::__releaseRegerences(true, ctx);
}
bool SubExpression::visit(IAlinousElementVisitor* visitor, AbstractSrcElement* parent, ThreadContext* ctx) throw() 
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
bool SubExpression::isConstant(ThreadContext* ctx) throw() 
{
	if(this->exp != nullptr && !this->exp->isConstant(ctx))
	{
		return false;
	}
	return true;
}
bool SubExpression::analyse(SrcAnalyseContext* context, bool leftValue, ThreadContext* ctx) throw() 
{
	if(this->exp != nullptr)
	{
		return this->exp->analyse(context, leftValue, ctx);
	}
	return true;
}
IExpression* SubExpression::getExp(ThreadContext* ctx) throw() 
{
	return exp;
}
void SubExpression::setExp(IExpression* exp, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->exp), exp, IExpression);
}
int SubExpression::getOp(ThreadContext* ctx) throw() 
{
	return op;
}
void SubExpression::setOp(int op, ThreadContext* ctx) throw() 
{
	this->op = op;
}
IAlinousVariable* SubExpression::resolveExpression(ScriptMachine* machine, bool debug, ThreadContext* ctx)
{
	return machine->resolveExpression(this->exp, debug, ctx);
}
ExpressionSourceId* SubExpression::getSourceId(ThreadContext* ctx) throw() 
{
	return (new(ctx) ExpressionSourceId(nullptr, this, exp->getSourceId(ctx)->getType(ctx), ctx));
}
bool SubExpression::isSQLExp(ThreadContext* ctx) throw() 
{
	return false;
}
int SubExpression::getExpressionType(ThreadContext* ctx) throw() 
{
	return IExpression::subExpression;
}
}}}

