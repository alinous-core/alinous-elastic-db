/*
 * Copyright (c) Tomohiro Iizuka. All rights reserved.
 * Licensed under the MIT license.
 */


#include "include/global.h"

namespace alinous {

template <typename T, typename C>
void SegRawLinkedList<T,C>::add(int index, T* element) throw(){
	if(index == this->length){
		addLast(element);
	}else{
		Element* e = getElement(index);
		Element* newElement = new Element(element);
		addBefore(e, newElement);
	}
}

template <typename T, typename C>
void SegRawLinkedList<T,C>::clear() throw(){
	const int max = this->length;
	for(int i = 0; i != max; ++i){
		removeElement(this->root);
	}
	this->length = 0;
}

template <typename T, typename C>
bool SegRawLinkedList<T,C>::contains(T* o) throw(){
	Iterator it = iterator();
	while(it.hasNext()){
		T* d = it.next();
		if(compareFunctor(o, d) == 0){
			return true;
		}
	}
	return false;
}

template <typename T, typename C>
T* SegRawLinkedList<T,C>::get(int index) throw(){
	int i = 0;
	Iterator it = iterator();
	while(it.hasNext()){
		T* d = it.next();

		if(i == index){
			return d;
		}
		++i;
	}
	return nullptr;
}

template <typename T, typename C>
int SegRawLinkedList<T,C>::indexOf(T* obj) throw(){
	int index = 0;
	Iterator it = iterator();
	while(it.hasNext()){
		T* d = it.next();

		if(compareFunctor(obj, d) == 0){
			return index;
		}
		++index;
	}
	return -1;
}

template <typename T, typename C>
bool SegRawLinkedList<T,C>::isEmpty() throw(){
	return this->length == 0;
}

template <typename T, typename C>
T* SegRawLinkedList<T,C>::remove(int index) throw(){
	Element* del = getElement(index);
	T* ret = del->data;
	removeElement(del);

	return ret;

}

template <typename T, typename C>
bool SegRawLinkedList<T,C>::remove(T* data) throw(){
	int index = indexOf(data);
	if(index < 0){
		return false;
	}

	Element* del = getElement(index);
	removeElement(del);


	return true;
}

template <typename T, typename C>
typename SegRawLinkedList<T,C>::Element* SegRawLinkedList<T,C>::getElement(int index) throw(){
	int i = 0;
	Iterator it = iterator();
	while(it.hasNext()){
		Element* e = it.nextElement();

		if(i == index){
			return e;
		}
		++i;
	}
	return nullptr;
}
template <typename T, typename C>
void SegRawLinkedList<T,C>::removeElement(Element* element) throw(){
	if(element == this->root){
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
template <typename T, typename C>
void SegRawLinkedList<T,C>::addBefore(Element* lastElement, Element* element) throw(){
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
template <typename T, typename C>
typename SegRawLinkedList<T,C>::Element* SegRawLinkedList<T,C>::addLast(T* data) throw(){
	SegRawLinkedList<T,C>::Element* element = new SegRawLinkedList<T,C>::Element(data);
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
template <typename T, typename C>
void SegRawLinkedList<T,C>::moveElementToTop(Element* element) throw(){
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

}

template class alinous::SegRawLinkedList<alinous::RawMemAllocElement, alinous::SegRawCompare>;
template class alinous::SegRawLinkedList<alinous::SegBitSetFactory, alinous::SegRawCompare>;
template class alinous::SegRawLinkedList<alinous::MemoryReleaser, alinous::SegRawCompare>;

