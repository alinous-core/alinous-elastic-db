#include "includes.h"


namespace alinous {namespace compile {namespace declare {namespace function {





bool ThrowsDefine::__init_done = __init_static_variables();
bool ThrowsDefine::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"ThrowsDefine", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 ThrowsDefine::~ThrowsDefine() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void ThrowsDefine::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"ThrowsDefine", L"~ThrowsDefine");
	__e_obj1.add(this->exceptions, this);
	exceptions = nullptr;
	if(!prepare){
		return;
	}
	IDeclare::__releaseRegerences(true, ctx);
}
bool ThrowsDefine::visit(IAlinousElementVisitor* visitor, AbstractSrcElement* parent, ThreadContext* ctx) throw() 
{
	if(!visitor->visit(this, parent, ctx))
	{
		return false;
	}
	int maxLoop = this->exceptions->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		if(!this->exceptions->get(i, ctx)->visit(visitor, this, ctx))
		{
			return false;
		}
	}
	return true;
}
bool ThrowsDefine::analyse(SrcAnalyseContext* context, bool leftValue, ThreadContext* ctx) throw() 
{
	int maxLoop = this->exceptions->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		this->exceptions->get(i, ctx)->analyse(context, leftValue, ctx);
	}
	return true;
}
void ThrowsDefine::addException(AlinousName* type, ThreadContext* ctx) throw() 
{
	this->exceptions->add(type, ctx);
}
ArrayList<AlinousName>* ThrowsDefine::getExceptions(ThreadContext* ctx) throw() 
{
	return exceptions;
}
int ThrowsDefine::getLine(ThreadContext* ctx) throw() 
{
	return IDeclare::getLine(ctx);
}
int ThrowsDefine::getStartPosition(ThreadContext* ctx) throw() 
{
	return IDeclare::getStartPosition(ctx);
}
int ThrowsDefine::getEndLine(ThreadContext* ctx) throw() 
{
	return IDeclare::getEndLine(ctx);
}
int ThrowsDefine::getEndPosition(ThreadContext* ctx) throw() 
{
	return IDeclare::getEndPosition(ctx);
}
AbstractSrcElement* ThrowsDefine::getParent(ThreadContext* ctx) throw() 
{
	return IDeclare::getParent(ctx);
}
void ThrowsDefine::setParent(AbstractSrcElement* parent, ThreadContext* ctx) throw() 
{
	IDeclare::setParent(parent, ctx);
}
}}}}

