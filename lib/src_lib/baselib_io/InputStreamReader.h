/*
 * Copyright (c) Tomohiro Iizuka. All rights reserved.
 * Licensed under the MIT license.
 */


#ifndef BASELIB_IO_INPUTSTREAMREADER_H_
#define BASELIB_IO_INPUTSTREAMREADER_H_

namespace org {namespace alinous {namespace charset {
class CharsetManager;
class CharsetDecoder;
}}}

namespace java { namespace io {

using namespace org::alinous::charset;

class InputStreamReader : public Reader {
public:
	constexpr static const int BUFFER_SIZE{1024};

	InputStreamReader(InputStream* in, ThreadContext* ctx);
	InputStreamReader(InputStream* in, UnicodeString* charsetName, ThreadContext* ctx);

	void __init(ThreadContext* ctx);
	void __initBuffer(int bufferSize, ThreadContext* ctx);
	void __ReleaseBuffer(ThreadContext* ctx);

	virtual ~InputStreamReader();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();

	virtual void close(ThreadContext* ctx);

	virtual int read(ThreadContext* ctx) {
		wchar_t ch = this->stream->read(ctx);

		return ch;
	}

	virtual int read(IArrayObjectPrimitive<wchar_t>* b, ThreadContext* ctx){
		return Reader::read(b, ctx);
	}
	virtual int read(IArrayObjectPrimitive<wchar_t>* b, int off, int len, ThreadContext* ctx);

private:
	InputStream* stream;
	UnicodeString* charsetName;

	IArrayObjectPrimitive<char>* byteBufferArray;
	ByteBuffer* bytes;
	ByteBuffer* remainBytes;
	CharBuffer* chars;
	CharsetDecoder* decoder;
};

}} /* namespace alinous */

#endif /* BASELIB_IO_INPUTSTREAMREADER_H_ */
