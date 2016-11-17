/*
 * Copyright (c) Tomohiro Iizuka. All rights reserved.
 * Licensed under the MIT license.
 */


#ifndef BASELIB_IO_READER_H_
#define BASELIB_IO_READER_H_

namespace java { namespace io {

using namespace java::nio;

class Reader : public virtual IObject {
public:
	Reader(ThreadContext* ctx);
	virtual ~Reader();
	void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();

	virtual void close(ThreadContext* ctx) = 0;
	virtual int read(IArrayObjectPrimitive<wchar_t>* b, int off, int len, ThreadContext* ctx) = 0;
	virtual int read(IArrayObjectPrimitive<wchar_t>* b, ThreadContext* ctx);
	virtual int read(ThreadContext* ctx) = 0;
	virtual bool ready(ThreadContext* ctx);
	virtual void mark(int readlimit, ThreadContext* ctx);
	virtual bool markSupported(ThreadContext* ctx);
	virtual void reset(ThreadContext* ctx);

	virtual int read(CharBuffer* target, ThreadContext* ctx) final;

	virtual long long skip(long long ns, ThreadContext* ctx);
};

}} /* namespace alinous */

#endif /* BASELIB_IO_READER_H_ */
