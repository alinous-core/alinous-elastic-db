/*
 * Copyright (c) Tomohiro Iizuka. All rights reserved.
 * Licensed under the MIT license.
 */


#ifndef SEGLINKEDLIST_H_
#define SEGLINKEDLIST_H_

namespace alinous {

template <typename T, typename C = SegRawCompare>
class SegRawLinkedList {
public:
	class Element {
	public:
		Element(T* ptr) throw() : data(ptr), next(nullptr), prev(nullptr){}
		Element(T* ptr, Element* prev, Element* next) throw() : data(ptr), next(next), prev(prev){}

		T* data;
		Element* next;
		Element* prev;
	};
public:
	class Iterator {
	public:
		Iterator(const Iterator& it) = default;
		Iterator(SegRawLinkedList* list) throw() : list(list), current(list->root) {}

		bool hasNext() throw() {
			return current != nullptr;
		}
		T* next() throw(){
			Element* prevCurent = current;
			current = current->next;
			return prevCurent->data;
		}

		Element* nextElement() throw() {
			Element* prevCurent = current;
			current = current->next;
			return prevCurent;
		}
	private:
		SegRawLinkedList* list;
		Element* current;
	};

protected:
	Element* root;
	Element* last;
	int length;
	const C compareFunctor;
public:
	SegRawLinkedList() throw() : root(nullptr), last(nullptr), length(0), compareFunctor() {}

	~SegRawLinkedList() throw() {
		clear();
	}

	Iterator iterator() throw() {
		Iterator iter(this);
		return iter;
	}

	void add(T* data) throw() {
		addLast(data);
	}
	void add(int index, T* element) throw() ;
	void clear() throw() ;
	bool contains(T* o) throw();
	T* get(int index) throw();
	int indexOf(T* obj) throw();
	bool isEmpty() throw();
	T* remove(int index) throw();
	bool remove(T* data) throw();
	int size() const throw();

	Element* getElement(int index) throw();
	void removeElement(Element* element) throw();
	void addBefore(Element* lastElement, Element* element) throw();
	Element* addLast(T* data) throw();
	void moveElementToTop(Element* element) throw();

};

}



#endif /* SEGLINKEDLIST_H_ */
