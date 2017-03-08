#include "include/global.h"


#include "alinous.remote.socket/ICommandData.h"
#include "alinous.compile/IAlinousElementVisitor.h"
#include "alinous.compile/IAlinousVisitorContainer.h"
#include "alinous.compile/AbstractSrcElement.h"
#include "alinous.compile/IAlinousElement.h"
#include "alinous.compile.declare/IDeclare.h"
#include "alinous.compile.declare.function/AlinousFunction.h"
#include "alinous.compile.declare/ClassMemberModifiers.h"
#include "alinous.compile.declare/IClassMember.h"
#include "alinous.compile.declare/AbstractClassMember.h"
#include "alinous.compile.declare/ClassMethodFunction.h"
#include "alinous.compile.declare/AlinousClass.h"
#include "alinous.compile/Token.h"
#include "alinous.system/AlinousCore.h"
#include "alinous.runtime/AlinousModule.h"
#include "alinous.compile.analyse/SrcAnalyseContext.h"
#include "alinous.server.http/HttpHeaderProcessor.h"
#include "alinous.server.http/IContentByteStream.h"
#include "alinous.web.htmlxml.module/AlinousWebHtmlXmlModule.h"
#include "alinous.server.webmodule/DynamicWebPageModuleStream.h"
#include "alinous.server.webmodule/AbstractWebModule.h"
#include "alinous.server.webmodule/DynamicWebPageModule.h"

namespace alinous {namespace server {namespace webmodule {





bool DynamicWebPageModule::__init_done = __init_static_variables();
bool DynamicWebPageModule::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"DynamicWebPageModule", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 DynamicWebPageModule::DynamicWebPageModule(AlinousWebHtmlXmlModule* htmlModule, AlinousModule* alnsModule, String* path, ThreadContext* ctx) throw()  : IObject(ctx), AbstractWebModule(alnsModule->getFile(ctx)->lastModified(ctx) < htmlModule->getFile(ctx)->lastModified(ctx) ? htmlModule->getFile(ctx)->lastModified(ctx) : alnsModule->getFile(ctx)->lastModified(ctx), ctx), htmlModule(nullptr), alnsModule(nullptr)
{
	this->moduleType = AbstractWebModule::DYNAMIC_MODULE;
	__GC_MV(this, &(this->htmlModule), htmlModule, AlinousWebHtmlXmlModule);
	__GC_MV(this, &(this->alnsModule), alnsModule, AlinousModule);
	__GC_MV(this, &(this->path), path, String);
}
void DynamicWebPageModule::__construct_impl(AlinousWebHtmlXmlModule* htmlModule, AlinousModule* alnsModule, String* path, ThreadContext* ctx) throw() 
{
	this->moduleType = AbstractWebModule::DYNAMIC_MODULE;
	__GC_MV(this, &(this->htmlModule), htmlModule, AlinousWebHtmlXmlModule);
	__GC_MV(this, &(this->alnsModule), alnsModule, AlinousModule);
	__GC_MV(this, &(this->path), path, String);
}
 DynamicWebPageModule::~DynamicWebPageModule() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void DynamicWebPageModule::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"DynamicWebPageModule", L"~DynamicWebPageModule");
	__e_obj1.add(this->htmlModule, this);
	htmlModule = nullptr;
	__e_obj1.add(this->alnsModule, this);
	alnsModule = nullptr;
	if(!prepare){
		return;
	}
	AbstractWebModule::__releaseRegerences(true, ctx);
}
IContentByteStream* DynamicWebPageModule::getContentStream(HttpHeaderProcessor* httpRequest, ThreadContext* ctx) throw() 
{
	return (new(ctx) DynamicWebPageModuleStream(httpRequest, htmlModule, alnsModule, ctx));
}
void DynamicWebPageModule::prepare(AlinousCore* core, ThreadContext* ctx) throw() 
{
	SrcAnalyseContext* context = (new(ctx) SrcAnalyseContext(this->alnsModule, core->getFunctionManager(ctx), core->sqlFunctionManager, ctx));
	context->newStack(ctx);
	{
		try
		{
			this->htmlModule->prepare(context, ctx);
		}
		catch(Throwable* e)
		{
			context->endStack(ctx);
			return;
		}
	}
	context->endStack(ctx);
}
bool DynamicWebPageModule::isDirty(ThreadContext* ctx) throw() 
{
	long long curtime = this->htmlModule->getFile(ctx)->lastModified(ctx);
	return curtime > this->timeStamp || this->alnsModule->getFile(ctx)->lastModified(ctx) > this->timeStamp;
}
void DynamicWebPageModule::__cleanUp(ThreadContext* ctx){
}
}}}

