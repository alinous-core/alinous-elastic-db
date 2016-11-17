/*
 * Copyright (c) Tomohiro Iizuka. All rights reserved.
 * Licensed under the MIT license.
 */


#ifndef BASELIB_THREAD_SEMAPHORE_H_
#define BASELIB_THREAD_SEMAPHORE_H_

namespace java { namespace lang {
class IObject;
}}

namespace alinous {
class ThreadContext;
}


namespace java { namespace util { namespace concurrent {

using namespace java::lang;
using namespace alinous;

class Semaphore : public virtual IObject {
public:
	Semaphore(int permit, ThreadContext* ctx) : IObject(ctx) {
		this->mutex = new SysMutex();
	}
	virtual ~Semaphore(){

	}

	void acquire(int permits) {

	}

	void release(int permits) {

	}
	void release() {
		release(1);
	}
	void acquire() {
		acquire(1);
	}
private:
	SysMutex* mutex;
};

}}} /* namespace java */

#endif /* BASELIB_THREAD_SEMAPHORE_H_ */
