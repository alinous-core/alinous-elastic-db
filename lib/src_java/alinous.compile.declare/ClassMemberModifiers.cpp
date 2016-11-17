#include "includes.h"


namespace alinous {namespace compile {namespace declare {





bool ClassMemberModifiers::__init_done = __init_static_variables();
bool ClassMemberModifiers::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"ClassMemberModifiers", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 ClassMemberModifiers::~ClassMemberModifiers() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void ClassMemberModifiers::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"ClassMemberModifiers", L"~ClassMemberModifiers");
	__e_obj1.add(this->list, this);
	list = nullptr;
	if(!prepare){
		return;
	}
	IDeclare::__releaseRegerences(true, ctx);
}
void ClassMemberModifiers::addModifier(String* mod, ThreadContext* ctx) throw() 
{
	this->list->add(mod, ctx);
	if(mod->equals(ConstStr::getCNST_STR_949(), ctx))
	{
		this->staticMod = true;
	}
		else 
	{
		if(mod->equals(ConstStr::getCNST_STR_950(), ctx))
		{
			protectedMod = false;
			privateMod = true;
		}
				else 
		{
			if(mod->equals(ConstStr::getCNST_STR_951(), ctx))
			{
				protectedMod = false;
				publicMod = true;
			}
		}
	}
}
ArrayList<String>* ClassMemberModifiers::getList(ThreadContext* ctx) throw() 
{
	return list;
}
bool ClassMemberModifiers::isStatic(ThreadContext* ctx) throw() 
{
	return this->staticMod;
}
bool ClassMemberModifiers::isPrivateMod(ThreadContext* ctx) throw() 
{
	return privateMod;
}
bool ClassMemberModifiers::isProtectedMod(ThreadContext* ctx) throw() 
{
	return protectedMod;
}
bool ClassMemberModifiers::isPublicMod(ThreadContext* ctx) throw() 
{
	return publicMod;
}
bool ClassMemberModifiers::visit(IAlinousElementVisitor* visitor, AbstractSrcElement* parent, ThreadContext* ctx) throw() 
{
	if(!visitor->visit(this, parent, ctx))
	{
		return false;
	}
	return true;
}
bool ClassMemberModifiers::analyse(SrcAnalyseContext* context, bool leftValue, ThreadContext* ctx) throw() 
{
	return true;
}
String* ClassMemberModifiers::toString(ThreadContext* ctx) throw() 
{
	StringBuffer* buff = (new(ctx) StringBuffer(ctx));
	int maxLoop = this->list->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		if(i > 0)
		{
			buff->append(ConstStr::getCNST_STR_73(), ctx);
		}
		String* mod = this->list->get(i, ctx);
		buff->append(mod, ctx);
	}
	return buff->toString(ctx);
}
int ClassMemberModifiers::getLine(ThreadContext* ctx) throw() 
{
	return IDeclare::getLine(ctx);
}
int ClassMemberModifiers::getStartPosition(ThreadContext* ctx) throw() 
{
	return IDeclare::getStartPosition(ctx);
}
int ClassMemberModifiers::getEndLine(ThreadContext* ctx) throw() 
{
	return IDeclare::getEndLine(ctx);
}
int ClassMemberModifiers::getEndPosition(ThreadContext* ctx) throw() 
{
	return IDeclare::getEndPosition(ctx);
}
AbstractSrcElement* ClassMemberModifiers::getParent(ThreadContext* ctx) throw() 
{
	return IDeclare::getParent(ctx);
}
void ClassMemberModifiers::setParent(AbstractSrcElement* parent, ThreadContext* ctx) throw() 
{
	IDeclare::setParent(parent, ctx);
}
}}}

