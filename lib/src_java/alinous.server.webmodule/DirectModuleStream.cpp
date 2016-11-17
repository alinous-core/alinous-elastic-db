#include "includes.h"


namespace alinous {namespace server {namespace webmodule {





bool DirectModuleStream::__init_done = __init_static_variables();
bool DirectModuleStream::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"DirectModuleStream", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 DirectModuleStream::~DirectModuleStream() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void DirectModuleStream::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"DirectModuleStream", L"~DirectModuleStream");
	__e_obj1.add(this->alnsModule, this);
	alnsModule = nullptr;
	__e_obj1.add(this->buffer, this);
	buffer = nullptr;
	if(!prepare){
		return;
	}
}
int DirectModuleStream::length(ThreadContext* ctx) throw() 
{
	return this->buffer->length;
}
void DirectModuleStream::output(OutputStream* outStream, ThreadContext* ctx)
{
	outStream->write(this->buffer, ctx);
}
void DirectModuleStream::prepare(AlinousCore* core, bool debug, ThreadContext* ctx)
{
	IAlinousVariable* val = this->alnsModule->execute(debug, ctx);
	String* str = val->getStringValue(ctx);
	{
		try
		{
			__GC_MV(this, &(this->buffer), str->getBytes(ConstStr::getCNST_STR_1047(), ctx), IArrayObjectPrimitive<char>);
		}
		catch(UnsupportedEncodingException* e)
		{
			core->getLogger(ctx)->logError(e, ctx);
		}
	}
}
String* DirectModuleStream::getContentType(ThreadContext* ctx) throw() 
{
	return nullptr;
}
}}}

