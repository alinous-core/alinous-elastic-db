/*
 * Copyright (c) Tomohiro Iizuka. All rights reserved.
 * Licensed under the MIT license.
 */


#ifndef SYSTEM_HASHMAPRAWARRAY_H_
#define SYSTEM_HASHMAPRAWARRAY_H_

namespace alinous {

template <typename K,typename V>
class HashMapInternalElement {
public:
    void* operator new(size_t size) throw() {
      	return SysThread::getMalloc()->allocate(size);
    }
    void* operator new(size_t size, ThreadContext* ctx) throw() {
    	return ctx->alloc->allocate(size);
    }
    void operator delete(void* p, size_t size) throw() {
    	SysThread::getMalloc()->freeMemory((char*)p, size);
    }

	HashMapInternalElement(K* k, V* v) throw() : key(k), value(v)
	{}
	int hashCode(ThreadContext* ctx) const throw(){
		K* keyPtr = this->key;

		return keyPtr->hashCode(ctx);
	}
	K* key;
	V* value;

	class ValueCompare {
	public:
		int operator() (const HashMapInternalElement<K, V>* const a, const HashMapInternalElement<K, V>* const b, ThreadContext* ctx) const throw() {
			typename K::ValueCompare cmp;

			return cmp(a->key, b->key, ctx);
		}
	};
};

template <typename K, typename V>
class HashMapRawArray {
public:

    void* operator new(size_t size) throw() {
      	return SysThread::getMalloc()->allocate(size);
    }

    void* operator new(size_t size, ThreadContext* ctx) throw() {
    	return ctx->alloc->allocate(size);
    }

    void operator delete(void* p, size_t size) throw() {
    	SysThread::getMalloc()->freeMemory((char*)p, size);
    }

	static const int MAX_HASH = 64;
	RawArray<HashMapInternalElement<K, V>, typename HashMapInternalElement<K, V>::ValueCompare> arrays[MAX_HASH];
	RawBitSet bitset;
	int numElements;

	HashMapRawArray() throw() : arrays({
		4,4,4,4,4,4,4,4, 4,4,4,4,4,4,4,4, 4,4,4,4,4,4,4,4, 4,4,4,4,4,4,4,4, // 32
		4,4,4,4,4,4,4,4, 4,4,4,4,4,4,4,4, 4,4,4,4,4,4,4,4, 4,4,4,4,4,4,4,4 // 64
				}),
		bitset(MAX_HASH / 8), numElements(0)
	{

	}
	virtual ~HashMapRawArray() throw() {

	}

	int size() const throw() {
		return this->numElements;
	}

	bool isEmpty() const throw() {
		return this->numElements == 0;
	}
	HashMapInternalElement<K, V>* addElement(HashMapInternalElement<K, V>* ptr) throw() {
		int hashcode = getHash(ptr);

		arrays[hashcode].addElementWithSorted(ptr);
		bitset.set(hashcode);
		++numElements;

		return ptr;
	}
	bool removeByObj(const HashMapInternalElement<K, V>* obj) throw() {
		int hashcode = getHash(obj);
		bool result =  arrays[hashcode].removeByObj(obj);
		if(result){
			--numElements;
		}

		if(arrays[hashcode].size() == 0){
			bitset.clear(hashcode);
		}

		return result;
	}
	HashMapInternalElement<K, V>* search(const HashMapInternalElement<K, V>* value) throw() {
		int hashcode = getHash(value);
		return arrays[hashcode].search(value);
	}

	void reset() throw() {
		for(int i = 0; i != MAX_HASH; i++){
			arrays[i].reset();
		}
		bitset.clear();
		numElements = 0;
	}

	class Iterator {
	public:
	    void* operator new(size_t size) throw() {
	      	return SysThread::getMalloc()->allocate(size);
	    }
	    void operator delete(void* p, size_t size) throw() {
	    	SysThread::getMalloc()->freeMemory((char*)p, size);
	    }

		int hashCode;
		int index;
		RawArray<HashMapInternalElement<K, V>, typename HashMapInternalElement<K, V>::ValueCompare>* arrays;
		const RawBitSet* bitset;
		Iterator(RawArray<HashMapInternalElement<K, V>, typename HashMapInternalElement<K, V>::ValueCompare>* ptr, RawBitSet* bitset) throw()
			: hashCode(0), index(0), arrays(ptr), bitset(bitset) {}
		bool hasNext() const throw() {
			RawArray<HashMapInternalElement<K, V>, typename HashMapInternalElement<K, V>::ValueCompare>* current = &arrays[hashCode];
			if(current->size() == index){
				const int nextHash = hashCode + 1;
				if(nextHash == MAX_HASH){
					return false;
				}

				int next = bitset->nextSetBit(nextHash);
				if(next < 0){
					return false;
				}
				return true;
			}

			return true;
		}
		HashMapInternalElement<K, V>* next() throw() {
			const RawArray<HashMapInternalElement<K, V>, typename HashMapInternalElement<K, V>::ValueCompare>* current = &arrays[hashCode];
			if(current->size() == index){
				const int nextHash = hashCode + 1;
				int next = bitset->nextSetBit(nextHash);

				if(nextHash == MAX_HASH || next < 0){
					return nullptr;
				}

				index = 0;
				hashCode = next;
			}

			current = &arrays[hashCode];
			return current->get(index++);
		}
	};

	Iterator iterator() throw() {
		return Iterator(arrays, &bitset);
	}
private:
	int getHash(const HashMapInternalElement<K, V>* ptr) const throw() {
		int num = ptr->hashCode(nullptr);
		num = (num >= 0) ? num : num * -1;

		int code = (num >> 1) % MAX_HASH;
		//wprintf(L"%llx --> %d\n", num, code);

		return code;
	}
};

}


#endif /* SYSTEM_HASHMAPRAWARRAY_H_ */
