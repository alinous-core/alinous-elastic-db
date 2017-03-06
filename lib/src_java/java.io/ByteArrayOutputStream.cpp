#include "include/global.h"


#include "java.io/StringWriter.h"
#include "java.io/StringReader.h"
#include "java.io/FilterInputStream.h"
#include "java.io/BufferedInputStream.h"
#include "java.io/FilterOutputStream.h"
#include "java.io/BufferedOutputStream.h"
#include "java.io/ByteArrayOutputStream.h"

namespace java {namespace io {





bool ByteArrayOutputStream::__init_done = __init_static_variables();
bool ByteArrayOutputStream::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"ByteArrayOutputStream", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 ByteArrayOutputStream::ByteArrayOutputStream(ThreadContext* ctx) throw()  : IObject(ctx), OutputStream(ctx), buf(nullptr), count(0)
{
	__GC_MV(this, &(buf), ArrayAllocatorPrimitive<char>::allocatep(ctx, 32), IArrayObjectPrimitive<char>);
}
void ByteArrayOutputStream::__construct_impl(ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(buf), ArrayAllocatorPrimitive<char>::allocatep(ctx, 32), IArrayObjectPrimitive<char>);
}
 ByteArrayOutputStream::ByteArrayOutputStream(int size, ThreadContext* ctx) throw()  : IObject(ctx), OutputStream(ctx), buf(nullptr), count(0)
{
	if(size >= 0)
	{
		__GC_MV(this, &(buf), ArrayAllocatorPrimitive<char>::allocatep(ctx, size), IArrayObjectPrimitive<char>);
	}
		else 
	{
		throw (new(ctx) IllegalArgumentException(ConstStr::getCNST_STR_370(), ctx));
	}
}
void ByteArrayOutputStream::__construct_impl(int size, ThreadContext* ctx) throw() 
{
	if(size >= 0)
	{
		__GC_MV(this, &(buf), ArrayAllocatorPrimitive<char>::allocatep(ctx, size), IArrayObjectPrimitive<char>);
	}
		else 
	{
		throw (new(ctx) IllegalArgumentException(ConstStr::getCNST_STR_370(), ctx));
	}
}
 ByteArrayOutputStream::~ByteArrayOutputStream() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void ByteArrayOutputStream::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"ByteArrayOutputStream", L"~ByteArrayOutputStream");
	__e_obj1.add(this->buf, this);
	buf = nullptr;
	if(!prepare){
		return;
	}
	OutputStream::__releaseRegerences(true, ctx);
}
void ByteArrayOutputStream::close(ThreadContext* ctx)
{
	OutputStream::close(ctx);
}
void ByteArrayOutputStream::reset(ThreadContext* ctx) throw() 
{
	count = 0;
}
int ByteArrayOutputStream::size(ThreadContext* ctx) throw() 
{
	return count;
}
IArrayObjectPrimitive<char>* ByteArrayOutputStream::toByteArray(ThreadContext* ctx) throw() 
{
	IArrayObjectPrimitive<char>* newArray = ArrayAllocatorPrimitive<char>::allocatep(ctx, count);
	System::arraycopy(buf, 0, newArray, 0, count, ctx);
	return newArray;
}
String* ByteArrayOutputStream::toString(ThreadContext* ctx) throw() 
{
	return (new(ctx) String(buf, 0, count, ctx));
}
String* ByteArrayOutputStream::toString(int hibyte, ThreadContext* ctx) throw() 
{
	IArrayObjectPrimitive<wchar_t>* newBuf = ArrayAllocatorPrimitive<wchar_t>::allocatep(ctx, size(ctx));
	for(int i = 0; i < newBuf->length; i ++ )
	{
		newBuf->set(((wchar_t)(((hibyte & 0xff) << 8) | (buf->get(i) & 0xff))),i, ctx);
	}
	return (new(ctx) String(newBuf, ctx));
}
String* ByteArrayOutputStream::toString(String* enc, ThreadContext* ctx)
{
	return (new(ctx) String(buf, 0, count, enc, ctx));
}
void ByteArrayOutputStream::write(IArrayObjectPrimitive<char>* buffer, int offset, int len, ThreadContext* ctx) throw() 
{
	if(offset < 0 || offset > buffer->length || len < 0 || len > buffer->length - offset)
	{
		throw (new(ctx) IndexOutOfBoundsException(ConstStr::getCNST_STR_371(), ctx));
	}
	if(len == 0)
	{
		return;
	}
	expand(len, ctx);
	System::arraycopy(buffer, offset, buf, this->count, len, ctx);
	this->count += len;
}
void ByteArrayOutputStream::write(int oneByte, ThreadContext* ctx) throw() 
{
	if(count == buf->length)
	{
		expand(1, ctx);
	}
	buf->set(((char)oneByte),count++, ctx);
}
void ByteArrayOutputStream::writeTo(OutputStream* out, ThreadContext* ctx)
{
	out->write(buf, 0, count, ctx);
}
void ByteArrayOutputStream::flush(ThreadContext* ctx) throw() 
{
}
void ByteArrayOutputStream::expand(int i, ThreadContext* ctx) throw() 
{
	if(count + i <= buf->length)
	{
		return;
	}
	IArrayObjectPrimitive<char>* newbuf = ArrayAllocatorPrimitive<char>::allocatep(ctx, (count + i) * 2);
	System::arraycopy(buf, 0, newbuf, 0, count, ctx);
	__GC_MV(this, &(buf), newbuf, IArrayObjectPrimitive<char>);
}
void ByteArrayOutputStream::__cleanUp(ThreadContext* ctx){
}
}}

