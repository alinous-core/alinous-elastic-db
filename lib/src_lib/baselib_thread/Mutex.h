/*
 * Copyright (c) Tomohiro Iizuka. All rights reserved.
 * Licensed under the MIT license.
 */


#ifndef BASELIB_THREAD_MUTEX_H_
#define BASELIB_THREAD_MUTEX_H_

namespace alinous {
class SysMutex;
class ThreadContext;
}

namespace java { namespace lang {
class IObject;
}}

namespace alinous { namespace concurrent {

using namespace alinous;
using namespace java::lang;

class Mutex : public SysMutex, public virtual IObject {
public:
	Mutex(ThreadContext* ctx) throw() : IObject(ctx), SysMutex() {}
	virtual ~Mutex() throw() {}
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx)throw(){}
	inline void lock(ThreadContext* ctx) throw() {
		SysMutex::lock();
	}
	inline void unlock(ThreadContext* ctx) throw() {
		SysMutex::unlock();
	}

public:
	static void __cleanUp(ThreadContext* ctx) throw()
	{
	}
};

class SpinMutex : public SysSpinMutex, public virtual IObject {
public:
	SpinMutex(ThreadContext* ctx) throw() : IObject(ctx), SysSpinMutex() {}
	virtual ~SpinMutex() throw() {}
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx)throw(){}

	inline void lock(ThreadContext* ctx) throw() {
		SysSpinMutex::lock();
	}
	inline void unlock(ThreadContext* ctx) throw() {
		SysSpinMutex::unlock();
	}

public:
	static void __cleanUp(ThreadContext* ctx) throw()
	{
	}
};

}} /* namespace java */

#endif /* BASELIB_THREAD_MUTEX_H_ */
