/*
 * Copyright (c) Tomohiro Iizuka. All rights reserved.
 * Licensed under the MIT license.
 */


#ifndef GC_GCENGINE_H_
#define GC_GCENGINE_H_


namespace alinous {

class GCLogCollector;
class GcLog;
class ThreadContext;

class GCEngine {
public:
	GCEngine(int hashSize) throw();
	virtual ~GCEngine() throw();

	inline void registerObject(GCObject* ptr) throw()
	{
		this->regLogSpin.lock();
		this->reglogs->addElement(ptr);
		this->regLogSpin.unlock();
	}

	void applyLogs(ThreadContext* ctx, GCLogCollector* collector) throw();
	inline void incStatus(GCObject* owner, GCObject* ptr) throw() {
		this->regLogSpin.lock();

		this->inclogs->addElement(ptr);
		this->incownerlogs->addElement(owner);

		this->regLogSpin.unlock();
	}

	int vacuum(ThreadContext* ctx) throw();
	int readtToDeleteSize() throw() {
		return this->readyToDelete->size();
	}

	void lock(GCObject* ptr) throw();

	void printGcStat() throw();

private:
	void internalRegisterObject(GCObject* ptr) throw();
	void internalLock(GCObject* ptr) throw();
	void internalIncStatus(GCObject* owner, GCObject* ptr) throw();

	bool applyUnlockToUsed(ThreadContext* ctx, GCObject* ptr) throw();
	bool applyUnlockToReadyToDelete(ThreadContext* ctx, GCObject* ptr) throw();

	bool applyDecreaseToUsed(ThreadContext* ctx, GCObject* ptr, GCObject* owner) throw();
	bool applyDecreaseToReadyToDelete(ThreadContext* ctx, GCObject* ptr, GCObject* owner) throw();


	void decStatus(ThreadContext* ctx, IObjectStatus* stat, GCObject* ptr, GCObject* owner) throw();
	IObjectStatus* findObjectStatus(GCObject* ptr) throw();

	void clearCyclicRefs(ThreadContext* ctx) throw();
private:
	HashedRawArray<IObjectStatus, IObjectStatus::Hash, IObjectStatus::RawCompare>* usedByRef;
	HashedRawArray<IObjectStatus, IObjectStatus::Hash, IObjectStatus::RawCompare>* readyToDelete;

	HashedRawArray<IObjectStatus, IObjectStatus::Hash, IObjectStatus::RawCompare>* cyclicBuffer;

	SysMutex mutex;


	RawArray<GCObject>* reglogs;
	RawArray<GCObject>* inclogs;
	RawArray<GCObject>* incownerlogs;
	RawArray<GCObject>* locklogs;

	SysSpinMutex regLogSpin;

};


} /* namespace alinous */

#endif /* GC_GCENGINE_H_ */
