/*
 * Copyright (c) Tomohiro Iizuka. All rights reserved.
 * Licensed under the MIT license.
 */


#ifndef SYSTEM_SEG_RAWARRAY_H_
#define SYSTEM_SEG_RAWARRAY_H_


namespace alinous {

template <typename T, typename C>
class RawArrayIterator;

#define DEFAULT_SEG_RAW_ARRAY_SIZE 16

struct SegRawCompare {
public:
	int operator() (const void* const a, const void* const b) const throw();
};


template <typename T, typename C = SegRawCompare> class SegRawArray {
public:
	typedef T* ElementType;

	SegRawArray() throw() ;
	SegRawArray(int defaultSize) throw() ;

	SegRawArray<T, C>* shallowCopy() throw() ;
	~SegRawArray() throw() ;
private:
	int indexOfInsert(const T* value) const throw() ;
	void insertWithKeepingOrder(T* ptr, int index) throw() ;
public:
	void addElementWithSorted(T* ptr) throw() ;
	void addElement(T* ptr) throw() ;
	void addElement(T* ptr, int index) throw() ;
	T* pop() throw() ;
	T* peek() const throw();
	void realloc() throw();
	T* get(int i) const throw();
	void set(int i, T* ptr) throw();
	void remove(const int index, const int length) throw();
	void remove(int index) throw();
	bool removeByObj(const T* obj) throw();
	void reset() throw();
	int size() const throw();
	T* search(const T* value) throw();
	int indexOf(const T* value) throw();
	void sort() throw();
	void setSorted(bool b) throw();
	void size(int num) throw();

	void __copy(T** dest, int dest_start, T** src, int src_start, const int count) throw() {
		T** d = dest + dest_start;
		T** s = src + src_start;

		FastCopy::copy(d, s, count * sizeof(T*));
	}

	void __move(T** dest, int dest_start, T** src, int src_start, const int count) throw() {
		T** d = dest + dest_start;
		void* s = src + src_start;

		::memmove(d, s, count * sizeof(T*));
	}

private:
	void downheap(int rootDefault, int leaf) const throw();
	void swap(const int i, const int j) const throw();
private:


	int numArray;
	int currentSize;
	ElementType* root;
	bool sorted;
	const C compareFunctor;

	ElementType* cursor;
};

}  // namespace alinous

#endif /* SYSTEM_SEG_RAWARRAY_H_ */
