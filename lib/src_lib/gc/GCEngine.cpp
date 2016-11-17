/*
 * Copyright (c) Tomohiro Iizuka. All rights reserved.
 * Licensed under the MIT license.
 */


#include "includes.h"


namespace alinous {

GCEngine::GCEngine(int hashSize) throw() {
	this->usedByRef = new HashedRawArray<IObjectStatus, IObjectStatus::Hash, IObjectStatus::RawCompare>(hashSize);
	this->readyToDelete = new HashedRawArray<IObjectStatus, IObjectStatus::Hash, IObjectStatus::RawCompare>(hashSize);

	this->cyclicBuffer =
			new HashedRawArray<IObjectStatus, IObjectStatus::Hash, IObjectStatus::RawCompare>(256);

	this->reglogs = new RawArray<GCObject>(1024 * 128);
	this->inclogs = new RawArray<GCObject>(1024 * 128);
	this->incownerlogs = new RawArray<GCObject>(1024 * 128);
	this->locklogs = new RawArray<GCObject>(1024 * 128);
}


GCEngine::~GCEngine() throw() {
	delete this->usedByRef;
	delete this->readyToDelete;

	delete this->cyclicBuffer;

	delete this->reglogs;
	delete this->locklogs;
	delete this->incownerlogs;
	delete this->inclogs;
}


void GCEngine::internalRegisterObject(GCObject* ptr) throw()
{
	IObjectStatus* stat = new IObjectStatus(ptr);
	this->readyToDelete->addElement(stat);
}


void GCEngine::applyLogs(ThreadContext* ctx, GCLogCollector* collector) throw()
{
	this->mutex.lock();

	RawArray<GCObject>* currentReg = nullptr;
	RawArray<GCObject>* currentLock = nullptr;

	RawArray<GCObject>* currentInc = nullptr;
	RawArray<GCObject>* currentOwner = nullptr;

	RawArray<GCObject>* unlockLog = collector->swichUnlockLog();
	RawArray<GCObject>* decLog = collector->swichDecLog();
	RawArray<GCObject>* decOwnerLog = collector->swichDecOwnerLog();

	// swap arrays
	this->regLogSpin.lock();

	//    register
	currentReg = this->reglogs;
	this->reglogs = new RawArray<GCObject>(1024 * 128);

	//    lock
	currentLock = this->locklogs;
	this->locklogs = new RawArray<GCObject>(1024 * 128);

	//    Increment
	currentInc = this->inclogs;
	currentOwner = this->incownerlogs;

	this->inclogs = new RawArray<GCObject>(1024 * 128);
	this->incownerlogs = new RawArray<GCObject>(1024 * 128);

	this->regLogSpin.unlock();


	// register
	int maxLoop = currentReg->size();
	for(int i = 0; i != maxLoop; ++i){
		GCObject* ptr = currentReg->get(i);
		internalRegisterObject(ptr);
	}
	delete currentReg;

	// locks
	maxLoop = currentLock->size();
	for(int i = 0; i != maxLoop; ++i){
		GCObject* ptr = currentLock->get(i);
		internalLock(ptr);
	}
	delete currentLock;

	// incs
	maxLoop = currentInc->size();
	for(int i = 0; i != maxLoop; ++i){
		GCObject* ptr = currentInc->get(i);
		GCObject* owner = currentOwner->get(i);

		internalIncStatus(owner, ptr);
	}
	delete currentInc;
	delete currentOwner;

	// unlock
	maxLoop = unlockLog->size();
	for(int i = 0; i != maxLoop; ++i){
		GCObject* ptr = unlockLog->get(i);

		if(!applyUnlockToReadyToDelete(ctx, ptr)){
			applyUnlockToUsed(ctx, ptr);
		}
	}
	delete unlockLog;

	// delete
	maxLoop = decLog->size();
	for(int i = 0; i != maxLoop; ++i){
		GCObject* ptr = decLog->get(i);
		GCObject* owner = decOwnerLog->get(i);

		if(!applyDecreaseToUsed(ctx, ptr, owner)){
			applyDecreaseToReadyToDelete(ctx, ptr, owner);
		}

	}
	delete decLog;
	delete decOwnerLog;

	this->mutex.unlock();
}

bool GCEngine::applyDecreaseToUsed(ThreadContext* ctx, GCObject* ptr, GCObject* owner) throw()
{
	IObjectStatus tmp(ptr);

	IObjectStatus* stat = this->usedByRef->search(&tmp);
	if(stat == nullptr){
		return false;
	}

	decStatus(ctx, stat, ptr, owner);
	if(stat->getRefs() == 0){
		this->usedByRef->removeByObj(stat);
		this->readyToDelete->addElement(stat);
	}

	return true;
}
bool GCEngine::applyDecreaseToReadyToDelete(ThreadContext* ctx, GCObject* ptr, GCObject* owner) throw()
{
	IObjectStatus tmp(ptr);

	IObjectStatus* stat = this->readyToDelete->search(&tmp);
	if(stat == nullptr){
		return false;
	}

	decStatus(ctx, stat, ptr, owner);

	return true;
}


bool GCEngine::applyUnlockToUsed(ThreadContext* ctx, GCObject* ptr) throw()
{
	IObjectStatus tmp(ptr);

	IObjectStatus* stat = this->usedByRef->search(&tmp);
	if(stat == nullptr){
		return false;
	}

	stat->unclock();

	if(stat->isReleasable()){
		IObjectUtils::forceReleaseRefs(stat->getPtr(), ctx, false);
	}
	else if(!stat->isLocked()){
		this->cyclicBuffer->reset();
		bool result = stat->checkCyclic(this->cyclicBuffer);
		if(result){
			clearCyclicRefs(ctx);
		}
	}

	return true;
}
bool GCEngine::applyUnlockToReadyToDelete(ThreadContext* ctx, GCObject* ptr) throw()
{
	IObjectStatus tmp(ptr);

	IObjectStatus* stat = this->readyToDelete->search(&tmp);
	if(stat == nullptr){
		return false;
	}

	stat->unclock();

	if(stat->isReleasable()){
		IObjectUtils::forceReleaseRefs(stat->getPtr(), ctx, false);
	}
	else if(!stat->isLocked()){
		this->cyclicBuffer->reset();
		bool result = stat->checkCyclic(this->cyclicBuffer);
		if(result){
			clearCyclicRefs(ctx);
		}
	}

	return true;
}


void GCEngine::internalIncStatus(GCObject* owner, GCObject* ptr) throw()
{
	IObjectStatus tmp(ptr);

	bool inReadyToDelete = true;
	IObjectStatus* stat = this->readyToDelete->search(&tmp);
	if(stat == nullptr){
		inReadyToDelete = false;
		stat = this->usedByRef->search(&tmp);
	}

	IObjectStatus* ownerStat = findObjectStatus(owner);

	stat->inc(ownerStat);
	if(inReadyToDelete){
		this->readyToDelete->removeByObj(stat);
		this->usedByRef->addElement(stat);
	}
}


void GCEngine::decStatus(ThreadContext* ctx, IObjectStatus* stat, GCObject* ptr, GCObject* owner) throw()
{
	IObjectStatus* ownerStat = nullptr;
	if(owner != nullptr){
		ownerStat = findObjectStatus(owner);
	}

	stat->dec(ownerStat);

	if(stat->isReleasable()){
		IObjectUtils::forceReleaseRefs(stat->getPtr(), ctx, ownerStat == nullptr);
	}else if(!stat->isLocked()){
		// cyclicTarget->addElement(stat);
		this->cyclicBuffer->reset();
		bool result = stat->checkCyclic(this->cyclicBuffer);
		if(result){
			clearCyclicRefs(ctx);
		}
	}
}

void GCEngine::clearCyclicRefs(ThreadContext* ctx) throw()
{
	auto it = this->cyclicBuffer->iterator();
	while(it.hasNext()){
		IObjectStatus* status = it.next();

		IObjectUtils::forceReleaseRefs(status->getPtr(), ctx, true);
	}
}

IObjectStatus* GCEngine::findObjectStatus(GCObject* ptr) throw()
{
	IObjectStatus tmp(ptr);

	IObjectStatus* owner = this->usedByRef->search(&tmp);
	if(owner == nullptr){
		owner = this->readyToDelete->search(&tmp);
	}
	return owner;
}

void GCEngine::lock(GCObject* ptr) throw()
{
	this->regLogSpin.lock();
	this->locklogs->addElement(ptr);
	this->regLogSpin.unlock();
}

void GCEngine::internalLock(GCObject* ptr) throw()
{
	IObjectStatus* stat = findObjectStatus(ptr);
	stat->lock();
}

int GCEngine::vacuum(ThreadContext* ctx) throw()
{
	RawArray<IObjectStatus, IObjectStatus::RawCompare> deleteList;

	this->mutex.lock();

	auto it = this->readyToDelete->iterator();
	while(it.hasNext()){
		IObjectStatus* stat = it.next();

		if(stat->isDeletable()){
			deleteList.addElement(stat);
		}
	}

	int maxLoop = deleteList.size();
	for(int i = 0; i != maxLoop; ++i){
		IObjectStatus* stat = deleteList.get(i);

		this->readyToDelete->removeByObj(stat);

		IObjectUtils::deleteIObject(stat->getPtr());
		delete stat;
	}

	this->mutex.unlock();

	return maxLoop;
}

void GCEngine::printGcStat() throw() {
	wprintf(L"#### Main GC Engine #############################\n");
	wprintf(L"READY TO DELETE : %d, USED : %d\n", this->readyToDelete->size(), this->usedByRef->size());

	if(this->usedByRef->size() > 0){
		auto it = this->usedByRef->iterator();
		while(it.hasNext()){
			IObjectStatus* stat = it.next();

			wprintf(L"%lld\n", stat->getPtr());
		}
	}

}

} /* namespace alinous */

