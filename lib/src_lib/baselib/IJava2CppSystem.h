/*
 * Copyright (c) Tomohiro Iizuka. All rights reserved.
 * Licensed under the MIT license.
 */

#ifndef BASELIB_IJAVA2CPPSYSTEM_H_
#define BASELIB_IJAVA2CPPSYSTEM_H_

namespace alinous {



class IJava2CppSystem {
public:
	IJava2CppSystem(){}
	virtual ~IJava2CppSystem(){}

	virtual void startMemoryAllocator() = 0;
	virtual void startGCExecutor() = 0;

	virtual void endThread(ThreadContext* context) = 0;
	virtual void gc(bool isFinal, ThreadContext* ctx) = 0;
	virtual bool isBackgoundGCEmpty() = 0;
	virtual void asyncGC(ThreadContext* ctx) = 0;
	virtual GCEngine* getGC() = 0;

	virtual void addThreadContext(ThreadContext* context) = 0;
	virtual ThreadContext* searchThreadContext(ThreadContext* context) = 0;

	static IJava2CppSystem* getSelf();


	static bool isEnd;

};

} /* namespace alinous */

#endif /* BASELIB_IJAVA2CPPSYSTEM_H_ */
