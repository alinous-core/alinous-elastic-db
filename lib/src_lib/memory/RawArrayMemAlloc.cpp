/*
 * Copyright (c) Tomohiro Iizuka. All rights reserved.
 * Licensed under the MIT license.
 */


#include "include/global.h"

#ifdef __DEBUG_LOG_MEM

DebugInfo::DebugInfo(){
	buffer = (char*)malloc(1024 * 1024 * 10);
	pos = 0;

	fp = fopen("memorylog.txt", "w+");

	abfd = bfd_openr(prog == nullptr ? "/home/iizuka/eclipse_cc/workspace/Alinous-NativeDebug/Debug/Alinous-NativeDebug" : prog, NULL);
	assert(abfd != NULL);
	bfd_check_format(abfd, bfd_object);

	int size = bfd_get_symtab_upper_bound(abfd);
	assert(size > 0);
	symbols = (asymbol**)malloc(size);
	assert(symbols != NULL);
	    nsymbols = bfd_canonicalize_symtab(abfd, symbols);
}

void DebugInfo::writePtr(void* ptr){
	// L"%llx %S\n"
	pos += sprintf(buffer + pos, "%llx\n\n", (long long)ptr);
	if(pos > 1024 * 1024 * 10 - 1024){
		fwrite(buffer, sizeof(char) * pos, 1, fp);
		pos = 0;
	}
}

void DebugInfo::writeFrame(StackFrame frame){
	pos += sprintf(buffer + pos, "\t[%s : %d] %s \n", frame.file_name, frame.lineno, frame.function_name);
	if(pos > 1024 * 1024 * 10 - 1024){
		fwrite(buffer, sizeof(char) * pos, 1, fp);
		pos = 0;
	}
}

DebugInfo::~DebugInfo(){
	bfd_close(abfd);
	free(symbols);

	fclose(fp);
	free(buffer);
}

DebugInfo* DebugInfo::getInstance(){
	static DebugInfo instance;
	return &instance;
}

#endif

