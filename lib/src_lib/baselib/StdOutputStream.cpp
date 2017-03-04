/*
 * Copyright (c) Tomohiro Iizuka. All rights reserved.
 * Licensed under the MIT license.
 */

#include "include/global.h"

namespace java{ namespace lang {

StdOutputStream::StdOutputStream(const int fd) : IObject(nullptr), OutputStream(nullptr), outFd(fd) {
}

StdOutputStream::~StdOutputStream(){
}
void StdOutputStream::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() {

}

void StdOutputStream::close(ThreadContext* ctx){

}
void StdOutputStream::flush(ThreadContext* ctx){

}
void StdOutputStream::write(IArrayObjectPrimitive<char>* buffer, ThreadContext* ctx) {
    write(buffer, 0, buffer->length, ctx);
}
void StdOutputStream::write(IArrayObjectPrimitive<char>* buffer, int off, int len, ThreadContext* ctx){
	char* ptr = buffer->rawPtr();
	ptr = ptr + off;

	int ret = ::write(this->outFd, ptr, len);
	if(ret < 0){
		throw new(ctx) IOException(ctx);
	}
}
void StdOutputStream::write(int b, ThreadContext* ctx){
	int ret = ::write(this->outFd, &b, 1);
	if(ret < 0){
		throw new(ctx) IOException(ctx);
	}
}

}}
