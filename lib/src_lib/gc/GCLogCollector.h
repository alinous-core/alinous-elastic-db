/*
 * Copyright (c) Tomohiro Iizuka. All rights reserved.
 * Licensed under the MIT license.
 */


#ifndef GC_GCLOGCOLLECTOR_H_
#define GC_GCLOGCOLLECTOR_H_

namespace alinous {

class GCLogCollector {
public:
	constexpr static int LOG_DEFAULT {1024 * 4};

	GCLogCollector(GCEngine* gcEngine) throw() ;
	~GCLogCollector() throw() ;

	RawArray<GCObject>* swichDecLog() throw();
	RawArray<GCObject>* swichDecOwnerLog() throw();
	RawArray<GCObject>* swichUnlockLog() throw();

	inline void registerObject(GCObject* ptr) throw() {
		this->gcEngine->registerObject(ptr);
	}

	inline void logInc(GCObject* owner, GCObject* ptr) throw() {
		this->gcEngine->incStatus(owner, ptr);
	}

	inline void logDec(GCObject* owner, GCObject* ptr)throw() {
		this->decLog->addElement(ptr);
		this->decOwnerLog->addElement(owner);
	}

	inline void unlock(GCObject* ptr) throw() {
		this->unlockLog->addElement(ptr);
	}
	inline void syncLog(ThreadContext* ctx) throw() {
		this->gcEngine->applyLogs(ctx, this);
	}

	inline int logSize() throw() {
		return this->decLog->size() + this->unlockLog->size();
	}

	inline void protectByLock(GCObject* obj) throw() {
		return this->gcEngine->lock(obj);
	}

	GCEngine* gcEngine;
	RawArray<GCObject>* decLog;
	RawArray<GCObject>* decOwnerLog;
	RawArray<GCObject>* unlockLog;

};

}  // namespace alinous





#endif /* GC_GCLOGCOLLECTOR_H_ */
