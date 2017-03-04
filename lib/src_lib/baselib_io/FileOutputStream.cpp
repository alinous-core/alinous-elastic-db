/*
 * Copyright (c) Tomohiro Iizuka. All rights reserved.
 * Licensed under the MIT license.
 */


#include "include/global.h"

namespace java { namespace io {

FileOutputStream::FileOutputStream(File *file, ThreadContext* ctx) : IObject(ctx), OutputStream(ctx) {
	ctx->incGcDenial();
	int mode = O_CREAT | O_TRUNC;
	openFile(file, mode, ctx);
	ctx->decGcDenial();
}
FileOutputStream::FileOutputStream(File* file, bool append, ThreadContext* ctx) : IObject(ctx), OutputStream(ctx) {
	ctx->incGcDenial();
	int mode = O_CREAT | O_TRUNC;
	if(append){
		mode = O_CREAT | O_APPEND;
	}
	openFile(file, mode, ctx);
	ctx->decGcDenial();
}
FileOutputStream::FileOutputStream(UnicodeString* fileName, ThreadContext* ctx) : IObject(ctx), OutputStream(ctx) {
	ctx->incGcDenial();
	File* f = new File(fileName, ctx);

	int mode = O_CREAT | O_TRUNC;
	openFile(f, mode, ctx);
	ctx->decGcDenial();
}
FileOutputStream::FileOutputStream(UnicodeString* fileName, bool append, ThreadContext* ctx) : IObject(ctx), OutputStream(ctx) {
	ctx->incGcDenial();
	File* f = new File(fileName, ctx);
	int mode = O_CREAT | O_TRUNC;
	if(append){
		mode = O_CREAT | O_APPEND;
	}
	openFile(f, mode, ctx);
	ctx->decGcDenial();
}


void FileOutputStream::openFile(File *file, int mode, ThreadContext* ctx){
	this->file = __GC_INS(this, file, File);

	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"FileOutputStream", L"openFile");
	UnicodeString* path = __GC_INS(this, this->file->getAbsolutePath(ctx), UnicodeString);
	__e_obj1.add(path, this);

	char* cpath = path->toCString(ctx);

	int amode = O_RDWR | mode;
	this->fd = ::open(cpath, amode, 0644);


	this->_fb = new FileBuffer(this->fd);

	delete [] cpath;
}

FileOutputStream::~FileOutputStream(){
	ThreadContext *ctx = ThreadContext::getCurentContext();
	__releaseRegerences(false, ctx);
}

void FileOutputStream::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() {
	if(this->file != nullptr){
		__GC_DEC(this, this->file, File);
		this->file = nullptr;
	}
	if(this->fd != 0){
		close(ctx);
	}
}

int FileOutputStream::available(ThreadContext* ctx) {
	return 0;
}
void FileOutputStream::flush(ThreadContext* ctx){
	this->_fb->flush();
	this->_fb->join();

}

void FileOutputStream::close(ThreadContext* ctx) {

	if(this->fd != 0){
		flush(ctx);

		::close(this->fd);
		this->fd = 0;
	}
	if(this->_fb != nullptr){
		delete this->_fb;
		this->_fb = nullptr;
	}

}

void FileOutputStream::write(IArrayObjectPrimitive<char>* buffer, int off, int len, ThreadContext* ctx){
	this->_fb->write(buffer, off, len);
}

void FileOutputStream::write(int b, ThreadContext* ctx) {
	this->_fb->write(b);
}

FileOutputStream::FileBuffer::FileBuffer(int fd) {
	this->fd = fd;
	long int pagesize = ::sysconf(_SC_PAGE_SIZE);
	this->num = 128;
	this->size = pagesize * this->num;

	one = ByteBuffer::allocate(size, nullptr); one->clear(nullptr);
	two = ByteBuffer::allocate(size, nullptr); two->clear(nullptr);
	buff = one;
	flushbuff = nullptr;

	this->th = nullptr;
}

FileOutputStream::FileBuffer::~FileBuffer() {
	delete one;
	delete two;
}

void* FileOutputStream::FileBuffer::doFlush(void* param) {
	FileBuffer* _this = (FileBuffer*)param;
	char* ptr = _this->flushbuff->rawPtr();

	int ret = ::write(_this->fd, ptr, _this->flushbuff->position(nullptr));
	if(ret){

	}

	_this->flushbuff->clear(nullptr);

	return nullptr;
}

void FileOutputStream::FileBuffer::flush() {
	if(this->th != nullptr){
		this->th->join();
	}

	this->flushbuff = this->buff;
	this->buff = this->buff == this->one ? this->two : this->one;

	th = SysThread::createThread(FileOutputStream::FileBuffer::doFlush, this);
	FileOutputStream::FileBuffer::doFlush(this);
}

void FileOutputStream::FileBuffer::join() {
	if(this->th != nullptr){
		this->th->join();
	}
}

void FileOutputStream::FileBuffer::write(IArrayObjectPrimitive<char>* buffer, int off, int len){
	const int maxLoop = off + len;
	int i;
	const int remain =buff->remaining(nullptr);
	const int firstMax = remain < maxLoop ? remain : maxLoop;

	char* src = buffer->raw->getPtr(off);
	int pos = this->buff->position(nullptr);
	char* dest = this->buff->data->getPtr(pos);

	for(i = off; i != firstMax; ++i){
		//this->buff->put(buffer->get(i), nullptr);
		*dest = *src;
		dest++; src++; pos++;
	}

	this->buff->position(pos, nullptr);

	if(!buff->hasRemaining(nullptr)){
		flush();
		pos = 0;
		dest = this->buff->data->getPtr(pos);
	}

	for(; i != maxLoop; i++){
		// this->buff->put(buffer->get(i), nullptr);
		*dest = *src;
		dest++; src++; pos++;
	}

	this->buff->position(pos, nullptr);
}
void FileOutputStream::FileBuffer::write(int b) {
	if(!buff->hasRemaining(nullptr)){
		flush();
	}
	char byteData = (char)b;
	this->buff->put(byteData, nullptr);
}

}}


