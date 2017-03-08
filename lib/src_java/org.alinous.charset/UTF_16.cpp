#include "include/global.h"


#include "org.alinous.charset/CharsetDecoder.h"
#include "org.alinous.charset/CharsetEncoder.h"
#include "org.alinous.charset/CharsetConverter.h"
#include "org.alinous.charset/UTF_16.h"

namespace org {namespace alinous {namespace charset {





constexpr const int UTF_16::UNKNOWN;
constexpr const int UTF_16::BIG;
constexpr const int UTF_16::LITTLE;
constexpr const int UTF_16::ANY;
constexpr const int UTF_16::NOT_DETECTED;
bool UTF_16::__init_done = __init_static_variables();
bool UTF_16::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"UTF_16", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 UTF_16::UTF_16(ThreadContext* ctx) throw()  : IObject(ctx), CharsetConverter(ctx), decoder(nullptr), encoder(nullptr)
{
	__GC_MV(this, &(decoder), (new(ctx) UTF_16::Decoder(ctx)), CharsetDecoder);
	__GC_MV(this, &(encoder), (new(ctx) UTF_16::Encoder(ctx)), CharsetEncoder);
}
void UTF_16::__construct_impl(ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(decoder), (new(ctx) UTF_16::Decoder(ctx)), CharsetDecoder);
	__GC_MV(this, &(encoder), (new(ctx) UTF_16::Encoder(ctx)), CharsetEncoder);
}
 UTF_16::~UTF_16() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void UTF_16::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"UTF_16", L"~UTF_16");
	__e_obj1.add(this->decoder, this);
	decoder = nullptr;
	__e_obj1.add(this->encoder, this);
	encoder = nullptr;
	if(!prepare){
		return;
	}
}
CharsetDecoder* UTF_16::newDecoder(ThreadContext* ctx) throw() 
{
	return decoder;
}
CharsetEncoder* UTF_16::newEncoder(ThreadContext* ctx) throw() 
{
	return encoder;
}
bool UTF_16::contains(String* cs, ThreadContext* ctx) throw() 
{
	return cs->equalsIgnoreCase(ConstStr::getCNST_STR_891(), ctx) || cs->equalsIgnoreCase(ConstStr::getCNST_STR_892(), ctx) || cs->equalsIgnoreCase(ConstStr::getCNST_STR_893(), ctx) || cs->equalsIgnoreCase(ConstStr::getCNST_STR_894(), ctx) || cs->equalsIgnoreCase(ConstStr::getCNST_STR_895(), ctx) || cs->equalsIgnoreCase(ConstStr::getCNST_STR_896(), ctx) || cs->equalsIgnoreCase(ConstStr::getCNST_STR_897(), ctx) || cs->equalsIgnoreCase(ConstStr::getCNST_STR_898(), ctx) || cs->equalsIgnoreCase(ConstStr::getCNST_STR_899(), ctx) || cs->equalsIgnoreCase(ConstStr::getCNST_STR_900(), ctx) || cs->equalsIgnoreCase(ConstStr::getCNST_STR_901(), ctx) || cs->equalsIgnoreCase(ConstStr::getCNST_STR_902(), ctx) || cs->equalsIgnoreCase(ConstStr::getCNST_STR_903(), ctx) || cs->equalsIgnoreCase(ConstStr::getCNST_STR_904(), ctx) || cs->equalsIgnoreCase(ConstStr::getCNST_STR_905(), ctx) || cs->equalsIgnoreCase(ConstStr::getCNST_STR_906(), ctx) || cs->equalsIgnoreCase(ConstStr::getCNST_STR_907(), ctx) || cs->equalsIgnoreCase(ConstStr::getCNST_STR_908(), ctx) || cs->equalsIgnoreCase(ConstStr::getCNST_STR_909(), ctx) || cs->equalsIgnoreCase(ConstStr::getCNST_STR_910(), ctx) || cs->equalsIgnoreCase(ConstStr::getCNST_STR_120(), ctx) || cs->equalsIgnoreCase(ConstStr::getCNST_STR_911(), ctx) || cs->equalsIgnoreCase(ConstStr::getCNST_STR_912(), ctx);
}
void UTF_16::__cleanUp(ThreadContext* ctx){
}
}}}

