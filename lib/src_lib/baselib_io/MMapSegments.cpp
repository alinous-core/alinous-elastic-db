/*
 * Copyright (c) Tomohiro Iizuka. All rights reserved.
 * Licensed under the MIT license.
 */


#include "includes.h"

namespace alinous { namespace io {


MMapSegment::MMapSegment(MMapSegments* segments, int fd, long long start, long long mappedSize, ThreadContext* ctx)
	: IObject(nullptr), fd(fd), start(start), mappedSize(mappedSize)
{
	this->segments = segments;
	//this->data = (char*)::mmap(NULL, this->mappedSize, PROT_READ | PROT_WRITE , MAP_SHARED, fd, this->start);

	this->data = (char*)ctx->alloc->allocate(segments->segmentSize);
	::memset(this->data, 0, segments->segmentSize);

	#ifdef __FILEIO_DEGUB
	assert(this->data != nullptr);
	#endif

	::lseek(this->fd, this->start, SEEK_SET);
	int ret = ::read(this->fd, this->data, this->mappedSize);
	if(ret < 0){
		throw  L"read init buff error";
	}
	this->dirty = false;

	// this->lastOfSegment = start + mappedSize - 1;
	this->lastOfSegment = start + mappedSize;

	this->userCount = 0;
	this->wait4Release = false;
}

MMapSegment::~MMapSegment(){
	// munmap(data, mappedSize);
	if(this->dirty){
		::lseek(this->fd, this->start, SEEK_SET);
		int ret = ::write(this->fd, this->data, this->mappedSize);

		if(ret < 0){
			//delete [] this->data;
			SysThread::getMalloc()->freeMemory((char*)this->data, this->segments->segmentSize);
			throw L"write back error";
		}
	}

	//delete [] this->data;
	SysThread::getMalloc()->freeMemory((char*)this->data, this->segments->segmentSize);

	this->data = nullptr;
}



void MMapSegments::onResized(long long fileSize, ThreadContext* ctx) {
	listMutex->lock();

	this->fileSize = fileSize;
	int numSegments = (int) ((fileSize % segmentSize) == 0 ? fileSize / segmentSize : (fileSize / segmentSize) + 1);

	long lastNumSegments = this->numSegments;
	this->numSegments = numSegments;

	int lastSegment = -1;
	for(int i = 0; i != numSegments; ++i){
		if(i < lastNumSegments){
			RawLinkedList<MMapSegment>::Element* segElement = const_cast<RawArray<RawLinkedList<MMapSegment>::Element>*>(this->pIndex)->get(i);

			if(segElement != nullptr){
				lastSegment = i;
			}
		}
		else{
			const_cast<RawArray<RawLinkedList<MMapSegment>::Element>*>(this->pIndex)->addElement(nullptr);
		}
	}

	if(lastSegment < 0){
		return;
	}

	RawLinkedList<MMapSegment>::Element* segElement = const_cast<RawArray<RawLinkedList<MMapSegment>::Element>*>(this->pIndex)->get(lastSegment);
	MMapSegment* seg = segElement->data;

	long nextLast = seg->start + this->segmentSize;
	if(nextLast > this->fileSize){
		nextLast = this->fileSize;
	}
	seg->lastOfSegment = nextLast;
	seg->mappedSize = nextLast - seg->start;

	listMutex->unlock();
}


DiskCacheManager::DiskCacheManager(ThreadContext* ctx) : IObject(ctx) {
	this->maxCache = 1024;
}


DiskCacheManager::~DiskCacheManager(){
	ThreadContext *ctx = ThreadContext::getCurentContext();
	__releaseRegerences(false, ctx);
}

void DiskCacheManager::__releaseRegerences(bool prepare, ThreadContext* ctx) throw()
{
	RawLinkedList<MMapSegment>* psegments = const_cast<RawLinkedList<MMapSegment>*>(&this->segments);
	if(psegments->size() > 0){
		RawLinkedList<MMapSegment>::Iterator it(psegments); // = iterator();segments.iterator();
		while(it.hasNext()){
			MMapSegment* seg = it.next();

			seg->mutex.lock();

			if(!seg->isDeletable()){
				seg->setWaitForRelease();
				seg->mutex.wait();
			}

			seg->mutex.unlock();

			delete seg;
		}

		psegments->clear();
	}
}

RawLinkedList<MMapSegment>::Element* DiskCacheManager::newSegment(MMapSegments* segments, int fd, long long start, long long segRelaSize, ThreadContext* ctx)
{
	RawLinkedList<MMapSegment>* psegments = const_cast<RawLinkedList<MMapSegment>*>(&this->segments);

	//cache out
	if(psegments->size() > this->maxCache){
		MMapSegment* seg = psegments->remove(0);

		seg->mutex.lock();
		if(!seg->isDeletable()){
			seg->setWaitForRelease();
			seg->mutex.wait();
		}

		seg->mutex.unlock();

		MMapSegments* ownerSeg = seg->segments;
		ownerSeg->cacheOutSegment(seg);

		delete seg;
	}

	MMapSegment* newseg = new(ctx) MMapSegment(segments, fd, start, segRelaSize, ctx);
	RawLinkedList<MMapSegment>::Element* element = psegments->addLast(newseg);

	return element;
}

void DiskCacheManager::notifyHitCache(RawLinkedList<MMapSegment>::Element* element){
	RawLinkedList<MMapSegment>* psegments = const_cast<RawLinkedList<MMapSegment>*>(&this->segments);

	psegments->moveElementToLast(element);
}

void DiskCacheManager::removeCache(RawLinkedList<MMapSegment>::Element* element){
	RawLinkedList<MMapSegment>* psegments = const_cast<RawLinkedList<MMapSegment>*>(&this->segments);
	MMapSegment* seg = element->data;

	seg->mutex.lock();
	if(!seg->isDeletable()){
		seg->setWaitForRelease();
		seg->mutex.wait();
	}
	seg->mutex.unlock();

	psegments->removeElement(element);
	delete seg;
}

}}

