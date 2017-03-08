#include "include/global.h"


#include "org.alinous.charset/CharsetDecoder.h"
#include "org.alinous.charset/CharsetEncoder.h"
#include "org.alinous.charset/CharsetConverter.h"
#include "org.alinous.charset/US_ASCII.h"

namespace org {namespace alinous {namespace charset {





bool US_ASCII::__init_done = __init_static_variables();
bool US_ASCII::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"US_ASCII", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 US_ASCII::US_ASCII(ThreadContext* ctx) throw()  : IObject(ctx), CharsetConverter(ctx), decoder(nullptr), encoder(nullptr)
{
	__GC_MV(this, &(decoder), (new(ctx) US_ASCII::Decoder(ctx)), CharsetDecoder);
	__GC_MV(this, &(encoder), (new(ctx) US_ASCII::Encoder(ctx)), CharsetEncoder);
}
void US_ASCII::__construct_impl(ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(decoder), (new(ctx) US_ASCII::Decoder(ctx)), CharsetDecoder);
	__GC_MV(this, &(encoder), (new(ctx) US_ASCII::Encoder(ctx)), CharsetEncoder);
}
 US_ASCII::~US_ASCII() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void US_ASCII::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"US_ASCII", L"~US_ASCII");
	__e_obj1.add(this->decoder, this);
	decoder = nullptr;
	__e_obj1.add(this->encoder, this);
	encoder = nullptr;
	if(!prepare){
		return;
	}
}
CharsetDecoder* US_ASCII::newDecoder(ThreadContext* ctx) throw() 
{
	return decoder;
}
CharsetEncoder* US_ASCII::newEncoder(ThreadContext* ctx) throw() 
{
	return encoder;
}
bool US_ASCII::contains(String* cs, ThreadContext* ctx) throw() 
{
	return cs->equalsIgnoreCase(ConstStr::getCNST_STR_916(), ctx);
}
void US_ASCII::__cleanUp(ThreadContext* ctx){
}
}}}

namespace org {namespace alinous {namespace charset {





bool US_ASCII::Decoder::__init_done = __init_static_variables();
bool US_ASCII::Decoder::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"US_ASCII::Decoder", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 US_ASCII::Decoder::Decoder(ThreadContext* ctx) throw()  : IObject(ctx), CharsetDecoder(ctx)
{
}
void US_ASCII::Decoder::__construct_impl(ThreadContext* ctx) throw() 
{
}
 US_ASCII::Decoder::~Decoder() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void US_ASCII::Decoder::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
}
CoderResult* US_ASCII::Decoder::decodeLoop(ByteBuffer* bb, CharBuffer* cb, ThreadContext* ctx) throw() 
{
	{
		int cbRemaining = cb->remaining(ctx);
		if(bb->hasArray(ctx) && cb->hasArray(ctx))
		{
			int rem = bb->remaining(ctx);
			rem = cbRemaining >= rem ? rem : cbRemaining;
			IArrayObjectPrimitive<char>* bArr = bb->array(ctx);
			IArrayObjectPrimitive<wchar_t>* cArr = cb->array(ctx);
			int bStart = bb->position(ctx);
			int cStart = cb->position(ctx);
			int i = 0;
			for(i = bStart; i < bStart + rem; i ++ )
			{
				char b = bArr->get(i);
				if(b < (char)0)
				{
					bb->position(i, ctx);
					cb->position(cStart, ctx);
					return CoderResult::malformedForLength(1, ctx);
				}
				cArr->set(((wchar_t)b),cStart++, ctx);
			}
			bb->position(i, ctx);
			cb->position(cStart, ctx);
			if(rem == cbRemaining && bb->hasRemaining(ctx))
			{
				return CoderResult::OVERFLOW;
			}
		}
				else 
		{
			while(bb->hasRemaining(ctx))
			{
				if(cbRemaining == 0)
				{
					return CoderResult::OVERFLOW;
				}
				char b = bb->get(ctx);
				if(b < (char)0)
				{
					bb->position(bb->position(ctx) - 1, ctx);
					return CoderResult::malformedForLength(1, ctx);
				}
				cb->put(((wchar_t)b), ctx);
				cbRemaining -- ;
			}
		}
	}
	return CoderResult::UNDERFLOW;
}
void US_ASCII::Decoder::__cleanUp(ThreadContext* ctx){
}
}}}

namespace org {namespace alinous {namespace charset {





bool US_ASCII::Encoder::__init_done = __init_static_variables();
bool US_ASCII::Encoder::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"US_ASCII::Encoder", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 US_ASCII::Encoder::Encoder(ThreadContext* ctx) throw()  : IObject(ctx), CharsetEncoder(ctx)
{
}
void US_ASCII::Encoder::__construct_impl(ThreadContext* ctx) throw() 
{
}
 US_ASCII::Encoder::~Encoder() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void US_ASCII::Encoder::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
}
CoderResult* US_ASCII::Encoder::encodeLoop(CharBuffer* cb, ByteBuffer* bb, ThreadContext* ctx) throw() 
{
	int bbRemaining = bb->remaining(ctx);
	{
		if(bb->hasArray(ctx) && cb->hasArray(ctx))
		{
			IArrayObjectPrimitive<char>* byteArr = bb->array(ctx);
			IArrayObjectPrimitive<wchar_t>* charArr = cb->array(ctx);
			int rem = cb->remaining(ctx);
			int byteArrStart = bb->position(ctx);
			rem = bbRemaining <= rem ? bbRemaining : rem;
			int x = 0;
			for(x = cb->position(ctx); x < cb->position(ctx) + rem; x ++ )
			{
				wchar_t c = charArr->get(x);
				if(c > (wchar_t)Byte::MAX_VALUE)
				{
					if(c >= (wchar_t)0xD800 && c <= (wchar_t)0xDFFF)
					{
						if(x + 1 < cb->limit(ctx))
						{
							wchar_t c1 = charArr->get(x + 1);
							if(c1 >= (wchar_t)0xD800 && c1 <= (wchar_t)0xDFFF)
							{
								cb->position(x, ctx);
								bb->position(byteArrStart, ctx);
								return CoderResult::unmappableForLength(2, ctx);
							}
						}
												else 
						{
							cb->position(x, ctx);
							bb->position(byteArrStart, ctx);
							return CoderResult::UNDERFLOW;
						}
						cb->position(x, ctx);
						bb->position(byteArrStart, ctx);
						return CoderResult::malformedForLength(1, ctx);
					}
					cb->position(x, ctx);
					bb->position(byteArrStart, ctx);
					return CoderResult::unmappableForLength(1, ctx);
				}
				byteArr->set(((char)c),byteArrStart++, ctx);
			}
			cb->position(x, ctx);
			bb->position(byteArrStart, ctx);
			if(rem == bbRemaining && cb->hasRemaining(ctx))
			{
				return CoderResult::OVERFLOW;
			}
		}
				else 
		{
			while(cb->hasRemaining(ctx))
			{
				if(bbRemaining == 0)
				{
					return CoderResult::OVERFLOW;
				}
				wchar_t c = cb->get(ctx);
				if(c > (wchar_t)Byte::MAX_VALUE)
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
				bb->put(((char)c), ctx);
				bbRemaining -- ;
			}
		}
	}
	return CoderResult::UNDERFLOW;
}
void US_ASCII::Encoder::__cleanUp(ThreadContext* ctx){
}
}}}

