/*
 * Copyright (c) Tomohiro Iizuka. All rights reserved.
 * Licensed under the MIT license.
 */

#ifndef BASELIB_JAVA2CPPSYSTEM_H_
#define BASELIB_JAVA2CPPSYSTEM_H_

namespace alinous {

class ThreadContext;
class SysMutex;

class ThreadContext;
class ThreadContextFactory;


class Java2CppSystem final : public IJava2CppSystem {
public:
	Java2CppSystem() throw() : IJava2CppSystem() {
		static MemoryAllocDestructor destruct;
		Java2CppSystem::memManager = new AlinousMemoryManager();

		this->pGCEngine = nullptr;
		this->threadContexts = nullptr;
		this->pGCExecutor = nullptr;
	}


	void startMemoryAllocator() throw() {
		Java2CppSystem::memManager->startThread(4);
	}
	void startGCExecutor() throw() {
		this->threadContexts = new RawArray<ThreadContext, ThreadContext::ValueCompare>(8);
		this->pGCEngine = new GCEngine(1024 * 1024);
		this->pGCExecutor = new BackGroundGcExecutor(this);
	}

	virtual ~Java2CppSystem() throw() {
		delete this->pGCExecutor;
		delete this->pGCEngine;
		delete this->threadContexts;
	}

	virtual bool isBackgoundGCEmpty() throw() {
		return this->pGCExecutor->isEmpty();
	}

	virtual void asyncGC(ThreadContext* ctx) throw() {
		this->pGCExecutor->asyncGc(ctx);
	}

	GCEngine* getGC() throw() {
		return this->pGCEngine;
	}
	void gc(bool isFinal, ThreadContext* ctx) throw() {
		this->pGCEngine->vacuum(ctx);
	}

	void endThread(ThreadContext* context) throw()
	{
		contextMutex.lock();

		if(this->threadContexts->search(context) != 0){
			this->threadContexts->removeByObj(context);
		}

		contextMutex.unlock();
	}

	void addThreadContext(ThreadContext* context) throw()
	{
		contextMutex.lock();
		this->threadContexts->addElementWithSorted(context);
		contextMutex.unlock();
	}

	ThreadContext* searchThreadContext(ThreadContext* context) throw()
	{
		contextMutex.lock();
		ThreadContext* current = this->threadContexts->search(context);
		contextMutex.unlock();

		return current;
	}
public:
	static AlinousMemoryManager* memManager;
private: // members
	GCEngine* pGCEngine;
	BackGroundGcExecutor* pGCExecutor;

	RawArray<ThreadContext,ThreadContext::ValueCompare> *threadContexts;
	static int threadContextCompare(void* av, void* bv) throw() ;
	SysMutex contextMutex;
};


} /* namespace alinous */

#endif /* BASELIB_JAVA2CPPSYSTEM_H_ */
