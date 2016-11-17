/*
 * Copyright (c) Tomohiro Iizuka. All rights reserved.
 * Licensed under the MIT license.
 */


#ifndef SYSTEM_RAWHASHMAP_H_
#define SYSTEM_RAWHASHMAP_H_


typedef int (*COMPARE_AMP_VALUE_FUNC)(void* a,void* b);

namespace alinous {

template <typename T, typename C> class RawArray;

template <typename T, typename V>
class MapElement {
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

	MapElement() throw() : key(0), value(0) {}
	MapElement(T* key, V* value) throw() : key(key), value(value){}
	T* key;
	V* value;

	class ValueCompare {
	public:
		int operator() (const MapElement* const a, const MapElement*  const b, ThreadContext* ctx) const throw() {
			return cmp(a->key, b->key, ctx);
		}
		typename T::ValueCompare cmp;
	};
};



template <typename T, typename V>
class RawHashMap {
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

	RawHashMap() throw() : memberDeleted(false), hashedElements(new RawArray<MapElement<T, V>, typename MapElement<T, V>::ValueCompare>(16))
	{
	}

	virtual ~RawHashMap() throw() {
		if(!this->memberDeleted){
			auto it = this->hashedElements->iterator();
			while(it.hasNext()){
				MapElement<T, V>* element = it.next();
				delete element;
			}
		}

		delete this->hashedElements;
	}

	void put(T* key, V* value) throw() {
		MapElement<T, V> *element = new MapElement<T, V>;
		element->key = key;
		element->value = value;

		int index = this->hashedElements->indexOf(element, 0);
		if(index >= 0){
			MapElement<T, V> *lastElement = this->hashedElements->get(index);
			delete lastElement;
			this->hashedElements->remove(index);
		}

		this->hashedElements->addElementWithSorted(element);
	}
	V* get(T* key, ThreadContext* ctx) throw() {
		const MapElement<T, V> tmp(key, 0);

		int index = this->hashedElements->indexOf(&tmp, ctx);
		if(index < 0){
			return 0;
		}

		return this->hashedElements->get(index)->value;
	}
	MapElement<T, V>* getMapElement(T* key, ThreadContext* ctx) const throw() {
		const MapElement<T, V> tmp(key, 0);

		int index = this->hashedElements->indexOf(&tmp, ctx);
		if(index < 0){
			return nullptr;
		}

		return this->hashedElements->get(index);
	}
	void clear() throw() {
		auto it = this->hashedElements->iterator();
		while(it.hasNext()){
			MapElement<T, V>* element = it.next();
			delete element;
		}

		this->hashedElements->reset();
	}
	void remove(T* key) throw() {
		const MapElement<T, V> tmp(key, 0);

		int index = hashedElements->indexOf(&tmp);
		const MapElement<T, V>* delObj = hashedElements->get(index);

		hashedElements->remove(index);
		delete delObj;
	}
	bool containsKey(T* key, ThreadContext* ctx) throw() {
		return get(key, ctx) != 0;
	}
	bool containsValue(V* value, ThreadContext* ctx) throw() {
		auto it  = this->hashedElements->iterator();
		while(it.hasNext()){
			MapElement<T, V>* element = it.next();
			if(element->value->equals(value, ctx)){
				return true;
			}
		}

		return false;
	}
	inline bool isEmpty() throw() {
		return size() == 0;
	}
	inline int size(){
		return this->hashedElements->size();
	}
	inline RawArrayIterator<MapElement<T, V>, typename MapElement<T, V>::ValueCompare>
	iterator() throw() {
		return this->hashedElements->iterator();
	}
public:
	bool memberDeleted;
	RawArray<MapElement<T, V>, typename MapElement<T, V>::ValueCompare> *hashedElements;

};

} /* namespace alinous */

#endif /* SYSTEM_RAWHASHMAP_H_ */
