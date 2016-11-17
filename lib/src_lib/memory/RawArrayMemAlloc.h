/*
 * Copyright (c) Tomohiro Iizuka. All rights reserved.
 * Licensed under the MIT license.
 */


#ifndef RAWARRAYMEMALLOC_H_
#define RAWARRAYMEMALLOC_H_


//#define __DEBUG_LOG_MEM

#ifdef __DEBUG_LOG_MEM
#include <bfd.h>
#include <execinfo.h>
#include <assert.h>

struct StackFrame{
	const char *file_name;
	const char *function_name;
	unsigned int lineno;
};
class DebugInfo{
public:
	bfd *abfd;
	asymbol **symbols;
	int nsymbols;

	char* buffer;
	int pos;

	FILE* fp;

	static char* prog;;

	DebugInfo();
	void writePtr(void* ptr);
	void writeFrame(StackFrame frame);
	~DebugInfo();
	static DebugInfo* getInstance();
#endif


namespace alinous {

class RawMemAllocElement {
public:
	RawMemAllocElement(u_int32_t blocksize, u_int32_t buff_size, u_int64_t alloc_ext, u_int64_t line_size
		, AlinousMemoryManager* memoryManager, ExtendThread* extThread) throw();
	~RawMemAllocElement() throw();

	int destruct1() throw();
	int destruct2() throw();

	char* alloc() throw(){
		char* pptr = *(this->current);
		this->current++;

		if(__builtin_expect(this->current != this->memEnd && this->current != this->empty, 1)){
			#ifdef __MEM_DEBUG
			MemoryReleaser** rel = (MemoryReleaser**)(pptr + this->blocksize);
			assert(*rel != nullptr);
			#endif

			return pptr;
		}


		if(__builtin_expect(this->current == this->memEnd, 0)){
			this->current = this->mems;
		}

		if(__builtin_expect(this->current != this->empty, 1)){
			#ifdef __MEM_DEBUG
			MemoryReleaser** rel = (MemoryReleaser**)(pptr + this->blocksize);
			assert(*rel != nullptr);
			#endif

			return pptr;
		}

		dec();
		extend();
		return alloc();
	}
	void freeMemory(char* ptr, u_int32_t bound) throw();
	void waitExtendReady() const throw();
	void extend() throw();
	void backGroundMalloc() throw();
	void dec() throw();

	const u_int32_t blocksize;
	u_int32_t buff_size;
	u_int32_t alloc_ext;
	//u_int32_t buff_size_mod;

	char** current;
	volatile char** empty;
	char** mems;
	char** memEnd;

	AlinousMemoryManager* memoryManager;
	ExtendThread* extThread;

	u_int64_t line_size;

	pthread_spinlock_t spinlock;
	AllocationResult* extBuff;

	MemoryReleaser* releaser;
public:
	volatile bool extReady;
	char** allocedMemory;

#ifdef __MEM_DEBUG
	void assertMemory();
#endif
};


class RawArrayMemAlloc {
public:
	RawArrayMemAlloc(AlinousMemoryManager* memoryManager) throw();
	~RawArrayMemAlloc() throw();
	inline void* allocate(const u_int32_t cap) {
		if(__builtin_expect(cap <= 131072, 1)){
			RawMemAllocElement* const ptr = getArrayElement(cap);

			return ptr->alloc();
		}

		return allocateLarge(cap);
	}



#ifdef __DEBUG_LOG_MEM
	void stackTrace(u_int32_t cap, void* ptr);
	StackFrame const resolve(void *address);
#endif

	void* allocateLarge(u_int32_t cap) throw();
	void freeMemory(char* ptr, u_int32_t cap) throw();
	static void testFreeMemory(char* ptr, u_int32_t cap, AlinousMemoryManager* memoryManager) throw();

private:
	AlinousMemoryManager* memoryManager;
	ExtendThread* extThread;

	// 0
	// 1
	RawMemAllocElement* mem4; // 2
	RawMemAllocElement* mem8; // 3
	RawMemAllocElement* mem16; // 4
	RawMemAllocElement* mem32; // 5
	RawMemAllocElement* mem64; // 6
	RawMemAllocElement* mem128; // 7
	RawMemAllocElement* mem256; // 8
	RawMemAllocElement* mem512;  // 9
	RawMemAllocElement* mem1024; // 10
	RawMemAllocElement* mem2048; // 11
	RawMemAllocElement* mem4096; // 12
	RawMemAllocElement* mem8192; // 13
	RawMemAllocElement* mem16384; // 14
	RawMemAllocElement* mem32768; // 15
	RawMemAllocElement* mem65536; // 16
	RawMemAllocElement* mem131072; // 17

	__attribute__((noinline))
	RawMemAllocElement* const getArrayElement(const u_int32_t cap) const throw()
	{
		if(cap <= 512){
			if(cap <= 32){
				if(cap <= 8){
					if(cap <= 4){
						return mem4;
					}
					return mem8;
				}
				else{
					if(cap <= 16){
						return mem16;
					}
					return mem32;
				}
			}
			else {
				if(cap <= 128){
					if(cap <= 64){
						return mem64;
					}
					return mem128;
				}
				else{
					if(cap <= 256){
						return mem256;
					}
					return mem512;
				}
			}
		}
		else{
			if(cap <= 8192){
				if(cap <= 2048){
					if(cap <= 1024){
						return mem1024;
					}
					return mem2048;
				}
				else{
					if(cap <= 4096){
						return mem4096;
					}
					return mem8192;
				}
			}else{
				if(cap <= 32768){
					if(cap <= 16384){
						return mem16384;
					}
					return mem32768;
				}
				else{
					if(cap <= 65536){
						return mem65536;
					}
					return mem131072;
				}
			}
		}


		return nullptr;

	}
public:

	inline static u_int64_t getBoudary(u_int64_t cap) throw(){
		if(cap <= 512){
			if(cap <= 32){
				if(cap <= 8){
					if(cap <= 4){
						return 4;
					}
					return 8;
				}
				else{
					if(cap <= 16){
						return 16;
					}
					return 32;
				}
			}
			else {
				if(cap <= 128){
					if(cap <= 64){
						return 64;
					}
					return 128;
				}
				else{
					if(cap <= 256){
						return 256;
					}
					return 512;
				}
			}
		}
		else{
			if(cap <= 8192){
				if(cap <= 2048){
					if(cap <= 1024){
						return 1024;
					}
					return 2048;
				}
				else{
					if(cap <= 4096){
						return 4096;
					}
					return 8192;
				}
			}else{
				if(cap <= 32768){
					if(cap <= 16384){
						return 16384;
					}
					return 32768;
				}
				else{
					if(cap <= 65536){
						return 65536;
					}
					return 131072;
				}
			}
		}

		return cap;
	}
};


class MemoryAllocDestructor {
public:
	MemoryAllocDestructor() throw() {
	}
	~MemoryAllocDestructor() throw();
};

}


#endif /* RAWARRAYMEMALLOC_H_ */