namespace org {namespace alinous {namespace charset {





constexpr const int UTF_16::Decoder::UNKNOWN;
constexpr const int UTF_16::Decoder::BIG;
constexpr const int UTF_16::Decoder::LITTLE;
constexpr const int UTF_16::Decoder::ANY;
constexpr const int UTF_16::Decoder::NOT_DETECTED;
bool UTF_16::Decoder::__init_done = __init_static_variables();
bool UTF_16::Decoder::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"UTF_16::Decoder", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 UTF_16::Decoder::Decoder(ThreadContext* ctx) throw()  : IObject(ctx), CharsetDecoder(ctx), endian(0)
{
	implReset(ctx);
}
void UTF_16::Decoder::__construct_impl(ThreadContext* ctx) throw() 
{
	implReset(ctx);
}
 UTF_16::Decoder::~Decoder() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void UTF_16::Decoder::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"Decoder", L"~Decoder");
	if(!prepare){
		return;
	}
}
CoderResult* UTF_16::Decoder::decodeLoop(ByteBuffer* in, CharBuffer* out, ThreadContext* ctx) throw() 
{
	int outRemaining = out->remaining(ctx);
	int pos = in->position(ctx);
	int limit = in->limit(ctx);
	{
		try
		{
			while(pos < limit - 1)
			{
				if(outRemaining == 0)
				{
					in->position(pos, ctx);
					return CoderResult::OVERFLOW;
				}
				int b1 = in->get(ctx) & 0xFF;
				int b2 = in->get(ctx) & 0xFF;
				if(endian == UNKNOWN)
				{
					endian = getDetectedEndian(b1, b2, ctx);
					if(endian == NOT_DETECTED)
					{
						endian = getDefaultEndian(ctx);
						if(endian == ANY)
						{
							endian = BIG;
						}
					}
										else 
					{
						if(getDefaultEndian(ctx) == ANY)
						{
							pos += 2;
							continue;
						}
					}
				}
				int jchar = (endian == BIG) ? (b1 << 8) | b2 : (b2 << 8) | b1;
				if(jchar >= 0xD800 && jchar <= 0xDFFF)
				{
					if(jchar >= 0xDC00)
					{
						in->position(pos, ctx);
						return CoderResult::malformedForLength(2, ctx);
					}
					if(outRemaining < 2)
					{
						in->position(pos, ctx);
						return CoderResult::OVERFLOW;
					}
					if(pos + 3 >= limit)
					{
						in->position(pos, ctx);
						return CoderResult::UNDERFLOW;
					}
					int b3 = in->get(ctx) & 0xFF;
					int b4 = in->get(ctx) & 0xFF;
					int jchar2 = (endian == BIG) ? (b3 << 8) | b4 : (b4 << 8) | b3;
					if(jchar2 < 0xDC00)
					{
						in->position(pos, ctx);
						return CoderResult::malformedForLength(4, ctx);
					}
					out->put(((wchar_t)jchar), ctx);
					out->put(((wchar_t)jchar2), ctx);
					outRemaining -= 2;
					pos += 4;
				}
								else 
				{
					out->put(((wchar_t)jchar), ctx);
					outRemaining -- ;
					pos += 2;
				}
			}
			in->position(pos, ctx);
			return CoderResult::UNDERFLOW;
		}
		catch(Throwable* e)
		{
			in->position(pos, ctx);
			throw e;
		}
	}
}
void UTF_16::Decoder::implReset(ThreadContext* ctx) throw() 
{
	endian = UNKNOWN;
}
int UTF_16::Decoder::getDefaultEndian(ThreadContext* ctx) throw() 
{
	return ANY;
}
int UTF_16::Decoder::getDetectedEndian(int b1, int b2, ThreadContext* ctx) throw() 
{
	if(b1 == 0xFF && b2 == 0xFE)
	{
		return LITTLE;
	}
	if(b1 == 0xFE && b2 == 0xFF)
	{
		return BIG;
	}
	return NOT_DETECTED;
}
void UTF_16::Decoder::__cleanUp(ThreadContext* ctx){
}
}}}

