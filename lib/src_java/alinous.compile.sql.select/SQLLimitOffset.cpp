#include "includes.h"


namespace alinous {namespace compile {namespace sql {namespace select {





bool SQLLimitOffset::__init_done = __init_static_variables();
bool SQLLimitOffset::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"SQLLimitOffset", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 SQLLimitOffset::~SQLLimitOffset() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void SQLLimitOffset::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"SQLLimitOffset", L"~SQLLimitOffset");
	__e_obj1.add(this->limit, this);
	limit = nullptr;
	__e_obj1.add(this->offset, this);
	offset = nullptr;
	if(!prepare){
		return;
	}
	IAlinousElement::__releaseRegerences(true, ctx);
}
bool SQLLimitOffset::visit(IAlinousElementVisitor* visitor, AbstractSrcElement* parent, ThreadContext* ctx) throw() 
{
	if(!visitor->visit(this, parent, ctx))
	{
		return false;
	}
	if(this->limit != nullptr && !this->limit->visit(visitor, this, ctx))
	{
		return false;
	}
	if(this->offset != nullptr && !this->offset->visit(visitor, this, ctx))
	{
		return false;
	}
	return true;
}
bool SQLLimitOffset::analyse(SrcAnalyseContext* context, bool leftValue, ThreadContext* ctx) throw() 
{
	if(this->limit != nullptr)
	{
		this->limit->analyse(context, leftValue, ctx);
	}
	if(this->offset != nullptr)
	{
		this->offset->analyse(context, leftValue, ctx);
	}
	return true;
}
ISQLExpression* SQLLimitOffset::getLimit(ThreadContext* ctx) throw() 
{
	return limit;
}
void SQLLimitOffset::setLimit(ISQLExpression* limit, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->limit), limit, ISQLExpression);
}
ISQLExpression* SQLLimitOffset::getOffset(ThreadContext* ctx) throw() 
{
	return offset;
}
void SQLLimitOffset::setOffset(ISQLExpression* offset, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->offset), offset, ISQLExpression);
}
int SQLLimitOffset::getLine(ThreadContext* ctx) throw() 
{
	return IAlinousElement::getLine(ctx);
}
int SQLLimitOffset::getStartPosition(ThreadContext* ctx) throw() 
{
	return IAlinousElement::getStartPosition(ctx);
}
int SQLLimitOffset::getEndLine(ThreadContext* ctx) throw() 
{
	return IAlinousElement::getEndLine(ctx);
}
int SQLLimitOffset::getEndPosition(ThreadContext* ctx) throw() 
{
	return IAlinousElement::getEndPosition(ctx);
}
AbstractSrcElement* SQLLimitOffset::getParent(ThreadContext* ctx) throw() 
{
	return IAlinousElement::getParent(ctx);
}
void SQLLimitOffset::setParent(AbstractSrcElement* parent, ThreadContext* ctx) throw() 
{
	IAlinousElement::setParent(parent, ctx);
}
void SQLLimitOffset::readData(NetworkBinaryBuffer* buff, ThreadContext* ctx)
{
	bool isnull = buff->getBoolean(ctx);
	if(!isnull)
	{
		IAlinousElement* el = AlinousElementNetworkFactory::formNetworkData(buff, ctx);
		if(el == nullptr || !((dynamic_cast<ISQLExpression*>(el) != 0)))
		{
			throw (new(ctx) VariableException(ConstStr::getCNST_STR_1044(), ctx));
		}
		__GC_MV(this, &(this->limit), static_cast<ISQLExpression*>(el), ISQLExpression);
	}
	isnull = buff->getBoolean(ctx);
	if(!isnull)
	{
		IAlinousElement* el = AlinousElementNetworkFactory::formNetworkData(buff, ctx);
		if(el == nullptr || !((dynamic_cast<ISQLExpression*>(el) != 0)))
		{
			throw (new(ctx) VariableException(ConstStr::getCNST_STR_1044(), ctx));
		}
		__GC_MV(this, &(this->offset), static_cast<ISQLExpression*>(el), ISQLExpression);
	}
}
void SQLLimitOffset::writeData(NetworkBinaryBuffer* buff, ThreadContext* ctx) throw() 
{
	buff->putInt(ICommandData::__SQLLimitOffset, ctx);
	bool isnull = (this->limit == nullptr);
	buff->putBoolean(isnull, ctx);
	if(!isnull)
	{
		this->limit->writeData(buff, ctx);
	}
	isnull = (this->offset == nullptr);
	buff->putBoolean(isnull, ctx);
	if(!isnull)
	{
		this->offset->writeData(buff, ctx);
	}
}
}}}}

