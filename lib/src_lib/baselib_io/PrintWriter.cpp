/*
 * Copyright (c) Tomohiro Iizuka. All rights reserved.
 * Licensed under the MIT license.
 */


#include "includes.h"

namespace java {
namespace io {

StaticUnicodeString PrintWriter::__lineSeparator{L"\n", 1};
UnicodeStringWrapper PrintWriter::_lineSeparator(PrintWriter::__lineSeparator);
constexpr UnicodeStringWrapper* const PrintWriter::lineSeparator;

PrintWriter::PrintWriter(OutputStream* out, ThreadContext* ctx) : IObject(ctx), Writer(ctx) {
	ctx->incGcDenial();
	this->out = __GC_INS(this, new OutputStreamWriter(out, ctx), OutputStreamWriter);
	this->autoflush = false;
	ctx->decGcDenial();
}
PrintWriter::PrintWriter(OutputStream* out, bool autoflush, ThreadContext* ctx) : IObject(ctx), Writer(ctx) {
	ctx->incGcDenial();
	this->out = __GC_INS(this, new OutputStreamWriter(out, ctx), OutputStreamWriter);
	this->autoflush = autoflush;
	ctx->decGcDenial();
}
PrintWriter::PrintWriter(Writer* out, ThreadContext* ctx) : IObject(ctx), Writer(ctx) {
	ctx->incGcDenial();
	this->out = __GC_INS(this, out, Writer);
	this->autoflush = false;
	ctx->decGcDenial();
}
PrintWriter::PrintWriter(Writer* out, bool autoflush, ThreadContext* ctx) : IObject(ctx), Writer(ctx) {
	ctx->incGcDenial();
	this->out = __GC_INS(this, out, Writer);
	this->autoflush = autoflush;
	ctx->decGcDenial();
}

PrintWriter::~PrintWriter(){
	ThreadContext *ctx = ThreadContext::getCurentContext();
	ctx->incGcDenial();
	__releaseRegerences(false, ctx);
	ctx->decGcDenial();
}

void PrintWriter::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() {
	if(this->out != nullptr){
		close(ctx);
	}
}

void PrintWriter::close(ThreadContext* ctx){
	if(this->out != nullptr){
		out->close(ctx);
		__GC_DEC(this, this->out, Writer);
		this->out = nullptr;
	}
}

void PrintWriter::flush(ThreadContext* ctx) {
	this->out->flush(ctx);
}

void PrintWriter::print(wchar_t ch, ThreadContext* ctx) {
	print(UnicodeString::valueOf(ch, ctx), ctx);
}

void PrintWriter::print(double dnum, ThreadContext* ctx) {
    print(UnicodeString::valueOf(dnum, ctx), ctx);
}

void PrintWriter::print(float fnum, ThreadContext* ctx) {
    print(UnicodeString::valueOf(fnum, ctx), ctx);
}

void PrintWriter::print(int inum, ThreadContext* ctx) {
    print(UnicodeString::valueOf(inum, ctx), ctx);
}

void PrintWriter::print(long long lnum, ThreadContext* ctx) {
    print(UnicodeString::valueOf(lnum, ctx), ctx);
}

void PrintWriter::print(IObject* obj, ThreadContext* ctx) {
    print(UnicodeString::valueOf(obj, ctx), ctx);
}

void PrintWriter::print(UnicodeString* str, ThreadContext* ctx) {
	UnicodeString* dest = str != nullptr ? str : new UnicodeString(L"null", ctx);
    write(dest, ctx);
}

void PrintWriter::println(wchar_t ch, ThreadContext* ctx) {
	println(UnicodeString::valueOf(ch, ctx), ctx);
}

void PrintWriter::println(double dnum, ThreadContext* ctx) {
	println(UnicodeString::valueOf(dnum, ctx), ctx);
}

void PrintWriter::println(float fnum, ThreadContext* ctx) {
	println(UnicodeString::valueOf(fnum, ctx), ctx);
}

void PrintWriter::println(int inum, ThreadContext* ctx) {
	println(UnicodeString::valueOf(inum, ctx), ctx);
}

void PrintWriter::println(long long lnum, ThreadContext* ctx) {
	println(UnicodeString::valueOf(lnum, ctx), ctx);
}

void PrintWriter::println(IObject* obj, ThreadContext* ctx) {
	println(UnicodeString::valueOf(obj, ctx), ctx);
}

void PrintWriter::println(UnicodeString* str, ThreadContext* ctx) {
	UnicodeString* dest = str != nullptr ? str : new UnicodeString(L"null", ctx);
    write(dest, ctx);
    newline(ctx);
}
 void PrintWriter::newline(ThreadContext* ctx) {
	print(lineSeparator, ctx);
}

void PrintWriter::write(IArrayObjectPrimitive<wchar_t>* cbuf, int off, int len, ThreadContext* ctx) {
	this->out->write(cbuf, off, len, ctx);
}
void PrintWriter::write(wchar_t c, ThreadContext* ctx) {
	this->out->write(c, ctx);
}
void PrintWriter::write(int c, ThreadContext* ctx) {
	this->out->write(c, ctx);
}
void PrintWriter::write(UnicodeString* str, int off, int len, ThreadContext* ctx) {
	this->out->write(str, off, len, ctx);
}
void PrintWriter::write(UnicodeString* str, ThreadContext* ctx){
	Writer::write(str, ctx);
}


}}


