/*
 * Copyright (c) Tomohiro Iizuka. All rights reserved.
 * Licensed under the MIT license.
 */


#include "includes.h"

namespace java { namespace io {

Reader::Reader(ThreadContext* ctx) : IObject(ctx) {}
Reader::~Reader(){}
void Reader::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() {}

int Reader::read(CharBuffer* target, ThreadContext* ctx) {
    if (nullptr == target) {
        throw new NullPointerException(ctx);
    }
    int length = target->length(ctx);
    IArrayObjectPrimitive<wchar_t>* buf = ArrayAllocatorPrimitive<wchar_t>::allocatep(ctx, length);
    length = Math::min(length, read(buf, ctx), ctx);
    if (length > 0) {
        target->put(buf, 0, length, ctx);
    }
    return length;
}

int Reader::read(IArrayObjectPrimitive<wchar_t>* b, ThreadContext* ctx) {
	return read(b, 0, b->length, ctx);
}

bool Reader::ready(ThreadContext* ctx){return true;}

void Reader::mark(int readlimit, ThreadContext* ctx) {}

bool Reader::markSupported(ThreadContext* ctx) {
	return false;
}

void Reader::reset(ThreadContext* ctx){};

long long Reader::skip(long long ns, ThreadContext* ctx){
	return -1;
}


}}

