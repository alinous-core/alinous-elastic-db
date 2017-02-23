#include "includes.h"


namespace alinous {namespace compile {namespace expression {





bool CastExpression::__init_done = __init_static_variables();
bool CastExpression::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"CastExpression", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 CastExpression::~CastExpression() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void CastExpression::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"CastExpression", L"~CastExpression");
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
bool CastExpression::visit(IAlinousElementVisitor* visitor, AbstractSrcElement* parent, ThreadContext* ctx) throw() 
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
bool CastExpression::isConstant(ThreadContext* ctx) throw() 
{
	return this->exp->isConstant(ctx);
}
bool CastExpression::analyse(SrcAnalyseContext* context, bool leftValue, ThreadContext* ctx) throw() 
{
	if(this->type != nullptr)
	{
		this->type->analyse(context, leftValue, ctx);
	}
	if(this->exp != nullptr)
	{
		this->exp->analyse(context, leftValue, ctx);
	}
	__GC_MV(this, &(this->analysedType), this->type->toAlinousType(context, ctx), AlinousType);
	return true;
}
IExpression* CastExpression::getExp(ThreadContext* ctx) throw() 
{
	return exp;
}
void CastExpression::setExp(IExpression* exp, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->exp), exp, IExpression);
}
AlinousName* CastExpression::getType(ThreadContext* ctx) throw() 
{
	return type;
}
void CastExpression::setType(AlinousName* type, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->type), type, AlinousName);
}
IAlinousVariable* CastExpression::resolveExpression(ScriptMachine* machine, bool debug, ThreadContext* ctx)
{
	return machine->resolveExpression(this->exp, debug, ctx);
}
ExpressionSourceId* CastExpression::getSourceId(ThreadContext* ctx) throw() 
{
	return (new(ctx) ExpressionSourceId(nullptr, this, this->analysedType, ctx));
}
bool CastExpression::isSQLExp(ThreadContext* ctx) throw() 
{
	return false;
}
int CastExpression::getExpressionType(ThreadContext* ctx) throw() 
{
	return IExpression::castExpression;
}
void CastExpression::readData(NetworkBinaryBuffer* buff, ThreadContext* ctx)
{
	bool isnull = buff->getBoolean(ctx);
	if(!isnull)
	{
		IAlinousElement* el = AlinousElementNetworkFactory::formNetworkData(buff, ctx);
		if(el == nullptr || !((dynamic_cast<AlinousName*>(el) != 0)))
		{
			throw (new(ctx) VariableException(ConstStr::getCNST_STR_970(), ctx));
		}
		__GC_MV(this, &(this->type), static_cast<AlinousName*>(el), AlinousName);
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
}
void CastExpression::writeData(NetworkBinaryBuffer* buff, ThreadContext* ctx)
{
	buff->putInt(ICommandData::__CastExpression, ctx);
	bool isnull = (this->type == nullptr);
	buff->putBoolean(isnull, ctx);
	if(!isnull)
	{
		this->type->writeData(buff, ctx);
	}
	isnull = (this->exp == nullptr);
	buff->putBoolean(isnull, ctx);
	if(!isnull)
	{
		this->exp->writeData(buff, ctx);
	}
}
int CastExpression::fileSize(ThreadContext* ctx)
{
	int total = 4;
	bool isnull = (this->type == nullptr);
	total += 1;
	if(!isnull)
	{
		this->type->fileSize(ctx);
	}
	isnull = (this->exp == nullptr);
	total += 1;
	if(!isnull)
	{
		this->exp->fileSize(ctx);
	}
	return total;
}
void CastExpression::toFileEntry(FileStorageEntryBuilder* builder, ThreadContext* ctx)
{
	builder->putInt(IExpressionFactory::__CastExpression, ctx);
	bool isnull = (this->type == nullptr);
	builder->putBoolean(isnull, ctx);
	if(!isnull)
	{
		this->type->toFileEntry(builder, ctx);
	}
	isnull = (this->exp == nullptr);
	builder->putBoolean(isnull, ctx);
	if(!isnull)
	{
		this->exp->toFileEntry(builder, ctx);
	}
}
void CastExpression::fromFileEntry(FileStorageEntryFetcher* fetcher, ThreadContext* ctx)
{
	bool isnull = fetcher->fetchBoolean(ctx);
	if(!isnull)
	{
		IAlinousElement* el = AlinousName::fromFileEntry(fetcher, ctx);
		if(el == nullptr || !((dynamic_cast<AlinousName*>(el) != 0)))
		{
			throw (new(ctx) VariableException(ConstStr::getCNST_STR_970(), ctx));
		}
		__GC_MV(this, &(this->type), static_cast<AlinousName*>(el), AlinousName);
	}
	isnull = fetcher->fetchBoolean(ctx);
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

