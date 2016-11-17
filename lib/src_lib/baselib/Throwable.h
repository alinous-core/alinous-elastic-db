/*
 * Copyright (c) Tomohiro Iizuka. All rights reserved.
 * Licensed under the MIT license.
 */

#ifndef BASELIB_THROWABLE_H_
#define BASELIB_THROWABLE_H_

namespace alinous {
class ThreadContext;
}

namespace java { namespace lang {

using namespace alinous;

class IObject;
class UnicodeString;

class Throwable : public virtual IObject {
public:
	Throwable(ThreadContext* ctx) throw();
	Throwable(UnicodeString* message, ThreadContext* ctx) throw();
	Throwable(UnicodeString* message, Throwable* cause, ThreadContext* ctx) throw();
	Throwable(const wchar_t* message, ThreadContext* ctx) throw();
	Throwable(Throwable* cause, ThreadContext* ctx) throw();
	virtual void printStackTrace(ThreadContext* ctx);
	virtual ~Throwable() throw();

	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw() ;
	virtual Throwable* getCause(ThreadContext* ctx) ;
	virtual UnicodeString* getMessage(ThreadContext* ctx) ;
protected:
	UnicodeString* message;
	Throwable* cause;
public:
	static void __cleanUp(ThreadContext* ctx) throw();
};

}} /* namespace alinous */

#endif /* BASELIB_THROWABLE_H_ */
