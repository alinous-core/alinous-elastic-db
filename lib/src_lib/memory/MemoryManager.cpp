/*
 * Copyright (c) Tomohiro Iizuka. All rights reserved.
 * Licensed under the MIT license.
 */


#include "includes.h"

#ifndef MEMORYMANAGER_CPP_
#define MEMORYMANAGER_CPP_


namespace alinous {



MemorySegment* MemorySegmentArray::allocNewSegment() throw() {
	char* head = this->manager->allocNewSegment();
	if(head == nullptr){
		return nullptr;
	}

	MemorySegment* newSeg = new MemorySegment(this->fragmentSize, head, this->bitsetFactory);
	this->array.addElement(newSeg);

	return newSeg;
}

/******************************************************************************************/
MemorySegment::MemorySegment(u_int64_t fragmentSize, char* const head, SegBitSetFactory* bitsetFactory) throw()
	: fragmentSize(fragmentSize + PTR_OVERHEAD), numFragments(SINGLE_SEG_SIZE / (fragmentSize+PTR_OVERHEAD)), headPtr(head)
{
	this->usage = bitsetFactory->newBitSet();
	this->usage->set(this->numFragments);
	this->lastPos = 0;
}

MemorySegment::~MemorySegment() throw() {
	delete this->usage;
}

bool MemorySegment::alloc(AllocationResult* const result, const u_int64_t orgnum, MemoryReleaser* postfix) throw() {
	#ifdef __MEM_DEBUG
	assert(postfix != nullptr);
	#endif


	if(this->lastPos >= numFragments){
		return true;
	}

	const u_int64_t fragmentSize = this->fragmentSize;
	const u_int64_t numFragments = this->numFragments;

	u_int64_t num = orgnum;
	char* const headPtr = this->headPtr;
	u_int64_t pos;
	u_int64_t length;
	u_int64_t endpos;
	bool isFull = false;

	const u_int64_t offset = fragmentSize - PTR_OVERHEAD;
	do{
		pos = this->usage->nextClearBit(lastPos);

		if(pos > numFragments){
			this->lastPos = numFragments;
			return true;
		}

		length = this->usage->nextSetBit(pos) - pos;
		length = length > num ? num : length;

		lastPos = pos + length;
		isFull = this->lastPos >= numFragments;

		endpos = lastPos;
		this->usage->set(pos, endpos);
		num -= length;

#ifdef __MEM_DEBUG
		assert(this->lastPos <= numFragments);

		int i = 0;
#endif
		char* endPtr = endpos * fragmentSize + headPtr;
		for(char* ptr = (pos*fragmentSize)+headPtr; ptr != endPtr; ptr+=fragmentSize){
			result->add(ptr);
			MemoryReleaser** pp = (MemoryReleaser**)(ptr + offset);
			*pp = postfix;

#ifdef __MEM_DEBUG
			pp = (MemoryReleaser**)(result->ptrs[i] + offset);
			i++;
			(*pp)->assertBound(postfix->element);
#endif
		}

	}
	while(num > 0 && !isFull);

	return isFull;
}

void MemorySegment::release(const char* ptr) throw() {
	const char* head = this->headPtr;
	const u_int64_t offset = ptr - head;

	const u_int64_t pos = offset / this->fragmentSize;
	this->usage->clear(pos);

#ifdef __MEM_DEBUG
	assert(pos < this->numFragments);
#endif

	if(pos == this->numFragments){
		printf("error");
	}


	this->lastPos = pos < this->lastPos ? pos : this->lastPos;
}

bool MemorySegment::isEmpty() throw() {
	u_int64_t pos = this->usage->nextSetBit(0);
	return pos == this->numFragments;
}

bool MemorySegment::showLeaks() throw() {
	u_int64_t pos = this->usage->nextSetBit(0);

	while(pos != this->numFragments){
		void* ptr = this->headPtr + pos * this->fragmentSize;
		wprintf(L"%llx\n", ptr);

		++pos;
		pos = this->usage->nextSetBit(pos);
	}
	return true;
}


/*********************************************************************************
 *
 */
MemorySegmentArray::MemorySegmentArray(AlinousMemoryPartitionManager* manager, const u_int32_t fragmentSize, BgBitSetAllocThread* thread) throw()
	: manager(manager), fragmentSize(fragmentSize), startScan(0)
{
	u_int64_t numBits = (MemorySegment::SINGLE_SEG_SIZE / (fragmentSize + MemorySegment::PTR_OVERHEAD)) + 1;
	this->bitsetFactory = new SegBitSetFactory(numBits, thread);
}
MemorySegmentArray::~MemorySegmentArray() throw() {
	int maxLoop = this->array.size();
	for(int i = 0; i != maxLoop; ++i){
		MemorySegment* seg = this->array.get(i);
		delete seg;
	}

	delete this->bitsetFactory;
}

void MemorySegmentArray::release(const char* ptr) throw() {
	MemorySegment* seg = nullptr;
	u_int64_t pos = 0;
	char* endPtr;
	char* startPtr;
	int maxLoop = this->array.size();
	for(int i = 0; i != maxLoop; ++i){
		seg = this->array.get(i);
		startPtr = seg->headPtr;
		endPtr = startPtr + MemorySegment::SINGLE_SEG_SIZE;
		if(seg->headPtr <= ptr && ptr < endPtr){
			pos = i;
			break;
		}
		seg = nullptr;
	}

	#ifdef __MEM_DEBUG
	/*if(seg == nullptr){
		for(int i = 0; i != maxLoop; ++i){
			seg = this->array.get(i);
			startPtr = seg->headPtr;
			endPtr = startPtr + MemorySegment::SINGLE_SEG_SIZE;

			if(ptr >= startPtr){
				printf("startok\n");
			}
			if(ptr < endPtr){
				printf("endok\n");
			}

			if(seg->headPtr <= ptr && ptr < endPtr){
				pos = i;
				break;
			}
		}
		seg = nullptr;
	}*/
	assert(seg != nullptr);
	#endif

	seg->release(ptr);
	this->startScan = pos < this->startScan ? pos : this->startScan;
}

bool MemorySegmentArray::alloc(AllocationResult* result, u_int32_t size, u_int64_t num, MemoryReleaser* postfix) throw() {
	const u_int64_t maxLoop = this->array.size();
	for(u_int64_t i = this->startScan; i != maxLoop; ++i){
		MemorySegment* seg = this->array.get(i);
		bool full = seg->alloc(result, num - result->numAlloced, postfix);

		if(full && i > this->startScan){
			this->startScan = i;
		}

		if(result->numAlloced == num){
			return true;
		}
	}

	// new segment
	MemorySegment* newSeg = allocNewSegment();
	while(newSeg != nullptr){
		/*bool full = */newSeg->alloc(result, num - result->numAlloced, postfix);

		if(result->numAlloced == num){
			return true;
		}

		newSeg = allocNewSegment();
	}

	return result->numAlloced == num;
}

bool MemorySegmentArray::isEmpty() throw() {
	int maxLoop = array.size();
	for(int i = 0; i != maxLoop; ++i){
		MemorySegment* seg = array.get(i);
		if(!seg->isEmpty()){
			seg->showLeaks();
			return false;
		}
	}

	return true;
}

/*********************************************************************************
 *
 */
AlinousMemoryPartitionManager::AlinousMemoryPartitionManager(u_int64_t maxMemory, BgBitSetAllocThread* thread) throw() : maxMemory(maxMemory)
		, numSegments(this->maxMemory / MemorySegment::SINGLE_SEG_SIZE)
		, memory( (char*)::malloc(this->maxMemory) )
		, last_memory(this->memory + maxMemory)
		, usage(64)
{
	::memset(this->memory, 0, maxMemory * sizeof(char));


	this->seg4 = new MemorySegmentArray(this, 4, thread);
	this->seg8 = new MemorySegmentArray(this, 8, thread);
	this->seg16 = new MemorySegmentArray(this, 16, thread);
	this->seg32 = new MemorySegmentArray(this, 32, thread);
	this->seg64 = new MemorySegmentArray(this, 64, thread);
	this->seg128 = new MemorySegmentArray(this, 128, thread);
	this->seg256 = new MemorySegmentArray(this, 256, thread);
	this->seg512 = new MemorySegmentArray(this, 512, thread);
	this->seg1024 = new MemorySegmentArray(this, 1024, thread);
	this->seg2048 = new MemorySegmentArray(this, 2048, thread);
	this->seg4096 = new MemorySegmentArray(this, 4096, thread);
	this->seg8192 = new MemorySegmentArray(this, 8192, thread);
	this->seg16384 = new MemorySegmentArray(this, 16384, thread);
	this->seg32768 = new MemorySegmentArray(this, 32768, thread);
	this->seg65536 = new MemorySegmentArray(this, 65536, thread);
	this->seg131072 = new MemorySegmentArray(this, 131072, thread);

	initSegment();
}

AlinousMemoryPartitionManager::~AlinousMemoryPartitionManager() throw() {
	delete seg4;
	delete seg8;
	delete seg16;
	delete seg32;
	delete seg64;
	delete seg128;
	delete seg256;
	delete seg512;
	delete seg1024;
	delete seg2048;
	delete seg4096;
	delete seg8192;
	delete seg16384;
	delete seg32768;
	delete seg65536;
	delete seg131072;

	::free(const_cast<char*>(this->memory));
}

bool AlinousMemoryPartitionManager::release(const char* ptr, u_int32_t size) throw() {
	if(ptr < this->memory || ptr >= this->last_memory){
		return false;
	}

	MemorySegmentArray* segArray = getSegment(size);
	segArray->release(ptr);
	return true;
}


void AlinousMemoryPartitionManager::alloc(AllocationResult* result, u_int32_t size, u_int32_t num, MemoryReleaser* postfix) throw() {
	MemorySegmentArray* const segArray = getSegment(size);

	#ifdef __MEM_DEBUG
	assert(segArray != nullptr);

	u_int64_t bound = segArray->getBound();
	u_int64_t block = postfix->element->blocksize;
	assert(bound == block);
	#endif

	segArray->alloc(result, size, num, postfix);

	return;
}

char* AlinousMemoryPartitionManager::allocNewSegment() throw() {
	u_int64_t pos = usage.nextClearBit(0);
	if(pos == this->numSegments){
		return nullptr;
	}

	char* mallocedPtr = this->memory + (pos * MemorySegment::SINGLE_SEG_SIZE);
	usage.set(pos);


	#ifdef __MEM_DEBUG
	assert(this->memory <= mallocedPtr && mallocedPtr < this->last_memory);
	#endif

	return mallocedPtr;
}

bool AlinousMemoryPartitionManager::isEmpty() throw() {
	return seg4->isEmpty() &&
			seg8->isEmpty() &&
			seg16->isEmpty() &&
			seg32->isEmpty() &&
			seg64->isEmpty() &&
			seg128->isEmpty() &&
			seg256->isEmpty() &&
			seg512->isEmpty() &&
			seg1024->isEmpty() &&
			seg2048->isEmpty() &&
			seg4096->isEmpty() &&
			seg8192->isEmpty() &&
			seg16384->isEmpty() &&
			seg32768->isEmpty() &&
			seg65536->isEmpty() &&
			seg131072->isEmpty();
}

void AlinousMemoryPartitionManager::initSegment() throw() {

}

MemorySegmentArray* const AlinousMemoryPartitionManager::getSegment(const u_int32_t size) throw() {
	if(size <= 512){
		if(size <= 32){
			if(size <= 8){
				if(size <= 4){
					return seg4;
				}
				return seg8;
			}
			else{
				if(size <= 16){
					return seg16;
				}
				return seg32;
			}
		}
		else {
			if(size <= 128){
				if(size <= 64){
					return seg64;
				}
				return seg128;
			}
			else{
				if(size <= 256){
					return seg256;
				}
				return seg512;
			}
		}
	}
	else{
		if(size <= 8192){
			if(size <= 2048){
				if(size <= 1024){
					return seg1024;
				}
				return seg2048;
			}
			else{
				if(size <= 4096){
					return seg4096;
				}
				return seg8192;
			}
		}else{
			if(size <= 32768){
				if(size <= 16384){
					return seg16384;
				}
				return seg32768;
			}
			else{
				if(size <= 65536){
					return seg65536;
				}
				return seg131072;
			}
		}
	}
	return nullptr;
}

/*********************************************************************************
 *
 */
AlinousMemoryManager::AlinousMemoryManager() throw() {
	pthread_spin_init(&spinlock, PTHREAD_PROCESS_PRIVATE);

	this->thread = nullptr;
}

void AlinousMemoryManager::startThread(int partitions) throw() {
	pthread_spin_lock(&spinlock);

	if(this->thread == nullptr){
		this->thread = new BgBitSetAllocThread();

		for(int i = 0; i != partitions; ++i){
			allocNewPartition();
		}
	}

	pthread_spin_unlock(&spinlock);
}

AlinousMemoryManager::~AlinousMemoryManager() throw() {
	int maxLoop = this->partitions.size();
	for(int i = 0; i != maxLoop; ++i){
		AlinousMemoryPartitionManager* partition = this->partitions.get(i);
		delete partition;
	}

	delete this->thread;

	pthread_spin_destroy(&spinlock);
}

void AlinousMemoryManager::release(const char* ptr, u_int32_t size) throw() {
	pthread_spin_lock(&spinlock);

	const int maxLoop = this->partitions.size();
	bool result;
	for(int i = 0; i != maxLoop; ++i){
		AlinousMemoryPartitionManager* partition = this->partitions.get(i);

		result = partition->release(ptr, size);
		if(result){
			pthread_spin_unlock(&spinlock);
			return;
		}
	}

	pthread_spin_unlock(&spinlock);
}
void AlinousMemoryManager::alloc(AllocationResult* result, u_int32_t size, u_int32_t num, MemoryReleaser* postfix) throw() {
	pthread_spin_lock(&spinlock);

	result->reset();

	const int maxLoop = this->partitions.size();
	for(int i = 0; i != maxLoop; ++i){
		AlinousMemoryPartitionManager* partition = this->partitions.get(i);
		partition->alloc(result, size, num, postfix);
		if(result->numAlloced == num){
			pthread_spin_unlock(&spinlock);
			return;
		}
	}

	AlinousMemoryPartitionManager* partition = allocNewPartition();
	while(partition != nullptr){
		partition->alloc(result, size, num, postfix);
		if(result->numAlloced == num){
			pthread_spin_unlock(&spinlock);
			return;
		}

		partition = allocNewPartition();
	}

	pthread_spin_unlock(&spinlock);
}

bool AlinousMemoryManager::isEmpty() throw() {
	int maxLoop = partitions.size();
	for(int i = 0; i != maxLoop; ++i){
		AlinousMemoryPartitionManager* partition = partitions.get(i);
		if(i == 20){
			partition->isEmpty();
		}

		if(!partition->isEmpty()){
			return false;
		}
	}
	return true;
}

AlinousMemoryPartitionManager* AlinousMemoryManager::allocNewPartition() throw() {
	AlinousMemoryPartitionManager* ppartition = new AlinousMemoryPartitionManager(PARTITION_SIZE, thread);
	this->partitions.addElement(ppartition);
	return ppartition;
}


}


#endif /* MEMORYMANAGER_CPP_ */
