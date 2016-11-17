/*
 * Copyright (c) Tomohiro Iizuka. All rights reserved.
 * Licensed under the MIT license.
 */


#ifndef BASELIB_IO_SERVERSOCKET_H_
#define BASELIB_IO_SERVERSOCKET_H_

namespace java{ namespace net {

using namespace ::alinous;
using namespace ::java::lang;


class ServerSocket : public IObject {
public:
	ServerSocket(int port, ThreadContext* ctx): IObject(ctx), port(port), srvsock(-1) {

	}

	ServerSocket* init(ThreadContext* ctx){
		struct sockaddr_in addr;

		srvsock = ::socket(AF_INET, SOCK_STREAM, 0);

		int onflg = 1;
		int result = setsockopt(srvsock, SOL_SOCKET, SO_REUSEADDR, &onflg, sizeof(onflg) );
		if(result != 0){
			::shutdown(this->srvsock, SHUT_RDWR);
			::close(this->srvsock);
			this->srvsock = 0;
			throw new(ctx) IOException(new(ctx) UnicodeString(L"could not set server socket option", ctx), ctx);
		}


		int sock_buf_size = 1024 * 256;
		result = setsockopt(srvsock, SOL_SOCKET, SO_SNDBUF,
		                   (char *)&sock_buf_size, sizeof(sock_buf_size) );
		if(result != 0){
			::shutdown(this->srvsock, SHUT_RDWR);
			::close(this->srvsock);
			this->srvsock = 0;
			throw new(ctx) IOException(new(ctx) UnicodeString(L"could not set server socket option(SO_SNDBUF)", ctx), ctx);
		}
		result = setsockopt(srvsock, SOL_SOCKET, SO_RCVBUF,
		                   (char *)&sock_buf_size, sizeof(sock_buf_size) );
		if(result != 0){
			::shutdown(this->srvsock, SHUT_RDWR);
			::close(this->srvsock);
			this->srvsock = 0;
			throw new(ctx) IOException(new(ctx) UnicodeString(L"could not set server socket option(SO_RCVBUF)", ctx), ctx);
		}

		addr.sin_family = AF_INET;
		addr.sin_port = htons(this->port);
		addr.sin_addr.s_addr = INADDR_ANY;

		result = ::bind(srvsock, (struct sockaddr *)&addr, sizeof(addr));
		if(result != 0){
			::shutdown(this->srvsock, SHUT_RDWR);
			::close(this->srvsock);
			this->srvsock = 0;
			throw new(ctx) IOException(new(ctx) UnicodeString(L"could not bind server socket", ctx), ctx);
		}

		result = ::listen(srvsock, 1024);
		if(result != 0){
			::shutdown(this->srvsock, SHUT_RDWR);
			::close(this->srvsock);
			this->srvsock = 0;
			throw new(ctx) IOException(new(ctx) UnicodeString(L"could not listen server socket", ctx), ctx);
		}

		return this;
	}


	virtual ~ServerSocket(){
		ThreadContext *ctx = ThreadContext::getCurentContext();
		__releaseRegerences(false, ctx);
	}
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw() {
		close(ctx);
	}

	void close(ThreadContext* ctx){
		if(this->srvsock > 0){
			::shutdown(this->srvsock, SHUT_RDWR);
			::close(this->srvsock);
			this->srvsock = 0;
		}
	}

	Socket* accept(ThreadContext* ctx){
		struct sockaddr_in client;
		socklen_t len = sizeof(client);

		int sock = ::accept(srvsock, (struct sockaddr *)&client, &len);

		return new Socket(sock, ctx);
	}

private:
	int port;
	int srvsock;
};

}} /* namespace alinous */

#endif /* BASELIB_IO_SERVERSOCKET_H_ */
