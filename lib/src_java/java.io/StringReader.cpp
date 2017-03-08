#include "include/global.h"


#include "java.io/StringReader.h"
#include "alinous.lock/LockObject.h"

namespace java {namespace io {





bool StringReader::__init_done = __init_static_variables();
bool StringReader::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"StringReader", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 StringReader::StringReader(String* str, ThreadContext* ctx) throw()  : IObject(ctx), Reader(ctx), str(nullptr), markpos(-1), pos(0), count(0), lock(__GC_INS(this, (new(ctx) LockObject(ctx)), LockObject))
{
	__GC_MV(this, &(this->str), str, String);
	this->count = str->length(ctx);
}
void StringReader::__construct_impl(String* str, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->str), str, String);
	this->count = str->length(ctx);
}
 StringReader::~StringReader() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void StringReader::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"StringReader", L"~StringReader");
	__e_obj1.add(this->str, this);
	str = nullptr;
	__e_obj1.add(this->lock, this);
	lock = nullptr;
	if(!prepare){
		return;
	}
	Reader::__releaseRegerences(true, ctx);
}
void StringReader::close(ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(str), nullptr, String);
}
void StringReader::mark(int readLimit, ThreadContext* ctx)
{
	if(readLimit < 0)
	{
		throw (new(ctx) IllegalArgumentException(ctx));
	}
	{
		SynchronizedBlockObj __synchronized_2(lock, ctx);
		if(isClosed(ctx))
		{
			throw (new(ctx) IOException(ctx));
		}
		markpos = pos;
	}
}
bool StringReader::markSupported(ThreadContext* ctx) throw() 
{
	return true;
}
int StringReader::read(ThreadContext* ctx)
{
	{
		SynchronizedBlockObj __synchronized_2(lock, ctx);
		if(isClosed(ctx))
		{
			throw (new(ctx) IOException(ctx));
		}
		if(pos != count)
		{
			return str->charAt(pos++, ctx);
		}
		return -1;
	}
}
int StringReader::read(IArrayObjectPrimitive<wchar_t>* buf, int offset, int len, ThreadContext* ctx)
{
	{
		SynchronizedBlockObj __synchronized_2(lock, ctx);
		if(isClosed(ctx))
		{
			throw (new(ctx) IOException(ctx));
		}
		if(offset < 0 || offset > buf->length)
		{
			throw (new(ctx) ArrayIndexOutOfBoundsException(ctx));
		}
		if(len < 0 || len > buf->length - offset)
		{
			throw (new(ctx) ArrayIndexOutOfBoundsException(ctx));
		}
		if(len == 0)
		{
			return 0;
		}
		if(pos == this->count)
		{
			return -1;
		}
		int end = pos + len > this->count ? this->count : pos + len;
		str->getChars(pos, end, buf, offset, ctx);
		int read = end - pos;
		pos = end;
		return read;
	}
}
bool StringReader::ready(ThreadContext* ctx)
{
	{
		SynchronizedBlockObj __synchronized_2(lock, ctx);
		if(isClosed(ctx))
		{
			throw (new(ctx) IOException(ctx));
		}
		return true;
	}
}
void StringReader::reset(ThreadContext* ctx)
{
	{
		SynchronizedBlockObj __synchronized_2(lock, ctx);
		if(isClosed(ctx))
		{
			throw (new(ctx) IOException(ctx));
		}
		pos = markpos != -1 ? markpos : 0;
	}
}
long long StringReader::skip(long long ns, ThreadContext* ctx)
{
	{
		SynchronizedBlockObj __synchronized_2(lock, ctx);
		if(isClosed(ctx))
		{
			throw (new(ctx) IOException(ctx));
		}
		int minSkip = -pos;
		int maxSkip = count - pos;
		if(maxSkip == 0 || ns > (long long)maxSkip)
		{
			ns = maxSkip;
		}
				else 
		{
			if(ns < (long long)minSkip)
			{
				ns = minSkip;
			}
		}
		pos += ns;
		return ns;
	}
}
bool StringReader::isClosed(ThreadContext* ctx) throw() 
{
	return str == nullptr;
}
void StringReader::__cleanUp(ThreadContext* ctx){
}
}}

