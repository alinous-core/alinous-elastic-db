/*
 * Copyright (c) Tomohiro Iizuka. All rights reserved.
 * Licensed under the MIT license.
 */


#ifndef BASELIB_IO_MMAPSEGMENTS_H_
#define BASELIB_IO_MMAPSEGMENTS_H_

namespace alinous { namespace io {

class MMapSegment;
class MMapSegments;
}}

namespace alinous { namespace io {

using alinous::io::MMapSegment;
using alinous::io::MMapSegments;

class DiskCacheManager : public virtual IObject {
public:
	DiskCacheManager(ThreadContext* ctx);
	virtual ~DiskCacheManager();

	void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();

	RawLinkedList<MMapSegment>::Element* newSegment(MMapSegments* segments, int fd, long long start, long long segRelaSize, ThreadContext* ctx);

	void notifyHitCache(RawLinkedList<MMapSegment>::Element* element);
	void removeCache(RawLinkedList<MMapSegment>::Element* element);

private:
	int maxCache;
	volatile RawLinkedList<MMapSegment> segments;
public:
	TaskSynchronizer listMutex;
};


class MMapSegment : public virtual IObject {
public:

    MMapSegment(MMapSegments* segments, int fd, long long start, long long mappedSize, ThreadContext* ctx);

	virtual ~MMapSegment();

	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw() {}

	inline int read(const long long position) {
		int base = position - this->start;

		return this->data[base] ;
	}

	inline long long read(const long long position, IArrayObjectPrimitive<char>* buffer, const int offset, const int count, const ThreadContext* ctx){

		int readCount = position + count <= this->lastOfSegment ? count : this->lastOfSegment - position;
		int base = position - this->start;


		FastCopy::copy(buffer->raw->root + offset, this->data + base, readCount);

	/*	for(int i = 0; i != readCount; ++i){
			buffer->set(this->data[base + i], offset + i, ctx);
		}
*/
		return readCount;
	}

	inline long long read(const long long position, char* buffer, const int offset, const int count, const ThreadContext* ctx) {

		int readCount = position + count <= this->lastOfSegment ? count : this->lastOfSegment - position;
		int base = position - this->start;

		FastCopy::copy(buffer + offset, this->data + base, readCount);
/*
		for(int i = 0; i != readCount; ++i){
			buffer[offset + i] = this->data[base + i];
		}
*/
		return readCount;
	}

	inline void write(long long position, int oneByte) {
		char ch = (char)oneByte;
		int base = position - this->start;

		this->data[base] = ch;
		this->dirty = true;
	}

	inline long long write(const long long position, const IArrayObjectPrimitive<char>* buffer, const int offset, const int count, const ThreadContext* ctx) {
		int writeCount = position + count <= this->lastOfSegment ? count : this->lastOfSegment - position;
		int base = position - this->start;

		for(int i = 0; i != writeCount; ++i){
			this->data[base + i] = buffer->get(offset + i);
		}

		this->dirty = true;

		return writeCount;
	}

	inline long long write(const long long position, const char* buffer, const int offset, const int count, const ThreadContext* ctx) {
		int writeCount = position + count <= this->lastOfSegment ? count : this->lastOfSegment - position;
		int base = position - this->start;

		for(int i = 0; i != writeCount; ++i){
			this->data[base + i] = buffer[offset + i];
		}

		this->dirty = true;

		return writeCount;
	}

	inline void incUserCount(){
		++this->userCount;
	}

	inline void decUserCount(){
		decUserCount(nullptr);
	}

	inline void decUserCount(ThreadContext* ctx){
		this->mutex.lock();
		--this->userCount;

		if(this->wait4Release && this->userCount == 0){
			this->wait4Release = false;
			this->mutex.notifyAll();
		}

		this->mutex.unlock();
	}

	inline bool isDeletable(){
		return this->userCount == 0;
	}

	inline void setWaitForRelease(){
		this->wait4Release = true;
	}

public:
	MMapSegments* segments;
	int fd;
	long long start;
	long long mappedSize;
	long long lastOfSegment;

private:
	int userCount;
	volatile bool wait4Release;
public:
	char* data;
	bool dirty;

