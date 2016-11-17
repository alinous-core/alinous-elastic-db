/*
 * Copyright (c) Tomohiro Iizuka. All rights reserved.
 * Licensed under the MIT license.
 */


#ifndef BASELIB_IO_SSLSOCKETFACTORY_H_
#define BASELIB_IO_SSLSOCKETFACTORY_H_


namespace javax {
namespace net {
namespace ssl {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::net::Socket;



class SSLSocketFactory : public IObject {
public:
	SSLSocketFactory(ThreadContext* ctx);

	virtual ~SSLSocketFactory();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();


	static SSLSocketFactory* getDefault(ThreadContext* ctx);
	Socket* createSocket(UnicodeString* host, int port, ThreadContext* ctx);

	static void __cleanUp(ThreadContext* ctx);

private:
	static SSLSocketFactory* instance;

};

} /* namespace ssl */
} /* namespace net */
} /* namespace javax */

#endif /* BASELIB_IO_SSLSOCKETFACTORY_H_ */
