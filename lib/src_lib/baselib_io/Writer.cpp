/*
 * Copyright (c) Tomohiro Iizuka. All rights reserved.
 * Licensed under the MIT license.
 */


#include "includes.h"

namespace java { namespace io {

StaticUnicodeString Writer::__TOKEN_NULL{L"null", 4};
UnicodeStringWrapper Writer::_TOKEN_NULL(Writer::__TOKEN_NULL);
constexpr UnicodeStringWrapper* const Writer::TOKEN_NULL;


Writer::Writer(ThreadContext* ctx) : IObject(ctx) {}
Writer::~Writer(){}
void Writer::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() {}

Writer* Writer::append(wchar_t c, ThreadContext* ctx) {
    write(c, ctx);
    return this;
}
Writer* Writer::append(CharSequence* csq, ThreadContext* ctx) {
    if (nullptr == csq) {
        write(TOKEN_NULL, ctx);
    } else {
        write(csq->toString(ctx), ctx);
    }
    return this;
}
Writer* Writer::append(CharSequence* csq, int start, int end, ThreadContext* ctx) {
    if (nullptr == csq) {
        write(TOKEN_NULL->substring(start, end, ctx), ctx);
    } else {
        write(csq->subSequence(start, end, ctx)->toString(ctx), ctx);
    }
    return this;
}

void Writer::write(IArrayObjectPrimitive<wchar_t>* cbuf, ThreadContext* ctx) {
	write(cbuf, 0, cbuf->length, ctx);
}

void Writer::write(UnicodeString* str, ThreadContext* ctx) {
	write(str, 0, str->length(ctx), ctx);
}

}}


