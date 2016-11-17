/*
 * Copyright (c) Tomohiro Iizuka. All rights reserved.
 * Licensed under the MIT license.
 */


#include "includes.h"


namespace javax {
namespace net {
namespace ssl {

SSLSocketFactory* SSLSocketFactory::instance = nullptr;

SSLSocketFactory::SSLSocketFactory(ThreadContext* ctx) : IObject(ctx)
{

}

SSLSocketFactory::~SSLSocketFactory() {
	ThreadContext *ctx = ThreadContext::getCurentContext();
	__releaseRegerences(false, ctx);
}
void SSLSocketFactory::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() {

}

void SSLSocketFactory::__cleanUp(ThreadContext* ctx) {
	if(SSLSocketFactory::instance != nullptr){
		__GC_DEC(nullptr, SSLSocketFactory::instance, SSLSocketFactory);
	}
}

SSLSocketFactory* SSLSocketFactory::getDefault(ThreadContext* ctx)
{
	if(SSLSocketFactory::instance == nullptr){
		SSLSocketFactory::instance = __GC_INS(nullptr, new(ctx) SSLSocketFactory(ctx), SSLSocketFactory);
	}
	return SSLSocketFactory::instance;
}

Socket* SSLSocketFactory::createSocket(UnicodeString* host, int port, ThreadContext* ctx)
{
	return nullptr;
}

} /* namespace ssl */
} /* namespace net */
} /* namespace javax */
