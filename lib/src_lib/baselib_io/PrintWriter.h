/*
 * Copyright (c) Tomohiro Iizuka. All rights reserved.
 * Licensed under the MIT license.
 */


#ifndef BASELIB_IO_PRINTWRITER_H_
#define BASELIB_IO_PRINTWRITER_H_

namespace java {
namespace io {

class PrintWriter : public Writer {
private:
	static StaticUnicodeString __lineSeparator;
	static UnicodeStringWrapper _lineSeparator;
public:
	constexpr static UnicodeStringWrapper* const lineSeparator{&_lineSeparator};

	PrintWriter(OutputStream* out, ThreadContext* ctx);
	PrintWriter(OutputStream* out, bool autoflush, ThreadContext* ctx);
	PrintWriter(Writer* out, ThreadContext* ctx);
	PrintWriter(Writer* out, bool autoflush, ThreadContext* ctx);
	virtual ~PrintWriter();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
	virtual void close(ThreadContext* ctx);
	virtual void flush(ThreadContext* ctx);
	void print(wchar_t ch, ThreadContext* ctx);
	void print(double dnum, ThreadContext* ctx);
	void print(float fnum, ThreadContext* ctx);
	void print(int inum, ThreadContext* ctx);
	void print(long long lnum, ThreadContext* ctx);
	void print(IObject* obj, ThreadContext* ctx);
	void print(UnicodeString* str, ThreadContext* ctx);
	void println(wchar_t ch, ThreadContext* ctx);
	void println(double dnum, ThreadContext* ctx);
	void println(float fnum, ThreadContext* ctx);
	void println(int inum, ThreadContext* ctx);
    void println(long long lnum, ThreadContext* ctx);
    void println(IObject* obj, ThreadContext* ctx);
    void println(UnicodeString* str, ThreadContext* ctx);
    void newline(ThreadContext* ctx);
	virtual void write(IArrayObjectPrimitive<wchar_t>* cbuf, int off, int len, ThreadContext* ctx);
	virtual void write(int c, ThreadContext* ctx);
	virtual void write(wchar_t c, ThreadContext* ctx);
	virtual void write(UnicodeString* str, int off, int len, ThreadContext* ctx);
	virtual void write(UnicodeString* str, ThreadContext* ctx);

protected:
	Writer* out;
	bool autoflush;
};

} /* namespace io */
} /* namespace java */

#endif /* BASELIB_IO_PRINTWRITER_H_ */
