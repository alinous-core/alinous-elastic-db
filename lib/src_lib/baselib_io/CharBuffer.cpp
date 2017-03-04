/*
 * Copyright (c) Tomohiro Iizuka. All rights reserved.
 * Licensed under the MIT license.
 */


#include "include/global.h"

namespace java {
namespace nio {

CharBuffer::CharBuffer(const wchar_t* buffer, int length, ThreadContext* ctx) : IObject(ctx) {
	data = new RawArrayPrimitive<wchar_t>(length);
	wrapper = new ArrayObjectPrimitive<wchar_t>(data, nullptr);

	//__GC_INS(this, this->data, RawArrayPrimitive<wchar_t>);
	//__GC_INS(this, this->wrapper, ArrayObjectPrimitive<wchar_t>);

	this->lim = length;
	this->pos = 0;
	this->cap = length;

	const int maxLoop = length;
	for(int i = 0; i != maxLoop; ++i){
		data->addElement(buffer[i]);
	}
}

CharBuffer::CharBuffer(int size, ThreadContext* ctx) : IObject(ctx) {
	data = new(ctx) RawArrayPrimitive<wchar_t>(size);
	data->numArray = size;
	wrapper = new(ctx) ArrayObjectPrimitive<wchar_t>(data, nullptr);

	//__GC_INS(this, this->data, RawArrayPrimitive<wchar_t>);
	//__GC_INS(this, this->wrapper, ArrayObjectPrimitive<wchar_t>);

	this->lim = size;
	this->pos = 0;
	this->cap = size;
}
CharBuffer::~CharBuffer(){
	__releaseRegerences(false, 0);
}

void CharBuffer::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() {
	if(this->data != nullptr){
		delete this->data;
		this->data = nullptr;

		delete this->wrapper;
		this->wrapper = nullptr;
	}
}

CharBuffer* CharBuffer::allocate(int capacity, ThreadContext* ctx) {
	CharBuffer* buff = new CharBuffer(capacity, ctx);
	return buff;
}
CharBuffer* CharBuffer::clear(ThreadContext* ctx) {
	this->lim = this->cap;
	this->pos = 0;
	return this;
}
RawArrayPrimitive<wchar_t>* CharBuffer::move(ThreadContext* ctx){
	return this->data->move(ctx);
}

bool CharBuffer::hasArray(ThreadContext* ctx){
	return true;
}
int CharBuffer::arrayOffset(ThreadContext* ctx){
	return 0;
}
IArrayObjectPrimitive<wchar_t>* CharBuffer::array(ThreadContext* ctx) {
	return static_cast<IArrayObjectPrimitive<wchar_t>*>(wrapper);
}

bool CharBuffer::hasRemaining(ThreadContext* ctx) {
    return (pos < lim);
}

int CharBuffer::length(ThreadContext* ctx) {
	return remaining(ctx);
}
int CharBuffer::remaining(ThreadContext* ctx)
{
	 return this->lim - this->pos;
}
int CharBuffer::position(ThreadContext* ctx)
{
	return this->pos;
}
CharBuffer* CharBuffer::position(int newPosition, ThreadContext* ctx)
{
	this->pos = newPosition;
	return this;
}
int CharBuffer::limit(ThreadContext* ctx)
{
	return this->lim;
}
CharBuffer* CharBuffer::limit(int limit, ThreadContext* ctx)
{
	this->lim = limit;
	return this;
}

wchar_t CharBuffer::get(ThreadContext* ctx)
{
	return data->get(this->pos++);
}
wchar_t CharBuffer::get(int index, ThreadContext* ctx)
{
	return data->get(index);
}

CharBuffer* CharBuffer::get(IArrayObjectPrimitive<wchar_t>* dest, ThreadContext* ctx) {
	return get(dest, 0, dest->length, ctx);
}

CharBuffer* CharBuffer::get(IArrayObjectPrimitive<wchar_t>* dest, int off, int len, ThreadContext* ctx) {
    int length = dest->length;
    if ((off < 0) || (len < 0) || (long) off + (long) len > length) {
        throw new IndexOutOfBoundsException(ctx);
    }

    if (len > remaining(ctx)) {
        throw new BufferUnderflowException(ctx);
    }
    for (int i = off; i < off + len; i++) {
    	dest->set(get(ctx), i, ctx);
    }
    return this;
}

CharBuffer* CharBuffer::put(wchar_t ch, ThreadContext* ctx)
{
	data->set(this->pos++, ch);
	return this;
}
CharBuffer* CharBuffer::put(int index, wchar_t ch, ThreadContext* ctx)
{
	data->set(index, ch);
	return this;
}

CharBuffer* CharBuffer::put(UnicodeString* str, ThreadContext* ctx) {
	int maxLoop = str->length(ctx);
	for(int i = 0; i != maxLoop; ++i){
		data->set(this->pos++, str->charAt(i, ctx));
	}
	return this;
}

CharBuffer* CharBuffer::put(IArrayObjectPrimitive<wchar_t>* src, ThreadContext* ctx) {
    return put(src, 0, src->length, ctx);
}

CharBuffer* CharBuffer::put(IArrayObjectPrimitive<wchar_t>* src, int off, int len, ThreadContext* ctx) {
    int length = src->length;
    if ((off < 0) || (len < 0) || (long) off + (long) len > length) {
        throw new IndexOutOfBoundsException(ctx);
    }

    if (len > remaining(ctx)) {
        throw new BufferOverflowException(ctx);
    }
    for (int i = off; i < off + len; i++) {
        put(src->get(i), ctx);
    }
    return this;
}
wchar_t* CharBuffer::rawArray() {
	return this->data->root;
}

CharBuffer* CharBuffer::wrap(IArrayObjectPrimitive<wchar_t>* buffer, int begin, int count, ThreadContext* ctx) {
	CharBuffer* newBuffer = new CharBuffer(count, ctx);

	for (int i = 0; i < count; i++) {
		newBuffer->put(buffer->get(begin + i), ctx);
	}
	newBuffer->position(0, ctx);
	return newBuffer;
}

CharBuffer* CharBuffer::wrap(UnicodeString* str, ThreadContext* ctx) {
	return wrap(str, 0, str->length(ctx), ctx);
}


CharBuffer* CharBuffer::wrap(UnicodeString* str, int begin, int count, ThreadContext* ctx) {
	CharBuffer* newBuffer = new CharBuffer(count, ctx);

	for (int i = 0; i < count; i++) {
		newBuffer->put(str->charAt(begin + i, ctx), ctx);
	}

	newBuffer->position(0, ctx);
	return newBuffer;
}

}}