	TaskSynchronizer mutex;

};

class MMapSegments {
public:
    inline void* operator new(size_t size) throw() {
      	return SysThread::getMalloc()->allocate(size);
    }
    inline void* operator new(size_t size, MemoryInterface* ctx) throw() {
    	return ctx->alloc->allocate(size);
    }
    inline void operator delete(void* p, size_t size) throw() {
    	SysThread::getMalloc()->freeMemory((char*)p, size);
    }

    inline MMapSegments(DiskCacheManager* diskCache, int fd, long long segmentSize, int fileSize){
    	this->diskCache = diskCache;
    	this->listMutex = &diskCache->listMutex;

    	this->fileSize = fileSize;
    	this->segmentSize = segmentSize;
    	int numSegments = (fileSize % segmentSize) == 0 ? fileSize / segmentSize : (fileSize / segmentSize) + 1;

    	this->numSegments = numSegments;

    	pIndex = new RawArray<RawLinkedList<MMapSegment>::Element >(numSegments);
    	const_cast<RawArray<RawLinkedList<MMapSegment>::Element>*>(this->pIndex)->size(numSegments);
    	for(int i = 0; i != numSegments; ++i){
    		const_cast<RawArray<RawLinkedList<MMapSegment>::Element>*>(this->pIndex)->set(i, nullptr);
    	}

    	this->fd = fd;
    }

    inline ~MMapSegments(){
    	this->listMutex->lock();

    	auto it = const_cast<RawArray<RawLinkedList<MMapSegment>::Element>*>(this->pIndex)->iterator();
    	while(it.hasNext()){
    		RawLinkedList<MMapSegment>::Element* element = it.next();
    		if(element != nullptr){
    			this->diskCache->removeCache(element);
    		}
    	}

    	this->listMutex->unlock();

    	delete pIndex;
    }

    inline MMapSegment* getSegment(long long pos, ThreadContext* ctx){
    	listMutex->lock();

    	long long index = pos / segmentSize;

    	RawArray<RawLinkedList<MMapSegment>::Element>* pIndex = const_cast<RawArray<RawLinkedList<MMapSegment>::Element>*>(this->pIndex);


    	RawLinkedList<MMapSegment>::Element* seg = pIndex->get(index);
    	if(seg != nullptr){
    		MMapSegment* ret = seg->data;

    		this->diskCache->notifyHitCache(seg);

    		ret->incUserCount();
    		listMutex->unlock();

			#ifdef __FILEIO_DEGUB
			assert(ret->data != nullptr);
			#endif

    		return ret;
    	}

    	long long start = pos - (pos % segmentSize);

    	// calc segment size
    	long long remain = (this->fileSize - start);
    	long long segRealSize = remain < this->segmentSize ? remain : this->segmentSize;

    	RawLinkedList<MMapSegment>::Element* element = this->diskCache->newSegment(this, this->fd, start, segRealSize, ctx);

		#ifdef __FILEIO_DEGUB
    	RawLinkedList<MMapSegment>::Element* testelb = pIndex->get(index);
		assert(testelb == nullptr);
		#endif


		pIndex->set(index, element);

		#ifdef __FILEIO_DEGUB
    	RawLinkedList<MMapSegment>::Element* testel = pIndex->get(index);
		assert(testel != nullptr);
		#endif

    	element->data->incUserCount();
    	listMutex->unlock();

		#ifdef __FILEIO_DEGUB
    	assert(element->data != nullptr);
		#endif

    	return element->data;
    }

    inline void cacheOutSegment(MMapSegment* seg){
    	int index = seg->start / this->segmentSize;
    	RawArray<RawLinkedList<MMapSegment>::Element>* pIndex = const_cast<RawArray<RawLinkedList<MMapSegment>::Element>*>(this->pIndex);

		#ifdef __FILEIO_DEGUB
    	RawLinkedList<MMapSegment>::Element* element = pIndex->get(index);
    	assert(element != nullptr);
		#endif


    	pIndex->set(index, nullptr);
    }

    void onResized(long long fileSize, ThreadContext* ctx);
private:
    DiskCacheManager* diskCache;
    volatile RawArray<RawLinkedList<MMapSegment>::Element >* pIndex;
	TaskSynchronizer* listMutex;
public:
	long long numSegments;
	long long segmentSize;
	long long fileSize;
	int fd;

};


}}
#endif /* BASELIB_IO_MMAPSEGMENTS_H_ */
