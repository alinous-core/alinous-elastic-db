#include "include/global.h"


#include "org.alinous.charset/CharsetDecoder.h"
#include "org.alinous.charset/CharsetEncoder.h"
#include "org.alinous.charset/CharsetConverter.h"
#include "org.alinous.charset/ISO_8859_1.h"

namespace org {namespace alinous {namespace charset {





bool ISO_8859_1::__init_done = __init_static_variables();
bool ISO_8859_1::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"ISO_8859_1", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 ISO_8859_1::ISO_8859_1(ThreadContext* ctx) throw()  : IObject(ctx), CharsetConverter(ctx), decoder(nullptr), encoder(nullptr)
{
	__GC_MV(this, &(decoder), (new(ctx) ISO_8859_1::Decoder(ctx)), CharsetDecoder);
	__GC_MV(this, &(encoder), (new(ctx) ISO_8859_1::Encoder(ctx)), CharsetEncoder);
}
void ISO_8859_1::__construct_impl(ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(decoder), (new(ctx) ISO_8859_1::Decoder(ctx)), CharsetDecoder);
	__GC_MV(this, &(encoder), (new(ctx) ISO_8859_1::Encoder(ctx)), CharsetEncoder);
}
 ISO_8859_1::~ISO_8859_1() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void ISO_8859_1::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"ISO_8859_1", L"~ISO_8859_1");
	__e_obj1.add(this->decoder, this);
	decoder = nullptr;
	__e_obj1.add(this->encoder, this);
	encoder = nullptr;
	if(!prepare){
		return;
	}
}
CharsetDecoder* ISO_8859_1::newDecoder(ThreadContext* ctx) throw() 
{
	return decoder;
}
CharsetEncoder* ISO_8859_1::newEncoder(ThreadContext* ctx) throw() 
{
	return encoder;
}
bool ISO_8859_1::contains(String* cs, ThreadContext* ctx) throw() 
{
	return cs->equalsIgnoreCase(ConstStr::getCNST_STR_924(), ctx) || cs->equalsIgnoreCase(ConstStr::getCNST_STR_916(), ctx);
}
void ISO_8859_1::__cleanUp(ThreadContext* ctx){
}
}}}

namespace org {namespace alinous {namespace charset {





bool ISO_8859_1::Decoder::__init_done = __init_static_variables();
bool ISO_8859_1::Decoder::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"ISO_8859_1::Decoder", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 ISO_8859_1::Decoder::Decoder(ThreadContext* ctx) throw()  : IObject(ctx), CharsetDecoder(ctx)
{
}
void ISO_8859_1::Decoder::__construct_impl(ThreadContext* ctx) throw() 
{
}
 ISO_8859_1::Decoder::~Decoder() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void ISO_8859_1::Decoder::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
}
CoderResult* ISO_8859_1::Decoder::decodeLoop(ByteBuffer* bb, CharBuffer* cb, ThreadContext* ctx) throw() 
{
	int bbRemaining = bb->remaining(ctx);
	if(bbRemaining == 0)
	{
		return CoderResult::UNDERFLOW;
	}
	int cbRemaining = cb->remaining(ctx);
	bool cbHasArray = cb->hasArray(ctx);
	if(cbHasArray)
	{
		if(bb->hasArray(ctx))
		{
			int rem = bbRemaining;
			rem = cbRemaining >= rem ? rem : cbRemaining;
			IArrayObjectPrimitive<char>* arr = bb->array(ctx);
			IArrayObjectPrimitive<wchar_t>* cArr = cb->array(ctx);
			int bStart = bb->position(ctx);
			int cStart = cb->position(ctx);
			int i = 0;
			for(i = bStart; i < bStart + rem; i ++ )
			{
				cArr->set(((wchar_t)(((int)arr->get(i)) & 0xFF)),cStart++, ctx);
			}
			bb->position(i, ctx);
			cb->position(cStart, ctx);
			if(rem == cbRemaining && bb->hasRemaining(ctx))
			{
				return CoderResult::OVERFLOW;
			}
			return CoderResult::UNDERFLOW;
		}
	}
	int rem = bbRemaining;
	rem = cbRemaining >= rem ? rem : cbRemaining;
	IArrayObjectPrimitive<char>* arr = ArrayAllocatorPrimitive<char>::allocatep(ctx, rem);
	bb->get(arr, ctx);
	IArrayObjectPrimitive<wchar_t>* cArr = ArrayAllocatorPrimitive<wchar_t>::allocatep(ctx, rem);
	for(int i = 0; i < rem; i ++ )
	{
		cArr->set(((wchar_t)(((int)arr->get(i)) & 0xFF)),i, ctx);
	}
	cb->put(cArr, ctx);
	if(cb->remaining(ctx) == 0)
	{
		return CoderResult::OVERFLOW;
	}
	return CoderResult::UNDERFLOW;
}
void ISO_8859_1::Decoder::__cleanUp(ThreadContext* ctx){
}
}}}

