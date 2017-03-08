#include "include/global.h"


#include "alinous.compile/IAlinousElementVisitor.h"
#include "alinous.compile/IAlinousVisitorContainer.h"
#include "alinous.compile/AbstractSrcElement.h"
#include "alinous.remote.socket/ICommandData.h"
#include "alinous.compile/IAlinousElement.h"
#include "alinous.compile.declare/IDeclare.h"
#include "alinous.system/AlinousException.h"
#include "alinous.runtime/ExecutionException.h"
#include "alinous.runtime.dom/VariableException.h"
#include "alinous.remote.socket/NetworkBinaryBuffer.h"
#include "alinous.compile.declare.function/AlinousFunction.h"
#include "alinous.compile.analyse/SrcAnalyseContext.h"
#include "alinous.compile.declare/IClassMember.h"
#include "alinous.compile.declare/AbstractClassMember.h"
#include "alinous.compile.declare/ClassMethodFunction.h"
#include "alinous.compile.declare/AlinousClass.h"
#include "alinous.compile/Token.h"
#include "alinous.compile.declare/ClassMemberModifiers.h"

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
 ClassMemberModifiers::ClassMemberModifiers(ThreadContext* ctx) throw()  : IObject(ctx), IDeclare(ctx), list(GCUtils<ArrayList<String> >::ins(this, (new(ctx) ArrayList<String>(ctx)), ctx, __FILEW__, __LINE__, L"")), staticMod(false), privateMod(false), protectedMod(true), publicMod(false)
{
}
void ClassMemberModifiers::__construct_impl(ThreadContext* ctx) throw() 
{
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
	if(mod->equals(ConstStr::getCNST_STR_953(), ctx))
	{
		this->staticMod = true;
	}
		else 
	{
		if(mod->equals(ConstStr::getCNST_STR_954(), ctx))
		{
			protectedMod = false;
			privateMod = true;
		}
				else 
		{
			if(mod->equals(ConstStr::getCNST_STR_955(), ctx))
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
void ClassMemberModifiers::readData(NetworkBinaryBuffer* buff, ThreadContext* ctx)
{
	int maxLoop = buff->getInt(ctx);
	for(int i = 0; i < maxLoop; ++i)
	{
		String* str = buff->getString(ctx);
		this->list->add(str, ctx);
	}
	this->staticMod = buff->getBoolean(ctx);
	this->privateMod = buff->getBoolean(ctx);
	this->protectedMod = buff->getBoolean(ctx);
	this->publicMod = buff->getBoolean(ctx);
}
void ClassMemberModifiers::writeData(NetworkBinaryBuffer* buff, ThreadContext* ctx) throw() 
{
	buff->putInt(ICommandData::__ClassMemberModifiers, ctx);
	int maxLoop = this->list->size(ctx);
	buff->putInt(maxLoop, ctx);
	for(int i = 0; i < maxLoop; ++i)
	{
		String* str = this->list->get(i, ctx);
		buff->putString(str, ctx);
	}
	buff->putBoolean(this->staticMod, ctx);
	buff->putBoolean(this->privateMod, ctx);
	buff->putBoolean(this->protectedMod, ctx);
	buff->putBoolean(this->publicMod, ctx);
}
void ClassMemberModifiers::__cleanUp(ThreadContext* ctx){
}
}}}

