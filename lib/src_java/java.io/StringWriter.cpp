#include "includes.h"


namespace java {namespace io {





String* StringWriter::TOKEN_NULL = ConstStr::getCNST_STR_369();
bool StringWriter::__init_done = __init_static_variables();
bool StringWriter::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"StringWriter", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 StringWriter::StringWriter(ThreadContext* ctx) throw()  : IObject(ctx), Writer(ctx), buf(nullptr)
{
	__GC_MV(this, &(buf), (new(ctx) StringBuffer(16, ctx)), StringBuffer);
}
void StringWriter::__construct_impl(ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(buf), (new(ctx) StringBuffer(16, ctx)), StringBuffer);
}
 StringWriter::StringWriter(int initialSize, ThreadContext* ctx) throw()  : IObject(ctx), Writer(ctx), buf(nullptr)
{
	if(initialSize < 0)
	{
		throw (new(ctx) IllegalArgumentException(ctx));
	}
	__GC_MV(this, &(buf), (new(ctx) StringBuffer(initialSize, ctx)), StringBuffer);
}
void StringWriter::__construct_impl(int initialSize, ThreadContext* ctx) throw() 
{
	if(initialSize < 0)
	{
		throw (new(ctx) IllegalArgumentException(ctx));
	}
	__GC_MV(this, &(buf), (new(ctx) StringBuffer(initialSize, ctx)), StringBuffer);
}
 StringWriter::~StringWriter() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void StringWriter::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"StringWriter", L"~StringWriter");
	__e_obj1.add(this->buf, this);
	buf = nullptr;
	if(!prepare){
		return;
	}
	Writer::__releaseRegerences(true, ctx);
}
void StringWriter::close(ThreadContext* ctx)
{
}
void StringWriter::flush(ThreadContext* ctx) throw() 
{
}
StringBuffer* StringWriter::getBuffer(ThreadContext* ctx) throw() 
{
	return buf;
}
String* StringWriter::toString(ThreadContext* ctx) throw() 
{
	return buf->toString(ctx);
}
void StringWriter::write(IArrayObjectPrimitive<wchar_t>* cbuf, int offset, int count, ThreadContext* ctx) throw() 
{
	if(offset < 0 || offset > cbuf->length || count < 0 || count > cbuf->length - offset)
	{
		throw (new(ctx) IndexOutOfBoundsException(ctx));
	}
	if(count == 0)
	{
		return;
	}
	buf->append(cbuf, offset, count, ctx);
}
void StringWriter::write(int oneChar, ThreadContext* ctx) throw() 
{
	buf->append(((wchar_t)oneChar), ctx);
}
void StringWriter::write(String* str, ThreadContext* ctx) throw() 
{
	buf->append(str, ctx);
}
void StringWriter::write(String* str, int offset, int count, ThreadContext* ctx) throw() 
{
	String* sub = str->substring(offset, offset + count, ctx);
	buf->append(sub, ctx);
}
StringWriter* StringWriter::append(wchar_t c, ThreadContext* ctx) throw() 
{
	write((int)c, ctx);
	return this;
}
StringWriter* StringWriter::append(CharSequence* csq, ThreadContext* ctx) throw() 
{
	if(nullptr == csq)
	{
		write(TOKEN_NULL, ctx);
	}
		else 
	{
		write(csq->toString(ctx), ctx);
	}
	return this;
}
StringWriter* StringWriter::append(CharSequence* csq, int start, int end, ThreadContext* ctx) throw() 
{
	if(nullptr == csq)
	{
		csq = TOKEN_NULL;
	}
	String* output = csq->subSequence(start, end, ctx)->toString(ctx);
	write(output, 0, output->length(ctx), ctx);
	return this;
}
}}

