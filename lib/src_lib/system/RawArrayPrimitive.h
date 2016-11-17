/*
 * Copyright (c) Tomohiro Iizuka. All rights reserved.
 * Licensed under the MIT license.
 */


#ifndef SYSTEM_RAWARRAYPRIMITIVE_H_
#define SYSTEM_RAWARRAYPRIMITIVE_H_

namespace alinous {

template <typename T>
class RawArrayPrimitiveIterator;


#define DEFAULT_RAW_PRIMITIVE_ARRAY_SIZE 128



template <typename T>
class RawArrayPrimitive {
	typedef int (*COMPARE_PRIMITIVE_FUNC)(T &a, T &b);
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

	RawArrayPrimitive(MemoryInterface* ctx) throw() : numArray(0), currentSize(DEFAULT_RAW_PRIMITIVE_ARRAY_SIZE),
			root((T*)ctx->alloc->allocate(currentSize * sizeof(T))),
			sorted(false)
	{
	#ifdef COUNT_IOBJECT
		__MEM_CTR::__cp();
	#endif
	}
	RawArrayPrimitive() throw() : numArray(0), currentSize(DEFAULT_RAW_PRIMITIVE_ARRAY_SIZE),
			root((T*)SysThread::getMalloc()->allocate(currentSize * sizeof(T))),
			sorted(false)
	{
	#ifdef COUNT_IOBJECT
		__MEM_CTR::__cp();
	#endif
	}
	RawArrayPrimitive(int defaultSize) throw() : numArray(0),
			currentSize(defaultSize > 4 ? defaultSize : 4),
			root((T*)SysThread::getMalloc()->allocate(currentSize * sizeof(T))),
			sorted(false)
	{
	#ifdef COUNT_IOBJECT
		__MEM_CTR::__cp();
	#endif
	}
	RawArrayPrimitive(int defaultSize, MemoryInterface* ctx) throw() : numArray(0),
	currentSize(defaultSize > 4 ? defaultSize : 4),
	root((T*)ctx->alloc->allocate(currentSize * sizeof(T))),
	sorted(false)
	{
	#ifdef COUNT_IOBJECT
	__MEM_CTR::__cp();
	#endif
	}

	RawArrayPrimitive(int defaultSize, COMPARE_PRIMITIVE_FUNC compare) throw() : numArray(0),
			currentSize(defaultSize > 4 ? defaultSize : 4),
			root((T*)SysThread::getMalloc()->allocate(currentSize * sizeof(T))),
			sorted(false)
	{
	#ifdef COUNT_IOBJECT
		__MEM_CTR::__cp();
	#endif
	}

	RawArrayPrimitive(T* array, int size, int cap) throw() {
		this->root = nullptr;
		mapElement(array, size, cap);

		this->sorted = false;
	}
	~RawArrayPrimitive() throw() {
		if(this->root != nullptr){
			SysThread::getMalloc()->freeMemory((char*)this->root, this->currentSize * sizeof(T));

			this->root = nullptr;
		}
	}
	RawArrayPrimitive<T>* move(ThreadContext* ctx) throw() {
		T* ar = this->root;

		RawArrayPrimitive<wchar_t>* ptr = new(ctx) RawArrayPrimitive<wchar_t>(ar, this->numArray, this->currentSize);

		this->root = nullptr;
		this->currentSize = 0;
		this->numArray = 0;

		return ptr;
	}

public:
	void mapElement(T* array, int length, int cap) throw() {
		if(this->root != nullptr){
			SysThread::getMalloc()->freeMemory((char*)this->root, this->currentSize * sizeof(T));
		}

		this->root = array;
		this->currentSize = cap;
		this->numArray = length;
	}
	T* allocNew() throw() {
		if(__builtin_expect(this->currentSize == this->numArray, 0)){
			int size = this->currentSize * 2;

			T* newPtr =(T*)SysThread::getMalloc()->allocate(size * sizeof(T));

			//__memset(newPtr, 0, sizeof(T) * size);

			FastCopy::copy(newPtr, this->root, sizeof(T) * this->currentSize);

			SysThread::getMalloc()->freeMemory((char*)this->root, this->currentSize * sizeof(T));

			this->root = newPtr;
			this->currentSize = size;

	#ifdef COUNT_IOBJECT
			__MEM_CTR::__cp();
	#endif
		}

		return &(this->root[this->numArray++]);
	}
	void addElement(const T value) throw() {
		if(__builtin_expect(this->currentSize == this->numArray, 0)){
			int size = this->currentSize * 2;

			T* newPtr =(T*)SysThread::getMalloc()->allocate(size * sizeof(T));
			//__memset(newPtr, 0, sizeof(T) * size);

			FastCopy::copy(newPtr, this->root, sizeof(T) * this->currentSize);

			SysThread::getMalloc()->freeMemory((char*)this->root, this->currentSize * sizeof(T));
			this->root = newPtr;

			this->currentSize = size;

	#ifdef COUNT_IOBJECT
			__MEM_CTR::__cp();
	#endif
		}

		this->root[this->numArray++] = value;

		this->sorted = false;
	}
	void addElement(const T value, const int index) throw() {
		if(__builtin_expect(this->currentSize == this->numArray, 0)){
			int size = this->currentSize * 2;

			T* newPtr =(T*)SysThread::getMalloc()->allocate(size * sizeof(T));

			FastCopy::copy(newPtr, this->root, sizeof(T) * this->currentSize);



			SysThread::getMalloc()->freeMemory((char*)this->root, this->currentSize * sizeof(T));

			this->root = newPtr;
			this->currentSize = size;

	#ifdef COUNT_IOBJECT
			__MEM_CTR::__cp();
	#endif

		}

		int copySize = this->numArray - index;
		if(copySize > 0){
			for(int i = this->numArray; i >= index; i--){
				this->root[i + 1] = this->root[i];
			}
		}

		this->numArray++;
		this->root[index] = value;
	}

	void remove(const int index, const int length) throw() {
		#ifdef __DEBUG__
		assert(index + length <= this->numArray);
		#endif

		const int copySize = (this->numArray - index - length);
		if(copySize > 0){
			for(int i = 0; i < copySize; i++){
				this->root[index + i] = this->root[index + i + length];
			}
		}

		this->numArray = this->numArray - length;
	}
	void remove(const int index) throw() {
		remove(index, 1);
	}
	void reset() throw() {
		this->numArray = 0;
		this->sorted = false;
	}
	bool contains(const T value) const throw() {
		const int max = this->numArray;
		for(int i = 0; i != max; ++i){
			if(root[i] == value){
				return true;
			}
		}
		return false;
	}
	bool removeFirstByValue(T value) throw() {
		const int max = this->numArray;
		for(int i = 0; i != max; ++i){
			if(root[i] == value){
				remove(i);

				return true;
			}
		}
		return false;
	}

	inline int size() const throw() {
		return numArray;
	}
	inline T get(const int i) const throw() {
		return *(this->root + i);
	}
	inline T* getPtr(const int i) const throw() {
		return (this->root + i);
	}
	inline void set(const int i, T value) const throw() {
		*(this->root + i) = value;
	}
	inline RawArrayPrimitiveIterator<T>* iterator() throw() {
		return new RawArrayPrimitiveIterator<T>(this);
	}

// private:
	int numArray;
	int currentSize;
	T* root;
	bool sorted;
};




} /* namespace alinous */

#endif /* SYSTEM_RAWARRAYPRIMITIVE_H_ */
