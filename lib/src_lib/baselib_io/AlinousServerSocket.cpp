/*
 * Copyright (c) Tomohiro Iizuka. All rights reserved.
 * Licensed under the MIT license.
 */


#include "includes.h"

namespace alinous {
namespace net {

AlinousServerSocket::AlinousServerSocket(int port, ThreadContext* ctx) throw() : IObject(ctx), port(port), svsocket(nullptr)
{

}

AlinousServerSocket::~AlinousServerSocket(){
	ThreadContext *ctx = ThreadContext::getCurentContext();
	__releaseRegerences(false, ctx);
}


void AlinousServerSocket::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() {
	if(this->svsocket != nullptr){
		this->svsocket->close(ctx);

		__GC_DEC(this, this->svsocket, ServerSocket);
		this->svsocket = nullptr;
	}
}

AlinousServerSocket* AlinousServerSocket::init(ThreadContext* ctx){
	GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"AlinousServerSocket", L"init");
	{
		ServerSocket* sock = new(ctx) ServerSocket(this->port, ctx);
		sock->init(ctx);

		__GC_MV(this, &(this->svsocket), sock, ServerSocket);
	}

	return this;
}

Socket* AlinousServerSocket::accept(ThreadContext* ctx){
	return this->svsocket->accept(ctx);
}


} /* namespace net */
} /* namespace alinous */
