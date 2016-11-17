#include "includes.h"


namespace alinous {namespace compile {namespace declare {





bool AbstractClassMember::__init_done = __init_static_variables();
bool AbstractClassMember::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"AbstractClassMember", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 AbstractClassMember::~AbstractClassMember() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void AbstractClassMember::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"AbstractClassMember", L"~AbstractClassMember");
	__e_obj1.add(this->modifier, this);
	modifier = nullptr;
	if(!prepare){
		return;
	}
	IClassMember::__releaseRegerences(true, ctx);
}
ClassMemberModifiers* AbstractClassMember::getModifier(ThreadContext* ctx) throw() 
{
	return modifier;
}
void AbstractClassMember::setModifier(ClassMemberModifiers* modifier, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->modifier), modifier, ClassMemberModifiers);
}
bool AbstractClassMember::isStatic(ThreadContext* ctx) throw() 
{
	if(this->modifier == nullptr)
	{
		return false;
	}
	return this->modifier->isStatic(ctx);
}
int AbstractClassMember::getLine(ThreadContext* ctx) throw() 
{
	return IClassMember::getLine(ctx);
}
int AbstractClassMember::getStartPosition(ThreadContext* ctx) throw() 
{
	return IClassMember::getStartPosition(ctx);
}
int AbstractClassMember::getEndLine(ThreadContext* ctx) throw() 
{
	return IClassMember::getEndLine(ctx);
}
int AbstractClassMember::getEndPosition(ThreadContext* ctx) throw() 
{
	return IClassMember::getEndPosition(ctx);
}
AbstractSrcElement* AbstractClassMember::getParent(ThreadContext* ctx) throw() 
{
	return IClassMember::getParent(ctx);
}
void AbstractClassMember::setParent(AbstractSrcElement* parent, ThreadContext* ctx) throw() 
{
	IClassMember::setParent(parent, ctx);
}
}}}

