/*
 * Copyright (c) Tomohiro Iizuka. All rights reserved.
 * Licensed under the MIT license.
 */



#ifndef SYSTEM_RAWARRAY_H_
#define SYSTEM_RAWARRAY_H_


namespace alinous {

class ThreadContext;

template <typename T, typename C>
class RawArrayIterator;

#define DEFAULT_RAW_ARRAY_SIZE 64

#ifdef COUNT_IOBJECT
class __MEM_CTR{
public:
	static int newCtr;
	static bool startCtr;
	static void __cr(){
		if(startCtr){
			newCtr++;
		}
	}
	static int newpCtr;
	static bool startpCtr;
	static void __cp(){
		if(startpCtr){
			newpCtr++;
		}
	}
};
#endif

template <typename T, typename C = RawCompare> class RawArray {
public:
	typedef T* ElementType;

	void* operator new(size_t size) throw() {
		return SysThread::getMalloc()->allocate(size);
	}
	void* operator new(size_t size, MemoryInterface* ctx) throw() {
		return ctx->alloc->allocate(size);
	}
	void operator delete(void* p, size_t size) throw() {
		SysThread::getMalloc()->freeMemory((char*)p, size);
	}

	RawArray() throw() : numArray(0), currentSize(DEFAULT_RAW_ARRAY_SIZE),
			root((ElementType*)SysThread::getMalloc()->allocate(this->currentSize * sizeof(ElementType))), cursor(root),
			sorted(false),
			compareFunctor() {

#ifdef COUNT_IOBJECT
		__MEM_CTR::__cr();
#endif

	}
	RawArray(int defaultSize) throw() : numArray(0), currentSize(defaultSize > 4 ? defaultSize : 4),
			root((ElementType*)SysThread::getMalloc()->allocate(currentSize * sizeof(ElementType))), cursor(root),
			sorted(false),
			compareFunctor()
	{
#ifdef COUNT_IOBJECT
		__MEM_CTR::__cr();
#endif
	}

	RawArray(MemoryInterface* ctx) throw() : numArray(0), currentSize(DEFAULT_RAW_ARRAY_SIZE),
			root((ElementType*)ctx->alloc->allocate(this->currentSize * sizeof(ElementType))), cursor(root),
			sorted(false),
			compareFunctor() {

#ifdef COUNT_IOBJECT
		__MEM_CTR::__cr();
#endif

	}
	RawArray(int defaultSize, MemoryInterface* ctx) throw() : numArray(0), currentSize(defaultSize > 4 ? defaultSize : 4),
			root((ElementType*)ctx->alloc->allocate(currentSize * sizeof(ElementType))), cursor(root),
			sorted(false),
			compareFunctor()
	{
#ifdef COUNT_IOBJECT
		__MEM_CTR::__cr();
#endif
	}


	RawArray<T, C>* shallowCopy() throw() {
		RawArray<T, C>* newInstance = new RawArray<T,C>(this->currentSize);
		newInstance->sorted = this->sorted;
		newInstance->numArray = this->numArray;
		newInstance->currentSize = this->currentSize;

		int size2Copy = this->numArray * sizeof(T*);
		FastCopy::copy(newInstance->root, this->root, size2Copy);

		newInstance->cursor = newInstance->root + this->numArray;

		return newInstance;
	}

	~RawArray() throw() {
		if(this->root != nullptr){
			// delete [] this->root;
			SysThread::getMalloc()->freeMemory((char*)this->root, this->currentSize * sizeof(ElementType));

			this->root = nullptr;
		}
	}
private:

	int indexOfInsertByLoop(const T* value, ThreadContext* const ctx) const throw()
	{
		const ElementType* const _root = this->root;
		int maxLoop = this->numArray;
		for(int i = 0; i != maxLoop; ++i){
			if(compareFunctor(value, _root[i], ctx) <= 0){
				return i;
			}
		}

		return maxLoop;
	}

	int indexOfInsert(const T* value, ThreadContext* const ctx) const throw()
	{
		if(this->numArray < 4){
			return indexOfInsertByLoop(value, ctx);
		}

		int begin = 0;
		int end = this->numArray - 1;
		int mid = (begin + end) / 2;

		const ElementType* const _root = this->root;
		while(begin <= end) {
			mid = (begin + end) / 2;

			if(compareFunctor(_root[mid], value, ctx) == 0){
				return mid;
			}
			else if(compareFunctor(_root[mid], value, ctx) < 0){
				begin = mid + 1;
			}
			else {
				end = mid - 1;
			}
		}

		if(end < 0){
			return 0;
		}
		if(compareFunctor(_root[end], value, ctx) > 0){
			return end;
		}


		if(begin >= size()){
			return size();
		}

		if(compareFunctor(_root[begin], value, ctx) > 0){
			return begin;
		}

		return size();
	}


	void insertWithKeepingOrder(T* ptr, int index) throw()
	{
		if(__builtin_expect(this->currentSize == this->numArray, 0)){
			realloc();
		}

		for(int i = this->numArray; i != index; i--){
			*(this->root + i)= *(this->root + i - 1);
		}


		this->root[index] = ptr;

		this->numArray++;
		this->cursor++;
	}
public:

	void addElementWithSorted(T* ptr) throw() {
		if(!this->sorted && size() > 1){
			sort(nullptr);
		}

		int index = indexOfInsert(ptr, nullptr);

		#ifdef __DEBUG__
		if(size() == 0){
			assert(index == 0);
		}
		else if(index < size()){
			const T* last = get(index);
			int diff = compareFunctor(ptr, last, nullptr);
			assert(diff <= 0);
			if(index > 0){
				T* before = get(index - 1);
				diff = compareFunctor(before, ptr, nullptr);
				assert(diff <= 0);
			}
		}else {
			const T* before = get(index - 1);
			int diff = compareFunctor(before, ptr, nullptr);
			assert(diff <= 0);
		}
		#endif


		insertWithKeepingOrder(ptr, index);
	}

	__attribute__((always_inline))
	void addElement(T* ptr) throw()
	{
		if(__builtin_expect(this->currentSize <= this->numArray, 0)){
			realloc();
		}

		//this->root[this->numArray++] = ptr;
		*this->cursor = ptr;

		this->cursor++;
		this->numArray++;
		this->sorted = false;
	}


	inline void addElement(T* ptr, int index) throw()
	{
		if(__builtin_expect(this->currentSize == this->numArray, 0)){
			realloc();
		}

		const int copySize = this->numArray - index;
		if(copySize > 0){
			for(int i = this->numArray - 1; i >= index; i--){
				*(this->root + i + 1) = *(this->root + i);
			}
		}

		this->numArray++;
		this->cursor++;
		*(this->root + index) = ptr;

		this->sorted = false;
	}

	inline T* pop() throw() {
		int index = this->numArray - 1;
		T* ptr = *(this->cursor - 1); // this->root[index];

		remove(index);

		return ptr;
	}

	inline T* peek() const throw() {
		if(__builtin_expect(this->numArray == 0, 0)){
			return nullptr;
		}
	//	int index = this->numArray - 1;
	//	T* ptr = this->root[index];
		T* ptr = *(this->cursor - 1);

		return ptr;
	}


	__attribute__((always_inline))
	inline T* peekNoCheck() throw() {
		// return this->root[this->numArray - 1];
		return *(this->cursor - 1);
	}


	void realloc() throw() {
		int lastSize = this->currentSize;
		int size = this->currentSize * 2;

		//ElementType* newPtr = new ElementType [size]{};
		ElementType* newPtr = (ElementType*)SysThread::getMalloc()->allocate(size * sizeof(ElementType));

		const int max = this->currentSize;
		__copy(newPtr, 0, this->root, 0, max);

		this->currentSize = size;

		// delete [] this->root;
		SysThread::getMalloc()->freeMemory((char*)this->root, lastSize * sizeof(ElementType));

		this->root = newPtr;
		this->cursor = this->root + this->numArray;

#ifdef COUNT_IOBJECT
		__MEM_CTR::__cr();
#endif
	}

	inline void __copy(T** dest, int dest_start, T** src, int src_start, const int count) throw()
	{
		T** d = dest + dest_start;
		T** s = src + src_start;

		FastCopy::copy(d, s, count * sizeof(T*));
	}

	inline T* get(int i) const throw() {
		return *(this->root + i);
	}
	void set(int i, T* ptr) throw() {
		#ifdef __DEBUG__
		assert(i < size());
		#endif

		*(this->root + i) = ptr;

		this->sorted = false;
	}


	void remove(const int index, const int length) throw()
	{
#ifdef __DEBUG__
		assert(index + length <= this->numArray);
#endif
		const int copySize = (this->numArray - index - length);
		if(copySize > 0){
			for(int i = 0; i < copySize; i++){
				this->root[index + i] = this->root[index + i + length];
			}
			//__move(this->root, index, this->root, index + length, copySize);
		}

		this->numArray = this->numArray - length;
		this->cursor -= length;
	}


	void __move(T** dest, int dest_start, T** src, int src_start, const int count) throw(){
		T** d = dest + dest_start;
		void* s = src + src_start;

		::memmove(d, s, count * sizeof(T*));
	}

	void remove(int index) throw()
	{
		remove(index, 1);
	}


	bool removeByObj(const T* obj) throw()
	{
		int index = indexOf(obj);

		if(index < 0){
			return false;
		}

		remove(index);

		return true;
	}
	void reset() throw() {
		this->numArray = 0;
		this->cursor = this->root;

		this->sorted = true;
	}

	const RawArrayIterator<T,C> iterator() throw()
	{
		RawArrayIterator<T,C> it(this);
		return it;
	}

	inline int size() const throw() {
		return numArray;
	}

	T* search(const T* value) throw()
	{
		return search(value, 0);
	}

	T* search(const T* value, ThreadContext* ctx) throw()
	{
		if(this->numArray == 0){
			return 0;
		}

		if(!this->sorted){
			this->sort();
		}
		int begin = 0;
		int end = this->numArray - 1;
		int mid = (begin + end) / 2;

		const ElementType* const _root = this->root;
		while(begin <= end) {
			mid = (begin + end) / 2;

			if(compareFunctor(_root[mid], value, ctx) == 0){
				return _root[mid];
			}
			else if((compareFunctor)(_root[mid], value, ctx) < 0){ // this->root[mid] < value
				begin = mid + 1;
			}
			else{ // this->root[mid] > value
				end = mid - 1;
			}
		}

		return nullptr;
	}
	int indexOf(const T* value) throw() {
		return indexOf(value, 0);
	}

	int indexOf(const T* value, ThreadContext* ctx) throw()
	{
		if(!this->sorted){
			this->sort();
		}
		int begin = 0;
		int end = this->numArray - 1;
		int mid = (begin + end) / 2;

		const ElementType* const _root = this->root;
		while(begin <= end) {
			mid = (begin + end) / 2;

			if(compareFunctor(_root[mid], value, ctx) == 0){
				return mid;
			}
			else if(compareFunctor(_root[mid], value, ctx) < 0){
				begin = mid + 1;
			}
			else {
				end = mid - 1;
			}
		}

		return -1;
	}
	void sort() throw() {
		return sort(0);
	}

	void sort(ThreadContext* ctx) throw()
	{
		int length = this->numArray;

		int middle = (length) / 2;

		for (int i = middle; i >= 0; i--) {
		    downheap(i, length - 1, ctx);
		}

		for (int i = length - 1; i > 0; i--) {
		    swap(0, i);
		    downheap(0, i - 1, ctx);
		}
		this->sorted = true;
	}
	void setSorted(bool b) throw()
	{
		this->sorted = b;
	}
	void size(int num){
		if(num > this->currentSize){
			realloc();
		}

		this->numArray = num;
		ElementType* pptr = this->cursor;
		ElementType* ppend = this->root + num;
		while(pptr != ppend){
			*pptr = 0;
			pptr++;
		}

		this->cursor = ppend;
	}

private:

	void downheap(int rootDefault, int leaf, ThreadContext* ctx) const throw()
	{
		int root = rootDefault;
		int left = (root + 1) * 2 - 1;;
		int right = left + 1;
		const T* leafMax;
		const T* rootValue = nullptr;
		const ElementType* const _root = this->root;

		while (left <= leaf) {
			if(right <= leaf){ // The tree has right
				left = compareFunctor(_root[left], _root[right], ctx) < 0 ? right : left;
			}

			leafMax = _root[left];
			rootValue = _root[root];

			if(compareFunctor(leafMax, rootValue, ctx) < 0){
				return;
			}

			swap(root, left);
			//debugPrint("swap() :");

			// next status
			root = left;
			left = (root + 1) * 2 - 1;
			right = left + 1;
		}
	}
	void swap(const int i, const int j) const throw()
	{
		T* tmp = root[i];
		root[i] = root[j];
		root[j] = tmp;
	}

public:
	int numArray;
	int currentSize;
	ElementType* root;
	ElementType* cursor;
	bool sorted;
	const C compareFunctor;


};

}  // namespace alinous

#endif /* SYSTEM_RAWARRAY_H_ */
