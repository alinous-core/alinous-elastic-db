/*
 * Copyright (c) Tomohiro Iizuka. All rights reserved.
 * Licensed under the MIT license.
 */


#ifndef BASELIB_IO_WRITER_H_
#define BASELIB_IO_WRITER_H_

namespace java { namespace io {

class Writer : public virtual IObject {
private:
	static StaticUnicodeString __TOKEN_NULL;
	static UnicodeStringWrapper _TOKEN_NULL;
public:
	constexpr static UnicodeStringWrapper* const TOKEN_NULL{&_TOKEN_NULL};

	Writer(ThreadContext* ctx);
	virtual ~Writer();
	void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();

	virtual void close(ThreadContext* ctx) = 0;
	virtual void flush(ThreadContext* ctx) = 0;

	virtual Writer* append(wchar_t c, ThreadContext* ctx);
	virtual Writer* append(CharSequence* csq, ThreadContext* ctx);
	virtual Writer* append(CharSequence* csq, int start, int end, ThreadContext* ctx);
	virtual void write(IArrayObjectPrimitive<wchar_t>* cbuf, ThreadContext* ctx);
	virtual void write(IArrayObjectPrimitive<wchar_t>* cbuf, int off, int len, ThreadContext* ctx) = 0;

	virtual void write(int c, ThreadContext* ctx) = 0;
	virtual void write(UnicodeString* str, ThreadContext* ctx);
	virtual void write(UnicodeString* str, int off, int len, ThreadContext* ctx) = 0;

	virtual bool checkError() {
        return false;
    }
};

}} /* namespace alinous */

#endif /* BASELIB_IO_WRITER_H_ */
