/*
 * Copyright (c) Tomohiro Iizuka. All rights reserved.
 * Licensed under the MIT license.
 */




namespace java { namespace lang {

class Throwable;

class Error : public Throwable {
public:
	Error(ThreadContext* ctx);
	Error(UnicodeString* message, ThreadContext* ctx);
	Error(UnicodeString* message, Throwable* cause, ThreadContext* ctx);
	virtual ~Error() throw(){}
};

class CloneNotSupportedException : public Throwable {
public:
	CloneNotSupportedException(ThreadContext* ctx);
	virtual ~CloneNotSupportedException() throw() {}
};

class IndexOutOfBoundsException : public Throwable {
public:
	IndexOutOfBoundsException(ThreadContext* ctx);
	IndexOutOfBoundsException(UnicodeString* message, ThreadContext* ctx);
	IndexOutOfBoundsException(UnicodeString* message, Throwable* cause, ThreadContext* ctx);
	virtual ~IndexOutOfBoundsException() throw() {}
};

class Exception : public Throwable {
public:
	Exception(ThreadContext* ctx);
	Exception(UnicodeString* message, ThreadContext* ctx);
	Exception(UnicodeString* message, Throwable* cause, ThreadContext* ctx);
	virtual ~Exception() throw() {}

};


class NegativeArraySizeException : public Throwable {
public:
	NegativeArraySizeException(ThreadContext* ctx);
	NegativeArraySizeException(UnicodeString* message, ThreadContext* ctx);
	NegativeArraySizeException(UnicodeString* message, Throwable* cause, ThreadContext* ctx);
	virtual ~NegativeArraySizeException() throw() {}

};

class NumberFormatException : public Throwable {
public:
	NumberFormatException(ThreadContext* ctx);
	NumberFormatException(UnicodeString* message, ThreadContext* ctx);
	NumberFormatException(UnicodeString* message, Throwable* cause, ThreadContext* ctx);
	virtual ~NumberFormatException() throw() {}
};

class NullPointerException : public Throwable {
public:
	NullPointerException(ThreadContext* ctx);
	NullPointerException(UnicodeString* message, ThreadContext* ctx);
	NullPointerException(UnicodeString* message, Throwable* cause, ThreadContext* ctx);
	virtual ~NullPointerException() throw() {}

};

class IllegalArgumentException : public Throwable {
public:
	IllegalArgumentException(ThreadContext* ctx);
	IllegalArgumentException(UnicodeString* message, ThreadContext* ctx);
	IllegalArgumentException(UnicodeString* message, Throwable* cause, ThreadContext* ctx);
	virtual ~IllegalArgumentException() throw() {}

};

class StringIndexOutOfBoundsException : public Throwable {
public:
	StringIndexOutOfBoundsException(ThreadContext* ctx);
	StringIndexOutOfBoundsException(int index, ThreadContext* ctx);
	StringIndexOutOfBoundsException(UnicodeString* message, ThreadContext* ctx);
	StringIndexOutOfBoundsException(UnicodeString* message, Throwable* cause, ThreadContext* ctx);
	virtual ~StringIndexOutOfBoundsException() throw() {}

};

class ArrayIndexOutOfBoundsException : public Throwable {
public:
	ArrayIndexOutOfBoundsException(ThreadContext* ctx);
	ArrayIndexOutOfBoundsException(int index, ThreadContext* ctx);
	ArrayIndexOutOfBoundsException(UnicodeString* message, ThreadContext* ctx);
	ArrayIndexOutOfBoundsException(UnicodeString* message, Throwable* cause, ThreadContext* ctx);
	virtual ~ArrayIndexOutOfBoundsException() throw() {}

};

class IllegalStateException : public Throwable {
public:
	IllegalStateException(ThreadContext* ctx);
	IllegalStateException(int index, ThreadContext* ctx);
	IllegalStateException(UnicodeString* message, ThreadContext* ctx);
	IllegalStateException(UnicodeString* message, Throwable* cause, ThreadContext* ctx);
	virtual ~IllegalStateException() throw() {}
};

class RuntimeException : public Throwable {
public:
	RuntimeException(ThreadContext* ctx);
	RuntimeException(int index, ThreadContext* ctx);
	RuntimeException(UnicodeString* message, ThreadContext* ctx);
	RuntimeException(UnicodeString* message, Throwable* cause, ThreadContext* ctx);
	RuntimeException(Throwable* cause, ThreadContext* ctx);
	virtual ~RuntimeException() throw() {}

};

class MissingResourceException : public Throwable {
public:
	MissingResourceException(ThreadContext* ctx);
	MissingResourceException(int index, ThreadContext* ctx);
	MissingResourceException(UnicodeString* message, ThreadContext* ctx);
	MissingResourceException(UnicodeString* message, Throwable* cause, ThreadContext* ctx);
	virtual ~MissingResourceException() throw() {}
};

class ArithmeticException : public Throwable {
public:
	ArithmeticException(ThreadContext* ctx);
	ArithmeticException(int index, ThreadContext* ctx);
	ArithmeticException(UnicodeString* message, ThreadContext* ctx);
	ArithmeticException(UnicodeString* message, Throwable* cause, ThreadContext* ctx);
	virtual ~ArithmeticException() throw() {}
};


}}

