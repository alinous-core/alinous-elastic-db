/*
 * Copyright (c) Tomohiro Iizuka. All rights reserved.
 * Licensed under the MIT license.
 */


#include "includes.h"

namespace alinous {

constexpr const u_int32_t SegBitSet::OFFSET;
constexpr const u_int32_t SegBitSet::ELM_SIZE;
constexpr const u_int32_t SegBitSet::RIGHT_BITS;
constexpr const u_int64_t SegBitSet::TWO_N_ARRAY[64];

SegBitSet::SegBitsetArray::SegBitsetArray(const int numBits) throw() : length(numBits) {
	buff = new u_int64_t[numBits]{};
}
SegBitSet::SegBitsetArray::~SegBitsetArray() throw() {
	delete [] buff;
}

void SegBitSet::SegBitsetArray::set(const u_int64_t value, const int index) throw() {
	*(this->buff + index) = value;
}

void SegBitSet::SegBitsetArray::growLength(const u_int32_t len) throw() {
	u_int64_t* tmp = new u_int64_t[len]{};

	FastCopy::copy(tmp, buff, length * sizeof(u_int64_t));
	this->length = len;
	delete [] buff;
	buff = tmp;
}



SegBitSet::SegBitSet(u_int64_t nbits) throw()
		: bits( (nbits >> OFFSET) + ((nbits & RIGHT_BITS) > 0) ? ((nbits >> (OFFSET - 1)) + ((nbits & RIGHT_BITS) > 0)) : 0 )
		//: bits( (nbits >> OFFSET) + ((nbits & RIGHT_BITS) > 0) ? 1 : 0 )
{

	_needClear = false;
	actualArrayLength = 0;
	isLengthActual = true;
}

bool SegBitSet::get(const u_int64_t pos) throw()
{
	const u_int32_t arrayPos = pos >> OFFSET;
	if(arrayPos < actualArrayLength)
	{
		return (bits[arrayPos] & TWO_N_ARRAY[pos & RIGHT_BITS]) != 0x0;
	}
	return false;
}


void SegBitSet::set(const u_int64_t pos) throw()
{
#ifdef __DEBUG__
	assert(pos >= (u_int32_t)0);
#endif
	const u_int64_t len = (pos >> OFFSET) + (u_int64_t)1;
	if(len > bits.length)
	{
		bits.growLength(len);
	}
	bits.set(bits[len - 1] | (TWO_N_ARRAY[pos & RIGHT_BITS]), len - 1);
	if(len > actualArrayLength)
	{
		actualArrayLength = len;
		isLengthActual = true;
	}
	needClear();
}

void SegBitSet::set(const u_int64_t pos1, const u_int64_t pos2)  throw() {
    if (pos1 < 0 || pos2 < 0 || pos2 < pos1) {
        return;
    }

    if (pos1 == pos2) {
        return;
    }
    const u_int64_t len2 = ((pos2 - 1) >> OFFSET) + 1;
    if (len2 > bits.length) {
        this->bits.growLength(len2);
    }

    const int idx1 = pos1 >> OFFSET;
    const int idx2 = (pos2 - 1) >> OFFSET;
    const u_int64_t factor1 = ((u_int64_t)~0L) << (pos1 & RIGHT_BITS);
    const u_int64_t factor2 = ((u_int64_t)~0L) >> (ELM_SIZE - (pos2 & RIGHT_BITS));

    if (idx1 == idx2) {
        //bits[idx1] |= (factor1 & factor2);
    	bits.set(bits[idx1] | (factor1 & factor2), idx1);
    } else {
        //bits[idx1] |= factor1;
    	bits.set(bits[idx1] | factor1, idx1);
        //bits[idx2] |= factor2;
    	bits.set(bits[idx2] | factor2, idx2);
        for (int i = idx1 + 1; i < idx2; i++) {
            //bits[i] |= (~0L);
        	bits.set(bits[i] | (u_int64_t)(~0L), i);
        }
    }
    if (idx2 + 1 > (int)actualArrayLength) {
        actualArrayLength = idx2 + 1;
        isLengthActual = true;
    }
    needClear();
}

void SegBitSet::clear(const u_int32_t pos) throw()
{
#ifdef __DEBUG__
	assert(pos >= (u_int32_t)0);
#endif
	if(!_needClear)
	{
		return ;
	}
	u_int32_t arrayPos = pos >> OFFSET;
	if(arrayPos < actualArrayLength)
	{
		bits.set(bits[arrayPos] & (~(TWO_N_ARRAY[pos & RIGHT_BITS])),arrayPos);
		if(bits[actualArrayLength - 1] == (u_int64_t)0)
		{
			isLengthActual = false;
		}
	}
}


int SegBitSet::nextSetBit(const u_int64_t pos) throw()
{
	if(pos >= actualArrayLength << OFFSET)
	{
		return -1;
	}
	u_int64_t idx = pos >> OFFSET;
	if(bits[idx] != (u_int64_t)0L)
	{
		for(u_int64_t j = pos & RIGHT_BITS; j < ELM_SIZE; j ++ )
		{
			if(((bits[idx] & (TWO_N_ARRAY[j])) != (u_int64_t)0))
			{
				return (idx << OFFSET) + j;
			}
		}
	}
	idx ++ ;
	while(idx < actualArrayLength && bits[idx] == (u_int64_t)0L)
	{
		idx ++ ;
	}
	if(idx == actualArrayLength)
	{
		return -1;
	}
	for(u_int64_t j = 0; j < ELM_SIZE; j ++ )
	{
		if(((bits[idx] & (TWO_N_ARRAY[j])) != 0))
		{
			return (idx << OFFSET) + j;
		}
	}
	return -1;
}

int SegBitSet::nextClearBit(const int pos) throw()
{
	if(pos < 0)
	{
		return -1;
	}
	const int length = actualArrayLength;
	const int bssize = length << OFFSET;
	if(pos >= bssize)
	{
		return pos;
	}
	int idx = pos >> OFFSET;
	if(bits[idx] != (u_int64_t)(~0L))
	{
		for(u_int64_t j = pos % ELM_SIZE; j < ELM_SIZE; j ++ )
		{
			if(((bits[idx] & (TWO_N_ARRAY[j])) == (u_int64_t)0))
			{
				return idx * ELM_SIZE + j;
			}
		}
	}
	idx ++ ;
	while(idx < length && bits[idx] == (u_int64_t)(~0L))
	{
		idx ++ ;
	}
	if(idx == length)
	{
		return bssize;
	}
	for(unsigned int j = 0; j < ELM_SIZE; j ++ )
	{
		if(((bits[idx] & (TWO_N_ARRAY[j])) == (u_int64_t)0))
		{
			return (idx << OFFSET) + j;
		}
	}
	return bssize;
}


void SegBitSet::clear() throw()
{
	if(_needClear)
	{

		for(u_int32_t i = 0; i < (u_int32_t)bits.length; i ++ )
		{
			bits.set(0L, i);
		}
		actualArrayLength = 0;
		isLengthActual = true;
		_needClear = false;
	}
}


/////////////////////////////////////////////////////////////////////////////////////
SegBitSetFactory::SegBitSetFactory(u_int64_t nbits, BgBitSetAllocThread* thread)  throw() : nbits(nbits)
{
	this->thread = thread;
	this->requesting = false;
	pthread_spin_init(&spinlock, PTHREAD_PROCESS_PRIVATE);

	doMalloc();
}
SegBitSetFactory::~SegBitSetFactory() throw() {
	wait4requestDone();

	int maxLoop = this->array.size();
	for(int i = 0; i != maxLoop; ++i){
		SegBitSet* ptr = this->array.get(i);
		delete ptr;
	}

	pthread_spin_destroy(&spinlock);
}

SegBitSet* SegBitSetFactory::newBitSet() throw() {
	wait4requestDone();

	pthread_spin_lock(&spinlock);

	SegBitSet* ptr = this->array.pop();

	pthread_spin_unlock(&spinlock);

	if(this->array.size() < 8 && !this->requesting){
		backGroundAllocate();
	}

	return ptr;
}

void SegBitSetFactory::wait4requestDone() throw()
{
	while(this->requesting){
		printf("waiting... %d \n", (int)this->nbits);
		::pthread_yield();
	}
}

void SegBitSetFactory::backGroundAllocate() throw() {
	this->requesting = true;

	//clock_t start = clock();

	this->thread->request(this);

	//clock_t end = clock();

	//int timeMicroSec = (end - start) * 1000 * 1000 / CLOCKS_PER_SEC;
	//printf("requesting alloc... thread : %d microsec\n", timeMicroSec);

}


void SegBitSetFactory::doMalloc() throw() {
	pthread_spin_lock(&spinlock);

	int maxLoop = 16;
	for(int i = this->array.size(); i < maxLoop; ++i){
		SegBitSet* bit = new SegBitSet(this->nbits);
		this->array.addElement(bit);
	}

	this->requesting = false;

	pthread_spin_unlock(&spinlock);
}


BgBitSetAllocThread::BgBitSetAllocThread() throw() : threadId(0), run(false), ready(false) {
	::pthread_mutex_init(&mutex, NULL);
	::pthread_cond_init(&cond, NULL);

	::pthread_create(&threadId, NULL, BgBitSetAllocThread::extendOperationLoop, this);

	::pthread_mutex_lock(&mutex);
	this->ready = true;

	if(this->run){
		::pthread_cond_signal(&cond);
	}else{
		::pthread_cond_wait(&cond, &mutex);
	}
	::pthread_mutex_unlock(&mutex);
}
BgBitSetAllocThread::~BgBitSetAllocThread() throw() {
	::pthread_mutex_lock(&mutex);
	this->run = false;
	::pthread_cond_signal(&cond);
	::pthread_mutex_unlock(&mutex);

	::pthread_join(this->threadId, nullptr);

	::pthread_cond_destroy(&cond);
	::pthread_mutex_destroy(&mutex);
}

void BgBitSetAllocThread::request(SegBitSetFactory* element) throw() {
	::pthread_mutex_lock(&(this->mutex));
	this->tasks.add(element);
	::pthread_cond_signal(&(this->cond));
	::pthread_mutex_unlock(&(this->mutex));
}


void* BgBitSetAllocThread::extendOperationLoop(void* param) throw() {
	BgBitSetAllocThread* _this = (BgBitSetAllocThread*)param;

	::pthread_mutex_lock(&_this->mutex);
	_this->run = true;

	if(_this->ready){
		::pthread_cond_signal(&_this->cond);
	}
	else{
		::pthread_cond_wait(&_this->cond, &_this->mutex);
	}

	/////////////////////////////////////////////////////////////
	while(_this->run || !_this->tasks.isEmpty()){
		if(_this->tasks.isEmpty()){
			::pthread_cond_wait(&_this->cond, &_this->mutex);
			continue;
		}

		SegBitSetFactory* element = _this->tasks.remove(0);

		::pthread_mutex_unlock(&_this->mutex);

		// do memory allocation
		_this->doJob(element);

		::pthread_mutex_lock(&_this->mutex);
	}

	::pthread_mutex_unlock(&_this->mutex);

	return nullptr;
}

void BgBitSetAllocThread::doJob(SegBitSetFactory* element) throw() {
	element->doMalloc();
}


}
