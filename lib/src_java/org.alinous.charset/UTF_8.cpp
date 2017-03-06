#include "include/global.h"


#include "org.alinous.charset/CharsetDecoder.h"
#include "org.alinous.charset/CharsetEncoder.h"
#include "org.alinous.charset/CharsetConverter.h"
#include "org.alinous.charset/UTF_16.h"
#include "org.alinous.charset/UTF_16BE.h"
#include "org.alinous.charset/CP_1254.h"
#include "org.alinous.charset/ISO_8859_7.h"
#include "org.alinous.charset/ISO_8859_5.h"
#include "org.alinous.charset/US_ASCII.h"
#include "org.alinous.charset/CP_1250.h"
#include "org.alinous.charset/CP_1251.h"
#include "org.alinous.charset/CP_1252.h"
#include "org.alinous.charset/CP_1253.h"
#include "org.alinous.charset/CP_1257.h"
#include "org.alinous.charset/IBM866.h"
#include "org.alinous.charset/ISO_8859_1.h"
#include "org.alinous.charset/ISO_8859_2.h"
#include "org.alinous.charset/ISO_8859_4.h"
#include "org.alinous.charset/ISO_8859_9.h"
#include "org.alinous.charset/ISO_8859_13.h"
#include "org.alinous.charset/ISO_8859_15.h"
#include "org.alinous.charset/KOI8_R.h"
#include "org.alinous.charset/UTF_16LE.h"
#include "org.alinous.charset/UTF_8.h"
#include "org.alinous.charset/CharsetManager.h"

namespace org {namespace alinous {namespace charset {





bool UTF_8::__init_done = __init_static_variables();
bool UTF_8::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"UTF_8", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 UTF_8::UTF_8(ThreadContext* ctx) throw()  : IObject(ctx), CharsetConverter(ctx), decoder(nullptr), encoder(nullptr)
{
	__GC_MV(this, &(decoder), (new(ctx) UTF_8::Decoder(ctx)), CharsetDecoder);
	__GC_MV(this, &(encoder), (new(ctx) UTF_8::Encoder(ctx)), CharsetEncoder);
}
void UTF_8::__construct_impl(ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(decoder), (new(ctx) UTF_8::Decoder(ctx)), CharsetDecoder);
	__GC_MV(this, &(encoder), (new(ctx) UTF_8::Encoder(ctx)), CharsetEncoder);
}
 UTF_8::~UTF_8() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void UTF_8::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"UTF_8", L"~UTF_8");
	__e_obj1.add(this->decoder, this);
	decoder = nullptr;
	__e_obj1.add(this->encoder, this);
	encoder = nullptr;
	if(!prepare){
		return;
	}
}
CharsetDecoder* UTF_8::newDecoder(ThreadContext* ctx) throw() 
{
	return decoder;
}
CharsetEncoder* UTF_8::newEncoder(ThreadContext* ctx) throw() 
{
	return encoder;
}
bool UTF_8::contains(String* cs, ThreadContext* ctx) throw() 
{
	return cs->equalsIgnoreCase(ConstStr::getCNST_STR_120(), ctx) || cs->equalsIgnoreCase(ConstStr::getCNST_STR_892(), ctx) || cs->equalsIgnoreCase(ConstStr::getCNST_STR_893(), ctx) || cs->equalsIgnoreCase(ConstStr::getCNST_STR_894(), ctx) || cs->equalsIgnoreCase(ConstStr::getCNST_STR_895(), ctx) || cs->equalsIgnoreCase(ConstStr::getCNST_STR_896(), ctx) || cs->equalsIgnoreCase(ConstStr::getCNST_STR_897(), ctx) || cs->equalsIgnoreCase(ConstStr::getCNST_STR_898(), ctx) || cs->equalsIgnoreCase(ConstStr::getCNST_STR_899(), ctx) || cs->equalsIgnoreCase(ConstStr::getCNST_STR_900(), ctx) || cs->equalsIgnoreCase(ConstStr::getCNST_STR_901(), ctx) || cs->equalsIgnoreCase(ConstStr::getCNST_STR_902(), ctx) || cs->equalsIgnoreCase(ConstStr::getCNST_STR_903(), ctx) || cs->equalsIgnoreCase(ConstStr::getCNST_STR_904(), ctx) || cs->equalsIgnoreCase(ConstStr::getCNST_STR_905(), ctx) || cs->equalsIgnoreCase(ConstStr::getCNST_STR_906(), ctx) || cs->equalsIgnoreCase(ConstStr::getCNST_STR_907(), ctx) || cs->equalsIgnoreCase(ConstStr::getCNST_STR_908(), ctx) || cs->equalsIgnoreCase(ConstStr::getCNST_STR_909(), ctx) || cs->equalsIgnoreCase(ConstStr::getCNST_STR_910(), ctx) || cs->equalsIgnoreCase(ConstStr::getCNST_STR_891(), ctx) || cs->equalsIgnoreCase(ConstStr::getCNST_STR_911(), ctx) || cs->equalsIgnoreCase(ConstStr::getCNST_STR_912(), ctx);
}
void UTF_8::__cleanUp(ThreadContext* ctx){
}
}}}

