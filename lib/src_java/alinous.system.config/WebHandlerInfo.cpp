#include "includes.h"


namespace alinous {namespace system {namespace config {





bool WebHandlerInfo::__init_done = __init_static_variables();
bool WebHandlerInfo::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"WebHandlerInfo", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 WebHandlerInfo::WebHandlerInfo(String* alinousHome, ThreadContext* ctx) throw()  : IObject(ctx), IAlinousConfigElement(ctx), documentRoot(nullptr), alinousHome(nullptr)
{
	__GC_MV(this, &(this->alinousHome), alinousHome, String);
}
void WebHandlerInfo::__construct_impl(String* alinousHome, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->alinousHome), alinousHome, String);
}
 WebHandlerInfo::~WebHandlerInfo() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void WebHandlerInfo::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"WebHandlerInfo", L"~WebHandlerInfo");
	__e_obj1.add(this->documentRoot, this);
	documentRoot = nullptr;
	__e_obj1.add(this->alinousHome, this);
	alinousHome = nullptr;
	if(!prepare){
		return;
	}
}
String* WebHandlerInfo::getDocumentRoot(ThreadContext* ctx) throw() 
{
	return documentRoot;
}
void WebHandlerInfo::setDocumentRoot(String* documentRoot, ThreadContext* ctx) throw() 
{
	String* documentAbsRoot = ConfigPathUtils::getAbsDirPath(this->alinousHome, documentRoot, ctx);
	if(documentAbsRoot->endsWith(ConstStr::getCNST_STR_984(), ctx))
	{
		__GC_MV(this, &(this->documentRoot), documentAbsRoot->substring(0, documentAbsRoot->length(ctx) - 1, ctx), String);
		return;
	}
	__GC_MV(this, &(this->documentRoot), documentAbsRoot, String);
}
}}}

