#include "include/global.h"


#include "alinous.net/UnknownHostException.h"
#include "org.alinous.charset/CharsetDecoder.h"
#include "org.alinous.charset/CharsetEncoder.h"
#include "org.alinous.charset/CharsetConverter.h"
#include "org.alinous.charset/CharsetManager.h"
#include "alinous.net/URLDecoder.h"
#include "alinous.net/URLEncoder.h"

namespace alinous {namespace net {





bool URLDecoder::__init_done = __init_static_variables();
bool URLDecoder::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"URLDecoder", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 URLDecoder::URLDecoder(ThreadContext* ctx) throw()  : IObject(ctx)
{
}
void URLDecoder::__construct_impl(ThreadContext* ctx) throw() 
{
}
 URLDecoder::~URLDecoder() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void URLDecoder::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
}
String* URLDecoder::decode(String* s, String* enc, ThreadContext* ctx)
{
	if(enc == nullptr)
	{
		throw (new(ctx) NullPointerException(ctx));
	}
	if(enc->length(ctx) == 0)
	{
		throw (new(ctx) UnsupportedEncodingException(ConstStr::getCNST_STR_0(), ctx));
	}
	if(s->indexOf((int)L'%', ctx) == -1)
	{
		if(s->indexOf((int)L'+', ctx) == -1)
		{
			return s;
		}
		IArrayObjectPrimitive<wchar_t>* str = s->toCharArray(ctx);
		for(int i = 0; i < str->length; i ++ )
		{
			if(str->get(i) == L'+')
			{
				str->set(L' ',i, ctx);
			}
		}
		return (new(ctx) String(str, ctx));
	}
	CharsetManager* manager = CharsetManager::getInstance(ctx);
	CharsetDecoder* decoder = manager->getDecoder(enc, ctx);
	return decode(s, decoder, ctx);
}
CharBuffer* URLDecoder::decode(ByteBuffer* in, CharsetDecoder* decoder, ThreadContext* ctx) throw() 
{
	int length = in->remaining(ctx);
	CharBuffer* output = CharBuffer::allocate(length, ctx);
	decoder->decodeLoop(in, output, ctx);
	return output;
}
String* URLDecoder::decode(String* s, CharsetDecoder* decoder, ThreadContext* ctx) throw() 
{
	IArrayObjectPrimitive<wchar_t>* str_buf = ArrayAllocatorPrimitive<wchar_t>::allocatep(ctx, s->length(ctx));
	IArrayObjectPrimitive<char>* buf = ArrayAllocatorPrimitive<char>::allocatep(ctx, s->length(ctx) / 3);
	int buf_len = 0;
	for(int i = 0; i < s->length(ctx); )
	{
		wchar_t c = s->charAt(i, ctx);
		if(c == L'+')
		{
			str_buf->set(L' ',buf_len, ctx);
		}
				else 
		{
			if(c == L'%')
			{
				int len = 0;
				do
				{
					if(i + 2 >= s->length(ctx))
					{
						throw (new(ctx) IllegalArgumentException(ConstStr::getCNST_STR_1()->clone(ctx)->append(i, ctx), ctx));
					}
					int d1 = Character::digit(s->charAt(i + 1, ctx), 16, ctx);
					int d2 = Character::digit(s->charAt(i + 2, ctx), 16, ctx);
					if(d1 == -1 || d2 == -1)
					{
						throw (new(ctx) IllegalArgumentException(ConstStr::getCNST_STR_2()->clone(ctx)->append(s->substring(i, i + 3, ctx), ctx)->append(ConstStr::getCNST_STR_3(), ctx)->append(String::valueOf(i, ctx), ctx), ctx));
					}
					buf->set(((char)((d1 << 4) + d2)),len++, ctx);
					i += 3;
				}
				while(i < s->length(ctx) && s->charAt(i, ctx) == L'%');
				CharBuffer* cb = decode(ByteBuffer::wrap(buf, 0, len, ctx), decoder, ctx);
				cb->position(0, ctx);
				len = cb->length(ctx);
				System::arraycopy(cb->array(ctx), 0, str_buf, buf_len, len, ctx);
				buf_len += len;
				continue;
			}
						else 
			{
				str_buf->set(c,buf_len, ctx);
			}
		}
		i ++ ;
		buf_len ++ ;
	}
	return (new(ctx) String(str_buf, 0, buf_len, ctx));
}
void URLDecoder::__cleanUp(ThreadContext* ctx){
}
}}

