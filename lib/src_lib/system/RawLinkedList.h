/*
 * Copyright (c) Tomohiro Iizuka. All rights reserved.
 * Licensed under the MIT license.
 */


#ifndef SYSTEM_RAWLINKEDLIST_H_
#define SYSTEM_RAWLINKEDLIST_H_

namespace alinous {


template <typename T, typename C = RawCompare>
class RawLinkedList {
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

	class Element {
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

		inline Element(T* ptr) throw() : data(ptr), next(nullptr), prev(nullptr){}
		inline Element(T* ptr, Element* prev, Element* next) throw() : data(ptr), next(next), prev(prev){}

		T* data;
		Element* next;
		Element* prev;
	};
public:
	class Iterator {
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

		//Iterator(Iterator& it) = default;
		inline Iterator(RawLinkedList<T, C>* list) throw() : list(list), current(list->root) {}

		inline bool hasNext() throw() {
			return current != nullptr;
		}
		inline T* next() throw() {
			Element* prevCurent = current;
			current = current->next;
			return prevCurent->data;
		}

		inline Element* nextElement() throw() {
			Element* prevCurent = current;
			current = current->next;
			return prevCurent;
		}
	private:
		RawLinkedList<T, C>* list;
		Element* current;
	};

protected:
	Element* root;
	Element* last;
	int length;
	const C compareFunctor;
public:
	inline RawLinkedList() throw() : root(nullptr), last(nullptr), length(0), compareFunctor() {}
	inline ~RawLinkedList() throw() {
		clear();
	}
	inline Iterator iterator() throw() {
		RawLinkedList<T,C>::Iterator iter(this);
		return iter;
	}
	inline void add(T* data) throw() {
		addLast(data);
	}
	inline void add(int index, T* element) throw() {
		if(index == this->length){
			addLast(element);
		}else{
			Element* e = getElement(index);
			Element* newElement = new Element(element);
			addBefore(e, newElement);
		}
	}
	inline void clear() throw() {
		const int max = this->length;
		for(int i = 0; i != max; ++i){
			removeElement(this->root);
		}
		this->length = 0;
	}
	inline T* get(int index) throw() {
		int i = 0;
		RawLinkedList<T,C>::Iterator it(this); // = iterator();
		while(it.hasNext()){
			T* d = it.next();

			if(i == index){
				return d;
			}
			++i;
		}
		return nullptr;
	}
	inline bool isEmpty() throw() {
		return this->length == 0;
	}
	inline bool contains(T* o) throw() {
		RawLinkedList<T,C>::Iterator it(this); // = iterator();
		while(it.hasNext()){
			T* d = it.next();
			if(compareFunctor(o, d, 0) == 0){
				return true;
			}
		}
		return false;
	}
	inline int indexOf(T* obj) throw() {
		int index = 0;
		RawLinkedList<T,C>::Iterator it(this); // = iterator();
		while(it.hasNext()){
			T* d = it.next();

			if(compareFunctor(obj, d, 0) == 0){
				return index;
			}
			++index;
		}
		return -1;
	}
	inline T* remove(int index) throw() {
		Element* del = getElement(index);
		T* ret = del->data;
		removeElement(del);

		return ret;

	}
	inline bool remove(T* data) throw() {
		int index = indexOf(data);
		if(index < 0){
			return false;
		}

		Element* del = getElement(index);
		removeElement(del);


		return true;
	}

	inline int size() throw() {
		return this->length;
	}

	inline RawLinkedList<T>* subList(int fromIndex, int toIndex) throw() {
		return nullptr;
	}
	inline Element* getElement(int index) throw() {
		int i = 0;
		RawLinkedList<T,C>::Iterator it(this); // = iterator();
		while(it.hasNext()){
			Element* e = it.nextElement();

			if(i == index){
				return e;
			}
			++i;
		}
		return nullptr;
	}
	inline void removeElement(Element* element) throw() {
		if(element == this->root){
			#ifdef __FILEIO_DEGUB
			assert(this->length == 1 || element->next != nullptr);
			#endif


			if(element->next != nullptr){
				element->next->prev = nullptr;
			}
			this->root = element->next;

			if(element == this->last){
				this->last = element->prev;
			}

			delete element;

			this->length--;

			return;
		}else if(element == this->last){
			element->prev->next = nullptr;
			this->last = element->prev;

			delete element;

			this->length--;

			return;
		}

		element->next->prev = element->prev;
		element->prev->next = element->next;

		delete element;

		this->length--;
	}

	inline void addBefore(Element* lastElement, Element* element) throw() {
		if(lastElement->prev == nullptr){ // is root
			lastElement->prev = element;

			this->root = element;
			this->root->next = lastElement;

			this->length++;

			return;
		}

		Element* parentOfLast = lastElement->prev;

		parentOfLast->next = element;
		lastElement->prev = element;

		element->prev = parentOfLast;
		element->next = lastElement;

		this->length++;
	}
	inline Element* addLast(T* data) throw() {
		Element* element = new Element(data);
		if(this->root == nullptr){
			this->root = element;
			this->last = element;

			element->prev = nullptr;
			element->next = nullptr;

			this->length++;

			return element;
		}

		this->last->next = element;

		element->prev = this->last;
		element->next = nullptr;
		this->last = element;

		this->length++;

		return element;
	}

	inline void moveElementToLast(Element* element) throw() {
		if(element == last){
			return;
		}

		if(element->prev == nullptr){ // is root
			this->root = element->next;
			element->next->prev = nullptr;
		}
		else{
			element->prev->next = element->next;
			element->next->prev = element->prev;
		}

		this->last->next = element;
		element->prev = this->last;

		element->next = nullptr;
		this->last = element;
	}

	inline void moveElementToTop(Element* element) throw() {
		if(element == root){
			return;
		}

		if(this->last == element){
			this->last = element->prev;
		}

		element->prev->next = element->next;

		if(element->next != nullptr){
			element->next->prev = element->prev;
		}

		root->prev = element;
		element->next = root;
		element->prev = nullptr;

		root = element;

	}
};

} /* namespace alinous */


#endif /* SYSTEM_RAWLINKEDLIST_H_ */
