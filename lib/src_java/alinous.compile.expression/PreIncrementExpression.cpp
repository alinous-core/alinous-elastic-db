#include "includes.h"


namespace alinous {namespace compile {namespace expression {





bool PreIncrementExpression::__init_done = __init_static_variables();
bool PreIncrementExpression::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"PreIncrementExpression", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 PreIncrementExpression::~PreIncrementExpression() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void PreIncrementExpression::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"PreIncrementExpression", L"~PreIncrementExpression");
	__e_obj1.add(this->exp, this);
	exp = nullptr;
	if(!prepare){
		return;
	}
	AbstractExpression::__releaseRegerences(true, ctx);
}
bool PreIncrementExpression::isConstant(ThreadContext* ctx) throw() 
{
	if(this->exp != nullptr && !this->exp->isConstant(ctx))
	{
		return false;
	}
	return true;
}
bool PreIncrementExpression::visit(IAlinousElementVisitor* visitor, AbstractSrcElement* parent, ThreadContext* ctx) throw() 
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
bool PreIncrementExpression::analyse(SrcAnalyseContext* context, bool leftValue, ThreadContext* ctx) throw() 
{
	if(this->exp != nullptr)
	{
		return this->exp->analyse(context, leftValue, ctx);
	}
	return true;
}
IExpression* PreIncrementExpression::getExp(ThreadContext* ctx) throw() 
{
	return exp;
}
void PreIncrementExpression::setExp(IExpression* exp, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->exp), exp, IExpression);
}
IAlinousVariable* PreIncrementExpression::resolveExpression(ScriptMachine* machine, bool debug, ThreadContext* ctx)
{
	IAlinousVariable* variable = machine->resolveExpression(this->exp, debug, ctx);
	if(variable == nullptr || variable->isArray(ctx))
	{
		throw (new(ctx) VariableException(ConstStr::getCNST_STR_995(), ctx));
	}
	if(variable->isNull(ctx))
	{
		throw (new(ctx) AlinousNullPointerException(ctx));
	}
	IntegerVariable* operand = (new(ctx) IntegerVariable(1, ctx));
	IAlinousVariable* val = variable->add(operand, ctx);
	variable->substitute(val, ctx);
	return variable;
}
ExpressionSourceId* PreIncrementExpression::getSourceId(ThreadContext* ctx) throw() 
{
	return (new(ctx) ExpressionSourceId(nullptr, this, this->exp->getSourceId(ctx)->getType(ctx), ctx));
}
bool PreIncrementExpression::isSQLExp(ThreadContext* ctx) throw() 
{
	return false;
}
int PreIncrementExpression::getExpressionType(ThreadContext* ctx) throw() 
{
	return IExpression::preIncrementExpression;
}
void PreIncrementExpression::readData(NetworkBinaryBuffer* buff, ThreadContext* ctx)
{
	bool isnull = buff->getBoolean(ctx);
	if(!isnull)
	{
		IAlinousElement* el = AlinousElementNetworkFactory::formNetworkData(buff, ctx);
		if(el == nullptr || !((dynamic_cast<IExpression*>(el) != 0)))
		{
			throw (new(ctx) VariableException(ConstStr::getCNST_STR_980(), ctx));
		}
		__GC_MV(this, &(this->exp), static_cast<IExpression*>(el), IExpression);
	}
}
void PreIncrementExpression::writeData(NetworkBinaryBuffer* buff, ThreadContext* ctx)
{
	buff->putInt(ICommandData::__PreIncrementExpression, ctx);
	bool isnull = (this->exp == nullptr);
	buff->putBoolean(isnull, ctx);
	if(!isnull)
	{
		this->exp->writeData(buff, ctx);
	}
}
int PreIncrementExpression::fileSize(ThreadContext* ctx)
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
void PreIncrementExpression::toFileEntry(FileStorageEntryBuilder* builder, ThreadContext* ctx)
{
	builder->putInt(IExpressionFactory::__PreIncrementExpression, ctx);
	bool isnull = (this->exp == nullptr);
	builder->putBoolean(isnull, ctx);
	if(!isnull)
	{
		this->exp->toFileEntry(builder, ctx);
	}
}
void PreIncrementExpression::fromFileEntry(FileStorageEntryFetcher* fetcher, ThreadContext* ctx)
{
	bool isnull = fetcher->fetchBoolean(ctx);
	if(!isnull)
	{
		IExpression* el = IExpressionFactory::fromFetcher(fetcher, ctx);
		if(el == nullptr || !((dynamic_cast<IExpression*>(el) != 0)))
		{
			throw (new(ctx) VariableException(ConstStr::getCNST_STR_980(), ctx));
		}
		__GC_MV(this, &(this->exp), static_cast<IExpression*>(el), IExpression);
	}
}
}}}

