#include "include/global.h"


#include "java.io/StringWriter.h"
#include "java.io/StringReader.h"
#include "java.io/FilterInputStream.h"
#include "java.io/BufferedInputStream.h"
#include "java.io/FilterOutputStream.h"
#include "java.io/BufferedOutputStream.h"
#include "java.io/ByteArrayOutputStream.h"

namespace java {namespace io {





bool BufferedInputStream::__init_done = __init_static_variables();
bool BufferedInputStream::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"BufferedInputStream", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 BufferedInputStream::BufferedInputStream(InputStream* in, ThreadContext* ctx) throw()  : IObject(ctx), FilterInputStream(in, ctx), buf(nullptr), count(0), marklimit(0), markpos(-1), pos(0)
{
	__GC_MV(this, &(buf), ArrayAllocatorPrimitive<char>::allocatep(ctx, 8192), IArrayObjectPrimitive<char>);
}
void BufferedInputStream::__construct_impl(InputStream* in, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(buf), ArrayAllocatorPrimitive<char>::allocatep(ctx, 8192), IArrayObjectPrimitive<char>);
}
 BufferedInputStream::BufferedInputStream(InputStream* in, int size, ThreadContext* ctx) throw()  : IObject(ctx), FilterInputStream(in, ctx), buf(nullptr), count(0), marklimit(0), markpos(-1), pos(0)
{
	if(size <= 0)
	{
		throw (new(ctx) IllegalArgumentException(ctx));
	}
	__GC_MV(this, &(buf), ArrayAllocatorPrimitive<char>::allocatep(ctx, size), IArrayObjectPrimitive<char>);
}
void BufferedInputStream::__construct_impl(InputStream* in, int size, ThreadContext* ctx) throw() 
{
	if(size <= 0)
	{
		throw (new(ctx) IllegalArgumentException(ctx));
	}
	__GC_MV(this, &(buf), ArrayAllocatorPrimitive<char>::allocatep(ctx, size), IArrayObjectPrimitive<char>);
}
 BufferedInputStream::~BufferedInputStream() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void BufferedInputStream::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"BufferedInputStream", L"~BufferedInputStream");
	__e_obj1.add(this->buf, this);
	buf = nullptr;
	if(!prepare){
		return;
	}
	FilterInputStream::__releaseRegerences(true, ctx);
}
int BufferedInputStream::available(ThreadContext* ctx)
{
	InputStream* localIn = in;
	if(buf == (IArrayObjectPrimitive<char>*)nullptr || localIn == nullptr)
	{
		throw (new(ctx) IOException(ctx));
	}
	return count - pos + localIn->available(ctx);
}
void BufferedInputStream::close(ThreadContext* ctx)
{
	__GC_MV(this, &(buf), nullptr, IArrayObjectPrimitive<char>);
	InputStream* localIn = in;
	__GC_MV(this, &(in), nullptr, InputStream);
	if(localIn != nullptr)
	{
		localIn->close(ctx);
	}
}
void BufferedInputStream::mark(int readlimit, ThreadContext* ctx) throw() 
{
	marklimit = readlimit;
	markpos = pos;
}
bool BufferedInputStream::markSupported(ThreadContext* ctx) throw() 
{
	return true;
}
int BufferedInputStream::read(ThreadContext* ctx)
{
	IArrayObjectPrimitive<char>* localBuf = buf;
	InputStream* localIn = in;
	if(__builtin_expect(localBuf == (IArrayObjectPrimitive<char>*)nullptr || localIn == nullptr, 0))
	{
		throw (new(ctx) IOException(ctx));
	}
	if(__builtin_expect(pos >= count && fillbuf(localIn, localBuf, ctx) == -1, 0))
	{
		return -1;
	}
	if(localBuf != buf)
	{
		localBuf = buf;
		if(__builtin_expect(localBuf == (IArrayObjectPrimitive<char>*)nullptr, 0))
		{
			throw (new(ctx) IOException(ctx));
		}
	}
	if(__builtin_expect(count - pos > 0, 1))
	{
		return localBuf->get(pos++) & 0xFF;
	}
	return -1;
}
int BufferedInputStream::read(IArrayObjectPrimitive<char>* buffer, int offset, int length, ThreadContext* ctx)
{
	IArrayObjectPrimitive<char>* localBuf = buf;
	if(localBuf == (IArrayObjectPrimitive<char>*)nullptr)
	{
		throw (new(ctx) IOException(ctx));
	}
	if(offset > buffer->length - length || offset < 0 || length < 0)
	{
		throw (new(ctx) IndexOutOfBoundsException(ctx));
	}
	if(length == 0)
	{
		return 0;
	}
	InputStream* localIn = in;
	if(localIn == nullptr)
	{
		throw (new(ctx) IOException(ctx));
	}
	int required = 0;
	if(pos < count)
	{
		int copylength = count - pos >= length ? length : count - pos;
		System::arraycopy(localBuf, pos, buffer, offset, copylength, ctx);
		pos += copylength;
		if(copylength == length || localIn->available(ctx) == 0)
		{
			return copylength;
		}
		offset += copylength;
		required = length - copylength;
	}
		else 
	{
		required = length;
	}
	while(true)
	{
		int read = 0;
		if(markpos == -1 && required >= localBuf->length)
		{
			read = localIn->read(buffer, offset, required, ctx);
			if(read == -1)
			{
				return required == length ? -1 : length - required;
			}
		}
				else 
		{
			if(fillbuf(localIn, localBuf, ctx) == -1)
			{
				return required == length ? -1 : length - required;
			}
			if(localBuf != buf)
			{
				localBuf = buf;
				if(localBuf == (IArrayObjectPrimitive<char>*)nullptr)
				{
					throw (new(ctx) IOException(ctx));
				}
			}
			read = count - pos >= required ? required : count - pos;
			System::arraycopy(localBuf, pos, buffer, offset, read, ctx);
			pos += read;
		}
		required -= read;
		if(required == 0)
		{
			return length;
		}
		if(localIn->available(ctx) == 0)
		{
			return length - required;
		}
		offset += read;
	}
}
void BufferedInputStream::reset(ThreadContext* ctx)
{
	if(buf == (IArrayObjectPrimitive<char>*)nullptr)
	{
		throw (new(ctx) IOException(ctx));
	}
	if(-1 == markpos)
	{
		throw (new(ctx) IOException(ctx));
	}
	pos = markpos;
}
long long BufferedInputStream::skip(long long amount, ThreadContext* ctx)
{
	IArrayObjectPrimitive<char>* localBuf = buf;
	InputStream* localIn = in;
	if(localBuf == (IArrayObjectPrimitive<char>*)nullptr)
	{
		throw (new(ctx) IOException(ctx));
	}
	if(amount < (long long)1)
	{
		return 0;
	}
	if(localIn == nullptr)
	{
		throw (new(ctx) IOException(ctx));
	}
	if(count - pos >= (int)amount)
	{
		pos += amount;
		return amount;
	}
	long long read = count - pos;
	pos = count;
	if(markpos != -1)
	{
		if(amount <= (long long)marklimit)
		{
			if(fillbuf(localIn, localBuf, ctx) == -1)
			{
				return read;
			}
			if(count - pos >= (int)amount - read)
			{
				pos += amount - read;
				return amount;
			}
			read += (count - pos);
			pos = count;
			return read;
		}
	}
	return read + localIn->skip(amount - read, ctx);
}
int BufferedInputStream::fillbuf(InputStream* localIn, IArrayObjectPrimitive<char>* localBuf, ThreadContext* ctx)
{
	if(markpos == -1 || (pos - markpos >= marklimit))
	{
		int result = localIn->read(localBuf, ctx);
		if(result > 0)
		{
			markpos = -1;
			pos = 0;
			count = result == -1 ? 0 : result;
		}
		return result;
	}
	if(markpos == 0 && marklimit > localBuf->length)
	{
		int newLength = localBuf->length * 2;
		if(newLength > marklimit)
		{
			newLength = marklimit;
		}
		IArrayObjectPrimitive<char>* newbuf = ArrayAllocatorPrimitive<char>::allocatep(ctx, newLength);
		System::arraycopy(localBuf, 0, newbuf, 0, localBuf->length, ctx);
		__GC_MV(this, &(buf), newbuf, IArrayObjectPrimitive<char>);
		localBuf = buf;
	}
		else 
	{
		if(markpos > 0)
		{
			System::arraycopy(localBuf, markpos, localBuf, 0, localBuf->length - markpos, ctx);
		}
	}
	pos -= markpos;
	count = markpos = 0;
	int bytesread = localIn->read(localBuf, pos, localBuf->length - pos, ctx);
	count = bytesread <= 0 ? pos : pos + bytesread;
	return bytesread;
}
void BufferedInputStream::__cleanUp(ThreadContext* ctx){
}
}}

