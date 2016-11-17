#include "includes.h"


namespace alinous {namespace server {





bool BinaryContentByteStream::__init_done = __init_static_variables();
bool BinaryContentByteStream::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"BinaryContentByteStream", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 BinaryContentByteStream::BinaryContentByteStream(IArrayObjectPrimitive<char>* bytes, ThreadContext* ctx) throw()  : IObject(ctx), IContentByteStream(ctx), bytes(nullptr)
{
	__GC_MV(this, &(this->bytes), bytes, IArrayObjectPrimitive<char>);
}
void BinaryContentByteStream::__construct_impl(IArrayObjectPrimitive<char>* bytes, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->bytes), bytes, IArrayObjectPrimitive<char>);
}
 BinaryContentByteStream::~BinaryContentByteStream() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void BinaryContentByteStream::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"BinaryContentByteStream", L"~BinaryContentByteStream");
	__e_obj1.add(this->bytes, this);
	bytes = nullptr;
	if(!prepare){
		return;
	}
}
int BinaryContentByteStream::length(ThreadContext* ctx) throw() 
{
	return bytes->length;
}
void BinaryContentByteStream::output(OutputStream* outStream, ThreadContext* ctx)
{
	outStream->write(this->bytes, ctx);
}
void BinaryContentByteStream::prepare(AlinousCore* core, bool debug, ThreadContext* ctx) throw() 
{
}
String* BinaryContentByteStream::getContentType(ThreadContext* ctx) throw() 
{
	return nullptr;
}
}}

