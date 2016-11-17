/*
 * Copyright (c) Tomohiro Iizuka. All rights reserved.
 * Licensed under the MIT license.
 */


#ifndef GC_BACKGROUNDGCEXECUTOR_H_
#define GC_BACKGROUNDGCEXECUTOR_H_

namespace alinous {

class BackGroundGcAction {
public:
	BackGroundGcAction(ThreadContext* ctx) throw();
	void exec(ThreadContext* ctx, IJava2CppSystem* system) throw() ;
	~BackGroundGcAction() throw() {
	}

private:
	GCLogCollector* logCollector;
};

class BackGroundGcExecutor {
public:
	BackGroundGcExecutor(IJava2CppSystem* system) throw();
	~BackGroundGcExecutor() throw();
	bool isEmpty() throw();
	void asyncGc(ThreadContext* ctx) throw();
	void execLoop(ThreadContext* ctx) throw();
	static void* threadFunc(void* param) throw();
private:
	TaskSynchronizer actionLock;
	RawLinkedList<BackGroundGcAction> actions;
	SysThread* thread;
	IJava2CppSystem* system;

	bool run;
	bool executing;
};

}  // namespace alinous



#endif /* GC_BACKGROUNDGCEXECUTOR_H_ */
