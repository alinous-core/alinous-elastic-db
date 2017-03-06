#include "include/global.h"


#include "java.io/StringWriter.h"
#include "java.io/StringReader.h"
#include "java.io/FilterInputStream.h"
#include "java.io/BufferedInputStream.h"
#include "java.io/FilterOutputStream.h"
#include "java.io/BufferedOutputStream.h"
#include "java.io/ByteArrayOutputStream.h"

namespace java {namespace io {





bool FilterInputStream::__init_done = __init_static_variables();
bool FilterInputStream::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"FilterInputStream", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 FilterInputStream::FilterInputStream(InputStream* in, ThreadContext* ctx) throw()  : IObject(ctx), InputStream(ctx), in(nullptr)
{
	__GC_MV(this, &(this->in), in, InputStream);
}
void FilterInputStream::__construct_impl(InputStream* in, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->in), in, InputStream);
}
 FilterInputStream::~FilterInputStream() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void FilterInputStream::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"FilterInputStream", L"~FilterInputStream");
	__e_obj1.add(this->in, this);
	in = nullptr;
	if(!prepare){
		return;
	}
	InputStream::__releaseRegerences(true, ctx);
}
int FilterInputStream::available(ThreadContext* ctx)
{
	return in->available(ctx);
}
void FilterInputStream::close(ThreadContext* ctx)
{
	in->close(ctx);
}
void FilterInputStream::mark(int readlimit, ThreadContext* ctx) throw() 
{
	in->mark(readlimit, ctx);
}
bool FilterInputStream::markSupported(ThreadContext* ctx) throw() 
{
	return in->markSupported(ctx);
}
int FilterInputStream::read(ThreadContext* ctx)
{
	return in->read(ctx);
}
int FilterInputStream::read(IArrayObjectPrimitive<char>* buffer, ThreadContext* ctx)
{
	return read(buffer, 0, buffer->length, ctx);
}
int FilterInputStream::read(IArrayObjectPrimitive<char>* buffer, int offset, int count, ThreadContext* ctx)
{
	return in->read(buffer, offset, count, ctx);
}
void FilterInputStream::reset(ThreadContext* ctx)
{
	in->reset(ctx);
}
long long FilterInputStream::skip(long long count, ThreadContext* ctx)
{
	return in->skip(count, ctx);
}
void FilterInputStream::__cleanUp(ThreadContext* ctx){
}
}}

