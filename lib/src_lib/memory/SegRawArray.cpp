/*
 * Copyright (c) Tomohiro Iizuka. All rights reserved.
 * Licensed under the MIT license.
 */


#include "include/global.h"

namespace alinous {

int SegRawCompare::operator() (const void* const a, const void* const b) const throw() {
	long long diff = (long long)a - (long long)b;
	if(diff == 0){
		return 0;
	}
	return diff > 0 ? 1 : -1;
}

template <typename T, typename C>
SegRawArray<T, C>::SegRawArray() throw() : compareFunctor() {
	this->currentSize = DEFAULT_SEG_RAW_ARRAY_SIZE;
	this->numArray = 0;

	int size = this->currentSize;

	this->root = new ElementType [size]{};
	this->cursor = root;

	this->sorted = true;
}

template <typename T, typename C>
SegRawArray<T, C>::SegRawArray(int defaultSize) throw() : compareFunctor()
{
	if(defaultSize < 4){
		defaultSize = 4;
	}

	this->currentSize = defaultSize;
	this->numArray = 0;

	int size = this->currentSize;

	this->root = new ElementType [size]{};
	this->cursor = root;

	this->sorted = true;
}

template <typename T, typename C>
SegRawArray<T, C>* SegRawArray<T, C>::shallowCopy() throw() {
	SegRawArray<T, C>* newInstance = new SegRawArray<T,C>(this->currentSize);
	newInstance->sorted = this->sorted;
	newInstance->numArray = this->numArray;
	newInstance->currentSize = this->currentSize;

	int size2Copy = this->numArray * sizeof(T*);
	FastCopy::copy(newInstance->root, this->root, size2Copy);

	newInstance->cursor = newInstance->root + this->numArray;

	return newInstance;
}

template <typename T, typename C>
SegRawArray<T, C>::~SegRawArray() throw() {
	if(this->root != nullptr){
		delete [] this->root;
		this->root = nullptr;
	}
}

template <typename T, typename C>
int SegRawArray<T, C>::indexOfInsert(const T* value) const throw()
{
	int begin = 0;
	int end = this->numArray - 1;
	int mid = (begin + end) / 2;

	const ElementType* const _root = this->root;
	while(begin <= end) {
		mid = (begin + end) / 2;

		if(compareFunctor(_root[mid], value) == 0){
			return mid;
		}
		else if(compareFunctor(_root[mid], value) < 0){
			begin = mid + 1;
		}
		else {
			end = mid - 1;
		}
	}

	if(end < 0){
		return 0;
	}
	if(compareFunctor(_root[end], value) > 0){
		return end;
	}


	if(begin >= size()){
		return size();
	}

	if(compareFunctor(_root[begin], value) > 0){
		return begin;
	}

	return size();
}

template <typename T, typename C>
void SegRawArray<T, C>::insertWithKeepingOrder(T* ptr, int index) throw()
{
	if(this->currentSize == this->numArray){
		realloc();
	}

	for(int i = this->numArray; i != index; i--){
		ElementType* pptr = this->root + i;
		*pptr = *(this->root + i - 1);
	}

	this->numArray++;
	*(this->root + index) = ptr;

	this->cursor++;
}

template <typename T, typename C>
void SegRawArray<T, C>::addElementWithSorted(T* ptr) throw() {
	if(!this->sorted && size() > 1){
		sort();
	}

	int index = indexOfInsert(ptr);

	insertWithKeepingOrder(ptr, index);
}

template <typename T, typename C>
void SegRawArray<T, C>::addElement(T* ptr) throw()
{
	if(__builtin_expect(this->currentSize <= this->numArray, 0)){
		realloc();
	}

	//this->root[this->numArray++] = ptr;
	*this->cursor++ = ptr;
	this->numArray++;

	this->sorted = false;
}

template <typename T, typename C>
void SegRawArray<T, C>::addElement(T* ptr, int index) throw()
{
	if(this->currentSize == this->numArray){
		realloc();
	}

	const int copySize = this->numArray - index;
	if(copySize > 0){
		for(int i = this->numArray; i >= index; i--){
			*(this->root + i + 1) = *(this->root + i);
		}
	}
	if(index == this->numArray){
		this->numArray++;
	}
	*(this->root + index) = ptr;

	this->sorted = false;
}

template <typename T, typename C>
T* SegRawArray<T, C>::pop() throw() {
	int index = this->numArray - 1;
	T* ptr = *(this->cursor - 1); // this->root[index];

	remove(index);

	return ptr;
}

template <typename T, typename C>
T* SegRawArray<T, C>::peek() const throw() {
	if(this->numArray == 0){
		return nullptr;
	}

	return *(this->cursor - 1);
}

template <typename T, typename C>
void SegRawArray<T, C>::realloc() throw() {
	int size = this->currentSize * 2;

	ElementType* newPtr = new ElementType [size]{};

	const int max = this->currentSize;
	__copy(newPtr, 0, this->root, 0, max);

	this->currentSize = size;

	delete [] this->root;

	this->root = newPtr;
	this->cursor = this->root + this->numArray;
}

template <typename T, typename C>
T* SegRawArray<T, C>::get(int i) const  throw() {
	//int page = i >> 7;
	//int offset = i & 127;

	// ElementType* base = this->root + (page << 7);

	return *(this->root + i);
}

template <typename T, typename C>
void SegRawArray<T, C>::set(int i, T* ptr) throw() {
	/*int page = i >> 7;
	int offset = i & 127;

	ElementType* base = this->root + (page << 7);

	base[offset] = ptr;*/

	*(this->root + i) = ptr;

	//this->root[i] = ptr;
	this->sorted = false;
}

template <typename T, typename C>
void SegRawArray<T, C>::remove(const int index, const int length) throw()
{
#ifdef __DEBUG__
	assert(index + length <= this->numArray);
#endif
	const int copySize = (this->numArray - index - length);
	if(copySize > 0){
		//for(int i = 0; i < copySize; i++){
		//	this->root[index + i] = this->root[index + i + length];
		//}
		__move(this->root, index, this->root, index + length, copySize);
	}

	this->numArray = this->numArray - length;
	this->cursor -= length;
}

template <typename T, typename C>
void SegRawArray<T, C>::remove(int index) throw()
{
	remove(index, 1);
}

template <typename T, typename C>
bool SegRawArray<T, C>::removeByObj(const T* obj) throw()
{
	int index = indexOf(obj);

	if(index < 0){
		return false;
	}

	remove(index);

	return true;
}
template <typename T, typename C>
void SegRawArray<T, C>::reset() throw() {
	this->numArray = 0;
	this->cursor = this->root;

	this->sorted = true;
}


template <typename T, typename C>
int SegRawArray<T, C>::size() const throw() {
	return numArray;
}

template <typename T, typename C>
T* SegRawArray<T, C>::search(const T* value) throw()
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

