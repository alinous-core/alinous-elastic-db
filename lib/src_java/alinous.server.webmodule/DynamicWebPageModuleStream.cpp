#include "includes.h"


namespace alinous {namespace server {namespace webmodule {





bool DynamicWebPageModuleStream::__init_done = __init_static_variables();
bool DynamicWebPageModuleStream::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"DynamicWebPageModuleStream", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 DynamicWebPageModuleStream::DynamicWebPageModuleStream(HttpHeaderProcessor* httpRequest, AlinousWebHtmlXmlModule* htmlModule, AlinousModule* alnsModule, ThreadContext* ctx) throw()  : IObject(ctx), IContentByteStream(ctx), alnsModule(nullptr), htmlModule(nullptr), httpRequest(nullptr), outString(nullptr)
{
	__GC_MV(this, &(this->htmlModule), htmlModule, AlinousWebHtmlXmlModule);
	__GC_MV(this, &(this->alnsModule), alnsModule, AlinousModule);
	__GC_MV(this, &(this->httpRequest), httpRequest, HttpHeaderProcessor);
}
void DynamicWebPageModuleStream::__construct_impl(HttpHeaderProcessor* httpRequest, AlinousWebHtmlXmlModule* htmlModule, AlinousModule* alnsModule, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->htmlModule), htmlModule, AlinousWebHtmlXmlModule);
	__GC_MV(this, &(this->alnsModule), alnsModule, AlinousModule);
	__GC_MV(this, &(this->httpRequest), httpRequest, HttpHeaderProcessor);
}
 DynamicWebPageModuleStream::~DynamicWebPageModuleStream() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void DynamicWebPageModuleStream::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"DynamicWebPageModuleStream", L"~DynamicWebPageModuleStream");
	__e_obj1.add(this->alnsModule, this);
	alnsModule = nullptr;
	__e_obj1.add(this->htmlModule, this);
	htmlModule = nullptr;
	__e_obj1.add(this->httpRequest, this);
	httpRequest = nullptr;
	__e_obj1.add(this->outString, this);
	outString = nullptr;
	if(!prepare){
		return;
	}
}
int DynamicWebPageModuleStream::length(ThreadContext* ctx) throw() 
{
	return this->outString->length;
}
void DynamicWebPageModuleStream::output(OutputStream* outStream, ThreadContext* ctx)
{
	outStream->write(this->outString, ctx);
}
void DynamicWebPageModuleStream::prepare(AlinousCore* core, bool debug, ThreadContext* ctx)
{
	ScriptMachine* machine = (new(ctx) ScriptMachine(this->alnsModule, core, ctx));
	HashMap<String,AbstractHttpParameter>* params = httpRequest->params;
	if(params != nullptr)
	{
		machine->importParams(params, ctx);
	}
	IAlinousVariable* val = this->alnsModule->execute(machine, debug, ctx);
	if(!val->getStringValue(ctx)->equals(ConstStr::getCNST_STR_9(), ctx))
	{
	}
	StringWriter* writer = (new(ctx) StringWriter(ctx));
	this->htmlModule->execute(machine, this->alnsModule, writer, debug, ctx);
	__GC_MV(this, &(this->outString), writer->toString(ctx)->getBytes(ConstStr::getCNST_STR_1047(), ctx), IArrayObjectPrimitive<char>);
	writer->close(ctx);
}
String* DynamicWebPageModuleStream::getContentType(ThreadContext* ctx) throw() 
{
	return ConstStr::getCNST_STR_1806();
}
}}}

