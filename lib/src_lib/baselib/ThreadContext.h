/*
 * Copyright (c) Tomohiro Iizuka. All rights reserved.
 * Licensed under the MIT license.
 */


#ifndef BASELIB_THREADCONTEXT_H_
#define BASELIB_THREADCONTEXT_H_

namespace java { namespace lang{
class IObject;
}}

namespace alinous {

using namespace java::lang;

class IJava2CppSystem;
class ThreadContext;
class SysThread;
class WaitReleaseNotifier;
class GCNotifier;


#ifdef __DEBUG__
struct StackFrame {
	const char* fileName;
	unsigned int lineNo;
	const char* functionName;
};

void printStackTrace(RawArray<StackFrame>* stackTrace){
	auto it = stackTrace->iterator();
	while(it.hasNext()){
		StackFrame* frame = it.next();

		wprintf(L"%s : %d [%s]\n", frame->fileName, frame->lineNo, frame->functionName);
	}

	wprintf(L"\n\n");
}

#endif

class ThreadContext : public MemoryInterface {
public:
	ThreadContext(SysThread *thread) throw();
	virtual ~ThreadContext() throw();
	void init(IJava2CppSystem* ps) throw();
	static ThreadContext *newThreadContext() throw();
	static ThreadContext* getCurentContext() throw();
public:
	inline GCObject* mv(GCObject* owner, GCObject* prev, GCObject* next) const throw()
	{
		if(prev != nullptr && !prev->staticInst){
			pLogger->logDec(owner, prev);
		}
		if(next != nullptr && !next->staticInst){
			pLogger->logInc(owner, next);
		}

		return next;
	}

	inline GCObject* reg(GCObject* ptr) throw()
	{
		pLogger->registerObject(ptr);

		return ptr;
	}

	inline GCObject* ins(GCObject* owner, GCObject* ptr) throw()
	{
		pLogger->logInc(owner, ptr);

		return ptr;
	}
	inline GCObject* dec(GCObject* owner, GCObject* ptr) throw()
	{
		pLogger->logDec(owner, ptr);
		return ptr;
	}
	inline const IObject* global(IObject* ptr) throw()
	{
		return ptr;
	}

public:


public:
	void asyncGC() throw();
	void localGC() throw();
	void localGC(bool force) throw();
#ifdef __DEBUG__
	void reportDeleteToDebugEngine(IObject* ptr);
	void showInfo(IObject* ptr);
#endif

	void gc(bool isFinal) throw();
	int getCurrentVariableSize() throw();
	const SysThread* getThread() const throw() { return this->pThread; }


	ThreadContext* traceStack(const char* fileName, int line) throw();
	bool setLostExt(bool lost) throw();
	void pushSynchronizedBlock(WaitReleaseNotifier * block) throw();
	WaitReleaseNotifier* popSynchronizedBlock() throw();
	WaitReleaseNotifier* getPeekSynchronizedBlock() throw();
	void incGcDenial() throw();
	void decGcDenial() throw();
	bool isGcDenial() throw();
public:

#ifdef __DEBUG__
	void dumpMainStatus(){
		this->system->getGC()->dumpStatus();
	}

	void dumpLocalGCStatus() {
		this->pLogger->dumpLogs();
	}

	void dumpAll() {
		dumpLocalGCStatus();
		dumpMainStatus();
	}
#endif

	void memLeakCheck() throw();
	GCLogCollector* switchCollector() throw();
	void importCollector(GCLogCollector* col) throw();


	GCLogCollector* pLogger;
private:
	IJava2CppSystem* system;
	SysThread *pThread;

	RawArray<GCObject>* protectLockObjects;

	bool lostExt;
	int denyGCCount;

	static SysMutex newLock;

public:
	void pushGCNotifier(GCNotifier* notifier) throw();
	GCNotifier* popGCNotifier() throw();
	GCNotifier* peekGCNotifier() throw();
	void registerObject(GCObject* obj, ThreadContext* ctx, const wchar_t* filePath, int line, const wchar_t* classOrFunc) throw();
	void releaseUndeletable(GCObject* obj) throw();
	void returnProtect(GCObject* obj) throw();
	void protectRootObject(GCObject* obj) throw();

	RawArray<GCNotifier>* notifiers;


public:
	struct ValueCompare {
	public:
		int operator() (const ThreadContext* const a, const ThreadContext* const b, const ThreadContext* const ctx) const throw();
	};

};



} /* namespace alinous */

#endif /* BASELIB_THREADCONTEXT_H_ */