		if(compareFunctor(_root[mid], value) == 0){
			return _root[mid];
		}
		else if((compareFunctor)(_root[mid], value) < 0){ // this->root[mid] < value
			begin = mid + 1;
		}
		else{ // this->root[mid] > value
			end = mid - 1;
		}
	}

	return nullptr;
}

template <typename T, typename C>
int SegRawArray<T, C>::indexOf(const T* value) throw()
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

		if(compareFunctor(_root[mid], value) == 0){
			return mid;
		}
		else if(compareFunctor(_root[mid], value) < 0){
			begin = mid + 1;
		}
		else {
			end = mid - 1;
		}
	}

	return -1;
}

template <typename T, typename C>
void SegRawArray<T, C>::sort() throw()
{
	int length = this->numArray;

	int middle = (length) / 2;

	for (int i = middle; i >= 0; i--) {
		downheap(i, length - 1);
	}

	for (int i = length - 1; i > 0; i--) {
		swap(0, i);
		downheap(0, i - 1);
	}
	this->sorted = true;
}

template <typename T, typename C>
void SegRawArray<T, C>::setSorted(bool b) throw()
{
	this->sorted = b;
}

template <typename T, typename C>
void SegRawArray<T, C>::size(int num) throw() {
	this->numArray = num;
}

template <typename T, typename C>
void SegRawArray<T, C>::downheap(int rootDefault, int leaf) const throw()
{
	int root = rootDefault;
	int left = (root + 1) * 2 - 1;;
	int right = left + 1;
	const T* leafMax;
	const T* rootValue = nullptr;
	const ElementType* const _root = this->root;

	while (left <= leaf) {
		if(right <= leaf){ // The tree has right
			left = compareFunctor(_root[left], _root[right]) < 0 ? right : left;
		}

		leafMax = _root[left];
		rootValue = _root[root];

		if(compareFunctor(leafMax, rootValue) < 0){
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
template <typename T, typename C>
void SegRawArray<T, C>::swap(const int i, const int j) const throw()
{
	T* tmp = root[i];
	root[i] = root[j];
	root[j] = tmp;
}

}

template class alinous::SegRawArray<alinous::AlinousMemoryPartitionManager, alinous::SegRawCompare>;
template class alinous::SegRawArray<alinous::MemorySegment, alinous::SegRawCompare>;
template class alinous::SegRawArray<alinous::SegBitSet, alinous::SegRawCompare>;




