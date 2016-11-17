/*
 * Copyright (c) Tomohiro Iizuka. All rights reserved.
 * Licensed under the MIT license.
 */


#include "includes.h"

namespace java{ namespace net{

InetSocketAddress::InetSocketAddress(UnicodeString* hostname, int port, ThreadContext* ctx) : IObject(ctx), hostname(hostname), port(port) {
	__GC_INS(this, this->hostname, UnicodeString);
}
InetSocketAddress::~InetSocketAddress() {
	ThreadContext *ctx = ThreadContext::getCurentContext();
	__releaseRegerences(false, ctx);
}

void InetSocketAddress::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() {
	if(this->hostname != nullptr){
		__GC_DEC(this, this->hostname, UnicodeString);

		this->hostname = nullptr;
	}
}


SocketInputStream::SocketInputStream(int fd, ThreadContext* ctx) : IObject(ctx), InputStream(ctx), fd(fd) {

}
SocketInputStream::~SocketInputStream() {
	ThreadContext *ctx = ThreadContext::getCurentContext();
	__releaseRegerences(false, ctx);
}
void SocketInputStream::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() {

}
void SocketInputStream::close(ThreadContext* ctx){

}
int SocketInputStream::read(IArrayObjectPrimitive<char>* b, int offset, int count, ThreadContext* ctx){
	int _count = (b->length - offset) < count ? (b->length - offset) : count;
	char* ptr = b->rawPtr() + offset;

	int n = ::read(this->fd, ptr, _count);
	if(n >= 0){
		return n;
	}

	return -1;
}
int SocketInputStream::read(IArrayObjectPrimitive<char>* b, ThreadContext* ctx) {
	return read(b, 0, b->length, ctx);
}
int SocketInputStream::read(ThreadContext* ctx){
	char ch[1]{};

	int res = ::read(this->fd, ch, 1);
	if(res == -1){
		throw new IOException(new UnicodeString(L"could not read data from the host address", ctx), ctx);
	}
	return ch[0];
}


SocketOutputStream::SocketOutputStream(int fd, ThreadContext* ctx) : IObject(ctx), OutputStream(ctx), fd(fd) {

}
SocketOutputStream::~SocketOutputStream() {
	ThreadContext *ctx = ThreadContext::getCurentContext();
	__releaseRegerences(false, ctx);
}
void SocketOutputStream::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() {

}

void SocketOutputStream::close(ThreadContext* ctx){

}
void SocketOutputStream::flush(ThreadContext* ctx){

}
void SocketOutputStream::write(IArrayObjectPrimitive<char>* buffer, ThreadContext* ctx) {
    write(buffer, 0, buffer->length, ctx);
}
void SocketOutputStream::write(IArrayObjectPrimitive<char>* buffer, int off, int len, ThreadContext* ctx){
	char* ptr = buffer->rawPtr();
	ptr = ptr + off;

	int size = ::write(this->fd, ptr, len);
	if(size != len){
		throw new IOException(new UnicodeString(L"could not send data to the host address", ctx), ctx);
	}
}
void SocketOutputStream::write(int b, ThreadContext* ctx){
	char byte = b;
	int size = ::write(this->fd, &byte, 1);
	if(size != 1){
		throw new IOException(new UnicodeString(L"could not send data to the host address", ctx), ctx);
	}
}


Socket::Socket(ThreadContext* ctx) : IObject(ctx), socket(0) {}
Socket::Socket(int fd, ThreadContext* ctx) : IObject(ctx), socket(fd) {}

Socket::Socket(UnicodeString* hostStr, int port, ThreadContext* ctx) : IObject(ctx), socket(0)
{
	InetSocketAddress* addr = (new(ctx) InetSocketAddress(hostStr, port, ctx));

	connect(addr, 300, ctx);
}

Socket::~Socket() {
	ThreadContext *ctx = ThreadContext::getCurentContext();
	__releaseRegerences(false, ctx);
}
void Socket::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() {
	close(ctx);

}
void Socket::connect(InetSocketAddress* addr, int timeout, ThreadContext* ctx) {
	char* hostname = addr->hostname->toCString(ctx);

	struct hostent *servhost = ::gethostbyname(hostname);

	if(servhost == nullptr){
		unsigned long int addr;
		addr = ::inet_addr(hostname);
		servhost= ::gethostbyaddr((char *)&addr,sizeof(addr),AF_INET);
		if(servhost == nullptr){
			delete [] hostname;
			throw new IOException(new UnicodeString(L"could not resolve host address", ctx), ctx);
		}
	}

	socket = ::socket(AF_INET, SOCK_STREAM, 0);
	if(socket < 0){
		delete [] hostname;
		throw new IOException(new UnicodeString(L"could not create socket", ctx), ctx);
	}

	int hport = htons(addr->port);
	//struct servent *se = ::getservbyport(hport, "tcp");

	struct sockaddr_in server;
	::memset((char*)&server, 0, sizeof(server));
	server.sin_family = AF_INET;
	server.sin_port = hport;
	FastCopy::copy((char *)&server.sin_addr, servhost->h_addr, servhost->h_length);

	int res = ::connect(this->socket, (sockaddr*)&server, sizeof(server));

	if(res < 0){
		delete [] hostname;
		throw new IOException(new UnicodeString(L"could not connect server", ctx), ctx);
	}



	delete [] hostname;
}
void Socket::close(ThreadContext* ctx){
	if(this->socket > 0){
		::close(this->socket);
		this->socket = 0;
	}
}

OutputStream* Socket::getOutputStream(ThreadContext* ctx){
	return new(ctx) SocketOutputStream(this->socket, ctx);
}

InputStream* Socket::getInputStream(ThreadContext* ctx){
	return new(ctx) SocketInputStream(this->socket, ctx);
}



}}


