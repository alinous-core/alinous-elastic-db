#include "includes.h"


namespace alinous {namespace compile {namespace expression {namespace blexp {





bool AbstractBooleanCollectionExpression::__init_done = __init_static_variables();
bool AbstractBooleanCollectionExpression::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"AbstractBooleanCollectionExpression", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 AbstractBooleanCollectionExpression::AbstractBooleanCollectionExpression(ThreadContext* ctx) throw()  : IObject(ctx), AbstractExpression(ctx), first(nullptr), expressions(GCUtils<ArrayList<BooleanSubExpression> >::ins(this, (new(ctx) ArrayList<BooleanSubExpression>(ctx)), ctx, __FILEW__, __LINE__, L""))
{
}
void AbstractBooleanCollectionExpression::__construct_impl(ThreadContext* ctx) throw() 
{
}
 AbstractBooleanCollectionExpression::~AbstractBooleanCollectionExpression() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void AbstractBooleanCollectionExpression::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"AbstractBooleanCollectionExpression", L"~AbstractBooleanCollectionExpression");
	__e_obj1.add(this->first, this);
	first = nullptr;
	__e_obj1.add(this->expressions, this);
	expressions = nullptr;
	if(!prepare){
		return;
	}
	AbstractExpression::__releaseRegerences(true, ctx);
}
IExpression* AbstractBooleanCollectionExpression::getFirst(ThreadContext* ctx) throw() 
{
	return first;
}
void AbstractBooleanCollectionExpression::setFirst(IExpression* first, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->first), first, IExpression);
}
ArrayList<BooleanSubExpression>* AbstractBooleanCollectionExpression::getExpressions(ThreadContext* ctx) throw() 
{
	return expressions;
}
void AbstractBooleanCollectionExpression::addSubExpression(BooleanSubExpression* exp, ThreadContext* ctx) throw() 
{
	this->expressions->add(exp, ctx);
}
bool AbstractBooleanCollectionExpression::visit(IAlinousElementVisitor* visitor, AbstractSrcElement* parent, ThreadContext* ctx) throw() 
{
	if(!visitor->visit(this, parent, ctx))
	{
		return false;
	}
	if(this->first != nullptr && !this->first->visit(visitor, this, ctx))
	{
		return false;
	}
	int maxLoop = this->expressions->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		if(!this->expressions->get(i, ctx)->visit(visitor, this, ctx))
		{
			return false;
		}
	}
	return true;
}
bool AbstractBooleanCollectionExpression::isConstant(ThreadContext* ctx) throw() 
{
	if(this->first != nullptr && !this->first->isConstant(ctx))
	{
		return false;
	}
	int maxLoop = this->expressions->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		if(!this->expressions->get(i, ctx)->isConstant(ctx))
		{
			return false;
		}
	}
	return true;
}
bool AbstractBooleanCollectionExpression::analyse(SrcAnalyseContext* context, bool leftValue, ThreadContext* ctx) throw() 
{
	if(this->first != nullptr)
	{
		this->first->analyse(context, leftValue, ctx);
	}
	int maxLoop = this->expressions->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		this->expressions->get(i, ctx)->analyse(context, leftValue, ctx);
	}
	return true;
}
ExpressionSourceId* AbstractBooleanCollectionExpression::getSourceId(ThreadContext* ctx) throw() 
{
	return (new(ctx) ExpressionSourceId(nullptr, this, (new(ctx) AlinousType(AlinousType::BOOL_TYPE, AlinousType::TYPE_PRIMITIVE, ctx)), ctx));
}
bool AbstractBooleanCollectionExpression::isSQLExp(ThreadContext* ctx) throw() 
{
	return false;
}
void AbstractBooleanCollectionExpression::__readData(NetworkBinaryBuffer* buff, ThreadContext* ctx)
{
	bool isnull = buff->getBoolean(ctx);
	if(!isnull)
	{
		IAlinousElement* el = AlinousElementNetworkFactory::formNetworkData(buff, ctx);
		if(el == nullptr || !((dynamic_cast<IExpression*>(el) != 0)))
		{
			throw (new(ctx) VariableException(ConstStr::getCNST_STR_980(), ctx));
		}
		__GC_MV(this, &(this->first), static_cast<IExpression*>(el), IExpression);
	}
	int maxLoop = buff->getInt(ctx);
	for(int i = 0; i < maxLoop; ++i)
	{
		IAlinousElement* el = AlinousElementNetworkFactory::formNetworkData(buff, ctx);
		if(el == nullptr || !((dynamic_cast<BooleanSubExpression*>(el) != 0)))
		{
			throw (new(ctx) VariableException(ConstStr::getCNST_STR_1009(), ctx));
		}
		this->expressions->add(static_cast<BooleanSubExpression*>(el), ctx);
	}
}
void AbstractBooleanCollectionExpression::__writeData(NetworkBinaryBuffer* buff, ThreadContext* ctx) throw() 
{
	bool isnull = (this->first == nullptr);
	buff->putBoolean(isnull, ctx);
	if(!isnull)
	{
		this->first->writeData(buff, ctx);
	}
	int maxLoop = this->expressions->size(ctx);
	buff->putInt(maxLoop, ctx);
	for(int i = 0; i < maxLoop; ++i)
	{
		BooleanSubExpression* exp = this->expressions->get(i, ctx);
		exp->writeData(buff, ctx);
	}
}
}}}}