namespace org {namespace alinous {namespace charset {





bool ISO_8859_1::Encoder::__init_done = __init_static_variables();
bool ISO_8859_1::Encoder::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"ISO_8859_1::Encoder", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 ISO_8859_1::Encoder::Encoder(ThreadContext* ctx) throw()  : IObject(ctx), CharsetEncoder(ctx)
{
}
void ISO_8859_1::Encoder::__construct_impl(ThreadContext* ctx) throw() 
{
}
 ISO_8859_1::Encoder::~Encoder() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void ISO_8859_1::Encoder::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
}
CoderResult* ISO_8859_1::Encoder::encodeLoop(CharBuffer* cb, ByteBuffer* bb, ThreadContext* ctx) throw() 
{
	int cbRemaining = cb->remaining(ctx);
	if(cbRemaining == 0)
	{
		return CoderResult::UNDERFLOW;
	}
	int bbRemaining = bb->remaining(ctx);
	bool cbHasArray = cb->hasArray(ctx);
	bool bbHasArray = bb->hasArray(ctx);
	if(cbHasArray)
	{
		if(bbHasArray)
		{
			IArrayObjectPrimitive<char>* byteArr = bb->array(ctx);
			IArrayObjectPrimitive<wchar_t>* charArr = cb->array(ctx);
			int byteArrStart = bb->position(ctx);
			int rem = bbRemaining <= cbRemaining ? bbRemaining : cbRemaining;
			int cbPos = cb->position(ctx);
			int x = 0;
			int jchar = 0;
			for(x = cbPos; x < cbPos + rem; x ++ )
			{
				jchar = ((int)charArr->get(x));
				if(jchar <= 0xFF)
				{
					byteArr->set(((char)jchar),byteArrStart++, ctx);
				}
								else 
				{
					break ;
				}
			}
			bb->position(byteArrStart, ctx);
			cb->position(x, ctx);
			if(x == cbPos + rem)
			{
				if(rem == bbRemaining && cb->hasRemaining(ctx))
				{
					return CoderResult::OVERFLOW;
				}
				return CoderResult::UNDERFLOW;
			}
			if(jchar >= 0xD800 && jchar <= 0xDFFF)
			{
				if(x + 1 < cb->limit(ctx))
				{
					wchar_t c1 = charArr->get(x + 1);
					if(c1 >= (wchar_t)0xD800 && c1 <= (wchar_t)0xDFFF)
					{
						return CoderResult::unmappableForLength(2, ctx);
					}
				}
								else 
				{
					return CoderResult::UNDERFLOW;
				}
				return CoderResult::malformedForLength(1, ctx);
			}
			return CoderResult::unmappableForLength(1, ctx);
		}
	}
	while(cb->hasRemaining(ctx))
	{
		if(bbRemaining == 0)
		{
			return CoderResult::OVERFLOW;
		}
		wchar_t c = cb->get(ctx);
		if(c > ((wchar_t)0x00FF))
		{
			if(c >= (wchar_t)0xD800 && c <= (wchar_t)0xDFFF)
			{
				if(cb->hasRemaining(ctx))
				{
					wchar_t c1 = cb->get(ctx);
					if(c1 >= (wchar_t)0xD800 && c1 <= (wchar_t)0xDFFF)
					{
						cb->position(cb->position(ctx) - 2, ctx);
						return CoderResult::unmappableForLength(2, ctx);
					}
										else 
					{
						cb->position(cb->position(ctx) - 1, ctx);
					}
				}
								else 
				{
					cb->position(cb->position(ctx) - 1, ctx);
					return CoderResult::UNDERFLOW;
				}
				cb->position(cb->position(ctx) - 1, ctx);
				return CoderResult::malformedForLength(1, ctx);
			}
			cb->position(cb->position(ctx) - 1, ctx);
			return CoderResult::unmappableForLength(1, ctx);
		}
				else 
		{
			bb->put(((char)c), ctx);
			bbRemaining -- ;
		}
	}
	return CoderResult::UNDERFLOW;
}
void ISO_8859_1::Encoder::__cleanUp(ThreadContext* ctx){
}
}}}

