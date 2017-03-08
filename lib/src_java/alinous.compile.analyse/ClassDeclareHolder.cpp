#include "include/global.h"


#include "alinous.compile/IAlinousVisitorContainer.h"
#include "alinous.remote.socket/ICommandData.h"
#include "alinous.compile/AbstractSrcElement.h"
#include "alinous.compile/IAlinousElement.h"
#include "alinous.compile.declare/AlinousName.h"
#include "alinous.compile.declare/IDeclare.h"
#include "alinous.compile.declare.function/AlinousFunction.h"
#include "alinous.compile.analyse/SrcAnalyseContext.h"
#include "alinous.compile.declare/ClassMemberModifiers.h"
#include "alinous.compile.declare/IClassMember.h"
#include "alinous.compile.declare/AbstractClassMember.h"
#include "alinous.compile.declare/ClassMethodFunction.h"
#include "alinous.compile/Token.h"
#include "alinous.runtime/AlinousModulePackage.h"
#include "alinous.compile.declare/AlinousClass.h"
#include "alinous.compile.analyse/ClassDeclareHolder.h"

namespace alinous {namespace compile {namespace analyse {





bool ClassDeclareHolder::__init_done = __init_static_variables();
bool ClassDeclareHolder::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"ClassDeclareHolder", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 ClassDeclareHolder::ClassDeclareHolder(ThreadContext* ctx) throw()  : IObject(ctx), declares(GCUtils<HashMap<String,ClassDeclareHolder::ClassDeclares> >::ins(this, (new(ctx) HashMap<String,ClassDeclareHolder::ClassDeclares>(ctx)), ctx, __FILEW__, __LINE__, L""))
{
}
void ClassDeclareHolder::__construct_impl(ThreadContext* ctx) throw() 
{
}
 ClassDeclareHolder::~ClassDeclareHolder() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void ClassDeclareHolder::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"ClassDeclareHolder", L"~ClassDeclareHolder");
	__e_obj1.add(this->declares, this);
	declares = nullptr;
	if(!prepare){
		return;
	}
}
AlinousClass* ClassDeclareHolder::fincClassDeclare(AlinousName* name, AlinousModulePackage* packageName, ThreadContext* ctx) throw() 
{
	AlinousClass* clazz = 0;
	if(name->getSegments(ctx)->size(ctx) == 1)
	{
		String* className = name->toString(ctx);
		clazz = findClassDeclareInPackage(className, packageName->toString(ctx), ctx);
		if(clazz != nullptr)
		{
			return clazz;
		}
		return findClassDeclareByName(className, ctx);
	}
	String* pkg = name->getPackageName(ctx);
	String* className = name->getClassName(ctx);
	return findClassDeclareInPackage(className, pkg, ctx);
}
void ClassDeclareHolder::addClassDeclare(AlinousClass* clazz, ThreadContext* ctx) throw() 
{
	String* pkg = clazz->getPackageName(ctx)->toString(ctx);
	ClassDeclareHolder::ClassDeclares* pkgDeclares = this->declares->get(pkg, ctx);
	if(pkgDeclares == nullptr)
	{
		pkgDeclares = (new(ctx) ClassDeclareHolder::ClassDeclares(ctx));
		this->declares->put(pkg, pkgDeclares, ctx);
	}
	pkgDeclares->addClassDeclare(clazz, ctx);
}
HashMap<String,ClassDeclareHolder::ClassDeclares>* ClassDeclareHolder::getDeclares(ThreadContext* ctx) throw() 
{
	return declares;
}
AlinousClass* ClassDeclareHolder::findClassDeclareByName(String* name, ThreadContext* ctx) throw() 
{
	AlinousClass* clazz = 0;
	Iterator<String>* it = this->declares->keySet(ctx)->iterator(ctx);
	while(it->hasNext(ctx))
	{
		String* pkg = it->next(ctx);
		ClassDeclareHolder::ClassDeclares* decls = this->declares->get(pkg, ctx);
		clazz = decls->get(name, ctx);
		if(clazz != nullptr)
		{
			return clazz;
		}
	}
	return nullptr;
}
AlinousClass* ClassDeclareHolder::findClassDeclareInPackage(String* name, String* packageName, ThreadContext* ctx) throw() 
{
	ClassDeclareHolder::ClassDeclares* decs = this->declares->get(packageName, ctx);
	if(decs == nullptr)
	{
		return nullptr;
	}
	AlinousClass* clazz = decs->get(name->toString(ctx), ctx);
	return clazz;
}
void ClassDeclareHolder::__cleanUp(ThreadContext* ctx){
}
}}}

namespace alinous {namespace compile {namespace analyse {





bool ClassDeclareHolder::ClassDeclares::__init_done = __init_static_variables();
bool ClassDeclareHolder::ClassDeclares::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"ClassDeclareHolder::ClassDeclares", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 ClassDeclareHolder::ClassDeclares::ClassDeclares(ThreadContext* ctx) throw()  : IObject(ctx), declares(GCUtils<HashMap<String,AlinousClass> >::ins(this, (new(ctx) HashMap<String,AlinousClass>(ctx)), ctx, __FILEW__, __LINE__, L""))
{
}
void ClassDeclareHolder::ClassDeclares::__construct_impl(ThreadContext* ctx) throw() 
{
}
 ClassDeclareHolder::ClassDeclares::~ClassDeclares() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void ClassDeclareHolder::ClassDeclares::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"ClassDeclares", L"~ClassDeclares");
	__e_obj1.add(this->declares, this);
	declares = nullptr;
	if(!prepare){
		return;
	}
}
void ClassDeclareHolder::ClassDeclares::addClassDeclare(AlinousClass* clazz, ThreadContext* ctx) throw() 
{
	this->declares->put(clazz->getName(ctx)->toString(ctx), clazz, ctx);
}
AlinousClass* ClassDeclareHolder::ClassDeclares::get(String* name, ThreadContext* ctx) throw() 
{
	return this->declares->get(name, ctx);
}
void ClassDeclareHolder::ClassDeclares::__cleanUp(ThreadContext* ctx){
}
}}}

