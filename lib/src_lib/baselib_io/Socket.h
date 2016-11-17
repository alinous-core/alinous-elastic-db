/*
 * Copyright (c) Tomohiro Iizuka. All rights reserved.
 * Licensed under the MIT license.
 */


#ifndef BASELIB_IO_SOCKET_H_
#define BASELIB_IO_SOCKET_H_

namespace java{ namespace net{

using namespace ::alinous;
using namespace ::java::lang;

class InetSocketAddress : public IObject {
public:
	InetSocketAddress(UnicodeString* hostname, int port, ThreadContext* ctx);
	virtual ~InetSocketAddress();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
	UnicodeString* hostname;
	int port;
};

class SocketInputStream : public InputStream {
public:
	SocketInputStream(int fd, ThreadContext* ctx);
	virtual ~SocketInputStream();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
	virtual void close(ThreadContext* ctx);
	virtual int read(IArrayObjectPrimitive<char>* b, int offset, int count, ThreadContext* ctx);
	virtual int read(IArrayObjectPrimitive<char>* b, ThreadContext* ctx);
	virtual int read(ThreadContext* ctx);
private:
	int fd;
};
class SocketOutputStream : public OutputStream {
public:
	SocketOutputStream(int fd, ThreadContext* ctx);
	virtual ~SocketOutputStream();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
	virtual void close(ThreadContext* ctx);
	virtual void flush(ThreadContext* ctx);
	virtual void write(IArrayObjectPrimitive<char>* buffer, ThreadContext* ctx);
	virtual void write(IArrayObjectPrimitive<char>* buffer, int off, int len, ThreadContext* ctx);
	virtual void write(int b, ThreadContext* ctx);

private:
	int fd;
};


class Socket : public IObject {
public:
	Socket(ThreadContext* ctx);
	Socket(int fd, ThreadContext* ctx);
	Socket(UnicodeString* hostStr, int port, ThreadContext* ctx);

	virtual ~Socket();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
	void connect(InetSocketAddress* addr, int timeout, ThreadContext* ctx);
	void close(ThreadContext* ctx);
	OutputStream* getOutputStream(ThreadContext* ctx);
	InputStream* getInputStream(ThreadContext* ctx);
private:
	int socket;
};

}} /* namespace alinous */

#endif /* BASELIB_IO_SOCKET_H_ */
