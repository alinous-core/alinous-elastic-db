/*
 * Copyright (c) Tomohiro Iizuka. All rights reserved.
 * Licensed under the MIT license.
 */


#ifndef BASELIB_IO_PRINTSTREAM_H_
#define BASELIB_IO_PRINTSTREAM_H_


namespace java { namespace io {

class PrintStream : public OutputStream {
public:
	PrintStream(OutputStream* outSt, ThreadContext* ctx) ;
	PrintStream(OutputStream* outSt, bool autoflush, ThreadContext* ctx);
	PrintStream(OutputStream* outSt, bool autoflush, UnicodeString* enc, ThreadContext* ctx);
	virtual ~PrintStream();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
	virtual void close(ThreadContext* ctx);
	void flush(ThreadContext* ctx);
	void print(UnicodeString* str, ThreadContext* ctx);
	void print(IArrayObjectPrimitive<wchar_t>* charArray, ThreadContext* ctx);
	void print(wchar_t ch, ThreadContext* ctx);
	void print(double value, ThreadContext* ctx);
	void print(float value, ThreadContext* ctx);
	void print(int value, ThreadContext* ctx);
	void print(long long value, ThreadContext* ctx);
	void print(bool value, ThreadContext* ctx);
	void print(IObject* value, ThreadContext* ctx);
	void newline(ThreadContext* ctx);
	void println(UnicodeString* str, ThreadContext* ctx);
	void println(IArrayObjectPrimitive<wchar_t>* charArray, ThreadContext* ctx);
	void println(wchar_t ch, ThreadContext* ctx);
	void println(double value, ThreadContext* ctx);
	void println(float value, ThreadContext* ctx);
	void println(int value, ThreadContext* ctx);
	void println(long long value, ThreadContext* ctx);
	void println(bool value, ThreadContext* ctx);
	void println(IObject* value, ThreadContext* ctx);
	virtual void write(IArrayObjectPrimitive<char>* buffer, int off, int len, ThreadContext* ctx);
	virtual void write(int b, ThreadContext* ctx);
private:
    bool autoflush;
    UnicodeString* encoding;
    OutputStream* outStream;
    SysMutex* mutex;

public:
    static StaticUnicodeString __NULL_TOKEN;
    static UnicodeStringWrapper _NULL_TOKEN;
    static constexpr UnicodeStringWrapper* NULL_TOKEN{&_NULL_TOKEN};

    static StaticUnicodeString __DEFAULT_ENCODE;
    static UnicodeStringWrapper _DEFAULT_ENCODE;
    static constexpr UnicodeStringWrapper* DEFAULT_ENCODE{&_DEFAULT_ENCODE};

    static StaticUnicodeString __LINE_SEPARATOR;
    static UnicodeStringWrapper _LINE_SEPARATOR;
    static constexpr UnicodeStringWrapper* LINE_SEPARATOR{&_LINE_SEPARATOR};
};

}}




#endif /* BASELIB_IO_PRINTSTREAM_H_ */
