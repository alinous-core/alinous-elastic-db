/*
 * Copyright (c) Tomohiro Iizuka. All rights reserved.
 * Licensed under the MIT license.
 */


#ifndef SYSTEM_RAWARRAYPRIMITIVEITERATOR_H_
#define SYSTEM_RAWARRAYPRIMITIVEITERATOR_H_

namespace alinous {

template <typename T>
class RawArrayPrimitive;

template <typename T>
class RawArrayPrimitiveIterator {
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

	RawArrayPrimitiveIterator(RawArrayPrimitive<T>* parent) throw() : array(parent) {
		this->pos = 0;
	}
	~RawArrayPrimitiveIterator() throw() {}

	bool hasNext() const throw(){
		return (this->pos < this->array->size());
	}
	T next() throw() {
		return this->array->get(this->pos++);
	}
	T* const nextPtr() throw() {
		return this->array->getPtr(this->pos++);
	}
	void remove() throw() {
		this->array->remove(--this->pos);
	}

private:
	RawArrayPrimitive<T>*  array;
	int pos;
};

} /* namespace alinous */

#endif /* SYSTEM_RAWARRAYPRIMITIVEITERATOR_H_ */