namespace org {namespace alinous {namespace charset {





constexpr const int UTF_16::Encoder::UNKNOWN;
constexpr const int UTF_16::Encoder::BIG;
constexpr const int UTF_16::Encoder::LITTLE;
constexpr const int UTF_16::Encoder::ANY;
constexpr const int UTF_16::Encoder::NOT_DETECTED;
bool UTF_16::Encoder::__init_done = __init_static_variables();
bool UTF_16::Encoder::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"UTF_16::Encoder", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 UTF_16::Encoder::Encoder(ThreadContext* ctx) throw()  : IObject(ctx), CharsetEncoder(ctx), endian(0)
{
	implReset(ctx);
}
void UTF_16::Encoder::__construct_impl(ThreadContext* ctx) throw() 
{
	implReset(ctx);
}
 UTF_16::Encoder::~Encoder() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void UTF_16::Encoder::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"Encoder", L"~Encoder");
	if(!prepare){
		return;
	}
}
CoderResult* UTF_16::Encoder::encodeLoop(CharBuffer* in, ByteBuffer* out, ThreadContext* ctx) throw() 
{
	int outRemaining = out->remaining(ctx);
	int pos = in->position(ctx);
	int limit = in->limit(ctx);
	{
		try
		{
			while(pos < limit)
			{
				if(endian == UNKNOWN)
				{
					endian = getDefaultEndian(ctx);
					if(endian == ANY)
					{
						if(outRemaining < 2)
						{
							endian = UNKNOWN;
							in->position(pos, ctx);
							return CoderResult::OVERFLOW;
						}
						endian = BIG;
						out->put(((char)0xFE), ctx);
						out->put(((char)0xFF), ctx);
						outRemaining -= 2;
					}
				}
				if(outRemaining == 0)
				{
					in->position(pos, ctx);
					return CoderResult::OVERFLOW;
				}
				int jchar = (in->get(ctx) & 0xFFFF);
				if(jchar >= 0xD800 && jchar <= 0xDFFF)
				{
					if(limit <= pos + 1)
					{
						in->position(pos, ctx);
						return CoderResult::UNDERFLOW;
					}
					if(outRemaining < 4)
					{
						in->position(pos, ctx);
						return CoderResult::OVERFLOW;
					}
					if(jchar >= 0xDC00)
					{
						in->position(pos, ctx);
						return CoderResult::malformedForLength(1, ctx);
					}
					int jchar2 = (in->get(ctx) & 0xFFFF);
					if(jchar2 < 0xDC00)
					{
						in->position(pos, ctx);
						return CoderResult::malformedForLength(1, ctx);
					}
					if(endian == BIG)
					{
						out->put(((char)((jchar >> 8) & 0xFF)), ctx);
						out->put(((char)(jchar & 0xFF)), ctx);
						out->put(((char)((jchar2 >> 8) & 0xFF)), ctx);
						out->put(((char)(jchar2 & 0xFF)), ctx);
					}
										else 
					{
						out->put(((char)(jchar & 0xFF)), ctx);
						out->put(((char)((jchar >> 8) & 0xFF)), ctx);
						out->put(((char)(jchar2 & 0xFF)), ctx);
						out->put(((char)((jchar2 >> 8) & 0xFF)), ctx);
					}
					outRemaining -= 4;
					pos ++ ;
				}
								else 
				{
					if(outRemaining < 2)
					{
						in->position(pos, ctx);
						return CoderResult::OVERFLOW;
					}
					if(endian == BIG)
					{
						out->put(((char)((jchar >> 8) & 0xFF)), ctx);
						out->put(((char)(jchar & 0xFF)), ctx);
					}
										else 
					{
						out->put(((char)(jchar & 0xFF)), ctx);
						out->put(((char)((jchar >> 8) & 0xFF)), ctx);
					}
					outRemaining -= 2;
				}
				pos ++ ;
			}
			in->position(pos, ctx);
			return CoderResult::UNDERFLOW;
		}
		catch(Throwable* e)
		{
			in->position(pos, ctx);
			throw e;
		}
	}
}
void UTF_16::Encoder::implReset(ThreadContext* ctx) throw() 
{
	endian = UNKNOWN;
}
int UTF_16::Encoder::getDefaultEndian(ThreadContext* ctx) throw() 
{
	return ANY;
}
void UTF_16::Encoder::__cleanUp(ThreadContext* ctx){
}
}}}

