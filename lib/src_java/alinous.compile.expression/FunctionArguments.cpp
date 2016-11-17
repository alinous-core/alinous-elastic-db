#include "includes.h"


namespace alinous {namespace compile {namespace expression {





bool FunctionArguments::__init_done = __init_static_variables();
bool FunctionArguments::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"FunctionArguments", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 FunctionArguments::~FunctionArguments() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void FunctionArguments::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"FunctionArguments", L"~FunctionArguments");
	__e_obj1.add(this->arguments, this);
	arguments = nullptr;
	if(!prepare){
		return;
	}
	AbstractExpression::__releaseRegerences(true, ctx);
}
bool FunctionArguments::visit(IAlinousElementVisitor* visitor, AbstractSrcElement* parent, ThreadContext* ctx) throw() 
{
	if(!visitor->visit(this, parent, ctx))
	{
		return false;
	}
	int maxLoop = this->arguments->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		if(!this->arguments->get(i, ctx)->visit(visitor, this, ctx))
		{
			return false;
		}
	}
	return true;
}
bool FunctionArguments::isConstant(ThreadContext* ctx) throw() 
{
	int maxLoop = this->arguments->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		if(!this->arguments->get(i, ctx)->isConstant(ctx))
		{
			return false;
		}
	}
	return true;
}
bool FunctionArguments::analyse(SrcAnalyseContext* context, bool leftValue, ThreadContext* ctx) throw() 
{
	int maxLoop = this->arguments->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		this->arguments->get(i, ctx)->analyse(context, leftValue, ctx);
	}
	return true;
}
void FunctionArguments::addArgument(IExpression* exp, ThreadContext* ctx) throw() 
{
	this->arguments->add(exp, ctx);
}
int FunctionArguments::getArgumentSize(ThreadContext* ctx) throw() 
{
	return this->arguments->size(ctx);
}
IAlinousVariable* FunctionArguments::resolveExpression(ScriptMachine* machine, bool debug, ThreadContext* ctx)
{
	throw (new(ctx) AlinousNotSupportedException(ctx));
}
ExpressionSourceId* FunctionArguments::getSourceId(ThreadContext* ctx) throw() 
{
	return (new(ctx) ExpressionSourceId(nullptr, this, nullptr, ctx));
}
bool FunctionArguments::isSQLExp(ThreadContext* ctx) throw() 
{
	return false;
}
int FunctionArguments::getExpressionType(ThreadContext* ctx) throw() 
{
	return IExpression::functionArguments;
}
}}}

