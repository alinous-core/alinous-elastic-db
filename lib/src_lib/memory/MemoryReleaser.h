/*
 * Copyright (c) Tomohiro Iizuka. All rights reserved.
 * Licensed under the MIT license.
 */


#ifndef MEMORY_MEMORYRELEASER_H_
#define MEMORY_MEMORYRELEASER_H_

namespace alinous {

class RawMemAllocElement;

class MemoryReleaser{
public:
	MemoryReleaser(RawMemAllocElement* element, AlinousMemoryManager* memoryManager) : element(element), memoryManager(memoryManager), remain(0) {
		::pthread_spin_init(&spinlock, PTHREAD_PROCESS_PRIVATE);
	}

	~MemoryReleaser(){
		::pthread_spin_destroy(&spinlock);
	}

	void freeMemory(char* ptr, u_int32_t cap) throw();

	void threadEnd(int remain){
		::pthread_spin_lock(&spinlock);
		this->element = nullptr;
		this->remain = remain;
		::pthread_spin_unlock(&spinlock);
	}

	bool isEmpty(){
		::pthread_spin_lock(&spinlock);
		bool result = this->element == nullptr &&this->remain == 0;
		::pthread_spin_unlock(&spinlock);

		return result;
	}

#ifdef __MEM_DEBUG
	void assertBound(RawMemAllocElement* element){
		assert(this->element == element);
	}

#endif

	RawMemAllocElement* element;
private:

	AlinousMemoryManager* memoryManager;
	pthread_spinlock_t spinlock;
	int remain;
};


class MemoryReleaserManager{
private:
	MemoryReleaserManager(){
		::pthread_spin_init(&spinlock, PTHREAD_PROCESS_PRIVATE);

		this->list = new SegRawLinkedList<MemoryReleaser, alinous::SegRawCompare>();
	}
public:
	~MemoryReleaserManager(){
		releaseEmptyReleaser();

		delete this->list;

		::pthread_spin_destroy(&spinlock);
	}

	static MemoryReleaserManager* getInstance(){
		static bool init = false;
		
		if(!init){
			MemoryReleaserManager::inst = new MemoryReleaserManager();
			init = true;
		}
		
		return MemoryReleaserManager::inst;
	}
	
	static void shutdown(){
		delete MemoryReleaserManager::inst;
		MemoryReleaserManager::inst = nullptr;
	}

	MemoryReleaser* newReleaser(RawMemAllocElement* element, AlinousMemoryManager* memoryManager){
		MemoryReleaser* rel = new MemoryReleaser(element, memoryManager);

		::pthread_spin_lock(&spinlock);
		list->add(rel);
		::pthread_spin_unlock(&spinlock);

		return rel;
	}

	void releaseEmptyReleaser(){
		SegRawLinkedList<MemoryReleaser, alinous::SegRawCompare>* nextlist = new SegRawLinkedList<MemoryReleaser, alinous::SegRawCompare>();

		::pthread_spin_lock(&spinlock);

		SegRawLinkedList<MemoryReleaser, alinous::SegRawCompare>::Iterator it = list->iterator();
		while(it.hasNext()){
			MemoryReleaser* rel = it.next();

			if(rel->isEmpty()){
				delete rel;
			}
			else{
				nextlist->add(rel);
			}
		}

		delete this->list;
		this->list = nextlist;

		::pthread_spin_unlock(&spinlock);
	}

private:
	static MemoryReleaserManager* inst;
	SegRawLinkedList<MemoryReleaser, alinous::SegRawCompare>* list;
	pthread_spinlock_t spinlock;
};

}

#endif /* MEMORY_MEMORYRELEASER_H_ */
