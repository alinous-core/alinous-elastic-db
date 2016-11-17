/*
 * Copyright (c) Tomohiro Iizuka. All rights reserved.
 * Licensed under the MIT license.
 */


#ifndef SYSTEM_SYSTHREAD_H_
#define SYSTEM_SYSTHREAD_H_


#define THREAD_ID pthread_t

namespace java { namespace lang {
class UnicodeString;
}}


namespace alinous {

using namespace ::java::lang;

typedef void *(*SysThread__start_routine) (void *);

class SysThread;


class ThreadInfo{
public:
	SysThread* thread;
	RawArrayMemAlloc* alloc;
};

class ThreadParams {
public:
	void *param;
	SysThread* thread;
};

class SysThread {
private:
	SysThread() throw() {
		this->id = 0;
		this->name_cstr = nullptr;
	}
public:
	~SysThread() throw() {
		this->id = 0;
		if(this->name_cstr != nullptr){
			delete [] this->name_cstr;
			this->name_cstr = nullptr;
		}

	}

	static SysThread* getCurrentThread() throw() ;

	static inline RawArrayMemAlloc* getMalloc() throw(){
		void* value = ::pthread_getspecific(SysThread::key);

		if(__builtin_expect(value == nullptr, 0)){
			SysThread* thread = new SysThread();
			thread->id = pthread_self();

			SysThread::init(thread);

			value = ::pthread_getspecific(SysThread::key);
		}

		ThreadInfo* info = (ThreadInfo*)value;
		return info->alloc;
	}
	static THREAD_ID getCurrentThreadId() throw() ;
	static SysThread* createThread(SysThread__start_routine threadFunc, void* params) throw() ;
	static void destructKey(void* info) throw() ;
	static void exits() throw();
	static void onceInit() throw();

	static void init(SysThread* thread) throw();

	bool suspend() throw();
	void resume() throw();
	void interrupt() throw();
	void join() const throw();

	THREAD_ID getId() const throw() { return this->id; }
	void setId(THREAD_ID thd) throw() { this->id = thd; }

	class ValueCompare {
	public:
		int operator() (const SysThread* const a, const SysThread* const b, const ThreadContext* const ctx) const throw() {
			return a->id  - b->id;
		}
	};

	void setName(UnicodeString* name, ThreadContext* ctx);


private:
	THREAD_ID id;
	char* name_cstr;
public:
	static pthread_key_t key;
	static bool key_registerd;
	static pthread_once_t once;
	static sigset_t mask;

	static bool initStaticDone;
	static bool initStatic() throw() {
		sigemptyset(&mask);
		sigaddset(&mask, SIGSUSPEND);
		sigaddset(&mask, SIGINTERRUPT);
		return true;
	}
public:
	static constexpr int SIGSUSPEND{35};
	static constexpr int SIGINTERRUPT{36};

};

} /* namespace alinous */

#endif /* SYSTEM_SYSTHREAD_H_ */
