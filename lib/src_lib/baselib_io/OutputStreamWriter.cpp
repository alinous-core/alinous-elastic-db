/*
 * Copyright (c) Tomohiro Iizuka. All rights reserved.
 * Licensed under the MIT license.
 */


#include "includes.h"

#ifndef BASELIB_IO_OUTPUTSTREAMWRITER_CPP_
#define BASELIB_IO_OUTPUTSTREAMWRITER_CPP_

namespace java { namespace io {
///////////////////////////////////////////////////////////////////////////////////
OutputStreamWriter::OutputStreamWriter(OutputStream* out, UnicodeString* charsetName, ThreadContext* ctx)
	: IObject(ctx), Writer(ctx)
{
	ctx->incGcDenial();
	this->out = __GC_INS(this, out, OutputStream);
	this->charsetName = __GC_INS(this, charsetName, UnicodeString);

	__init(ctx);
	ctx->decGcDenial();
}
OutputStreamWriter::OutputStreamWriter(OutputStream* out, ThreadContext* ctx)
	: IObject(ctx), Writer(ctx)
{
	ctx->incGcDenial();
	this->out = __GC_INS(this, out, OutputStream);
	this->charsetName = __GC_INS(this, new UnicodeString(L"ISO_8859_1", ctx), UnicodeString);

	__init(ctx);
	ctx->decGcDenial();
}


void OutputStreamWriter::__init(ThreadContext* ctx) {
	this->bytes = nullptr;
	this->chars = nullptr;
	this->outBuff = nullptr;

	CharsetManager* mgr = CharsetManager::getInstance(ctx);
	this->encoder = __GC_INS(this, mgr->getEncoder(this->charsetName, ctx), CharsetEncoder);
}

void OutputStreamWriter::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() {
	if(this->out != nullptr){
		close(ctx);
	}
	if(this->charsetName != nullptr){
		__GC_DEC(this, this->charsetName, UnicodeString);
		__GC_DEC(this, this->encoder, CharsetEncoder);
		__GC_DEC(this, this->outBuff, IArrayObjectPrimitive<char>);
		this->charsetName = nullptr;
		this->encoder = nullptr;
		this->outBuff = nullptr;
	}

	__ReleaseBuffer(ctx);
}

void OutputStreamWriter::__initBuffer(int bufferSize, ThreadContext* ctx) {
	this->bytes = __GC_INS(this, ByteBuffer::allocate(bufferSize * 4, ctx), ByteBuffer);
	this->chars = __GC_INS(this, CharBuffer::allocate(bufferSize, ctx), CharBuffer);
	this->outBuff = __GC_INS(this, new ArrayObjectPrimitive<char>(bufferSize * 4, ctx), IArrayObjectPrimitive<char>);
}
void OutputStreamWriter::__ReleaseBuffer(ThreadContext* ctx) {
	if(this->bytes != nullptr){
		__GC_DEC(this, this->bytes, ByteBuffer);
		__GC_DEC(this, this->chars, CharBuffer);

		this->bytes = nullptr;
		this->chars = nullptr;
	}
}

void OutputStreamWriter::close(ThreadContext* ctx){
	if(this->out != nullptr){
		out->close(ctx);
		__GC_DEC(this, this->out, OutputStream);
		this->out = nullptr;
	}
}

void OutputStreamWriter::flush(ThreadContext* ctx) {
	this->out->flush(ctx);
}

void OutputStreamWriter::write(IArrayObjectPrimitive<wchar_t>* cbuf, int off, int len, ThreadContext* ctx) {
	if(this->chars == nullptr){
		__initBuffer(len, ctx);
	}
	else if(this->chars->cap < len){
		__ReleaseBuffer(ctx);
		__initBuffer(len, ctx);
	}

	this->chars->clear(ctx);
	this->chars->put(cbuf, ctx);
	this->chars->limit(this->chars->position(ctx), ctx)->position(0, ctx);

	this->encoder->encodeLoop(this->chars, this->bytes, ctx);

	int length = this->bytes->position(ctx);
	this->bytes->position(0, ctx);
	//this->bytes->get(this->outBuff, 0, length, ctx);

	this->out->write(this->bytes->array(ctx), 0, length, ctx);

}
void OutputStreamWriter::write(int c, ThreadContext* ctx) {
	IArrayObjectPrimitive<wchar_t>* cbuf = new ArrayObjectPrimitive<wchar_t>(1);
	cbuf->set(c, 0, ctx);
	write(cbuf, 0, 1, ctx);
}
void OutputStreamWriter::write(UnicodeString* str, int off, int len, ThreadContext* ctx) {
	IArrayObjectPrimitive<char>* bytes = str->getBytes(this->charsetName, ctx);

	this->out->write(bytes, 0, bytes->length, ctx);

}
}}



#endif /* BASELIB_IO_OUTPUTSTREAMWRITER_CPP_ */
