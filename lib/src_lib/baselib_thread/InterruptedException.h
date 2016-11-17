/*
 * Copyright (c) Tomohiro Iizuka. All rights reserved.
 * Licensed under the MIT license.
 */


#ifndef BASELIB_THREAD_INTERRUPTEDEXCEPTION_H_
#define BASELIB_THREAD_INTERRUPTEDEXCEPTION_H_

namespace java { namespace lang {
class IObject;
class Throwable;
}}
namespace alinous {
class ThreadContext;
}

namespace java { namespace lang {

using namespace alinous;
using namespace java::lang;


class InterruptedException : public Throwable {
public:
	InterruptedException(ThreadContext* ctx) : IObject(ctx), Throwable(ctx) {

	}
	static void __cleanUp(ThreadContext* ctx)
	{
	}

};

}} /* namespace java */

#endif /* BASELIB_THREAD_INTERRUPTEDEXCEPTION_H_ */
