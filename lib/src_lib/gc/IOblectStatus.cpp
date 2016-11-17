/*
 * Copyright (c) Tomohiro Iizuka. All rights reserved.
 * Licensed under the MIT license.
 */


#include "includes.h"

namespace alinous {

int IObjectStatus::RawCompare::operator() (const IObjectStatus* const a, const IObjectStatus* const b, const ThreadContext* const ctx) const throw() {
	long long diff = (u_int64_t)a->ptr - (u_int64_t)b->ptr;
	if(diff == 0){
		return 0;
	}
	return diff > 0 ? 1 : -1;
}

int IObjectStatus::OwnerStatus::ValueCompare::operator() (const OwnerStatus* const a, const OwnerStatus* const b, const ThreadContext* const ctx) const throw() {
	long long diff = (u_int64_t)a->ptr->getPtr() - (u_int64_t)b->ptr->getPtr();
	if(diff == 0){
		return 0;
	}
	return diff > 0 ? 1 : -1;
}

void IObjectStatus::OwnerStatus::inc() throw(){
	++count;
	this->ptr->incTo();
}
void IObjectStatus::OwnerStatus::dec() throw(){
	--count;
	this->ptr->decTo();
}
int IObjectStatus::OwnerStatus::getCount() throw(){
	return this->count;
}

IObjectStatus::IObjectStatus(GCObject* ptr) throw() : ptr(ptr), refs(0), numFromOwners(0), toCount(0), locked(1) {
	this->owners = new RawArray<OwnerStatus, typename OwnerStatus::ValueCompare>();
}

void IObjectStatus::inc(IObjectStatus* owner) throw() {
	this->refs++;
	if(owner == nullptr){
		return;
	}

	OwnerStatus* status = findOwner(owner);
	if(status == nullptr){
		status = new OwnerStatus(owner);
		status->inc();
		this->owners->addElement(status);
	}else{
		status->inc();
		if(status->getCount() == 0){
			this->owners->removeByObj(status);
			delete status;
		}
	}

	this->numFromOwners++;
}

void IObjectStatus::dec(IObjectStatus* owner) throw(){
	this->refs--;
	if(owner == nullptr){
		return;
	}

	OwnerStatus* status = findOwner(owner);
	if(status == nullptr){
		status = new OwnerStatus(owner);
		status->dec();
		this->owners->addElement(status);
	}
	else{
		status->dec();
		if(status->getCount() == 0){
			this->owners->removeByObj(status);
			delete status;
		}
	}

	this->numFromOwners--;
}

bool IObjectStatus::checkCyclic(HashedRawArray<IObjectStatus, IObjectStatus::Hash, IObjectStatus::RawCompare>* buffer) throw(){
	int baseLinks = this->refs - this->numFromOwners;
	if(this->ptr->released || this->isLocked() ||	baseLinks > 0){
		return false;
	}

	IObjectStatus* st = buffer->search(this);
	if(st != nullptr){
		return true;
	}
	buffer->addElement(this);

	int maxLoop = this->owners->size();
	for(int i = 0; i != maxLoop; ++i){
		OwnerStatus* ownerStat = this->owners->get(i);
		bool result = ownerStat->ptr->checkCyclic(buffer);

		if(!result){
			return false;
		}
	}

	return true;
}

IObjectStatus::OwnerStatus* IObjectStatus::findOwner(IObjectStatus* owner) throw(){
	int maxLoop = this->owners->size();
	for(int i = 0; i != maxLoop; ++i){
		OwnerStatus* stat = this->owners->get(i);
		if(owner == stat->ptr){
			return stat;
		}
	}
	return nullptr;
}

}

