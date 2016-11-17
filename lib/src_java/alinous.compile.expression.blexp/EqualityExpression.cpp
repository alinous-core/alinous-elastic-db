#include "includes.h"


namespace alinous {namespace compile {namespace expression {namespace blexp {





constexpr const int EqualityExpression::EQ;
constexpr const int EqualityExpression::NOT_EQ;
bool EqualityExpression::__init_done = __init_static_variables();
bool EqualityExpression::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"EqualityExpression", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 EqualityExpression::~EqualityExpression() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void EqualityExpression::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"EqualityExpression", L"~EqualityExpression");
	__e_obj1.add(this->left, this);
	left = nullptr;
	__e_obj1.add(this->right, this);
	right = nullptr;
	if(!prepare){
		return;
	}
	AbstractBooleanExpression::__releaseRegerences(true, ctx);
}
bool EqualityExpression::visit(IAlinousElementVisitor* visitor, AbstractSrcElement* parent, ThreadContext* ctx) throw() 
{
	if(!visitor->visit(this, parent, ctx))
	{
		return false;
	}
	if(this->left != nullptr && !this->left->visit(visitor, this, ctx))
	{
		return false;
	}
	if(this->right != nullptr && !this->right->visit(visitor, this, ctx))
	{
		return false;
	}
	return true;
}
bool EqualityExpression::isConstant(ThreadContext* ctx) throw() 
{
	if(this->left != nullptr && !this->left->isConstant(ctx))
	{
		return false;
	}
	if(this->right != nullptr && !this->right->isConstant(ctx))
	{
		return false;
	}
	return true;
}
bool EqualityExpression::analyse(SrcAnalyseContext* context, bool leftValue, ThreadContext* ctx) throw() 
{
	if(this->left != nullptr)
	{
		this->left->analyse(context, leftValue, ctx);
	}
	if(this->right != nullptr)
	{
		this->right->analyse(context, leftValue, ctx);
	}
	return true;
}
IExpression* EqualityExpression::getLeft(ThreadContext* ctx) throw() 
{
	return left;
}
void EqualityExpression::setLeft(IExpression* left, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->left), left, IExpression);
}
IExpression* EqualityExpression::getRight(ThreadContext* ctx) throw() 
{
	return right;
}
void EqualityExpression::setRight(IExpression* right, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->right), right, IExpression);
}
int EqualityExpression::getOpe(ThreadContext* ctx) throw() 
{
	return ope;
}
void EqualityExpression::setOpe(String* opeStr, ThreadContext* ctx) throw() 
{
	if(opeStr->equals(ConstStr::getCNST_STR_993(), ctx))
	{
		this->ope = EQ;
	}
		else 
	{
		this->ope = NOT_EQ;
	}
}
IAlinousVariable* EqualityExpression::resolveExpression(ScriptMachine* machine, bool debug, ThreadContext* ctx)
{
	IAlinousVariable* l = machine->resolveExpression(this->left, debug, ctx);
	IAlinousVariable* r = machine->resolveExpression(this->right, debug, ctx);
	int cmp = l->compareTo(r, ctx);
	if((this->ope == EQ && cmp == 0) || (this->ope == NOT_EQ && cmp != 0))
	{
		return (new(ctx) IntegerVariable(1, ctx));
	}
	return (new(ctx) IntegerVariable(0, ctx));
}
ExpressionSourceId* EqualityExpression::getSourceId(ThreadContext* ctx) throw() 
{
	return (new(ctx) ExpressionSourceId(nullptr, this, (new(ctx) AlinousType(AlinousType::BOOL_TYPE, AlinousType::TYPE_PRIMITIVE, ctx)), ctx));
}
int EqualityExpression::getExpressionType(ThreadContext* ctx) throw() 
{
	return IExpression::equalityExpression;
}
}}}}

