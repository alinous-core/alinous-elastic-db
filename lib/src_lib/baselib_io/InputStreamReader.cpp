/*
 * Copyright (c) Tomohiro Iizuka. All rights reserved.
 * Licensed under the MIT license.
 */


#include "includes.h"

namespace java { namespace io {

using namespace org::alinous::charset;

InputStreamReader::InputStreamReader(InputStream* in, ThreadContext* ctx) : IObject(ctx), Reader(ctx) {
	this->stream = __GC_INS(this, in, InputStream);
	this->charsetName = __GC_INS(this, new UnicodeString(L"ISO_8859_1", ctx), UnicodeString);


	__init(ctx);
}

InputStreamReader::InputStreamReader(InputStream* in, UnicodeString* charsetName, ThreadContext* ctx) : IObject(ctx), Reader(ctx) {
	this->stream = __GC_INS(this, in, InputStream);
	this->charsetName = __GC_INS(this, charsetName, UnicodeString);

	__init(ctx);
}

void InputStreamReader::__init(ThreadContext* ctx) {
	this->byteBufferArray = nullptr;
	this->bytes = nullptr;
	this->chars = nullptr;
	this->remainBytes = __GC_INS(this, ByteBuffer::allocate(4, ctx), ByteBuffer);

	this->remainBytes->limit(0, ctx);

	CharsetManager* mgr = CharsetManager::getInstance(ctx);
	this->decoder = __GC_INS(this, mgr->getDecoder(this->charsetName, ctx), CharsetDecoder);
}

InputStreamReader::~InputStreamReader(){
	ThreadContext *ctx = ThreadContext::getCurentContext();
	__releaseRegerences(false, ctx);
}

void InputStreamReader::__initBuffer(int bufferSize, ThreadContext* ctx) {
	this->byteBufferArray = __GC_INS(this, new ArrayObjectPrimitive<char>(bufferSize, ctx), ArrayObjectPrimitive<char>);
	this->bytes = __GC_INS(this, ByteBuffer::allocate(bufferSize + 4, ctx), ByteBuffer);
	this->chars = __GC_INS(this, CharBuffer::allocate(bufferSize, ctx), CharBuffer);
}

void InputStreamReader::__ReleaseBuffer(ThreadContext* ctx) {
	if(this->byteBufferArray != nullptr){
		__GC_DEC(this, this->byteBufferArray, IArrayObjectPrimitive<char>);
		__GC_DEC(this, this->bytes, ByteBuffer);
		__GC_DEC(this, this->chars, CharBuffer);

		this->byteBufferArray = nullptr;
		this->bytes = nullptr;
		this->chars = nullptr;
	}
}

void InputStreamReader::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() {
	if(this->stream != nullptr){
		close(ctx);
	}
	if(this->charsetName != nullptr){
		__GC_DEC(this, this->charsetName, UnicodeString);
		this->charsetName = nullptr;
	}

	__ReleaseBuffer(ctx);

	if(this->remainBytes != nullptr){
		__GC_DEC(this, this->remainBytes, ByteBuffer);
		__GC_DEC(this, this->decoder, CharsetDecoder);
		this->remainBytes = nullptr;
		this->decoder = nullptr;
	}
}

void InputStreamReader::close(ThreadContext* ctx){
	if(this->stream != nullptr){
		stream->close(ctx);
		__GC_DEC(this, this->stream, InputStream);
		this->stream = nullptr;
	}
}

int InputStreamReader::read(IArrayObjectPrimitive<wchar_t>* b, int off, int len, ThreadContext* ctx) {
	if(this->byteBufferArray == nullptr){
		__initBuffer(b->length, ctx);
	}
	else if(this->byteBufferArray->length != b->length){
		__ReleaseBuffer(ctx);
		__initBuffer(b->length, ctx);
	}


	int readCount = stream->read(byteBufferArray, ctx);
	if(readCount < 0){
		return readCount;
	}

	this->bytes->clear(ctx);
	this->chars->clear(ctx);

	this->remainBytes->position(0, ctx);
	while(this->remainBytes->hasRemaining(ctx))
	{
		char rb = this->remainBytes->get(ctx);
		this->bytes->put(rb, ctx);
	}
	this->bytes->put(byteBufferArray, 0, readCount, ctx);

	int newLimit = this->bytes->position(ctx);
	this->bytes->limit(newLimit, ctx);
	this->bytes->position(0, ctx);


	this->decoder->decodeLoop(this->bytes, this->chars, ctx);

	this->remainBytes->clear(ctx);
	while(this->bytes->hasRemaining(ctx))
	{
		char rb = this->bytes->get(ctx);
		this->remainBytes->put(rb, ctx);
	}
	int remainPos = this->remainBytes->position(ctx);
	this->remainBytes->limit(remainPos, ctx);


	int decodedPos = this->chars->position(ctx);
	this->chars->position(0, ctx);
	this->chars->limit(decodedPos, ctx);

	int decodecLength = this->chars->length(ctx);
	this->chars->get(b, off, decodecLength, ctx);

	return decodecLength;
}




}}


