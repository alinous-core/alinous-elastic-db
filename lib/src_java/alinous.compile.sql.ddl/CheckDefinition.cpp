#include "includes.h"


namespace alinous {namespace compile {namespace sql {namespace ddl {





bool CheckDefinition::__init_done = __init_static_variables();
bool CheckDefinition::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"CheckDefinition", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 CheckDefinition::~CheckDefinition() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void CheckDefinition::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"CheckDefinition", L"~CheckDefinition");
	__e_obj1.add(this->exp, this);
	exp = nullptr;
	if(!prepare){
		return;
	}
	IAlinousElement::__releaseRegerences(true, ctx);
}
bool CheckDefinition::visit(IAlinousElementVisitor* visitor, AbstractSrcElement* parent, ThreadContext* ctx) throw() 
{
	if(!visitor->visit(this, parent, ctx))
	{
		return false;
	}
	if(this->exp != nullptr && !this->exp->visit(visitor, parent, ctx))
	{
		return false;
	}
	return true;
}
bool CheckDefinition::analyse(SrcAnalyseContext* context, bool leftValue, ThreadContext* ctx) throw() 
{
	if(this->exp != nullptr)
	{
		this->exp->analyse(context, leftValue, ctx);
	}
	return true;
}
ISQLExpression* CheckDefinition::getExp(ThreadContext* ctx) throw() 
{
	return exp;
}
void CheckDefinition::setExp(ISQLExpression* exp, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->exp), exp, ISQLExpression);
}
int CheckDefinition::getLine(ThreadContext* ctx) throw() 
{
	return IAlinousElement::getLine(ctx);
}
int CheckDefinition::getStartPosition(ThreadContext* ctx) throw() 
{
	return IAlinousElement::getStartPosition(ctx);
}
int CheckDefinition::getEndLine(ThreadContext* ctx) throw() 
{
	return IAlinousElement::getEndLine(ctx);
}
int CheckDefinition::getEndPosition(ThreadContext* ctx) throw() 
{
	return IAlinousElement::getEndPosition(ctx);
}
AbstractSrcElement* CheckDefinition::getParent(ThreadContext* ctx) throw() 
{
	return IAlinousElement::getParent(ctx);
}
void CheckDefinition::setParent(AbstractSrcElement* parent, ThreadContext* ctx) throw() 
{
	IAlinousElement::setParent(parent, ctx);
}
void CheckDefinition::readData(NetworkBinaryBuffer* buff, ThreadContext* ctx)
{
	bool isnull = buff->getBoolean(ctx);
	if(isnull)
	{
		IAlinousElement* el = AlinousElementNetworkFactory::formNetworkData(buff, ctx);
		if(el == nullptr || !((dynamic_cast<ISQLExpression*>(el) != 0)))
		{
			throw (new(ctx) VariableException(ConstStr::getCNST_STR_1044(), ctx));
		}
		__GC_MV(this, &(this->exp), static_cast<ISQLExpression*>(el), ISQLExpression);
	}
}
void CheckDefinition::writeData(NetworkBinaryBuffer* buff, ThreadContext* ctx) throw() 
{
	buff->putInt(ICommandData::__CheckDefinition, ctx);
	bool isnull = (this->exp == nullptr);
	buff->putBoolean(isnull, ctx);
	if(!isnull)
	{
		this->exp->writeData(buff, ctx);
	}
}
}}}}

