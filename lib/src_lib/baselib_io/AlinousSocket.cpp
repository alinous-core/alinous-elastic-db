/*
 * AlinousSocket.cpp
 *
 *  Created on: 2016/12/09
 *      Author: iizuka
 */

#include "include/global.h"

namespace alinous {
namespace net {


AlinousSocket::AlinousSocket(UnicodeString* _host, int _port, ThreadContext* ctx) : IObject(ctx), host(_host), port(_port), socket(nullptr)
{
	__GC_INS(this, this->host, UnicodeString);
}
AlinousSocket::AlinousSocket(Socket* socket, ThreadContext* ctx): IObject(ctx), host(nullptr), port(0), socket(socket)
{
	__GC_INS(this, this->socket, Socket);
}

AlinousSocket* AlinousSocket::init(ThreadContext* ctx){
	this->socket = new Socket(this->host, this->port, ctx);
	__GC_INS(this, this->socket, Socket);

	return this;
}

AlinousSocket::~AlinousSocket(){
	ThreadContext *ctx = ThreadContext::getCurentContext();
	__releaseRegerences(false, ctx);
}

void AlinousSocket::__releaseRegerences(bool prepare, ThreadContext* ctx) throw(){
	if(this->socket != nullptr){
		this->socket->close(ctx);

		__GC_DEC(this, this->socket, Socket);
		this->socket = nullptr;
	}

	if(this->host != nullptr){
		__GC_DEC(this, this->host, UnicodeString);
		this->host = nullptr;
	}
}


OutputStream* AlinousSocket::getOutputStream(ThreadContext* ctx){
	return this->socket->getOutputStream(ctx);
}
InputStream* AlinousSocket::getInputStream(ThreadContext* ctx){
	return this->socket->getInputStream(ctx);
}
void AlinousSocket::close(ThreadContext* ctx){
	this->socket->close(ctx);
}


} /* namespace net */
} /* namespace alinous */
