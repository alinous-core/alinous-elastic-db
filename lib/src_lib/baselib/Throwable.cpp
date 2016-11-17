/*
 * Copyright (c) Tomohiro Iizuka. All rights reserved.
 * Licensed under the MIT license.
 */


#include "includes.h"

namespace java { namespace lang {

Throwable::Throwable(ThreadContext* ctx) throw() : IObject(ctx) {
	this->message = nullptr;
	this->cause = nullptr;
}

Throwable::Throwable(UnicodeString* message, ThreadContext* ctx) throw() : IObject(ctx) {
	this->message = message;
	this->cause = nullptr;

	__GC_INS(this, this->message, UnicodeString);
}

Throwable::Throwable(UnicodeString* message, Throwable* cause, ThreadContext* ctx) throw() : IObject(ctx) {
	this->message = message;
	this->cause = cause;

	__GC_INS(this, this->message, UnicodeString);
	__GC_INS(this, this->cause, Throwable);
}
Throwable::Throwable(const wchar_t* message, ThreadContext* ctx) throw()  : IObject(ctx) {
	this->message = new UnicodeString(message, ctx);
	this->cause = cause;

	__GC_INS(this, this->message, UnicodeString);
	__GC_INS(this, this->cause, Throwable);
}

Throwable::Throwable(Throwable* cause, ThreadContext* ctx) throw() : IObject(ctx) {
	this->message = nullptr;
	this->cause = cause;

	__GC_INS(this, this->cause, Throwable);
}

void Throwable::printStackTrace(ThreadContext* ctx) {
	System::out->println(this->message, ctx);
}

Throwable::~Throwable() throw(){
	ThreadContext* ctx = ThreadContext::getCurentContext();

	__releaseRegerences(false, ctx);
}

void Throwable::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() {
	if(this->message != nullptr){
		__GC_DEC(this, this->message, UnicodeString);
		this->message = nullptr;
	}

	if(this->cause != nullptr){
		__GC_DEC(this, this->cause, Throwable);
		this->cause = nullptr;
	}

}

Throwable* Throwable::getCause(ThreadContext* ctx)  {
	return this->cause;
}
UnicodeString* Throwable::getMessage(ThreadContext* ctx)  {
	return this->message;
}

void Throwable::__cleanUp(ThreadContext* ctx) throw()
{
}


}}


