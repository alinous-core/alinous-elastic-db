#include "include/global.h"


#include "alinous.server.http/HttpHeaderProcessor.h"
#include "alinous.system/AlinousCore.h"
#include "alinous.server.http/IContentByteStream.h"
#include "alinous.web.htmlxml.module/AlinousWebHtmlXmlModule.h"
#include "alinous.server.webmodule/StaticHtmlModuleStream.h"
#include "alinous.server.webmodule/AbstractWebModule.h"
#include "alinous.server.webmodule/StaticHtmlModule.h"

namespace alinous {namespace server {namespace webmodule {





bool StaticHtmlModule::__init_done = __init_static_variables();
bool StaticHtmlModule::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"StaticHtmlModule", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 StaticHtmlModule::StaticHtmlModule(AlinousWebHtmlXmlModule* htmlModule, String* path, ThreadContext* ctx) throw()  : IObject(ctx), AbstractWebModule(htmlModule->getFile(ctx)->lastModified(ctx), ctx), htmlModule(nullptr)
{
	this->moduleType = AbstractWebModule::STATIC_HTML;
	__GC_MV(this, &(this->htmlModule), htmlModule, AlinousWebHtmlXmlModule);
	__GC_MV(this, &(this->path), path, String);
}
void StaticHtmlModule::__construct_impl(AlinousWebHtmlXmlModule* htmlModule, String* path, ThreadContext* ctx) throw() 
{
	this->moduleType = AbstractWebModule::STATIC_HTML;
	__GC_MV(this, &(this->htmlModule), htmlModule, AlinousWebHtmlXmlModule);
	__GC_MV(this, &(this->path), path, String);
}
 StaticHtmlModule::~StaticHtmlModule() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void StaticHtmlModule::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"StaticHtmlModule", L"~StaticHtmlModule");
	__e_obj1.add(this->htmlModule, this);
	htmlModule = nullptr;
	if(!prepare){
		return;
	}
	AbstractWebModule::__releaseRegerences(true, ctx);
}
IContentByteStream* StaticHtmlModule::getContentStream(HttpHeaderProcessor* httpRequest, ThreadContext* ctx) throw() 
{
	return (new(ctx) StaticHtmlModuleStream(httpRequest, this->htmlModule, ctx));
}
void StaticHtmlModule::prepare(AlinousCore* core, ThreadContext* ctx) throw() 
{
}
bool StaticHtmlModule::isDirty(ThreadContext* ctx) throw() 
{
	return this->htmlModule->getFile(ctx)->lastModified(ctx) > this->timeStamp;
}
void StaticHtmlModule::__cleanUp(ThreadContext* ctx){
}
}}}

