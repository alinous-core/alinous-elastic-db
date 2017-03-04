#include "include/global.h"


#include "java.io/StringWriter.h"
#include "java.io/StringReader.h"
#include "java.io/FilterInputStream.h"
#include "java.io/BufferedInputStream.h"
#include "java.io/FilterOutputStream.h"
#include "java.io/BufferedOutputStream.h"
#include "java.io/ByteArrayOutputStream.h"

namespace java {namespace io {





bool BufferedOutputStream::__init_done = __init_static_variables();
bool BufferedOutputStream::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"BufferedOutputStream", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 BufferedOutputStream::BufferedOutputStream(OutputStream* out, ThreadContext* ctx) throw()  : IObject(ctx), FilterOutputStream(out, ctx), buf(nullptr), count(0)
{
	__GC_MV(this, &(buf), ArrayAllocatorPrimitive<char>::allocatep(ctx, 8192), IArrayObjectPrimitive<char>);
}
void BufferedOutputStream::__construct_impl(OutputStream* out, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(buf), ArrayAllocatorPrimitive<char>::allocatep(ctx, 8192), IArrayObjectPrimitive<char>);
}
 BufferedOutputStream::BufferedOutputStream(OutputStream* out, int size, ThreadContext* ctx) throw()  : IObject(ctx), FilterOutputStream(out, ctx), buf(nullptr), count(0)
{
	if(size <= 0)
	{
		throw (new(ctx) IllegalArgumentException(ctx));
	}
	__GC_MV(this, &(buf), ArrayAllocatorPrimitive<char>::allocatep(ctx, size), IArrayObjectPrimitive<char>);
}
void BufferedOutputStream::__construct_impl(OutputStream* out, int size, ThreadContext* ctx) throw() 
{
	if(size <= 0)
	{
		throw (new(ctx) IllegalArgumentException(ctx));
	}
	__GC_MV(this, &(buf), ArrayAllocatorPrimitive<char>::allocatep(ctx, size), IArrayObjectPrimitive<char>);
}
 BufferedOutputStream::~BufferedOutputStream() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void BufferedOutputStream::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"BufferedOutputStream", L"~BufferedOutputStream");
	__e_obj1.add(this->buf, this);
	buf = nullptr;
	if(!prepare){
		return;
	}
	FilterOutputStream::__releaseRegerences(true, ctx);
}
void BufferedOutputStream::flush(ThreadContext* ctx)
{
	flushInternal(ctx);
	out->flush(ctx);
}
void BufferedOutputStream::write(IArrayObjectPrimitive<char>* buffer, int offset, int length, ThreadContext* ctx)
{
	IArrayObjectPrimitive<char>* internalBuffer = buf;
	if(internalBuffer != (IArrayObjectPrimitive<char>*)nullptr && length >= internalBuffer->length)
	{
		flushInternal(ctx);
		out->write(buffer, offset, length, ctx);
		return;
	}
	if(buffer == (IArrayObjectPrimitive<char>*)nullptr)
	{
		throw (new(ctx) NullPointerException(ctx));
	}
	if(offset < 0 || offset > buffer->length - length)
	{
		throw (new(ctx) ArrayIndexOutOfBoundsException(ctx));
	}
	if(length < 0)
	{
		throw (new(ctx) ArrayIndexOutOfBoundsException(ctx));
	}
	if(internalBuffer == (IArrayObjectPrimitive<char>*)nullptr)
	{
		throw (new(ctx) IOException(ctx));
	}
	if(length >= (internalBuffer->length - count))
	{
		flushInternal(ctx);
	}
	System::arraycopy(buffer, offset, internalBuffer, count, length, ctx);
	count += length;
}
void BufferedOutputStream::close(ThreadContext* ctx)
{
	if(buf == (IArrayObjectPrimitive<char>*)nullptr)
	{
		return;
	}
	{
		try
		{
			FilterOutputStream::close(ctx);
		}
		catch(Throwable* e)
		{
			__GC_MV(this, &(buf), nullptr, IArrayObjectPrimitive<char>);
			throw e;
		}
	}
	__GC_MV(this, &(buf), nullptr, IArrayObjectPrimitive<char>);
}
void BufferedOutputStream::write(int oneByte, ThreadContext* ctx)
{
	IArrayObjectPrimitive<char>* internalBuffer = buf;
	if(internalBuffer == (IArrayObjectPrimitive<char>*)nullptr)
	{
		throw (new(ctx) IOException(ctx));
	}
	if(count == internalBuffer->length)
	{
		out->write(internalBuffer, 0, count, ctx);
		count = 0;
	}
	internalBuffer->set(((char)oneByte),count++, ctx);
}
void BufferedOutputStream::flushInternal(ThreadContext* ctx)
{
	if(count > 0)
	{
		out->write(buf, 0, count, ctx);
		count = 0;
	}
}
}}

