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
void ExpStreamCast::readData(NetworkBinaryBuffer* buff, ThreadContext* ctx)
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
		if(el == nullptr || !((dynamic_cast<ExpressionStream*>(el) != 0)))
		{
			throw (new(ctx) VariableException(ConstStr::getCNST_STR_1018(), ctx));
		}
		__GC_MV(this, &(this->exp), static_cast<ExpressionStream*>(el), ExpressionStream);
	}
}
void ExpStreamCast::writeData(NetworkBinaryBuffer* buff, ThreadContext* ctx) throw() 
{
	buff->putInt(ICommandData::__ExpStreamCast, ctx);
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
int ExpStreamCast::fileSize(ThreadContext* ctx)
{
	int total = 4;
	bool isnull = (this->type == nullptr);
	total += 1;
	if(!isnull)
	{
		total += this->type->fileSize(ctx);
	}
	isnull = (this->exp == nullptr);
	total += 1;
	if(!isnull)
	{
		total += this->exp->fileSize(ctx);
	}
	return total;
}
void ExpStreamCast::toFileEntry(FileStorageEntryBuilder* builder, ThreadContext* ctx)
{
	builder->putInt(IExpressionFactory::__ExpStreamCast, ctx);
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
void ExpStreamCast::fromFileEntry(FileStorageEntryFetcher* fetcher, ThreadContext* ctx)
{
	bool isnull = fetcher->fetchBoolean(ctx);
	if(!isnull)
	{
		AlinousName* el = AlinousName::fromFileEntry(fetcher, ctx);
		if(el == nullptr)
		{
			throw (new(ctx) VariableException(ConstStr::getCNST_STR_970(), ctx));
		}
		__GC_MV(this, &(this->type), el, AlinousName);
	}
	isnull = fetcher->fetchBoolean(ctx);
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

