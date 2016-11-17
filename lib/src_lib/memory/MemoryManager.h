/*
 * Copyright (c) Tomohiro Iizuka. All rights reserved.
 * Licensed under the MIT license.
 */


#include "include/global.h"

#ifndef MEMORYMANAGER_H_
#define MEMORYMANAGER_H_

namespace alinous {
class AlinousMemoryPartitionManager;
class AlinousMemoryManager;
class MemorySegmentArray;
class MemoryReleaser;

/*********************************************************************************
 *
 */
class AllocationResult {
public:
	AllocationResult() throw(): numAlloced(0), ext(false) {
		this->ptrs = new char*[256];
		this->cur = this->ptrs;
	}
	AllocationResult(u_int32_t size) throw() : numAlloced(0), ext(false) {
		this->ptrs = new char*[size];
		this->cur = this->ptrs;
	}
	AllocationResult(u_int32_t size, char** pp) throw() : numAlloced(0) , ext(true){
		this->ptrs = pp;
		this->cur = pp;
	}
	~AllocationResult() throw() {
		if(!ext){
			delete [] this->ptrs;
		}
	}
	void add(char* ptr) throw() {
		*cur++ = ptr;
		this->numAlloced++;
	}
	void reset() throw() {
		this->numAlloced = 0;
		this->cur = this->ptrs;
	}

	u_int64_t numAlloced;
	char** ptrs;
	char** cur;
	bool ext;
};

/*********************************************************************************
 *
 */
class MemorySegment {
public:
	const constexpr static u_int64_t SINGLE_SEG_SIZE{1024*1024*8};
	const constexpr static u_int64_t PTR_OVERHEAD = 8;

	MemorySegment(u_int64_t fragmentSize, char* const head, SegBitSetFactory* bitsetFactory) throw();
	~MemorySegment() throw();

	bool alloc(AllocationResult* const result, const u_int64_t orgnum, MemoryReleaser* postfix) throw();
	void release(const char* ptr) throw();

	bool isEmpty() throw();
	bool showLeaks() throw();

private:
	const u_int64_t fragmentSize;
	const u_int64_t numFragments;
	SegBitSet* usage;
public:
	char* const headPtr;
	u_int64_t lastPos;
};


/*********************************************************************************
 *
 */
class MemorySegmentArray{
public:
	MemorySegmentArray(AlinousMemoryPartitionManager* manager, const u_int32_t fragmentSize, BgBitSetAllocThread* thread) throw();
	~MemorySegmentArray() throw();

	void release(const char* ptr) throw();
	bool alloc(AllocationResult* result, u_int32_t size, u_int64_t num, MemoryReleaser* postfix) throw();
	bool isEmpty() throw();

	u_int64_t getBound(){
		return this->fragmentSize;
	}
private:
	MemorySegment* allocNewSegment() throw();

private:
	AlinousMemoryPartitionManager* const manager;
	const u_int64_t fragmentSize;
	SegRawArray<MemorySegment> array;
	u_int64_t startScan;
	SegBitSetFactory* bitsetFactory;
};


/*********************************************************************************
 *
 */
class AlinousMemoryPartitionManager {
public:
	AlinousMemoryPartitionManager(u_int64_t maxMemory, BgBitSetAllocThread* thread) throw();
	~AlinousMemoryPartitionManager() throw();

	bool release(const char* ptr, u_int32_t size) throw();
	void alloc(AllocationResult* result, u_int32_t size, u_int32_t num, MemoryReleaser* postfix) throw();
	char* allocNewSegment() throw();
	bool isEmpty() throw();

	const u_int64_t maxMemory;
	const u_int64_t numSegments;
	char* const memory;
	char* const last_memory;
	SegBitSet usage;

private:

	MemorySegmentArray* seg4;
	MemorySegmentArray* seg8;
	MemorySegmentArray* seg16;
	MemorySegmentArray* seg32;
	MemorySegmentArray* seg64;
	MemorySegmentArray* seg128;
	MemorySegmentArray* seg256;
	MemorySegmentArray* seg512;
	MemorySegmentArray* seg1024;
	MemorySegmentArray* seg2048;
	MemorySegmentArray* seg4096;
	MemorySegmentArray* seg8192;
	MemorySegmentArray* seg16384;
	MemorySegmentArray* seg32768;
	MemorySegmentArray* seg65536;
	MemorySegmentArray* seg131072;


	void initSegment() throw();
	MemorySegmentArray* const getSegment(const u_int32_t size) throw();
};


/*********************************************************************************
 *
 */
class AlinousMemoryManager {
public:
	constexpr static u_int64_t PARTITION_SIZE = 1024L * 1024L * 128L;

	AlinousMemoryManager() throw();
	void startThread(int partitions) throw();
	~AlinousMemoryManager() throw();

	void release(const char* ptr, u_int32_t size) throw();
	void alloc(AllocationResult* result, u_int32_t size, u_int32_t num, MemoryReleaser* postfix) throw();
	bool isEmpty() throw();
private:
	AlinousMemoryPartitionManager* allocNewPartition() throw();

private:
	BgBitSetAllocThread* thread;
	SegRawArray<AlinousMemoryPartitionManager> partitions;
	pthread_spinlock_t spinlock;
};

}

#endif /* MEMORYMANAGER_H_ */
