/*
 * Copyright (c) Tomohiro Iizuka. All rights reserved.
 * Licensed under the MIT license.
 */


#include "includes.h"

namespace java { namespace lang {

Error::Error(ThreadContext* ctx) : IObject(ctx),Throwable(ctx) {}
Error::Error(UnicodeString* message, ThreadContext* ctx) : IObject(ctx),Throwable(message, ctx) {}
Error::Error(UnicodeString* message, Throwable* cause, ThreadContext* ctx) : IObject(ctx),Throwable(message, cause, ctx) {}

CloneNotSupportedException::CloneNotSupportedException(ThreadContext* ctx) : IObject(ctx),Throwable(ctx) {}

IndexOutOfBoundsException::IndexOutOfBoundsException(ThreadContext* ctx) : IObject(ctx),Throwable(ctx) {}
IndexOutOfBoundsException::IndexOutOfBoundsException(UnicodeString* message, ThreadContext* ctx) : IObject(ctx),Throwable(message, ctx) {}
IndexOutOfBoundsException::IndexOutOfBoundsException(UnicodeString* message, Throwable* cause, ThreadContext* ctx) : IObject(ctx),Throwable(message, cause, ctx) {}


Exception::Exception(ThreadContext* ctx) : IObject(ctx),Throwable(ctx) {}
Exception::Exception(UnicodeString* message, ThreadContext* ctx) : IObject(ctx),Throwable(message, ctx) {}
Exception::Exception(UnicodeString* message, Throwable* cause, ThreadContext* ctx) : IObject(ctx),Throwable(message, cause, ctx) {}

NegativeArraySizeException::NegativeArraySizeException(ThreadContext* ctx) : IObject(ctx),Throwable(ctx) {}
NegativeArraySizeException::NegativeArraySizeException(UnicodeString* message, ThreadContext* ctx) : IObject(ctx),Throwable(message, ctx) {}
NegativeArraySizeException::NegativeArraySizeException(UnicodeString* message, Throwable* cause, ThreadContext* ctx) : IObject(ctx),Throwable(message, cause, ctx) {}

NumberFormatException::NumberFormatException(ThreadContext* ctx) : IObject(ctx),Throwable(ctx) {}
NumberFormatException::NumberFormatException(UnicodeString* message, ThreadContext* ctx) : IObject(ctx),Throwable(message, ctx) {}
NumberFormatException::NumberFormatException(UnicodeString* message, Throwable* cause, ThreadContext* ctx) : IObject(ctx),Throwable(message, cause, ctx) {}


NullPointerException::NullPointerException(ThreadContext* ctx) : IObject(ctx),Throwable(ctx) {}
NullPointerException::NullPointerException(UnicodeString* message, ThreadContext* ctx) : IObject(ctx),Throwable(message, ctx) {}
NullPointerException::NullPointerException(UnicodeString* message, Throwable* cause, ThreadContext* ctx) : IObject(ctx),Throwable(message, cause, ctx) {}

IllegalArgumentException::IllegalArgumentException(ThreadContext* ctx) : IObject(ctx),Throwable(ctx) {}
IllegalArgumentException::IllegalArgumentException(UnicodeString* message, ThreadContext* ctx) : IObject(ctx),Throwable(message, ctx) {}
IllegalArgumentException::IllegalArgumentException(UnicodeString* message, Throwable* cause, ThreadContext* ctx) : IObject(ctx),Throwable(message, cause, ctx) {}


StringIndexOutOfBoundsException::StringIndexOutOfBoundsException(ThreadContext* ctx) : IObject(ctx),Throwable(ctx) {}
StringIndexOutOfBoundsException::StringIndexOutOfBoundsException(int index, ThreadContext* ctx) : IObject(ctx),Throwable(ctx) {}
StringIndexOutOfBoundsException::StringIndexOutOfBoundsException(UnicodeString* message, ThreadContext* ctx) : IObject(ctx),Throwable(message, ctx) {}
StringIndexOutOfBoundsException::StringIndexOutOfBoundsException(UnicodeString* message, Throwable* cause, ThreadContext* ctx) : IObject(ctx),Throwable(message, cause, ctx) {}


ArrayIndexOutOfBoundsException::ArrayIndexOutOfBoundsException(ThreadContext* ctx) : IObject(ctx),Throwable(ctx) {}
ArrayIndexOutOfBoundsException::ArrayIndexOutOfBoundsException(int index, ThreadContext* ctx) : IObject(ctx),Throwable(ctx) {}
ArrayIndexOutOfBoundsException::ArrayIndexOutOfBoundsException(UnicodeString* message, ThreadContext* ctx) : IObject(ctx),Throwable(message, ctx) {}
ArrayIndexOutOfBoundsException::ArrayIndexOutOfBoundsException(UnicodeString* message, Throwable* cause, ThreadContext* ctx) : IObject(ctx),Throwable(message, cause, ctx) {}


IllegalStateException::IllegalStateException(ThreadContext* ctx) : IObject(ctx),Throwable(ctx) {}
IllegalStateException::IllegalStateException(int index, ThreadContext* ctx) : IObject(ctx),Throwable(ctx) {}
IllegalStateException::IllegalStateException(UnicodeString* message, ThreadContext* ctx) : IObject(ctx),Throwable(message, ctx) {}
IllegalStateException::IllegalStateException(UnicodeString* message, Throwable* cause, ThreadContext* ctx) : IObject(ctx),Throwable(message, cause, ctx) {}


RuntimeException::RuntimeException(ThreadContext* ctx) : IObject(ctx),Throwable(ctx) {}
RuntimeException::RuntimeException(int index, ThreadContext* ctx) : IObject(ctx),Throwable(ctx) {}
RuntimeException::RuntimeException(UnicodeString* message, ThreadContext* ctx) : IObject(ctx),Throwable(message, ctx) {}
RuntimeException::RuntimeException(UnicodeString* message, Throwable* cause, ThreadContext* ctx) : IObject(ctx),Throwable(message, cause, ctx) {}
RuntimeException::RuntimeException(Throwable* cause, ThreadContext* ctx) : IObject(ctx),Throwable(cause, ctx) {}


MissingResourceException::MissingResourceException(ThreadContext* ctx) : IObject(ctx),Throwable(ctx) {}
MissingResourceException::MissingResourceException(int index, ThreadContext* ctx) : IObject(ctx),Throwable(ctx) {}
MissingResourceException::MissingResourceException(UnicodeString* message, ThreadContext* ctx) : IObject(ctx),Throwable(message, ctx) {}
MissingResourceException::MissingResourceException(UnicodeString* message, Throwable* cause, ThreadContext* ctx) : IObject(ctx),Throwable(message, cause, ctx) {}

ArithmeticException::ArithmeticException(ThreadContext* ctx) : IObject(ctx),Throwable(ctx) {}
ArithmeticException::ArithmeticException(int index, ThreadContext* ctx) : IObject(ctx),Throwable(ctx) {}
ArithmeticException::ArithmeticException(UnicodeString* message, ThreadContext* ctx) : IObject(ctx),Throwable(message, ctx) {}
ArithmeticException::ArithmeticException(UnicodeString* message, Throwable* cause, ThreadContext* ctx) : IObject(ctx),Throwable(message, cause, ctx) {}
}}