namespace alinous {

RawMemAllocElement::RawMemAllocElement(u_int32_t blocksize, u_int32_t buff_size, u_int64_t alloc_ext, u_int64_t line_size
	, AlinousMemoryManager* memoryManager, ExtendThread* extThread) throw()
		: blocksize(blocksize),buff_size(buff_size),alloc_ext(alloc_ext)
		,current(0), empty(0), memoryManager(memoryManager), extThread(extThread), line_size(line_size)
		, extReady(false),allocedMemory(nullptr)
{
	pthread_spin_init(&spinlock, PTHREAD_PROCESS_PRIVATE);

	this->releaser = MemoryReleaserManager::getInstance()->newReleaser(this, memoryManager);

	void* ptr = ::malloc(line_size * sizeof(RawMemAllocElement*));
	this->mems = (char**)ptr;
	this->memEnd = this->mems + this->buff_size;

	this->current = this->mems;
	this->empty = const_cast<volatile char**>(this->mems);

	int maxLoop = buff_size;
	AllocationResult result(maxLoop);
	this->memoryManager->alloc(&result, this->blocksize, maxLoop, this->releaser);

	for(int i = 0; i != maxLoop; ++i){
		this->mems[i] = result.ptrs[i]; //newBlock();
	}

	ptr = ::malloc(alloc_ext * sizeof(void*));
	this->allocedMemory = (char**)ptr;

	this->extBuff = new AllocationResult(alloc_ext, this->allocedMemory);
	this->memoryManager->alloc(this->extBuff, this->blocksize, alloc_ext, this->releaser);

#ifdef __MEM_DEBUG
	assertMemory();
#endif

	this->extReady = true;
}

RawMemAllocElement::~RawMemAllocElement() throw() {
	waitExtendReady();

	pthread_spin_lock(&spinlock);

	int remain;
	if(empty <= current){
		remain = destruct1();
	}
	else{
		remain = destruct2();
	}

	#ifdef __MEM_DEBUG
	assertMemory();
	#endif
	
	::free((void*)this->mems);

	int maxLoop = this->alloc_ext;
	for(int i = 0; i != maxLoop; ++i){
		char *ptr =this->allocedMemory[i];
		this->memoryManager->release(ptr, this->blocksize);
	}
	::free((void*)this->allocedMemory);

	pthread_spin_unlock(&spinlock);

	pthread_spin_destroy(&spinlock);

	delete this->extBuff;

	this->releaser->threadEnd(remain);
}

int RawMemAllocElement::destruct1() throw() {
	char** ptr;
	char** end = const_cast<char**>(this->empty);
	int remain = this->buff_size;

	for(ptr = this->mems; ptr != end; ptr++){
		this->memoryManager->release(*ptr, this->blocksize);
		remain--;
	}

	end = this->memEnd;
	for(ptr = this->current; ptr != end; ptr++){
		this->memoryManager->release(*ptr, this->blocksize);
		remain--;
	}

	return remain;
}
int RawMemAllocElement::destruct2() throw() {
	char** ptr;
	char** end = const_cast<char**>(this->empty);
	int remain = this->buff_size;

	for(ptr = this->current; ptr != end; ptr++){
		this->memoryManager->release(*ptr, this->blocksize);
		remain--;
	}

	return remain;
}



void RawMemAllocElement::freeMemory(char* ptr, u_int32_t bound) throw(){
	pthread_spin_lock(&spinlock);

	#ifdef __MEM_DEBUG
	MemoryReleaser** rel = (MemoryReleaser**)(ptr + bound);
	assert(*rel != nullptr);
	#endif

	*(this->empty) = ptr;
	char** next = const_cast<char**>(this->empty) + 1;
	this->empty = const_cast<volatile char**>(next != this->memEnd ? next : this->mems);

	pthread_spin_unlock(&spinlock);
}

void RawMemAllocElement::waitExtendReady() const throw() {
	//timespec tp, tpend;
	//clock_gettime(CLOCK_MONOTONIC, &tp);

//	int i = 0;
	while(!this->extReady){
		//printf("sleep...[%d]\n", i++);
		//::pthread_yield();


	}

	//clock_gettime(CLOCK_MONOTONIC, &tpend);
	//long long loss = (tpend.tv_sec * 1000 * 1000 * 1000 + tpend.tv_nsec)
	//			- (tp.tv_sec * 1000 * 1000 * 1000 + tp.tv_nsec);
	//printf("loss time...[%lld]\n", loss);
}

void RawMemAllocElement::extend() throw() {
	waitExtendReady();

	//timespec tp, tpend;
	//clock_gettime(CLOCK_MONOTONIC, &tp);

	#ifdef __MEM_DEBUG
	assertMemory();
	#endif

	char** lastAllocedMemory = this->allocedMemory;

	pthread_spin_lock(&spinlock);

	u_int32_t nextmax = this->buff_size + alloc_ext;
	bool extend_line = this->line_size < nextmax;

	if(extend_line){
		//this->line_size = this->line_size * 2;
		u_int64_t nextSize = this->line_size * 2;
		char** pptr = (char**)malloc(nextSize * sizeof(char*));

		FastCopy::copy(pptr, this->mems, this->line_size * sizeof(char*));
		memset(pptr + this->line_size, 0, this->line_size * sizeof(char*));

		u_int64_t curOffset = this->current - this->mems;
		u_int64_t empOffset = const_cast<char**>(this->empty) - this->mems;

		this->current = pptr + curOffset;
		this->empty = const_cast<volatile char**>(pptr + empOffset);

		::free(this->mems);
		this->mems = pptr;
		this->memEnd = this->mems + this->buff_size;
		this->line_size = nextSize;
	}

	u_int32_t extsize = this->alloc_ext;
	char** nextEnd = this->memEnd + extsize;

	if(empty <= current){
		FastCopy::copy(this->memEnd, lastAllocedMemory, extsize * sizeof(char*));
	}
	else { // empty > current
		// move used
		u_int64_t borrowedOffset = this->memEnd - const_cast<char**>(this->empty);
		memmove(nextEnd - borrowedOffset, this->empty, borrowedOffset + sizeof(char*));

		// extend
		FastCopy::copy(this->empty, lastAllocedMemory, extsize * sizeof(char*));

		this->empty = const_cast<volatile char**>(nextEnd - borrowedOffset);
	}

	this->extThread->request(this);

	this->memEnd = nextEnd;
	this->buff_size += extsize;

	pthread_spin_unlock(&spinlock);

}

void RawMemAllocElement::backGroundMalloc() throw() {
	// bgalloc
	int maxLoop = this->alloc_ext;

	this->memoryManager->alloc(this->extBuff, this->blocksize, maxLoop, this->releaser);
	this->extReady = true;

	#ifdef __MEM_DEBUG
	assertMemory();
	#endif
}



void RawMemAllocElement::dec() throw() {
	this->current = (this->current != this->mems) ? this->current - 1 : this->memEnd - 1;
}


RawArrayMemAlloc::RawArrayMemAlloc(AlinousMemoryManager* memoryManager) throw() :
	memoryManager(memoryManager), extThread(new ExtendThread())
/*
	mem4(new RawMemAllocElement(4, 1024, 1024*8, 1024*32, memoryManager, extThread)),
	mem8(new RawMemAllocElement(8, 1024, 1024*8, 1024*32, memoryManager, extThread)),
	mem16(new RawMemAllocElement(16, 1024, 1024*8, 1024*32, memoryManager, extThread)),
	mem32(new RawMemAllocElement(32, 1024, 1024*8, 1024*32, memoryManager, extThread)),
	mem64(new RawMemAllocElement(64, 1024, 1024*8, 1024*32, memoryManager, extThread)),
	mem128(new RawMemAllocElement(128, 1024, 1024*8, 1024*32, memoryManager, extThread)),
	mem256(new RawMemAllocElement(256, 1024, 1024*8, 1024*32, memoryManager, extThread)),
	mem512(new RawMemAllocElement(512, 1024, 1024*8, 1024*32, memoryManager, extThread)),
	mem1024(new RawMemAllocElement(1024, 256, 256, 1024*8, memoryManager, extThread)),
	mem2048(new RawMemAllocElement(2048, 256, 256, 1024*8, memoryManager, extThread)),
	mem4096(new RawMemAllocElement(4096, 128, 256, 1024*8, memoryManager, extThread)),
	mem8192(new RawMemAllocElement(8192, 16, 256, 1024*8, memoryManager, extThread)),
	mem16384(new RawMemAllocElement(16384, 16, 256, 1024, memoryManager, extThread)),
	mem32768(new RawMemAllocElement(32768, 16, 256, 1024, memoryManager, extThread)),
	mem65536(new RawMemAllocElement(65536, 16, 256, 1024, memoryManager,extThread)),
	mem131072(new RawMemAllocElement(131072, 16, 256, 1024, memoryManager, extThread))
*/
{
	this->mem4 = new RawMemAllocElement(4, 1024, 1024*8, 1024*32, memoryManager, extThread);
	this->mem8 = new RawMemAllocElement(8, 1024, 1024*8, 1024*32, memoryManager, extThread);
	this->mem16 = new RawMemAllocElement(16, 1024, 1024*8, 1024*32, memoryManager, extThread);
	this->mem32 = new RawMemAllocElement(32, 1024, 1024*8, 1024*32, memoryManager, extThread);
	this->mem64 = new RawMemAllocElement(64, 1024, 1024*8, 1024*32, memoryManager, extThread);
	this->mem128 = new RawMemAllocElement(128, 1024, 1024*8, 1024*32, memoryManager, extThread);
	this->mem256 = new RawMemAllocElement(256, 1024, 1024*8, 1024*32, memoryManager, extThread);
	this->mem512 = new RawMemAllocElement(512, 1024, 1024*8, 1024*32, memoryManager, extThread);
	this->mem1024 = new RawMemAllocElement(1024, 256, 256, 1024*8, memoryManager, extThread);
	this->mem2048 = new RawMemAllocElement(2048, 256, 256, 1024*8, memoryManager, extThread);
	this->mem4096 = new RawMemAllocElement(4096, 128, 256, 1024*8, memoryManager, extThread);
	this->mem8192 = new RawMemAllocElement(8192, 16, 256, 1024*8, memoryManager, extThread);
	this->mem16384 = new RawMemAllocElement(16384, 16, 256, 1024, memoryManager, extThread);
	this->mem32768 = new RawMemAllocElement(32768, 16, 256, 1024, memoryManager, extThread);
	this->mem65536 = new RawMemAllocElement(65536, 16, 256, 1024, memoryManager,extThread);
	this->mem131072 = new RawMemAllocElement(131072, 16, 256, 1024, memoryManager, extThread);

}

RawArrayMemAlloc::~RawArrayMemAlloc() throw() {
	delete this->extThread;

	delete this->mem4;
	delete this->mem8;
	delete this->mem16;
	delete this->mem32;
	delete this->mem64;
	delete this->mem128;
	delete this->mem256;
	delete this->mem512;
	delete this->mem1024;
	delete this->mem2048;
	delete this->mem4096;
	delete this->mem8192;
	delete this->mem16384;
	delete this->mem32768;
	delete this->mem65536;
	delete this->mem131072;
}




#ifdef __DEBUG_LOG_MEM
void RawArrayMemAlloc::stackTrace(u_int32_t cap, void* ptr){
	DebugInfo::getInstance()->writePtr(ptr);

	const static ssize_t trace_frames_max = 100;
	void* trace_frames[trace_frames_max] = {};

	int size = ::backtrace(trace_frames, trace_frames_max);
	size = size > 4 ? 5 : size;
	for(int i = 2; i != size; ++i){
		void* address = trace_frames[i];
		StackFrame frame = resolve(address);

		DebugInfo::getInstance()->writeFrame(frame);
	}
}

StackFrame const RawArrayMemAlloc::resolve(void *address){
	bfd_vma offset = (bfd_vma)address;

	asection *section = ::bfd_get_section_by_name(DebugInfo::getInstance()->abfd, ".debug_info");
	assert(section != nullptr);

	const char *file_name;
	const char *function_name;
	unsigned int lineno;
	int found = bfd_find_nearest_line(
								DebugInfo::getInstance()->abfd,
								section,
								DebugInfo::getInstance()->symbols,
								offset,
								&file_name,
								&function_name,
								&lineno);
	if(found > 0){
		StackFrame frame;
		frame.file_name = file_name;
		frame.lineno = lineno;
		frame.function_name = function_name;

		return frame;
	}

	StackFrame frame;
	return frame;
}
#endif

void* RawArrayMemAlloc::allocateLarge(u_int32_t cap) throw() {
	char* ptr = (char*)malloc(cap + sizeof(void*));
	MemoryReleaser** pp = (MemoryReleaser**)(ptr + cap);
	*pp = nullptr;
	return ptr;
}

void RawArrayMemAlloc::freeMemory(char* ptr, u_int32_t cap) throw() {
	if(cap > 131072){
		::free(ptr);
		return;
	}


	int bound = RawArrayMemAlloc::getBoudary(cap);
	MemoryReleaser** pp = (MemoryReleaser**)(ptr + bound);

	#ifdef __MEM_DEBUG
	assert(*pp != nullptr);
	#endif

	(*pp)->freeMemory(ptr, bound);
}

void RawArrayMemAlloc::testFreeMemory(char* ptr, u_int32_t cap, AlinousMemoryManager* memoryManager) throw() {
	int bound = RawArrayMemAlloc::getBoudary(cap);
	Releaser** pp = (Releaser**)(ptr + bound);

	if(*pp == nullptr){
		if(bound < 131073){
			memoryManager->release(ptr, bound);
			return;
		}

		::free(ptr);
		return;
	}
}

#ifdef __MEM_DEBUG
void RawMemAllocElement::assertMemory(){
	int offset = this->blocksize;
	int maxLoop = this->alloc_ext;
	for(int i = 0; i != maxLoop; ++i){
		char* ptr = *(this->allocedMemory + i);

		MemoryReleaser** rel = (MemoryReleaser**)(ptr + offset);
		(*rel)->assertBound(this);
	}

}
#endif

}
