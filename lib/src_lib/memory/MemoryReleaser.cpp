/*
 * Copyright (c) Tomohiro Iizuka. All rights reserved.
 * Licensed under the MIT license.
 */


#include "include/global.h"


namespace alinous {

MemoryReleaserManager* MemoryReleaserManager::inst = nullptr;

void MemoryReleaser::freeMemory(char* ptr, u_int32_t bound) throw()
{
	#ifdef __MEM_DEBUG
	if(this->element != nullptr){
		u_int64_t blocksize = this->element->blocksize;
		assert(blocksize == bound);
	}
	#endif

	::pthread_spin_lock(&spinlock);

	if(this->element != nullptr){
		this->element->freeMemory(ptr, bound);

		::pthread_spin_unlock(&spinlock);
		return;
	}

	this->memoryManager->release(ptr, bound);
	this->remain--;


	::pthread_spin_unlock(&spinlock);
}


}

