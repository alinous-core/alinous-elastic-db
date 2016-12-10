#include "includes.h"


namespace alinous {namespace server {namespace webmodule {





bool StaticHtmlModuleStream::__init_done = __init_static_variables();
bool StaticHtmlModuleStream::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"StaticHtmlModuleStream", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 StaticHtmlModuleStream::StaticHtmlModuleStream(HttpHeaderProcessor* httpRequest, AlinousWebHtmlXmlModule* htmlModule, ThreadContext* ctx) throw()  : IObject(ctx), IContentByteStream(ctx), htmlModule(nullptr), buff(nullptr)
{
	__GC_MV(this, &(this->htmlModule), htmlModule, AlinousWebHtmlXmlModule);
	String* code = this->htmlModule->toStaticString(ctx);
	{
		try
		{
			__GC_MV(this, &(this->buff), code->getBytes(ConstStr::getCNST_STR_1047(), ctx), IArrayObjectPrimitive<char>);
		}
		catch(UnsupportedEncodingException* e)
		{
			e->printStackTrace(ctx);
		}
	}
}
void StaticHtmlModuleStream::__construct_impl(HttpHeaderProcessor* httpRequest, AlinousWebHtmlXmlModule* htmlModule, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->htmlModule), htmlModule, AlinousWebHtmlXmlModule);
	String* code = this->htmlModule->toStaticString(ctx);
	{
		try
		{
			__GC_MV(this, &(this->buff), code->getBytes(ConstStr::getCNST_STR_1047(), ctx), IArrayObjectPrimitive<char>);
		}
		catch(UnsupportedEncodingException* e)
		{
			e->printStackTrace(ctx);
		}
	}
}
 StaticHtmlModuleStream::~StaticHtmlModuleStream() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void StaticHtmlModuleStream::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"StaticHtmlModuleStream", L"~StaticHtmlModuleStream");
	__e_obj1.add(this->htmlModule, this);
	htmlModule = nullptr;
	__e_obj1.add(this->buff, this);
	buff = nullptr;
	if(!prepare){
		return;
	}
}
int StaticHtmlModuleStream::length(ThreadContext* ctx) throw() 
{
	return this->buff->length;
}
void StaticHtmlModuleStream::output(OutputStream* outStream, ThreadContext* ctx)
{
	outStream->write(this->buff, ctx);
}
void StaticHtmlModuleStream::prepare(AlinousCore* core, bool debug, ThreadContext* ctx)
{
}
String* StaticHtmlModuleStream::getContentType(ThreadContext* ctx) throw() 
{
	return ConstStr::getCNST_STR_1794();
}
}}}

