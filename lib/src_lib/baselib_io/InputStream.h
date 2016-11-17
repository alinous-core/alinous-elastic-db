/*
 * Copyright (c) Tomohiro Iizuka. All rights reserved.
 * Licensed under the MIT license.
 */


#ifndef BASELIB_IO_INPUTSTREAM_H_
#define BASELIB_IO_INPUTSTREAM_H_

namespace java { namespace io {

class InputStream : public virtual IObject {
public:
	InputStream(ThreadContext* ctx) : IObject(ctx) {}
	virtual ~InputStream(){}

	virtual void close(ThreadContext* ctx) = 0;
	virtual int read(IArrayObjectPrimitive<char>* b, int off, int len, ThreadContext* ctx) = 0;
	virtual int read(IArrayObjectPrimitive<char>* b, ThreadContext* ctx) {
		return read(b, 0, b->length, ctx);
	}
	virtual int read(ThreadContext* ctx) = 0;
	virtual int available(ThreadContext* ctx) { return 0; }
	virtual void mark(int readlimit, ThreadContext* ctx) {}
	virtual bool markSupported(ThreadContext* ctx) { return false; }
	virtual void reset(ThreadContext* ctx){};

	virtual long long skip(long long n, ThreadContext* ctx){ return n; }

	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw(){}
};

}} /* namespace alinous */

#endif /* BASELIB_IO_INPUTSTREAM_H_ */
