#include "include/global.h"


#include "alinous.net/URLEncoder.h"

namespace alinous {namespace net {





String* URLEncoder::digits = ConstStr::getCNST_STR_6();
bool URLEncoder::__init_done = __init_static_variables();
bool URLEncoder::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"URLEncoder", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 URLEncoder::URLEncoder(ThreadContext* ctx) throw()  : IObject(ctx)
{
}
void URLEncoder::__construct_impl(ThreadContext* ctx) throw() 
{
}
 URLEncoder::~URLEncoder() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void URLEncoder::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
}
String* URLEncoder::encode(String* s, String* enc, ThreadContext* ctx)
{
	if(s == nullptr || enc == nullptr)
	{
		throw (new(ctx) NullPointerException(ctx));
	}
	ConstStr::getCNST_STR_4()->getBytes(enc, ctx);
	StringBuffer* buf = (new(ctx) StringBuffer(s->length(ctx) + 16, ctx));
	int start = -1;
	for(int i = 0; i < s->length(ctx); i ++ )
	{
		wchar_t ch = s->charAt(i, ctx);
		if((ch >= L'a' && ch <= L'z') || (ch >= L'A' && ch <= L'Z') || (ch >= L'0' && ch <= L'9') || ConstStr::getCNST_STR_5()->indexOf((int)ch, ctx) > -1)
		{
			if(start >= 0)
			{
				convert(s->substring(start, i, ctx), buf, enc, ctx);
				start = -1;
			}
			if(ch != L' ')
			{
				buf->append(ch, ctx);
			}
						else 
			{
				buf->append(L'+', ctx);
			}
		}
				else 
		{
			if(start < 0)
			{
				start = i;
			}
		}
	}
	if(start >= 0)
	{
		convert(s->substring(start, s->length(ctx), ctx), buf, enc, ctx);
	}
	return buf->toString(ctx);
}
void URLEncoder::convert(String* s, StringBuffer* buf, String* enc, ThreadContext* ctx)
{
	IArrayObjectPrimitive<char>* bytes = s->getBytes(enc, ctx);
	for(int j = 0; j < bytes->length; j ++ )
	{
		buf->append(L'%', ctx);
		buf->append(digits->charAt((int)(bytes->get(j) & 0xf0) >> 4, ctx), ctx);
		buf->append(digits->charAt((int)bytes->get(j) & 0xf, ctx), ctx);
	}
}
void URLEncoder::__cleanUp(ThreadContext* ctx){
}
}}

