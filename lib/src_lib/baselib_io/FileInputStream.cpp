/*
 * Copyright (c) Tomohiro Iizuka. All rights reserved.
 * Licensed under the MIT license.
 */


#include "include/global.h"

namespace java { namespace io {


FileInputStream::FileInputStream(File *file, ThreadContext* ctx) : IObject(ctx), InputStream(ctx) {
	ctx->incGcDenial();
	openFile(file, ctx);
	ctx->decGcDenial();
}

FileInputStream::FileInputStream(UnicodeString* fileName, ThreadContext* ctx) : IObject(ctx), InputStream(ctx) {
	ctx->incGcDenial();
	File* f = new File(fileName, ctx);
	openFile(f, ctx);
	ctx->decGcDenial();
}


void FileInputStream::openFile(File *file, ThreadContext* ctx){
	this->file = __GC_INS(this, file, File);

	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"FileInputStream", L"openFile");
	UnicodeString* path = __GC_INS(this, this->file->getAbsolutePath(ctx), UnicodeString);
	__e_obj1.add(path, this);

	char* cpath = path->toCString(ctx);

	this->desc = fopen(cpath, "rb");

	delete [] cpath;

	if(this->desc == 0x0){
		throw new FileNotFoundException(ctx);
	}
}

FileInputStream::~FileInputStream(){
	ThreadContext *ctx = ThreadContext::getCurentContext();
	ctx->incGcDenial();
	__releaseRegerences(false, ctx);
	ctx->decGcDenial();
}

void FileInputStream::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() {
	if(this->file != nullptr){
		__GC_DEC(this, this->file, File);
		this->file = nullptr;
	}
	if(this->desc != nullptr){
		close(ctx);
	}
}

int FileInputStream::available(ThreadContext* ctx) {
	return 0;
}

void FileInputStream::close(ThreadContext* ctx) {
	if(this->desc != nullptr){
		fclose(this->desc);
		this->desc = nullptr;
	}
}

int FileInputStream::read(ThreadContext* ctx) {
	char ch[1];

	int n = ::fread(ch, 1, 1, this->desc);

	if(n > 0){
		return (int)ch[0];
	}
	return -1;
}

int FileInputStream::read(IArrayObjectPrimitive<char>* buffer, int offset, int count, ThreadContext* ctx) {
	int _count = (buffer->length - offset) < count ? (buffer->length - offset) : count;
	char* ptr = buffer->rawPtr() + offset;

	int n = ::fread(ptr, 1, _count, this->desc);
	if(::ferror(this->desc) != 0){
		throw new IOException(ctx);
	}

	if(n > 0){
		return n;
	}

	return -1;
}
int FileInputStream::read(IArrayObjectPrimitive<char>* b, ThreadContext* ctx) {
	return read(b, 0, b->length, ctx);
}
long long FileInputStream::skip(long long count) {
	return 0;
}

}}