namespace java { namespace io {
IOException::IOException(ThreadContext* ctx) : IObject(ctx),Throwable(ctx) {}
IOException::IOException(UnicodeString* message, ThreadContext* ctx) : IObject(ctx),Throwable(message, ctx) {}
IOException::IOException(UnicodeString* message, Throwable* cause, ThreadContext* ctx) : IObject(ctx),Throwable(message, cause, ctx) {}

UnsupportedEncodingException::UnsupportedEncodingException(ThreadContext* ctx) : IObject(ctx),IOException(ctx) {}
UnsupportedEncodingException::UnsupportedEncodingException(UnicodeString* message, ThreadContext* ctx) : IObject(ctx),IOException(message, ctx) {}
UnsupportedEncodingException::UnsupportedEncodingException(UnicodeString* message, Throwable* cause, ThreadContext* ctx) : IObject(ctx),IOException(message, cause, ctx) {}

EOFException::EOFException(ThreadContext* ctx) : IObject(ctx),IOException(ctx) {}
EOFException::EOFException(UnicodeString* message, ThreadContext* ctx) : IObject(ctx),IOException(message, ctx) {}
EOFException::EOFException(UnicodeString* message, Throwable* cause, ThreadContext* ctx) : IObject(ctx),IOException(message, cause, ctx) {}

FileNotFoundException::FileNotFoundException(ThreadContext* ctx) : IObject(ctx),IOException(ctx) {}
FileNotFoundException::FileNotFoundException(UnicodeString* message, ThreadContext* ctx) : IObject(ctx),IOException(message, ctx) {}
FileNotFoundException::FileNotFoundException(UnicodeString* message, Throwable* cause, ThreadContext* ctx) : IObject(ctx),IOException(message, cause, ctx) {}
}}


namespace java { namespace nio {
BufferUnderflowException::BufferUnderflowException(ThreadContext* ctx) : IObject(ctx),Throwable(ctx) {}
BufferUnderflowException::BufferUnderflowException(UnicodeString* message, ThreadContext* ctx) : IObject(ctx),Throwable(message, ctx) {}
BufferUnderflowException::BufferUnderflowException(UnicodeString* message, Throwable* cause, ThreadContext* ctx) : IObject(ctx),Throwable(message, cause, ctx) {}

BufferOverflowException::BufferOverflowException(ThreadContext* ctx) : IObject(ctx),Throwable(ctx) {}
BufferOverflowException::BufferOverflowException(UnicodeString* message, ThreadContext* ctx) : IObject(ctx),Throwable(message, ctx) {}
BufferOverflowException::BufferOverflowException(UnicodeString* message, Throwable* cause, ThreadContext* ctx) : IObject(ctx),Throwable(message, cause, ctx) {}
}}

namespace java { namespace nio { namespace charset {
UnsupportedCharsetException::UnsupportedCharsetException(ThreadContext* ctx) : IObject(ctx),Throwable(ctx) {}
UnsupportedCharsetException::UnsupportedCharsetException(UnicodeString* message, ThreadContext* ctx) : IObject(ctx),Throwable(message, ctx) {}
UnsupportedCharsetException::UnsupportedCharsetException(UnicodeString* message, Throwable* cause, ThreadContext* ctx) : IObject(ctx),Throwable(message, cause, ctx) {}
}}}

namespace java { namespace net {
UnknownHostException::UnknownHostException(ThreadContext* ctx) : IObject(ctx),Throwable(ctx) {}
UnknownHostException::UnknownHostException(UnicodeString* message, ThreadContext* ctx) : IObject(ctx),Throwable(message, ctx) {}
UnknownHostException::UnknownHostException(UnicodeString* message, Throwable* cause, ThreadContext* ctx) : IObject(ctx),Throwable(message, cause, ctx) {}

}}


