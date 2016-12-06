#include "includes.h"


namespace alinous {namespace server {





String* AlinousWebContentProcessor::PING_TO_SERVER = ConstStr::getCNST_STR_1777();
String* AlinousWebContentProcessor::PING_RETURN = ConstStr::getCNST_STR_1777();
String* AlinousWebContentProcessor::DEBUG_CMD_ACCESS = ConstStr::getCNST_STR_1778();
String* AlinousWebContentProcessor::HEAD_METHOD = ConstStr::getCNST_STR_1779();
bool AlinousWebContentProcessor::__init_done = __init_static_variables();
bool AlinousWebContentProcessor::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"AlinousWebContentProcessor", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 AlinousWebContentProcessor::AlinousWebContentProcessor(AlinousCore* core, ThreadContext* ctx) throw()  : IObject(ctx), core(nullptr), webModuleManager(nullptr), mimeResolver(nullptr)
{
	__GC_MV(this, &(this->core), core, AlinousCore);
	__GC_MV(this, &(this->webModuleManager), core->webModuleManager, WebModuleManager);
	__GC_MV(this, &(mimeResolver), (new(ctx) MimeResolver(ctx)), MimeResolver);
}
void AlinousWebContentProcessor::__construct_impl(AlinousCore* core, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->core), core, AlinousCore);
	__GC_MV(this, &(this->webModuleManager), core->webModuleManager, WebModuleManager);
	__GC_MV(this, &(mimeResolver), (new(ctx) MimeResolver(ctx)), MimeResolver);
}
 AlinousWebContentProcessor::~AlinousWebContentProcessor() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void AlinousWebContentProcessor::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"AlinousWebContentProcessor", L"~AlinousWebContentProcessor");
	__e_obj1.add(this->core, this);
	core = nullptr;
	__e_obj1.add(this->webModuleManager, this);
	webModuleManager = nullptr;
	__e_obj1.add(this->mimeResolver, this);
	mimeResolver = nullptr;
	if(!prepare){
		return;
	}
}
AlinousCore* AlinousWebContentProcessor::getCore(ThreadContext* ctx) throw() 
{
	return core;
}
ContentResult* AlinousWebContentProcessor::proccess(HttpHeaderProcessor* request, ThreadContext* ctx)
{
	bool head = request->getMethod(ctx)->equals(HEAD_METHOD, ctx);
	String* path = request->getPath(ctx);
	String* ext = getExt(path, ctx);
	if(path->equals(AlinousWebContentProcessor::PING_TO_SERVER, ctx))
	{
		String* pingReturn = PING_RETURN;
		IArrayObjectPrimitive<char>* ret = nullptr;
		{
			try
			{
				ret = pingReturn->getBytes(ConstStr::getCNST_STR_1047(), ctx);
			}
			catch(UnsupportedEncodingException* e)
			{
			}
		}
		ContentResult* result = (new(ctx) ContentResult((new(ctx) BinaryContentByteStream(ret, ctx)), ext, this->mimeResolver, head, ctx));
		return result;
	}
		else 
	{
		if(core->debug && path->equals(AlinousWebContentProcessor::DEBUG_CMD_ACCESS, ctx))
		{
			return (new(ctx) ContentResult(DebugProcessor::process(this->core, request, ctx), ConstStr::getCNST_STR_1776(), this->mimeResolver, head, ctx));
		}
	}
	AbstractWebModule* module = this->webModuleManager->getModule(path, core->debug, ctx);
	if(module == nullptr)
	{
		return (new(ctx) ContentResult(nullptr, ext, this->mimeResolver, head, ctx));
	}
	ContentResult* result = (new(ctx) ContentResult(module->getContentStream(request, ctx), ext, this->mimeResolver, head, ctx));
	return result;
}
String* AlinousWebContentProcessor::getExt(String* path, ThreadContext* ctx) throw() 
{
	int idx = path->lastIndexOf((int)L'.', ctx);
	if(idx < 0)
	{
		return nullptr;
	}
	return path->substring(idx + 1, path->length(ctx), ctx);
}
}}

