/*
 * Copyright (c) Tomohiro Iizuka. All rights reserved.
 * Licensed under the MIT license.
 */


#ifndef BASELIB_IO_OUTPUTSTREAM_H_
#define BASELIB_IO_OUTPUTSTREAM_H_

namespace java { namespace io {

class OutputStream : public virtual IObject {
public:
	OutputStream(ThreadContext* ctx);
	virtual ~OutputStream();

	virtual void close(ThreadContext* ctx){};
	virtual void flush(ThreadContext* ctx) = 0;
	virtual void write(IArrayObjectPrimitive<char>* buffer, ThreadContext* ctx);
	virtual void write(IArrayObjectPrimitive<char>* buffer, int off, int len, ThreadContext* ctx) = 0;
	virtual void write(int b, ThreadContext* ctx) = 0;

	virtual bool checkError();

	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw(){}
};

}} /* namespace alinous */

#endif /* BASELIB_IO_OUTPUTSTREAM_H_ */
