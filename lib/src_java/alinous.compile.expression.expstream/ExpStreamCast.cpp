#include "includes.h"


namespace alinous {namespace compile {namespace expression {namespace expstream {





bool ExpStreamCast::__init_done = __init_static_variables();
bool ExpStreamCast::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"ExpStreamCast", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 ExpStreamCast::ExpStreamCast(ThreadContext* ctx) throw()  : IObject(ctx), AbstractExpression(ctx), type(nullptr), exp(nullptr), analysedType(nullptr)
{
}
void ExpStreamCast::__construct_impl(ThreadContext* ctx) throw() 
{
}
 ExpStreamCast::~ExpStreamCast() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void ExpStreamCast::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"ExpStreamCast", L"~ExpStreamCast");
	__e_obj1.add(this->type, this);
	type = nullptr;
	__e_obj1.add(this->exp, this);
	exp = nullptr;
	__e_obj1.add(this->analysedType, this);
	analysedType = nullptr;
	if(!prepare){
		return;
	}
	AbstractExpression::__releaseRegerences(true, ctx);
}
IAlinousVariable* ExpStreamCast::resolveExpression(ScriptMachine* machine, bool debug, ThreadContext* ctx)
{
	return nullptr;
}
bool ExpStreamCast::analyse(SrcAnalyseContext* context, bool leftValue, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->analysedType), this->type->toAlinousType(context, ctx), AlinousType);
	this->exp->analyse(context, leftValue, ctx);
	return true;
}
bool ExpStreamCast::visit(IAlinousElementVisitor* visitor, AbstractSrcElement* parent, ThreadContext* ctx) throw() 
{
	if(!visitor->visit(this, parent, ctx))
	{
		return false;
	}
	if(this->type != nullptr && !this->type->visit(visitor, this, ctx))
	{
		return false;
	}
	if(this->exp != nullptr && !this->exp->visit(visitor, this, ctx))
	{
		return false;
	}
	return true;
}
bool ExpStreamCast::isConstant(ThreadContext* ctx) throw() 
{
	return false;
}
AlinousName* ExpStreamCast::getType(ThreadContext* ctx) throw() 
{
	return type;
}
void ExpStreamCast::setType(AlinousName* type, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->type), type, AlinousName);
}
ExpressionStream* ExpStreamCast::getExp(ThreadContext* ctx) throw() 
{
	return exp;
}
void ExpStreamCast::setExp(ExpressionStream* exp, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->exp), exp, ExpressionStream);
}
ExpressionSourceId* ExpStreamCast::getSourceId(ThreadContext* ctx) throw() 
{
	return (new(ctx) ExpressionSourceId(nullptr, this, this->analysedType, ctx));
}
int ExpStreamCast::getExpressionType(ThreadContext* ctx) throw() 
{
	return IExpression::expStreamCast;
}
}}}}

