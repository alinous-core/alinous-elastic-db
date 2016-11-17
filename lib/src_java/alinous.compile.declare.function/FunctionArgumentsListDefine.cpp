#include "includes.h"


namespace alinous {namespace compile {namespace declare {namespace function {





bool FunctionArgumentsListDefine::__init_done = __init_static_variables();
bool FunctionArgumentsListDefine::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"FunctionArgumentsListDefine", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 FunctionArgumentsListDefine::~FunctionArgumentsListDefine() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void FunctionArgumentsListDefine::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"FunctionArgumentsListDefine", L"~FunctionArgumentsListDefine");
	__e_obj1.add(this->list, this);
	list = nullptr;
	if(!prepare){
		return;
	}
	IDeclare::__releaseRegerences(true, ctx);
}
bool FunctionArgumentsListDefine::visit(IAlinousElementVisitor* visitor, AbstractSrcElement* parent, ThreadContext* ctx) throw() 
{
	if(!visitor->visit(this, parent, ctx))
	{
		return false;
	}
	int maxLoop = this->list->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		if(!this->list->get(i, ctx)->visit(visitor, this, ctx))
		{
			return false;
		}
	}
	return true;
}
bool FunctionArgumentsListDefine::same(FunctionArgumentsListDefine* other, ThreadContext* ctx) throw() 
{
	if(list->size(ctx) != other->list->size(ctx))
	{
		return false;
	}
	int maxLoop = this->list->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		FunctionArgumentDefine* def = this->list->get(i, ctx);
		FunctionArgumentDefine* odef = other->list->get(i, ctx);
		if(!def->sameMethodSig(odef, ctx))
		{
			return false;
		}
	}
	return true;
}
bool FunctionArgumentsListDefine::analyse(SrcAnalyseContext* context, bool leftValue, ThreadContext* ctx) throw() 
{
	int maxLoop = this->list->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		this->list->get(i, ctx)->analyse(context, leftValue, ctx);
	}
	return true;
}
String* FunctionArgumentsListDefine::toString(ThreadContext* ctx) throw() 
{
	StringBuffer* buff = (new(ctx) StringBuffer(ctx));
	buff->append(ConstStr::getCNST_STR_972(), ctx);
	int maxLoop = this->list->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		FunctionArgumentDefine* df = this->list->get(i, ctx);
		if(i != 0)
		{
			buff->append(ConstStr::getCNST_STR_73(), ctx);
		}
		buff->append(df->toString(ctx), ctx);
	}
	buff->append(ConstStr::getCNST_STR_889(), ctx);
	return buff->toString(ctx);
}
void FunctionArgumentsListDefine::addArgument(FunctionArgumentDefine* arg, ThreadContext* ctx) throw() 
{
	this->list->add(arg, ctx);
}
ArrayList<FunctionArgumentDefine>* FunctionArgumentsListDefine::getList(ThreadContext* ctx) throw() 
{
	return list;
}
int FunctionArgumentsListDefine::getLine(ThreadContext* ctx) throw() 
{
	return IDeclare::getLine(ctx);
}
int FunctionArgumentsListDefine::getStartPosition(ThreadContext* ctx) throw() 
{
	return IDeclare::getStartPosition(ctx);
}
int FunctionArgumentsListDefine::getEndLine(ThreadContext* ctx) throw() 
{
	return IDeclare::getEndLine(ctx);
}
int FunctionArgumentsListDefine::getEndPosition(ThreadContext* ctx) throw() 
{
	return IDeclare::getEndPosition(ctx);
}
AbstractSrcElement* FunctionArgumentsListDefine::getParent(ThreadContext* ctx) throw() 
{
	return IDeclare::getParent(ctx);
}
void FunctionArgumentsListDefine::setParent(AbstractSrcElement* parent, ThreadContext* ctx) throw() 
{
	IDeclare::setParent(parent, ctx);
}
}}}}

