#include "include/global.h"


#include "java.io/StringWriter.h"
#include "java.io/StringReader.h"
#include "java.io/FilterInputStream.h"
#include "java.io/BufferedInputStream.h"
#include "java.io/FilterOutputStream.h"
#include "java.io/BufferedOutputStream.h"
#include "java.io/ByteArrayOutputStream.h"

namespace java {namespace io {





bool FilterOutputStream::__init_done = __init_static_variables();
bool FilterOutputStream::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"FilterOutputStream", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 FilterOutputStream::FilterOutputStream(OutputStream* out, ThreadContext* ctx) throw()  : IObject(ctx), OutputStream(ctx), out(nullptr)
{
	__GC_MV(this, &(this->out), out, OutputStream);
}
void FilterOutputStream::__construct_impl(OutputStream* out, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->out), out, OutputStream);
}
 FilterOutputStream::~FilterOutputStream() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void FilterOutputStream::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"FilterOutputStream", L"~FilterOutputStream");
	__e_obj1.add(this->out, this);
	out = nullptr;
	if(!prepare){
		return;
	}
	OutputStream::__releaseRegerences(true, ctx);
}
void FilterOutputStream::close(ThreadContext* ctx)
{
	{
		try
		{
			flush(ctx);
		}
		catch(Throwable* e)
		{
		}
	}
	{
		try
		{
			out->close(ctx);
		}
		catch(Throwable* e)
		{
		}
	}
}
void FilterOutputStream::flush(ThreadContext* ctx)
{
	out->flush(ctx);
}
void FilterOutputStream::write(IArrayObjectPrimitive<char>* buffer, ThreadContext* ctx)
{
	write(buffer, 0, buffer->length, ctx);
}
void FilterOutputStream::write(IArrayObjectPrimitive<char>* buffer, int offset, int length, ThreadContext* ctx)
{
	if(offset > buffer->length || offset < 0)
	{
		throw (new(ctx) ArrayIndexOutOfBoundsException(ctx));
	}
	if(length < 0 || length > buffer->length - offset)
	{
		throw (new(ctx) ArrayIndexOutOfBoundsException(ctx));
	}
	for(int i = 0; i < length; i ++ )
	{
		write((int)buffer->get(offset + i), ctx);
	}
}
void FilterOutputStream::write(int oneByte, ThreadContext* ctx)
{
	out->write(oneByte, ctx);
}
}}

