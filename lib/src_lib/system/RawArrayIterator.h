/*
 * Copyright (c) Tomohiro Iizuka. All rights reserved.
 * Licensed under the MIT license.
 */


#ifndef SYSTEM_RAWARRAYITERATOR_H_
#define SYSTEM_RAWARRAYITERATOR_H_

namespace alinous {



template <typename T, typename C = RawCompare>
class RawArrayIterator {
public:
    void* operator new(size_t size) throw() {
      	return SysThread::getMalloc()->allocate(size);
    }
    void* operator new(size_t size, MemoryInterface* ctx) throw() {
    	return ctx->alloc->allocate(size);
    }
    void operator delete(void* p, size_t size) throw() {
    	SysThread::getMalloc()->freeMemory((char*)p, size);
    }


	RawArrayIterator(const RawArrayIterator<T, C>& base) throw() : array(base.array), pos(base.pos) {

	}
	RawArrayIterator(RawArray<T, C>* parent) throw() : array(parent), pos(0) {

	}
	~RawArrayIterator() throw() {}

	inline bool hasNext() const throw()
	{
		return (this->pos < this->array->size());
	}

	inline T* next() throw() {
		return this->array->get(this->pos++);
	}

	void remove() throw() {
		this->array->remove(--this->pos);
	}
private:
	RawArray<T, C>* const array;
	int pos;
};

}

#endif /* SYSTEM_RAWARRAYITERATOR_H_ */
