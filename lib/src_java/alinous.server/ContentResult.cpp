#include "includes.h"


namespace alinous {namespace server {





bool ContentResult::__init_done = __init_static_variables();
bool ContentResult::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"ContentResult", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 ContentResult::ContentResult(IContentByteStream* byteData, String* ext, MimeResolver* mimeResolver, bool head, ThreadContext* ctx) throw()  : IObject(ctx), byteDataStream(nullptr), head(0), contentType(nullptr)
{
	__GC_MV(this, &(this->byteDataStream), byteData, IContentByteStream);
	this->head = head;
	if(ext == nullptr)
	{
		ext = ConstStr::getCNST_STR_1775();
	}
	String* content = mimeResolver->getContentType(ext, ctx);
	String* streamContent = nullptr;
	if(byteData != nullptr)
	{
		streamContent = byteData->getContentType(ctx);
	}
	__GC_MV(this, &(this->contentType), streamContent != nullptr ? streamContent : content, String);
}
void ContentResult::__construct_impl(IContentByteStream* byteData, String* ext, MimeResolver* mimeResolver, bool head, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->byteDataStream), byteData, IContentByteStream);
	this->head = head;
	if(ext == nullptr)
	{
		ext = ConstStr::getCNST_STR_1775();
	}
	String* content = mimeResolver->getContentType(ext, ctx);
	String* streamContent = nullptr;
	if(byteData != nullptr)
	{
		streamContent = byteData->getContentType(ctx);
	}
	__GC_MV(this, &(this->contentType), streamContent != nullptr ? streamContent : content, String);
}
 ContentResult::~ContentResult() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void ContentResult::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"ContentResult", L"~ContentResult");
	__e_obj1.add(this->byteDataStream, this);
	byteDataStream = nullptr;
	__e_obj1.add(this->contentType, this);
	contentType = nullptr;
	if(!prepare){
		return;
	}
}
String* ContentResult::getContentType(ThreadContext* ctx) throw() 
{
	return contentType;
}
IContentByteStream* ContentResult::getByteDataStream(ThreadContext* ctx) throw() 
{
	return byteDataStream;
}
}}

