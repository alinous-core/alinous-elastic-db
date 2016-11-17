/*
 * Copyright (c) Tomohiro Iizuka. All rights reserved.
 * Licensed under the MIT license.
 */

#include "includes.h"

#ifndef BASELIB_IO_OUTPUTSTREAMWRITER_H_
#define BASELIB_IO_OUTPUTSTREAMWRITER_H_

namespace org {namespace alinous {namespace charset {
class CharsetManager;
class CharsetEncoder;
}}}


namespace java { namespace io {

using namespace org::alinous::charset;

class OutputStreamWriter : public Writer {
public:
	OutputStreamWriter(OutputStream* out, UnicodeString* charsetName, ThreadContext* ctx);
	OutputStreamWriter(OutputStream* out, ThreadContext* ctx);

	void __init(ThreadContext* ctx);
	void __initBuffer(int bufferSize, ThreadContext* ctx);
	void __ReleaseBuffer(ThreadContext* ctx);

	virtual ~OutputStreamWriter() {
		ThreadContext *ctx = ThreadContext::getCurentContext();
		ctx->incGcDenial();
		__releaseRegerences(false, ctx);
		ctx->decGcDenial();
	}

	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();

	virtual void close(ThreadContext* ctx);
	virtual void flush(ThreadContext* ctx);
	virtual void write(IArrayObjectPrimitive<wchar_t>* cbuf, int off, int len, ThreadContext* ctx);
	virtual void write(IArrayObjectPrimitive<wchar_t>* cbuf, ThreadContext* ctx){
		write(cbuf, 0, cbuf->length, ctx);
	}
	virtual void write(int c, ThreadContext* ctx);
	virtual void write(UnicodeString* str, int off, int len, ThreadContext* ctx);
	virtual void write(UnicodeString* str, ThreadContext* ctx){
		write(str, 0, str->length(ctx), ctx);
	}

	class EncodingTask {
	public:
		EncodingTask(IArrayObjectPrimitive<wchar_t>* cbuf, int off, int len) {

		}

		void execute(){

		}

	private:

	};

private:
	OutputStream *out;
	UnicodeString* charsetName;
	CharsetEncoder* encoder;

	CharBuffer* chars;
	ByteBuffer* bytes;
	IArrayObjectPrimitive<char>* outBuff;

};

}} /* namespace alinous */

#endif /* BASELIB_IO_OUTPUTSTREAMWRITER_H_ */
