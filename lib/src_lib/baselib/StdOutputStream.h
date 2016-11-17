/*
 * Copyright (c) Tomohiro Iizuka. All rights reserved.
 * Licensed under the MIT license.
 */

#ifndef BASELIB_STDOUTPUTSTREAM_H_
#define BASELIB_STDOUTPUTSTREAM_H_

namespace java{ namespace lang {

using namespace java::io;

class StdOutputStream : public OutputStream {
public:
	/**
	 * STDOUT_FILENO
	 */
	StdOutputStream(const int fd);
	virtual ~StdOutputStream();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw() ;

	virtual void close(ThreadContext* ctx);
	virtual void flush(ThreadContext* ctx);
	virtual void write(IArrayObjectPrimitive<char>* buffer, ThreadContext* ctx);
	virtual void write(IArrayObjectPrimitive<char>* buffer, int off, int len, ThreadContext* ctx);
	virtual void write(int b, ThreadContext* ctx);

private:
	const int outFd;
};

}}

#endif /* BASELIB_STDOUTPUTSTREAM_H_ */
