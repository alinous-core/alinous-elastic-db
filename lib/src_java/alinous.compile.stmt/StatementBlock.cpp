#include "includes.h"


namespace alinous {namespace compile {namespace stmt {





bool StatementBlock::__init_done = __init_static_variables();
bool StatementBlock::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"StatementBlock", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 StatementBlock::~StatementBlock() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void StatementBlock::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"StatementBlock", L"~StatementBlock");
	__e_obj1.add(this->list, this);
	list = nullptr;
	if(!prepare){
		return;
	}
	AbstractAlinousStatement::__releaseRegerences(true, ctx);
}
bool StatementBlock::visit(IAlinousElementVisitor* visitor, AbstractSrcElement* parent, ThreadContext* ctx) throw() 
{
	if(!visitor->visit(this, parent, ctx))
	{
		return false;
	}
	if(this->list != nullptr && !this->list->visit(visitor, this, ctx))
	{
		return false;
	}
	return true;
}
IStatement* StatementBlock::getFirstStatement(ThreadContext* ctx) throw() 
{
	if(list == nullptr)
	{
		return nullptr;
	}
	return this->list->getFirstStatement(ctx);
}
bool StatementBlock::analyse(SrcAnalyseContext* context, bool leftValue, ThreadContext* ctx) throw() 
{
	if((dynamic_cast<AlinousFunction*>(this->parent) != 0))
	{
		context->newStack(ctx);
	}
		else 
	{
		context->getCurrentStack(ctx)->newSubStack(ctx);
	}
	AbstractSrcElement* parent = getParent(ctx);
	if((dynamic_cast<AlinousFunction*>(parent) != 0))
	{
		AlinousFunction* func = static_cast<AlinousFunction*>(parent);
		addArgumentsToAnalysingStack(func, context, ctx);
	}
	if(this->list != nullptr)
	{
		this->list->analyse(context, leftValue, ctx);
	}
	if((dynamic_cast<AlinousFunction*>(this->parent) != 0))
	{
		context->endStack(ctx);
	}
		else 
	{
		context->getCurrentStack(ctx)->endSubStack(ctx);
	}
	return true;
}
StatementList* StatementBlock::getList(ThreadContext* ctx) throw() 
{
	return list;
}
void StatementBlock::setList(StatementList* list, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->list), list, StatementList);
}
IStatement::StatementType StatementBlock::getType(ThreadContext* ctx) throw() 
{
	return StatementType::BLOCK;
}
void StatementBlock::validate(SourceValidator* validator, ThreadContext* ctx) throw() 
{
}
void StatementBlock::readData(NetworkBinaryBuffer* buff, ThreadContext* ctx)
{
	bool isnull = buff->getBoolean(ctx);
	if(!isnull)
	{
		IAlinousElement* el = AlinousElementNetworkFactory::formNetworkData(buff, ctx);
		if(el == nullptr || !((dynamic_cast<StatementList*>(el) != 0)))
		{
			throw (new(ctx) VariableException(ConstStr::getCNST_STR_1094(), ctx));
		}
		__GC_MV(this, &(this->list), static_cast<StatementList*>(el), StatementList);
	}
}
void StatementBlock::writeData(NetworkBinaryBuffer* buff, ThreadContext* ctx) throw() 
{
	buff->putInt(ICommandData::__StatementBlock, ctx);
	bool isnull = (this->list == nullptr);
	buff->putBoolean(isnull, ctx);
	if(!isnull)
	{
		this->list->writeData(buff, ctx);
	}
}
void StatementBlock::addArgumentsToAnalysingStack(AlinousFunction* func, SrcAnalyseContext* context, ThreadContext* ctx) throw() 
{
	FunctionArgumentsListDefine* argDef = func->getArguments(ctx);
	if(argDef == nullptr)
	{
		return;
	}
	VariableDeclareHolder* variableHolder = context->getCurrentStack(ctx);
	ArrayList<FunctionArgumentDefine>* list = argDef->getList(ctx);
	int maxLoop = list->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		FunctionArgumentDefine* arg = list->get(i, ctx);
		variableHolder->addTypeVariableDeclare(arg, ctx);
	}
}
}}}

