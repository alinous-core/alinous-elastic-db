/*
 * Copyright (c) Tomohiro Iizuka. All rights reserved.
 * Licensed under the MIT license.
 */



#include "includes.h"

namespace java { namespace io {


StaticUnicodeString PrintStream::__DEFAULT_ENCODE{L"utf-8", 5};
UnicodeStringWrapper PrintStream::_DEFAULT_ENCODE{PrintStream::__DEFAULT_ENCODE};
constexpr UnicodeStringWrapper* PrintStream::DEFAULT_ENCODE;

StaticUnicodeString PrintStream::__NULL_TOKEN{L"null", 4};
UnicodeStringWrapper PrintStream::_NULL_TOKEN{PrintStream::__NULL_TOKEN};
constexpr UnicodeStringWrapper* PrintStream::NULL_TOKEN;

StaticUnicodeString PrintStream::__LINE_SEPARATOR{L"\n", 1};
UnicodeStringWrapper PrintStream::_LINE_SEPARATOR{PrintStream::__LINE_SEPARATOR};
constexpr UnicodeStringWrapper* PrintStream::LINE_SEPARATOR;


PrintStream::PrintStream(OutputStream* outSt, ThreadContext* ctx) : IObject(ctx), OutputStream(ctx) {
	this->outStream = outSt;
	__GC_INS(this, this->outStream, OutputStream);

	this->mutex = new SysMutex();
	this->encoding = nullptr;
}
PrintStream::PrintStream(OutputStream* outSt, bool autoflush, ThreadContext* ctx) : IObject(ctx), OutputStream(ctx) {
	this->outStream = outSt;
	__GC_INS(this, this->outStream, OutputStream);
	this->autoflush = autoflush;

	this->mutex = new SysMutex();
	this->encoding = nullptr;
}
PrintStream::PrintStream::PrintStream(OutputStream* outSt, bool autoflush, UnicodeString* enc, ThreadContext* ctx) : IObject(ctx), OutputStream(ctx) {
	this->outStream = outSt;
	__GC_INS(this, this->outStream, OutputStream);
	this->autoflush = autoflush;

	this->encoding = enc;
	__GC_INS(this, this->encoding, UnicodeString);

	this->mutex = new SysMutex();
}

PrintStream::~PrintStream(){
	ThreadContext *ctx = ThreadContext::getCurentContext();
	__releaseRegerences(false, ctx);
}

void PrintStream::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() {
	if(this->outStream != nullptr){
		close(ctx);
	}
}

void PrintStream::close(ThreadContext* ctx) {
	if(this->outStream == nullptr){
		return;
	}
	this->outStream->close(ctx);
	__GC_DEC(this, this->outStream, OutputStream);
	this->outStream = nullptr;

	__GC_DEC(this, this->encoding, UnicodeString);
	this->encoding = nullptr;

	delete this->mutex;
	this->mutex = nullptr;
}

void PrintStream::flush(ThreadContext* ctx) {
	this->outStream->flush(ctx);
}

void PrintStream::print(UnicodeString* str, ThreadContext* ctx){
	if(str == nullptr){
		print(NULL_TOKEN, ctx);
		return;
	}

	if (this->encoding == nullptr) {
		this->outStream->write(str->getBytes(DEFAULT_ENCODE, ctx), ctx);
	}else{
		this->outStream->write(str->getBytes(str, ctx), ctx);
	}
}

void PrintStream::print(IArrayObjectPrimitive<wchar_t>* charArray, ThreadContext* ctx){
	const int maxLoop = charArray->length;
	for(int i = 0; i != maxLoop; ++i){
		print(charArray->get(i), ctx);
	}
}

void PrintStream::print(wchar_t ch, ThreadContext* ctx){
	print(UnicodeString::valueOf(ch, ctx), ctx);
}
void PrintStream::print(double value, ThreadContext* ctx){
	print(UnicodeString::valueOf(value, ctx), ctx);
}
void PrintStream::print(float value, ThreadContext* ctx){
	print(UnicodeString::valueOf(value, ctx), ctx);
}
void PrintStream::print(int value, ThreadContext* ctx){
	print(UnicodeString::valueOf(value, ctx), ctx);
}
void PrintStream::print(long long value, ThreadContext* ctx){
	print(UnicodeString::valueOf(value, ctx), ctx);
}
void PrintStream::print(bool value, ThreadContext* ctx){
		print(UnicodeString::valueOf(value, ctx), ctx);
	}
void PrintStream::print(IObject* value, ThreadContext* ctx){
	print(UnicodeString::valueOf(value, ctx), ctx);
}

void PrintStream::newline(ThreadContext* ctx) {
	print(LINE_SEPARATOR, ctx);
}

void PrintStream::println(UnicodeString* str, ThreadContext* ctx){
	print(str, ctx);
	newline(ctx);
}

void PrintStream::println(IArrayObjectPrimitive<wchar_t>* charArray, ThreadContext* ctx){
	const int maxLoop = charArray->length;
	for(int i = 0; i != maxLoop; ++i){
		print(charArray->get(i), ctx);
	}
	newline(ctx);
}

void PrintStream::println(wchar_t ch, ThreadContext* ctx){
	println(UnicodeString::valueOf(ch, ctx), ctx);
}
void PrintStream::println(double value, ThreadContext* ctx){
	println(UnicodeString::valueOf(value, ctx), ctx);
}
void PrintStream::println(float value, ThreadContext* ctx){
	println(UnicodeString::valueOf(value, ctx), ctx);
}
void PrintStream::println(int value, ThreadContext* ctx){
	println(UnicodeString::valueOf(value, ctx), ctx);
}
void PrintStream::println(long long value, ThreadContext* ctx){
	println(UnicodeString::valueOf(value, ctx), ctx);
}
void PrintStream::println(bool value, ThreadContext* ctx){
		println(UnicodeString::valueOf(value, ctx), ctx);
}
void PrintStream::println(IObject* value, ThreadContext* ctx){
	println(UnicodeString::valueOf(value, ctx), ctx);
}

void PrintStream::write(IArrayObjectPrimitive<char>* buffer, int off, int len, ThreadContext* ctx){
	this->outStream->write(buffer, off, len, ctx);
}
void PrintStream::write(int b, ThreadContext* ctx){
	this->outStream->write(b, ctx);
}


}}

