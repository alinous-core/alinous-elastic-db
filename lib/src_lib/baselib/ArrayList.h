/*
 * Copyright (c) Tomohiro Iizuka. All rights reserved.
 * Licensed under the MIT license.
 */

#ifndef BASELIB_ARRAYLIST_H_
#define BASELIB_ARRAYLIST_H_

namespace alinous{
class ThreadContext;
template <typename T, typename C> class RawArray;

}

namespace java{
namespace util {

using namespace alinous;

template <typename T> class List;
template <typename T> class Iterator;
template <typename T> class ArrayListIterator;

template <typename T>
class ArrayList : public List<T> {
public:
	ArrayList(ThreadContext* ctx) throw() : IObject(ctx), List<T>(ctx), array(ctx) {

	}
	ArrayList(int cap, ThreadContext* ctx) throw() : IObject(ctx), List<T>(ctx), array(cap, ctx) {

	}

	virtual ~ArrayList() throw() {
		ThreadContext* ctx = ThreadContext::getCurentContext();
		__releaseRegerences(false, ctx);
	}

	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw() {
		auto it = this->array.iterator();
		while(it.hasNext()){
			T* obj = it.next();
			__GC_DEC(this, obj, T);
		}
		this->array.reset();
	}

	inline virtual void add(T* obj, ThreadContext* ctx) throw() final
	{
		__GC_INS(this, obj, T);

		this->array.addElement(obj);
	}
	inline virtual void add(int index, T* element, ThreadContext* ctx) throw() final
	{
		__GC_INS(this, element, T);

		T* lastOne = this->array.get(index);
		if(lastOne != 0){
			__GC_DEC(this, lastOne, T);
		}

		this->array.addElement(element, index);
	}
	inline virtual void addAll(List<T>* list, ThreadContext* ctx) throw() final {
		int maxLoop = list->size(ctx);
		for(int i = 0; i != maxLoop; ++i){
			T* element = list->get(i, ctx);
			add(element, ctx);
		}

	}

	inline virtual void clear(ThreadContext* ctx) throw() final
	{
		const int maxLoop =this->array.size();
		for(int i = 0; i != maxLoop; ++i){
			T* obj = this->array.get(i);
			__GC_DEC(this, obj, T);
		}

		this->array.reset();
	}
	inline virtual bool contains(T* o, ThreadContext* ctx) throw() final
	{
		const int maxLoop =this->array.size();
		for(int i = 0; i != maxLoop; ++i){
			T* obj = this->array.get(i);

			if(obj->equals(o, ctx)){
				return true;
			}
		}

		return false;
	}
	inline virtual T* get(int index, ThreadContext* ctx) throw() final
	{
		return __GC_RT(this->array.get(index), T);
	}

	inline virtual T* set(int index, T* element, ThreadContext* ctx) throw() final {
		__GC_INS(this, element, T);
		T* last = this->array.get(index);
		if(last != 0){
			__GC_DEC(this, last, T);
		}

		this->array.set(index, element);

		return __GC_RT(last, T);
	}

	inline virtual List<T>* subList(int fromIndex, int toIndex, ThreadContext* ctx) throw() final {
		ArrayList<T> *newList = new ArrayList<T>(ctx);
		const int max = toIndex;
		for(int i = fromIndex; i < max; ++i){
			newList->add(get(i, ctx), ctx);
		}
		return newList;
	}

	inline virtual int indexOf(T* o,ThreadContext* ctx) throw() final
	{
		int pos = 0;
		auto it = this->array.iterator();
		while(it.hasNext()){
			T* obj = it.next();
			IObject *pObj = (IObject*)obj;
			if(pObj->equals(o, ctx)){
				return pos;
			}
			pos++;
		}

		return -1;
	}
	inline virtual bool isEmpty(ThreadContext* ctx) throw() final
	{

		return size(ctx) == 0;
	}
	inline virtual Iterator<T> *iterator(ThreadContext* ctx) throw() final
	{

		ArrayListIterator<T> *it = new ArrayListIterator<T>(ctx);
		it->init(&this->array, ctx);

		return it;
	}
	inline virtual T* remove(int index, ThreadContext* ctx) throw() final
	{
		T* del = this->array.get(index);
		this->array.remove(index);
		__GC_DEC(this, del, T);
		return __GC_RT(del, T);
	}
	inline virtual bool remove(T* o, ThreadContext* ctx) throw() final
	{
		int idx = indexOf(o, ctx);
		if(idx < 0){
			return false;
		}

		remove(idx, ctx);

		return true;
	}

	inline virtual void removeRange(int fromIndex, int toIndex, ThreadContext* ctx) throw()
	{
		int removeLength = toIndex - fromIndex;

		const int max = toIndex;
		for(int i = fromIndex; i < max; i++){
			T* ptr = this->array.get(i);
			__GC_DEC(this, ptr, T);
		}

		this->array.remove(fromIndex, removeLength);

	}
	inline virtual int size(ThreadContext* ctx) throw() final
	{

		return this->array.size();
	}

	inline ArrayObject<T>* toArray(ThreadContext* ctx) throw() {
		ArrayObject<T>* array = new(ctx) ArrayObject<T>(ctx);
		auto it = this->array.iterator();
		while(it.hasNext()){
			T* element = it.next();

			array->append(element, ctx);
		}

		return array;
	}

	inline ArrayObject<T>* toArray(IArrayObject<T>* dummy, ThreadContext* ctx) throw() final {
		ArrayObject<T>* array = new(ctx) ArrayObject<T>(ctx);
		auto it = this->array.iterator();
		while(it.hasNext()){
			T* element = it.next();

			array->append(element, ctx);
		}

		return array;
	}


private:
	RawArray<T> array;

public:
	inline static void __cleanUp(ThreadContext* ctx) throw() {

	}
};

}} /* namespace alinous */


#endif /* BASELIB_ARRAYLIST_H_ */
