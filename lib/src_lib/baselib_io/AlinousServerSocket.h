/*
 * Copyright (c) Tomohiro Iizuka. All rights reserved.
 * Licensed under the MIT license.
 */


#ifndef BASELIB_IO_ALINOUSSERVERSOCKET_H_
#define BASELIB_IO_ALINOUSSERVERSOCKET_H_


namespace java{ namespace net{
class ServerSocket;
}}

namespace alinous {
namespace net {

using ::java::net::ServerSocket;
using ::java::net::Socket;

class AlinousServerSocket : public IObject {
public:
	AlinousServerSocket(int port, ThreadContext* ctx) throw();
	virtual ~AlinousServerSocket();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();

	AlinousServerSocket* init(ThreadContext* ctx);
	Socket* accept(ThreadContext* ctx);

private:
	int port;
	ServerSocket* svsocket;

};

} /* namespace net */
} /* namespace alinous */

#endif /* BASELIB_IO_ALINOUSSERVERSOCKET_H_ */
