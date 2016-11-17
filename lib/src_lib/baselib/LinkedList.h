/*
 * Copyright (c) Tomohiro Iizuka. All rights reserved.
 * Licensed under the MIT license.
 */

#ifndef BASELIB_LINKEDLIST_H_
#define BASELIB_LINKEDLIST_H_

namespace java { namespace lang{
class IObject;
}}

namespace alinous {
class ThreadContext;
}


namespace java { namespace util {

using namespace alinous;
using namespace java::lang;

template <typename T> class List;
template <typename T> class Iterator;

template <typename T>
class LinkedList final : public List<T> {
public:
	class LinkedListIterator final : public Iterator<T> {

	public:
		LinkedListIterator(LinkedList* list, ThreadContext* ctx) throw(): IObject(ctx), Iterator<T>(ctx), ite(&list->rawList) {

		}

		virtual ~LinkedListIterator() throw() {
			__releaseRegerences(false, nullptr);
		}

		virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw() {

		}
		virtual bool hasNext(ThreadContext* ctx) throw() {
			return ite.hasNext();
		}

		virtual T* next(ThreadContext* ctx) throw() {
			return ite.next();
		}
		virtual void remove(ThreadContext* ctx) throw() {
		}
	private:
		typename RawLinkedList<T>::Iterator ite;
	};


	LinkedList(ThreadContext* ctx) throw() : IObject(ctx), List<T>(ctx), rawList() {}
	LinkedList() throw() : IObject(0), List<T>(0), rawList() {}
	virtual ~LinkedList() throw() {
		ThreadContext* ctx = ThreadContext::getCurentContext();
		__releaseRegerences(false, ctx);
	}

	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw() {
		auto it = this->rawList.iterator();
		while(it.hasNext()){
			T* obj = it.next();
			__GC_DEC(this, obj, T);
		}
		this->rawList.clear();
	}
	virtual void add(T* obj, ThreadContext* ctx) throw() {
		__GC_INS(this, obj, T);

		this->rawList.add(obj);
	}
	virtual void add(int index, T* element, ThreadContext* ctx) throw() {
		__GC_INS(this, element, T);

		T* lastOne = this->rawList.get(index);
		if(lastOne != 0){
			__GC_DEC(this, lastOne, T);
		}

		this->rawList.add(index, element);
	}
	virtual void addAll(List<T>* list, ThreadContext* ctx) throw() {
		int maxLoop = list->size(ctx);
		for(int i = 0; i != maxLoop; ++i){
			T* element = list->get(i, ctx);
			add(element, ctx);
		}
	}
	virtual void clear(ThreadContext* ctx) throw() {
		auto it = this->rawList.iterator();
		while(it.hasNext()){
			T* obj = it.next();
			__GC_DEC(this, obj, T);
		}

		this->rawList.clear();
	}

	virtual bool contains(T* o, ThreadContext* ctx) throw() {
		return this->rawList.contains(o);
	}

	virtual bool equals(T* o, ThreadContext* ctx) throw() {
		return false;
	}
	virtual T* get(int index, ThreadContext* ctx) throw() {
		return __GC_RT(this->rawList.get(index), T);
	}
	virtual T* set(int index, T* element, ThreadContext* ctx) throw() {
		__GC_INS(this, element, T);

		auto elm = this->rawList.getElement(index);

		T* last = elm->data;
		if(last != 0){
			__GC_DEC(this, last, T);
		}

		elm->data = element;

		return __GC_RT(last, T);
	}
	virtual int indexOf(T* o,ThreadContext* ctx) throw() {
		return this->rawList.indexOf(o);
	}
	virtual bool isEmpty(ThreadContext* ctx) throw() {
		return this->rawList.isEmpty();
	}
	virtual Iterator<T> *iterator(ThreadContext* ctx) throw() {
		return nullptr;
	}
	virtual T* remove(int index, ThreadContext* ctx) throw() {
		T* del = this->rawList.get(index);

		this->rawList.remove(index);
		__GC_DEC(this, del, T);

		return __GC_RT(del, T);
	}
	void removeFirst(ThreadContext* ctx) throw() {
		remove(0, ctx);
	}
	virtual bool remove(T* o, ThreadContext* ctx) throw() {
		int idx = this->rawList.indexOf(o);
		if(idx < 0){
			return false;
		}

		remove(idx, ctx);

		return true;
	}
	virtual int size(ThreadContext* ctx) throw() {
		return this->rawList.size();
	}
	virtual List<T>* subList(int fromIndex, int toIndex, ThreadContext* ctx) throw() {
		return nullptr;
	}
	virtual ArrayObject<T>* toArray(IArrayObject<T>* dummy, ThreadContext* ctx) throw() {
		return nullptr;
	}
private:
	RawLinkedList<T> rawList;
};

}} /* namespace alinous */

#endif /* BASELIB_LINKEDLIST_H_ */
