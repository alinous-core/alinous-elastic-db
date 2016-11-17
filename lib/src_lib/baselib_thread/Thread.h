/*
 * Copyright (c) Tomohiro Iizuka. All rights reserved.
 * Licensed under the MIT license.
 */


#ifndef BASELIB_THREAD_THREAD_H_
#define BASELIB_THREAD_THREAD_H_
namespace alinous {
class ThreadContext;
}

void* __alinous_thread_runner_starts(void *p);

namespace java { namespace lang {

using namespace alinous;
using namespace java::lang;

class IObject;


//class ThreadInfo;


class Runnable : public virtual IObject {
public:
	Runnable(ThreadContext* ctx) : IObject(ctx){}
	virtual ~Runnable(){}
	virtual void run(ThreadContext* ctx) = 0;

public:
	static void __cleanUp(ThreadContext* ctx)
	{
	}
};

class Thread : public Runnable, public virtual IObject {
public:
	Thread(ThreadContext* ctx);
	Thread(SysThread* thread, ThreadContext* ctx);
	Thread(Runnable *target, ThreadContext* ctx);
	Thread(Runnable *target, UnicodeString* name, ThreadContext* ctx);
	virtual ~Thread();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
	void start(ThreadContext* ctx);
	static void handler(int sig);
	static void __destructKey(void* info);
	static void* __alinous_thread_runner_starts(void *params);
	static Thread* getCurrentThread(ThreadContext* ctx);
	void join(ThreadContext* ctx);
	static void sleep(int milli, ThreadContext* ctx);
	virtual bool equals(IObject* obj, ThreadContext* ctx);
	class ValueCompare {
	public:
		int operator() (const SysThread* const a, const SysThread* const b, const ThreadContext* const ctx) const {
			return a->getId()  - b->getId();
		}
	};

	class Hash {
	public:
		u_int64_t operator() (const IObject* const a) const {
			const Thread* th = dynamic_cast<const Thread*>(a);
			return th->getId(nullptr);
		}
	};

	long getId(ThreadContext* ctx) const ;
	static Thread* currentThread(ThreadContext* ctx);
	virtual void run(ThreadContext* ctx) {}

	void setName(UnicodeString* name, ThreadContext* ctx);

private:
	SysThread *sysThread;
	Runnable *target;
	UnicodeString* name;
public:
	static void __cleanUp(ThreadContext* ctx)
	{
	}
};

}} /* namespace alinous */



#endif /* BASELIB_THREAD_THREAD_H_ */
