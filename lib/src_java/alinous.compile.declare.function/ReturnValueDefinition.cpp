#include "includes.h"


namespace alinous {namespace compile {namespace declare {namespace function {





bool ReturnValueDefinition::__init_done = __init_static_variables();
bool ReturnValueDefinition::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"ReturnValueDefinition", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 ReturnValueDefinition::~ReturnValueDefinition() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void ReturnValueDefinition::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"ReturnValueDefinition", L"~ReturnValueDefinition");
	__e_obj1.add(this->type, this);
	type = nullptr;
	__e_obj1.add(this->analysedType, this);
	analysedType = nullptr;
	if(!prepare){
		return;
	}
	IDeclare::__releaseRegerences(true, ctx);
}
bool ReturnValueDefinition::visit(IAlinousElementVisitor* visitor, AbstractSrcElement* parent, ThreadContext* ctx) throw() 
{
	if(!visitor->visit(this, parent, ctx))
	{
		return false;
	}
	if(this->type != nullptr && !this->type->visit(visitor, this, ctx))
	{
		return false;
	}
	return true;
}
bool ReturnValueDefinition::analyse(SrcAnalyseContext* context, bool leftValue, ThreadContext* ctx) throw() 
{
	if(this->type != nullptr)
	{
		this->type->analyse(context, leftValue, ctx);
	}
	__GC_MV(this, &(this->analysedType), this->type->toAlinousType(context, ctx), AlinousType);
	return true;
}
String* ReturnValueDefinition::toString(ThreadContext* ctx) throw() 
{
	StringBuffer* buff = (new(ctx) StringBuffer(ctx));
	buff->append(this->type->toString(ctx), ctx);
	return buff->toString(ctx);
}
AlinousName* ReturnValueDefinition::getType(ThreadContext* ctx) throw() 
{
	return type;
}
void ReturnValueDefinition::setType(AlinousName* type, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->type), type, AlinousName);
}
bool ReturnValueDefinition::isVoid(ThreadContext* ctx) throw() 
{
	return this->type->isVoid(ctx);
}
AlinousType* ReturnValueDefinition::getAnalysedType(ThreadContext* ctx) throw() 
{
	return analysedType;
}
int ReturnValueDefinition::getLine(ThreadContext* ctx) throw() 
{
	return IDeclare::getLine(ctx);
}
int ReturnValueDefinition::getStartPosition(ThreadContext* ctx) throw() 
{
	return IDeclare::getStartPosition(ctx);
}
int ReturnValueDefinition::getEndLine(ThreadContext* ctx) throw() 
{
	return IDeclare::getEndLine(ctx);
}
int ReturnValueDefinition::getEndPosition(ThreadContext* ctx) throw() 
{
	return IDeclare::getEndPosition(ctx);
}
AbstractSrcElement* ReturnValueDefinition::getParent(ThreadContext* ctx) throw() 
{
	return IDeclare::getParent(ctx);
}
void ReturnValueDefinition::setParent(AbstractSrcElement* parent, ThreadContext* ctx) throw() 
{
	IDeclare::setParent(parent, ctx);
}
void ReturnValueDefinition::readData(NetworkBinaryBuffer* buff, ThreadContext* ctx)
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
}
void ReturnValueDefinition::writeData(NetworkBinaryBuffer* buff, ThreadContext* ctx) throw() 
{
	buff->putInt(ICommandData::__ReturnValueDefinition, ctx);
	bool isnull = (this->type == nullptr);
	buff->putBoolean(isnull, ctx);
	if(!isnull)
	{
		this->type->writeData(buff, ctx);
	}
}
}}}}