namespace java { namespace io {

using namespace java::lang;

class IOException : public Throwable {
public:
	IOException(ThreadContext* ctx);
	IOException(UnicodeString* message, ThreadContext* ctx);;
	IOException(UnicodeString* message, Throwable* cause, ThreadContext* ctx);
	virtual ~IOException() throw() {}
};

class UnsupportedEncodingException : public IOException {
public:
	UnsupportedEncodingException(ThreadContext* ctx);
	UnsupportedEncodingException(UnicodeString* message, ThreadContext* ctx);
	UnsupportedEncodingException(UnicodeString* message, Throwable* cause, ThreadContext* ctx);
	virtual ~UnsupportedEncodingException() throw() {}
};

class EOFException : public IOException {
public:
	EOFException(ThreadContext* ctx);
	EOFException(UnicodeString* message, ThreadContext* ctx);
	EOFException(UnicodeString* message, Throwable* cause, ThreadContext* ctx);
	virtual ~EOFException() throw() {}
};

class FileNotFoundException : public IOException {
public:
	FileNotFoundException(ThreadContext* ctx);
	FileNotFoundException(UnicodeString* message, ThreadContext* ctx);
	FileNotFoundException(UnicodeString* message, Throwable* cause, ThreadContext* ctx);
	virtual ~FileNotFoundException() throw() {}
};

}}

namespace java { namespace nio {
using namespace java::lang;



class BufferUnderflowException : public Throwable {
public:
	BufferUnderflowException(ThreadContext* ctx);
	BufferUnderflowException(UnicodeString* message, ThreadContext* ctx);
	BufferUnderflowException(UnicodeString* message, Throwable* cause, ThreadContext* ctx);
	virtual ~BufferUnderflowException() throw() {}
};

class BufferOverflowException : public Throwable {
public:
	BufferOverflowException(ThreadContext* ctx);
	BufferOverflowException(UnicodeString* message, ThreadContext* ctx);
	BufferOverflowException(UnicodeString* message, Throwable* cause, ThreadContext* ctx);
	virtual ~BufferOverflowException() throw() {}
};

}}


namespace java { namespace nio { namespace charset {
using namespace java::lang;

class UnsupportedCharsetException : public Throwable {
public:
	UnsupportedCharsetException(ThreadContext* ctx);
	UnsupportedCharsetException(UnicodeString* message, ThreadContext* ctx);
	UnsupportedCharsetException(UnicodeString* message, Throwable* cause, ThreadContext* ctx);
	virtual ~UnsupportedCharsetException() throw() {}
};


}}}


