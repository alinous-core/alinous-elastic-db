#include "includes.h"


namespace alinous {namespace compile {namespace declare {namespace function {





bool AlinousFunction::__init_done = __init_static_variables();
bool AlinousFunction::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"AlinousFunction", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 AlinousFunction::~AlinousFunction() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void AlinousFunction::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"AlinousFunction", L"~AlinousFunction");
	__e_obj1.add(this->name, this);
	name = nullptr;
	__e_obj1.add(this->returnType, this);
	returnType = nullptr;
	__e_obj1.add(this->arguments, this);
	arguments = nullptr;
	__e_obj1.add(this->throwsDefine, this);
	throwsDefine = nullptr;
	__e_obj1.add(this->block, this);
	block = nullptr;
	__e_obj1.add(this->analysedReturnType, this);
	analysedReturnType = nullptr;
	if(!prepare){
		return;
	}
	IDeclare::__releaseRegerences(true, ctx);
}
String* AlinousFunction::getFunctionName(ThreadContext* ctx) throw() 
{
	return this->name->toString(ctx);
}
bool AlinousFunction::sameSig(AlinousFunction* other, ThreadContext* ctx) throw() 
{
	if(!this->name->equals(other->name, ctx))
	{
		return false;
	}
	if(!this->arguments->same(other->arguments, ctx))
	{
		return false;
	}
	return true;
}
bool AlinousFunction::visit(IAlinousElementVisitor* visitor, AbstractSrcElement* parent, ThreadContext* ctx) throw() 
{
	if(!visitor->visit(this, parent, ctx))
	{
		return false;
	}
	if(this->name != nullptr && !this->name->visit(visitor, this, ctx))
	{
		return false;
	}
	if(this->returnType != nullptr && !this->returnType->visit(visitor, this, ctx))
	{
		return false;
	}
	if(this->arguments != nullptr && !this->arguments->visit(visitor, this, ctx))
	{
		return false;
	}
	if(this->throwsDefine != nullptr && !this->throwsDefine->visit(visitor, this, ctx))
	{
		return false;
	}
	if(this->block != nullptr && !this->block->visit(visitor, this, ctx))
	{
		return false;
	}
	return true;
}
bool AlinousFunction::analyse(SrcAnalyseContext* context, bool leftValue, ThreadContext* ctx) throw() 
{
	this->name->analyse(context, leftValue, ctx);
	if(this->returnType != nullptr)
	{
		this->returnType->analyse(context, leftValue, ctx);
	}
	this->arguments->analyse(context, leftValue, ctx);
	if(this->throwsDefine != nullptr)
	{
		this->throwsDefine->analyse(context, leftValue, ctx);
	}
	this->block->analyse(context, leftValue, ctx);
	if(this->returnType != nullptr && !this->returnType->isVoid(ctx))
	{
		__GC_MV(this, &(this->analysedReturnType), this->returnType->getAnalysedType(ctx), AlinousType);
	}
		else 
	{
		if(this->returnType != nullptr && this->returnType->isVoid(ctx))
		{
			__GC_MV(this, &(this->analysedReturnType), (new(ctx) AlinousType(AlinousType::NULL_TYPE, AlinousType::TYPE_VOID, ctx)), AlinousType);
		}
	}
	return true;
}
FunctionCallExpression* AlinousFunction::callSuperConstructor(ThreadContext* ctx) throw() 
{
	IStatement* stmt = this->block->getFirstStatement(ctx);
	if(stmt == nullptr)
	{
		return nullptr;
	}
	FunctionCallCollector* visitor = (new(ctx) FunctionCallCollector(ctx));
	stmt->visit(visitor, this->parent, ctx);
	int maxLoop = visitor->getList(ctx)->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		FunctionCallExpression* func = visitor->getList(ctx)->get(i, ctx);
		if(func->body->equals(ConstStr::getCNST_STR_982(), ctx))
		{
			return func;
		}
	}
	return nullptr;
}
String* AlinousFunction::toString(ThreadContext* ctx) throw() 
{
	StringBuffer* buff = (new(ctx) StringBuffer(ctx));
	if(this->returnType != nullptr)
	{
		buff->append(this->returnType->toString(ctx), ctx)->append(ConstStr::getCNST_STR_380(), ctx);
	}
	buff->append(this->name->toString(ctx), ctx);
	if(this->arguments != nullptr)
	{
		buff->append(this->arguments->toString(ctx), ctx);
	}
		else 
	{
		buff->append(ConstStr::getCNST_STR_983(), ctx);
	}
	return buff->toString(ctx);
}
AlinousName* AlinousFunction::getName(ThreadContext* ctx) throw() 
{
	return name;
}
void AlinousFunction::setName(AlinousName* name, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->name), name, AlinousName);
}
ReturnValueDefinition* AlinousFunction::getReturnType(ThreadContext* ctx) throw() 
{
	return returnType;
}
void AlinousFunction::setReturnType(ReturnValueDefinition* returnType, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->returnType), returnType, ReturnValueDefinition);
}
FunctionArgumentsListDefine* AlinousFunction::getArguments(ThreadContext* ctx) throw() 
{
	return arguments;
}
void AlinousFunction::setArguments(FunctionArgumentsListDefine* arguments, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->arguments), arguments, FunctionArgumentsListDefine);
}
ThrowsDefine* AlinousFunction::getThrowsDefine(ThreadContext* ctx) throw() 
{
	return throwsDefine;
}
void AlinousFunction::setThrowsDefine(ThrowsDefine* throwsDefine, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->throwsDefine), throwsDefine, ThrowsDefine);
}
StatementBlock* AlinousFunction::getBlock(ThreadContext* ctx) throw() 
{
	return block;
}
void AlinousFunction::setBlock(StatementBlock* block, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->block), block, StatementBlock);
}
AlinousType* AlinousFunction::getAnalysedReturnType(ThreadContext* ctx) throw() 
{
	return analysedReturnType;
}
int AlinousFunction::getLine(ThreadContext* ctx) throw() 
{
	return IDeclare::getLine(ctx);
}
int AlinousFunction::getStartPosition(ThreadContext* ctx) throw() 
{
	return IDeclare::getStartPosition(ctx);
}
int AlinousFunction::getEndLine(ThreadContext* ctx) throw() 
{
	return IDeclare::getEndLine(ctx);
}
int AlinousFunction::getEndPosition(ThreadContext* ctx) throw() 
{
	return IDeclare::getEndPosition(ctx);
}
AbstractSrcElement* AlinousFunction::getParent(ThreadContext* ctx) throw() 
{
	return IDeclare::getParent(ctx);
}
void AlinousFunction::setParent(AbstractSrcElement* parent, ThreadContext* ctx) throw() 
{
	IDeclare::setParent(parent, ctx);
}
void AlinousFunction::readData(NetworkBinaryBuffer* buff, ThreadContext* ctx)
{
	bool isnull = buff->getBoolean(ctx);
	if(!isnull)
	{
		IAlinousElement* el = AlinousElementNetworkFactory::formNetworkData(buff, ctx);
		if(el == nullptr || !((dynamic_cast<AlinousName*>(el) != 0)))
		{
			throw (new(ctx) VariableException(ConstStr::getCNST_STR_970(), ctx));
		}
		__GC_MV(this, &(this->name), static_cast<AlinousName*>(el), AlinousName);
	}
	isnull = buff->getBoolean(ctx);
	if(!isnull)
	{
		IAlinousElement* el = AlinousElementNetworkFactory::formNetworkData(buff, ctx);
		if(el == nullptr || !((dynamic_cast<ReturnValueDefinition*>(el) != 0)))
		{
			throw (new(ctx) VariableException(ConstStr::getCNST_STR_984(), ctx));
		}
		__GC_MV(this, &(this->returnType), static_cast<ReturnValueDefinition*>(el), ReturnValueDefinition);
	}
	isnull = buff->getBoolean(ctx);
	if(!isnull)
	{
		IAlinousElement* el = AlinousElementNetworkFactory::formNetworkData(buff, ctx);
		if(el == nullptr || !((dynamic_cast<FunctionArgumentsListDefine*>(el) != 0)))
		{
			throw (new(ctx) VariableException(ConstStr::getCNST_STR_985(), ctx));
		}
		__GC_MV(this, &(this->arguments), static_cast<FunctionArgumentsListDefine*>(el), FunctionArgumentsListDefine);
	}
	isnull = buff->getBoolean(ctx);
	if(!isnull)
	{
		IAlinousElement* el = AlinousElementNetworkFactory::formNetworkData(buff, ctx);
		if(el == nullptr || !((dynamic_cast<ThrowsDefine*>(el) != 0)))
		{
			throw (new(ctx) VariableException(ConstStr::getCNST_STR_986(), ctx));
		}
		__GC_MV(this, &(this->throwsDefine), static_cast<ThrowsDefine*>(el), ThrowsDefine);
	}
	isnull = buff->getBoolean(ctx);
	if(!isnull)
	{
		IAlinousElement* el = AlinousElementNetworkFactory::formNetworkData(buff, ctx);
		if(el == nullptr || !((dynamic_cast<StatementBlock*>(el) != 0)))
		{
			throw (new(ctx) VariableException(ConstStr::getCNST_STR_987(), ctx));
		}
		__GC_MV(this, &(this->block), static_cast<StatementBlock*>(el), StatementBlock);
	}
}
void AlinousFunction::writeData(NetworkBinaryBuffer* buff, ThreadContext* ctx)
{
	buff->putInt(ICommandData::__AlinousFunction, ctx);
	bool isnull = (this->name == nullptr);
	buff->putBoolean(isnull, ctx);
	if(!isnull)
	{
		this->name->writeData(buff, ctx);
	}
	isnull = (this->returnType == nullptr);
	buff->putBoolean(isnull, ctx);
	if(!isnull)
	{
		this->returnType->writeData(buff, ctx);
	}
	isnull = (this->arguments == nullptr);
	buff->putBoolean(isnull, ctx);
	if(!isnull)
	{
		this->arguments->writeData(buff, ctx);
	}
	isnull = (this->throwsDefine == nullptr);
	buff->putBoolean(isnull, ctx);
	if(!isnull)
	{
		this->throwsDefine->writeData(buff, ctx);
	}
	isnull = (this->block == nullptr);
	buff->putBoolean(isnull, ctx);
	if(!isnull)
	{
		this->block->writeData(buff, ctx);
	}
}
}}}}

