/*
 * AlinousSocket.h
 *
 *  Created on: 2016/12/09
 *      Author: iizuka
 */

#ifndef BASELIB_IO_ALINOUSSOCKET_H_
#define BASELIB_IO_ALINOUSSOCKET_H_

namespace java{ namespace net{
class Socket;
}}

namespace alinous {
namespace net {

using ::java::net::Socket;

class AlinousSocket : public IObject {
public:
	AlinousSocket(UnicodeString* host, int port, ThreadContext* ctx);
	AlinousSocket(Socket* socket, ThreadContext* ctx);

	virtual ~AlinousSocket();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();

	AlinousSocket* init(ThreadContext* ctx);

	OutputStream* getOutputStream(ThreadContext* ctx);
	InputStream* getInputStream(ThreadContext* ctx);
	void close(ThreadContext* ctx);
private:
	UnicodeString* host;
	int port;
	Socket* socket;
};

} /* namespace net */
} /* namespace alinous */

#endif /* BASELIB_IO_ALINOUSSOCKET_H_ */
