#include "includes.h"


namespace alinous {namespace compile {namespace declare {





bool ClassImplements::__init_done = __init_static_variables();
bool ClassImplements::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"ClassImplements", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 ClassImplements::~ClassImplements() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void ClassImplements::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"ClassImplements", L"~ClassImplements");
	__e_obj1.add(this->className, this);
	className = nullptr;
	__e_obj1.add(this->analysedClazz, this);
	analysedClazz = nullptr;
	if(!prepare){
		return;
	}
	IDeclare::__releaseRegerences(true, ctx);
}
bool ClassImplements::visit(IAlinousElementVisitor* visitor, AbstractSrcElement* parent, ThreadContext* ctx) throw() 
{
	if(!visitor->visit(this, parent, ctx))
	{
		return false;
	}
	if(!this->className->visit(visitor, this, ctx))
	{
		return false;
	}
	return true;
}
AlinousName* ClassImplements::getClassName(ThreadContext* ctx) throw() 
{
	return className;
}
void ClassImplements::setClassName(AlinousName* className, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->className), className, AlinousName);
}
AlinousClass* ClassImplements::getAnalysedClazz(ThreadContext* ctx) throw() 
{
	if(this->analysedClazz == nullptr)
	{
	}
	return analysedClazz;
}
bool ClassImplements::analyse(SrcAnalyseContext* context, bool leftValue, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->analysedClazz), context->findClassDeclare(this->className, ctx), AlinousClass);
	if(this->analysedClazz == nullptr)
	{
		context->getSourceValidator(ctx)->addError(toString(ctx)->clone(ctx)->append(ConstStr::getCNST_STR_965(), ctx), this, ctx);
	}
	return true;
}
int ClassImplements::getLine(ThreadContext* ctx) throw() 
{
	return IDeclare::getLine(ctx);
}
int ClassImplements::getStartPosition(ThreadContext* ctx) throw() 
{
	return IDeclare::getStartPosition(ctx);
}
int ClassImplements::getEndLine(ThreadContext* ctx) throw() 
{
	return IDeclare::getEndLine(ctx);
}
int ClassImplements::getEndPosition(ThreadContext* ctx) throw() 
{
	return IDeclare::getEndPosition(ctx);
}
AbstractSrcElement* ClassImplements::getParent(ThreadContext* ctx) throw() 
{
	return IDeclare::getParent(ctx);
}
void ClassImplements::setParent(AbstractSrcElement* parent, ThreadContext* ctx) throw() 
{
	IDeclare::setParent(parent, ctx);
}
}}}

