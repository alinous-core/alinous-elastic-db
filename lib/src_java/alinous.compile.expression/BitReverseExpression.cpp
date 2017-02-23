#include "includes.h"


namespace alinous {namespace compile {namespace expression {





bool BitReverseExpression::__init_done = __init_static_variables();
bool BitReverseExpression::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"BitReverseExpression", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 BitReverseExpression::~BitReverseExpression() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void BitReverseExpression::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"BitReverseExpression", L"~BitReverseExpression");
	__e_obj1.add(this->exp, this);
	exp = nullptr;
	if(!prepare){
		return;
	}
	AbstractExpression::__releaseRegerences(true, ctx);
}
bool BitReverseExpression::visit(IAlinousElementVisitor* visitor, AbstractSrcElement* parent, ThreadContext* ctx) throw() 
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
IExpression* BitReverseExpression::getExp(ThreadContext* ctx) throw() 
{
	return exp;
}
void BitReverseExpression::setExp(IExpression* exp, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->exp), exp, IExpression);
}
bool BitReverseExpression::isConstant(ThreadContext* ctx) throw() 
{
	return this->exp->isConstant(ctx);
}
bool BitReverseExpression::analyse(SrcAnalyseContext* context, bool leftValue, ThreadContext* ctx) throw() 
{
	return exp->analyse(context, leftValue, ctx);
}
IAlinousVariable* BitReverseExpression::resolveExpression(ScriptMachine* machine, bool debug, ThreadContext* ctx)
{
	IAlinousVariable* variable = machine->resolveExpression(this->exp, debug, ctx);
	if(variable == nullptr || variable->isArray(ctx))
	{
		throw (new(ctx) VariableException(ConstStr::getCNST_STR_995(), ctx));
	}
	VariantValue* value = (static_cast<DomVariable*>(variable))->getValue(ctx);
	if(value->isNull(ctx))
	{
		throw (new(ctx) AlinousNullPointerException(ctx));
	}
	variable = variable->copy(ctx);
	variable = variable->bitReverse(ctx);
	return variable;
}
ExpressionSourceId* BitReverseExpression::getSourceId(ThreadContext* ctx) throw() 
{
	return (new(ctx) ExpressionSourceId(nullptr, this, exp->getSourceId(ctx)->getType(ctx), ctx));
}
bool BitReverseExpression::isSQLExp(ThreadContext* ctx) throw() 
{
	return false;
}
int BitReverseExpression::getExpressionType(ThreadContext* ctx) throw() 
{
	return IExpression::bitReverseExpression;
}
void BitReverseExpression::readData(NetworkBinaryBuffer* buff, ThreadContext* ctx)
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
void BitReverseExpression::writeData(NetworkBinaryBuffer* buff, ThreadContext* ctx)
{
	buff->putInt(ICommandData::__BitReverseExpression, ctx);
	bool isnull = (this->exp == nullptr);
	buff->putBoolean(isnull, ctx);
	if(!isnull)
	{
		this->exp->writeData(buff, ctx);
	}
}
int BitReverseExpression::fileSize(ThreadContext* ctx)
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
void BitReverseExpression::toFileEntry(FileStorageEntryBuilder* builder, ThreadContext* ctx)
{
	builder->putInt(IExpressionFactory::__BitReverseExpression, ctx);
	bool isnull = (this->exp == nullptr);
	builder->putBoolean(isnull, ctx);
	if(!isnull)
	{
		this->exp->toFileEntry(builder, ctx);
	}
}
void BitReverseExpression::fromFileEntry(FileStorageEntryFetcher* fetcher, ThreadContext* ctx)
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

