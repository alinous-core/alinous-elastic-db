/*
 * Copyright (c) Tomohiro Iizuka. All rights reserved.
 * Licensed under the MIT license.
 */


#ifndef SYSTEM_HASHEDRAWARRAY_H_
#define SYSTEM_HASHEDRAWARRAY_H_

namespace alinous {

template <typename T, typename H, typename C>
class HashedRawArray {
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

	int MAX_HASH = 128;
	int MAX_HASH_MASK = 128 - 1;
	RawArray<T, C> **arrays;
	RawBitSet bitset;
	const H hashBaseFunc;
	int numElements;

	HashedRawArray(int maxHash) throw() : MAX_HASH(maxHash), MAX_HASH_MASK(maxHash - 1),
			bitset(MAX_HASH / 8), hashBaseFunc(), numElements(0)
	{
		initArrays();
	}
	HashedRawArray() throw() :
		bitset(MAX_HASH / 8), hashBaseFunc(), numElements(0)
	{
		initArrays();
	}
private:
	void initArrays() throw() {
		this->MAX_HASH_MASK = this->MAX_HASH - 1;

		this->arrays = new RawArray<T, C>* [this->MAX_HASH];
		int maxLoop = this->MAX_HASH;

		RawArray<T, C>** ptr = this->arrays;

		for(int i = 0; i != maxLoop; ++i){
			ptr[i] = new RawArray<T, C>();
		}
	}
public:
	virtual ~HashedRawArray() throw() {
		int maxLoop = this->MAX_HASH;
		for(int i = 0; i != maxLoop; ++i){
			delete this->arrays[i];
		}


		delete [] this->arrays;
		this->arrays = nullptr;
	}
	int size() const throw() {
		return this->numElements;
	}
	T* addElement(T* ptr) throw() {
		u_int64_t hashcode = getHash(ptr);

		arrays[hashcode]->addElementWithSorted(ptr);
		bitset.set(hashcode);
		++numElements;

		return ptr;
	}
	bool removeByObj(const T* obj) throw() {
		int hashcode = getHash(obj);
		bool result = arrays[hashcode]->removeByObj(obj);
		if(result){
			--numElements;
		}

		if(arrays[hashcode]->size() == 0){
			bitset.clear(hashcode);
		}

		return result;
	}
	T* search(const T* value)throw(){
		int hashcode = getHash(value);
		return arrays[hashcode]->search(value);
	}
	void reset() throw() {
		for(int i = 0; i != MAX_HASH; i++){
			arrays[i]->reset();
		}
		bitset.clear();
		numElements = 0;
	}

	class Iterator {
	public:
		int MAX_HASH;
		int hashCode;
		int index;
		RawArray<T, C>** arrays;
		const RawBitSet* bitset;
		Iterator(RawArray<T, C>** ptr, RawBitSet* bitset, int MAX_HASH) throw() : MAX_HASH(MAX_HASH), hashCode(0), index(0), arrays(ptr), bitset(bitset) {}

		bool hasNext() const throw() {
			RawArray<T, C>* current = arrays[hashCode];
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
		T* next() throw() {
			const RawArray<T, C>* current = arrays[hashCode];
			if(current->size() == index){
				const int nextHash = hashCode + 1;
				int next = bitset->nextSetBit(nextHash);

				if(nextHash == MAX_HASH || next < 0){
					return nullptr;
				}

				index = 0;
				hashCode = next;
			}

			current = *(arrays + hashCode);
			return current->get(index++);
		}
	};

	Iterator iterator() throw() {
		return Iterator(arrays, &bitset, this->MAX_HASH);
	}
private:
	u_int64_t getHash(const T* ptr) const throw() {
		u_int64_t num = hashBaseFunc(ptr);
		//int code = FNVHash::fnv_1_hash_32((uint8_t *)&num, sizeof(u_int64_t)) % MAX_HASH;

		//int code = (num >> 1) % MAX_HASH;

		u_int64_t code = ((num * 2654404609L) >> 32) & MAX_HASH_MASK;
		//wprintf(L"%llx --> %d\n", num, code);

		return code;
	}
};
} /* namespace alinous */

#endif /* SYSTEM_HASHEDRAWARRAY_H_ */
