#include "includes.h"


namespace alinous {namespace compile {namespace expression {namespace expstream {





bool ExpStreamParenthesis::__init_done = __init_static_variables();
bool ExpStreamParenthesis::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"ExpStreamParenthesis", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 ExpStreamParenthesis::ExpStreamParenthesis(ThreadContext* ctx) throw()  : IObject(ctx), AbstractExpression(ctx), exp(nullptr)
{
}
void ExpStreamParenthesis::__construct_impl(ThreadContext* ctx) throw() 
{
}
 ExpStreamParenthesis::~ExpStreamParenthesis() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void ExpStreamParenthesis::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"ExpStreamParenthesis", L"~ExpStreamParenthesis");
	__e_obj1.add(this->exp, this);
	exp = nullptr;
	if(!prepare){
		return;
	}
	AbstractExpression::__releaseRegerences(true, ctx);
}
IAlinousVariable* ExpStreamParenthesis::resolveExpression(ScriptMachine* machine, bool debug, ThreadContext* ctx)
{
	return this->exp->resolveExpression(machine, debug, ctx);
}
bool ExpStreamParenthesis::visit(IAlinousElementVisitor* visitor, AbstractSrcElement* parent, ThreadContext* ctx) throw() 
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
bool ExpStreamParenthesis::isConstant(ThreadContext* ctx) throw() 
{
	return false;
}
bool ExpStreamParenthesis::analyse(SrcAnalyseContext* context, bool leftValue, ThreadContext* ctx) throw() 
{
	return this->exp->analyse(context, leftValue, ctx);
}
ExpressionStream* ExpStreamParenthesis::getExp(ThreadContext* ctx) throw() 
{
	return exp;
}
void ExpStreamParenthesis::setExp(ExpressionStream* exp, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->exp), exp, ExpressionStream);
}
ExpressionSourceId* ExpStreamParenthesis::getSourceId(ThreadContext* ctx) throw() 
{
	return (new(ctx) ExpressionSourceId(nullptr, this, this->exp->getSourceId(ctx)->getType(ctx), ctx));
}
int ExpStreamParenthesis::getExpressionType(ThreadContext* ctx) throw() 
{
	return IExpression::expStreamParenthesis;
}
void ExpStreamParenthesis::readData(NetworkBinaryBuffer* buff, ThreadContext* ctx)
{
	bool isnull = buff->getBoolean(ctx);
	if(!isnull)
	{
		IAlinousElement* el = AlinousElementNetworkFactory::formNetworkData(buff, ctx);
		if(el == nullptr || !((dynamic_cast<ExpressionStream*>(el) != 0)))
		{
			throw (new(ctx) VariableException(ConstStr::getCNST_STR_1018(), ctx));
		}
		__GC_MV(this, &(this->exp), static_cast<ExpressionStream*>(el), ExpressionStream);
	}
}
void ExpStreamParenthesis::writeData(NetworkBinaryBuffer* buff, ThreadContext* ctx) throw() 
{
	buff->putInt(ICommandData::__ExpStreamParenthesis, ctx);
	bool isnull = (this->exp == nullptr);
	buff->putBoolean(isnull, ctx);
	if(!isnull)
	{
		this->exp->writeData(buff, ctx);
	}
}
int ExpStreamParenthesis::fileSize(ThreadContext* ctx)
{
	int total = 4;
	bool isnull = (this->exp == nullptr);
	total += 1;
	if(!isnull)
	{
		total += this->exp->fileSize(ctx);
	}
	return total;
}
void ExpStreamParenthesis::toFileEntry(FileStorageEntryBuilder* builder, ThreadContext* ctx)
{
	builder->putInt(IExpressionFactory::__ExpStreamParenthesis, ctx);
	bool isnull = (this->exp == nullptr);
	builder->putBoolean(isnull, ctx);
	if(!isnull)
	{
		this->exp->toFileEntry(builder, ctx);
	}
}
void ExpStreamParenthesis::fromFileEntry(FileStorageEntryFetcher* fetcher, ThreadContext* ctx)
{
	bool isnull = fetcher->fetchBoolean(ctx);
	if(!isnull)
	{
		IExpression* el = IExpressionFactory::fromFetcher(fetcher, ctx);
		if(el == nullptr || !((dynamic_cast<ExpressionStream*>(el) != 0)))
		{
			throw (new(ctx) VariableException(ConstStr::getCNST_STR_1018(), ctx));
		}
		__GC_MV(this, &(this->exp), static_cast<ExpressionStream*>(el), ExpressionStream);
	}
}
}}}}