namespace org {namespace alinous {namespace charset {





const StaticArrayObjectPrimitive<int> UTF_8::Decoder::__remainingBytes = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 3, 3, 3, 3, 3, 3, 3, 3, -1, -1, -1, -1, -1, -1, -1, -1};
IArrayObjectPrimitive<int>* UTF_8::Decoder::remainingBytes = (IArrayObjectPrimitive<int>*)const_cast<StaticArrayObjectPrimitive<int>*>(&__remainingBytes);
const StaticArrayObjectPrimitive<int> UTF_8::Decoder::__remainingNumbers = {0, 4224, 401536, 29892736};
IArrayObjectPrimitive<int>* UTF_8::Decoder::remainingNumbers = (IArrayObjectPrimitive<int>*)const_cast<StaticArrayObjectPrimitive<int>*>(&__remainingNumbers);
const StaticArrayObjectPrimitive<int> UTF_8::Decoder::__lowerEncodingLimit = {-1, 0x80, 0x800, 0x10000};
IArrayObjectPrimitive<int>* UTF_8::Decoder::lowerEncodingLimit = (IArrayObjectPrimitive<int>*)const_cast<StaticArrayObjectPrimitive<int>*>(&__lowerEncodingLimit);
bool UTF_8::Decoder::__init_done = __init_static_variables();
bool UTF_8::Decoder::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"UTF_8::Decoder", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 UTF_8::Decoder::Decoder(ThreadContext* ctx) throw()  : IObject(ctx), CharsetDecoder(ctx)
{
}
void UTF_8::Decoder::__construct_impl(ThreadContext* ctx) throw() 
{
}
 UTF_8::Decoder::~Decoder() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void UTF_8::Decoder::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
}
CoderResult* UTF_8::Decoder::decodeLoop(ByteBuffer* in, CharBuffer* out, ThreadContext* ctx) throw() 
{
	if(in->hasArray(ctx) && out->hasArray(ctx))
	{
		return decodeHasArray(in, out, ctx);
	}
	return decodeNotHasArray(in, out, ctx);
}
CoderResult* UTF_8::Decoder::decodeNotHasArray(ByteBuffer* in, CharBuffer* out, ThreadContext* ctx) throw() 
{
	int outRemaining = out->remaining(ctx);
	int pos = in->position(ctx);
	int limit = in->limit(ctx);
	{
		try
		{
			while(pos < limit)
			{
				if(outRemaining == 0)
				{
					in->position(pos, ctx);
					return CoderResult::OVERFLOW;
				}
				int jchar = in->get(ctx);
				if(jchar < 0)
				{
					jchar = jchar & 0x7F;
					int tail = remainingBytes->get(jchar);
					if(tail == -1)
					{
						in->position(pos, ctx);
						return CoderResult::malformedForLength(1, ctx);
					}
					if(limit - pos < 1 + tail)
					{
						in->position(pos, ctx);
						return CoderResult::UNDERFLOW;
					}
					int nextByte = 0;
					for(int i = 0; i < tail; i ++ )
					{
						nextByte = in->get(ctx) & 0xFF;
						if((nextByte & 0xC0) != 0x80)
						{
							in->position(pos, ctx);
							return CoderResult::malformedForLength(1 + i, ctx);
						}
						jchar = (jchar << 6) + nextByte;
					}
					jchar -= remainingNumbers->get(tail);
					if(jchar < lowerEncodingLimit->get(tail))
					{
						in->position(pos, ctx);
						return CoderResult::malformedForLength(1, ctx);
					}
					pos += tail;
				}
				if(jchar <= 0xffff)
				{
					out->put(((wchar_t)jchar), ctx);
					outRemaining -- ;
				}
								else 
				{
					if(outRemaining < 2)
					{
						in->position(pos, ctx);
						return CoderResult::OVERFLOW;
					}
					out->put(((wchar_t)((jchar >> 0xA) + 0xD7C0)), ctx);
					out->put(((wchar_t)((jchar & 0x3FF) + 0xDC00)), ctx);
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
CoderResult* UTF_8::Decoder::decodeHasArray(ByteBuffer* in, CharBuffer* out, ThreadContext* ctx) throw() 
{
	int outRemaining = out->remaining(ctx);
	int pos = in->position(ctx);
	int limit = in->limit(ctx);
	IArrayObjectPrimitive<char>* bArr = in->array(ctx);
	IArrayObjectPrimitive<wchar_t>* cArr = out->array(ctx);
	int inIndexLimit = limit + in->arrayOffset(ctx);
	int inIndex = pos + in->arrayOffset(ctx);
	int outIndex = out->position(ctx) + out->arrayOffset(ctx);
	for(; inIndex < inIndexLimit && outRemaining > 0; inIndex ++ )
	{
		int jchar = bArr->get(inIndex);
		if(jchar < 0)
		{
			jchar = jchar & 0x7F;
			int tail = remainingBytes->get(jchar);
			if(tail == -1)
			{
				in->position(inIndex - in->arrayOffset(ctx), ctx);
				out->position(outIndex - out->arrayOffset(ctx), ctx);
				return CoderResult::malformedForLength(1, ctx);
			}
			if(inIndexLimit - inIndex < 1 + tail)
			{
				break ;
			}
			for(int i = 0; i < tail; i ++ )
			{
				int nextByte = bArr->get(inIndex + i + 1) & 0xFF;
				if((nextByte & 0xC0) != 0x80)
				{
					in->position(inIndex - in->arrayOffset(ctx), ctx);
					out->position(outIndex - out->arrayOffset(ctx), ctx);
					return CoderResult::malformedForLength(1 + i, ctx);
				}
				jchar = (jchar << 6) + nextByte;
			}
			jchar -= remainingNumbers->get(tail);
			if(jchar < lowerEncodingLimit->get(tail))
			{
				in->position(inIndex - in->arrayOffset(ctx), ctx);
				out->position(outIndex - out->arrayOffset(ctx), ctx);
				return CoderResult::malformedForLength(1, ctx);
			}
			inIndex += tail;
		}
		if(jchar <= 0xffff)
		{
			cArr->set(((wchar_t)jchar),outIndex++, ctx);
			outRemaining -- ;
		}
				else 
		{
			if(outRemaining < 2)
			{
				return CoderResult::OVERFLOW;
			}
			cArr->set(((wchar_t)((jchar >> 0xA) + 0xD7C0)),outIndex++, ctx);
			cArr->set(((wchar_t)((jchar & 0x3FF) + 0xDC00)),outIndex++, ctx);
			outRemaining -= 2;
		}
	}
	in->position(inIndex - in->arrayOffset(ctx), ctx);
	out->position(outIndex - out->arrayOffset(ctx), ctx);
	return (outRemaining == 0 && inIndex < inIndexLimit) ? CoderResult::OVERFLOW : CoderResult::UNDERFLOW;
}
void UTF_8::Decoder::__cleanUp(ThreadContext* ctx){
}
}}}

namespace org {namespace alinous {namespace charset {





bool UTF_8::Encoder::__init_done = __init_static_variables();
bool UTF_8::Encoder::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"UTF_8::Encoder", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 UTF_8::Encoder::Encoder(ThreadContext* ctx) throw()  : IObject(ctx), CharsetEncoder(ctx)
{
}
void UTF_8::Encoder::__construct_impl(ThreadContext* ctx) throw() 
{
}
 UTF_8::Encoder::~Encoder() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void UTF_8::Encoder::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
}
CoderResult* UTF_8::Encoder::encodeLoop(CharBuffer* in, ByteBuffer* out, ThreadContext* ctx) throw() 
{
	if(in->hasArray(ctx) && out->hasArray(ctx))
	{
		return encodeHasArray(in, out, ctx);
	}
	return encodeNotHasArray(in, out, ctx);
}
CoderResult* UTF_8::Encoder::encodeHasArray(CharBuffer* in, ByteBuffer* out, ThreadContext* ctx) throw() 
{
	int outRemaining = out->remaining(ctx);
	int pos = in->position(ctx);
	int limit = in->limit(ctx);
	IArrayObjectPrimitive<char>* bArr = 0;
	IArrayObjectPrimitive<wchar_t>* cArr = 0;
	int x = pos;
	bArr = out->array(ctx);
	cArr = in->array(ctx);
	int outPos = out->position(ctx);
	int rem = in->remaining(ctx);
	for(x = pos; x < pos + rem; x ++ )
	{
		int jchar = (cArr->get(x) & 0xFFFF);
		if(jchar <= 0x7F)
		{
			if(outRemaining < 1)
			{
				in->position(x, ctx);
				out->position(outPos, ctx);
				return CoderResult::OVERFLOW;
			}
			bArr->set(((char)(jchar & 0xFF)),outPos++, ctx);
			outRemaining -- ;
		}
				else 
		{
			if(jchar <= 0x7FF)
			{
				if(outRemaining < 2)
				{
					in->position(x, ctx);
					out->position(outPos, ctx);
					return CoderResult::OVERFLOW;
				}
				bArr->set(((char)(0xC0 + ((jchar >> 6) & 0x1F))),outPos++, ctx);
				bArr->set(((char)(0x80 + (jchar & 0x3F))),outPos++, ctx);
				outRemaining -= 2;
			}
						else 
			{
				if(jchar >= 0xD800 && jchar <= 0xDFFF)
				{
					if(limit <= x + 1)
					{
						in->position(x, ctx);
						out->position(outPos, ctx);
						return CoderResult::UNDERFLOW;
					}
					if(outRemaining < 4)
					{
						in->position(x, ctx);
						out->position(outPos, ctx);
						return CoderResult::OVERFLOW;
					}
					if(jchar >= 0xDC00)
					{
						in->position(x, ctx);
						out->position(outPos, ctx);
						return CoderResult::malformedForLength(1, ctx);
					}
					int jchar2 = cArr->get(x + 1) & 0xFFFF;
					if(jchar2 < 0xDC00)
					{
						in->position(x, ctx);
						out->position(outPos, ctx);
						return CoderResult::malformedForLength(1, ctx);
					}
					int n = (jchar << 10) + jchar2 + 0xFCA02400;
					bArr->set(((char)(0xF0 + ((n >> 18) & 0x07))),outPos++, ctx);
					bArr->set(((char)(0x80 + ((n >> 12) & 0x3F))),outPos++, ctx);
					bArr->set(((char)(0x80 + ((n >> 6) & 0x3F))),outPos++, ctx);
					bArr->set(((char)(0x80 + (n & 0x3F))),outPos++, ctx);
					outRemaining -= 4;
					x ++ ;
				}
								else 
				{
					if(outRemaining < 3)
					{
						in->position(x, ctx);
						out->position(outPos, ctx);
						return CoderResult::OVERFLOW;
					}
					bArr->set(((char)(0xE0 + ((jchar >> 12) & 0x0F))),outPos++, ctx);
					bArr->set(((char)(0x80 + ((jchar >> 6) & 0x3F))),outPos++, ctx);
					bArr->set(((char)(0x80 + (jchar & 0x3F))),outPos++, ctx);
					outRemaining -= 3;
				}
			}
		}
		if(outRemaining == 0)
		{
			in->position(x + 1, ctx);
			out->position(outPos, ctx);
			return CoderResult::OVERFLOW;
		}
	}
	if(rem != 0)
	{
		in->position(x, ctx);
		out->position(outPos, ctx);
	}
	return CoderResult::UNDERFLOW;
}
CoderResult* UTF_8::Encoder::encodeNotHasArray(CharBuffer* in, ByteBuffer* out, ThreadContext* ctx) throw() 
{
	int outRemaining = out->remaining(ctx);
	int pos = in->position(ctx);
	int limit = in->limit(ctx);
	{
		try
		{
			while(pos < limit)
			{
				if(outRemaining == 0)
				{
					in->position(pos, ctx);
					return CoderResult::OVERFLOW;
				}
				int jchar = (in->get(ctx) & 0xFFFF);
				if(jchar <= 0x7F)
				{
					if(outRemaining < 1)
					{
						in->position(pos, ctx);
						return CoderResult::OVERFLOW;
					}
					out->put(((char)(jchar & 0xFF)), ctx);
					outRemaining -- ;
				}
								else 
				{
					if(jchar <= 0x7FF)
					{
						if(outRemaining < 2)
						{
							in->position(pos, ctx);
							return CoderResult::OVERFLOW;
						}
						out->put(((char)(0xC0 + ((jchar >> 6) & 0x1F))), ctx);
						out->put(((char)(0x80 + (jchar & 0x3F))), ctx);
						outRemaining -= 2;
					}
										else 
					{
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
							int n = (jchar << 10) + jchar2 + 0xFCA02400;
							out->put(((char)(0xF0 + ((n >> 18) & 0x07))), ctx);
							out->put(((char)(0x80 + ((n >> 12) & 0x3F))), ctx);
							out->put(((char)(0x80 + ((n >> 6) & 0x3F))), ctx);
							out->put(((char)(0x80 + (n & 0x3F))), ctx);
							outRemaining -= 4;
							pos ++ ;
						}
												else 
						{
							if(outRemaining < 3)
							{
								in->position(pos, ctx);
								return CoderResult::OVERFLOW;
							}
							out->put(((char)(0xE0 + ((jchar >> 12) & 0x0F))), ctx);
							out->put(((char)(0x80 + ((jchar >> 6) & 0x3F))), ctx);
							out->put(((char)(0x80 + (jchar & 0x3F))), ctx);
							outRemaining -= 3;
						}
					}
				}
				pos ++ ;
			}
		}
		catch(Throwable* e)
		{
			in->position(pos, ctx);
		}
	}
	in->position(pos, ctx);
	return CoderResult::UNDERFLOW;
}
void UTF_8::Encoder::__cleanUp(ThreadContext* ctx){
}
}}}

