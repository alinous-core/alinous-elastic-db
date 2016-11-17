/*
 * Copyright (c) Tomohiro Iizuka. All rights reserved.
 * Licensed under the MIT license.
 */

#include "includes.h"

namespace java { namespace io {
OutputStream::OutputStream(ThreadContext* ctx) : IObject(ctx) {
}
OutputStream::~OutputStream(){
}


void OutputStream::write(IArrayObjectPrimitive<char>* buffer, ThreadContext* ctx) {
    write(buffer, 0, buffer->length, ctx);
}

bool OutputStream::checkError(){return false;}

}}


