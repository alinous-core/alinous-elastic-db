/*
 * AlinousSSLSocketFactory.h
 *
 *  Created on: 2016/12/09
 *      Author: iizuka
 */

#ifndef BASELIB_IO_ALINOUSSSLSOCKETFACTORY_H_
#define BASELIB_IO_ALINOUSSSLSOCKETFACTORY_H_



namespace alinous {
namespace net {

class AlinousSSLSocketFactory {
public:
	static AlinousSocket* createSocket(UnicodeString* host, int port, ThreadContext* ctx);
};

} /* namespace net */
} /* namespace alinous */

#endif /* BASELIB_IO_ALINOUSSSLSOCKETFACTORY_H_ */
