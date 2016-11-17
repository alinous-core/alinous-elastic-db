#include "includes.h"


namespace alinous {namespace server {namespace webmodule {





bool BinaryModule::__init_done = __init_static_variables();
bool BinaryModule::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"BinaryModule", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 BinaryModule::BinaryModule(String* path, File* file, ThreadContext* ctx) throw()  : IObject(ctx), AbstractWebModule(file->lastModified(ctx), ctx), file(nullptr)
{
	this->moduleType = AbstractWebModule::BINARY_MODULE;
	__GC_MV(this, &(this->file), file, File);
	__GC_MV(this, &(this->path), path, String);
}
void BinaryModule::__construct_impl(String* path, File* file, ThreadContext* ctx) throw() 
{
	this->moduleType = AbstractWebModule::BINARY_MODULE;
	__GC_MV(this, &(this->file), file, File);
	__GC_MV(this, &(this->path), path, String);
}
 BinaryModule::~BinaryModule() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void BinaryModule::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"BinaryModule", L"~BinaryModule");
	__e_obj1.add(this->file, this);
	file = nullptr;
	if(!prepare){
		return;
	}
	AbstractWebModule::__releaseRegerences(true, ctx);
}
IContentByteStream* BinaryModule::getContentStream(HttpHeaderProcessor* httpRequest, ThreadContext* ctx) throw() 
{
	return (new(ctx) BinaryModuleStream(httpRequest, this->file, ctx));
}
void BinaryModule::prepare(AlinousCore* core, ThreadContext* ctx) throw() 
{
}
bool BinaryModule::isDirty(ThreadContext* ctx) throw() 
{
	return this->file->lastModified(ctx) > this->timeStamp;
}
}}}

